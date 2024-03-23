.text 0x00400000

addi $t0, $0, 5
addi $t1, $t0, 10
add $t2, $t0, $t1
subi $t3, $t1, 30 

addi $v0, $zero, 10 #Salir del programa
syscall
