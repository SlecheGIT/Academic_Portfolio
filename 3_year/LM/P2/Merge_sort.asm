#notas de variaveis
#s0 == vetor
#s1 == quant_elementos
#t0 == validacao
#t1 == aux1
#t2 == aux2
#t3 == aux_ponteiro

MAIN:
	addi $v0, $zero, 5
	syscall
	
	add $s1, $v0, $zero #quantidade de elementos no vetor
	
	sll $a0, $s1, 2 #alocando vetor (quant_elementos *4 bytes)
	addi $v0, $zero, 9
	syscall
	
	addu $s0, $v0, $zero
	
	add $t1, $zero, $zero
	read_loop:
		slt $t0, $t1, $s1
		beq $t0, $zero, read_end
		
		addi $v0, $zero, 5
		syscall
		
		sll $t2, $t1, 2
		addu $t3, $s0, $t2
		sw $v0, 0($t3)
		
		addi $t1, $t1, 1
		j read_loop
	read_end:
	
	addu $a0, $s0, $zero
	add $a1, $zero, $zero
	addi $a2, $s1, -1
	jal MERGESORT
	
	add $t1, $zero, $zero
	print_loop:
		slt $t0, $t1, $s1
		beq $t0, $zero, print_end
		
		sll $t2, $t1, 2
		addu $t3, $s0, $t2
		
		lw $a0, 0($t3)
		addi $v0, $zero, 1
		syscall
		
		ori $a0, $zero, ' '
		addi $v0, $zero, 11
		syscall
		
		addi $t1, $t1, 1
		j print_loop
	print_end:
	
	addi $v0, $zero, 10
	syscall

#s0 == vetor completo
#s1 == inicio
#s2 == fim
MERGESORT:
	addi $sp, $sp, -20
	sw $ra, 16($sp)
	sw $s0, 12($sp)
	sw $s1, 8($sp)
	sw $s2, 4($sp)
	sw $s3, 0($sp)
	
	
	addu $s0, $a0, $zero
	add $s1, $a1, $zero
	add $s2, $a2, $zero
	
	slt $t0, $s1, $s2
	beq $t0, $zero, MergeSort_return
	
	sub $t1, $s2, $s1
	srl $t1, $t1, 1
	add $s3, $s1, $t1
	
	
	addu $a0, $s0, $zero
	add $a1, $s1, $zero
	add $a2, $s3, $zero
	jal MERGESORT
	
	addu $a0, $s0, $zero
	addi $a1, $s3, 1
	add $a2, $s2, $zero
	jal MERGESORT
	
	addu $a0, $s0, $zero
	add $a1, $s1, $zero
	add $a2, $s3, $zero
	add $a3, $s2, $zero
	jal MERGE
	
	MergeSort_return:
		lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		lw $s2, 4($sp)
		lw $s3, 0($sp)
		addi $sp, $sp, 20
		jr $ra

#s0 == subvetor maximo
#s1 == indice inicial
#s2 == indice meio
#s3 == indice final
#s4 == aux vetor esquerda
#s5 == aux vetor direita
#s6 == tamanho do subvetor esquerda
#s7 == tamanho do subvetor direita

#t4 == ponteiro de s4
#t5 == ponteiro de s5
#t6 == indice do vetor esquerda
#t7 == indice do vetor direita

