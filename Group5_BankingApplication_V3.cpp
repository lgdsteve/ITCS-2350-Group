// Group5_BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>
#include "Header.h"
#include "LayoutFuncs.h"



using namespace std;


struct AccountInfo {
    string  iAccountNum;
    string  sName;
    string  sAddress;
    string  sDistrict;
    string  sState;
    string  sZip;
    string  sPhone;
    string  sEMail;
};

struct TransHist {
    string sAccType;
    string sDate;
    string sDesc;
    string dChange;
    string dBalance;
};

bool GetAccountList(string sFNAccounts, AccountInfo AccData[], int iAccSize)
{
    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(sFNAccounts); // inpustStream will open the filename called BowlingScores.txt.

    if (inputStream.is_open()) // this while loop will only loop to check if the file is good.
    {
        for (int i = 0; i < iAccSize; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {

            getline(inputStream, AccData[i].iAccountNum, ',');
            getline(inputStream, AccData[i].sName, ',');
            getline(inputStream, AccData[i].sAddress, ',');
            getline(inputStream, AccData[i].sState, ',');
            getline(inputStream, AccData[i].sZip, ',');
            getline(inputStream, AccData[i].sPhone, ',');
            getline(inputStream, AccData[i].sEMail);
        }
    }

    return true;
};


void PrintAccounts(AccountInfo AccData[], int iAccSize) {
    cout << "| Index # | Account Number | Name | Address | District | State | Zip | Phone | E-Mail |" << endl;
    for (int i = 0; i < iAccSize; i++) {
        cout << i + 1 << ") "                               // Make sure to check if this print out a number > 1 or it will break the DeleteAcc() function (0 exits without change)
            << AccData[i].iAccountNum << " "
            << AccData[i].sName << " "
            << AccData[i].sAddress << " "
            << AccData[i].sState << " "
            << AccData[i].sZip << " "
            << AccData[i].sPhone << " "
            << AccData[i].sEMail << endl;
    }
    cout << endl;
};

bool GetTransHist(string sFNTransHist, TransHist TransData[], int iTHsize)
{

    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(sFNTransHist); // inpustStream will open the filename called BowlingScores.txt.

    while (inputStream.good()) // this while loop will only loop to check if the file is good.
    {
        for (int i = 0; i < iTHsize; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {
            getline(inputStream, TransData[i].sAccType, ',');
            getline(inputStream, TransData[i].sDate, ',');
            getline(inputStream, TransData[i].sDesc, ',');
            getline(inputStream, TransData[i].dChange, ',');
            getline(inputStream, TransData[i].dBalance);

        }
    }

    return true;
};


void PrintTransHist(TransHist TransData[], int iAccRows)
{
    cout << "| # | Account Type | Date | Description | Balance Change | New Balance |" << endl;
    for (int i = 0; i < iAccRows; i++) {
        cout << i + 1 << ") "
            << TransData[i].sAccType << " "
            << TransData[i].sDate << " "
            << TransData[i].sDesc << " "
            << TransData[i].dChange << " "
            << TransData[i].dBalance << endl;
    }
    cout << endl;
};

int CountAccLines(string sFNAccounts, int iAccSize) {
    ifstream fsAcc;
    fsAcc.open(sFNAccounts);
    string sA;

    if (!fsAcc) {
        cout << "File read error: " << sFNAccounts << endl;

    }
    while (!fsAcc.eof()) {
        getline(fsAcc, sA);
        iAccSize++;
    }
    fsAcc.close();
    iAccSize = iAccSize - 1;
    return iAccSize;
}

int CountTHLines(string sFNTransHist, int iTHSize) {
    ifstream fsTH;
    fsTH.open(sFNTransHist);
    string sT;

    if (!fsTH) {
        cout << "File read error: " << sFNTransHist << endl;

    }
    while (!fsTH.eof()) {
        getline(fsTH, sT);
        iTHSize++;
    }
    fsTH.close();
    iTHSize = iTHSize - 1;
    return iTHSize;

}

int DeleteAccount(const char* file_name, string sFNAccounts, int iAccSize) {
    int AccIndexNum = 0;								// Account to be deleted
    char c;												// char c will be the character retrieved from the AccountsList file
    int iLineNum = 1;									// Current line number

    // Print warning message and get the account number (as an index number) to delete 
    cout << "WARNING! This will perminently delete the account!" << endl;
    cout << "Enter the Index Number from the accounts list or 0 to exit: ";
    cin >> AccIndexNum;
    cout << endl;

    //Validate the entry and run the function
    if (AccIndexNum < iAccSize && AccIndexNum > 0) {			// If the number is above 0 and less than the number of accounts..
        ifstream ifs(sFNAccounts);							// Open the accounts file as read only

        ofstream ofs;										// Create the temp file to save changes to
        ofs.open("temp.txt", ofstream::out);					// and write the contents to the temp file.

        while (ifs.get(c)) {								// Get the current character (c). We're looking for the line number to delete (AccIndexNum)
            if (c == '\n') {								// If it's the end of line (\n)..
                iLineNum++;									// Increment the iLineNum to move to the next line.
            }
            if (iLineNum != AccIndexNum) {					// If the current line does not match the user supplied line 
                ofs << c;									// Get the new character from the file.
            }
        }

        ofs.close();										// Close the temp file
        ifs.close();										// Close the AccountsList file

        remove(file_name);									// Delete old AccountsList file
        rename("temp.txt", file_name);						// Rename the temp file to AccountList
        remove("temp.txt");									// Delete the temp file

        // Print successful deletion of record to the user
        cout << "Account record number " << AccIndexNum << " has been successfully deleted." << endl << endl;

        // Decrease size of array by 1
        iAccSize = iAccSize - 1;
    }
    else if (AccIndexNum == 0) {							// If the user entered 0, then return to the main menu without changes
        cout << "Returning to main menu..." << endl << endl;
    }
    else {													// Any other entry, break the function without changes.
        cout << "Entry must be a number and less than " << iAccSize << endl;
    }

    return iAccSize;
}





int main()
{
    // Declare constants
    const int I_ACC_SIZE = 20;
    const int I_TH_SIZE = 35;

    const string S_ACC_NAME = "AccountListCopy.csv";
    const string S_TH_NAME = "TransactionHistory.csv";

    // Declare variables to count the rows in the files
    int iAccSize = 0;
    int iTHSize = 0;

    iAccSize = CountAccLines(S_ACC_NAME, iAccSize);      // Call the functions to count the rows and return the value.
    iTHSize = CountTHLines(S_TH_NAME, iTHSize);        // These values will be passed into other functions (like DeleteAccount() function)

    // FOR DEBUG PURPOSES
    //cout << "Accounts: " << iAccSize << endl;
    //cout << "Transact: " << iTHSize << endl << endl;

    AccountInfo AccData[I_ACC_SIZE];              // Initialize the data structure array for the Accounts List file
    TransHist TransData[I_TH_SIZE];               // Initialize the data structure array for the Transaction History file

    GetAccountList(S_ACC_NAME, AccData, iAccSize);
    GetTransHist(S_TH_NAME, TransData, iTHSize);
    cout << AccData[0].iAccountNum << endl;
    char cMenu = 'M';                           // Default menu option to show the menu on first run

    cout << fixed;

    ShowHeader();

    while (toupper(cMenu) != 'Q') {                         // Stay in the loop unless the user enters Q/q to exit
        switch (toupper(cMenu)) {
        case 'M':                                           // User entered M (or first run by default)
            ShowMenu();                                     // Call the ShowMenu() function to display the menu options
            MenuCmd();                                      // MenuCmd() function to show the menu
            cin >> cMenu;                                   // Get the user's option
            break;                                          // Break the case to go back to the top of the loop
        case 'A':                                           // Function 1
            // GetAccountList(sFNAccounts, arrAccList);         // Get the account list
            PrintAccounts(AccData, iAccSize);                                 // Print the accounts list
            MenuCmd();
            cin >> cMenu;
            break;
        case 'T':
            // GetTransHist();                                  // Get transaction history
            PrintTransHist(TransData, iTHSize);                                // Print trasaction history for specific account
            MenuCmd();
            cin >> cMenu;
            break;
        case 'D':
            iAccSize = DeleteAccount("AccountListCopy.csv", S_ACC_NAME, iAccSize);         // Delete account from AccountList.csv
            GetAccountList(S_ACC_NAME, AccData, iAccSize);
            MenuCmd();
            cin >> cMenu;
            break;
        case 'Q':                       // Quit Program
            cout << "Thank you" << endl;
            break;
        default:                        // Bad entry, try again.
            cout << "Invalid entry: " << toupper(cMenu) << endl;
            MenuCmd();
            cin >> cMenu;
            break;
        }

    }



    cout << "Thank you!" << endl;    // User has entered Q/q to quit resulting in the loop ending
    system("pause");                 // Pause and end the program
    return 0;
}
