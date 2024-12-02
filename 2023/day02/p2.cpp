#include <fstream>
#include <iostream>
#include <string>

int	cube_count(std::string str, const char color, int limit)
{
	std::string	digits;
	int			nCubes;
	int			maxCubes;
	int 		i;

	nCubes = 0;
	maxCubes = 0;
	i = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ';' && digits.size() != 0)
			digits.clear();
		else if (std::isdigit(str[i]))
			digits.push_back(str[i]);
		else if (str[i] == ' ' && str[i + 1] == color)
		{
			nCubes = stoi(digits);
			if (nCubes > maxCubes)
				maxCubes = nCubes;
		}
		else
			digits.clear();
	}
	i++;
	return (maxCubes);
}

int main()
{
	int				maxR;
	int				maxG;
	int				maxB;
	int				sum;
	std::ifstream 	file("input");
	// std::ifstream 	file("test");
	std::string		str;

	sum = 0;
	maxR = 0;
	maxG = 0;
	maxB = 0;
	while (std::getline(file, str))
	{
		maxR = cube_count(&str[str.find(":")], 'r', maxR);
		maxG = cube_count(&str[str.find(":")], 'g', maxG);
		maxB = cube_count(&str[str.find(":")], 'b', maxB);

		int power = maxR * maxG * maxB;
		sum += power;
		std::cout << "Power: " << power << std::endl;
	}
	std::cout << "Sum: " << sum << std::endl;
}