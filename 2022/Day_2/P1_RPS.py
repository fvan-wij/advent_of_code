#P1
#A = Rock
#B = Paper
#C = Scissors

points = 0

lose = 0 #Lose = 0p
draw = 3 #Draw = 3p
win  = 6 #Win = 6p

x = 1 #X = Rock // 1p
y = 2 #Y = Paper // 2p
z = 3 #Z = Scissors //3p

with open('strategy.txt') as f:
	for line in f:

		Elf_hand = line[0]
		Your_hand = line[2]

		if Your_hand == 'X' and Elf_hand == 'A' or Your_hand == 'Y' and Elf_hand == 'B' or Your_hand == 'Z' and Elf_hand == 'C':
			points += draw
		elif Your_hand == 'X':
			if Elf_hand == 'B':
				points += lose
			else: points += win

		elif Your_hand == 'Y':
			if Elf_hand == 'C':
				points += lose
			else: points += win

		elif Your_hand == 'Z':
			if Elf_hand == 'A':
				points += lose
			else: points += win
		if Your_hand == 'X':
			points += x
		if Your_hand == 'Y':
			points += y
		if Your_hand == 'Z':
			points += z
		print("Elf hand is {}\nYour hand is {}".format(Elf_hand, Your_hand))
		print("Plus your hand {} is {}\n".format(Your_hand, points))

print(points)
