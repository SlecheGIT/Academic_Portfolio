.data
prompt_msg: .asciiz "Digite um numero inteiro: "

.text
.globl main

main:
    # 1. Exibe uma mensagem para o usuário
    addi $v0, $zero ,4              # Código de serviço para imprimir string
    addi $a0, $zero ,%hi(prompt_msg)     # Endereço da string a ser impressa
    syscall

    # 2. Lê o inteiro do teclado
    li $v0, 5              # Código de serviço para ler inteiro
    syscall                # Executa a leitura. O resultado fica em $v0

    # 3. Move o inteiro lido para $t0 para uso futuro
    move $t0, $v0          # move $t0, $v0

    # Agora o inteiro está em $t0. Para imprimi-lo de volta:
    li $v0, 1              # Código de serviço para imprimir inteiro
    move $a0, $t0          # Coloca o número a ser impresso em $a0
    syscall

    # Finaliza o programa
    li $v0, 10      # Código para terminar a execução
    syscall
 