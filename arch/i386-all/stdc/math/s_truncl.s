/*
 * Based on code written by J.T. Conklin <jtc@NetBSD.org>.
 * Public domain.
 */

	#include "aros/i386/asm.h"

	.text
	_ALIGNMENT
	.globl	AROS_CDEFNAME(truncl)
	_FUNCTION(AROS_CDEFNAME(truncl))

	.set	FirstArg, 4 /* Skip Return-Adress */
	.set	arg_x, FirstArg

AROS_CDEFNAME(truncl):
	pushl	%ebp
	movl	%esp,%ebp
	subl	$8,%esp

	fstcw	-4(%ebp)		/* store fpu control word */
	movw	-4(%ebp),%dx
	orw	$0x0c00,%dx		/* round towards -oo */
	movw	%dx,-8(%ebp)
	fldcw	-8(%ebp)		/* load modfied control word */

	fldt	8(%ebp)			/* round */
	frndint

	fldcw	-4(%ebp)		/* restore original control word */

	leave
	ret
