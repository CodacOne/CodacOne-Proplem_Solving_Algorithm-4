#include <iostream>
#include <ctime>
#include <string>


using namespace std;
int SNumberOfDaysInMonth(short Year, short Month);

// print number of days and hors and minute and seconde in month

int EnterNumberOFyearAndMonth(string text)
{
	int number = 0;
	cout << text<<endl;
	cin >> number;
	return number;

}



bool CheckIsLeapYear(short Year)
{


	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

short NumberDayInMonth(short Year, short Month)
{

	return SNumberOfDaysInMonth(Year, Month) ;

}


short NumberHoursOfMonth(short Year, short Month)
{

	return NumberDayInMonth(Year, Month) * 24;

}

int NumberMinuteOfMonth(short Year, short Month)
{

	return NumberHoursOfMonth(Year, Month) * 60;

}


int NumberSecondeOfMonth(short Year, short Month)
{

	return NumberMinuteOfMonth(Year, Month) * 60;

}

int SNumberOfDaysInMonth(short Year, short Month)
{
	if(Month > 12 || Month< 1)
	{ 
		return 0;
	}

	if (Month == 2)
	{
		return CheckIsLeapYear(Year) ? 29 : 28;
	}

	short arrDays[7] = {1,3,5,7,8,10,12};

	for (int i = 1; i <= 7; i++)
	{
		if (arrDays[i - 1] == Month)
	
			return 31;
	}

	return 30;
}

int main()
{
	int Year = EnterNumberOFyearAndMonth("Enter the Year,pls");
	int Month = EnterNumberOFyearAndMonth("Enter the Month,pls");


	cout << "Number of days  in Month [" << Month << "] is " <<
		NumberDayInMonth(Year, Month);

	cout << "\nNumber of days  in Month [" << Month << "] is " <<
		NumberHoursOfMonth(Year, Month);

	cout << " \nNumber of days  in Month [" << Month << "] is " <<
		NumberMinuteOfMonth(Year, Month);

	cout << " \nNumber of days  in Month [" << Month << "] is " << 
		NumberSecondeOfMonth(Year, Month);


	system("pause>0");
	return 0;

}