

addi $t4, $zero, 4
addi $t5, $zero, -1

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

add $fp, $zero, $sp

addi $v0, $zero, 9
mul $a0, $s0, $t4
syscall
add $s1, $zero, $v0

add $t0, $zero, $zero
FOR_INVERTER:
beq $t0, $s0, FIM_INVERTER

	add $t1, $zero, $s1
	addi $t2, $t0, 1
	sub $t2, $s0, $t2
	mul $t2, $t2, $t4
	add $t1, $t1, $t2
	
	lw $t2, 0($sp)
	sw $t2, 0($t1)
	addi $sp, $sp, 4
	
	addi $t0, $t0, 1

j FOR_INVERTER
FIM_INVERTER:

add $sp, $zero, $fp

add $t0, $zero, $zero
FOR_IMPRESSAO_PILHA:
beq $t0, $s0, FIM_IMPRESSAO_PILHA

	lw $a0, 0($sp)
	addi $sp, $sp, 4
	
	addi $v0, $zero, 1
	syscall
	
	addi $v0, $zero, 11
	ori $a0, $zero, ' '
	syscall
	
	addi $t0, $t0, 1

j FOR_IMPRESSAO_PILHA
FIM_IMPRESSAO_PILHA:

addi $v0, $zero, 11
addi $a0, $zero, 10
syscall
#{
add $t0, $zero, $zero
FOR_IMPRESSAO_VETOR:
beq $t0, $s0, FIM_IMPRESSAO_VETOR
	
	add $t1, $zero, $s1
	mul $t2, $t0, $t4
	add $t1, $t1, $t2
	
	addi $v0, $zero, 1
	lw $a0, 0($t1)
	syscall
	
	addi $v0, $zero, 11
	ori $a0, $zero, ' '
	syscall 
	
	addi $t0, $t0, 1
	
j FOR_IMPRESSAO_VETOR
FIM_IMPRESSAO_VETOR:
#}
addi $v0, $zero, 10
syscall
