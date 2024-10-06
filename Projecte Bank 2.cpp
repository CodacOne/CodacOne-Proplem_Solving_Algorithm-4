#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

// Project Bank_1_Extension  2

struct stUser
{

	string UserName;
	string Password;
	int Permissions;
	bool DeleteMarkUser = false;
};
struct stClientdata
{
	string AccountNumber;
	string Name;
	string PinCode;
	string Phone;
	double AcoountBalance;
	bool DeleteMark = false;

};



void GoToBackToOptionManageUsers();
void GoBackToMainMenu();
void OptionMainMenuScreen();
void ShowLoginScreen();
void ShowTransactionMainMenu();
void OptionManageUsers();

void GoBackToTransactionMainMenu();
void ShowTransactionScreen();
void ShowDepositScreen();
void ShowWithdrawScreen();
void PerformTransactions(int ChoiceNumber);
int ReadPermissions();
void Login();
void PerformanceUsers(short NumberChoice);
string ConvertUserRecordToLine(stUser User);
bool FindUserByNameAndPassword(string UserName, vector <stUser> vUserdata, stUser& ClientOrder);


const string ClientdataFileName = "Clientdata.txt";
const string FileName = "Users.txt";

stUser CurrentUser;

void PrintClientRecord(stClientdata Client);

enum eOptionTransactions
{

	eDeposit = 1, eWithdraw = 2
	, eTotalBalance = 3, eMainMenuTran = 4

};

enum enOptionManageUsers
{

	eListUsers = 1, eAddNewUsers = 2
	, eDeleteUsers = 3
	, eUpdateUsers = 4, eFindUsers = 5, eMainMenu = 6

};
enum eOptions
{

	eClientList = 1, eAddClient = 2, eDeleteClient = 3
	, eUpdateClient = 4, eFindClient = 5, eManageUsers = 7
	, eTransactions = 6, eLogout = 8

};

enum enMainMenuePermissions
{
	eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
	pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};

int ReadNumberChioce()
{

	short NumberDoYouWant = 0;
	cout << "Chose what do you want to do? [1 to 8]?\n";
	cin >> NumberDoYouWant;
	return NumberDoYouWant;
}
string ReadAccountNumber()
{
	string AccountNumber = "";

	cout << " Please,Enter Account Number ?\n\n";
	cin >> AccountNumber;

	return AccountNumber;
}

string ReadUserName()
{
	string UserName = "";

	cout << " Please,Enter User Name ?\n\n";
	cin >> UserName;

	return UserName;
}

string ReadPassword()
{
	string Password = "";

	cout << " Please,Enter Password ?\n\n";
	cin >> Password;

	return Password;
}
int ReadNumberChioceToTransaction()
{

	short NumberDoYouWant = 0;
	cout << "Chose what do you want to do? [1 to 4]?\n";
	cin >> NumberDoYouWant;
	return NumberDoYouWant;
}
int ReadNumberChioceForUsers()
{

	short NumberDoYouWant = 0;
	cout << "Chose what do you want to do? [1 to 6]?\n";
	cin >> NumberDoYouWant;
	return NumberDoYouWant;
}

bool CheckAccessPermissions(enMainMenuePermissions Permissions)
{
	if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
	{
		return true;
	}
		
	if (Permissions & CurrentUser.Permissions == Permissions)
	{
		return true;
	}

	else
		return false;

}
	

void ShowAccessDeniedMessage()
{


	cout << "\n_________________________________________\n";
	cout << "Access Denied,you don't have permission to do this ,pls Contact with Admin\n";
	cout << "_________________________________________\n\n";

}

/*****************************Start Client File**************************************/


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

