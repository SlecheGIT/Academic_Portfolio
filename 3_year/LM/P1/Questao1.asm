
#s0 = n, s1 = V
addi $t0, $zero, 4 #tamanho do inteiro em t0=4

addi $v0, $zero, 5 #le n
syscall
add $s0, $zero, $v0 #armazena n em s0

addi $v0, $zero, 9 #codigo para alocar
mul $a0, $s0, $t0 #multiplica n por tamanho de um inteiro
syscall
add $s1, $zero, $v0 #move o endereco criado para s1
	
	
#{
add $s2, $zero, $zero #inicializa o contador em s2
FOR_LEITURA:
beq $s2, $s0, FIM_LEITURA

	addi $v0, $zero, 5
	syscall

	add $t1, $zero, $s1 # passa o primeiro endereco do vetor s1 para t1
	mul $t2, $s2, $t0 # multiplica 4 bytes pelo indice do vetor
	add $t1, $t1, $t2 # soma o vetor com a localizacao do proximo indice

	sw $v0, 0($t1) # salva a entrada na posicao calculada em t1

	addi $s2, $s2, 1 #incremento
	
j FOR_LEITURA
FIM_LEITURA:
#}

add $s2, $zero, $zero
#{
FOR_IMPRESSAO:
beq $s2, $s0, FIM_IMPRESSAO

	add $t1, $zero, $s1 # passa o primeiro endereco do vetor s1 para t1
	mul $t2, $s2, $t0 # multiplica 4 bytes pelo indice do vetor
	add $t1, $t1, $t2  # soma o vetor com a localizacao do proximo indice

	addi $v0, $zero, 1
	lw $a0, 0($t1)  # carrega a entrada na posicao calculada em t1 entao v0 = t1
	syscall

	addi $v0, $zero, 11
	ori $a0, $zero, ' '
	syscall

	addi $s2, $s2, 1
	
j FOR_IMPRESSAO
FIM_IMPRESSAO:
#}

addi $v0, $zero, 10
syscall
	
