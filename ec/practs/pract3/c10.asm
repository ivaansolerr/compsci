.text 

etiq1: 
li $a0, '>'
li $v0, 11
syscall

li $v0,12
syscall

eitq2:
subi $a0, $v0, 48
li $v0, 1
syscall
j etiq1
