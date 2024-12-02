#P1

#Read each line, store left input in elf1 and right input in elf2
#Parse input to integers
#Check if elf1 is in range of elf2 or vice versa +1

pair = []
with open("Day_4/input.txt") as f:
	for line in f:
		strippedLine = line.rstrip('\n')
		filter = strippedLine.split(',')
		pair.append(filter)

x = 0
lineno = 0
for i in range(len(pair)):
		line2split = pair[i][0]
		elf1 = line2split.split('-') 
		line2split = pair[i][1]
		elf2 = line2split.split('-')
		lineno += 1
		if (int(elf1[0]) >= int(elf2[0]) and int(elf1[1]) <= int(elf2[1])) or (int(elf2[0]) >= int(elf1[0]) and int(elf2[1]) <= int(elf1[1])):
			print("Line no in which there is full overlap: {}".format(lineno))
			print("Elf1 = {}\t|\tElf2 = {}\n".format(elf1, elf2))
			x += 1

print("Total ", x)
