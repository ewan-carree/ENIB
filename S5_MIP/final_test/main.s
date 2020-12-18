        	.data
upper:		.word 0
tab10:  	.word   100, 10, 1, 0
tbz:		.asciz	"c'Est_uN_(1)_TeXTe_bIZarRE_!"
			.align

			.bss
out:		.skip	40



        	.text
			.thumb
			.syntax unified
			.global main

/* int conv(char* s, unsigned int val)
 *   int to ascii (decimal) conversion
 * parameters
 *   r0 = s
 *   r1 = val
 *  return value
 *   r0 = number of chars used for conversion
 */
			.type	conv, %function
conv:		push	{r4-r6, lr}
			mov		r6, r0
			ldr		r2,=tab10
			mov		r5, #0
c_l1:		ldr		r3, [r2], #4
			cmp		r3, #0
			beq		c_end
			mov		r4,#0x30
c_l2:		cmp		r1, r3
			blt		c_l2e
			sub		r1, r1, r3
			add		r4, r4, #1
			b		c_l2
c_l2e:		cmp		r5, #0
			bne		c_l3
			cmp		r4, #0x30
			beq		c_l4
c_l3:		mov		r5, #1
c_l4:		cmp		r5, #1
			bne		c_l1
			strb	r4, [r0], #1
			b		c_l1
c_end:		sub		r0, r0, r6
			pop		{r4-r6, pc}
        	.size	conv, .-conv

// helper function
			.type	clear_buf, %function
clear_buf:	ldr		r0, =out
			mov		r1, #40
			mov		r2,#0
cl_loop:	strb	r2, [r0], #1
			subs	r1, r1, #1
			bne		cl_loop
			mov		pc, lr
        	.size	clear_buf, .-clear_buf






			
/* void to_lower(char*in, char*out)
 *   copie la chaîne in dans la chaîne out en la transformant
 *   en minuscule.
 *   Paramètre d'entrée
 *   - r0 : contient l'adresse de la chaîne in
 *   - r1 : contient l'adresse de la chaîne out
 */
			.type	to_lower, %function
to_lower:	
loop:		ldrb r3, [r0], #1
		cmp r3, #0
		beq end
		b test_AZ
		
test_AZ:	cmp r3, 'A'
		blo notAZ
		cmp r3, 'Z'
		bhi notAZ
		b AZ
		
notAZ:		strb r3, [r1], #1
		b loop

AZ:		add r3, r3, #0x20
		strb r3, [r1], #1
		b loop

end:		mov r3, r1
		mov pc, lr
        	.size	to_lower, .-to_lower










/* void to_upper(char*in, char*out)
 *   copie la chaîne in dans la chaîne out en la transformant
 *   en majuscule.
 *   Paramètre d'entrée
 *   - r0 : contient l'adresse de la chaîne in
 *   - r1 : contient l'adresse de la chaîne out
 */
			.type	to_upper, %function
to_upper:	
loop2:		ldrb r3, [r0], #1
		cmp r3, #0
		beq end2
		b test_az
		
test_az:	cmp r3, 'a'
		blo notaz
		cmp r3, 'z'
		bhi notaz
		b az
		
notaz:		strb r3, [r1], #1
		b loop2

az:		sub r3, r3, #0x20
		strb r3, [r1], #1
		b loop2

end2:		mov r3, r1
		mov pc, lr
        	.size	to_upper, .-to_upper






/* void fix_case(char*s, int upper)
 *   modifie la casse dans la chaîne s en fonction du paramètre
 *   upper. Si upper=0, la chaîne est transformée en minuscule.
 *   Si upper=1, la chaîne est transformée en majuscule.
 *   Paramètre d'entrée
 *   - r0 : contient l'adresse de la chaîne s
 *   - r1 : contient upper
 */
			.type	fix_case, %function
fix_case:	
		cmp r1, #0
		beq to_lower2
		b to_upper

        	.size	fix_case, .-fix_case


to_lower2:	
loop4:		ldrb r3, [r0], #1
		cmp r3, #0
		beq end5
		b test_AZ2
		
test_AZ2:	cmp r3, 'A'
		blo notAZ2
		cmp r3, 'Z'
		bhi notAZ2
		b AZ2
		
notAZ2:		strb r3, [r0]
		b loop4

AZ2:		add r3, r3, #0x20
		strb r3, [r0]
		b loop4

end5:		mov r3, r1
		mov pc, lr
        	.size	to_lower, .-to_lower












underscore: 	
loop3:		ldrb r3, [r0], #1
		cmp r3, #0
		beq end3
		b test_undersc

test_undersc:	cmp r3, #0x5F
		beq is_undersc
		b not_undersc

is_undersc:	sub r3, r3, #0x3F
		strb r3, [r1], #1
		b loop3

not_undersc:	strb r3, [r1], #1
		b loop3

end3:		mov r3, r1
		mov pc, lr
        	.size	underscore, .-underscore
		





		
//----------------------------------------------------------------------------
// fonction main
//----------------------------------------------------------------------------
main:		// test 'to_lower' function
			ldr		r0,=tbz
			ldr		r1,=out
			bl		to_lower
			
			bl		clear_buf
			
			// test 'to_upper' function
			ldr		r0,=tbz
			ldr		r1,=out
			bl		to_upper
			
			bl		clear_buf
			
			// test 'fix_case' function
			ldr		r0,=tbz
			ldr		r1,=upper
			ldr 		r1,[r1]
			bl		fix_case

			bl		clear_buf

			
			ldr		r0,=tbz
			ldr		r1,=out
			bl		underscore

			bl		clear_buf
			
			nop
theend: 	b       theend
