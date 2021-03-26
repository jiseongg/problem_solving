#include <iostream>

int _gcd(int a, int b)
{
	int res = b ? _gcd(b, a%b) : a;
	return res;
}

int main()
{
	int a, b;
	int gcd, lcm;

	std::cin >> a >> b;
	
	gcd = _gcd(a, b);
	lcm = (a / gcd) * b;

  std::cout << gcd << std::endl;
  std::cout << lcm << std::endl;

	return 0;
}
