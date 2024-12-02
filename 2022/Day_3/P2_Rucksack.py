#P2
step = 3
i = 0
result = 0
with open('Day_3/input.txt') as f:
	for lineno, line in enumerate(f):
		if lineno % step < 3:
			if lineno % step == 0:
				s1 = set(line[0:-1])
			if lineno % step == 1:
				s2 = set(line[0:-1])
			if lineno % step == 2:
				s3 = set(line[0:-1])
				overlap = list(s1 & s2 & s3)
				print("Overlap in group({}) = {}".format(i, overlap))
				i += 1
				value = ord(overlap[0])
				if overlap[0].isupper():
					letter_value = value - 38
				elif overlap[0].islower():
					letter_value = value - 96
				result += letter_value
print("\n--Sum of all the overlapping items in each group is: {}--\n".format(result))