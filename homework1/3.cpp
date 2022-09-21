#include <iostream>

int main()
{
	int a = 5;
	int b = 9;
	a = a + b;
	b = -b + a;
	a = a - b;
	std::cout << a << ' ' << b;
}