MERGE:
	addi $sp, $sp, -36
	sw $ra, 32($sp)
	sw $s0, 28($sp)
	sw $s1, 24($sp)
	sw $s2, 20($sp)
	sw $s3, 16($sp)
	sw $s4, 12($sp)
	sw $s5, 8($sp)
	sw $s6, 4($sp)
	sw $s7, 0($sp)
	
	addu $s0, $a0, $zero
	add $s1, $a1, $zero
	add $s2, $a2, $zero
	add $s3, $a3, $zero
	
	sub $s6, $s2, $s1 # N1
	addi $s6, $s6, 1 
	sub $s7, $s3, $s2 #N2
	
	sll $a0, $s6, 2 #multiplica por 4 , que gera o tramanho em bytes do subvetor a ser alocado
	addi $v0, $zero, 9
	syscall
	addu $s4, $v0, $zero
	
	sll $a0, $s7, 2
	addi $v0, $zero, 9
	syscall
	addu $s5, $v0, $zero
	
	add $t1, $zero, $zero
	copy_left:
		slt $t0, $t1, $s6
		beq $t0, $zero, copy_left_end
		
		
		add $t2, $s1, $t1
		sll $t2, $t2, 2
		addu $t3, $s0, $t2
		lw $t4, 0($t3)
		
		sll $t2, $t1, 2
		addu $t3, $s4, $t2
		sw $t4, 0($t3)
		
		addi $t1, $t1, 1
		j copy_left
	copy_left_end:
	
	add $t1, $zero, $zero
	copy_right:
		slt $t0, $t1, $s7
		beq $t0, $zero, copy_right_end
		
		
		add $t2, $s2, $t1
		addi $t2, $t2, 1
		sll $t2, $t2, 2
		addu $t3, $s0, $t2
		lw $t4, 0($t3)
		
		sll $t2, $t1, 2
		addu $t3, $s5, $t2
		sw $t4, 0($t3)
		
		addi $t1, $t1, 1
		j copy_right
	copy_right_end:
	
	add $t1, $zero, $zero # i == indice da lista esquerda
	add $t2, $zero, $zero # j == indice da lista direita
	add $t3, $s1, $zero # indice da lista principal
	
	intercala:
		slt $t6, $t1, $s6
		slt $t7, $t2, $s7
		and $t0, $t6, $t7
		beq $t0, $zero, intercala_end
		
		sll $t6, $t1, 2
		addu $t6, $s4, $t6
		lw $t6, 0($t6)
		
		sll $t7, $t2, 2
		addu $t7, $s5, $t7
		lw $t7, 0($t7)
		
		slt $t0, $t7, $t6
		bne $t0, $zero, else
		if:
			sll $t4, $t3, 2
			addu $t4, $s0, $t4
			sw $t6, 0($t4)
			addi $t1, $t1, 1
			j else_end
		else:
			sll $t4, $t3, 2
			addu $t4, $s0, $t4
			sw $t7, 0($t4)
			addi $t2, $t2, 1
		else_end:
		
		addi $t3, $t3, 1
		j intercala
	intercala_end:
	
	
	resto_esquerda:
		slt $t0, $t1, $s6
		beq $t0, $zero, resto_esquerda_end
		
		sll $t6, $t1, 2
		addu $t6, $s4, $t6
		lw $t6, 0($t6)
		
		sll $t4, $t3, 2
		addu $t4, $s0, $t4
		sw $t6, 0($t4)
		
		addi $t1, $t1, 1
		addi $t3, $t3, 1
		j resto_esquerda
	resto_esquerda_end:
	
	resto_direita:
		slt $t0, $t2, $s7
		beq $t0, $zero, resto_direita_end
		
		sll $t7, $t2, 2
		addu $t7, $s5, $t7
		lw $t7, 0($t7)
		
		sll $t4, $t3, 2
		addu $t4, $s0, $t4
		sw $t7, 0($t4)
		
		addi $t2, $t2, 1
		addi $t3, $t3, 1
		j resto_direita
	resto_direita_end:

	Merge_return: #desnecessario, retirar depois
	lw $ra, 32($sp)
	lw $s0, 28($sp)
	lw $s1, 24($sp)
	lw $s2, 20($sp)
	lw $s3, 16($sp)
	lw $s4, 12($sp)
	lw $s5, 8($sp)
	lw $s6, 4($sp)
	lw $s7, 0($sp)
	addi $sp, $sp, 36
		
	jr $ra
