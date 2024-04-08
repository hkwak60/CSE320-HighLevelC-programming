	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_modifyName                     ## -- Begin function modifyName
	.p2align	4, 0x90
_modifyName:                            ## @modifyName
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_modifyNumber                   ## -- Begin function modifyNumber
	.p2align	4, 0x90
_modifyNumber:                          ## @modifyNumber
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, 8(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_modifyData                     ## -- Begin function modifyData
	.p2align	4, 0x90
_modifyData:                            ## @modifyData
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, 16(%rax)
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0                   ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	movsd	%xmm0, 16(%rax)
	movq	-16(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, 16(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3, 0x0                          ## -- Begin function main
LCPI3_0:
	.quad	0x4029666666666666              ## double 12.699999999999999
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	$10, %edi
	callq	_malloc
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rdi
	leaq	L_.str(%rip), %rsi
	movq	$-1, %rdx
	callq	___strcpy_chk
	movl	$100, -24(%rbp)
	movl	$150, -40(%rbp)
	movl	-40(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movsd	LCPI3_0(%rip), %xmm0            ## xmm0 = mem[0],zero
	movsd	%xmm0, -40(%rbp)
	movsd	-40(%rbp), %xmm0                ## xmm0 = mem[0],zero
	leaq	L_.str.2(%rip), %rdi
	movb	$1, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rsi
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	-32(%rbp), %rdi
	leaq	L_.str.5(%rip), %rsi
	callq	_modifyName
	leaq	-32(%rbp), %rdi
	movl	$20, %esi
	callq	_modifyNumber
	leaq	-32(%rbp), %rdi
	leaq	-40(%rbp), %rsi
	callq	_modifyData
	movq	-32(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-24(%rbp), %esi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rsi
	leaq	L_.str.8(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-16(%rbp), %esi
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movsd	-16(%rbp), %xmm0                ## xmm0 = mem[0],zero
	leaq	L_.str.10(%rip), %rdi
	movb	$1, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"LIF Neuron"

L_.str.1:                               ## @.str.1
	.asciz	"dataA: %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"dataA: %f\n"

L_.str.3:                               ## @.str.3
	.asciz	"Number of synapses and average weight"

L_.str.4:                               ## @.str.4
	.asciz	"dataA: %s\n"

L_.str.5:                               ## @.str.5
	.asciz	"Hodgkin-Huxley"

L_.str.6:                               ## @.str.6
	.asciz	"SNN name: %s\n"

L_.str.7:                               ## @.str.7
	.asciz	"SNN number: %d\n"

L_.str.8:                               ## @.str.8
	.asciz	"SNN common data: %s\n"

L_.str.9:                               ## @.str.9
	.asciz	"dataA(int & double attributes) after stringData initialization: \nint: %d\n"

L_.str.10:                              ## @.str.10
	.asciz	"double: %f\n"

.subsections_via_symbols
