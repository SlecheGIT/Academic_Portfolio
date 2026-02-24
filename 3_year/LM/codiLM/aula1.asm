# int x, y, z, w
# x = y = z = w = 1

addi $v0, $zero, 5 # Código 5 em v0: Leitura de um inteiro
syscall
add $s0, $zero, $v0 # Leitura s0(x)

addi $v0, $zero, 5 # Código 5 em v0: Leitura de um inteiro
syscall
add $s1, $zero, $v0 # Leitura s1(y)

addi $v0, $zero, 5 # Código 5 em v0: Leitura de um inteiro
syscall
add $s2, $zero, $v0 # Leitura s2(z)

addi $v0, $zero, 5 # Código 5 em v0: Leitura de um inteiro
syscall
add $s3, $zero, $v0 # Leitura s3(w)


# addi $s0, $zero, 1 # s0(x) = 1
# addi $s1, $zero, 1 # s1(y) = 1
# addi $s2, $zero, 1 # s2(z) = 1
# addi $s3, $zero, 1 # s3(w) = 1

# x = (((x + y) - z) - w)
add $t0, $s0, $s1 # t0 = x + y
sub $t0, $t0, $s2 # t0 = t0 - z
sub $s0, $t0, $s3 # x = t0 - w

# Escrita
addi $v0, $zero, 1 # Código 1 em v0: Imprimir um inteiro em a0
add $a0, $zero, $s0 # Passar o valor de s0(x) para a0
syscall
