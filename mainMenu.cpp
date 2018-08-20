///////////////////////////////////////////////////////////////
// mainMenu.cpp

///////////////////////////////////////////////////////////////
#include "Account.h"
#include "checkingAccount.h"
#include "savingAccount.h"
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::fstream;
using std::getline;
using std::ios;
using std::vector;
using std::ws;
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void clearScreen();
void displayTitle();
void pauseScreen();
char quit();
lint_t findRecord(vector<Account*>*& pv_pca, const field_t ssn);
bool verifyDuplicateEntries(vector<Account*>*& pv_pca, accNum_t accNum);
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void mainMenu(vector<Account*>*& pv_pca)
{
	char myChoice = (' ');

	do
	{
		clearScreen();
		displayTitle();

		cout << '\n'
			 << CREATE_NEW_ACCOUNT		<< '\n'
			 << DEPOSIT_INTO_ACCOUNT	<< '\n'
		     << WITHDRAWAL_FROM_ACCOUNT	<< '\n'
		     << VIEW_ACCOUNT			<< '\n'
			 << ERASE_ACCOUNT			<< '\n'
			 << REMOVE_FILE				<< '\n'
			 << LOAD_FILE				<< '\n'
			 << ARCHIVE_FILE			<< '\n'
		     << EXIT_PROGRAM			<< '\n' 
										<< endl;

		cout << ENTER_CHOICE;
		cin >> myChoice;

		myChoice = toupper(myChoice);

		if(myChoice == EXIT_CODE)
		{
			if(quit() == TRUE)	{ break; }
			else 
			{ 
				myChoice = ' ';

				continue; 
			}
		}

		switch(myChoice)
		{
		case(CREATE_CODE):
			{
				accountType_t acc = (' ');
				bool isGoBack = (false);

				do
				{
					clearScreen();
					displayTitle();

					cout << '\n' << WHAT_TYPE_OF_ACC;
					cin >> acc;

					acc = toupper(acc);

					if(acc != CHECKING_CODE && acc != SAVING_CODE && acc != GO_BACK_CODE)
					{
						cerr << '\n' << ERROR_100 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else if(acc == GO_BACK_CODE)
					{
						isGoBack = (true);
					}

					if(!isGoBack)
					(acc == CHECKING_CODE) 
						? pv_pca->push_back(new checkingRecord_t()) 
						: pv_pca->push_back(new savingRecord_t());

				}while(acc != CHECKING_CODE && acc != SAVING_CODE && acc != GO_BACK_CODE);

				if(!isGoBack)
				{
					pv_pca->back()->insertAccNum(accNum_t(pv_pca->size()));
					pv_pca->back()->createAccount();
				}

				break;
			}
		case(DEPOSIT_CODE):
			{
				if(pv_pca->empty())
				{
					cerr << '\n' << ERROR_101 << '\n' << endl;
					
					pauseScreen();

					continue;
				}
				
				field_t ssn;

				cout << '\n' << ENTER_SSN;
				cin >> ws;
				getline(cin, ssn);

				if(ssn == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					uint_t elemNum_;

					elemNum_ = findRecord(pv_pca, ssn);
					
					if(elemNum_ == RECORD_NOT_FOUND)
					{
						cerr << '\n' << ERROR_106 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else
					{
						pv_pca->at(elemNum_)->depositMoney();
					}					
				}

				break;
			}
		case(WITHDRAWAL_CODE):
			{
				if(pv_pca->empty())
				{
					cerr << '\n' << ERROR_101 << '\n' << endl;
					
					pauseScreen();

					continue;
				}

				field_t ssn;

				cout << '\n' << ENTER_SSN;
				cin >> ws;
				getline(cin, ssn);

				if(ssn == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else		
				{
					uint_t elemNum_;

					elemNum_ = findRecord(pv_pca, ssn);
					
					if(elemNum_ == RECORD_NOT_FOUND)
					{
						cerr << '\n' << ERROR_106 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else
					{
						pv_pca->at(elemNum_)->withdrawMoney();
					}
				}

				break;
			}
		case(VIEW_CODE):
			{
				if(pv_pca->empty())
				{
					cerr << '\n' << ERROR_101 << '\n' << endl;
					
					pauseScreen();

					continue;
				}

				field_t ssn;

				cout << '\n' << ENTER_SSN;
				cin >> ws;
				getline(cin, ssn);

				if(ssn == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					uint_t elemNum_;

					elemNum_ = findRecord(pv_pca, ssn);
					
					if(elemNum_ == RECORD_NOT_FOUND)
					{
						cerr << '\n' << ERROR_106 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else
					{
						pv_pca->at(elemNum_)->viewAccount();
					}
				}
				
				break;
			}
		case(ERASE_CODE):
			{
				if(pv_pca->empty())
				{
					cerr << '\n' << ERROR_101 << '\n' << endl;
					
					pauseScreen();

					continue;
				}

				field_t ssn;

				cout << '\n' << ENTER_SSN;
				cin >> ws;
				getline(cin, ssn);

				if(ssn == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					uint_t elemNum_;

					elemNum_ = findRecord(pv_pca, ssn);
					
					if(elemNum_ == RECORD_NOT_FOUND)
					{
						cerr << '\n' << ERROR_106 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else
					{
						pv_pca->erase(pv_pca->begin() + elemNum_);

						cout << '\n' << RECORD_ERASED << '\n' << endl;
		
						pauseScreen();
					}
				}

				break;
			}
		case(REMOVE_FILE_CODE):
			{
				field_t fileName;

				cout << '\n' << FILE_TO_REMOVE;
				cin >> fileName;

				if(fileName == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					field_t filePath;

					filePath = DATA_DIRECTORY;
					filePath += "\\";
					filePath += fileName;
					
					if(_unlink(filePath.c_str()) == -1 )
					{
						cerr << '\n' << ERROR_105 << '\n' << endl;

						pauseScreen();

						continue;
					}
					else
					{
						cout << '\n' << FILE_REMOVED << '\n' << endl;

						pauseScreen();
					}
				}

				break;
			}
		case(LOAD_FILE_CODE):
			{
				fstream fin;
				field_t fileName;

				accountType_t	typeOfAccount;
				accNum_t		accountNumber;
				field_t			customerSocial,
								customerFullName,
								customerAddress,
								customerCity,
								customerState,
								customerZipCode,
								customerHomePhone,
								customerWorkPhone,
								customerPinNumber;
				currency_t		balance;

				cout << '\n' << INPUT_FILENAME;
				cin >> fileName;

				if(fileName == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					field_t filePath;

					filePath = DATA_DIRECTORY;
					filePath += "\\";
					filePath += fileName;

					fin.open(filePath.c_str(), ios::in);
					
					if(!fin)
					{
						cerr << '\n' << ERROR_103 << '\n' << endl;
					}
					else
					{
						while(!fin.eof())
						{
							fin >> typeOfAccount;
							fin >> accountNumber;			
							(fin >> ws), getline(fin, customerSocial);
							(fin >> ws), getline(fin, customerFullName);
							(fin >> ws), getline(fin, customerAddress);
							(fin >> ws), getline(fin, customerCity);
							(fin >> ws), getline(fin, customerState);
							(fin >> ws), getline(fin, customerZipCode);
							(fin >> ws), getline(fin, customerHomePhone);
							(fin >> ws), getline(fin, customerWorkPhone);
							(fin >> ws), getline(fin, customerPinNumber);
							fin >> balance;

							// check for duplicate accountNumbers - if duplicate is found, it is excluded
							if(verifyDuplicateEntries(pv_pca, accountNumber) == false)
							{
								if(typeOfAccount == CHECKING_CODE)
								{
									pv_pca->push_back(new CheckingAccount(accountNumber, 
									customerSocial, customerFullName, customerAddress,
									customerCity, customerState, customerZipCode,
									customerHomePhone, customerWorkPhone, customerPinNumber,
									balance));
								}
								else
								{
									pv_pca->push_back(new SavingAccount(accountNumber, 
									customerSocial, customerFullName, customerAddress, 
									customerCity, customerState, customerZipCode, 
									customerHomePhone, customerWorkPhone, customerPinNumber, balance));
								}
							}
						}

						cout << '\n' << LOAD_COMPLETED << '\n' << endl;
		
						fin.close();
					}
				
					pauseScreen();
				}

				break;
			}
		case(ARCHIVE_FILE_CODE):
			{
				if(pv_pca->empty())
				{
					cerr << '\n' << ERROR_101 << '\n' << endl;
					
					pauseScreen();

					continue;
				}

				_mkdir(DATA_DIRECTORY);

				fstream fout;
				field_t fileName, filePath;

				cout << '\n' << OUTPUT_FILENAME;
				cin >> fileName;

				if(fileName == "-1")
				{
					; // don't do anything if the user takes the action of going back
				}
				else
				{
					filePath = DATA_DIRECTORY;
					filePath += "\\";
					filePath += fileName;

					fout.open(filePath.c_str(), ios::out | ios::app);

					if(!fout)
					{
						cerr << '\n' << ERROR_104 << '\n' << endl;
					}
					else
					{
						for(uint_t i = 0; i < pv_pca->size(); ++i)
						{
							if(pv_pca->at(i)->accountNumber() == 1)
							{
								fout << pv_pca->at(i)->typeOfAccount() << '\n';
							}
							else
							{
								fout << '\n' << pv_pca->at(i)->typeOfAccount() << '\n';
							}

								fout << pv_pca->at(i)->accountNumber()		<< '\n'
									 << pv_pca->at(i)->customerSocial()		<< '\n'
									 << pv_pca->at(i)->customerFullName()	<< '\n'
									 << pv_pca->at(i)->customerAddress()	<< '\n'
									 << pv_pca->at(i)->customerCity()		<< '\n'
									 << pv_pca->at(i)->customerState()		<< '\n'
									 << pv_pca->at(i)->customerZipCode()	<< '\n'
									 << pv_pca->at(i)->customerHomePhone()	<< '\n'
									 << pv_pca->at(i)->customerWorkPhone()	<< '\n'
									 << pv_pca->at(i)->customerPinNumber()	<< '\n'
									 << pv_pca->at(i)->balance()			<< flush;
						}

						cout << '\n' << ARCHIVE_COMPLETED << '\n' << endl;

						fout.close();
					}

					pauseScreen();
				}

				break;
			}
		default:
			{
				cerr << '\n' << ERROR_102 << '\n' << endl;

				pauseScreen();
			}
		} // end of switch
	}while(myChoice != EXIT_CODE);
}
///////////////////////////////////////////////////////////////