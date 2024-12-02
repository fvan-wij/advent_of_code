#P2
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

		if Your_hand == 'X': #Lose
			points += lose
			if Elf_hand == 'A':
				points += z
			if Elf_hand == 'B':
				points += x
			if Elf_hand == 'C':
				points += y

		elif Your_hand == 'Y': #Draw
			points += draw
			if Elf_hand == 'A':
				points += x
			if Elf_hand == 'B':
				points += y
			if Elf_hand == 'C':
				points += z

		elif Your_hand == 'Z': #Win
			points += win
			if Elf_hand == 'A':
				points += y
			if Elf_hand == 'B':
				points += z
			if Elf_hand == 'C':
				points += x

print(points)
