.data
.text

.globl main
main:

# ----------------------------
# $s0 = endereço base do vetor V
# $s1 = n (número de inteiros)
# $t0 = endereço temporário de elemento
# $t1 = i (contador do loop externo)
# $t2 = j (contador do loop interno)
# $t3 = deslocamento / auxiliar
# $t4 = 4 (bytes por inteiro)
# $t5 = V[j]
# $t6 = V[j+1]
# $t7 = resultado de comparação
# ----------------------------

# $t4 = 4
addi $t4, $zero, 4

# --- Lê n ---
addi $v0, $zero, 5
syscall
add $s1, $zero, $v0        # $s1 = n

# --- Aloca espaço para n inteiros ---
addi $v0, $zero, 9         # syscall 9 = sbrk
mul $a0, $s1, $t4          # $a0 = n * 4
syscall
add $s0, $zero, $v0        # $s0 = endereço base do vetor

# --- Lê os n elementos ---
add $t1, $zero, $zero      # i = 0
FOR_LEITURA:
beq $t1, $s1, FIM_LEITURA

    # syscall para ler inteiro
    addi $v0, $zero, 5
    syscall

    # calcula endereço: base + i * 4
    mul $t3, $t1, $t4
    add $t0, $s0, $t3

    # armazena o valor lido no vetor
    sw $v0, 0($t0)

    addi $t1, $t1, 1
    j FOR_LEITURA
FIM_LEITURA:

# --- Bubble Sort ---
add $t1, $zero, $zero      # i = 0
FOR_EXTERNO:
beq $t1, $s1, FIM_EXTERNO

    add $t2, $zero, $zero  # j = 0
FOR_INTERNO:
    addi $t3, $t2, 1
    beq $t3, $s1, FIM_INTERNO   # if j+1 == n → fim

    # endereço de V[j]
    mul $t3, $t2, $t4
    add $t0, $s0, $t3

    # endereço de V[j+1]
    add $t3, $t0, $t4

    # carrega V[j] e V[j+1]
    lw $t5, 0($t0)
    lw $t6, 0($t3)

    # se V[j+1] < V[j] → troca
    slt $t7, $t6, $t5
    beq $t7, $zero, MANTEM

        sw $t6, 0($t0)
        sw $t5, 0($t3)

MANTEM:
    addi $t2, $t2, 1
    j FOR_INTERNO
FIM_INTERNO:

    addi $t1, $t1, 1
    j FOR_EXTERNO
FIM_EXTERNO:

# --- Fim do programa ---
addi $v0, $zero, 10
syscall
