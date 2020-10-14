;;kernel.asm
bits 32			;nasm directive for 32 bit
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002	;magic num
	dd 0x00		;flags
	dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero
	

global start
extern kmain		;kmain is defined in the c file

start:
  cli			;block interrupts
  mov esp, stack_space
  call kmain
  hlt			;halt the CPU

section .bss
resb 8192		;reserve 8KB for the stack
stack_space:
