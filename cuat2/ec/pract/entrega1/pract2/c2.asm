.text 0x00400000

addi $v0, $zero, 5 #Salir del programa
syscall

subi $a0, $v0, 1
addi $v0, $zero, 1 #Salir del programa
syscall

addi $v0, $zero, 10 #Salir del programa
syscall