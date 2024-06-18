	.arch armv8-a
	.file	"plus1cpp.cpp"
	.text
	.align	2
	.global	_Z5plus1i
	.type	_Z5plus1i, %function
_Z5plus1i:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, 12]
	ldr	w0, [sp, 12]
	add	w0, w0, 1
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	_Z5plus1i, .-_Z5plus1i
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
