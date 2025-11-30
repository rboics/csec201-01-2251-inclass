.586					;This indicates what version of masm is being used
.model flat, stdcall	;This specified the memory model
						;In a nutshell, how function calls occur

.stack 2048				;Specify size of stack in bytes

;These two lines are commented out
;Because I realized my VS setup is incomplete

;includelib libcmt.lib
;includelib legacy_stdio_definitions.lib	;printf/scanf
;The above two lines are linking instructions
;That import common libraries

;Function prototype for a Windows function for ending a process
ExitProcess PROTO, dwExitCode: DWORD

.data
	;If we had global vars, we put them here
	input dw 5	;creates int called called input
				;a "global" variable
				;the initial value is 5
				;dw -> data type, 4 bytes (in x86)
				;	dw -> double word -> 4 bytes

.code ;Where we put our code

	main PROC c	;where main begins
		;code for main will go here
		;function prologue to set the set up the stack frame
		push ebp ;We save the beginning of the calling function's stack frame on the stack
		mov ebp, esp	;copying esp into ebp
						;esp tracks the current top of the stack
						;ebp definitionally keeps track of where the stack frame
						;begins



		;passes in the input variable to AddOne
;		mov ebx, input
		push ebx

		;calls AddOne
		; call ->
		;	push eip so that we can return from add one
		;	copies the address of the AddOne label into eip
		call AddOne
		
		;copy the return value to the edx register


		;function epilogue to remove the stack frame
		mov esp, ebp	;We set the top of the stack to be the lowest
						;address in the current stack frame
		pop ebp
		;Returns or exits the process
		

		;write a function that adds one and returns the result


		;In the C standard...
		;Arguments are pushed onto the stack
		;Arguments are referenced from the stack
		;Return values are left inside of the eax register
		AddOne:		;This is a label that is effectively a "name" for a block of code
			
			;function prologue
			push ebp	;save the base of main's stack for AddOne
			mov ebp,esp	;set up a new stack frame for AddOne

			;copy the argument to AddOne into a register
			mov ecx, [ebp+8]	;Offset is +8 since
								;there's only one arg and we want the 1st arg
			add ecx, 1

			mov eax,ecx			;set up return value
								
			;function epilogue
			mov esp,ebp ;getting rid of AddOne's stack frame
			pop ebp		;restoring main's stack frame
			
			;If everything works to plan, the address put onto the stack
			;by call AddOne should be on the top the stack

			ret	;return, basically an alias for pop eip

	main endp	;where main ends
end main

	