# Este programa testa o Teclado Hexadecimal (Matriz) do Digital Lab Sim.
# Ele escaneia as 4 linhas do teclado, uma por uma, em um loop infinito.
# Quando uma tecla é encontrada, ele imprime o CÓDIGO HEXADECIMAL
# (ex: 0x41 para a tecla '2') no console (Run I/O).
#
# REQUISITOS:
# 1. Digital Lab Sim (Tools -> Digital Lab Sim) deve estar ABERTO.
# 2. O Digital Lab Sim deve estar CONECTADO (clique em "Connect to MIPS").
# 3. Pseudo-instruções DESABILITADAS (Settings -> Permit extended...)

.text
.globl main

main:
    # $k0 = 0xffff0012 (endereco que ativa a linha do teclado hexadecimal)
    lui $k0, 0xFFFF
    ori $k0, $k0, 0x0012

    # $k1 = 0xffff0014 (endereco dos dados do teclado hexdecimal)
    lui $k1, 0xFFFF
    ori $k1, $k1, 0x0014

main_loop: # loop de eventos
    addiu $t0, $zero, 1 # $t0 = linha que sera verificada, comeca com 1 (1,2,4,8)

# loop de escaneamento (testa uma linha por vez)
scan_loop:
    
    sb $t0, 0($k0) # escreve $t0 em 0xffff0012
    lw $t1, 0($k1) # le 0xffff0014
    bne $t1, $zero, key_found  #  se tiver algo diferente de 0 a tecla foi apertada naquela linha, convertemos a matriz de retorno em um numero 
    
    # nenhuma tecla encontrada, prepara para a próxima linha
    # atualiza a linha: 1 -> 2 -> 4 -> 8
    sll $t0, $t0, 1         # $t0 = $t0 * 2
    
    # se $at = 0 entao (máscara = 16) , comeca novamente a escanear a primeira linha
    # se $at = 1 entao (máscara < 16) e volta ao loop para escanear proxima linha
    addiu $t2, $zero, 16
    slt $at, $t0, $t2  # $at = 1 se (máscara < 16)
    bne $at, $zero, scan_loop
    
    j main_loop

# tecla Encontrada
key_found:
    # converte a matriz para um decimal
    add $a0, $t1, $zero
    jal DEF_CONVERT_KEY
  
    addu $a0, $v0, $zero    # Move o código para $a0
    addiu $v0, $zero, 1  # $v0 = 34 (syscall print_hex)
    syscall
    
    # 2. Imprime um caractere de nova linha
    addiu $a0, $zero, 0x0A  # $a0 = '\n'
    addiu $v0, $zero, 11  # $v0 = 11 (syscall print_char)
    syscall

# --- Espera a Tecla Ser Solta ---
# (Se não fizermos isso, ele imprimirá "0x41" mil vezes por segundo)
wait_for_release:
    # 3. Lê o *mesmo* endereço de dados novamente
    lw $t1, 0($k1)
    
    # 4. Fica preso neste loop ENQUANTO a tecla estiver pressionada
    bne $t1, $zero, wait_for_release
    
    # 5. A tecla foi solta! (leitura deu 0).
    #    Volta ao loop principal para recomeçar o scan.
    j main_loop
    
    
DEF_CONVERT_KEY:
	add $t0, $a0, $zero
	
    # --- Coluna 1 (0-3) ---
    addiu $t1, $zero, 0x11
    beq $t0, $t1, key_0
    
    addiu $t1, $zero, 0x21
    beq $t0, $t1, key_1
    
    addiu $t1, $zero, 0x41
    beq $t0, $t1, key_2
    
    addiu $t1, $zero, 0x81
    beq $t0, $t1, key_3
    
    # coluna 2 (4-7)
    addiu $t1, $zero, 0x12
    beq $t0, $t1, key_4
    
    addiu $t1, $zero, 0x22
    beq $t0, $t1, key_5
    
    addiu $t1, $zero, 0x42
    beq $t0, $t1, key_6
    
    addiu $t1, $zero, 0x82
    beq $t0, $t1, key_7
    
    # coluna 3 (8, 9, a, b)
    addiu $t1, $zero, 0x14
    beq $t0, $t1, key_8
    
    addiu $t1, $zero, 0x24
    beq $t0, $t1, key_9
    
    addiu $t1, $zero, 0x44
    beq $t0, $t1, key_A
    
    addiu $t1, $zero, 0x84
    beq $t0, $t1, key_B
    
    # coluna 4 (c, d, e, f)
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