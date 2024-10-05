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


bool ChcekDayLastDayInMonth(stDate Date)
{

	return ( Date.Day ==ShowNumberOfDaysInMonth(Date.Year, Date.Month));

}




int main()
{
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	
	if (ChcekDayLastDayInMonth(Date))
	{

		cout << "Yes, Day is last day in month \n";


	}

	else
	{
		cout << "No, Day is Not last day in month \n";

	}

	if (Date.Month==12)
	{

		cout << "Yes, month is last month in year \n";


	}
	

	else
	{
		cout << "No, month is Not last month in year \n";

	}


		
	system("pause>0");
	return 0;

}