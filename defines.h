///////////////////////////////////////////////////////////////
// defines.h

///////////////////////////////////////////////////////////////
#pragma once
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
#define ACCOUNT_PREFIX				"100-15-101"

#define CLEAR_SCREEN				"cls"
#define PAUSE_SCREEN				"pause"

#define PROGRAM_TITLE				"Armond\'s Bank\n_____________"

#define EXCEPTION					"Exception: "
#define UNKNOWN_ERROR				"Unknown internal error!"

#define CHECKING_CODE				'C'
#define SAVING_CODE					'S'
#define CREATE_CODE					'N'
#define DEPOSIT_CODE				'D'
#define WITHDRAWAL_CODE				'W'
#define VIEW_CODE					'V'
#define EXIT_CODE					'X'
#define GO_BACK_CODE				'G'
#define ERASE_CODE					'E'
#define REMOVE_FILE_CODE			'R'
#define LOAD_FILE_CODE				'L'
#define ARCHIVE_FILE_CODE			'A'

#define CREATE_NEW_ACCOUNT			"(N) Create new account"
#define DEPOSIT_INTO_ACCOUNT		"(D) Deposit into account"
#define WITHDRAWAL_FROM_ACCOUNT		"(W) Withdraw from account"
#define VIEW_ACCOUNT				"(V) View account information"
#define ERASE_ACCOUNT				"(E) Erase account"
#define REMOVE_FILE					"(R) Remove File"
#define LOAD_FILE					"(L) Load accounts"
#define ARCHIVE_FILE				"(A) Archive accounts"
#define EXIT_PROGRAM				"(X) Exit Program"

#define ENTER_CHOICE				"Please choose an option: __\b\b"

#define IS_QUIT						"Are you sure you want to exit? (Y)es, (N)o: __\b\b"

#define WHAT_TYPE_OF_ACC			"(C)hecking, (S)aving account, or (G)o back? __\b\b"

#define ENTER_ACC_NUMBER			"Enter your account number or -1 to go back: ___\b\b\b"
#define ENTER_SSN					"Enter your social security number or -1 to go back: ___________\b\b\b\b\b\b\b\b\b\b\b"

#define OUTPUT_FILENAME				"Enter file name to output or -1 to go back: __________\b\b\b\b\b\b\b\b\b\b"
#define INPUT_FILENAME				"Enter file name to load data from or -1 to go back: __________\b\b\b\b\b\b\b\b\b\b"

#define FILE_TO_REMOVE				"Enter file name to delete or -1 to go back: __________\b\b\b\b\b\b\b\b\b\b"

#define ERROR_100					"Error 100: No such account, please try again!"
#define ERROR_101					"Error 101: No records active, please create a record!"
#define ERROR_102					"Error 102: Invalid entry, please try again!"
#define ERROR_103					"Error 103: File does not exist, please try again!"
#define ERROR_104					"Error 104: File could not be created!"
#define ERROR_105					"Error 105: File does not exist or could not be accessed!"
#define ERROR_106					"Error 106: Unable to locate account based on the given SSN!"
#define ERROR_107					"Error 107: Could not write to disk"

#define CHECKING_ACCOUNT			"Checking Account"
#define SAVING_ACCOUNT				"Saving Account"

#define ACCOUNT_TYPE				"Account Type         : "
#define ACCOUNT_NUMBER				"Account #            : "
#define SOCIAL_SECURITY_NUMBER		"Social Security #    : "
#define FULL_NAME					"Customer Full Name   : "
#define ADDRESS						"Full Address         : "
#define CITY						"City                 : "
#define STATE						"State                : "
#define ZIP_CODE					"Zip Code             : "
#define HOME_PHONE					"Home Phone           : "
#define WORK_PHONE					"Work Phone           : "
#define BALANCE						"Balance              : $"

#define INSUFFICIENT_FUNDS			"Insufficient funds, please try again!"

#define RECORD_ERASED				"Record has been successfully erased!"
#define ARCHIVE_COMPLETED			"Record(s) have been successfully archived!"
#define LOAD_COMPLETED				"Record(s) have been successfully loaded!"
#define FILE_REMOVED				"File has been successfully removed!"

#define HOW_MUCH_WITHDRAWAL			"How much would you like to withdrawal or -1 to go back: $_______\b\b\b\b\b\b\b"
#define HOW_MUCH_DEPOSIT			"How much would you like to deposit or -1 to go back: $_______\b\b\b\b\b\b\b"

#define CUSTOMERS_ACCOUNT_NUMBER	"Customers account number     : "

#define ENTER_SOCIAL_SECURITY		"Enter customer\'s Social      : ___________\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_CUSTOMERS_FULL_NAME	"Enter customer\'s full name   : ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
#define	ENTER_ADDRESS				"Enter customer\'s address     : ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_CITY					"Enter customer\'s city        : __________\b\b\b\b\b\b\b\b\b\b"
#define ENTER_STATE					"Enter customer\'s state       : __\b\b"
#define ENTER_ZIP_CODE				"Enter customer\'s zip code    : _____\b\b\b\b\b"
#define ENTER_HOME_PHONE			"Enter customer\'s home phone  : ____________\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_WORK_PHONE			"Enter customer\'s work phone  : ____________\b\b\b\b\b\b\b\b\b\b\b\b"
#define ENTER_PIN					"Enter a four digit pin #     : ____\b\b\b\b"
#define ENTER_INITIAL_BALANCE		"Enter initial deposit amount : $_______\b\b\b\b\b\b\b"

#define DATA_DIRECTORY				"UserData"
#define CONFIG_DIRECTORY			"ConfigData"
#define TEMP_DIRECTORY				"Temp"
#define BACKUP_DIRECTORY			"Backup"

#define TRUE						'Y'
#define FALSE						'N'

#define	RECORD_FOUND				999
#define RECORD_NOT_FOUND			-999

#define MENU_BORDER					"(\\/*********************************\\/)"
#define MENU_BORDER_2				"(\\/*****-_ACCOUNT-INFORMATION_-*****\\/)"
///////////////////////////////////////////////////////////////