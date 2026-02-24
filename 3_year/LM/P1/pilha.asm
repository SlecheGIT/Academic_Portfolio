

#s0 = n inteiros
add $s1, $zero, $zero
add $s2, $zero, $zero
add $s3, $zero, $zero
add $t1, $zero, $zero
addi $t4, $zero, -4

addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

add $t0, $zero, $zero
FOR_LEITURA:
beq $t0, $s0, FIM_LEITURA

	addi $v0, $zero, 5
	syscall
	
	addi $sp, $sp, -4
	sw $v0, 0($sp)
	
	addi $t0, $t0, 1
	
j FOR_LEITURA
FIM_LEITURA:

add $t0, $zero, $zero
FOR_SOMA:
beq $t0, $s0, FIM_SOMA

	lw $t1, 0($sp)
	addi $sp, $sp, 4
	
	add $s1, $s1, $t1
	
	andi $t1, $t1, 1
	add $s2, $s2, $t1
	
	bne $t1, $zero, FIM_IF
	
		addi, $s3, $s3, 1
	
	FIM_IF:
	
	addi $t0, $t0, 1
	
j FOR_SOMA
FIM_SOMA:

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall

addi $v0, $zero, 1
add $a0, $zero, $s1
syscall

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall

addi $v0, $zero, 1
add $a0, $zero, $s2
syscall

addi $v0, $zero, 11
ori $a0, $zero, 'a'
syscall

addi $v0, $zero, 1
add $a0, $zero, $s3
syscall

addi $v0, $zero, 10
syscall
