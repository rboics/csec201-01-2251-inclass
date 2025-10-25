#include <stdio.h>
#include <windows.h>

//Declaring custom function pointer types
typedef (__stdcall* hello_fn)();
//typedef void (__stdcall* hello_fn)(void);
typedef int(__stdcall* add_and_double_fn)(int, int);
typedef int(__stdcall* double_it)(int);


int main(void) {
	system("pause"); //Prompt "Press any key to continue"
	HINSTANCE importedDLL = LoadLibrary(L"D:\\csec201-2251-01\\ExampleDLL\\Debug\\ExampleDLL.dll");
	system("pause"); //Prompt "Press any key to continue"
	if (importedDLL == NULL) {
		printf("DLL was not loaded!\n");
		return 0;
	}
	else {
		printf("DLL was loaded!\n");
	}
	system("pause");
	//myFunction is a pointer
	//It'll hold the address of dllDemo once we call GetProcAddress;
	hello_fn myFunction;
	myFunction = (hello_fn)GetProcAddress(importedDLL, "dllDemo");
	if (myFunction == NULL)printf("dllDemo not found in DLL\n");
	else myFunction();
	system("pause");

	add_and_double_fn myFunction2;
	myFunction2 = (add_and_double_fn)GetProcAddress(importedDLL, "_add_and_double@8");
	if (myFunction2 == NULL)printf("add_and_double not found in DLL\n");
	else {
		int result = myFunction2(5, 8);
		printf("Result is: %d\n", result);
	}
	system("pause");

	double_it myFunction3;
	myFunction3 = (hello_fn)GetProcAddress(importedDLL, "_double_it@4");
	if (myFunction3 == NULL)printf("double_it not found in DLL\n");
	else {
		int result = myFunction3(5);
		printf("Result is: %d\n", result);
	}
	system("pause");
}