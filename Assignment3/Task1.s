	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$236, -8(%rbp)
	movl	-8(%rbp), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$7, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%rbp)
	jl	LBB0_7
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	movl	-12(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB0_4
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_5
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_6
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB0_1
LBB0_7:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-8(%rbp), %eax
	orl	$4, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$7, -16(%rbp)
LBB0_8:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -16(%rbp)
	jl	LBB0_14
## %bb.9:                               ##   in Loop: Header=BB0_8 Depth=1
	movl	-8(%rbp), %eax
	movl	-16(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB0_11
## %bb.10:                              ##   in Loop: Header=BB0_8 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_12
LBB0_11:                                ##   in Loop: Header=BB0_8 Depth=1
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_12:                                ##   in Loop: Header=BB0_8 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_8 Depth=1
	movl	-16(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_8
LBB0_14:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-8(%rbp), %eax
	andl	$-33, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %esi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$7, -20(%rbp)
LBB0_15:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -20(%rbp)
	jl	LBB0_21
## %bb.16:                              ##   in Loop: Header=BB0_15 Depth=1
	movl	-8(%rbp), %eax
	movl	-20(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB0_18
## %bb.17:                              ##   in Loop: Header=BB0_15 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_19
LBB0_18:                                ##   in Loop: Header=BB0_15 Depth=1
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_19:                                ##   in Loop: Header=BB0_15 Depth=1
	jmp	LBB0_20
LBB0_20:                                ##   in Loop: Header=BB0_15 Depth=1
	movl	-20(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB0_15
LBB0_21:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-8(%rbp), %eax
	xorl	$128, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %esi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$7, -24(%rbp)
LBB0_22:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -24(%rbp)
	jl	LBB0_28
## %bb.23:                              ##   in Loop: Header=BB0_22 Depth=1
	movl	-8(%rbp), %eax
	movl	-24(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB0_25
## %bb.24:                              ##   in Loop: Header=BB0_22 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_26
LBB0_25:                                ##   in Loop: Header=BB0_22 Depth=1
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_26:                                ##   in Loop: Header=BB0_22 Depth=1
	jmp	LBB0_27
LBB0_27:                                ##   in Loop: Header=BB0_22 Depth=1
	movl	-24(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB0_22
LBB0_28:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-8(%rbp), %eax
	sarl	$7, %eax
                                        ## kill: def $al killed $al killed $eax
	movb	%al, -25(%rbp)
	movsbl	-25(%rbp), %eax
	xorl	$-1, %eax
	cmpl	$0, %eax
	je	LBB0_30
## %bb.29:
	leaq	L_.str.8(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_31
LBB0_30:
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_31:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Initial data: 0x%02X\n"

L_.str.1:                               ## @.str.1
	.asciz	"In binary: "

L_.str.2:                               ## @.str.2
	.asciz	"1"

L_.str.3:                               ## @.str.3
	.asciz	"0"

L_.str.4:                               ## @.str.4
	.asciz	"\n\n"

L_.str.5:                               ## @.str.5
	.asciz	"After setting 3rd bit: 0x%02X\n"

L_.str.6:                               ## @.str.6
	.asciz	"After clearing 5th bit: 0x%02X\n"

L_.str.7:                               ## @.str.7
	.asciz	"After toggling 7th bit: 0x%02X\n"

L_.str.8:                               ## @.str.8
	.asciz	"7th bit is 0\nSuccessfully toggled!\n"

L_.str.9:                               ## @.str.9
	.asciz	"7th bit is 1\n"

.subsections_via_symbols