vector <stClientdata> LoadClientDataFromFile(string FileNam)
{

	fstream MyData;
	stClientdata Client;
	vector <stClientdata> Clientdata;

	string line = "";

	MyData.open("Clientdata.txt", ios::in);

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
void AddDataLineToClientsFile(string ClientdataFileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(ClientdataFileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();

	}

}

bool ClientExistsOrNot(string AccountNumber)
{

	fstream MyData;
	stClientdata Client;

	string line = "";

	MyData.open("Clientdata.txt", ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{
			Client = ConvertLinetoRecord(line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyData.close();
				return true;
			}

		}

		MyData.close();
	}
	return false;
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

stClientdata ReadClientData() {

	stClientdata ClientData;

	cout << "Enter Account Number :\n";
	getline(cin >> ws, ClientData.AccountNumber);

	while (ClientExistsOrNot(ClientData.AccountNumber))
	{
		cout << "\nClient With ( " << ClientData.AccountNumber << " ) already Exists , Enter another Account number ?\n";

		getline(cin >> ws, ClientData.AccountNumber);

	}

	cout << "Enter Name :\n";
	getline(cin, ClientData.Name);

	cout << "Enter PinCode :\n";
	getline(cin, ClientData.PinCode);

	cout << "Enter Phone :\n";
	getline(cin, ClientData.Phone);

	cout << "Enter Account Balance :\n";
	cin >> ClientData.AcoountBalance;


	return ClientData;
}

void AddNewClient()
{
	stClientdata Client;
	Client = ReadClientData();

	AddDataLineToClientsFile(ClientdataFileName, ConvertClientRecordToLine(Client));

}

void AddNewClients()
{
	if (!CheckAccessPermissions(enMainMenuePermissions::pAddNewClient))
	{

		ShowAccessDeniedMessage();
		return;

	}


	char AddMore = 'n';

	cout << "\n---------------------------------------\n";
	cout << "\tAdd New Client Screen\n";
	cout << "---------------------------------------\n";
	do
	{
		cout << "Adding New Client :\n\n\n";

		AddNewClient();

		cout << "Client Add successfully, Do you want to add more Clients ? Y/N ?\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');


}

bool FindClientByAccountNumber(string AccountNumber, vector <stClientdata> vClientdata, stClientdata& ClientOrder)
{
	vector <stClientdata> Client;
	stClientdata stClient;


	for (stClientdata MyClient : vClientdata)
	{
		if (MyClient.AccountNumber == AccountNumber)
		{



			ClientOrder = MyClient;
			return true;
		}


	}

	return false;

}

void MarkClientForDeleteByAccoutNumber(string AccountNumber, vector <stClientdata>& vClientdata)
{

	for (stClientdata& c : vClientdata)
	{
		if (c.AccountNumber == AccountNumber)
		{

			c.DeleteMark = true;
		}


	}

}

vector <stClientdata> SaveClientDataToFileAfterDelete(vector <stClientdata> vClientdata)
{
	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(ClientdataFileName, ios::out);


	if (MyFile.is_open())
	{


		for (stClientdata Line : vClientdata)
		{

			if (Line.DeleteMark == false)
			{

				DataFileNew = ConvertClientRecordToLine(Line);
				MyFile << DataFileNew << endl;

			}




		}


		MyFile.close();
	}


	return vClientdata;
}

void DeleteClientByAccountNumber()
{
	if (!CheckAccessPermissions(enMainMenuePermissions::pDeleteClient))
	{

		ShowAccessDeniedMessage();
		return;

	}


	stClientdata Client;
	vector <stClientdata> vClientdata;

	string AccountNumber = ReadAccountNumber();

	char ChoiceDelete = 'n';


	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	if (FindClientByAccountNumber(AccountNumber, vClientdata, Client))
	{
		cout << "The Following are the client details :\n\n";
		PrintClientRecord(Client);

		cout << "Do you sure you want Delete this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			MarkClientForDeleteByAccoutNumber(AccountNumber, vClientdata);
			SaveClientDataToFileAfterDelete(vClientdata);



			cout << "\n\n Cleint Delete Succefuly. \n";
		}

	}

	else
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}



}

vector <stClientdata> SaveClientDataToFileAfterUpdate(vector <stClientdata> vClientdata)
{
	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(ClientdataFileName, ios::out);


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

vector <stClientdata> UpdateClient(vector <stClientdata>& vClientdata)
{
	for (stClientdata& Client : vClientdata)

	{
		if (Client.DeleteMark == true)
		{
			cout << "Enter Name ? " << endl;
			getline(cin >> ws, Client.Name);


			cout << "Enter PinCode ? " << endl;
			cin >> Client.PinCode;

			cout << "Enter Phone ? " << endl;
			cin >> Client.Phone;

			cout << "Enter Account Balance ? " << endl;
			cin >> Client.AcoountBalance;
			break;   // Very important to speed code
		}
	}
	return vClientdata;
}

void UpdateClientByAccountNumber()
{

	if (!CheckAccessPermissions(enMainMenuePermissions::pUpdateClients))
	{

		ShowAccessDeniedMessage();
		return;

	}


	stClientdata Client;
	vector <stClientdata> vClientdata;

	char ChoiceDelete = 'n';

	cout << "\n---------------------------------------\n";
	cout << "\tUpdate Client Screen\n";
	cout << "---------------------------------------\n";

	string AccountNumber = ReadAccountNumber();


	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	if (FindClientByAccountNumber(AccountNumber, vClientdata, Client))
	{

		PrintClientRecord(Client);

		cout << "Do you sure you want Update this Client ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			MarkClientForDeleteByAccoutNumber(AccountNumber, vClientdata);
			UpdateClient(vClientdata);
			SaveClientDataToFileAfterUpdate(vClientdata);


			// Refresh data of file
		//	vClientdata = LoadClientDataFromFile(ClientdataFileName);

			cout << "\n\n Cleint Update Succefuly. \n";
		}

	}

	else
	{
		cout << "Client with Account number (" << AccountNumber << ") Not found !\n\n";
	}



}

void FindClientAndPrintDetails()
{
	if (!CheckAccessPermissions(enMainMenuePermissions::pFindClient))
	{

		ShowAccessDeniedMessage();
		return;

	}


	vector <stClientdata> vClientdata;
	stClientdata Client;

	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	string AccountNumber = ReadAccountNumber();
	system("cls");
	cout << "--------------------------------\n";
	cout << "\tFind Client Screen\n";
	cout << "--------------------------------\n";

	for (stClientdata MyClient : vClientdata)
	{
		if (MyClient.AccountNumber == AccountNumber)
		{



			Client = MyClient;
			PrintClientRecord(Client);
			break;
		}

		else
			cout << "Client With Account Number ( " << AccountNumber << " ) is Not found!\n";
		break;
	}

}

/*****************************End Client File**************************************/


/************************************Start Function users*********************************************/
stUser ConvertUsersLinetoRecord(string line, string Delim = "#//#")
{
	vector<string> vUserData;
	stUser User;

	vUserData = SplitString(line, Delim);

	User.UserName = vUserData[0];
	User.Password = vUserData[1];
	User.Permissions = stoi(vUserData[2]);

	return User;
}
vector <stUser> LoadUsersDataFromFile(string FileName)
{

	fstream MyData;
	stUser User;
	vector <stUser> vUser;

	string line = "";

	MyData.open("Users.txt", ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{

			User = ConvertUsersLinetoRecord(line);
			vUser.push_back(User);

		}
		MyData.close();

	}
	return vUser;
}

void PrintUserRecord(stUser & User)
{
	cout << "THE following are the User details :\n";
	cout << "------------------------------------------\n";
	cout << " " << setw(20) << left << "Username : " << User.UserName << endl;
	cout << " " << setw(20) << left << "Password : " << User.Password << endl;
	cout << " " << setw(20) << left << "Permission: " << User.Permissions << endl;

	cout << "------------------------------------------\n";
}

void MarkUserForDeleteByUsername(string Username, vector <stUser>& vUser)
{

	for (stUser& c : vUser)
	{
		if (c.UserName == Username)
		{

			c.DeleteMarkUser = true;
		}


	}

}

void FindUserAndPrintDetails()
{

	vector <stUser> vUser;
	stUser User;

	vUser = LoadUsersDataFromFile(FileName);

	string UserName = ReadUserName();

	system("cls");
	cout << "--------------------------------\n";
	cout << "\tFind User Screen\n";
	cout << "--------------------------------\n";

	for (stUser MyClient : vUser)
	{
		if (MyClient.UserName == UserName)
		{

			User = MyClient;
			PrintUserRecord(User);
			break;
		}


	}


	cout << "User With UserName ( " << UserName << " ) is Not found!\n";


}

vector <stUser> SaveUserDataToFileAfterUpdate(vector <stUser> vUser)
{
	fstream MyFile;   // stUser User
	string DataFileNew = "";

	MyFile.open(FileName, ios::out);


	if (MyFile.is_open())
	{


		for (stUser Line : vUser)
		{

			DataFileNew = ConvertUserRecordToLine(Line);
			MyFile << DataFileNew << endl;

		}


		MyFile.close();
	}


	return vUser;
}


vector <stUser> UpdateUser(vector <stUser>& vUser)
{
	for (stUser& User : vUser)

	{
		if (User.DeleteMarkUser == true)
		{
			cout << "Enter UserName ? " << endl;
			getline(cin >> ws, User.UserName);


			cout << "Enter Password? " << endl;
			cin >> User.Password;

			User.Permissions = ReadPermissions();

			break;   // Very important to speed code
		}
	}
	return vUser;
}


void UpdateUserByUserName()
{
	// stUser User
	stUser User;
	vector <stUser> vUser;

	char ChoiceDelete = 'n';

	cout << "\n---------------------------------------\n";
	cout << "\tUpdate User Screen\n";
	cout << "---------------------------------------\n";

	string UserName = ReadUserName();


	vUser = LoadUsersDataFromFile(FileName);

	if (FindUserByNameAndPassword(UserName, vUser, User))
	{

		PrintUserRecord(User);

		cout << "Do you sure you want Update this User ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			MarkUserForDeleteByUsername(UserName, vUser);
			UpdateUser(vUser);
			SaveUserDataToFileAfterUpdate(vUser);

			cout << "\n\n Update User Succefuly. \n";
		}

	}

	else
	{
		cout << "User with Username (" << UserName << ") Not found !\n\n";
	}



}


