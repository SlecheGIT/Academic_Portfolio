
#s0 = numero de inteiros
#s1 = vetor
#s2 = somatoria
#s3 = quantidade de impar
#s4 = quantidade de par

#t0 = indice
#t1 = ponteiro de vetor
#t2 = auxiliar em contas
#t3 = load do vetor
#t4 = tamanho de um inteiro

addi $t4, $zero, 4 # t1 = 4 - numero de bytes
add $s2, $zero, $zero
add $s3, $zero, $zero
add $s4, $zero, $zero

addi $v0, $zero, 5 # 5 de leitura de inteiro
syscall
add $s0, $zero, $v0 #s0 = n - numero de entradas

addi $v0, $zero, 9 # 11 de alocacao
mul $a0, $s0, $t4 # multiplica a entrada pelos bytes necessarios para cada inteiro
syscall
add $s1, $zero, $v0 # enderecando s1 com o vetor criado

add $t0, $zero, $zero
#{
FOR_LEITURA:
beq $t0, $s0, FIM_LEITURA

	addi $v0, $zero, 5 # entrada de inteiros
	syscall
	
	add $t1, $zero, $s1 # endereco para o calculo do endereco
	mul $t2, $t0, $t4 # calcula o indice para somar ao endereco
	add $t1, $t1, $t2 # chega ao endereco da posicao desejada
	
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	
j FOR_LEITURA
FIM_LEITURA:
#}

add $t0, $zero, $zero
#{
FOR_CONTADORES:
beq $t0, $s0, FIM_CONTADORES
	
	add $t1, $zero, $s1
	mul $t2, $t0, $t4
	add $t1, $t1, $t2
	
	lw $t3, 0($t1)
	add $s2, $s2, $t3
	
	andi $t2, $t3, 1
	add $s3, $s3, $t2 # se for impar ele adicionara 1 caso contrario 0
	
	bne $t2, $zero, IF_NOT_PAIR
		addi $s4, $s4, 1
	IF_NOT_PAIR:
	
	addi $t0, $t0, 1
j FOR_CONTADORES
FIM_CONTADORES:
#}

addi $v0, $zero, 1
add $a0, $zero, $s2
syscall # imprime a somatoria

addi $v0, $zero, 11
ori $a0, $zero, ','
syscall 

addi $v0, $zero, 1
add $a0, $zero, $s3
syscall # imprime quantos impar

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall
ori $a0, $zero, 'e'
syscall
ori $a0, $zero, ' '
syscall

addi $v0, $zero, 1
add $a0, $zero, $s4
syscall # imprime quantos par

addi $v0, $zero, 10
syscall
