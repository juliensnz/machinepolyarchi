## Squelette pour la programmation en assembleur MIPS
## Université de Nantes
## S21I010
## (c) 2008, Frederic Goualard.
	
	.text
	.globl _start

_start:
## Insérer ici le code du programme principal

li $a0, 20
li $a1,10
jal pgcd
move $a0,$v0
jal print_int



## Fin du programme principal 		
	li   	$v0, 10
	syscall


## Insérer ci-dessous le code des procédures et fonctions additionnelles

pgcd :
sub $sp,$sp,32
sw $a1,28($sp)
sw $a0,24($sp)
sw $ra,20($sp)
sw $fp,16($sp)
add $fp,$sp,32

if :
bnez $a1,else
b return

else :
move $t0,$a1
rem $a1,$a0,$a1
move $a0,$t0
jal pgcd

return:
lw $a1,28($sp)
lw $a0,24($sp)
lw $ra,20($sp)
lw $fp,16($sp)
sub $sp,$sp,32

jr $ra

## Fin des procédures et fonctions additionnelles

	.data
## Insérer ici les données globales du programme


## Fin des données globales du programme
	
	
##############################
## Ne rien modifier ci-dessous
##############################

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
