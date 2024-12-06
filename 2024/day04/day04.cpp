#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

const std::string PATTERN = {"XMAS"};

const std::unordered_map<std::string, std::pair<int, int>> DIRECTIONS = 
{
	{"Up", 			{-1, 0}},
	{"RightUp",		{-1, 1}},
	{"Right",		{0, 1}},
	{"RightDown",	{1, 1}},
	{"Down",		{1, 0}},
	{"DownLeft",	{1, -1}},
	{"Left",		{0, -1}},
	{"UpLeft",		{-1, -1}}
};

std::vector<std::vector<char>>	get_2d_arr_from_file(const std::string& file_path)
{
	std::ifstream file(file_path);
	std::vector<std::vector<char>>	grid;
	std::string line;

	while(std::getline(file, line))
	{
		std::vector<char> chars;
		for (char c : line)
			chars.push_back(c);
		grid.push_back(chars);
	}

	return grid;
}


int	recursive_pattern_search(const std::vector<std::vector<char>>& grid, int row, int col, const std::string& dir, size_t iteration)
{
	if (iteration < PATTERN.size())
		std::cout << "Iteration: " << iteration << ", looking for letter: " << PATTERN[iteration] << std::endl;
	else
		return iteration;
	// Base cases
	if (row < 0 || row > static_cast<int>(grid.size()))
		return iteration;
	if (col < 0 || col > static_cast<int>(grid[row].size()))
		return iteration;
	if (not grid[row][col] || grid[row][col] != PATTERN[iteration])
		return iteration;

	// Recursive cases
	return recursive_pattern_search(grid, row + DIRECTIONS.at(dir).first, col + DIRECTIONS.at(dir).second, dir, iteration + 1);
}


int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "No input" << std::endl;
		return -1;
	}
	else
	{
		auto grid = get_2d_arr_from_file(argv[1]);
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[j].size(); j++)
			{
				for (auto& dir : DIRECTIONS)
				{
					if (recursive_pattern_search(grid, i, j, dir.first, 0) == static_cast<int>(PATTERN.length()))
						std::cout << "YOINKS" << std::endl;
				}
			}
		}
	}
	// std::cout << "Answer: " << answer << std::endl;
}

