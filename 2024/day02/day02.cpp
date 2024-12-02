#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <sstream>

bool	is_safe(int a, int b)
{
	return (std::abs(a - b) >= 1 && std::abs(a - b) <= 3);
}

bool	is_safe_and_increasing(std::vector<int>& int_line)
{
	size_t count = 0;

	for (size_t i = 0; i < int_line.size(); i++)
	{
		if (i != 0)
		{
			if (int_line[i] > int_line[i - 1] && is_safe(int_line[i], int_line[i - 1]))
			{
				count++;
			}
		}
	}
	return (count == int_line.size() - 1);
}

bool	is_safe_and_decreasing(std::vector<int>& int_line)
{
	size_t count = 0;

	for (size_t i = 0; i < int_line.size(); i++)
	{
		if (i != 0)
		{
			if (int_line[i] < int_line[i - 1] && is_safe(int_line[i], int_line[i - 1]))
			{
				count++;
			}
		}
	}
	return (count == int_line.size() - 1);
}

bool	tolerates_single_bad_level(std::vector<int>& int_line)
{

	for (size_t i = 0; i < int_line.size(); i++)
	{
		std::vector<int> temp_line = int_line;
		temp_line.erase(temp_line.begin() + i);
		if (is_safe_and_decreasing(temp_line) || is_safe_and_increasing(temp_line))
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "No input" << std::endl;
		return -1;
	}

	std::ifstream file(argv[1]);
	std::string line;
	int safe_reports = 0;
	int tolerates_bad_lvl = 0;

	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::vector<int> int_line;
		std::string number;

		while (ss >> number)
		{
			int_line.push_back(std::stoi(number));
		}

		if (is_safe_and_decreasing(int_line) || is_safe_and_increasing(int_line))
		{
			safe_reports++;
		}

		if (tolerates_single_bad_level(int_line))
		{
			tolerates_bad_lvl++;
		}
	}
	std::cout << "Answer part A: " << safe_reports << std::endl;
	std::cout << "Answer part B: " << tolerates_bad_lvl << std::endl;
}

