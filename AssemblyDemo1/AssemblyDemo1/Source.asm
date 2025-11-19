.586					;This "flavor" of MASM
.model flat, stdcall	;This line is responsible for
						;"the model of memory"
						;Basically, how functions get called
.stack 2048				;Set the max stack size to be 1k

;Two libraries we'll commonly use functions from
includelib libcmt.lib
;include legacy_stdio_definitions.lib ;This gets printf/scanf

;Function prototype for ExitProcess, used to terminate the process
;when our code is done
ExitProcess PROTO, dwExitCode: DWORD

.data
	;If we have global variables, they go here

.code
	main PROC c
		;Code goes here

		;Function prologue
		;Create the stack frame
		push ebp ;save the old base pointer
		mov ebp, esp ;initialize the new stack frame

		;Beginning of int x=0;
		sub esp, 4	 ;"Creates" one four-byte large space on the stack
					 ;When we want to work with this variable,
					 ;We can use [ebp-4]
		
		;mov [ebp-4], 0 ;Challenge in that most operations
					   ;want at least one register as an operand

		mov eax,0
		mov [ebp-4], eax
		;end of int x=0;

		;x = x+1;
		mov eax, [ebp-4]
		add eax, 1
		mov [ebp-4], eax

		;Function epilogue
		;Tear down the stack frame and
		;Leave the function/process
		mov esp,ebp		;undoes mov ebp, esp
		pop ebp			;undoes push ebp
		INVOKE ExitProcess, 0	;Exit the program
								;If this were a function other than
								;main, would be ret

	main endp
end main



