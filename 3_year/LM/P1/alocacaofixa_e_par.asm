
addi $t4, $zero, 4 # t4 == 4,  para calcular bytes
add $t3, $zero, $zero # t3 == auxiliar para contas
addi $t5, $zero, 2

add $t1, $zero, $zero # t1 == ptr
add $t0, $zero, $zero # t0 == i

add $s2, $zero, $zero # s2 == soma
add $s3, $zero, $zero # s3 == cont_par
add $s4, $zero, $zero # s4 == cont_impar

addi $v0, $zero, 5
syscall
add $s0, $zero, $v0 # s0 == n

add $fp, $zero, $sp
sub $sp, $sp, $t4

mul $t3, $s0, $t4
sub $sp, $sp, $t3
add $s1, $zero, $sp

FOR_LEITURA:
beq $t0, $s0, FIM_LEITURA

	addi $v0, $zero, 5
	syscall
	
	add $t1, $zero, $s1
	mul $t3, $t0, $t4
	add $t1, $t1, $t3
	
	sw $v0, 0($t1)
	
	addi $t0, $t0, 1
	
j FOR_LEITURA
FIM_LEITURA:
add $t0, $zero, $zero

FOR_CALCULOS:
beq $t0, $s0, FIM_CALCULOS

	add $t1, $zero, $s1
	mul $t3, $t0, $t4
	add $t1, $t1, $t3
	
	lw $t3, 0($t1)
	add $s2, $s2, $t3
	
	div $t3, $t5
	mfhi $t3
	
	add $s4, $s4, $t3
	bne $t3, $zero, PULA_PAR
		addi $s3, $s3, 1
	PULA_PAR:
	
	addi $t0, $t0, 1
	
j FOR_CALCULOS
FIM_CALCULOS:

addi $v0, $zero, 1
add $a0, $zero, $s2
syscall

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall

addi $v0, $zero, 1
add $a0, $zero, $s4
syscall

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall

addi $v0, $zero, 1
add $a0, $zero, $s3
syscall

addi $v0, $zero, 11
ori $a0, $zero, ' '
syscall

add $sp, $zero, $fp

addi $v0, $zero, 10
syscall