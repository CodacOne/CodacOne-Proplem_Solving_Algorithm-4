#include <iostream>
#include <ctime>
#include <string>


using namespace std;
int ShowNumberOfDaysInMonth(short Year, short Month);

// print  day name of week 

int ReadYear()
{
	int year = 0;
	cout << "Enter a year please?" << endl;
	cin >> year;
	return year;
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

string MonthName(short NumberMonth)
{
	string arrDayName[12] = { "Jan","Feb","Mar","Apr"
				  ,"May","Jun","Jul","Aug","Sep","Oct","Nov","Dec", };

	return arrDayName[NumberMonth - 1];

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

string DayName(short DayOrder)
{
	string arrDayName[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	return arrDayName[DayOrder];

}

void printMonthCalender(short Month, short Year)
{
	short Day = 1;
	short Day_Order = DayOrder(Month, Year, 1);
	short NumberOfDaysInMonth = ShowNumberOfDaysInMonth(Year, Month);

	printf(" ______________ %s_______________\n\n", MonthName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");

	int i;
	for (i = 0; i < Day_Order; i++)

		printf("     ");


	for (int j = 1; j <= NumberOfDaysInMonth; j++)
	{
		printf("%5d", j);
		if (++i == 7)
		{
			printf("\n");
			i = 0;

		}
	}
	printf("\n  _________________________________\n");


}


void printYearCalender(short Year)
{

	printf("\n  _________________________________\n\n");
	printf("          Calender %d ", Year);
	printf("\n  _________________________________\n\n");


	for (int i = 1; i <= 12; i++)
	{

		printMonthCalender(i, Year);

	}
	cout << endl;
}


int main()
{
	short Year = ReadYear();
	

	printYearCalender(Year);


	system("pause>0");
	return 0;

}