bool FindUserByNameAndPassword(string UserName, vector <stUser> vUserdata, stUser & ClientOrder)
{

	for (stUser MyClient : vUserdata)
	{
		if (MyClient.UserName == UserName)
		{

			ClientOrder = MyClient;
			return true;
		}


	}

	return false;

}
vector <stUser> SaveUserDataToFileAfterDelete(vector <stUser>& vUser)
{

	fstream MyFile;
	string DataFileNew = "";

	MyFile.open(FileName, ios::out);


	if (MyFile.is_open())
	{


		for (stUser& Line : vUser)
		{

			if (Line.DeleteMarkUser == false)
			{

				DataFileNew = ConvertUserRecordToLine(Line);
				MyFile << DataFileNew << endl;

			}

		}

		MyFile.close();
	}


	return vUser;
}

void DeleteUser()
{
	stUser User;
	vector <stUser> vUserdata;

	string Username = ReadUserName();
	string Password = ReadPassword();

	char ChoiceDelete = 'n';


	vUserdata = LoadUsersDataFromFile(FileName);

	if (FindUserByNameAndPassword(Username, vUserdata, User))
	{
		cout << "The Following are the client details :\n\n";
		PrintUserRecord(User);

		cout << "Do you sure you want Delete this User ? y/n ?\n\n";
		cin >> ChoiceDelete;


		if (ChoiceDelete == 'Y' || ChoiceDelete == 'y')
		{


			MarkUserForDeleteByUsername(Username, vUserdata);
			SaveUserDataToFileAfterDelete(vUserdata);



			cout << "\n\n User Delete Succefuly. \n";
		}

	}

	else
	{
		cout << "User with Username (" << Username << ") Not found !\n\n";
	}


}


