#P1
sum = 0
i = 0
calories = []

with open('Day_1/input_d1.txt') as f:
	for line in f:
		if line[0] != '\n':
			sum+=int(line)
		if line[0] == '\n':
			calories.append(sum)
			sum = 0

max_calories = max(calories)
print("Max calories = {}".format(max_calories))
