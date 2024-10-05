#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
	string OrderDayInWeek;
};

bool CheckIsLeapYear(short Year)
{

	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

short DayOrder(short month, short year, short Day)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;

	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
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

short DayOrderInWeek(stDate Date)
{

	return DayOrder(Date.Month, Date.Year, Date.Day);

}

/*
int NumberOfDays(short Day, short Month, short year)
{

	short RemanningDays = ShowNumberOfDaysInMonth(year, Month);
	RemanningDays = RemanningDays - Day;
	Month = Month + 1;
	int Number_OfDays = 0;

	for (int i = Month; i <= 12; i++)
	{

		Number_OfDays = Number_OfDays + ShowNumberOfDaysInMonth(year, i);

	}
	return (Number_OfDays + RemanningDays);
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


string PrintDayOrder(stDate Date)
{
	string arrOfDaysWeek[7] = { "sun","mon","tue","wed","thu","fri","sat" };
	return arrOfDaysWeek[DayOrderInWeek(Date)];
}



bool IsItWeekend(stDate Date)
{
	short Weekend = DayOrderInWeek(Date);
	return (Weekend == 5 || Weekend == 6);
}

bool IsItBuisnessDay(stDate Date)
{

	return !IsItWeekend(Date);
}
stDate EnterDate(stDate Date)
{

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}


stDate ReturnActualvacationDaysToDate(stDate Date, short Days)
{
	for (int i = 1; i <= Days; i++)
	{


		if (!IsItBuisnessDay(Date))
		{

			Days= Days+1;
		}


		Date = IncreaseDateByOneDay(Date);

	}


	return Date;
}

int main()
{
	stDate Date;


	short vacationsDays = 0;

	cout << "\nVacation starts : \n";
	Date = EnterDate(Date);

	//--------------------------
	cout << "\n Vacation From : " << PrintDayOrder(Date) << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;



	cout << "\n Please Enter vacations Days : ";
	cin >> vacationsDays;

	Date = ReturnActualvacationDaysToDate(Date, vacationsDays);
	cout << "\n Return Date : " << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}