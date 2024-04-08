	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_matrix_multiply1               ## -- Begin function matrix_multiply1
	.p2align	4, 0x90
_matrix_multiply1:                      ## @matrix_multiply1
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
	cmpl	$50, -28(%rbp)
	jge	LBB0_12
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -32(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_5 Depth 3
	cmpl	$50, -32(%rbp)
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
	cmpl	$70, -36(%rbp)
	jge	LBB0_8
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=3
	movq	-8(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-36(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
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
	subq	$96, %rsp
	movl	$0, -4(%rbp)
	movl	$400, %edi                      ## imm = 0x190
	callq	_malloc
	movq	%rax, -48(%rbp)
	movl	$0, -52(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$50, -52(%rbp)
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	$200, %edi
	callq	_malloc
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	%rdx, (%rax,%rcx,8)
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB1_1
LBB1_4:
	movl	$400, %edi                      ## imm = 0x190
	callq	_malloc
	movq	%rax, -32(%rbp)
	movl	$0, -56(%rbp)
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$50, -56(%rbp)
	jge	LBB1_8
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=1
	movl	$280, %edi                      ## imm = 0x118
	callq	_malloc
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movslq	-56(%rbp), %rcx
	movq	%rdx, (%rax,%rcx,8)
## %bb.7:                               ##   in Loop: Header=BB1_5 Depth=1
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	jmp	LBB1_5
LBB1_8:
	movl	$560, %edi                      ## imm = 0x230
	callq	_malloc
	movq	%rax, -40(%rbp)
	movl	$0, -60(%rbp)
LBB1_9:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$70, -60(%rbp)
	jge	LBB1_12
## %bb.10:                              ##   in Loop: Header=BB1_9 Depth=1
	movl	$200, %edi
	callq	_malloc
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movslq	-60(%rbp), %rcx
	movq	%rdx, (%rax,%rcx,8)
## %bb.11:                              ##   in Loop: Header=BB1_9 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB1_9
LBB1_12:
	leaq	L_.str(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	callq	_fopen
	movq	%rax, -16(%rbp)
	movl	$0, -64(%rbp)
LBB1_13:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_15 Depth 2
	cmpl	$50, -64(%rbp)
	jge	LBB1_20
## %bb.14:                              ##   in Loop: Header=BB1_13 Depth=1
	movl	$0, -68(%rbp)
LBB1_15:                                ##   Parent Loop BB1_13 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$70, -68(%rbp)
	jge	LBB1_18
## %bb.16:                              ##   in Loop: Header=BB1_15 Depth=2
	movq	-16(%rbp), %rdi
	movq	-32(%rbp), %rax
	movslq	-64(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdx
	movslq	-68(%rbp), %rax
	shlq	$2, %rax
	addq	%rax, %rdx
	leaq	L_.str.2(%rip), %rsi
	movb	$0, %al
	callq	_fscanf
## %bb.17:                              ##   in Loop: Header=BB1_15 Depth=2
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	jmp	LBB1_15
LBB1_18:                                ##   in Loop: Header=BB1_13 Depth=1
	jmp	LBB1_19
LBB1_19:                                ##   in Loop: Header=BB1_13 Depth=1
	movl	-64(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -64(%rbp)
	jmp	LBB1_13
LBB1_20:
	movl	$0, -72(%rbp)
LBB1_21:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_23 Depth 2
	cmpl	$70, -72(%rbp)
	jge	LBB1_28
## %bb.22:                              ##   in Loop: Header=BB1_21 Depth=1
	movl	$0, -76(%rbp)
LBB1_23:                                ##   Parent Loop BB1_21 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$50, -76(%rbp)
	jge	LBB1_26
## %bb.24:                              ##   in Loop: Header=BB1_23 Depth=2
	movq	-16(%rbp), %rdi
	movq	-40(%rbp), %rax
	movslq	-72(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdx
	movslq	-76(%rbp), %rax
	shlq	$2, %rax
	addq	%rax, %rdx
	leaq	L_.str.2(%rip), %rsi
	movb	$0, %al
	callq	_fscanf
## %bb.25:                              ##   in Loop: Header=BB1_23 Depth=2
	movl	-76(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -76(%rbp)
	jmp	LBB1_23
LBB1_26:                                ##   in Loop: Header=BB1_21 Depth=1
	jmp	LBB1_27
LBB1_27:                                ##   in Loop: Header=BB1_21 Depth=1
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	jmp	LBB1_21
LBB1_28:
	movq	-32(%rbp), %rdi
	movq	-40(%rbp), %rsi
	movq	-48(%rbp), %rdx
	callq	_matrix_multiply1
	leaq	L_.str.3(%rip), %rdi
	leaq	L_.str.4(%rip), %rsi
	callq	_fopen
	movq	%rax, -24(%rbp)
	movl	$0, -80(%rbp)
LBB1_29:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_31 Depth 2
	cmpl	$50, -80(%rbp)
	jge	LBB1_36
## %bb.30:                              ##   in Loop: Header=BB1_29 Depth=1
	movl	$0, -84(%rbp)
LBB1_31:                                ##   Parent Loop BB1_29 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$50, -84(%rbp)
	jge	LBB1_34
## %bb.32:                              ##   in Loop: Header=BB1_31 Depth=2
	movq	-24(%rbp), %rdi
	movq	-48(%rbp), %rax
	movslq	-80(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-84(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	leaq	L_.str.2(%rip), %rsi
	movb	$0, %al
	callq	_fprintf
## %bb.33:                              ##   in Loop: Header=BB1_31 Depth=2
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -84(%rbp)
	jmp	LBB1_31
LBB1_34:                                ##   in Loop: Header=BB1_29 Depth=1
	movq	-24(%rbp), %rdi
	leaq	L_.str.5(%rip), %rsi
	movb	$0, %al
	callq	_fprintf
## %bb.35:                              ##   in Loop: Header=BB1_29 Depth=1
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	jmp	LBB1_29
LBB1_36:
	movl	$0, -88(%rbp)
LBB1_37:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$50, -88(%rbp)
	jge	LBB1_40
## %bb.38:                              ##   in Loop: Header=BB1_37 Depth=1
	movq	-48(%rbp), %rax
	movslq	-88(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdi
	callq	_free
	movq	-32(%rbp), %rax
	movslq	-88(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdi
	callq	_free
## %bb.39:                              ##   in Loop: Header=BB1_37 Depth=1
	movl	-88(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -88(%rbp)
	jmp	LBB1_37
LBB1_40:
	movq	-48(%rbp), %rdi
	callq	_free
	movq	-32(%rbp), %rdi
	callq	_free
	movl	$0, -92(%rbp)
LBB1_41:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$70, -92(%rbp)
	jge	LBB1_44
## %bb.42:                              ##   in Loop: Header=BB1_41 Depth=1
	movq	-40(%rbp), %rax
	movslq	-92(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdi
	callq	_free
## %bb.43:                              ##   in Loop: Header=BB1_41 Depth=1
	movl	-92(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -92(%rbp)
	jmp	LBB1_41
LBB1_44:
	movq	-40(%rbp), %rdi
	callq	_free
	movq	-16(%rbp), %rdi
	callq	_fclose
	movq	-24(%rbp), %rdi
	callq	_fclose
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"matrices.txt"

L_.str.1:                               ## @.str.1
	.asciz	"r"

L_.str.2:                               ## @.str.2
	.asciz	"%d "

L_.str.3:                               ## @.str.3
	.asciz	"output.txt"

L_.str.4:                               ## @.str.4
	.asciz	"w+"

L_.str.5:                               ## @.str.5
	.asciz	"\n"

L_.str.6:                               ## @.str.6
	.asciz	"\t<output.txt generated>\n"

.subsections_via_symbols
