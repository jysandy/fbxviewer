This projects loads a set of FBX files and renders them.

The files are to be specified in code, in the Init() method in FbxViewer.cpp. The filenames 
should be pushed back in the 'filenames' object which is of type vector<string>. 
Corresponding to each FBX file, a texture may be optionally pushed back in the 'textureFileNames' 
object which is of type vector<wstring>. For example, let us assume that one wants to load two files.
The first is called roc_body.FBX with a texture called roc_body.png, and the second is called 
roc_wing.FBX with a texture called roc_wing.png. Assuming that all of these files are in the project directory
(the same directory which contains the source files), the following code should be added to the the FBXApp::Init()
method just after the call to D3dtut::D3DApp::Init():

filenames.push_back("roc_body.FBX");
textureFilenames.push_back(L"roc_body.png");
filenames.push_back("roc_wing.FBX");
textureFilenames.push_back(L"roc_wing.png");

The code assumes that the texture filename for an FBX file in 'filenames' at index i can be found in 
'textureFilenames' at index i. If there is no corresponding texture filename specified, the code attempts
to get the filename from the FBX file itself. If the filename cannot be found even in the FBX file, the 
program terminates with an error.

For now, FBXViewer supports rendering with Phong lighting and one texture per mesh. Additional features will
be added.

HOW TO BUILD:
The project downloaded may have some references and include paths which are valid only on my computer. You should
replace these when you attempt to build it on your computer.
FBXViewer has three dependencies. One is DX11Lib, which can be found at https://github.com/jysandy/dx11lib. Add the 
project to the solution, then add it as a reference to FBXViewer.

The second dependency is DirectXTK, which can be downloaded at http://go.microsoft.com/fwlink/?LinkId=248929. Add the 
project called 'DirectXTK_Desktop_2013.vcxproj' to the solution, then add it as a reference to FBXViewer. Also add the 
path to the 'DirectXTK' folder(the folder which contains the project files, NOT the Inc folder) to the include directories 
of FBXViewer. 

The third dependency is the Autodesk FBX SDK. Instructions to download and set up the FBX SDK with 
Visual Studio are available at
http://help.autodesk.com/view/FBX/2015/ENU/?guid=__files_GUID_6E7B1A2E_584C_49C6_999E_CD8367841B7C_htm

After resolving these dependencies, simply build and run. The camera is a first-person camera, which can be controlled by
the WASD keys. Holding LMB or RMB and moving the mouse will move the camera. Press Alt+Enter to toggle fullscreen mode.