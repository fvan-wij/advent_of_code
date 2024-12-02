#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

char	return_first_digit_in_str(std::string str)
{
	int i;
	char digit;

	i = 0;
	digit = 0;
	while (i < str.size())
	{
		if (isdigit(str[i]))
		{
			digit = str[i];
			return (digit);
		}
		i++;
	}
	return ('x');
}

char	return_last_digit_in_str(std::string str)
{
	int i;
	char digit;

	i = str.size();
	digit = 0;
	while (i >= 0)
	{
		if (isdigit(str[i]))
		{
			digit = str[i];
			return (digit);
		}
		i--;
	}
	return ('x');
}

int main()
{
	std::ifstream file("input");
	std::string str;
	int sum;

	sum = 0;
	while (std::getline(file, str))
	{
		std::string digits;
		digits.push_back(return_first_digit_in_str(str));
		digits.push_back(return_last_digit_in_str(str));

		int calibration_value = stoi(digits);
		sum += calibration_value;
	}
	std::cout << "sum" << sum << std::endl;
}
