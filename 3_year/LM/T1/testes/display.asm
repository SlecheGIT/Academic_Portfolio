# Este programa demonstra como usar uma Tabela de Consulta (Lookup Table)
# sem usar pseudo-instru��es.
#
# ASSUME que o segmento .data come�a em 0x10010000 (padr�o do MARS)

.data
# Display de 7 segmentos
# Right: 0xFFFF0010
# Left: 0xFFFF0011
# Tabela de consulta == 0x10010000
display_map:
    .word 63     # �ndice 0 (d�gito '0') 0x10010000 (0111111)
    .word 6      # �ndice 1 (d�gito '1') 0x10010004 (0000110)
    .word 91     # �ndice 2 (d�gito '2') 0x10010008 (1011011)
    .word 79     # �ndice 3 (d�gito '3') 0x1001000C (1001111)
    .word 102    # �ndice 4 (d�gito '4') 0x10010010 (1100110)
    .word 109    # �ndice 5 (d�gito '5') 0x10010014 (1101101)
    .word 125    # �ndice 6 (d�gito '6') 0x10010018 (1111101)
    .word 7      # �ndice 7 (d�gito '7') 0x1001001C (0000111)
    .word 127    # �ndice 8 (d�gito '8') 0x10010020 (1111111)
    .word 111    # �ndice 9 (d�gito '9') 0x10010024 (1101111)

.text
.globl main

main:

    # N�s fazemos isso manualmente, pois n�o podemos usar %hi/%lo
    # $s0 = 0x10010000 (Endere�o inicial do .data e da display_map)
    lui $s0, 0x1001
    ori $s0, $s0, 0x0000
    # --- Passo 2: Definir o �ndice que queremos procurar ---
    # Vamos usar o seu exemplo: queremos o d�gito '2'
    addiu $t0, $zero, 8     # $t0 = 2 (nosso �ndice)
    
    # --- Passo 3: Calcular o offset na tabela ---
    # Cada item � uma .word (4 bytes).
    # Precisamos do endere�o do item [2], que �: Endere�oBase + (�ndice * 4)
    # offset = $t0 * 4
    sll $t1, $t0, 2         # $t1 = 2 << 2 = 8. Nosso offset � 8 bytes.
    
    # --- Passo 4: Calcular o endere�o final do item ---
    # end_final = Endere�oBase + offset
    # $t2 = $s0 + $t1
    addu $t2, $s0, $t1      # $t2 = 0x10010000 + 8 = 0x10010008
                            # Este � o endere�o de mem�ria onde o '91' est� armazenado.
                            
    # --- Passo 5: Carregar o valor daquele endere�o ---
    # $t3 = Memoria[ $t2 ]
    lw $t3, 0($t2)          # $t3 agora cont�m o valor 91 (ou 0x5B)
    
    # --- Passo 6: Prova - Salvar o resultado na mem�ria ---
    lui $t0, 0xFFFF
    ori $t0, $t0, 0x0011
    
    sb $t3 0($t0)
    # --- Fim do Programa ---
    addiu $v0, $zero, 10    # syscall 10 (exit)
    syscall