string ConvertUserRecordToLine(stUser User)
{
	string Delim = "#//#";
	string line = "";
	line = line + User.UserName + Delim;
	line = line + User.Password + Delim;
	line = line + to_string(User.Permissions) + Delim;


	return line;
}


int ReadPermissions()
{

	short Permission = 0;
	char choicePermission = 'y';


	//////////////////////////////////////////

	cout << "Do you want to give Full access ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		return -1;
	}
	//////////////////////////////////////////
	cout << "\nDo you want to give access to :\n";

	cout << "Show client list ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pListClients;
	}

	//////////////////////////////////////////
	cout << "Add new client  ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pAddNewClient;
	}

	//////////////////////////////////////////
	cout << "Delete client  ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pDeleteClient;
	}
	//////////////////////////////////////////
	cout << "Update client  ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pUpdateClients;
	}

	//////////////////////////////////////////

	cout << "Find client  ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pFindClient;
	}

	//////////////////////////////////////////

	cout << "Tranactions ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pTranactions;
	}

	//////////////////////////////////////////

	cout << "Manage Users ? Y/N";
	cin >> choicePermission;

	if (choicePermission == 'y' || choicePermission == 'Y')
	{

		Permission += enMainMenuePermissions::pManageUsers;
	}

	return Permission;
}

void AddDataLineToUserFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();

	}

}

