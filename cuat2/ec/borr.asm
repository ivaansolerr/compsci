.text
li $t0, 0x12345678

sll $t1, $t0, 4
srl $t2, $t0, 4

move $a0, $t1
li $v0, 1
syscall

move $a0, $t1
li $v0, 1
syscall