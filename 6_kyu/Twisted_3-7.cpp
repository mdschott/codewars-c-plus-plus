/*
There is a planet... in a galaxy far far away. It is exactly like our planet, but it has one difference:

#The values of the digits 3 and 7 are twisted. Our 3 means 7 on the planet Twisted-3-7. And 7 means 3.

Your task is to create a method, that can sort an array the way it would be sorted on Twisted-3-7.

7 Examples from a friend from Twisted-3-7:

[1,2,3,4,5,6,7,8,9] -> [1,2,7,4,5,6,3,8,9]
[12,13,14] -> [12,14,13]
[9,2,4,7,3] -> [2,7,4,3,9]
There is no need for a precheck. The array will always be not null and will always contain at least one number.

You should not modify the input array!
*/

#include <vector>
using namespace std;

vector <int> sortTwisted37 (vector <int> numbers) {
  
	std::string value = "";
	int trueValue = 0;
	std::vector<int> result;

	for (int i = 0; i < numbers.size(); i++)
	{
		value = std::to_string(numbers.at(i));
		

		for (int j = 0; j < value.length(); j++)
		{
			
			if (value.at(j) == '3')
			{
				value.replace(j, 1 , "7");
			}
			else if (value.at(j) == '7')
			{
				value.replace(j, 1 , "3");
			}
		}
		trueValue = std::stoi(value);
		result.push_back(trueValue);
		std::sort(result.begin(), result.end());
	}

	for (int i = 0; i < result.size(); i++)
	{
		value = std::to_string(result.at(i));

		for (int j = 0; j < value.length(); j++)
		{
			if (value.at(j) == '3')
			{
				value.replace(j, 1, "7");
			}
			else if (value.at(j) == '7')
			{
				value.replace(j, 1, "3");
			}
		}
		trueValue = std::stoi(value);
		result.at(i) = trueValue;
	}

	return result;
}