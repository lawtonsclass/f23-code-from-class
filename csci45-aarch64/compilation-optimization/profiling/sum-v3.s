	.arch armv8-a
	.file	"sum-v3.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.align	2
	.global	_Z9fillArrayPii
	.type	_Z9fillArrayPii, %function
_Z9fillArrayPii:
.LFB1986:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, 8]
	str	w1, [sp, 4]
	str	wzr, [sp, 28]
	b	.L2
.L4:
	ldr	x0, [sp, 8]
	ldr	w1, [sp, 28]
	str	w1, [x0]
	ldr	w0, [sp, 28]
	add	w0, w0, 1
	str	w0, [sp, 28]
	ldr	x0, [sp, 8]
	add	x0, x0, 4
	str	x0, [sp, 8]
	ldr	w0, [sp, 4]
	sub	w0, w0, #1
	str	w0, [sp, 4]
.L2:
	ldr	w0, [sp, 4]
	cmp	w0, 0
	ble	.L3
	ldr	w0, [sp, 4]
	and	w0, w0, 3
	cmp	w0, 0
	bne	.L4
.L3:
	ldr	w0, [sp, 28]
#APP
// 17 "sum-v3.cpp" 1
	dup v0.4S, w0
// 0 "" 2
// 18 "sum-v3.cpp" 1
	mov w3, #0
	mov v1.4S[0], w3
	mov w3, #1
	mov v1.4S[1], w3
	mov w3, #2
	mov v1.4S[2], w3
	mov w3, #3
	mov v1.4S[3], w3
	add v0.4S, v0.4S, v1.4S
// 0 "" 2
// 28 "sum-v3.cpp" 1
	movi v1.4S, #4
// 0 "" 2
#NO_APP
	b	.L5
.L6:
	ldr	x0, [sp, 8]
#APP
// 32 "sum-v3.cpp" 1
	st1 {v0.4S}, [x0]
// 0 "" 2
// 34 "sum-v3.cpp" 1
	add v0.4S, v0.4S, v1.4S
// 0 "" 2
#NO_APP
	ldr	x0, [sp, 8]
	add	x0, x0, 16
	str	x0, [sp, 8]
	ldr	w0, [sp, 4]
	sub	w0, w0, #4
	str	w0, [sp, 4]
.L5:
	ldr	w0, [sp, 4]
	cmp	w0, 0
	bgt	.L6
	nop
	nop
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1986:
	.size	_Z9fillArrayPii, .-_Z9fillArrayPii
	.align	2
	.global	_Z8sumArrayPii
	.type	_Z8sumArrayPii, %function
_Z8sumArrayPii:
.LFB1987:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, 8]
	str	w1, [sp, 4]
	str	xzr, [sp, 24]
	str	wzr, [sp, 20]
	b	.L8
.L9:
	ldrsw	x0, [sp, 20]
	lsl	x0, x0, 2
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldr	w0, [x0]
	sxtw	x0, w0
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	str	x0, [sp, 24]
	ldr	w0, [sp, 20]
	add	w0, w0, 1
	str	w0, [sp, 20]
.L8:
	ldr	w1, [sp, 20]
	ldr	w0, [sp, 4]
	cmp	w1, w0
	blt	.L9
	ldr	x0, [sp, 24]
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1987:
	.size	_Z8sumArrayPii, .-_Z8sumArrayPii
	.section	.rodata
	.align	3
.LC0:
	.string	"sum: "
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB1988:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	mov	w0, 57607
	movk	w0, 0x5f5, lsl 16
	str	w0, [sp, 28]
	ldrsw	x0, [sp, 28]
	mov	x1, 2305843009213693950
	cmp	x0, x1
	bhi	.L12
	lsl	x0, x0, 2
	b	.L15
.L12:
	bl	__cxa_throw_bad_array_new_length
.L15:
	bl	_Znam
	str	x0, [sp, 32]
	ldr	w1, [sp, 28]
	ldr	x0, [sp, 32]
	bl	_Z9fillArrayPii
	ldr	w1, [sp, 28]
	ldr	x0, [sp, 32]
	bl	_Z8sumArrayPii
	str	x0, [sp, 40]
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, :got:_ZSt4cout
	ldr	x0, [x0, :got_lo12:_ZSt4cout]
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	ldr	x1, [sp, 40]
	bl	_ZNSolsEm
	adrp	x1, :got:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	ldr	x1, [x1, :got_lo12:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	bl	_ZNSolsEPFRSoS_E
	mov	w0, 0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1988:
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, %object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
