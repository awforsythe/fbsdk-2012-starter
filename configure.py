import os
import sys
import glob

INPUT_FILE_PATTERNS = [
	'%s.sln',
	'%s.vcproj',
	'%s.vcproj.user',
	os.path.join('include', '%s*.h'),
	os.path.join('src', '%s*.cpp'),
	os.path.join('src', 'main.cpp')
]

def print_usage():

	print 'configure.py: Renames the FBSDK starter project.'
	print '       Usage: configure.py newName [oldName]'

def parse_arguments(argv):

	newName = ''
	oldName = 'PluginName'

	if len(argv) > 1:
		newName = argv[1]
	if len(argv) > 2:
		oldName = argv[2]

	return {
		'newName': newName,
		'oldName': oldName
	}

def get_input_files(oldName):

	inputFiles = []
	projectRoot = os.path.dirname(__file__)

	for relativePattern in [p.replace('%s', oldName) for p in INPUT_FILE_PATTERNS]:

		absolutePattern = os.path.join(projectRoot, relativePattern)
		inputFiles.extend(glob.glob(absolutePattern))

	return inputFiles

def can_open_file(filePath):

	try:
		fp = open(filePath, 'r')
	except IOError:
		return False
	else:
		fp.close()
		return True

def find_and_replace_in_file(filePath, oldString, newString):

	infilePath = filePath + '.bak'
	os.rename(filePath, infilePath)

	with open(infilePath, 'r') as infile:
		with open(filePath, 'w') as outfile:
			for line in infile:
				outfile.write(line.replace(oldString, newString))

	os.remove(infilePath)

def find_and_replace_in_filename(filePath, oldString, newString):

	dirname, basename = os.path.split(filePath)

	if oldString in basename:

		newFilePath = os.path.join(dirname, basename.replace(oldString, newString))
		os.rename(filePath, newFilePath)

def main():

	args = parse_arguments(sys.argv)
	
	if not args['newName']:
		print_usage()
		return -1

	filePaths = get_input_files(args['oldName'])
	for path in filePaths:
		if not can_open_file(path):
			print 'Could not open %s!' % os.path.basename(path)
			print 'Please ensure that the project is not currently open in Visual Studio.'
			return -1

	for path in filePaths:
		find_and_replace_in_file(path, args['oldName'], args['newName'])
		find_and_replace_in_filename(path, args['oldName'], args['newName'])

	print 'Project successfully renamed to %s.' % args['newName']
	return 0

if __name__ == '__main__':
	main()