bool UserExistsOrNot(string UserName)
{

	fstream MyData;
	stUser User;

	string line = "";

	MyData.open("Users.txt", ios::in);

	if (MyData.is_open())
	{
		while (getline(MyData, line))
		{
			User = ConvertUsersLinetoRecord(line);
			if (User.UserName == UserName)
			{
				MyData.close();
				return true;
			}

		}

		MyData.close();
	}
	return false;
}

stUser ReadUserData(stUser& User)
{

	cout << "Enter Username :\n";
	getline(cin >> ws, User.UserName);

	while (UserExistsOrNot(User.UserName))
	{
		cout << "\nUser With ( " << User.UserName << " ) already Exists , Enter another UserName  ?\n";

		getline(cin >> ws, User.UserName);

	}

	cout << "Enter Password :\n";
	getline(cin, User.Password);

	User.Permissions = ReadPermissions();
	return User;

}

void AddNewUser()
{
	stUser User;

	User = ReadUserData(User);
	AddDataLineToUserFile(FileName, ConvertUserRecordToLine(User));

}

void AddNewUsers()
{

	char AddMore = 'n';

	cout << "\n---------------------------------------\n";
	cout << "\tAdd New Users Screen\n";
	cout << "---------------------------------------\n";
	do
	{
		cout << "\nAdding New User :\n\n\n";

		AddNewUser();

		cout << "User Add successfully, Do you want to add more Users ? Y/N ?\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');



}

void PrintRecordUsers(stUser& User)
{

	cout << "| " << left << setw(30) << User.UserName;
	cout << "| " << left << setw(25) << User.Password;
	cout << "| " << left << setw(25) << User.Permissions;


}

void UserList()
{

	vector <stUser> vUser;
	vUser = LoadUsersDataFromFile(FileName);


	cout << setw(40) << "Users List (" << vUser.size() << ") User(S). " << endl;

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;

	cout << "| " << left << setw(30) << "User Name ";
	cout << "| " << left << setw(25) << "Password ";
	cout << "| " << left << setw(25) << "Permissions ";


	cout << "\n\n--------------------------------------------------";
	cout << "------------------------------" << endl;


	for (stUser Us : vUser)
	{

		PrintRecordUsers(Us);
		cout << endl;
	}

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;



}

void PerformanceUsers(short NumberChoice)
{
	switch (NumberChoice)
	{
	case  enOptionManageUsers::eListUsers:
	{
		system("cls");
		UserList();
		GoToBackToOptionManageUsers();
		break;
	}

	case  enOptionManageUsers::eAddNewUsers:
	{
		system("cls");
		AddNewUsers();
		GoToBackToOptionManageUsers();
		break;
	}
	case  enOptionManageUsers::eDeleteUsers:
	{
		system("cls");
		DeleteUser();
		GoToBackToOptionManageUsers();
		break;
	}

	case  enOptionManageUsers::eUpdateUsers:
	{
		system("cls");
	//	UpdateUserByUserName();
		GoToBackToOptionManageUsers();
		break;
	}

	case  enOptionManageUsers::eFindUsers:
	{
		system("cls");
	//	FindUserAndPrintDetails();
		GoToBackToOptionManageUsers();
		break;
	}

	case  enOptionManageUsers::eMainMenu:
	{
		system("cls");
		OptionMainMenuScreen();
		break;
	}

	}
}

void ShowManageUsers()
{

	cout << "============================================\n";
	cout << "           Manage Users Menu Screen              \n";
	cout << "============================================\n";


}
void GoToBackToOptionManageUsers()
{
	cout << "Press any key to go back to Main Menu....\n";
	system("pause>0");
	system("cls");
	OptionManageUsers();
}

void OptionManageUsers()
{
	if (!CheckAccessPermissions(enMainMenuePermissions::pManageUsers))
	{

		ShowAccessDeniedMessage();
		return;

	}


	ShowManageUsers();
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menu.\n";

	cout << "============================================\n";

	PerformanceUsers(ReadNumberChioceForUsers());
}

/************************************End Function users*********************************************/



/*************************Start Function to Trancsaction***********************************/
void AmountBalanceAfterDeposit(double Deposit,
	string AccountNumber, vector <stClientdata>& vClientdata, char AddOrSub)
{

	for (stClientdata& Client : vClientdata)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			switch (AddOrSub)
			{

			case '+':
			{
				Client.AcoountBalance = Client.AcoountBalance + Deposit;
				break;
			}

			case '-':
			{
				Client.AcoountBalance = Client.AcoountBalance - Deposit;
				break;
			}


			}


		}


	}

	SaveClientDataToFileAfterUpdate(vClientdata);

}

