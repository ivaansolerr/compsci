.data
 A: .word 2, 4, 6, 8, 10 # vector A iniciado con valores
 B: .word 0:4 # Vector B vacío
 C: .space 20 # Otra definición de vector vacio
 str: .asciiz "Introduce un entero: "
 .text
la $s0, A # Dirección base del vector A
la $s1, B # Dirección base del vector B
li $s5, 5 # Tamaño del vector
li $t5, 0 # Entero a rellenar
loop:
	add $t2, $s1, $t0
	addi $s2, $s2, 1

	la $a0, str
	li $v0, 4
	syscall

	la $a0, str
	li $v0, 4 
	li $v0, 5
	syscall
	move $t3, $v0
	sw $t3, 0($t2)
	
	li $v0, 11
	la $a0, '\n'
	syscall

	sll $t0, $s2, 2 # Índice del vector x4
	bne $s2, $s5, loop
	
li $v0, 10 #Acaba el programa
syscall