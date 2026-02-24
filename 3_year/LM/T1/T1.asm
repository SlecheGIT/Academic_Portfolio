.data
# Display de 7 segmentos
# Right: 0xFFFF0010
# Left: 0xFFFF0011

# Tabela de consulta == 0x10010000
display_map:
    .word 63    # indice 0 (digito '0') 0x10010000 (0111111)
    .word 6     # indice 1 (digito '1') 0x10010004 (0000110)
    .word 91    # indice 2 (digito '2') 0x10010008 (1011011)
    .word 79    # indice 3 (digito '3') 0x1001000C (1001111)
    .word 102   # indice 4 (digito '4') 0x10010010 (1100110)
    .word 109   # indice 5 (digito '5') 0x10010014 (1101101)
    .word 125   # indice 6 (digito '6') 0x10010018 (1111101)
    .word 7     # indice 7 (digito '7') 0x1001001C (0000111)
    .word 127   # indice 8 (digito '8') 0x10010020 (1111111)
    .word 111   # indice 9 (digito '9') 0x10010024 (1101111)
    .word 121	# indice 10 (digito 'E') 0x10010028 (1111001)
.text
.globl main
#s0 pilha de ate 10 elementos
#s1 quantidade de elementos
#s2 = digito de unidade
#s3 = digito de dezena
#s4 == enderedeco da tabela 
#s5 = endereco do display direito
#s6 = endereco do display esquerdo
main:
    # k0 = 0xffff0012 (endereco que ativa a linha do teclado hexadecimal)
    lui $k0, 0xFFFF
    ori $k0, $k0, 0x0012

    # k1 = 0xffff0014 (endereco dos dados do teclado hexdecimal)
    lui $k1, 0xFFFF
    ori $k1, $k1, 0x0014
    
    # reserva 10 espacos na memoria
    addi $a0, $zero, 40
    addi $v0, $zero, 9
    syscall
    addu $s0, $v0, $zero
    
    addi $s1, $zero, 0 #quantidades de elementos na pilha
	
	addi $s2, $zero, -1 #numero correspondente a unidade (display direito)
	addi $s3, $zero, -1 #numero correspondente a dezena (display esquerdo)
	
	lui $s4, 0x1001 
    ori $s4, $s4, 0x0000 # endereco da tabela de traducao
    
    lui $s5, 0xFFFF
    ori $s5, $s5, 0x0010 # endereco do display direito
    
    lui $s6, 0xFFFF
    ori $s6, $s6, 0x0011  # endereco do display esquerdo
    
    sb $zero, 0($s5) # zera o display no inicio
	sb $zero, 0($s6)
	
main_loop: # loop de eventos
    addiu $t0, $zero, 1 # t0 = linha que sera verificada, comeca com 1 (1,2,4,8)

# loop de escaneamento , ele testa uma linha por vez para que mostre a tecla pressionada naquela linha
scan_loop:
    
    sb $t0, 0($k0) # escreve t0 em 0xffff0012
    lw $t1, 0($k1) # le 0xffff0014
    bne $t1, $zero, key_found  #  se tiver algo diferente de 0 a tecla foi apertada naquela linha, convertemos a matriz de retorno em um numero 
    
    # nenhuma tecla encontrada, prepara para a proxima linha
    # atualiza a linha: 1 -> 2 -> 4 -> 8
    sll $t0, $t0, 1         # t0 = t0 * 2
    
    # se at = 0 entao (mascara = 16) , comeca novamente a escanear a primeira linha
    # se at = 1 entao (mascara < 16) e volta ao loop para escanear proxima linha
    addiu $t2, $zero, 16
    slt $at, $t0, $t2  # at = 1 se (mascara < 16)
    bne $at, $zero, scan_loop
    
    j main_loop

