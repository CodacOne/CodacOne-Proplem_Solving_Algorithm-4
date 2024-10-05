#include <iostream>
#include <ctime>
#include <string>

using namespace std;


struct stDate
{
	short Year=0;
	short Month=0;
	short Day=0;

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

/*
int ShowNumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
	{
		return 0;
	}


	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckIsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1];


}*/


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


	cout << "\n Enter a  Date1 \n ";
	Date1= EnterDate(Date1);

	cout << "\n Enter a  Date2 \n ";
	Date2= EnterDate(Date2);



	//--------------------------
	if (IsDate1AfterDate2(Date1, Date2))
	{

		cout << "\n Yes Date1 is After Date2 \n";

	}

	else
	{
		cout << "\n No Date1 is Not After Date2  \n";

	}

	


	system("pause>0");
	return 0;

}