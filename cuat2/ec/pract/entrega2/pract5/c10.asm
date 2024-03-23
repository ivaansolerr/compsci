li $v0, 5
syscall
move $t0, $v0

li $v0, 5
syscall
move $t1, $v0

sle $t3,$t0,$t1
beq $t3, $0, final_for

inicio_for:
	li $a0, '\n' 
	li $v0, 11
	syscall

	addi $a0, $t0, 0
	li $v0, 1
	syscall

	beq $t0, $t1, final_for
	addi $t0, $t0, 1
		
	j inicio_for

final_for:
	li $v0, 10
	syscall
		