# tecla encontrada
key_found:
    # converte a matriz para um decimal
    add $a0, $t1, $zero
    jal DEF_CONVERT_KEY
  	add $t1, $zero, $v0
  	
  	addi $t0, $zero, 10
  	beq $t0, $t1, acumulador
  	
  	slt $t0, $t1, $t0 # se o numero for menor que 10 entao nao eh uma funcao
  	bne $t0, $zero, leitura
  	
  	addu $a0, $s0, $zero
  	addu $a1, $s1, $zero
  	
  	addi $t0, $zero, 11
  	beq $t0, $t1, media_aritmetica
  	
	#addi $t0, $zero, 12
  	#beq $t0, $t1, verificar_pilha
  	
  	addi $t0, $zero, 12
  	beq $t0, $t1, desvio_padrao
  	
  	addi $t0, $zero, 13
  	beq $t0, $t1, sequencia_VanEck
  	
  	addi $t0, $zero, 14
  	beq $t0, $t1, sequencia_fibbonacci
  	
  	addi $t0, $zero, 15
  	beq $t0, $t1, clear
  	
  	j wait_key_press # para garantir em casos de erro
  	
  	
  	#verificar_pilha:
  	#	jal VER_PILHA
  	#	j wait_key_press
  	
  	clear: #tecla f
 		clear_stack:
 			beq $s1, $zero, clear_stack_end
 			
 			addi $t1, $s1, -1
 			sll $t1, $t1, 2
 			add $t1, $s0, $t1
 			
 			sw $zero, 0($t1)
 			
 			addi $s1, $s1, -1 
 			j clear_stack
 		clear_stack_end:
  		addi $s2, $zero, -1
  		addi $s3, $zero, -1
  		
    	sb $zero, 0($s5)
    	sb $zero, 0($s6)
    	
  		j wait_key_press
  	
  	sequencia_fibbonacci: #tecla e
  		addi $t0, $zero, -1
  		beq $s2, $t0, wait_key_press # se nenhum digito foi escrito ele pula a execucao
  		
  		add $a0, $s2, $zero
  		add $a1, $s3, $zero
  		jal DEF_JOIN_NUMBERS
  		
  		add $a0, $v0, $zero
  		jal DEF_FIBBONACCI

  		add $t1, $v0, $zero
  		addi $t2, $zero, 100
  		slt $t0, $t1, $t2
  		bne $t0, $zero, not_overflow_fib
  			
  			addi $t2, $zero, 10
  			sll $t2, $t2, 2
  			add $t2, $s4, $t2
  			lw $t0, 0($t2)
  			sb $t0, 0($s5)
  			sb $t0, 0($s6)
  			
  			j wait_key_press
  		not_overflow_fib:
  		
    	addiu $t7, $zero, 10
    	div $t1, $t7
    
    	mflo $s3        
    	mfhi $s2    
    	
    	beq $s3, $zero, not_dozen_fib
  			sll $t2, $s3, 2  
    		addu $t2, $s4, $t2
    		lw $t3, 0($t2)
    		sb $t3, 0($s6)
    		j yes_dozen_fib
  		not_dozen_fib:
  			sb $zero, 0($s6)
  		yes_dozen_fib:
  		
  		sll $t2, $s2, 2  
    	addu $t2, $s4, $t2
    	lw $t3, 0($t2)
    	sb $t3, 0($s5)
  		j wait_key_press
  	
  	sequencia_VanEck: #tecla d
  		addi $t0, $zero, -1
  		beq $s2, $t0, wait_key_press
  		
  		add $a0, $s2, $zero
  		add $a1, $s3, $zero
  		jal DEF_JOIN_NUMBERS
  		
  		beq $v0, $zero , wait_key_press
  		addi $a0, $v0, -1 
  		
  		jal DEF_VanEck
  		
		add $t1, $v0, $zero
		
  		addi $t2, $zero, 100
  		slt $t0, $t1, $t2
  		bne $t0, $zero, not_overflow
  			
  			addi $t2, $zero, 10
  			sll $t2, $t2, 2
  			add $t2, $s4, $t2
  			lw $t0, 0($t2)
  			sb $t0, 0($s5)
  			sb $t0, 0($s6)
  			
  			j wait_key_press
  		not_overflow:
  		
    		addiu $t7, $zero, 10
    		div $t1, $t7
    
    		mflo $s3        
    		mfhi $s2    
    	
    		beq $s3, $zero, not_dozen
  			sll $t2, $s3, 2  
    			addu $t2, $s4, $t2
    			lw $t3, 0($t2)
    			sb $t3, 0($s6)
    			j yes_dozen
  		not_dozen:
  			sb $zero, 0($s6)
  		yes_dozen:
  		
  		sll $t2, $s2, 2  
    	addu $t2, $s4, $t2
    	lw $t3, 0($t2)
    	sb $t3, 0($s5)
  		
  		j wait_key_press
  		
  	desvio_padrao: #tecla c
  		addi $t2, $s1, -1
  		beq $s1, $zero, except
  		beq $t2, $zero, except
  		
  		addu $a0, $s0, $zero
  		addu $a1, $s1, $zero
 		jal DEF_DESVIO_PADRAO
 		
 		j wait_key_press
 		except:
 			add $s2, $zero, $zero
 			addi $s3, $zero, -1
 			lw $t2, 0($s4)
 			sb $t2, 0($s5)
  	
  		j wait_key_press
  		
  	
  	media_aritmetica: #tecla b
  		add $t2, $zero, $zero
  		beq $s1, $zero, wait_key_press
  		
  		addu $a0, $s0, $zero
  		addu $a1, $s1, $zero
 		jal DEF_MEDIA_ARITMETICA
  		
  		j wait_key_press
  		
  	acumulador: #tecla a
  		addi $t0, $zero, 10
  		slt $t0, $s1, $t0 # cont_elementos < 10
  		beq $t0, $zero, wait_key_press # se a pilha estiver cheia pule o salvamento
  		
  		addi $t0, $zero, -1
  		beq $s2, $t0, wait_key_press # se nenhum digito foi escrito ele pula o salvamento
  		
  		add $a0, $s2, $zero
  		add $a1, $s3, $zero
  		jal DEF_JOIN_NUMBERS
  		add $t0, $v0, $zero
  		
    	sll $t1, $s1, 2
    	addu $t1, $s0, $t1
    	sw $t0, 0($t1)
    	
    	addi $s2, $zero, -1
    	addi $s3, $zero, -1
    	
    	#reseta display
    	sb $zero, 0($s5)
    	sb $zero, 0($s6)
    	
    	addi $s1, $s1, 1
    	j wait_key_press
    	
  	leitura:
  	addi $t0, $zero, -1
  	beq $s2, $t0, if_unit # se nao tiver unidade sera colocado la
  	beq $s3, $t0, if_dozen # se nao tiver dezena sera colocado la 
  	
  	#se tiver ambos reseta o que foi escrito ate ali, comecando novamente a unidade
  	addi $s2, $zero, -1
  	addi $s3, $zero, -1
  	
   	if_unit:
   		add $s2, $zero, $t1
   		
    	sb $zero, 0($s6)
    	
   		sll $t2, $s2, 2  
    	addu $t2, $s4, $t2
    	lw $t3, 0($t2)
    	sb $t3, 0($s5)
    	
   		j wait_key_press
    if_dozen:
    	beq $s2, $zero, if_unit #se o primeiro for 0 ele nao cria o numero 02 e sim apenas 2 para nao bugar a vizualizacao do display
    	
    	add $s3, $zero, $s2
    	add $s2, $zero, $t1
    	
    	sll $t2, $s3, 2  
    	addu $t2, $s4, $t2
    	lw $t3, 0($t2)
    	sb $t3, 0($s6)
    	
    	sll $t2, $s2, 2  
    	addu $t2, $s4, $t2
    	lw $t3, 0($t2)
    	sb $t3, 0($s5)

