.text
.glob _start:
li $a0, 20
li $a1,20
jal pgcd
move $a0,$v0
jal print_int
syscall

pgcd :
sub $sp,$sp,32
sw $a0,28($sp)
sw $a1,24($sp)
sw $ra,20($sp)
sw $fp,16($sp)
add $fp,$sp,32
	if :
		bnez $a1,else
		
	else :
		move $a0,$a1
		rem $a1,$a0,$a1
		jal pgcd
sw $a0,28($sp)
sw $a1,24($sp)
sw $ra,20($sp)
sw $fp,16($sp)
sub $sp,$sp,32