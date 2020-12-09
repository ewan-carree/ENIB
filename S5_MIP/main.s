			.data
x:			.word   165
hexa_digit:	.byte   '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
s1:			.asciz  "0x10A3"        // 6 caractères + octet nul
s2:			.asciz	"l'hiver, c'est ≠ de l'été" // 25 caractères + octet nul = 30 octets


			.bss
s:			.skip   12


			.text
			.thumb
			.syntax unified
			.global main
//---------------------------------------------------------------------------
// fonction strlen : taille d'une chaîne de caractères
//   prototype : int strlen(char *s);
//   paramètres d'entrée
//     r0 : pointeur sur la chaîne
//   valeurs renvoyées
//     r0 : taille
//---------------------------------------------------------------------------
			.type	strlen, %function
			
strlen:			mov r1, #0 // on met 0 dans r1
s_loop:			ldrb r2, [r0], #1 // r2 = *r0; r0+=1
			cmp r2, #0 // on compare la valeur de r2 a 0
			beq s_end // si c'est égal à 0, on sort de la boucle
			add r1, r1, #1 // on met dans r1 la valeur r1 + 1
			b s_loop // on reboucle
s_end: 			mov r0, r1 // on deplace r1 dans r0
			mov pc, lr
			
        	.size	strlen, .-strlen
        
//---------------------------------------------------------------------------
// fonction asciihexa2uint : conversion chaîne de caractères hexa --> entier
//   paramètres d'entrée
//     r0 : pointeur sur la chaîne
//   valeurs renvoyées
//     r0 : valeur entière
//---------------------------------------------------------------------------
			.type	asciihexa2uint, %function
			
asciihexa2uint:		add r0, r0, #2 // on se place à la valeur hexadecimale en sautant "0x"
			mov r2, #0 // r2 = d = 0
			
a_loop:			ldrb r1, [r0], #1 // lecture caractère et autoincrementation
			cmp r1, #'0' //0x30 ou 48
			blo a_end // si inferieur a '0', on branche a a_end
			cmp r1, #'9' 
			bhi a_testAF // si superieur a 9, on branche a a_testAF car c'est forcement autre chose qu'un chiffre
			sub r1, r1, #'0' //on met dans r1 la valeur de r1 moins le code ascii du caractere '0'
			b a_suite

a_testAF:		cmp r1, #'A'
			blo a_end // si inferieur a 'A', on branche a a_end
			cmp r1, #'F' 
			bhi a_testaf // si superieur a F, on branche a a_testas car c'est forcement autre chose qu'une majuscule
			sub r1, r1, #'A' //on met dans r1 la valeur de r1 moins le code ascii du caractere 'A'
			add r1, r1, #10 // on ajoute 10 a r1
			b a_suite

a_testaf:		cmp r1, #'a'
			blo a_end // si inferieur a 'a', on branche a a_end
			cmp r1, #'f' 
			bhi a_end // si sperieur a 'f', on branche a a_end
			sub r1, r1, #'a' //on met dans r1 la valeur de r1 moins le code ascii du caractere 'A'
			add r1, r1, #10 // on ajoute 10 a r1
			b a_suite

a_suite: 		//d = 16d+digit
			mov r12, #16
			mul r2, r2, r12
			add r2, r2, r1 
			b a_loop

a_end:			mov r0, r2			
			mov pc, lr
			
        	.size	asciihexa2uint, .-asciihexa2uint
        
//---------------------------------------------------------------------------
// fonction uint2asciihexa : conversion entier --> chaîne de caractères hexa
//   prototype : void uint2asciihexa(uint32_t d, char *s);
//   paramètres d'entrée
//     r0 : valeur entière
//     r1 : pointeur sur la chaîne
//---------------------------------------------------------------------------
			.type	uint2asciihexa, %function
uint2asciihexa:

			
			
			mov		pc, lr
			
        	.size	uint2asciihexa, .-uint2asciihexa
        	
//---------------------------------------------------------------------------
// fonction main
//---------------------------------------------------------------------------
main:		// test strlen
			/* PASSAGE DE PARAMETRES A COMPLETER */

			bl		strlen
        
			// test asciihexa2uint
			/* PASSAGE DE PARAMETRES A COMPLETER */
			ldr r0, = s1
			bl		asciihexa2uint

			// test uint2asciihexa
			/* PASSAGE DE PARAMETRES A COMPLETER */
			ldr r0, =x
			bl		uint2asciihexa
        
        	// test strlen8
			/* PASSAGE DE PARAMETRES A COMPLETER
			bl		strlen8 */

theend:		b       theend

//---------------------------------------------------------------------------
       