wait_key_press: # espera a tecla ser solta, senao contara constantemente a mesma tecla
    lw $t1, 0($k1)
    bne $t1, $zero, wait_key_press
    j main_loop
 
return_main: #nao existe pois em nenhum guia o botao close eh operavel
	addi $v0, $zero, 10
	syscall
   
#fim da main
    
DEF_CONVERT_KEY:
	add $t0, $a0, $zero
	
    # coluna 1 (0 a 3)
    addiu $t1, $zero, 0x11
    beq $t0, $t1, key_0
    
    addiu $t1, $zero, 0x21
    beq $t0, $t1, key_1
    
    addiu $t1, $zero, 0x41
    beq $t0, $t1, key_2
    
    addiu $t1, $zero, 0x81
    beq $t0, $t1, key_3
    
    # coluna 2 (4 a 7)
    addiu $t1, $zero, 0x12
    beq $t0, $t1, key_4
    
    addiu $t1, $zero, 0x22
    beq $t0, $t1, key_5
    
    addiu $t1, $zero, 0x42
    beq $t0, $t1, key_6
    
    addiu $t1, $zero, 0x82
    beq $t0, $t1, key_7
    
    # coluna 3 (8 a b)
    addiu $t1, $zero, 0x14
    beq $t0, $t1, key_8
    
    addiu $t1, $zero, 0x24
    beq $t0, $t1, key_9
    
    addiu $t1, $zero, 0x44
    beq $t0, $t1, key_A
    
    addiu $t1, $zero, 0x84
    beq $t0, $t1, key_B
    
    # coluna 4 (c a f)
    addiu $t1, $zero, 0x18
    beq $t0, $t1, key_C
    
    addiu $t1, $zero, 0x28
    beq $t0, $t1, key_D
    
    addiu $t1, $zero, 0x48
    beq $t0, $t1, key_E
    
    addiu $t1, $zero, 0x88
    beq $t0, $t1, key_F
    
    # erro 
	addiu $v0, $zero, -1      # carrega -1 se a tecla nao for correspondente
    j return_convert_key      

	key_0: 
		addiu $v0, $zero, 0
		j return_convert_key
	key_1: 
		addiu $v0, $zero, 1
		j return_convert_key
	key_2: 
		addiu $v0, $zero, 2
		j return_convert_key
	key_3: 
		addiu $v0, $zero, 3
		j return_convert_key
	key_4: 
		addiu $v0, $zero, 4
		j return_convert_key
	key_5: 
		addiu $v0, $zero, 5
		j return_convert_key
	key_6: 
		addiu $v0, $zero, 6
		j return_convert_key
	key_7: 
		addiu $v0, $zero, 7
		j return_convert_key
	key_8: 
		addiu $v0, $zero, 8
		j return_convert_key
	key_9: 
		addiu $v0, $zero, 9
		j return_convert_key
	key_A: 
		addiu $v0, $zero, 10
		j return_convert_key 
	key_B: 
		addiu $v0, $zero, 11
		j return_convert_key
	key_C: 
		addiu $v0, $zero, 12
		j return_convert_key 
	key_D: 
		addiu $v0, $zero, 13
		j return_convert_key 
	key_E: 
		addiu $v0, $zero, 14
		j return_convert_key 
	key_F: 
		addiu $v0, $zero, 15
		j return_convert_key 

	return_convert_key:
	jr $ra
	
