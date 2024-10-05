#include <iostream>
#include <ctime>
#include <string>
#include <vector>


using namespace std;

struct stDate
{
	int Year;
	int Month;
	int Day;
	
};



string ReadString()
{
	string S1;
	cout << "Enter Your string pls :" << endl;
	getline(cin, S1);
	return S1;

}


vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	string sWord = " ";
	short pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{

		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")

	{
		vString.push_back(S1);
	}

	return vString;

}


stDate StringToDate(string Datestring)
{
	vector <string> vDate;
	stDate Date;

	vDate=SplitString(Datestring, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year= stoi(vDate[2]);

	return Date;
}

string DateToString(stDate Date)
{
	string Delim = "/";

	return to_string(Date.Day) + Delim + to_string(Date.Month) + Delim + to_string(Date.Year);

}
int main()
{
	stDate Date;
	vector <string> vString;


	string Datestring=ReadString();

	Date =StringToDate(Datestring);
	
	cout << "\n Day : " << Date.Day ;
	cout << "\n Month : " << Date.Month ;
	cout << "\n Year : " << Date.Year ;

	cout << "\nYou intered : " << DateToString(Date);

		



	system("pause>0");
	return 0;

}