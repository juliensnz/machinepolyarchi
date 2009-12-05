	.text
	.globl _start

_start:
	la $a0, msg1
	jal print_string
	jal read_int
	move $s0, $v0
	la $a0, msg2
	jal print_string
	jal read_int
	move $a0, $s0
	move $a1, $v0
	jal proc
	move $s0, $v0
	la $a0, msg3
	jal print_string
	move $a0, $s0
	jal print_int
	
	# exit()
	li   	$v0, 10
	syscall


proc:
	sub $sp, $sp, 32
	sw $ra, 20($sp)
	sw $fp, 16($sp)
	add $fp, $sp, 32

	add $v0, $a0, $a1	

	lw $ra, 20($sp)
	lw $fp, 16($sp)
	add $sp, $sp, 32
	jr $ra


	.data
msg1: .asciiz "Premier nombre ? "
msg2: .asciiz "Deuxième nombre ? "
msg3: .asciiz "Résultat : "

#########################
#########################

	.text
# print_char --
# Affiche le caractère se trouvant dans $a0
print_char:
	sub 	$sp, $sp, 32
	sw		$ra, 20($sp)
	sw		$fp, 16($sp)
	add 	$fp, $sp, 32

	li	$v0, 11
	syscall
	
	lw		$ra, 20($sp)
	lw		$fp, 16($sp)
	add		$sp, $sp, 32
	jr		$ra


# print_string --
# Affiche la chaîne dont l'adresse se trouve dans $a0
print_string:
	sub 	$sp, $sp, 32
	sw		$ra, 20($sp)
	sw		$fp, 16($sp)
	add 	$fp, $sp, 32

	li		$v0, 4
	syscall
	
	lw		$ra, 20($sp)
	lw		$fp, 16($sp)
	add		$sp, $sp, 32
	jr		$ra

# print_int --
# Affiche l'entier signé se trouvant dans $a0
print_int:
	sub 	$sp, $sp, 32
	sw		$ra, 20($sp)
	sw		$fp, 16($sp)
	add 	$fp, $sp, 32
	
	li $v0, 1
	syscall

	lw		$ra, 20($sp)
	lw		$fp, 16($sp)
	add		$sp, $sp, 32
	jr		$ra

	
# read_int --
# Lit un entier signé au clavier et le retourne dans $v0
read_int:
	sub 	$sp, $sp, 32
	sw		$ra, 20($sp)
	sw		$fp, 16($sp)
	add 	$fp, $sp, 32
	
	li $v0, 5
	syscall
	
	lw		$ra, 20($sp)
	lw		$fp, 16($sp)
	add		$sp, $sp, 32
	jr		$ra
