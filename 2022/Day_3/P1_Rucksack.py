#P1
result = 0
with open('Day_3/input.txt') as f:
	for line in f:
		n = len(line)
		s1 = line[0:n//2]
		s2 = line[n//2:]
		set_s1 = set(s1)
		set_s2 = set(s2)
		overlap = list(set_s1 & set_s2)
		print("\n1st half {}\n2nd half {}Overlap {}".format(s1, s2, overlap))
		value = ord(overlap[0])
		print("ASCII value of overlap {}".format(value))
		if overlap[0].isupper():
			letter_value = value - 38
		elif overlap[0].islower():
			letter_value = value - 96
		print("Priority value is {}".format(letter_value))
		result += letter_value
	print("\n--Result is: {}--\n".format(result))