DEF_JOIN_NUMBERS:
	add $t1, $zero, $zero
	addi $t0, $zero, -1
  	beq $a1, $t0, jump_dozen
  		# t1 = s3 * 2
    	sll $t1, $a1, 1  

   		# t0 = s3 * 8
    	sll $t2, $a1, 3 
    
    	# t0 = (s3 * 8) + (s3 * 2)
    	addu $t1, $t2, $t1  
    jump_dozen:
    	
    # t0 = (s3 * 10) + s2
    addu $t0, $t1, $a0
    return_join_numbers:
    
	add $v0, $t0, $zero
	jr $ra
	
DEF_FIBBONACCI:
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $s1, 4($sp)
	sw $s0, 0($sp)
	
	add $s0, $a0, $zero
	beq $s0, $zero, case_base0
	
	addi $t0, $zero, 1
	beq $s0, $t0, case_base1
	
	addi $a0, $s0, -1
	jal DEF_FIBBONACCI
	add $s1, $v0, $zero
	
	addi $a0, $s0, -2
	jal DEF_FIBBONACCI
	add $v0, $v0, $s1
	
	j return_fibbonacci
	
	case_base0:
		add $v0, $zero, $zero
		j return_fibbonacci
	case_base1:
		addi $v0, $zero, 1
	return_fibbonacci:
	lw $ra, 8($sp)
	lw $s1, 4($sp)
	lw $s0, 0($sp)
	addi $sp, $sp, 12
	jr $ra
	
	
VER_PILHA:
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	add $t0, $zero, $zero
	addiu $a0, $zero, 10  # a0 = '\n'
    addiu $v0, $zero, 11 
    syscall
	ver_while:
		slt $t1, $t0, $s1
		beq $t1, $zero, fim_while
		
		sll $t2, $t0, 2
		addu $t2, $s0, $t2
		lw $a0, 0($t2)
		
		addi $v0, $zero, 1
		syscall
		
		ori $a0, $zero, ' '
    	addiu $v0, $zero, 11  
    	syscall
		
		addi $t0, $t0, 1
		j ver_while
	fim_while:
	sw $ra, 0($sp)
	addiu $sp, $sp, 4
	
	jr $ra

