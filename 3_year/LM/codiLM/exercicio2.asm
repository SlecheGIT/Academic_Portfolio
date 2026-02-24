# Leia a
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

# Leia b
addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

# Se a < b
slt $t0, $s0, $s1
beq $t0, $zero, END_IF_a_less_than_b

# Imprimir 'a'
addi $v0, $zero, 11
addi $a0, $zero, 98
syscall

END_IF_a_less_than_b:
	# Se a > b
	slt $t0, $s1, $s0
	beq $t0, $zero, END_IF_a_greater_than_b
	
	# Imprimir 'b'
	addi $v0, $zero, 11
	addi $a0, $zero, 99
	syscall
	
END_IF_a_greater_than_b:
	# Se a <= b
	slt $t0, $s1, $s0
	bne $t0, $zero, END_IF_a_less_than_or_equal_to_b
	
	# Imprimir 'c'
	addi $v0, $zero, 11
	addi $a0, $zero, 100
	syscall
	
END_IF_a_less_than_or_equal_to_b:
	#  Se a >= b
	slt $t0, $s0, $s1
	bne $t0, $zero, END_IF_a_greater_than_or_equal_to_b
	
	# Imprimir 'd'
	addi $v0, $zero, 11
	addi $a0, $zero, 101
	syscall

END_IF_a_greater_than_or_equal_to_b:
	# Se a < 100
	slti $t0, $s0, 100
	beq $t0, $zero, END_IF_a_less_than_100
		
	# Imprimir 'e'
	addi $v0, $zero, 11
	addi $a0, $zero, 102
	syscall

END_IF_a_less_than_100:
	# Se a > 100
	# LEMBRAR!!! (a > 100) --> (a - 100 > 0) --> (0 < a - 100)
	addi $t0, $s0, -100
	slt $t0, $zero, $t0
	beq $t0, $zero, END_IF_a_greater_than_100
	
	# Imprimir 'f'
	addi $v0, $zero, 11
	addi $a0, $zero, 103
	syscall

END_IF_a_greater_than_100:
	addi $v0, $zero, 10
	syscall
