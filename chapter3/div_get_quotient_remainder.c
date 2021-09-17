void remdiv(long x, long y,
            long *qp, long *rp)
{
    long q = x / y;
    long r = x % y;
    *qp = q;
    *rp = r;
}

// remdiv:
// x in %rdi, y in %rsi, qp in %rdx, rp in %rcx
// 	movq	%rdi, %rax
// 	movq	%rdx, %r8
// 	cqto
// 	idivq	%rsi
// 	movq	%rax, (%r8)
// 	movq	%rdx, (%rcx)
// 	ret

// idivq makes such effect
// R[%rdx] <= R[%rdx]:R[%rax] mod S,
// and R[%rax] <= R[%rdx]:R[%rax] / 10

// In this code, argument rp must first be saved in a different register (movq	%rdx, %r8),
// since argument register %rdx is required for the division operation.