#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class BankAccount
{
	private:
		string email,phoneno,password,username,accounttype;
		int age;
		double balance;	
	public:
		string get_username()
		{
			return username;
		}
		string get_passwd()
		{
			return password;
		}
		void setDetails();
		void viewAccountDetails();
		void withdraw();
		void deposit();
		void saveToFile();
};
void BankAccount::setDetails() 
{
	fflush(stdin);
	cout<<"\nPlease Enter Username (no spaces) = ";
	cin>>username;
	cout<<"\nPlease Enter email = ";cin>>email;
	cout<<"\nPlease Enter phone number = ";cin>>phoneno;
	cout<<"\nPlease Enter age = ";cin>>age;
	cout<<"\nPlease Enter Account Type = ";cin>>accounttype;
	cout<<"\nPlease Enter Initial Balance = ";cin>>balance;
	cout<<"\nPlease Set Password = ";cin>>password;
}
void BankAccount::viewAccountDetails()
{
	cout << "\nAccount Details = \n";
    cout << "Username: " << username << "\nEmail: " << email << "\nPhone: " << phoneno << "\nAccount Type: " << accounttype << "\nBalance: " << fixed << setprecision(2) << balance << endl;
}
void BankAccount::withdraw()
{
	double amount;
	cout<<"\nPlease Enter amount to withdraw = ";cin>>amount;
	double minimumBalance = age<18?500:1000;
	if(balance-amount<minimumBalance)
	{
		cout<<"\nInsufficient balance. Minimum balance must be maintained.";
	}
	else
	{
		balance-=amount;
		cout<<"\nWithdrawal successful.\n Current Balance = "<<balance<<endl;
	}
}
void BankAccount::deposit()
{
	int notes[4], denominations[4]={100, 200, 500, 2000};
	double total=0;
	cout<<"\nEnter the number of notes for denominations (100, 200, 500, 2000) : \n";
	for(int i=0;i<4;i++)
	{
		cout<<denominations[i]<<"= ";
		cin>>notes[i];
		total+=notes[i]*denominations[i];
	}
	double depositAmount;
	cout<<"\nEnter Total Deposit Amount = ";
	cin>>depositAmount;
	if(total==depositAmount)
	{
		balance+=total;
		cout<<"\nDeposit Successful. Current Balance = "<<balance<<endl;
	}
	else
	{
		cout<<"\nError: Deposit amount doesn't match note total.\n";
	}
}
void BankAccount::saveToFile() 
{
	ofstream file("login.dat",ios::app);
	if(file)
	{
		file<<username<< " " <<password<<endl;
		file.close();
	}
	else
	{
		cout<<"\nError saving login data.\n";
	}
}
class BankSystem
{
	public:
		void menu()
		{
			BankAccount b;
			string username,password;
			int choice;			
			while(true)
			{
				cout<<"\nNamaste! Welcome To National Bank.\nWe hope you are having a great day.\n";
				cout<<"\n---Banking System Menu---\n";
				cout<<"\n1.Register.\n2.Login.\n3.Exit.";
				cout<<"\nPlease Enter your choice : ";cin>>choice;
				if(choice==1)
				{
					cout<<"\nPlease Register to continue ";
					b.setDetails();
					b.saveToFile();
					cout<<"\nRegistration Successful!";
				}				
				else if(choice==2)
				{
					char usrname[50],passwrd[50];
					cout<<"\nEnter Username = ";
					cin>>usrname;
					cout<<"\nEnter Password = ";
					cin>>passwrd;
					if((b.get_username()==usrname) && (b.get_passwd()==passwrd))
					{
								cout<<"\nSuccessfully Logged In!\n";
								while(true)
								{
									cout<<"\n---Account Menu---\n";
									cout<<"\n1.View Account Details.\n2.Withdraw Money.\n3.Deposit Money.\n4.Logout and Exit.\n";
									cout<<"\nPlease Enter Your Choice = ";
									cin>>choice;
									
									if(choice==1)
									{
										b.viewAccountDetails();
									}
									else if(choice==2)
									{
										b.withdraw();
									}
									else if(choice==3)
									{
										b.deposit();
									}
									else if(choice==4)
									{
										cout<<"\nLogging Out...\n";
										break;
									}
									else
									{
										cout<<"\nInvalid Choice. Please Try Again.\n";
									}
								}
						}
						else
						{
						cout<<"\nInvalid Username or Password.\nPlease Try Again";
						}	
					}
				
				
				else if(choice==3)
				{
					cout<<"\nExiting System.\nGoodbye, See you soon.";
					break;
				}
				else
				{
					cout<<"\nInvalid Choice. Try again.";
				}
			}
		}
};

int main()
{
	BankSystem bs;
	bs.menu();
	return 0;
}