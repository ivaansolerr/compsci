.data

M1: .asciiz "Introduce el primer número:\n"
M2: .asciiz "Introduce el segundo número:\n"

.align 2

num1: .space 4
num2: .space 4

.text
la $a0, M1
li $v0, 4
syscall

li $v0, 5
syscall
move $t0, $v0
sw $t0,num1


la $a0, M2
li $v0, 4
syscall

li $v0, 5
syscall
move $t1, $v0
sw $t1,num2

slt $t2, $t0, $t1
beq $t2, $0, mayor2

j mayor1
 
mayor2:
move $a0, $t1
li $v0, 1
syscall
la $a0, ' '
li $v0, 11
syscall
move $a0, $t0
li $v0, 1
syscall
j final

mayor1:
move $a0, $t0
li $v0, 1
syscall
la $a0, ' '
li $v0, 11
syscall
move $a0, $t1
li $v0, 1
syscall
j final

final:
li $v0, 10
syscall