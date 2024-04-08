	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_matrix_multiply                ## -- Begin function matrix_multiply
	.p2align	4, 0x90
_matrix_multiply:                       ## @matrix_multiply
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$0, -28(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
                                        ##       Child Loop BB0_5 Depth 3
	cmpl	$9, -28(%rbp)
	jge	LBB0_12
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -32(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_5 Depth 3
	cmpl	$9, -32(%rbp)
	jge	LBB0_10
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=2
	movq	-24(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-32(%rbp), %rcx
	movl	$0, (%rax,%rcx,4)
	movl	$0, -36(%rbp)
LBB0_5:                                 ##   Parent Loop BB0_1 Depth=1
                                        ##     Parent Loop BB0_3 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpl	$8, -36(%rbp)
	jge	LBB0_8
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=3
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %ecx
	shll	$3, %ecx
	movslq	%ecx, %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movslq	-36(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-16(%rbp), %rax
	imull	$9, -36(%rbp), %ecx
	movslq	%ecx, %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movslq	-32(%rbp), %rcx
	imull	(%rax,%rcx,4), %edx
	movq	-24(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-32(%rbp), %rcx
	addl	(%rax,%rcx,4), %edx
	movl	%edx, (%rax,%rcx,4)
## %bb.7:                               ##   in Loop: Header=BB0_5 Depth=3
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB0_5
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=2
	jmp	LBB0_9
LBB0_9:                                 ##   in Loop: Header=BB0_3 Depth=2
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB0_3
LBB0_10:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_11
LBB0_11:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB0_1
LBB0_12:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	subq	$624, %rsp                      ## imm = 0x270
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -596(%rbp)
	leaq	-304(%rbp), %rdi
	leaq	l___const.main.matA(%rip), %rsi
	movl	$288, %edx                      ## imm = 0x120
	callq	_memcpy
	leaq	-592(%rbp), %rdi
	leaq	l___const.main.matB(%rip), %rsi
	movl	$288, %edx                      ## imm = 0x120
	callq	_memcpy
	movl	$72, %edi
	callq	_malloc
	movq	%rax, -608(%rbp)
	movl	$0, -612(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$9, -612(%rbp)
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	$36, %edi
	callq	_malloc
	movq	%rax, %rdx
	movq	-608(%rbp), %rax
	movslq	-612(%rbp), %rcx
	movq	%rdx, (%rax,%rcx,8)
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-612(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -612(%rbp)
	jmp	LBB1_1
LBB1_4:
	leaq	-304(%rbp), %rdi
	leaq	-592(%rbp), %rsi
	movq	-608(%rbp), %rdx
	callq	_matrix_multiply
	movl	$0, -616(%rbp)
LBB1_5:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_7 Depth 2
	cmpl	$9, -616(%rbp)
	jge	LBB1_12
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=1
	movl	$0, -620(%rbp)
LBB1_7:                                 ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$9, -620(%rbp)
	jge	LBB1_10
## %bb.8:                               ##   in Loop: Header=BB1_7 Depth=2
	movq	-608(%rbp), %rax
	movslq	-616(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-620(%rbp), %rcx
	movl	(%rax,%rcx,4), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.9:                               ##   in Loop: Header=BB1_7 Depth=2
	movl	-620(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -620(%rbp)
	jmp	LBB1_7
LBB1_10:                                ##   in Loop: Header=BB1_5 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.11:                              ##   in Loop: Header=BB1_5 Depth=1
	movl	-616(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -616(%rbp)
	jmp	LBB1_5
LBB1_12:
	movl	$0, -624(%rbp)
LBB1_13:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$9, -624(%rbp)
	jge	LBB1_16
## %bb.14:                              ##   in Loop: Header=BB1_13 Depth=1
	movq	-608(%rbp), %rax
	movslq	-624(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdi
	callq	_free
## %bb.15:                              ##   in Loop: Header=BB1_13 Depth=1
	movl	-624(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -624(%rbp)
	jmp	LBB1_13
LBB1_16:
	movq	-608(%rbp), %rdi
	callq	_free
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB1_18
## %bb.17:
	xorl	%eax, %eax
	addq	$624, %rsp                      ## imm = 0x270
	popq	%rbp
	retq
LBB1_18:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4, 0x0                          ## @__const.main.matA
l___const.main.matA:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7

	.p2align	4, 0x0                          ## @__const.main.matB
l___const.main.matB:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	7                               ## 0x7
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	8                               ## 0x8
	.long	9                               ## 0x9
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "

L_.str.1:                               ## @.str.1
	.asciz	"\n"

.subsections_via_symbols
