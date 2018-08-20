///////////////////////////////////////////////////////////////
// Account.cpp

///////////////////////////////////////////////////////////////
#include "Account.h"
#include "stdafx.h"
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ws;
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void clearScreen();
void displayTitle();
void pauseScreen();
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
Account::Account()
{
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
Account::Account(accountType_t c_atype)
:my_typeOfAccount(c_atype),
 my_accountNumber(new accNum_t),
 my_customerSocial(new field_t),
 my_customerFullName(new field_t),
 my_customerAddress(new field_t),
 my_customerCity(new field_t),
 my_customerState(new field_t),
 my_customerZipCode(new field_t),
 my_customerHomePhone(new field_t),
 my_customerWorkPhone(new field_t),
 my_pinNumber(new pin_t),
 my_balance(new currency_t)
{
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
Account::Account(accountType_t c_atype, accNum_t c_actnum, field_t c_ssn, 
		         field_t c_fn, field_t c_adr, field_t c_cty, field_t c_st, 
				 field_t c_zc, field_t c_hph, field_t c_wph, pin_t c_pin, 
				 currency_t c_bal)
:my_typeOfAccount(c_atype),
 my_accountNumber(new accNum_t(c_actnum)),
 my_customerSocial(new field_t(c_ssn)),
 my_customerFullName(new field_t(c_fn)),
 my_customerAddress(new field_t(c_adr)),
 my_customerCity(new field_t(c_cty)),
 my_customerState(new field_t(c_st)),
 my_customerZipCode(new field_t(c_zc)),
 my_customerHomePhone(new field_t(c_hph)),
 my_customerWorkPhone(new field_t(c_wph)),
 my_pinNumber(new pin_t(c_pin)),
 my_balance(new currency_t(c_bal))
{
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
Account::~Account()
{
	delete my_accountNumber;
	delete my_customerSocial;
	delete my_customerFullName;
	delete my_customerAddress;
	delete my_customerCity;
	delete my_customerState;
	delete my_customerZipCode;
	delete my_customerHomePhone;
	delete my_customerWorkPhone;
	delete my_pinNumber;
	delete my_balance;
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void Account::createAccount()
{
	clearScreen();
	displayTitle();

	// Account Number
	cout << '\n' << CUSTOMERS_ACCOUNT_NUMBER << ACCOUNT_PREFIX 
	     << this->accountNumber() << endl;

	// Social Security Number
	cout << ENTER_SOCIAL_SECURITY;
	cin >> ws;
	getline(cin, *my_customerSocial);

	// Full Name
	cout << ENTER_CUSTOMERS_FULL_NAME;
	cin >> ws;
	getline(cin, *my_customerFullName);
	
	// Address
	cout << ENTER_ADDRESS;
	cin >> ws;
	getline(cin, *my_customerAddress);

	// City
	cout << ENTER_CITY;
	cin >> ws;
	getline(cin, *my_customerCity);

	// State
	cout << ENTER_STATE;
	cin >> ws;
	getline(cin, *my_customerState);

	// Zip Code
	cout << ENTER_ZIP_CODE;
	cin >> ws;
	getline(cin, *my_customerZipCode);

	// Home Phone
	cout << ENTER_HOME_PHONE;
	cin >> ws;
	getline(cin, *my_customerHomePhone);

	// Work Phone
	cout <<	ENTER_WORK_PHONE;
	cin >> ws;
	getline(cin, *my_customerWorkPhone);

	// Pin
	cout << ENTER_PIN;
	cin >> ws;
	getline(cin, *my_pinNumber);

	// Balance
	cout << ENTER_INITIAL_BALANCE;
	cin >> *my_balance;
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void Account::depositMoney()
{
	clearScreen();
	displayTitle();

	currency_t amt = (0);

	cout << '\n' << HOW_MUCH_DEPOSIT;
	cin >> amt;

	*my_balance += (amt);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void Account::withdrawMoney()
{
	clearScreen();
	displayTitle();

	currency_t amt = (0);
	bool isOver = (false);

	do
	{
		cout << '\n' << HOW_MUCH_WITHDRAWAL;
		cin >> amt;

		if(amt > balance())
		{
			cout << '\n' << INSUFFICIENT_FUNDS << '\n' << endl;

			isOver = (true);
			
			pauseScreen();

			continue;
		}
		else
		{
			*my_balance -= (amt);
		}
	}while(isOver == true);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void Account::insertAccNum(accNum_t accNum)
{
	*my_accountNumber = (accNum);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void Account::viewAccount() const
{
	clearScreen();
	displayTitle();

	cout << '\n' << MENU_BORDER_2 << '\n' << endl;
	cout << ACCOUNT_TYPE;
	(this->typeOfAccount() == CHECKING_CODE) 
		? cout << CHECKING_ACCOUNT 
		: cout << SAVING_ACCOUNT;
	endl(cout);

	cout << ACCOUNT_NUMBER << ACCOUNT_PREFIX << this->accountNumber() << '\n'
			<< SOCIAL_SECURITY_NUMBER << this->customerSocial() << '\n'
			<< FULL_NAME << this->customerFullName() << '\n'
			<< ADDRESS << this->customerAddress() << '\n'
			<< CITY << this->customerCity() << '\n'
			<< STATE << this->customerState() << '\n'
			<< ZIP_CODE << this->customerZipCode() << '\n'
			<< HOME_PHONE << this->customerHomePhone() << '\n'
			<< WORK_PHONE << this->customerWorkPhone() << '\n'
			<< '\n' << BALANCE << this->balance() << '\n';
	cout << '\n' << MENU_BORDER << '\n' << endl;;

	pauseScreen();
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
accountType_t Account::typeOfAccount() const
{
	return(my_typeOfAccount);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
accNum_t Account::accountNumber() const
{
	return(*my_accountNumber);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerSocial() const
{
	return(*my_customerSocial);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerFullName() const
{
	return(*my_customerFullName);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t Account::customerAddress() const
{
	return(*my_customerAddress);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerCity() const
{
	return(*my_customerCity);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerState() const
{
	return(*my_customerState);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerZipCode() const
{
	return(*my_customerZipCode);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerHomePhone() const
{
	return(*my_customerHomePhone);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
field_t	Account::customerWorkPhone() const
{
	return(*my_customerWorkPhone);
}
///////////////////////////////////////////////////////////////

field_t Account::customerPinNumber() const
{
	return(*my_pinNumber);
}

///////////////////////////////////////////////////////////////
currency_t Account::balance() const
{
	return(*my_balance);
}
///////////////////////////////////////////////////////////////