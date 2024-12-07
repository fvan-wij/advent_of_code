#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

std::set<std::pair<int, int>>	get_sets_from_file(const std::string& file_path, std::set<std::pair<int, int>>& page_set, std::vector<std::vector<int>>& update_set)
{
	std::ifstream file(file_path);
	std::string line;

	// Get the pages
	while(std::getline(file, line) && line != "")
	{
		std::string a = line.substr(0, line.find("|"));
		std::string b = line.substr(line.find("|") + 1, 2);

		page_set.insert({std::stoi(a), std::stoi(b)});
	}

	// Get the updates
	std::string	number;
    while (std::getline(file, line))
	{
        std::stringstream ss(line); // Use a stringstream to split by commas
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



unsigned int	solve_a(std::set<std::pair<int, int>> page_set, std::vector<std::vector<int>> update_set)
{
	unsigned int answer_b = 0;
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
	unsigned int answer_b = 0;
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
	std::cout << "Answer b: " << answer_b << std::endl;
}

