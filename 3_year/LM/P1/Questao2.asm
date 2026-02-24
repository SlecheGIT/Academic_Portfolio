
#s0 = vetor = V 
#s1 = numero de inteiros = n

#t0 = aux vetor
#t1 = i
#t2 = j
#t3 = aux operacoes
#t4 = 4 bytes

addi $t4, $zero, 4

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

addi $v0, $zero, 9
mul $a0, $s1, $t4
syscall
add $s0, $zero, $v0

add $t1, $zero, $zero
FOR_LEITURA:
beq $t1, $s1, FIM_LEITURA

	addi $v0, $zero, 5
	syscall
	
	add $t0, $zero, $s0
	mul $t3, $t1, $t4
	add $t0, $t0, $t3
	
	sw $v0, 0($t0)
	addi $t1, $t1, 1
	
j FOR_LEITURA
FIM_LEITURA:

add $t1, $zero, $zero

FOR_EXTERNO:
beq $t1, $s1, FIM_EXTERNO
	
	add $t2, $zero, $zero
	
	FOR_INTERNO:
	addi $t3, $t2, 1
	beq $t3, $s1, FIM_INTERNO
	
		add $t0, $zero, $s0
		mul $t3, $t2, $t4
		add $t0, $t0, $t3
		add $t3, $t0, $t4 # adicionando +1 a proxima posicao
		
		lw $t5, 0($t0)
		lw $t6, 0($t3)
		
		slt $t7, $t6, $t5
		
		beq $t7, $zero, MANTEM
		
			sw $t6, 0($t0)
			sw $t5, 0($t3)
		
		MANTEM:
		
		addi $t2, $t2, 1
		
	j FOR_INTERNO
	FIM_INTERNO:
	
	addi $t1, $t1, 1
	
j FOR_EXTERNO
FIM_EXTERNO:


add $t1, $zero, $zero
FOR_IMPRESSAO:
beq $t1, $s1, FIM_IMPRESSAO
	
	add $t0, $zero, $s0
	mul $t3, $t1, $t4
	add $t0, $t0, $t3
	
	addi $v0, $zero, 1
	lw $a0, 0($t0)
	syscall
	
	addi $v0, $zero, 11
	ori $a0, $zero, ' '
	syscall
	
	addi $t1, $t1, 1
	
j FOR_IMPRESSAO
FIM_IMPRESSAO:

addi $v0, $zero, 10
syscall