#duas funcoes para van_eck 
#importante se informar que a sequencia de van_eck recursiva eh a maneira incorreta e ineficiente de realizar esse algoritmo
#a maneira de corrigir eh um algoritmo iterativo disfarçado de recursão
DEF_VanEck: 
    addiu $sp, $sp, -16
    sw $ra, 12($sp)
    sw $s0, 8($sp)
    sw $s1, 4($sp)
    sw $s2, 0($sp)
    
    addiu $s0, $a0, 0

    bne $s0, $zero, sequence_empt
    addiu $v0, $zero, 0
    j return_VanEck
    sequence_empt:

        addiu $t0, $s0, 1
        sll $t0, $t0, 2
        
        addiu $a0, $t0, 0
        addiu $v0, $zero, 9
        syscall
        addiu $s1, $v0, 0
        
        addiu $a0, $t0, 0
        addiu $v0, $zero, 9
        syscall
        addiu $s2, $v0, 0

        addiu $t0, $s0, 1
        addiu $t1, $s2, 0
        addiu $t2, $zero, -1
    init_loop:
    beq $t0, $zero, init_loop_end
    sw $t2, 0($t1)
    addiu $t1, $t1, 4
    addiu $t0, $t0, -1
    j init_loop
    init_loop_end:

        sw $zero, 0($s1)

        # a0 = n recursivo
        # a1 = n original
        # a2 = sequencia
        # a3 = ultima vcez visto
        
        addiu $a0, $zero, 1
        addiu $a1, $s0, 0
        addiu $a2, $s1, 0
        addiu $a3, $s2, 0
        
        jal DEF_VanEck_RECURSIVE

        sll $t0, $s0, 2
        add $t0, $t0, $s1
        lw $v0, 0($t0)
        
    return_VanEck:
        lw $s2, 0($sp)
        lw $s1, 4($sp)
        lw $s0, 8($sp)
        lw $ra, 12($sp)
        addiu $sp, $sp, 16
        
        jr $ra

DEF_VanEck_RECURSIVE:
    addiu $sp, $sp, -20
    sw $ra, 16($sp)
    sw $s0, 12($sp)
    sw $s1, 8($sp)
    sw $s2, 4($sp)
    sw $s3, 0($sp)

    addiu $s0, $a0, 0
    addiu $s1, $a1, 0
    addiu $s2, $a2, 0
    addiu $s3, $a3, 0
    
    # caso nase
    slt $t0, $s1, $s0
    bne $t0, $zero, return_VanEck_recursive
    
    addiu $t0, $s0, -1
    sll $t0, $t0, 2
    add $t0, $t0, $s2
    lw $t1, 0($t0)
    
    sll $t2, $t1, 2
    add $t2, $t2, $s3
    lw $t3, 0($t2)
    
    addiu $t4, $zero, 0
    addiu $t5, $zero, -1
    beq $t3, $t5, not_calc
    
    addiu $t5, $s0, -1
    sub $t4, $t5, $t3
    
    not_calc:
        sll $t0, $s0, 2
        add $t0, $t0, $s2
        sw $t4, 0($t0)
        
        addiu $t5, $s0, -1
        sw $t5, 0($t2)
        
        addiu $a0, $s0, 1
        addiu $a1, $s1, 0
        addiu $a2, $s2, 0
        addiu $a3, $s3, 0
        
        jal DEF_VanEck_RECURSIVE
        
    return_VanEck_recursive:
        lw $s3, 0($sp)
        lw $s2, 4($sp)
        lw $s1, 8($sp)
        lw $s0, 12($sp)
        lw $ra, 16($sp)
        addiu $sp, $sp, 20
        
        jr $ra
        
        
