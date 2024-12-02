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

#P2
j = 0
sum_top_3 = 0
for j in range(3):
	max_calories = max(calories) #Find highest calories
	index = calories.index(max_calories) #Find index of highest calories in array
	print("Index of max = {}".format(index)) #Print index
	print("Max calories = {}".format(max_calories))
	sum_top_3 += max_calories
	del calories[index]
	j+=1

print("Sum of top 3 = {}".format(sum_top_3))


#Easier way of sorting top 3
print(sorted(calories, reverse=True)[:3])

