.text

li $a0, '>'
li $v0, 11
syscall

li $v0, 12
syscall
move $t0, $v0

li $a0,'\n'
li $v0, 11
syscall

move $a0, $t0
li $v0, 34
syscall

li $v0, 10
syscall