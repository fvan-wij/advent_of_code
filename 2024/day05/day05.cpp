#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

std::set<std::pair<int, int>>	get_sets_from_file(const std::string& file_path, std::set<std::pair<int, int>>& page_set, std::vector<std::vector<int>>& update_set)
{
	std::ifstream file(file_path);
	std::string line;

	while(std::getline(file, line) && line != "") // Get the pages 
	{
		std::string a = line.substr(0, line.find("|"));
		std::string b = line.substr(line.find("|") + 1, 2);

		page_set.insert({std::stoi(a), std::stoi(b)});
	}

	std::string	number;
    while (std::getline(file, line)) // Get the updates 
	{
        std::stringstream ss(line);
		std::vector<int> temp;
        while (std::getline(ss, number, ','))
		{
			temp.push_back(std::stoi(number));
        }
		update_set.push_back(temp);
    }
	for (auto& [a, b] : page_set)
	{
		std::cout << "[" << a << ", " << b << "]" << std::endl;
	}

    for (const auto& s : update_set) 
	{
        std::cout << "{ ";
        for (const auto& elem : s)
		{
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }

	return page_set;
}

bool	set_is_valid(std::vector<int> pages, std::set<std::pair<int, int>> rules)
{
	for (auto& [x, y] : rules)
	{
		auto px = std::find(pages.begin(), pages.end(), x);
		auto py = std::find(pages.begin(), pages.end(), y);
		if (px != pages.end() && py != pages.end())
		{

			auto x_index = px - pages.begin();
			auto y_index = py - pages.begin();
			if (x_index >= y_index)
			{
				return false;
			}
		}
	}
	return true;
}

unsigned int	solve_a(std::set<std::pair<int, int>> rules, std::vector<std::vector<int>> vec_pages)
{
	unsigned int answer_b = 0;

	for (auto& pages : vec_pages)
	{
		if (set_is_valid(pages, rules))
		{
			answer_b += pages[std::ceil((pages.size() / 2))];
		}
	}
	return answer_b;
}
//
// unsigned int	solve_b(const std::vector<std::vector<char>> grid)
// {
// 	unsigned int answer_b = 0;
// 	return answer_b;
// }


int main(int argc, char *argv[])
{
	unsigned int answer_a = 0;
	// unsigned int answer_b = 0;
	if (argc == 1)
	{
		std::cerr << "No input" << std::endl;
		return -1;
	}
	else
	{
		std::set<std::pair<int, int>> page_set;
		std::vector<std::vector<int>> update_set;
		get_sets_from_file(argv[1], page_set, update_set);
		answer_a = solve_a(page_set, update_set);
		// answer_b = solve_b(grid);
	}
	std::cout << "Answer a: " << answer_a << std::endl;
	// std::cout << "Answer b: " << answer_b << std::endl;
}

