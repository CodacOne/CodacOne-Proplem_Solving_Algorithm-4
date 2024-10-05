#include <iostream>
#include <ctime>
#include <string>


using namespace std;
int ShowNumberOfDaysInMonth(short Year, short Month);


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


int ShowNumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
	{
		return 0;
	}


	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (CheckIsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1];


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


stDate DateAfterAdding(short Day, short Month, short year, short DaysAdd)
{
	stDate Date;
	short RemainningDays = DaysAdd;
	short NumberOfDaysInEveryMonth = 0;
	

	Date.Month = Month;
	Date.Year = year;
	Date.Day = Day;

	while (true)
	{
	NumberOfDaysInEveryMonth =ShowNumberOfDaysInMonth(Date.Year, Date.Month);

		if (RemainningDays >= NumberOfDaysInEveryMonth)
		{
			if (Date.Month > 12)
			{
				Date.Month = 0;
				Date.Year++;

		     }
			Date.Month++;
			RemainningDays = RemainningDays - NumberOfDaysInEveryMonth+ Date.Day;
			Date.Day = 0;
		}

		else
		{

			Date.Day = RemainningDays;
			break;
		}


	}

	return Date;
}

int main()
{
	stDate Date;
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysAdd = 0;


	cout << "How many days to add \n?";
	cin >> DaysAdd;

	Date=DateAfterAdding(Day, Month, Year, DaysAdd);

	cout << "Date after adding [" << DaysAdd << "] Days is :" << Date.Day << "/" << Date.Month << "/"
		<< Date.Year;


	system("pause>0");
	return 0;

}