.text
.globl main

main:
    addiu $v0, $zero, 5
    syscall
    
    addiu $a0, $v0, 0
    
    jal van_eck
    
    addiu $s0, $v0, 0
    
    addiu $v0, $zero, 1
    addiu $a0, $s0, 0
    syscall
    
    addiu $v0, $zero, 10
    syscall

van_eck:
    addiu $sp, $sp, -28
    sw $ra, 24($sp)
    sw $s0, 20($sp)
    sw $s1, 16($sp)
    sw $s2, 12($sp)
    sw $s3, 8($sp)
    sw $s4, 4($sp)
    sw $s5, 0($sp)
    
    addiu $s0, $a0, 0

    bne $s0, $zero, van_eck_continue
    addiu $v0, $zero, 0
    j van_eck_epilogue
van_eck_continue:

    addiu $t0, $s0, 1
    sll $t0, $t0, 2
    
    addiu $a0, $t0, 0
    addiu $v0, $zero, 9
    syscall
    addiu $s1, $v0, 0
    
    addiu $a0, $t0, 0
    addiu $v0, $zero, 9
    syscall
    addiu $s2, $v0, 0

    addiu $t0, $s0, 1
    addiu $t1, $s2, 0
    addiu $t2, $zero, -1
init_loop:
    beq $t0, $zero, init_loop_end
    sw $t2, 0($t1)
    addiu $t1, $t1, 4
    addiu $t0, $t0, -1
    j init_loop
init_loop_end:

    sw $zero, 0($s1)
    addiu $s4, $zero, 0
    
    addiu $s3, $zero, 1
loop_start:
    slt $t0, $s0, $s3
    bne $t0, $zero, loop_end

    addiu $s5, $zero, 0
    
    sll $t0, $s4, 2
    add $t0, $t0, $s2
    lw $t1, 0($t0)
    
    addiu $t2, $zero, -1
    beq $t1, $t2, skip_calc
    
    addiu $t2, $s3, -1
    sub $s5, $t2, $t1
    
skip_calc:
    sll $t0, $s3, 2
    add $t0, $t0, $s1
    sw $s5, 0($t0)
    
    addiu $t2, $s3, -1
    sll $t0, $s4, 2
    add $t0, $t0, $s2
    sw $t2, 0($t0)
    
    addiu $s4, $s5, 0
    
    addiu $s3, $s3, 1
    j loop_start
loop_end:

    sll $t0, $s0, 2
    add $t0, $t0, $s1
    lw $v0, 0($t0)
    
van_eck_epilogue:
    lw $s5, 0($sp)
    lw $s4, 4($sp)
    lw $s3, 8($sp)
    lw $s2, 12($sp)
    lw $s1, 16($sp)
    lw $s0, 20($sp)
    lw $ra, 24($sp)
    addiu $sp, $sp, 28
    
    jr $ra