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

int NumberOfDays(short Day, short Month, short year)
{ 

	short RemanningDays=ShowNumberOfDaysInMonth(year, Month);
	RemanningDays = RemanningDays - Day;
	Month = Month + 1;
	int Number_OfDays = 0;

	for (int i = Month; i <=12; i++)
	{

		Number_OfDays = Number_OfDays + ShowNumberOfDaysInMonth(year, i);

	}
	return (Number_OfDays + RemanningDays);
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


string PrintDayOrder(stDate Date)
{  
	string arrOfDaysWeek[7] = { "sun","mon","tue","wed","thu","fri","sat"};
 return arrOfDaysWeek[ DayOrder(Date.Month, Date.Year, Date.Day)];
}

bool IsEndOfWeek(stDate Date)
{

	return DayOrderInWeek(Date) ==6;
}

bool IsItWeekend(stDate Date)
{ 
	short Weekend = DayOrderInWeek(Date);
	return (Weekend == 5 || Weekend == 6);
}



short DaysUntilEndWeek(stDate Date)
{
	
	return 6 - DayOrderInWeek(Date);
}


short DaysUntilEndMonth(stDate Date)
{
	short NumberOfDaysInMonth =ShowNumberOfDaysInMonth(Date.Year, Date.Month);
	short Counter = 0;
	for (int i = Date.Day ; i <= NumberOfDaysInMonth; i++)
	{
		Counter++;

	}

	return Counter;
}


short DaysUntilEndYear(stDate Date)
{

	return (NumberOfDays(Date.Day, Date.Month, Date.Year));


}


int main()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	Date.OrderDayInWeek = PrintDayOrder(Date);


	//--------------------------
	cout << "\nToday is " << Date.OrderDayInWeek << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	//--------------------------
	cout << "\n\nIs It End of Week ? \n";

	if (IsEndOfWeek(Date))
	{
		cout << "Yes ,It Is  End of Week  ? \n";
	}
	else
	{
		cout << "No ,It Is Not End of Week   \n";
	}

	//--------------------------

	cout << "\nIs It WeekEnd ? \n";

	if (IsItWeekend(Date))
	{
		cout << "Yes ,It Is a Week End ? \n";
	}
	else
	{
		cout << "No ,It Is Not a Week End  \n";
	}

	
	//--------------------------


	cout << "\nIs It Business Day? \n";

	if (!IsItWeekend(Date))
	{
		cout << "Yes ,It Is  Business Day ? \n";
	}
	else
	{
		cout << "No ,It Is Not  Business Day  \n";
	}

	//--------------------------


	cout << "\n Days Until end of Week  : "<< DaysUntilEndWeek(Date) << " Day(s)\n";

    cout << "\n Days Until end of Month : " << DaysUntilEndMonth(Date) << " Day(s)\n";

	cout << "\n Days Until end of Year  : " << DaysUntilEndYear(Date) << " Day(s)\n";


	system("pause>0");
	return 0;

}