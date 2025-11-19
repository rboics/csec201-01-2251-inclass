.586				;assembler
.model flat,stdcall ;assembler
.stack 2048			;assembler

;instruction to link with libcmt.lib
includelib libcmt.lib	

;instruction to link with legacy_stdio_definitions.lib
includelib legacy_stdio_definitions.lib

;like prototypes - an signal to the assembler
;that printf/scanf will be in library files we're linking to
extern printf:NEAR
extern scanf:NEAR

.data
;0ah = \n
;0 = NULL
outputformat BYTE "Your number is: %d", 0ah, 0
inputformat BYTE "%d", 0

.code
main PROC c
	;function prologue
	push ebp
	mov ebp, esp

	;Declare a local variable, int x
	sub esp, 4

	push eax	;to prevent changes from scanf
	push ebx
	push ecx
	push edx

	;scanf("%d", &x);
	;push ebp-4 too complex
	mov eax, ebp
	sub eax, 4
	push eax	;&x is now on the stack
	push offset inputformat	;addr of "%d" is now on the stack
	call scanf
	add esp, 8	;clear scanf's arguments from the stack

	pop edx
	pop ecx
	pop ebx
	pop eax		;restore the registers so that scanf doesnt change them


	push eax	;to prevent changes from scanf
	push ebx
	push ecx
	push edx
	;printf("Your number is: %d\n", x);
	push [ebp-4]	;ebp-4 is ok, inside of the [] used to deref
	push offset outputformat
	call printf
	add esp,8	;clear outputformat addr and x off the stack

	pop edx
	pop ecx
	pop ebx
	pop eax		;restore the registers so that scanf doesnt change them



	;function epilogue
	mov esp, ebp
	pop ebp
	ret
main endp
end