void ShowDeposit()
{
	vector <stClientdata> vClientdata;
	stClientdata ClientData;
	double Depositamount = 0;
	char Choiceperformance = 'n';

	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	ShowDepositScreen();


	cout << "Enter Account Number :\n";
	getline(cin >> ws, ClientData.AccountNumber);

	while (!ClientExistsOrNot(ClientData.AccountNumber))

	{
		cout << "Client With [" << ClientData.AccountNumber << "] Not exist.\n";
		getline(cin >> ws, ClientData.AccountNumber);
	}

	FindClientByAccountNumber(ClientData.AccountNumber, vClientdata, ClientData);
	PrintClientRecord(ClientData);

	cout << "\nPlease Enter Deposit amount?\n";
	cin >> Depositamount;
	cout << "Are you sure you want perform this transaction? Y/N ?\n";
	cin >> Choiceperformance;

	if (Choiceperformance == 'y' || Choiceperformance == 'Y')

	{
		AmountBalanceAfterDeposit(Depositamount, ClientData.AccountNumber, vClientdata, '+');
	}


	else
	{
		GoBackToTransactionMainMenu();
	}
}

void ShowWithdraw()
{

	vector <stClientdata> vClientdata;
	stClientdata ClientData;
	double Withdrawamount = 0;
	char Choiceperformance = 'n';

	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	ShowWithdrawScreen();


	cout << "Enter Account Number :\n";
	getline(cin >> ws, ClientData.AccountNumber);

	while (!ClientExistsOrNot(ClientData.AccountNumber))

	{
		cout << "Client With [" << ClientData.AccountNumber << "] Not exist.\n";
		getline(cin >> ws, ClientData.AccountNumber);
	}

	FindClientByAccountNumber(ClientData.AccountNumber, vClientdata, ClientData);
	PrintClientRecord(ClientData);

	cout << "\nPlease Enter Withdraw amount?\n";
	cin >> Withdrawamount;
	cout << "Are you sure you want perform this transaction? Y/N ?\n";
	cin >> Choiceperformance;

	if (toupper(Choiceperformance) == 'y' || Withdrawamount < ClientData.AcoountBalance)

	{
		AmountBalanceAfterDeposit(Withdrawamount, ClientData.AccountNumber, vClientdata, '-');
	}


	else
	{
		GoBackToTransactionMainMenu();
	}



}

