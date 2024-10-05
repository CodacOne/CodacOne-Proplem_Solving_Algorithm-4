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


stDate DecreaseDateByOneDay(stDate Date)
{
	
	if (Date.Day==1   )
	{
		  if (Date.Month == 1)
		  {
			Date.Day = 31;
			Date.Year = Date.Year - 1;
			Date.Month = 12;
			return Date;
		  }
		
		 else	{
			Date.Month = Date.Month - 1;
			Date.Day = ShowNumberOfDaysInMonth(Date.Year, Date.Month);
			return Date;
		       }



	}

	
	else
	{
		Date.Day--;
		return Date;
	}


}

stDate DecreaseDateByXDays(stDate Date, int NumberOfDaysADD)
{
	for (int i = 1; i <= NumberOfDaysADD; i++)
	{

		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date, int NumberOfWeek)
{
	for (int i = 1; i <= NumberOfWeek; i++)
	{

		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}


stDate DecreaseDateByXWeek(stDate Date, int NumberOfWeek)
{
	for (int i = 1; i <= NumberOfWeek; i++)
	{

		Date = DecreaseDateByOneWeek(Date,7);
	}
	return Date;
}


stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month= 12;
		Date.Year--;
	}

	else
	{
		Date.Month--;

	}
	short NumberOfDaysInMonth = ShowNumberOfDaysInMonth(Date.Year, Date.Month);

	if (NumberOfDaysInMonth < Date.Day)
	{
		Date.Day = NumberOfDaysInMonth;

	}


	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short Months)
{
	for (int i = 1; i <= Months; i++)
	{

		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	if (CheckIsLeapYear(Date.Year))
	{

		short NumberOfDaysInMonth = ShowNumberOfDaysInMonth(Date.Year, Date.Month);
		//Date.Day = NumberOfDaysInMonth;
		Date.Year--;
	}

	else
	{
		Date.Year--;

	}
	return Date;
}

stDate DecreaseDateByXYears(stDate Date, short Years)
{
	for (int i = 1; i <= Years; i++)
	{

		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short Years)
{
	Date.Year = Date.Year - Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year = Date.Year - 10;
	return Date;
}

stDate DecreaseDateByXDecade(stDate Date, short Decades)
{
	for (int i = 1; i <= Decades; i++)
	{

		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date, short Decades)
{
	Date.Year = Date.Year - 100;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year = Date.Year - 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year = Date.Year - 1000;
	return Date;
}


int main()
{
	stDate Date;

	short Day = 1;
	short Week = 7 * Day;


	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();


	

	Date = DecreaseDateByOneDay(Date);
	cout << "\n 01- Subtracting One Day is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	 Date = DecreaseDateByXDays(Date, 10);
	cout << " 02- Subtracting 10 Day is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = DecreaseDateByOneWeek(Date, Week);
	cout << " 03- Subtracting One Week is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = DecreaseDateByXWeek(Date, 10 );
	cout << " 04- Subtracting 10 Week is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = DecreaseDateByOneMonth(Date);
	cout << " 05- Subtracting One Month is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = DecreaseDateByXMonths(Date, 5);
	cout << " 06- Subtracting  5 Months is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;
	
	Date = DecreaseDateByOneYear(Date);
	cout << " 07- Subtracting  One year is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

	
	Date = DecreaseDateByXYears(Date, 10);
	cout << " 08- Subtracting  10 years is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	
	Date = DecreaseDateByXYearsFaster(Date, 10);
	cout << " 09- Subtracting  10 years (faster) is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = DecreaseDateByOneDecade(Date);
	cout << " 10- Subtracting  One Decade is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = DecreaseDateByXDecade(Date, 10);
	cout << " 11- Subtracting 10 Decades is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = DecreaseDateByXDecadeFaster(Date, 10);
	cout << " 12- Subtracting  10 Decades (faster) is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;



	Date = DecreaseDateByOneCentury(Date);
	cout << " 13- Subtracting  One Century is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;


	Date = DecreaseDateByOneMillennium(Date);
	cout << " 14- Subtracting  One Century is : " << Date.Day << "/" << Date.Month <<
		"/" << Date.Year << endl;

		

	system("pause>0");
	return 0;

}