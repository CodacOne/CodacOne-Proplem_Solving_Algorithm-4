#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;

};

bool CheckIsLeapYear(short Year)
{

	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month)
		? ((Date1.Day == Date2.Day) ? true : false) : false) : false;

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

int GetDiffrenceInDays(stDate Date1, stDate Date2, bool EndDay=0)
{

	short Days = 0;

	while (!IsDate1EqualDate2(Date1, Date2))
	{

		Days++;
		Date1=IncreaseDateByOneDay(Date1);

	}


	return (EndDay) ? ++Days : Days ;
}

int ReadYear()
{
	int year = 0;
	cout << "Enter a year please? ";
	cin >> year;
	return year;
}

int ReadMonth()
{
	int Month = 0;
	cout << "Enter a Month please? ";
	cin >> Month;
	return Month;
}

int ReadDay()
{
	int Day = 0;
	cout << "Enter a Day please? ";
	cin >> Day;
	return Day;
}


stDate EnterDate(stDate Date)
{
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}


int main()
{

	stDate Date1;
	stDate Date2;


	cout << "Enter a  Period 1 \n";
	cout << "Enter start Date : \n ";

	Date1 = EnterDate(Date1);

	cout << "\n\nEnter End Date :  \n ";
	Date2 = EnterDate(Date1);

    cout << "\nPeriod Length is  : \n"<< GetDiffrenceInDays(Date1, Date2);
	cout << "\nPeriod Length (Including end Date) is : \n"<< GetDiffrenceInDays(Date1, Date2,1);

	system("pause>0");
	return 0;

}