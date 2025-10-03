// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>


//We don't *need* __stdcall for dllDemo
//Because dllDemo takes no arguments and returns no values
//So, the stack frame structure doesn't matter much for dllDemo
//Would not be wrong (probably best practice) to include __stdcall
extern "C" __declspec(dllexport)
void dllDemo(void) {
    printf("Hello from dllDemo\n");
}


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
}



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
        break;
    }
    return TRUE;
}

