# Leia n
# Aloque array V - com n inteiros
# Escreva V (com espaços entre os elementos)

# Mapeamento
#	V -> s0
#	n -> s1
#	i -> s2

addi $v0, $zero, 5 # syscall code 5: Ler inteiro
syscall # Leia n
add $s1, $zero, $v0 # Mapear o n lido em s1

addi $t0, $zero, 4 # 4 bytes por int
mul $t0, $s1, $t0 # n ints * 4 bytes

add $fp, $zero, $sp # Salvar o inicio da pilha

sub $sp, $sp, $t0 # Subtrair do sp a qnt de bytes necessaria
addi $s0, $sp, 4 # Salvar em s0 o inicio do array

addi $t0, $zero, 4 # 4 bytes por int
add $s2, $zero, $zero # inicializar i = 0
FOR_LEITURA:
	slt $t1, $s2, $s1 # Testar i < n
	beq $t1, $zero, FIM_FOR_LEITURA
	
	addi $v0, $zero, 5
	syscall
	
	mul $t1, $s2, $t0 # i * 4 bytes
	add $t1, $s0, $t1 # V[i] = base + deslocamento
	sw $v0, 0($t1) # Armazenar o valor lido
	
	addi $s2, $s2, 1 # i++
	j FOR_LEITURA
FIM_FOR_LEITURA:

addi $t0, $zero, 4 # 4 bytes por int
add $s2, $zero, $zero # inicializar i = 0
FOR_IMPRIME:
	slt $t1, $s2, $s1 # Testar i < n
	beq $t1, $zero, FIM_FOR_IMPRIME
	
	mul $t1, $s2, $t0 # i * 4 bytes
	add $t1, $s0, $t1 # V[i] = base + deslocamento
	
	lw $a0, 0($t1)
	addi $v0, $zero, 1 # syscall code 1: Imprimir inteiro
	syscall	

	addi $s2, $s2, 1
	j FOR_IMPRIME
FIM_FOR_IMPRIME:

add $sp, $zero, $fp	# Restaurar o ponteiro da pilha (desalocar)

addi $v0, $zero, 10 # syscall code 10: Finalizar programa
syscall