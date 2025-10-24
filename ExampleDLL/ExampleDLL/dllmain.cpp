// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>

                                 //Kind of like "public" in Java
extern "C" __declspec(dllexport) //export the function so that it can be found by GetProcAddress
void dllDemo(void) {
    printf("Hello from dllDemo\n");
}

void notExported(void) {
    printf("Shouldn't be able to call this\n");
}



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
        break;
    }
    return TRUE;
}

