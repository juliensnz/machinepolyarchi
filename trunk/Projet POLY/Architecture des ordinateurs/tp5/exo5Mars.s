## Squelette pour la programmation en assembleur MIPS
## Universit� de Nantes
## S21I010
## (c) 2008, Frederic Goualard.
	
	.text
	.globl _start

_start:
## Ins�rer ici le code du programme principal

li $a0, 20
li $a1,10
jal pgcd
move $a0,$v0
jal print_int



## Fin du programme principal 		
	li   	$v0, 10
	syscall


## Ins�rer ci-dessous le code des proc�dures et fonctions additionnelles

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

## Fin des proc�dures et fonctions additionnelles

	.data
## Ins�rer ici les donn�es globales du programme


## Fin des donn�es globales du programme
	
	
##############################
## Ne rien modifier ci-dessous
##############################

	.text
# print_char --
# Affiche le caract�re se trouvant dans $a0
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
# Affiche la cha�ne dont l'adresse se trouve dans $a0
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
# Affiche l'entier sign� se trouvant dans $a0
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
# Lit un entier sign� au clavier et le retourne dans $v0
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
