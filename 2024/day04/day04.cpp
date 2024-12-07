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


int	recursive_pattern_search(const std::vector<std::vector<char>>& grid, int row, int col, 
		const std::string& dir, const std::string& pattern, size_t iteration)
{
	// Base cases
	if (iteration > pattern.size() - 1)
		return iteration;
	if (row < 0 || row > static_cast<int>(grid.size()) - 1)
		return iteration;
	if (col < 0 || col > static_cast<int>(grid[row].size()) - 1)
		return iteration;
	if (grid[row][col] != PATTERN[iteration])
		return iteration;

	// Recursive case
	return recursive_pattern_search(grid, row + DIRECTIONS.at(dir).first,
			col + DIRECTIONS.at(dir).second, dir, pattern, iteration + 1);
}

unsigned int	solve_a(const std::vector<std::vector<char>>& grid)
{
	unsigned int answer = 0;
	std::string	pattern = "XMAS";
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			for (auto& dir : DIRECTIONS)
			{
				if (recursive_pattern_search(grid, i, j, dir.first, pattern, 0) == static_cast<int>(pattern.length()))
				{
					answer++;
				}
			}
		}
	}
	return answer;
}


bool	is_valid_coordinate(const std::vector<std::vector<char>>& grid, std::pair<int, int> dir)
{
	return ((dir.first >= 0 && dir.second >= 0) && (dir.first < (int)grid.size() - 1 && dir.second < (int)grid[dir.first].size()));
}

bool	is_mas(const std::vector<std::vector<char>>& grid, std::pair<int, int> dir_a, std::pair<int, int> dir_b)
{
	if (is_valid_coordinate(grid, dir_a) && is_valid_coordinate(grid, dir_b))
	{
		return ((grid[dir_a.first][dir_a.second] == 'M' && grid[dir_b.first][dir_b.second] == 'S') || (grid[dir_a.first][dir_a.second] == 'S' && grid[dir_b.first][dir_b.second] == 'M'));
	}
	return false;
}

unsigned int	solve_b(const std::vector<std::vector<char>> grid)
{
	unsigned int answer_b = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			std::pair<int, int> UL = {i - 1, j - 1};
			std::pair<int, int> DR = {i + 1, j + 1};
			std::pair<int, int> UR = {i - 1, j + 1};
			std::pair<int, int> DL = {i + 1, j - 1};

			if (grid[i][j] == 'A' && is_mas(grid, UL, DR) && is_mas(grid, UR, DL))
			{
				answer_b++;
			}
		}
	}

	return answer_b;
}


int main(int argc, char *argv[])
{
	unsigned int answer_a = 0;
	unsigned int answer_b = 0;
	if (argc == 1)
	{
		std::cerr << "No input" << std::endl;
		return -1;
	}
	else
	{
		auto grid = get_2d_arr_from_file(argv[1]);
		// answer_a = solve_a(grid);
		answer_b = solve_b(grid);
	}
	std::cout << "Answer a: " << answer_a << std::endl;
	std::cout << "Answer b: " << answer_b << std::endl;
}

