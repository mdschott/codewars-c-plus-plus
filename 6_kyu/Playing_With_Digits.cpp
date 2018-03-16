/*
Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1

695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2

46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p,
we want to find a positive integer k, if it exists, such as the sum of the digits of n taken to the successive powers of p is equal to k * n.

In other words:
Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

If it is the case we will return k, if not return -1.

Note: n, p will always be given as strictly positive integers.
*/

#include <cmath>
#include <stack>

class DigPow
{
public:
  static int digPow(int n, int p)
  {
  int exponentialNumber = 0;
	std::stack<int> parsedNumber;
	int k = 1;
	int x = n;
	int exponent = 0;

	//Formula:
	//(K/10^(N-1)) mod 10 
	while (x >= 1)
	{
		parsedNumber.push(((int)(n / (std::pow(10, exponent))) % 10));
		exponent++;
		x = x / 10;
	}

	exponent = p;
	x = parsedNumber.size();
	for (int i = 0; i < x; i++)
	{
		exponentialNumber += (int)(std::pow(parsedNumber.top(), exponent));
		parsedNumber.pop();
		exponent++;
	}

	while ((k * n) <= exponentialNumber)
	{
		if ((k * n) == exponentialNumber)
			return k;
		k++;
	}

	return -1;

  }
};