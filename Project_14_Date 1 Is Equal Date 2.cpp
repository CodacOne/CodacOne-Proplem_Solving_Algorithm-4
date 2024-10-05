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





bool ChcekIfDate1LessThanDate2(stDate Date1, stDate Date2)
{

	return (Date1.Year == Date2.Year) ?
		((Date1.Month== Date2.Month)?  
		((Date1.Day== Date2.Day)?true :false)  :false): false;

		
}

int main()
{
	stDate Date1;
	stDate Date2;
	Date1.Day = ReadDay();
	Date1.Month = ReadMonth();
	Date1.Year = ReadYear();

	Date2.Day = ReadDay();
	Date2.Month = ReadMonth();
	Date2.Year = ReadYear();



	if (ChcekIfDate1LessThanDate2(Date1, Date2))
	{
		cout << "Yes Date 1 is Equal to Date2 \n";
	}

	else
		cout << "No Date 1 is Not Equal to Date2 \n";

	system("pause>0");
	return 0;

}