DEF_DESVIO_PADRAO:
    addiu $sp, $sp, -20
    sw $ra, 16($sp)
    sw $s0, 12($sp)         # pilha
    sw $s1, 8($sp)          # cont_elementos
    sw $s2, 4($sp)         
    sw $s3, 0($sp)          
    
    addu $s0, $a0, $zero    # $s0 = pilha
    addu $s1, $a1, $zero    # $s1 = cont_elementos
    
    addu $t0, $s1, $zero
    addu $t1, $zero, $zero
    
    beq $s1, $zero, desvio_overflow

	sum_while_desvio:
		beq $t0, $zero, sum_while_desvio_end
		addiu $t0, $t0, -1
		sll $t2, $t0, 2
		addu $t2, $s0, $t2
		lw $t3, 0($t2)
		addu $t1, $t1, $t3      # somatoria
		j sum_while_desvio
	sum_while_desvio_end:

	sll $s2, $t1, 6         # soma x 64
	sll $t2, $t1, 5         # soma x 32
	sll $t3, $t1, 2         # soma x 4
	addu $s2, $s2, $t2
	addu $t1, $s2, $t3      # t1 = Soma * 100
	
	div $t1, $s1            # (soma * 100) / cont_elementos
	mflo $s2                # s2 = media x 100

	addu $t0, $s1, $zero    
	addu $s3, $zero, $zero  

	d_sum_loop:
		beq $t0, $zero, d_sum_end
		addiu $t0, $t0, -1  
		
		sll $t2, $t0, 2
		addu $t2, $s0, $t2
		lw $t3, 0($t2)         
		
		sll $t4, $t3, 6
		sll $t5, $t3, 5
		sll $t6, $t3, 2
		addu $t4, $t4, $t5
		addu $t3, $t4, $t6     
		
		# x - media
		subu $t3, $t3, $s2     
		
		# x ao quadrado
		mult $t3, $t3
		mflo $t4               
		
		# somatoria
		addu $s3, $s3, $t4     
		j d_sum_loop
	d_sum_end:
		
	div $s3, $s1     
	mflo $t1            
	
	addu $a0, $t1, $zero   
	jal sqrt_integer
	addu $t1, $v0, $zero  

	# impressao
	
	addiu $t2, $zero, 100
	div $t1, $t2
	mfhi $t3
	mflo $t4
	
	# resto for 0, eh um numero redondo
	beq $t3, $zero, eh_inteiro_desvio
		
	eh_float_desvio:
		addiu $t1, $t1, 5
		addiu $t2, $zero, 10
		div $t1, $t2
		mflo $t1
		
		addiu $t2, $zero, 100
		slt $at, $t1, $t2
		beq $at, $zero, desvio_overflow
		
		addiu $t2, $zero, 10
		div $t1, $t2
		mflo $t3    # t3 = Dezena
		mfhi $t4    # $t4 = Unidade 
		
		# display dezena 
		sll $t0, $t3, 2
		addu $t1, $s4, $t0     
		lw $t2, 0($t1)
		ori $t2, $t2, 128
		sb $t2, 0($s6)
		
		# display unidade 
		sll $t0, $t4, 2
		addu $t1, $s4, $t0     
		lw $t2, 0($t1)
		sb $t2, 0($s5)
		
		j return_desvio_padrao

	eh_inteiro_desvio:
		addiu $t2, $zero, 100
		slt $at, $t4, $t2
		beq $at, $zero, desvio_overflow

		addiu $t2, $zero, 10
		div $t4, $t2
		mflo $t3    # t3 = Dezena 
		mfhi $t4    # t4 = Unidade 
		
		beq $t3, $zero, jump_left_display_desvio

		# Imprime dezena 
		sll $t0, $t3, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s6)

		j print_right_display_desvio

	jump_left_display_desvio:
		sb $zero, 0($s6)
		
	print_right_display_desvio:
		# Imprime unidade
		sll $t0, $t4, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s5)
		
		j return_desvio_padrao
		
	desvio_overflow:
		addiu $t0, $zero, 10    # pega o codigo E
		
		sll $t0, $t0, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s6)
		sb $t2, 0($s5)

	return_desvio_padrao:
		# limpa $v0 para nao retornar lixo
		addu $v0, $zero, $zero
		
		lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		lw $s2, 4($sp)
		lw $s3, 0($sp)
		addiu $sp, $sp, 20
		jr $ra