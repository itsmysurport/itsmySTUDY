#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("");
	cout << str + ": " << sizeof(str) << endl;
	str = "ASDASDASDASASDASDASDASASDASDASDASASDASDASDAS";
	cout << sizeof(str) << endl;

	return 0;
}