.data
vector: .space 64
size: .word 16
msg: .asciiz "\nIntroduce los valores del vector: "

.text
la $s0, vector
la $t4, vector
lw $s1, size
la $s2, msg
li $s3, 4

loop:
	la $a0, ($s2)
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	sw $t1, 0($t4)
	
	addi $t0, $t0, 1
	sll $t2, $t0, 2
	add $t3, $t2, $s0
	move $t4, $t3
	
	bne $s1, $t0, loop

sumDig:
	lw $t1, 0($s0)
	add $t5, $t1, $t5
	addi $t7, $t7, 1
	addi $s0, $s0, 20
	bne $s3, $t7, sumDig
	

move $a0, $t5
li $v0, 1
syscall

li $v0, 10 # Acabar programa
syscall

