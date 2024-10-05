#include <iostream>
#include <ctime>
#include <string>


using namespace std;
int ShowNumberOfDaysInMonth(short Year, short Month);


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


int ShowNumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
	{
		return 0;
	}


	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckIsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1];


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


int NumberOfDays(short Day, short Month, short year)
{
	int Number_OfDays = 0;
	for (int i = 1; i < Month; i++)
	{

		Number_OfDays = Number_OfDays + ShowNumberOfDaysInMonth(year, i);

	}
	return (Number_OfDays + Day);
}


stDate  ConvertToDate(short year, short Month, short NumberDays)
{
	stDate Date;
	short NumberOfDaysInMonth = 0;
	short RemainingDays = NumberDays;

	Date.Month = 1;
	Date.Year = year;

	while (true)
	{
		NumberOfDaysInMonth = ShowNumberOfDaysInMonth(year, Date.Month);

		if (RemainingDays > NumberOfDaysInMonth)
		{

			RemainingDays -= NumberOfDaysInMonth;
			Date.Month++;

		}

		else
		{

			Date.Day = RemainingDays;
			break;
		}
	}


	return Date;
}


/*   Methode 2
void ConvertTotalDaysFromTheBeginingOfYheYeartoDate(short year, short NumberOfDays)
{

	int Number_OfDays = 0;
	int i;
	int NumberOfMonth = 1;
	for ( i = 1; i <= 12; i++)
	{
		if (NumberOfDays > 31)
		{

			NumberOfDays = NumberOfDays - ShowNumberOfDaysInMonth(year, i);
			NumberOfMonth++;

		}

	}
	cout << NumberOfDays << "/" << NumberOfMonth << "/" << year << endl;
}*/


int main()
{
	stDate Date;
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	int NumberOfDaysFromTheBegningOfYear = NumberOfDays(Day, Month, Year);


	cout << "\n Number of Days from the begining of the year is : " <<
		NumberOfDaysFromTheBegningOfYear;


	/*	cout << "\n Date for [" << NumberOfDaysFromTheBegningOfYear << "] is :";
	ConvertTotalDaysFromTheBeginingOfYheYeartoDate(Year, NumberOfDaysFromTheBegningOfYear);*/

	Date = ConvertToDate(Year, Month, NumberOfDaysFromTheBegningOfYear);
	cout << "\n Date for [" << NumberOfDaysFromTheBegningOfYear << "] is :" <<
		Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


	system("pause>0");
	return 0;

}