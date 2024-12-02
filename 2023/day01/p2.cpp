#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

int isspelledoutdigit(std::string str, int i)
{
   std::string numberSet[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    size_t pos;

    pos = 0;
    int j = 0;
    while (j < 9)
    {
        if (str.compare(i, numberSet[j].size(), numberSet[j]) == 0)
            return  (j + 1);
        j++;
    }
    return (0);
}

char	first_digit_in_str(std::string str)
{
	int i;
	char digit;

	i = 0;
	digit = 0;
	while (i < str.size())
	{
        digit = isspelledoutdigit(str, i) + 48;
        if (digit != '0')
            return (digit);
        else if (isdigit(str[i]))
		{
			digit = str[i];
			return (digit);
		}
		i++;
	}
	return ('x');
}

char	last_digit_in_str(std::string str)
{
	int i;
	char digit;

	i = str.size();
	digit = 0;
	while (i >= 0)
	{
        digit = isspelledoutdigit(str, i) + 48;
        if (digit != '0')
            return (digit);
        else if (isdigit(str[i]))
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
	std::ifstream   file("input");
	std::string     str;
    int             calibration_value;
	int             sum;

	sum = 0;
    calibration_value = 0;
	while (std::getline(file, str))
	{
		std::string digits;
		digits.push_back(first_digit_in_str(str));
		digits.push_back(last_digit_in_str(str));

		calibration_value = stoi(digits);
		sum += calibration_value;
	}
    std::cout << "Sum is: " << sum << std::endl;
}
