####################################
# #
# Código ejemplo #
# if-then-else #
# #
####################################

.text

li $v0, 5
syscall 
move $s1, $v0

li $v0, 5
syscall
move $s2, $v0

slt $t2, $s1, $s2
beq $t2, $zero, imprimirA

j imprimirB

imprimirA:
	move $a0, $s1
	li $v0, 1
	syscall
	j final
	
imprimirB:
	move $a0, $s2
	li $v0, 1
	syscall
	j final
	
final:
	li $v0, 10
	syscall