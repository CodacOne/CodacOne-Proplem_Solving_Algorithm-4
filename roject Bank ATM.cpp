#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void Login();
void ShowLoginScreen();
void ShowBalanceScreeen();
void OptionMainMenuScreen();
void  CheckBalance();
void GoBackToMainMenu();
void ShoQiuckWithDrawScreeen();
void ShoNormalWithDrawScreeen();
void ShowDepositeScreeen();


const string FileClientdata = "Clientdata.txt";

struct stClientdata
{
	string AccountNumber;
	string Name;
	string PinCode;
	string Phone;
	double AcoountBalance;
	bool DeleteMark = false;

};

enum enOptionAtm
{
	eQuickWithdraw=1,eNormalWithdraw=2  ,eDeposit=3,
	eCheckBalance=4  ,eLogout=5 

};
stClientdata CurrentUser;

int ReadNumberChioce()
{

	short NumberDoYouWant = 0;
	while (NumberDoYouWant <1 ||  NumberDoYouWant>5)
	{
		cout << "Chose what do you want to do? [1 to 5]?\n";
		cin >> NumberDoYouWant;
	}
	
	return NumberDoYouWant;
}

int ReadAmountNormalWithDraw()
{
	int amount = 0;
	do
	{
		cout << "Enter an amount multiple of 5's ?";
		cin >> amount;
		
	} while (amount % 5 != 0);


	return amount;
}
int ReadDepositeNumber()
{
	int Depositeamount = 0;
	cout << "Enter a positive Deposite amount ?";
	cin >> Depositeamount;

	while (Depositeamount <=0)
	{

		cout << "Enter a positive Deposite amount ?";
		cin >> Depositeamount;

	}
	
	return Depositeamount;
}
short ReadChioceWithDrawQuick()
{

	short NumberDoYouWant = 0;
	while (NumberDoYouWant < 1 || NumberDoYouWant>9)
	{
		cout << "Chose what do you want to do? [1 to 9]?\n";
		cin >> NumberDoYouWant;
	}
	return NumberDoYouWant;
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

stClientdata ConvertLinetoRecord(string line, string Delim = "#//#")
{
	vector<string> vClinteData;
	stClientdata sClientdata;

	vClinteData = SplitString(line, Delim);

	sClientdata.AccountNumber = vClinteData[0];
	sClientdata.Name = vClinteData[1];
	sClientdata.PinCode = vClinteData[2];
	sClientdata.Phone = vClinteData[3];
	sClientdata.AcoountBalance = stod(vClinteData[4]); // casting string to double

	return sClientdata;
}

vector <stClientdata> LoadClientDataFromFile(string FileClientdata)
{

	fstream MyData;
	stClientdata Client;
	vector <stClientdata> Clientdata;

	string line = "";

	MyData.open(FileClientdata, ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{

			Client = ConvertLinetoRecord(line);
			Clientdata.push_back(Client);

		}

		return Clientdata;
	}

}

string ConvertClientRecordToLine(stClientdata Clientdata)
{
	string Delim = "#//#";
	string line = "";
	line = line + Clientdata.AccountNumber + Delim;
	line = line + Clientdata.Name + Delim;
	line = line + Clientdata.PinCode + Delim;
	line = line + Clientdata.Phone + Delim;
	line = line + to_string(Clientdata.AcoountBalance) + Delim;

	return line;
}

vector <stClientdata> SaveClientDataToFileAfterUpdate(vector <stClientdata> vClientdata)
{
	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(FileClientdata, ios::out);


	if (MyFile.is_open())
	{


		for (stClientdata Line : vClientdata)
		{

			DataFileNew = ConvertClientRecordToLine(Line);
			MyFile << DataFileNew << endl;

		}


		MyFile.close();
	}


	return vClientdata;
}

bool FindUserByUsernameAndPasswordNew(string AccountNumber, string Pinode, stClientdata &user)
{
	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(FileClientdata);

	for (stClientdata U : vClientdata)
	{
		if (U.AccountNumber == AccountNumber && U.PinCode == Pinode)
		{
			user = U;
			return true;
		}

	}
	return false;
}

bool LOadUserInfo(string UserName, string Password)
{

	if (FindUserByUsernameAndPasswordNew(UserName, Password, CurrentUser))
	{
		return 	true;
	}

	else
		return false;
}

short PerformanceWithDrawQuick(short NumberOfChoice)
{
	switch (NumberOfChoice)
{
	case   1:
	{
		
		return  20;
	}

	case   2:
	{
		
		return  50;
	}

	case  3:
	{
		
		return  100;
	}

	case   4:
	{
		
		return  200;
	}

	case   5:
	{
		
		return  400;
	}

	case   6:
	{
		
		return  600;
	}

	case   7:
	{
		
		return 800;
	}

	case   8:
	{
		
		return  1000;
	}

	
}

}

void AddBalanceToClientFileByAccountNumber(string AccountNumber,int AmountBalance)
{

	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(FileClientdata);

	for (stClientdata &c: vClientdata)
	{
		if (c.AccountNumber== AccountNumber)
		{
			c.AcoountBalance += AmountBalance;
		}
	}
	SaveClientDataToFileAfterUpdate(vClientdata);


}


bool DepositeBalanceToClientByAccountNumber(string AccountNumber, double AmountBalance,
	vector <stClientdata> &vClientdata)
{
	
	char Answer = 'n';
	cout << "Are you sure you want perform this Transaction y/n ?";
	cin >> Answer;

	if (Answer=='y' || Answer=='Y') 
	{

		for (stClientdata &c : vClientdata)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c.AcoountBalance += AmountBalance;
				SaveClientDataToFileAfterUpdate(vClientdata);
				cout << "Done Successfully, new Balance is:" << c.AcoountBalance<< endl;
				return true;
			}
		}
		
		return false;
	}
	
	
}

