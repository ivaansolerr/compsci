.data
str: .word 2,4,6,8,10,0

.text
la $s0, str
add $s1, $zero, $zero # Iniciamos contador a 0

loop:
	addi $t0, $s0, 4 # dirección del byte a examinar
	lw $t1, 0( $t0 )
	
	move $a0, $t1
	li $v0, 11
	syscall
	
	beq $t1, $zero, exit # salimos si carácter leído='\0'
	addi $s1, $s1, 1 # incrementamos el contador

j loop

exit:
	li $v0, 10
        syscall

 

