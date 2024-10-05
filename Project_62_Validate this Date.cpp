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


stDate EnterDate(stDate Date)
{

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool ValidateThisDate(stDate Date)
{
	if (Date.Month >= 1  &&  Date.Month <= 12)
	{
		if (Date.Day <= ShowNumberOfDaysInMonth(Date.Year, Date.Month) && Date.Day > 0 )
		{

			return true;
		}


	}

	return false;

}

int main()
{
	stDate Date;
	cout << "\nVacation starts : \n";
	Date = EnterDate(Date);


	if (ValidateThisDate(Date))
	{

		cout << "\nYes Date is validte  Date . \n";
	}

	else
	{

		cout << "\nNo Date is Not validte  Date . \n";
	}


	system("pause>0");
	return 0;

}