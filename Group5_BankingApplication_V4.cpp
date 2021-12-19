// Group5_BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>
#include <cstdio>           // For rename() function

using namespace std;

// Account Info Structure
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

// Transaction History Structure
struct TransHist {
    string sAccType;
    string sDate;
    string sDesc;
    string dChange;
    string dBalance;
};

/******************************************** Show Header *************************************************/
void ShowHeader() {
    int HEADERLEN = 100;           // White spacing for total header length (Width of program and text)
    string MSGHeader = " ACME Banking Administrator System ";
    int MSGHeaderLen = static_cast<int>(MSGHeader.length());
    // Declare and figure out how man astrisks to put on the left and right side of the header text
    int FillLen = HEADERLEN - MSGHeaderLen;
    int FillSide = FillLen / 2;
    string Fill(FillSide, '*');

    // Build the Program Header
    cout << setfill('*');                               // Sets filler to astrisks
    cout << setw(HEADERLEN) << "" << endl;              // Astrisks on the top
    cout << setw(static_cast<std::streamsize>(MSGHeaderLen) + FillSide) << right << MSGHeader << Fill << endl; // Left astrisks, Program title, right astrisks
    cout << setw(HEADERLEN) << "" << endl << endl;      // Astrisks on the bottom

}

/******************************************** Menu Command *************************************************/
void MenuCmd() {
    cout << "Please enter selection: ";
}

/******************************************** Show Menu *************************************************/
void ShowMenu()
{
    // Simple text menu of section options
    cout << "Please select one of the following options..." << endl;
    cout << "Show menu: \'M\'" << endl;
    cout << "Show Accounts: \'A\'" << endl;
    cout << "Show Transaction History: \'T\'" << endl;
    cout << "Delete an Account: \'D\'" << endl;
    cout << "Quit: \'Q\'" << endl << endl;

}

/******************************************** Get Accounts List *************************************************/
bool GetAccountList(string sFNAccounts, AccountInfo AccData[], int iAccSize) {
    ifstream inputStream;                                           // Initialize the file stream.    
    inputStream.open(sFNAccounts);                                  // Open input file stream
    if (inputStream.is_open()) {                                    // If the inputstream opened..
        for (int i = 0; i < iAccSize; i++) {                        // Iterate through the rows in the file and enter data into the struct
            getline(inputStream, AccData[i].iAccountNum, ',');
            getline(inputStream, AccData[i].sName, ',');            // Get the current line from inputStream, enter the data and..
            getline(inputStream, AccData[i].sAddress, ',');         // use commas and the delineator between data sets.
            getline(inputStream, AccData[i].sState, ',');
            getline(inputStream, AccData[i].sZip, ',');
            getline(inputStream, AccData[i].sPhone, ',');
            getline(inputStream, AccData[i].sEMail);
        }
    }
    return true;
};

/******************************************** Print Accounts List *************************************************/
void PrintAccounts(AccountInfo AccData[], int iAccSize) {
    cout << "| # | Account Number | Name | Address | District | State | Zip | Phone | E-Mail |" << endl;
    for (int i = 0; i < iAccSize; i++) {
        cout << i + 1 << ") | "                         // Print index number + 1 to adjust so the first number isn t 0.
            << AccData[i].iAccountNum << " | "          // Account Number
            << AccData[i].sName << " | "                // Account Holder Name
            << AccData[i].sAddress << " | "             // Address
            << AccData[i].sState << " | "               // State
            << AccData[i].sZip << " | "                 // Zip
            << AccData[i].sPhone << " | "               // Phone
            << AccData[i].sEMail << endl;               // E-Mail and new line
    }
    cout << endl;
};

/******************************************** Get Transaction History *************************************************/
bool GetTransHist(string sFNTransHist, TransHist TransData[], int iTHsize) {
    ifstream inputStream;                           // Initialize the file stream
    inputStream.open(sFNTransHist);                 // Open the file
    while (inputStream.good()) {                    // If the file opened...
        for (int i = 0; i < iTHsize; i++) {         // Iterate through the file and get the lines
            getline(inputStream, TransData[i].sAccType, ',');
            getline(inputStream, TransData[i].sDate, ',');          // Get the current line from inputStream, enter the data and ..
            getline(inputStream, TransData[i].sDesc, ',');          // use commas and the delineator between data sets.
            getline(inputStream, TransData[i].dChange, ',');
            getline(inputStream, TransData[i].dBalance);
        }
    }
    return true;
};

/******************************************** Pring Transaction History *************************************************/
void PrintTransHist(TransHist TransData[], int iAccRows) {
    cout << "| # | Account Type | Date | Description | Balance Change | New Balance |" << endl;
    for (int i = 0; i < iAccRows; i++) {
        cout << i + 1 << ") | "                         // Print index number + 1 to adjust so the first number isn t 0
            << TransData[i].sAccType << " | "           // Account Type
            << TransData[i].sDate << " | "              // Transaction Date
            << TransData[i].sDesc << " | $"             // Description
            << TransData[i].dChange << " | $"           // Balance Change
            << TransData[i].dBalance << endl;           // New Balance
    }
    cout << endl;
};

