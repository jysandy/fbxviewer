#include <Windows.h>
#include <iostream>

#include "FBXViewer.h"

#define WIN32_LEAN_AND_MEAN


int APIENTRY wWinMain(HINSTANCE hinstance, HINSTANCE hprevinst, PWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(hprevinst);
	FBXViewer::FBXApp app = FBXViewer::FBXApp(hinstance);

	try
	{
		if (app.Init())
		{
			return app.Run();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cin.ignore();
	}
	catch (D3dtut::D3dutil::D3DException& e)
	{
		MessageBox(NULL, e.error.c_str(), L"Error", MB_ICONERROR);
	}

	return 0;
}