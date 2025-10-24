#include <stdio.h>
#include <windows.h> //Needed for LoadLibrary and for GetProcAddress

int main(void) {

	//Pointer to the loaded DLL in memory
	//HINSTANCE is the type for a generic "Handle"
	//Handle is just an open system resource
	HINSTANCE LoadedDLL;
	LoadedDLL = LoadLibrary(L"C:\\Users\\rboics\\csec201-public\\csec201-01-2251-inclass\\ExampleDLL\\Debug\\ExampleDLL.dll");
	if (LoadedDLL == NULL) {
		printf("The library was not loaded!\n");
		return 0;
	}
}