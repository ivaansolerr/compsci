.text


li $v0, 5
syscall

move $a0, $v0
jal imprim

li $v0,10
syscall

imprim: addi $v0,$0,1 #comienza la función
syscall #Escribe un valor
li $a0, '\n' #Salto de línia
li $v0,11
syscall
jr $ra 