/******************************************** Count Account Lines *************************************************/
int CountAccLines(string sFNAccounts, int iAccSize) {
    ifstream fsAcc;                 // Initialize the file stream
    fsAcc.open(sFNAccounts);        // Open the file
    string sA;                      // Dummty string to hold data

    if (!fsAcc) {                   // Check if file is opened, print error if not
        cout << "File read error: " << sFNAccounts << endl;

    }
    while (!fsAcc.eof()) {          // While there is no end of file
        getline(fsAcc, sA);         // Get the line..
        iAccSize++;                 // Count the line
    }
    fsAcc.close();                  // Close the file
    iAccSize = iAccSize - 1;        // Adjust the number of lines to account for the array
    return iAccSize;                // Return the total number of lines
}

/******************************************** Count Transaction Lines *************************************************/
int CountTHLines(string sFNTransHist, int iTHSize) {
    ifstream fsTH;                  // Initialize file stream
    fsTH.open(sFNTransHist);        // Open the file
    string sT;                      // Dummy string to hold data

    if (!fsTH) {                    // Check if the file opened, print error if not
        cout << "File read error: " << sFNTransHist << endl;

    }
    while (!fsTH.eof()) {           // While there is no end of file
        getline(fsTH, sT);          // Get the line
        iTHSize++;                  // Count the line
    }
    fsTH.close();                   // Close the file
    iTHSize = iTHSize - 1;          // Adjust the number of lines to account for the array
    return iTHSize;                 // Return the total number of lines
}

/******************************************** Delete Account *************************************************/
void DeleteAccount(string S_ACC_NAME, int iAccSize) {
    int AccIndexNum = 0;								// Account to be deleted
    char c;												// char c will be the character retrieved from the AccountsList file
    int iLineNum = 1;									// Current line number

    string sFNTemp = "temp.txt";                        // Temp file name as string
    char cFNTemp[] = "temp.txt";                        // Temp file name as char array
    char cFNAccounts[] = "AccountList.csv";             // Account List as char array for rename (line 239)

    // Print warning message and get the account number (as an index number) to delete 
    cout << "WARNING! This will perminently delete the account!" << endl;
    cout << "Enter the Index Number from the accounts list or 0 to exit: ";
    cin >> AccIndexNum;
    cout << endl;

    //Validate the entry and run the function
    if (AccIndexNum < iAccSize && AccIndexNum > 0) {			// If the number is above 0 and less than the number of accounts..
        ifstream ifs(S_ACC_NAME);							// Open the accounts file as read only

        ofstream ofs;										// Create the temp file to save changes to
        ofs.open(sFNTemp, ofstream::out);					// and write the contents to the temp file.

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

        remove(cFNAccounts);							    // Delete old AccountsList file

        if (rename(cFNTemp, cFNAccounts) != 0) {            // Rename the temp file to AccountList
            perror("Error Renaming File");
        };

        remove(cFNTemp);									// Delete the temp file

        // Print successful deletion of record to the user
        cout << "Account record number " << AccIndexNum << " has been successfully deleted." << endl << endl;
    }
    else if (AccIndexNum == 0) {							// If the user entered 0, then return to the main menu without changes
        cout << "Returning to main menu..." << endl << endl;
    }
    else {													// Any other entry, break the function without changes.
        cout << "Entry must be a number and less than " << iAccSize << endl;
    }
}

/******************************************** Main *************************************************/
int main()
{
    // Declare const
    const int I_ACC_SIZE = 20;
    const int I_TH_SIZE = 35;

    // Declare variables to count the rows in the files
    int iAccSize = 0;
    int iTHSize = 0;

    const string S_ACC_NAME = "AccountList.csv";
    const string S_TH_NAME = "TransactionHistory.csv";

    iAccSize = CountAccLines(S_ACC_NAME, iAccSize);         // Call the functions to count the rows and return the value.
    iTHSize = CountTHLines(S_TH_NAME, iTHSize);             // These values will be passed into other functions (like DeleteAccount() function)

    AccountInfo AccData[I_ACC_SIZE];                // Initialize the data structure array for the Accounts List file
    TransHist TransData[I_TH_SIZE];                 // Initialize the data structure array for the Transaction History file    
    
    char cMenu = 'M';                               // Default menu option to show the menu on first run

    cout << fixed;

    ShowHeader();                                   // Print header

    while (toupper(cMenu) != 'Q') {                         // Stay in the loop unless the user enters Q/q to exit
        switch (toupper(cMenu)) {
        case 'M':                                           // User entered M (or first run by default)
            ShowMenu();                                     // Call the ShowMenu() function to display the menu options
            MenuCmd();                                      // MenuCmd() function to show the menu
            cin >> cMenu;                                   // Get the user's option
            break;                                          // Break the case to go back to the top of the loop
        case 'A':                                           // Function 1
            GetAccountList(S_ACC_NAME, AccData, iAccSize);
            PrintAccounts(AccData, iAccSize);                                 // Print the accounts list
            MenuCmd();
            cin >> cMenu;
            break;
        case 'T':
            GetTransHist(S_TH_NAME, TransData, iTHSize);
            PrintTransHist(TransData, iTHSize);                                // Print trasaction history for specific account
            MenuCmd();
            cin >> cMenu;
            break;
        case 'D':
            DeleteAccount(S_ACC_NAME, iAccSize);         // Delete account from AccountList.csv
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
