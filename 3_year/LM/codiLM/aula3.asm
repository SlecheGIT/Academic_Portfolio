# "if-else"

# if (a > b) {
# 	Imprime a;
# } else {
#	imprime b;
# }
# exit(0);

# Leia a
addi $v0, $zero, 5
syscall 
add $s0, $zero, $v0 

# Leia b
addi $v0, $zero, 5
syscall 
add $s1, $zero, $v0

# se b < b, t0 recebe 0
slt $t0, $s1, $s0
beq $t0, $zero, ELSE # Se for igual a zero, vá para o else

# Imprime a
addi $v0, $zero, 1
add $a0, $zero, $s0
syscall

j FIM_ELSE # Terminou de executar o corpo do IF

ELSE:
	# Imprime b
	addi $v0, $zero, 1
	add $a0, $zero, $s1
	syscall

FIM_ELSE:
	addi $a0, $zero, 10
	syscall