void PrintTotalBalance(stClientdata Clientdata)
{

	cout << "| " << setw(15) << left << Clientdata.AccountNumber;
	cout << "| " << setw(40) << left << Clientdata.Name;
	cout << "| " << setw(15) << left << Clientdata.AcoountBalance;

}

void ShowTotalBalance()
{
	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(ClientdataFileName);

	double TotalBalance = 0;

	cout << setw(40) << "Client List (" << vClientdata.size() << ") Client(S). " << endl;

	cout << "\n--------------------------------------------------";
	cout << "------------------------------\n" << endl;
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(40) << left << "Client Name";
	cout << "| " << setw(15) << left << "Balance";
	cout << "\n--------------------------------------------------";
	cout << "------------------------------\n" << endl;

	for (stClientdata Client : vClientdata)
	{

		PrintTotalBalance(Client);
		cout << endl;
		TotalBalance = TotalBalance + Client.AcoountBalance;

	}

	cout << "\n--------------------------------------------------";
	cout << "------------------------------\n" << endl;

	cout << " \t\tTotal Balance = " << TotalBalance << endl;;
}

void GoBackToTransactionMainMenu()
{

	cout << "Press any key to go back to Main Menu....\n";
	system("pause>0");
	system("cls");
	ShowTransactionMainMenu();
}
void ShowWithdrawScreen()
{

	cout << "--------------------------------\n";
	cout << "\tWithdraw Screen\n";
	cout << "--------------------------------\n";

}
void ShowDepositScreen()
{

	cout << "--------------------------------\n";
	cout << "\tDeposit Screen\n";
	cout << "--------------------------------\n";
}

void PerformTransactions(int ChoiceNumber)
{

	switch (ChoiceNumber)
	{
	case  eOptionTransactions::eDeposit:
	{
		system("cls");
		ShowDeposit();
		GoBackToTransactionMainMenu();
		break;
	}

	case  eOptionTransactions::eWithdraw:
	{
		system("cls");
		ShowWithdraw();
		GoBackToTransactionMainMenu();
		break;
	}

	case  eOptionTransactions::eTotalBalance:
	{
		system("cls");
		ShowTotalBalance();
		GoBackToTransactionMainMenu();
		break;
	}

	case  eOptionTransactions::eMainMenuTran:
	{
		system("cls");
		GoBackToMainMenu();
		break;
	}
	}

}


/*************************Start Function to Trancsaction***********************************/




void ExitProgram()
{

	cout << "\n\n------------------------------------\n";
	cout << "\tPrograms Ends :-)\n";
	cout << "------------------------------------\n";



}


void PrintRecordClients(stClientdata Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(20) << left << Client.PinCode;
	cout << "| " << setw(20) << left << Client.Phone;
	cout << "| " << setw(15) << left << Client.AcoountBalance;


}


void PrintClientRecord(stClientdata Client)
{
	cout << "THE following are the Client details :\n";
	cout << "------------------------------------------\n";
	cout << " " << setw(20) << left << "AccountNumber : " << Client.AccountNumber << endl;
	cout << " " << setw(20) << left << "Name : " << Client.Name << endl;
	cout << " " << setw(20) << left << "PinCode : " << Client.PinCode << endl;
	cout << " " << setw(20) << left << "Phone : " << Client.Phone << endl;
	cout << " " << setw(20) << left << "AcoountBalance : " << Client.AcoountBalance << endl;
	cout << "------------------------------------------\n";
}


void printAllClientsData(vector <stClientdata> vClientdata)