void CalculateBalanceAfterWithDrawQuick(short Choice)
{
	
	short QuickWithDrawBalance = 0;
	if (Choice==9)
	{

		return;
	}

	QuickWithDrawBalance= PerformanceWithDrawQuick(Choice);
	
	while (QuickWithDrawBalance > CurrentUser.AcoountBalance)
	{
		cout << "The amount exeeds your Balance,make another choice .";
		cout << "Press any key to continue....";
		system("pause>0");
		ShoQiuckWithDrawScreeen();

	}

	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(FileClientdata);

	DepositeBalanceToClientByAccountNumber(CurrentUser.AccountNumber,
		QuickWithDrawBalance*-1, vClientdata);
	CurrentUser.AcoountBalance -= QuickWithDrawBalance;

}


void PrintQuickWithDrawOption()
{

	cout << "\t[1] 20\t[2] 50\n";
	cout << "\t[3] 100\t[4] 200\n";
	cout << "\t[5] 400\t[6] 600\n";
	cout << "\t[7] 800\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "============================================\n";
	cout << "Your Balance is : " << CurrentUser.AcoountBalance << endl;
	CalculateBalanceAfterWithDrawQuick(ReadChioceWithDrawQuick());
	
}

void NormalWithDraw()
{
	int ResultNormalWithDraw = 0;

	ShoNormalWithDrawScreeen();
	
	ResultNormalWithDraw=ReadAmountNormalWithDraw();

		while (ResultNormalWithDraw > CurrentUser.AcoountBalance)
		{

			cout << "The amount exeeds your Balance,make another choice .";
			ResultNormalWithDraw=ReadAmountNormalWithDraw();
		}

		vector <stClientdata> vClientdata;
		vClientdata = LoadClientDataFromFile(FileClientdata);

		DepositeBalanceToClientByAccountNumber(CurrentUser.AccountNumber,
			ResultNormalWithDraw * -1, vClientdata);
		CurrentUser.AcoountBalance -= ResultNormalWithDraw;

	
}


void DepositeToBalance()
{
	ShowDepositeScreeen();

	int Depositeamount = 0;
	Depositeamount =ReadDepositeNumber();
	
	
	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(FileClientdata);

	DepositeBalanceToClientByAccountNumber(CurrentUser.AccountNumber,
		Depositeamount * 1, vClientdata);
	CurrentUser.AcoountBalance += Depositeamount;


}

void QiuckWithDraw()
{
	ShoQiuckWithDrawScreeen();

	PrintQuickWithDrawOption();


}
void  CheckBalance()
{  
	short TotalBalance = 0;
	ShowBalanceScreeen();

		cout << "Your Balance is : " << CurrentUser.AcoountBalance << endl;
	
}


void ShowMainMenuScreen()
{


	cout << "============================================\n";
	cout << "          ATM Main Menu Screen              \n";
	cout << "============================================\n";
}
void ShoQiuckWithDrawScreeen()
{
	cout << "============================================\n";
	cout << "         Quick  WithDraw  Screeen            \n";
	cout << "============================================\n";
}
void ShoNormalWithDrawScreeen()
{
	cout << "============================================\n";
	cout << "         Normal  WithDraw  Screeen            \n";
	cout << "============================================\n";
}
void ShowBalanceScreeen()
{
		cout << "============================================\n";
		cout << "          Check Balance  Screeen            \n";
		cout << "============================================\n";
}
void ShowDepositeScreeen()
{
	cout << "============================================\n";
	cout << "          Deposite  Screeen            \n";
	cout << "============================================\n";
}
void ShowLoginScreen()
{


	cout << "\n\n------------------------------------\n";
	cout << "\tLogin Screen \n";
	cout << "------------------------------------\n";


}

void GoBackToMainMenu()
{

	cout << "Press any key to go back to Main Menu....\n";
	system("pause>0");
	system("cls");
	OptionMainMenuScreen();
}

void PerformWhatDoYouWant(enOptionAtm OptionAtm)
{

	switch (OptionAtm)
	{
 case  enOptionAtm::eQuickWithdraw:
	{
		system("cls");
		QiuckWithDraw();
		GoBackToMainMenu();
		break;
	}

	
	case  enOptionAtm::eNormalWithdraw:
	{
		system("cls");
		NormalWithDraw();
		GoBackToMainMenu();
		break;
	}
	
	case  enOptionAtm::eDeposit:
	{
		system("cls");
		DepositeToBalance();
		GoBackToMainMenu();
		break;
	}
	case  enOptionAtm::eCheckBalance:  //
	{
		system("cls");
		CheckBalance();
		GoBackToMainMenu();
		break;
	}
	
	case enOptionAtm::eLogout:  //
	{

		system("cls");
		Login();
		break;

	}

	   }

	
}


void OptionMainMenuScreen()
{
	system("cls");
	ShowMainMenuScreen();
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "============================================\n";


	PerformWhatDoYouWant((enOptionAtm)ReadNumberChioce());
}

void Login()
{
	string AccountNumber = "";
	string PinCode = "";

	bool LoginFailed = false;
	 ShowLoginScreen();

	do {


		if (LoginFailed)
		{

			cout << "InValid username/Password !\n";
		}


		cout << "Enter AccountNumber ?";
		cin >> AccountNumber;

		cout << "Enter PinCode ?";
		cin >> PinCode;



		LoginFailed = !LOadUserInfo(AccountNumber, PinCode);

	} while (LoginFailed);
	 OptionMainMenuScreen();
}
int main() {

	Login();


	return 0;
}