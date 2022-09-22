	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 1
	.globl	__Z5g_funv              ## -- Begin function _Z5g_funv
	.p2align	4, 0x90
__Z5g_funv:                             ## @_Z5g_funv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, %rax
	xorl	%esi, %esi
	movq	%rdi, %rcx
	movq	%rcx, -8(%rbp)
	movb	$0, -9(%rbp)
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	__ZN8CExampleC1Ei
	movb	$1, -9(%rbp)
	testb	$1, -9(%rbp)
	jne	LBB0_2
## %bb.1:
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN8CExampleD1Ev
LBB0_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN8CExampleC1Ei       ## -- Begin function _ZN8CExampleC1Ei
	.weak_def_can_be_hidden	__ZN8CExampleC1Ei
	.p2align	4, 0x90
__ZN8CExampleC1Ei:                      ## @_ZN8CExampleC1Ei
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	callq	__ZN8CExampleC2Ei
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN8CExampleD1Ev       ## -- Begin function _ZN8CExampleD1Ev
	.weak_def_can_be_hidden	__ZN8CExampleD1Ev
	.p2align	4, 0x90
__ZN8CExampleD1Ev:                      ## @_ZN8CExampleD1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN8CExampleD2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN8CExampleC2Ei       ## -- Begin function _ZN8CExampleC2Ei
	.weak_def_can_be_hidden	__ZN8CExampleC2Ei
	.p2align	4, 0x90
__ZN8CExampleC2Ei:                      ## @_ZN8CExampleC2Ei
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %ecx
	movl	%ecx, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN8CExampleD2Ev       ## -- Begin function _ZN8CExampleD2Ev
	.weak_def_can_be_hidden	__ZN8CExampleD2Ev
	.p2align	4, 0x90
__ZN8CExampleD2Ev:                      ## @_ZN8CExampleD2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
