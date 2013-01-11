fbsdk-2012-starter
==================

This repository contains a bare-bones project for Visual Studio 2008 which is
cleanly configured to build a plugin for MotionBuilder 2012. It's essentially
an empty C++ DLL project which has been preconfigured to include and link
against the fbsdk library in both 32-bit and 64-bit flavors.

In addition to facilitating the creation of new projects and throwaway
testbeds, this template is also meant to demonstrate the basics of fbsdk to
new users. It provides a few template classes, like ExampleBox and
ExampleTool, demonstrating the common object types that a plugin might
sbuclass.

Installation and Setup
----------------------
```
git clone git://github.com/awforsythe/fbsdk-2012-starter.git
rename fbsdk-2012-starter YourProjectName
cd YourProjectName
configure.py YourProjectName
YourProjectName.sln
```

Getting Started
---------------   
0. Before opening the solution, run configure.py [NewPluginName] from the
   command line in order to give your version of the project a sensible name.
   Once the project is renamed, open the .sln file.

1. Open the Property Manager and check the User Macros for the
   fbsdk-2012-win32-plugin and fbsdk-2012-x64-plugin property sheets. Ensure
   that the MotionBuilder installation path is noted correctly in each.

2. Select the appropriate platform and the Debug build. Note that you must
   have the corresponding version of MotionBuilder installed (Win32 or x64).

3. Build the solution. If all is well, the plugin should build and the
   post-build event (Deploying PluginName.dll...) should indicate
   *1 File(s) copied*.

4. Press F5 to launch MotionBuilder in Debug mode. If warned about debug
   information, suppress the warning and click Yes.

5. The new classes registered in *main.cpp* should now be accessible. To
   verify, click Open Reality in the menu bar, expand Tools, and click
   "*PluginName* Example Tool." A tool window should appear.

The MotionBuilder Directory
---------------------------
The project configuration needs the path to the MotionBuilder installation
directory in order to locate the fbsdk library, copy the .dll to the plugins
directory, and launch motionbuilder.exe for debugging. This path is defined
with the user macro *$(MotionBuilderDirectory)* in the included property
sheets.

There are two property sheets: one for Win32 builds, and one for x64. If you
don't have a particular build of MotionBuilder installed, simply refrain from
building the plugin for that platform.

Directory Structure
-------------------
The project directory (containing the .sln and .vcproj files) is organized
into a few typical subdirectories. C++ code is kept in the *include* and *src*
directories, intermediate build files are stored under *obj*, and the output
.dll file is placed in *bin*.

Building and Output Files
-------------------------
When the .dll is built, it's stored locally beneath the *bin* directory, with
each platform and build configuration in a separate subdirectory (e.g.,
*bin/x64/debug*). A custom post-build event copies the .dll to the
MotionBuilder plugins directory after the build. The release and debug .dlls
will overwrite one another in this directory, so remember that MotionBuilder
will load whichever DLL was built most recently.

Debugging
---------
The included .user file configures the debug build to launch the MotionBuilder
executable with a console window for output. Once the plugin is built and
copied, pressing F5 should launch MotionBuilder and load the appropriate
debugging information.
