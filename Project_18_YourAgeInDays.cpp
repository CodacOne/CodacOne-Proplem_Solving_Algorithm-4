

#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;

};
bool CheckIsLeapYear(short Year)
{

	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}


int ReadYear()
{
	int year = 0;
	cout << "Enter a year please?" << endl;
	cin >> year;
	return year;
}

int ReadMonth()
{
	int Month = 0;
	cout << "Enter a Month please?" << endl;
	cin >> Month;
	return Month;
}

int ReadDay()
{
	int Day = 0;
	cout << "Enter a Day please?" << endl;
	cin >> Day;
	return Day;
}



int ShowNumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
	{
		return 0;
	}


	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckIsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1];


}


bool ChcekIfDate1LessThanDate2(stDate Date1, stDate Date2)
{

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year)
		? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month
			? Date1.Day < Date2.Day : false)) : false);
}


int NumberOfDays(short Day, short Month, short year)
{
	int Number_OfDays = 0;
	for (int i = 1; i < Month; i++)
	{

		Number_OfDays = Number_OfDays + ShowNumberOfDaysInMonth(year, i);

	}
	return (Number_OfDays + Day);
}



stDate IncreaseDateByOneDay(stDate Date)
{

	if (Date.Day == ShowNumberOfDaysInMonth(Date.Year, Date.Month) && Date.Month == 12)
	{
		Date.Month = 1;
		Date.Day = 1;
		Date.Year++;
		return Date;
	}

	if (Date.Day == ShowNumberOfDaysInMonth(Date.Year, Date.Month))
	{
		Date.Month++;
		Date.Day = 1;
		return Date;
	}

	else
	{
		Date.Day++;
		return Date;
	}


}


int CalculateDifferenceINDays(stDate Date1, stDate Date2, bool EndDay = 0)
{
	int Days = 0;
	while (ChcekIfDate1LessThanDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);


	}
	return EndDay ? ++Days : Days;
}

stDate GetSystemDate() 
{ 
	 stDate Date;
	 time_t t = time(0); 
	 tm* now = localtime(&t);
     Date.Year = now->tm_year + 1900;
	 Date.Month = now->tm_mon + 1;
     Date.Day = now->tm_mday;
	 return Date;
}

int main()
{
	stDate Date1;
	stDate Date2;

	
	cout << "Please Enter your Date of Birth \n";

	Date1.Day = ReadDay();
	Date1.Month = ReadMonth();
	Date1.Year = ReadYear();

	Date2 = GetSystemDate();

	cout << " Your Age is : " << CalculateDifferenceINDays(Date1, Date2, 1) <<
		" Day(s)\n\n";

	system("pause>0");
	return 0;

}