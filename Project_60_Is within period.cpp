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
	stDate CheckDate;
	
};


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


bool IsWithinPeriod(stPeriod Period, stPeriod PeriodCheck)
{

	if ((DateCompare(Period.startDate, PeriodCheck.CheckDate) == enDateCompare::Beore)
		&& DateCompare(Period.EndDate, PeriodCheck.CheckDate) == enDateCompare::After)
	{

		return true;
	}

	else
	{

		return false;
	}

}

int main()
{

	stDate Date1;
	stDate Date2;

	stPeriod Period;
	stPeriod PeriodCheck;

	cout << "\nEnter a  Period  \n";
	cout << "Enter start Date  \n\n";

	Period.startDate = EnterDate(Date1);

	cout << "\n\nEnter End Date  \n\n";
	Period.EndDate = EnterDate(Date1);


	cout << "\n\nEnter Date to Check : \n\n";
	PeriodCheck.CheckDate = EnterDate(Date1);

	if (IsWithinPeriod(Period, PeriodCheck))
	{
		cout << " Yes , Date is within period ";
	}

	else
	{
		cout << " No , Date is Not within period ";

	}

	system("pause>0");
	return 0;

}