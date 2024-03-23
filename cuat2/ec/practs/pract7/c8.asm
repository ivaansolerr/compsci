.data

vector: .word -4, 5, 8, -1

msg1: .asciiz "\n La suma de los valores positivos és = "
msg2: .asciiz "\n La suma de los valores negativos és = "


.text

Principal:

li $v0, 4 # Función para imprimir string
la $a0, msg1 # Leer la dirección de msg1
syscall

la $a0, vector # dirección del vector como parámetro
li $a1, 4 # Longitud del vector como parámetro

jal sum # Llamada a la función sum

move $a0, $v0 # Resultado 1 de la función
li $v0, 1
syscall # Imprimir suma positivos



li $v0, 4
la $a0, msg2
syscall

jal sum # Llamada a la función sum

move $a0, $v1 # Resultado 2 de la función
li $v0, 1
syscall # imprimir suma negativos

li $v0, 10 # Acabar programa
syscall

####################################
# Funciones #
####################################
#sum: 
	# we have to add a loop
