#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

std::pair<int, int>	find_lowest_pair(std::vector<int>& a, std::vector<int>& b)
{
	std::pair<int, int> p;

	p.first = INT_MAX;
	p.second = INT_MAX;

	int index_a = 0;
	int index_b = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] < p.first)
		{
			p.first = a[i];
			index_a = i;
		}
		if (b[i] < p.second)
		{
			p.second = b[i];
			index_b = i;
		}
	}
	a.erase(a.begin() + index_a);
	b.erase(b.begin() + index_b);
	return p;
}

int calc_total_distance(std::vector<int>& a, std::vector<int>& b)
{
	int sum = 0;
	while (not a.empty() || not b.empty())
	{
		std::pair<int, int> lowest_pair = find_lowest_pair(a, b);
		sum += std::abs(lowest_pair.first - lowest_pair.second);
	}
	return sum;
}

int	calc_simularity_score(std::vector<int>& a, std::vector<int>& b)
{
	unsigned long sum = 0;
	int count = 0;
	for (auto num_a : a)
	{
		for (auto num_b : b)
		{
			if (num_a == num_b)
				count++;
		}
		sum += num_a * count;
		count = 0;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "No input" << std::endl;
		return -1;
	}

	std::ifstream file(argv[1]);

	std::vector<int> a;
	std::vector<int> b;
	std::string line;
	while(std::getline(file, line))
	{
		// std::cout << line << std::endl;
		int number_one = std::stoi(line.substr(line.find_first_of("0123456789"), line.find_first_of(" ")));
		int number_two = std::stoi(line.substr(line.find_last_of(" ") + 1, line.find_last_of("0123456789")));
		a.push_back(number_one);
		b.push_back(number_two);
	}
	// std::cout << calc_total_distance(a, b) << std::endl;
	std::cout << calc_simularity_score(a, b) << std::endl;
}

