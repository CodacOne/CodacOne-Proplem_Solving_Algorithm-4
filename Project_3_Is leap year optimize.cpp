#include <iostream>
#include <ctime>
#include <string>


using namespace std;


// check is year leap or not leap by line code
int EnterYear()
{
	int Year = 0;
	cout << "Enter The year to check please ?\n";
	cin >> Year;
	return Year;

}



bool CheckIsLeapYear(int Year)
{


	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

int main()

{

	int Year = EnterYear();

	if (CheckIsLeapYear(Year))
	{

		cout << "Yes,Year [ " << Year << "] is a leap year\n";
	}

	else
	{
		cout << "No,Year [ " << Year << "] is Not a leap year\n";
	}

	system("pause>0");
	return 0;

}