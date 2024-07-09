	.arch armv8-a
	.file	"sum-v3.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.align	2
	.p2align 4,,11
	.global	_Z9fillArrayPii
	.type	_Z9fillArrayPii, %function
_Z9fillArrayPii:
.LFB2055:
	.cfi_startproc
	cmp	w1, 0
	ble	.L7
	tst	x1, 3
	beq	.L7
	mov	w2, 0
	b	.L3
	.p2align 2,,3
.L12:
	tst	x4, 3
	beq	.L11
.L3:
	str	w2, [x0], 4
	add	w2, w2, 1
	subs	w4, w1, w2
	bne	.L12
.L2:
#APP
// 17 "sum-v3.cpp" 1
	dup v0.4S, w1
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
	cmp	w4, 0
	ble	.L1
	sub	w1, w4, #1
	lsr	w1, w1, 2
	add	w1, w1, 1
	ubfiz	x1, x1, 4, 31
	add	x1, x0, x1
	.p2align 3,,7
.L5:
#APP
// 32 "sum-v3.cpp" 1
	st1 {v0.4S}, [x0]
// 0 "" 2
// 34 "sum-v3.cpp" 1
	add v0.4S, v0.4S, v1.4S
// 0 "" 2
#NO_APP
	add	x0, x0, 16
	cmp	x1, x0
	bne	.L5
.L1:
	ret
	.p2align 2,,3
.L11:
	mov	w1, w2
	b	.L2
	.p2align 2,,3
.L7:
	mov	w4, w1
	mov	w1, 0
	b	.L2
	.cfi_endproc
.LFE2055:
	.size	_Z9fillArrayPii, .-_Z9fillArrayPii
	.align	2
	.p2align 4,,11
	.global	_Z8sumArrayPii
	.type	_Z8sumArrayPii, %function
_Z8sumArrayPii:
.LFB2056:
	.cfi_startproc
	mov	x4, x0
	cmp	w1, 0
	ble	.L19
	sub	w0, w1, #1
	cmp	w0, 2
	bls	.L20
	lsr	w3, w1, 2
	mov	x2, x4
	movi	v0.4s, 0
	add	x3, x4, w3, uxtw 4
	.p2align 3,,7
.L16:
	ldr	q1, [x2], 16
	saddw	v0.2d, v0.2d, v1.2s
	saddw2	v0.2d, v0.2d, v1.4s
	cmp	x3, x2
	bne	.L16
	addp	d0, v0.2d
	and	w2, w1, -4
	fmov	x0, d0
	cmp	w1, w2
	beq	.L13
.L15:
	ldrsw	x5, [x4, w2, sxtw 2]
	add	w3, w2, 1
	sbfiz	x6, x2, 2, 32
	add	x0, x0, x5
	cmp	w1, w3
	ble	.L13
	add	x4, x4, x6
	add	w2, w2, 2
	ldrsw	x3, [x4, 4]
	add	x0, x0, x3
	cmp	w1, w2
	ble	.L13
	ldrsw	x1, [x4, 8]
	add	x0, x0, x1
.L13:
	ret
	.p2align 2,,3
.L19:
	mov	x0, 0
	ret
.L20:
	mov	w2, 0
	mov	x0, 0
	b	.L15
	.cfi_endproc
.LFE2056:
	.size	_Z8sumArrayPii, .-_Z8sumArrayPii
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	"sum: "
	.section	.text.startup,"ax",@progbits
	.align	2
	.p2align 4,,11
	.global	main
	.type	main, %function
main:
.LFB2057:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x0, 33820
	movk	x0, 0x17d7, lsl 16
	mov	x29, sp
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -16
	.cfi_offset 20, -8
	bl	_Znam
	mov	w1, 57607
	mov	x5, x0
	movk	w1, 0x5f5, lsl 16
	movi	v0.4s, 0
	bl	_Z9fillArrayPii
	mov	x0, 33808
	mov	x1, x5
	movk	x0, 0x17d7, lsl 16
	add	x0, x5, x0
	.p2align 3,,7
.L23:
	ldr	q1, [x1], 16
	saddw	v0.2d, v0.2d, v1.2s
	saddw2	v0.2d, v0.2d, v1.4s
	cmp	x1, x0
	bne	.L23
	addp	d0, v0.2d
	mov	x0, 32768
	movk	x0, 0x17d7, lsl 16
	add	x5, x5, x0
	adrp	x0, :got:_ZSt4cout
	ldr	x0, [x0, :got_lo12:_ZSt4cout]
	mov	x2, 5
	fmov	x3, d0
	ldrsw	x4, [x5, 1048]
	ldrsw	x6, [x5, 1044]
	adrp	x1, .LC0
	ldrsw	x19, [x5, 1040]
	add	x1, x1, :lo12:.LC0
	add	x3, x4, x3
	add	x19, x19, x6
	add	x19, x19, x3
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	adrp	x0, :got:_ZSt4cout
	ldr	x0, [x0, :got_lo12:_ZSt4cout]
	mov	x1, x19
	bl	_ZNSo9_M_insertImEERSoT_
	mov	x19, x0
	ldr	x0, [x0]
	ldr	x0, [x0, -24]
	add	x0, x19, x0
	ldr	x20, [x0, 240]
	cbz	x20, .L29
	ldrb	w0, [x20, 56]
	cbz	w0, .L25
	ldrb	w1, [x20, 67]
.L26:
	mov	x0, x19
	bl	_ZNSo3putEc
	bl	_ZNSo5flushEv
	ldp	x19, x20, [sp, 16]
	mov	w0, 0
	ldp	x29, x30, [sp], 32
	.cfi_remember_state
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_restore 20
	.cfi_def_cfa_offset 0
	ret
.L25:
	.cfi_restore_state
	mov	x0, x20
	bl	_ZNKSt5ctypeIcE13_M_widen_initEv
	ldr	x2, [x20]
	mov	w1, 10
	mov	x0, x20
	ldr	x2, [x2, 48]
	blr	x2
	and	w1, w0, 255
	b	.L26
.L29:
	bl	_ZSt16__throw_bad_castv
	.cfi_endproc
.LFE2057:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
