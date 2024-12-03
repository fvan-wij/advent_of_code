#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

std::vector<std::string> tokenize_string(std::string string, std::string delimiter)
{
        std::vector<std::string>        tokens;
        size_t                          pos = 0;

        pos = string.find(delimiter);
        while (pos != std::string::npos)
        {
                        std::string token = string.substr(0, pos);
                        if (!token.empty() && token != "\n")
                        {
                			tokens.push_back(token);
                        }
                        string.erase(0, pos + delimiter.length());
                        pos = string.find(delimiter);
        }
                if (!string.empty())
                tokens.push_back(string);
        return tokens;
}

bool	valid_parentheses(std::string& token)
{
	size_t i = 0;
	if (token[i] != '(')
		return false;
	i++;
	while (token[i] && (std::isdigit(token[i]) || token[i] == ','))
	{
		i++;
	}
	if (token[i] == ')')
		return true;
	return false;
}

void	toggle_state(std::string& token, bool& toggle)
{
	size_t do_index = token.find("do()");
	size_t dont_index = token.find("don't()");
	if (do_index != std::string::npos)
	{
		toggle = true;
	}
	else if (dont_index != std::string::npos)
	{
		toggle = false;
	}
}

bool valid_digit_length(std::string& digits_a, std::string& digits_b)
{
	size_t count_a = std::count_if( digits_a.begin(), digits_a.end(), 
			[]( char c ) { return std::isdigit( c ); } );
	size_t count_b = std::count_if( digits_b.begin(), digits_b.end(), 
			[]( char c ) { return std::isdigit( c ); } );
	if ((count_a == 0 || count_a > 3) || (count_b  == 0 || count_b > 3))
		return false;
	return true;
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
	unsigned long answer = 0;

	bool toggle = true;
	while(std::getline(file, line))
	{
		std::vector<std::string> tokens = tokenize_string(line, "mul");

		for (size_t i = 1; i < tokens.size(); i++)
		{
			std::string& curr_token = tokens[i];
			std::string& prev_token = tokens[i - 1];
			toggle_state(prev_token, toggle); // Disable this function to get answer A
			if (valid_parentheses(curr_token) && toggle)
			{

				std::string digits_a = curr_token.substr(curr_token.find_first_of("01234567890"), curr_token.find_first_of(","));
				std::string digits_b = curr_token.substr(curr_token.find_first_of(",") + 1, curr_token.find_last_not_of("1234567890", curr_token.find_first_of(",") + 1) + 1);

				if (valid_digit_length(digits_a, digits_b))
					answer += std::stoi(digits_a) * std::stoi(digits_b);
			}
		}

	}
	std::cout << "Answer: " << answer << std::endl;
}

