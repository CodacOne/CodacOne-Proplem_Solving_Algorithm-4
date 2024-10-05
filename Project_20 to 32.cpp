#include <iostream>
#include <ctime>
#include <string>
#include "MyDateLibraryr.h"
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


/*
int NumberOfDays(short Day, short Month, short year)
{
	int Number_OfDays = 0;
	for (int i = 1; i < Month; i++)
	{

		Number_OfDays = Number_OfDays + ShowNumberOfDaysInMonth(year, i);

	}
	return (Number_OfDays + Day);
}
*/


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

stDate IncreaseDateByXDays(stDate Date, int NumberOfDaysADD)
{
	for (int i = 1; i <=NumberOfDaysADD; i++)
	{

		Date=IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date, int NumberOfWeek)
{
	for (int i = 1; i <= NumberOfWeek; i++)
	{

		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}


stDate IncreaseDateByXWeek(stDate Date, int NumberOfWeek)
{
	for (int i = 1; i <= NumberOfWeek; i++)
	{

		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
   

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}

	else
	{
		Date.Month++;

	}
	short NumberOfDaysInMonth = ShowNumberOfDaysInMonth(Date.Year, Date.Month);

	if (NumberOfDaysInMonth < Date.Day)
	{
		Date.Day = NumberOfDaysInMonth;

	}


	return Date;
}

stDate IncreaseDateByXMonths(stDate Date,short Months)
{
	for (int i = 1; i <= Months; i++)
	{

		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	if (CheckIsLeapYear(Date.Year))
	{

		short NumberOfDaysInMonth = ShowNumberOfDaysInMonth(Date.Year, Date.Month);
		//Date.Day = NumberOfDaysInMonth;
		Date.Year++;
	}

	else
	{
		Date.Year++;

	}
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short Years)
{
	for (int i = 1; i <= Years; i++)
	{

		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short Years)
{
	Date.Year = Date.Year + Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year = Date.Year +10;
	return Date;
}

stDate IncreaseDateByXDecade(stDate Date, short Decades)
{
	for (int i = 1; i <= Decades; i++)
	{

		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, short Decades)
{
	Date.Year = Date.Year + 100;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year = Date.Year + 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year = Date.Year + 1000;
	return Date;
}


int main()
{
	stDate Date;

	short Day = 1;
	short Week = 7* Day;
	

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	// include first library
	MyLibDate::First();

	Date = IncreaseDateByOneDay(Date);
	cout << "\n 01- Adding One Day is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;
	
	Date = IncreaseDateByXDays(Date,10);
	cout << " 02- Adding 10 Day is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

    
	Date = IncreaseDateByOneWeek(Date, Week);
	cout << " 03- Adding One Week is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = IncreaseDateByXWeek(Date,10*Week);
	cout << " 04- Adding 10 Week is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = IncreaseDateByOneMonth(Date);
	cout << " 05- Adding One Month is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = IncreaseDateByXMonths(Date,5);
	cout << " 06- Adding  5 Months is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	Date = IncreaseDateByOneYear(Date);
	cout << " 07- Adding  One year is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = IncreaseDateByXYears(Date,10);
	cout << " 08- Adding  10 years is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;



	Date = IncreaseDateByXYearsFaster(Date, 10);
	cout << " 09- Adding  10 years (faster) is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = IncreaseDateByOneDecade(Date);
	cout << " 10- Adding  One Decade is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = IncreaseDateByXDecade(Date,10);
	cout << " 11- Adding 10 Decades is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = IncreaseDateByXDecadeFaster(Date, 10);
	cout << " 12- Adding  10 Decades (faster) is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;



	Date = IncreaseDateByOneCentury(Date);
	cout << " 13- Adding  One Century is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = IncreaseDateByOneMillennium(Date);
	cout << " 14- Adding  One Century is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;
	
	/*	*/

	system("pause>0");
	return 0;

}