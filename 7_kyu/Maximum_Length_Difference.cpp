/*
You are given two arrays a1 and a2 of strings. 
Each string is composed with letters from a to z. 
Let x be any string in the first array and y be any string in the second array.

Find max(abs(length(x) − length(y)))
*/

class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2)
    {
    if (a1.empty() || a2.empty())
			return -1;


		int xmin = a1.front().size();
		int xmax = a1.front().size();

		int ymin = a2.front().size();
		int ymax = a2.front().size();

		for (int i = 0; i < a1.size(); i++)
		{
			if (a1.at(i).size() > xmax)
			{
				xmax = a1.at(i).size();
			}

			if (a1.at(i).size() < xmin)
			{
				xmin = a1.at(i).size();
			}
		}

		for (int i = 0; i < a2.size(); i++)
		{
			if (a2.at(i).size() < ymin)
			{
				ymin = a2.at(i).size();
			}

			if (a2.at(i).size() > ymax)
			{
				ymax = a2.at(i).size();
			}
		}

		if ((abs(xmax - ymin)) > (abs(ymax - xmin)))
		{
			return (abs(xmax - ymin));
		}
		else return (abs(ymax - xmin));
    }
};