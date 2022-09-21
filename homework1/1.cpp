# include <iostream>
using namespace std;

int main()
{
    cout << "from SI to CGS" << endl;
    cout << "enter value"<<endl;
    float a;
    cin >> a;
    cout << "from m to cm" << endl;
    cout<< a * 100 << endl;
    cout << "from kg to g" << endl;
    cout<<a * 1000 << endl;
    cout << "from m/s to cm/c" << endl;
    cout<<a * 100 << endl;
    cout << "from m/s^2 to gal" << endl;
    cout<< a * 100 << endl;
    cout << "from n to dyne" << endl;
    cout<< a * 100000;
}