{
	cout << setw(40) << "Client List (" << vClientdata.size() << ") Client(S). " << endl;

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(20) << "Pin code";
	cout << "| " << left << setw(20) << "Phone";
	cout << "| " << left << setw(15) << "Balance";

	cout << "\n\n--------------------------------------------------";
	cout << "------------------------------" << endl;


	for (stClientdata Result : vClientdata)
	{

		PrintRecordClients(Result);
		cout << endl;
	}

	cout << "--------------------------------------------------";
	cout << "------------------------------" << endl;

}

void ShowTransactionScreen()
{

	cout << "\n\n========================================\n";
	cout << "\t Transactions Menue Screen\n";
	cout << "========================================\n";

}


void ShowClentList()
{

	if (!CheckAccessPermissions(enMainMenuePermissions::pListClients))
	{

		ShowAccessDeniedMessage();
		return;

	}

	vector <stClientdata> vClientdata;
	vClientdata = LoadClientDataFromFile(ClientdataFileName);
	printAllClientsData(vClientdata);

}


void ShowTransactionMainMenu()
{
	if (!CheckAccessPermissions(enMainMenuePermissions::pTranactions))
	{

		ShowAccessDeniedMessage();
		return;

	}


	ShowTransactionScreen();

	cout << "\t[1] Deposite.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menu.\n";

	cout << "================================\n";


	PerformTransactions(ReadNumberChioceToTransaction());

}


void PerformToClient(enOptionManageUsers NumberDoYouWant)
{

	switch (NumberDoYouWant)
	{
	case  eOptions::eClientList:
	{
		system("cls");
		 ShowClentList();
		GoBackToMainMenu();
		break;
	}


	case  eOptions::eAddClient:
	{
		system("cls");
		AddNewClients();
		GoBackToMainMenu();
		break;
	}
	
	case  eOptions::eDeleteClient:
	{
		system("cls");
		DeleteClientByAccountNumber();
		GoBackToMainMenu();
		break;
	}

	case  eOptions::eUpdateClient:
	{
		system("cls");
		UpdateClientByAccountNumber();
		GoBackToMainMenu();
		break;
	}

	case eOptions::eFindClient:
	{

		system("cls");
		FindClientAndPrintDetails();
		GoBackToMainMenu();
		break;

	}
	
	case eOptions::eTransactions:
	{

		system("cls");
		ShowTransactionMainMenu();

		break;

	}
	case eOptions::eManageUsers:
	{

		system("cls");
		OptionManageUsers();

		break;

	}

	case eOptions::eLogout:
	{

		system("cls");
		 Login();

		break;

	}
	
	}
}

void GoBackToMainMenu()
{

	cout << "Press any key to go back to Main Menu....\n";
	system("pause>0");
	system("cls");
	OptionMainMenuScreen();
}

void ShowMainMenuScreen()
{

	system("cls");
	cout << "============================================\n";
	cout << "            Main Menu Screen              \n";
	cout << "============================================\n";
}

void OptionMainMenuScreen()
{
	
	ShowMainMenuScreen();
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Fined Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "============================================\n";


	PerformToClient(enOptionManageUsers(ReadNumberChioce()));
}

bool FindUserByUsernameAndPasswordNew(string UserName, string Password, stUser & user)
{
	vector <stUser> vUser;
	vUser = LoadUsersDataFromFile(FileName);

	for (stUser U : vUser)
	{
		if (U.UserName == UserName && U.Password == Password)
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


void Login()
{
	string username = "";
	string Password = "";

	bool LoginFailed = false;
	ShowLoginScreen();

	do {


		if (LoginFailed)
		{

			cout << "InValid username/Password !\n";
		}


		cout << "Enter username ?";
		cin >> username;

		cout << "Enter Password ?";
		cin >> Password;



		LoginFailed = !LOadUserInfo(username, Password);

	} while (LoginFailed);
	OptionMainMenuScreen();
}

void ShowLoginScreen()
{


	cout << "\n\n------------------------------------\n";
	cout << "\tLogin Screen \n";
	cout << "------------------------------------\n";


}

int main() {

	Login();


	return 0;
}