# Name : Anubhav Dinesh Patel
# Roll No : 20
# Reg No : 218

	.file	"what.c"
	.text
	.globl	what
	.type	what, @function
what:
.LFB0:
	pushq	%rbp            # push base pointer to stack
	movq	%rsp, %rbp      # copy stack pointer to base pointer
	movq	%rdi, -24(%rbp) # copy first argument into data variable
	movl	%esi, -28(%rbp) # copy second argument into no variable
	movl	$1, -12(%rbp)   # i = 1
	jmp	.L2					# jump to L2
.L8:
	movl	-12(%rbp), %eax     # %eax = i
	cltq                        # sign extend %eax
	leaq	0(,%rax,4), %rdx    # %rdx = i * 4
	movq	-24(%rbp), %rax     # %rax = &data[0]
	addq	%rdx, %rax          # %rax = &data[i]
	movl	(%rax), %eax        # %eax = data[i]
	movl	%eax, -4(%rbp)      # temp = data[i]
	movl	-12(%rbp), %eax     # %eax = i
	subl	$1, %eax            # %eax = %eax - 1
	movl	%eax, -8(%rbp)      # j = i - 1
	jmp	.L3						# jump L3
.L7:
	movl	-8(%rbp), %eax		# %eax = j
	cltq						# sign extend value in %eax
	leaq	0(,%rax,4), %rdx	# %rdx = j * 4
	movq	-24(%rbp), %rax		# %rax = &data[0]
	addq	%rdx, %rax			# %rax = &data[j]
	movl	(%rax), %eax		# %eax = data[j] (%eax = Mem[%rax])
	cmpl	%eax, -4(%rbp)		# cmp temp & %eax ( set flags for temp - %eax)
	jle	.L9						# jump to L9 if temp <= %eax
	movl	-8(%rbp), %eax		# %eax = j
	cltq						# sign extend %eax
	leaq	0(,%rax,4), %rdx	# rdx = rax * 4
	movq	-24(%rbp), %rax		# rax = &data[0]
	addq	%rdx, %rax			# %rax = &data[j] (%rax = rax + rdx) 
	movl	-8(%rbp), %edx		# %edx = j
	movslq	%edx, %rdx			# %rdx = sign-extended %edx
	addq	$1, %rdx			# %rdx = rdx + 1
	leaq	0(,%rdx,4), %rcx	# %rcx = %rdx * 4
	movq	-24(%rbp), %rdx		# %rdx = &data[0]
	addq	%rcx, %rdx			# %rdx = &data[j+1]
	movl	(%rax), %eax		# %eax = data[j]
	movl	%eax, (%rdx)		# data[j+1] = data[j]
	subl	$1, -8(%rbp)		# j = j - 1
.L3:
	cmpl	$0, -8(%rbp)    # compare j and 0 (set flags for j - 0)
	jns	.L7                 # jump to L7 if j >= 0 
	jmp	.L6					# else jump to L6
.L9:
	nop
.L6:
	movl	-8(%rbp), %eax  	# eax register = j
	cltq						# signed extension of %rax
	addq	$1, %rax			# %rax = %rax + 1
	leaq	0(,%rax,4), %rdx 	# %rdx = %rax * 4
	movq	-24(%rbp), %rax		# %rax = &data[0]
	addq	%rax, %rdx			# %rdx = &data[j+1] 
	movl	-4(%rbp), %eax		# %eax = temp
	movl	%eax, (%rdx)		# data[j+1] = temp (Mem[%rdx] = %eax)
	addl	$1, -12(%rbp)		# i = i + 1
.L2:
	movl	-12(%rbp), %eax     # put the value of i into %eax register
	cmpl	-28(%rbp), %eax     # compare i(%eax) & no
	jl	.L8                     # jump if i(%eax) < no
	nop                         
	popq	%rbp                # pop stored base address
	ret                         # return function
.LFE0:
	.size	what, .-what
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
