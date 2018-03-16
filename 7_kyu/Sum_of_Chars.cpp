/*
Compare two strings by comparing the sum of their values (ASCII character code).

For comparing treat all letters as UpperCase
null/NULL/Nil/None should be treated as empty strings
If the string contains other characters than letters, treat the whole string as it would be empty
Your method should return true, if the strings are equal and false if they are not equal.
*/

bool compare(std::string s1, std::string s2)
{
    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	int sum1 = 0;
	int sum2 = 0;
	int length = 0;
	bool foundNonChar1 = false;
	bool foundNonChar2 = false;

	if (s1.length() > s2.length())
		length = s1.length();
	else
		length = s2.length();

	for (int i = 0; i < length; i++)
	{
		if (s1.length() > i)
		{
			sum1 += (int)s1.at(i);

			if ((s1.at(i) < 65) || (s1.at(i) > 90))
				foundNonChar1 = true;
		}

		if (s2.length() > i)
		{
			sum2 += (int)s2.at(i);

			if ((s2.at(i) < 65) || (s2.at(i) > 90))
				foundNonChar2 = true;
		}
	}

	if (foundNonChar1 == true)
		sum1 = 0;

	if (foundNonChar2 == true)
		sum2 = 0;

	if (sum1 == sum2)
		return true;


	return false;
}