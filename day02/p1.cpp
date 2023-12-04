#include <fstream>
#include <iostream>
#include <string>

int	cube_limit_exceeded(std::string str, const char color, int limit)
{
	std::string	digits;
	int			nCubes;
	int 		i;

	nCubes = 0;
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
			// std::cout << "nOfCubes" << nCubes << std::endl;
			if (nCubes > limit)
				return (nCubes);
		}
		else
			digits.clear();
	}
	i++;
	return (0);
}

int main()
{
	const int		maxR = 12;
	const int		maxG = 13;
	const int		maxB = 14;
	int				sum;
	std::ifstream 	file("input");
	// std::ifstream 	file("test");
	std::string		str;

	sum = 0;
	while (std::getline(file, str))
	{
		if (!cube_limit_exceeded(&str[str.find(":")], 'r', maxR)
			&& !cube_limit_exceeded(&str[str.find(":")], 'g', maxG)
			&& !cube_limit_exceeded(&str[str.find(":")], 'b', maxB))
			{
				std::string game_id;
				for (char character : str)
				{
					if (std::isdigit(character))
						game_id.push_back(character);
					else if (character == ':')
						sum += stoi(game_id);
				}
			}
	}
	std::cout << "Sum is: " << sum << std::endl;
}