DEF_MEDIA_ARITMETICA:
    addiu $sp, $sp, -16
    sw $ra, 12($sp)
    sw $s0, 8($sp)
    sw $s1, 4($sp)
    sw $s2, 0($sp)
    
    addu $s0, $a0, $zero
    addu $s1, $a1, $zero
    
    addu $t0, $s1, $zero
    addu $t1, $zero, $zero
    
    beq $s1, $zero, media_overflow

	sum_while:
    	beq $t0, $zero, sum_while_end
   		addiu $t0, $t0, -1
    
   		sll $t2, $t0, 2
    	addu $t2, $s0, $t2
   		lw $t3, 0($t2)
    				
    	addu $t1, $t1, $t3 #somatoria
    	j sum_while
	sum_while_end:

    sll $s2, $t1, 6
    sll $t2, $t1, 5
    sll $t3, $t1, 2
    addu $s2, $s2, $t2
    addu $t1, $s2, $t3      # t1 = Soma * 100
    
    div $t1, $s1  # (soma * 100) / quant_n
    mflo $t1                

    addiu $t2, $zero, 100
    div $t1, $t2           
    mfhi $t3                
    mflo $t4                
    
    # resto for 0, eh um numero redondo
    beq $t3, $zero, eh_inteiro
    
	eh_float:
		addiu $t1, $t1, 5      
		addiu $t2, $zero, 10
		div $t1, $t2
		mflo $t1               
		
		addiu $t2, $zero, 100
		slt $at, $t1, $t2
		beq $at, $zero, media_overflow
		
		addiu $t2, $zero, 10
		div $t1, $t2
		mflo $t3    # t3 = Dezena
		mfhi $t4    # t4 = Unidade 
		
		# display dezena 
		sll $t0, $t3, 2
		add $t1, $s4, $t0
		lw $t2, 0($t1)
		ori $t2, $t2, 128
		sb $t2, 0($s6)
		
		# display unidade 
		sll $t0, $t4, 2
		add $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s5)
		
		j return_media_aritmetica

	eh_inteiro:
		addiu $t2, $zero, 100
		slt $at, $t4, $t2
		beq $at, $zero, media_overflow

		addiu $t2, $zero, 10
		div $t4, $t2
		mflo $t3  # t3 = dezena 
		mfhi $t4  # t4 = unidade 
		
		beq $t3, $zero, jump_left_display_media

			# imprime dezena 
			sll $t0, $t3, 2
			addu $t1, $s4, $t0
			lw $t2, 0($t1)
			sb $t2, 0($s6)
		
		jump_left_display_media:

		# imprime unidade
		sll $t0, $t4, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s5)
		
		j return_media_aritmetica
		
	media_overflow:
		addiu $t0, $zero, 10
		
		sll $t0, $t0, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s6)
		sb $t2, 0($s5)

	return_media_aritmetica:
		# limpa v0 para nao retornar lixo
		addu $v0, $zero, $zero
		
		lw $ra, 12($sp)
		lw $s0, 8($sp)
		lw $s1, 4($sp)
		lw $s2, 0($sp)
		addiu $sp, $sp, 16
		jr $ra

# calcula raiz pelo metodo de newton aproximacao sucessivas visto com calculo numerico
DEF_SQRT: 
    # se n=0, raiz =0 
    beq $a0, $zero, sqrt_return_zero
    
    addu $t0, $a0, $zero    # t0 = n
    addu $t1, $a0, $zero    # t1 = chute inicial (metodo de newton)
    
sqrt_loop:
    div $t0, $t1
    mflo $t2
    
    addu $t3, $t1, $t2
    
    srl $t1, $t3, 1         
    
    # checa estabilidade do chite inicial, 
    slt $t3, $t2, $t1  #esqueci do erro de oscilacao , em vez de esperar estabilizar , melhor ir ate for igual ou subir
    bne $t3, $zero, sqrt_loop 
    
    addu $v0, $t1, $zero
    jr $ra

sqrt_return_zero:
    addu $v0, $zero, $zero
    jr $ra
    
 # nao existe apenas desvio padrao, eh desvio padrao amostral ou populacional???
 # funcao foi feita com desvio padrao  populacional
DEF_DESVIO_PADRAO:
    addiu $sp, $sp, -20
    sw $ra, 16($sp)
    sw $s0, 12($sp)         # pilha
    sw $s1, 8($sp)          # cont_elementos
    sw $s2, 4($sp)         
    sw $s3, 0($sp)          
    
    addu $s0, $a0, $zero    # s0 = pilha
    addu $s1, $a1, $zero    # s1 = cont_elementos
    
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
	
	addi $t1, $s1, -1
	div $s3, $t1   
	mflo $t1            
	
	addu $a0, $t1, $zero   
	jal DEF_SQRT
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
		mfhi $t4    # t4 = Unidade 
		
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

		# imprime dezena 
		sll $t0, $t3, 2
		addu $t1, $s4, $t0
		lw $t2, 0($t1)
		sb $t2, 0($s6)

		j print_right_display_desvio

	jump_left_display_desvio:
		sb $zero, 0($s6)
		
	print_right_display_desvio:
		# imprime unidade
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
		# limpa v0 para nao retornar lixo
		addu $v0, $zero, $zero
		
		lw $ra, 16($sp)
		lw $s0, 12($sp)
		lw $s1, 8($sp)
		lw $s2, 4($sp)
		lw $s3, 0($sp)
		addiu $sp, $sp, 20
		jr $ra
