add $fp, $zero, $sp # Guardar o valor inicial de sp em fp antes de gerenciar memória com sp
# fp sempre estará informando quando começou a mexer com a pilha

# int S0[5];
add $s0, $zero, $sp
addi $sp, $sp, -20

# int S1[5];
add $s1, $zero, $sp
addi $sp, $sp, -20

# int i; // $s2
addi $s2, $zero, 0
addi $t0, $zero, 4 # Cria uma constante 4, para calculo de deslocamento
# for(i = 0; i < 5; i++)
FOR_1:
	slti $t1, $s2, 5
	beq $t1, $zero, FIM_FOR_1
	# leia $v0
	addi $v0, $zero, 5
	syscall
	# S0[i] = $v0
	mul $t1, $t0, $s2 # Calculo de deslocamento
	add $t1, $t1, $s0 # Soma end. base com deslocamento
	sw $v0, 0($t1)
	addi $s2, $s2, 1
	j FOR_1
FIM_FOR_1:
s

# int *ptr;
# for (ptr = S0; ptr < S0 + * 4; ptr += 4)
# 	leia num
# 	*ptr <- num

add $sp, $zero, $fp

addi $v0, $zero, 10
syscall
