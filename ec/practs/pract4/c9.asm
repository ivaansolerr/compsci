.text
li $a0, '>'
li $v0,11
syscall

li $v0,5
syscall

move $a0, $v0

jal horasToSegs
move $a0, $v0
jal imprim

li $v0,10 
syscall

imprim:
	addi $v0,$0,1 #función imprim
	syscall #Escribe el valor en $a0
	li $a0, '\n' #Salto de línia
	li $v0,11
	syscall
	jr $ra 

horasToSegs:
	sll $t0, $a0, 11
	sll $t1, $a0, 10
	sll $t2, $a0, 9
	sll $t3, $a0, 4
	add $v0, $t0, $t1
	add $v0, $t2, $v0
	add $v0, $t3, $v0
	jr $ra
