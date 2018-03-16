/*
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. 
The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.
*/

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
  std::string s = in;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::string compare = "";
	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s.find_first_of(s.at(i)) != s.find_last_of(s.at(i)))
		{
			int x = compare.find(s.at(i));
			if (x < 0)
				count++;
				compare += s.at(i);
		}
		
	}

	return count;
}