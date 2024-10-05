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

bool IsDate1_Equal_Date2(stDate Date1, stDate Date2)
{
	return Date1.Year == Date2.Year ? ((Date1.Month== Date2.Month)? Date1.Day== Date2.Day ? true: false :false ): false;


}



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






stDate EnterDate(stDate Date)
{
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}


short CalculateActualvacationDays(stDate Date1, stDate Date2)
{
	short CounterToActualvacationDays = 0;
	short Counter = 0;

	while (!IsDate1_Equal_Date2(Date1, Date2))
	{
		Counter++;
		Date1 = IncreaseDateByOneDay(Date1);

		if (DayOrderInWeek(Date1)==5 || DayOrderInWeek(Date1) == 6)
		{
			CounterToActualvacationDays++;
		}
		
	}
	
	return (Counter- CounterToActualvacationDays);
}

int main()
{
	stDate Date1;
	stDate Date2;

	cout << "\nVacation starts : \n";
	Date1 = EnterDate(Date1);
	cout << "\nVacation Ends : \n";
	Date2 = EnterDate(Date2);

	


	//--------------------------
	cout << "\n Vacation From : " << PrintDayOrder(Date1) << " , "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	cout << "\n Vacation To : " << PrintDayOrder(Date2) << " , "
		<< Date2.Day << "/" << Date2.Month << "/" << Date2.Year;


	cout << "\n Actual vacation Days is : " << CalculateActualvacationDays(Date1, Date2);


	system("pause>0");
	return 0;

}