// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>

<<<<<<< HEAD
                                 //Kind of like "public" in Java
extern "C" __declspec(dllexport) //export the function so that it can be found by GetProcAddress
=======

//We don't *need* __stdcall for dllDemo
//Because dllDemo takes no arguments and returns no values
//So, the stack frame structure doesn't matter much for dllDemo
//Would not be wrong (probably best practice) to include __stdcall
extern "C" __declspec(dllexport)
>>>>>>> 72cb92e005cc2e05b26a81988b0f08134e6c4ac7
void dllDemo(void) {
    printf("Hello from dllDemo\n");
}

<<<<<<< HEAD
void notExported(void) {
    printf("Shouldn't be able to call this\n");
=======

//Not exported
int __stdcall double_it(int x) {
    return x * 2;
}

//Note: We added __stdcall
//This tells the Loading executable how the stack frame
//for this function should be structured
extern "C" __declspec(dllexport)
int __stdcall add_and_double(int a, int b) {
    int sum = a + b;
    return double_it(sum);     // uses the non-exported helper
>>>>>>> 72cb92e005cc2e05b26a81988b0f08134e6c4ac7
}



<<<<<<< HEAD
//This function gets called when the LoadLibrary is called()
//This function gets called when we close the library
BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call, LPVOID lpReserved
                     )
{
    //There are extremely tight restrictions on what code you add to DllMain

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH://This occurs when the DLL is loaded
                            //Rare to see a break between these two cases
    case DLL_THREAD_ATTACH: //Thread_attach also gets called when the DLL loads
    case DLL_THREAD_DETACH: //This state occurs when the DLL is removed
                            //Similarly, rare to a break here
    case DLL_PROCESS_DETACH://Also called when the DLL is removed from memory
=======
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    printf("Hello from DllMain");

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
>>>>>>> 72cb92e005cc2e05b26a81988b0f08134e6c4ac7
        break;
    }
    return TRUE;
}

