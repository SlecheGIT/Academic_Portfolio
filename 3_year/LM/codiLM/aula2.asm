# Desvios condicionais

# slt e slti
# slt R1, R2, R3 -> será 1 se R2 < R3; 0 caso contrário
# slti R1, R2, Imediato -> será 1 se R2 < Imediato; 0 caso contrário

# beq e bne
# beq R1, R2, Label -> se R1 = R2 então PC = Label
# bne R1, R2, Label -> se R1 != R2 então PC = Label

# obs: Label é um endereço

# a < b
# slt $t0, $s0, $s1
# beq $t0, $zero, FIM_IF

# a > b -> b < a
# slt $t0, $s1, $s2
# beq $t0, $zero, FIM_IF

# a >= b -> !(a < b)
# slt $t0, $s0, $s1
# bne $t0, $zero, FIM_IF

# a <= b -> !(b < a)
# slt $t0, $s1, $s0
# beq $t0, $zero, FIM_IF

# a == b
# bne $s0, $s1, FIM_IF

# a != b
# beq $s0, $s1, FIM_IF

# a < 10
# slt $t0, $s0, 10
# beq $t0, $zero, FIM_IF

# a > 10 -> a - 10 > 0; 0 < a - 10
# addi $t0, $s0, -10
# slt $t0, $zero, $t0
# beq $t0, $zero, FIM_IF
