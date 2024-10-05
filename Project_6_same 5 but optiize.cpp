#include <iostream>
#include <ctime>
#include <string>


using namespace std;
int ShowNumberOfDaysInMonth(short Year, short Month);

// print number of days and hors and minute and seconde in month but optimize

int EnterNumberOFyearAndMonth(string text)
{
	int number = 0;
	cout << text << endl;
	cin >> number;
	return number;

}



bool CheckIsLeapYear(short Year)
{

	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

int ShowNumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
	{
		return 0;
	}


	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

	return (Month == 2) ? (CheckIsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1];

	
}

int main()
{
	int Year = EnterNumberOFyearAndMonth("Enter the Year,pls");
	int Month = EnterNumberOFyearAndMonth("Enter the Month,pls");


	cout << "Number of days  in Month [" << Month << "] is : " <<
		ShowNumberOfDaysInMonth( Year,Month);
		


	system("pause>0");
	return 0;

}