#P1
crateRow =	([['S', 'Z', 'P', 'D', 'L', 'B', 'F', 'C'], 
['N', 'V', 'G', 'P', 'H', 'W', 'B'],
['F', 'W', 'B', 'J', 'G'],
['G', 'J', 'N', 'F', 'L', 'W', 'C', 'S'],
['W', 'J', 'L', 'T', 'P', 'M', 'S', 'H'],
['B', 'C', 'W', 'G', 'F', 'S'],
['H', 'T', 'P', 'M', 'Q', 'B', 'W'],
['F', 'S', 'W', 'T'], 
['N', 'C', 'R']])

instructions = []

with open('day_5/input.txt') as f: #Parse input
	for lineno, line in enumerate(f):
		if lineno > 9:
			instructions.append([int(s) for s in line.split() if s.isdigit()])

def move_crate(nOfCrates, sourc, dest): #Delete nOfCrates from source and append to destination
	temp = []
	temp.append(crateRow[sourc - 1][-nOfCrates:])
	del crateRow[sourc - 1][-nOfCrates:]
	j = len(temp[0]) - 1
	while j != -1:
		crateRow[dest - 1].append(temp[0][j])
		j -= 1

n = [] #n of crates to be moved
src = [] #from source
dst = [] #to destination

for i in range(len(instructions)): #Parse instructions into seperate int variables
	n.append(instructions[i][0])
	src.append(instructions[i][1])
	dst.append(instructions[i][2])

for j in range(len(instructions)): #Iterate move_crate() using parsed instructions
	move_crate(n[j], src[j], dst[j])

print(crateRow)

#P1 = FWSHSPJWM