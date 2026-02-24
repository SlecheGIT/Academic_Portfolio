# Instruções para gravação em memória
# sw reg1, offset (reg2)
# -> reg1 - palavra a ser gravada
# -> reg2 - endereço base na MEM
# -> offset(número sinalizado de 16 bits) - deslocamento a partir de reg2
#	      (dado em número de bytes)
#	      MEM[reg2+offset] <- reg1, onde (reg2+offset) é multiplo de 4

# sh - store half word - multiplo de 2
# sb - store byte
# sp - contém o 1 endereço livre do programa
 
 
addi $s0, $zero, 0XFFF
sh $s0, 0($sp) # sp + 0
sh $s0, 2($sp) # sp + 2
sw $s0, -4($sp) # sp - 4

lw $s0, 0($sp)

addi $v0, $zero, 10
syscall