#include <iostream>
#include <ctime>
#include <string>

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

void SwapDates(stDate &Date1, stDate &Date2)
{

	stDate TempDates;

	TempDates = Date1;
	Date1 = Date2;
	Date2 = TempDates;

}

int CalculateDifferenceINDays(stDate Date1, stDate Date2, bool EndDay = 0)
{
	int Days = 0;
	short SwapFlagValue = 1;

	if (!(ChcekIfDate1LessThanDate2(Date1, Date2)))
	{

		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while((ChcekIfDate1LessThanDate2(Date1, Date2)))
	{

		Days++;
			Date1 = IncreaseDateByOneDay(Date1);

	}
	
	  
	return EndDay ? ++Days* SwapFlagValue : Days* SwapFlagValue;
}


int main()
{
	stDate Date1;
	stDate Date2;

	int Difference1 = 0;
	int Difference2 = 0;

	Date1.Day = ReadDay();
	Date1.Month = ReadMonth();
	Date1.Year = ReadYear();


	Date2.Day = ReadDay();
	Date2.Month = ReadMonth();
	Date2.Year = ReadYear();




	cout << " Difference is : " << CalculateDifferenceINDays(Date1, Date2) << " Day(s)\n";
	cout << " Difference (Including End Day) is : " << CalculateDifferenceINDays(Date1, Date2, 1) <<
		" Day(s)\n\n";

	system("pause>0");
	return 0;

}