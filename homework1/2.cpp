#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a;
	float b;
	float c;
	cout << "coefficient before x^2"<<endl;
	cin >> a;
	cout << "coefficient before x" << endl;
	cin >> b;
	cout << "coefficient before x^0" << endl;
	cin >> c;
	float D;
	D = b * b - 4 * a * c;
	if (D < 0) {
		cout << "no solution";
		exit(0);
	}
	float x1 = (-b + sqrt(D)) / (2 * a);
	float x2 = (-b - sqrt(D)) / (2 * a);
	cout << "solution " << x1 << " and " << x2;
}
