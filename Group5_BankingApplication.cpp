// Group5_BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>
#include "Header.h"
#include "LayoutFuncs.h"
#include "CountFileRows.h"
#include "AccountList.h"
#include "TransHistory.h"
#include "DeleteAcc.h"




const string sFNAccounts = "AccountList.csv";
const string sFNTransHist = "TransactionHistory.csv";

const int iAccRows = 10;
const int iAccCols = 6;
const int iTHRows = 35;
const int iTHCols = 5;


struct AccountInfo {
    int     iAccountNum;
    string  sName;
    string  sAddress;
    string  sState;
    string  sZip;
    string  sPhone;
    string  sEMail;
};

struct TransData {
    string sAccType;
    string sDate;
    string sDesc;
    double dChange;
    double dBalance;
};



int main()
{
    // Declare variables to count the rows in the files
    int iAccNum = 0;
    int iTHNum = 0;
    iAccNum = CountAccLines(sFNAccounts, iAccNum);      // Call the functions to count the rows and return the value.
    iTHNum = CountTHLines(sFNTransHist, iTHNum);        // These values will be passed into other functions (like DeleteAccount() function)

    // FOR DEBUG PURPOSES
    //cout << "Accounts: " << iAccNum << endl;
    //cout << "Transact: " << iTHNum << endl << endl;

    AccountInfo arrAccList[iAccRows];
    TransData arrTransHist[iTHRows];
    char cMenu = 'M';
    
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
            // PrintAccounts();                                 // Print the accounts list
            MenuCmd();
            cin >> cMenu;
            break;
        case 'T':
            // GetTransHist();                                  // Get transaction history
            // PrintTransHist();                                // Print trasaction history for specific account
            MenuCmd();
            cin >> cMenu;
            break;
        case 'D':
            DeleteAccount("AccountList.csv", sFNAccounts, iAccNum);         // Delete account from AccountList.csv
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



