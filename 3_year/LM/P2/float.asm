main:
	addi $v0, $zero, 7
	syscall
	
	mov.d $f20, $f0

	syscall
	mov.d $f22, $f0

	add.d $f24, $f20, $f22

	mov.d $f12, $f24

	addi $v0, $zero, 3
	syscall
	
	addi $v0, $zero, 10
	syscall
	
