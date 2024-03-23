.text 

li $a0, '>'
li $v0,11
syscall
li $v0,5
syscall
move $a0, $v0
jal mult10 
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

mult10:
	sll $t0, $a0,  
	sll $t1, $a0, 1 
	add $v0, $t0, $t1
	jr $ra
