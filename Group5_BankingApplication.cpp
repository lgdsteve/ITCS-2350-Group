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




const string sFNAccounts = "AccountList.csv";
const int iAccCols = 6;
struct AccountInfo {
    int     iAccountNum = 0;
    string  sName;
    string  sAddress;
    string  sState;
    string  sZip;
    string  sPhone;
    string  sEMail;
};

const string sFNTransHist = "TransactionHistory.csv";
struct TransData {
    string sAccType;
    string sDate;
    string sDesc;
    double dChange;
    double dBalance;
};



bool GetAccountList(string sFNAccounts, AccountInfo arrAccList[]) {
    ifstream fs;
    fs.open(sFNAccounts);
    if (!fs) {
        cout << "Error reading file: " << sFNAccounts << endl;
        return false;
    }
    int i = 0;
    string sAccDetail;

    while (getline(fs, sAccDetail)) {

        stringstream inputString(sAccDetail);
        //getline(sAccDetail, arrAccList[i].iAccountNum, ',');
        //getline(sAccDetail, arrAccList[i].sName, ',');
        //getline(sAccDetail, arrAccList[i].sAddress, ',');
        //getline(sAccDetail, arrAccList[i].sState, ',');
        //getline(sAccDetail, arrAccList[i].sZip, ',');
        //getline(sAccDetail, arrAccList[i].sPhone, ',');
        //getline(sAccDetail, arrAccList[i].sEMail, ',');

        i++;
        sAccDetail = "";
    }

    /*while (fs.good()) {
        getline(fs, sAccDetail, ',');
    }
    while (!fs.eof()) {

       


        fs >> arrAccList[i].iAccountNum;
        for (int c = 0; c < iAccCols; c++) {

        }
    }*/
    fs.close();
}; 





int main()
{
    int iAccNum = 0;
    int iTHNum = 0;
    iAccNum = CountAccLines(sFNAccounts, iAccNum);
    iTHNum = CountTHLines(sFNTransHist, iTHNum);
   
    cout << "Accounts: " << iAccNum << endl;
    cout << "Transact: " << iTHNum << endl << endl;

    AccountInfo arrAccList[10];
    char cMenu = 'M';

    ShowHeader();

    while (toupper(cMenu) != 'Q') {  // Stay in the loop unless the user enters Q/q to exit
        switch (toupper(cMenu)) {
        case 'M':               // User entered M (or first run by default)
            ShowMenu();            // Call the ShowMenu() function to display the menu options
            MenuCmd();             // MenuCmd() function to show the menu
            cin >> cMenu;            // Get the user's option
            break;                  // Break the case to go back to the top of the loop
        case 'A':                       // Function 1
            //GetAccountList(sFNAccounts, arrAccList);
            MenuCmd();
            cin >> cMenu;
            break;
        case '2':                       // Function 2
            //Function2();
            MenuCmd();
            cin >> cMenu;
            break;
        case '3':                       // Function 3
            //Function3();
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
    system("pause");                // Pause and end the program
    return 0;
}



