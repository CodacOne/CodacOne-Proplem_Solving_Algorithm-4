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

short DayOrder(short month, short year, short Day)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;

	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}


string DayName(short DayOrder)
{
	string arrDayName[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	return arrDayName[DayOrder];

}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\n Date       : " << Day << "/" << Month << "/" << Year << endl;
	cout << "\n Day Order  : " << DayOrder(Month, Year, Day);
	cout << "\n Day Order  : " << DayName(DayOrder(Month, Year, Day));

	system("pause>0");
	return 0;

}