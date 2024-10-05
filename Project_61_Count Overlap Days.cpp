#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum enDateCompare { Beore = -1, Equal = 0, After = 1 };

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;

};

struct stPeriod
{

	stDate EndDate;
	stDate startDate;

};

// Methode 1 My plane

/*
bool IsDateEndPeriod1BeforeDateStartPeriod2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}


bool IsDateEndPeriod2BeforeDateStartPeriod1(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
*/

// Methode 2 
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month)
		? ((Date1.Day == Date2.Day) ? true : false) : false) : false;

}


bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{


	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

}

int ReadYear()
{
	int year = 0;
	cout << "Enter a year please?";
	cin >> year;
	return year;
}

int ReadMonth()
{
	int Month = 0;
	cout << "Enter a Month please?";
	cin >> Month;
	return Month;
}

int ReadDay()
{
	int Day = 0;
	cout << "Enter a Day please?";
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

//  methode 1 
/*
bool IsPeriodeOverlap(stPeriod Period1, stPeriod Period2)
{

	if (IsDateEndPeriod1BeforeDateStartPeriod2(Period2.EndDate, Period1.startDate)
		|| IsDateEndPeriod2BeforeDateStartPeriod1(Period2.EndDate, Period1.startDate))
	{

		return false;
	}

	else
	{

		return true;
	}

}
*/


// methode 2

enDateCompare DateCompare(stDate Period1, stDate Period2)
{
	if (IsDate1BeforeDate2(Period1, Period2))
	{
		return enDateCompare::Beore;
	}

	if (IsDate1EqualDate2(Period1, Period2))
	{
		return enDateCompare::Equal;
	}

	return enDateCompare::After;
}

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

bool IsPeriodOverlap(stPeriod Period1, stPeriod Period2)
{
	if (DateCompare(Period2.EndDate, Period1.startDate) == enDateCompare::Beore ||
		DateCompare(Period1.EndDate, Period2.startDate) == enDateCompare::Beore)
	{
		return false;
	}
	else
	{
		return true;
	}
}


int OverlapDaysCount(stPeriod Period1, stPeriod Period2)
{
	short Counter = 0;

	if (!IsPeriodOverlap(Period1, Period2))
	{
		return 0;
	}


	if (IsDate1BeforeDate2(Period2.startDate, Period1.EndDate))
	{
		while (IsPeriodOverlap(Period1, Period2))
		{

			Period2.startDate = IncreaseDateByOneDay(Period2.startDate);
			Counter++;

		}

	}

	else
	{
		while (IsPeriodOverlap(Period2, Period1))
		{

			Period1.startDate = IncreaseDateByOneDay(Period1.startDate);
			Counter++;

		}
	}


	return Counter++;
}

int main()
{

	stDate Date1;
	stDate Date2;

	stPeriod Period1;
	stPeriod Period2;
	//////////////////////////////////////
	cout << "\n Enter a  Period 1 \n ";
	cout << " Enter start Date  \n ";

	Period1.startDate = EnterDate(Date1);
	cout << " Enter End Date  \n ";
	Period1.EndDate = EnterDate(Date1);

	//////////////////////////////////////

	cout << "\n Enter a  Period 2 \n ";
	cout << " Enter start Date  \n ";

	Period2.startDate = EnterDate(Date2);

	cout << " Enter End Date  \n ";
	Period2.EndDate = EnterDate(Date2);
	//////////////////////////////////////

	cout<<" Overlap Days Count is : \n"<<OverlapDaysCount(Period1, Period2);
	

	system("pause>0");
	return 0;

}