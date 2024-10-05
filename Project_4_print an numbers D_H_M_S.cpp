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



bool CheckIsLeapYear(short Year)
{


	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

short NumberDayOfYear(short Year)
{

	return CheckIsLeapYear(Year) ? 366 : 365;

}


short NumberHoursOfYear(short Year)
{

	return NumberDayOfYear(Year) * 24;

}

int NumberMinuteOfYear(short Year)
{

	return NumberHoursOfYear(Year) * 60;

}


int NumberSecondeOfYear(short Year)
{

	return NumberMinuteOfYear(Year) * 60;

}

int main()

{

	int Year = EnterYear();

		cout << " Number of days  in Year ["<< Year<<"] is "<< NumberDayOfYear(Year);
		cout << "\nNumber of days  in Year [" << Year << "] is " << NumberHoursOfYear(Year);
		cout << " \nNumber of days  in Year [" << Year << "] is " << NumberMinuteOfYear(Year);
		cout << " \nNumber of days  in Year [" << Year << "] is " << NumberSecondeOfYear(Year);

	system("pause>0");
	return 0;

}