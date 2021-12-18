// Group5_BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>
#include <cstdio>




using namespace std;

const string sFNAccounts = "AccountList.csv";
const string sFNTransHist = "TransactionHistory.csv";

const int iAccRows = 8;
const int iAccCols = 10;
const int iTHRows = 5;
const int iTHCols = 35;


struct AccountInfo {
    int     iAccountNum = 0;
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
    double dChange = 0.0;
    double dBalance = 0.0;
};


void ShowHeader() {
    int HEADERLEN = 60;           // White spacing for total header length (Width of program and text)
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



void MenuCmd() {
    cout << "Please enter selection: ";
}

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

bool GetAccountList(string sFNAccounts, AccountInfo AccData[iAccRows])
{
    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(sFNAccounts); // inpustStream will open the filename called BowlingScores.txt.

    while (inputStream.good()) // this while loop will only loop to check if the file is good.
    {
        for (int i = 0; i < iAccCols; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {
            inputStream >> AccData[i].iAccountNum; // inputs data into the Players array.

            for (int j = 0; j < iAccRows; j++) // this loop will each player and there 4 points for each round.
            {
                inputStream >> AccData[i].sName[j];
                inputStream >> AccData[i].sAddress[j];
                inputStream >> AccData[i].sState[j];
                inputStream >> AccData[i].sZip[j];
                inputStream >> AccData[i].sPhone[j];
                inputStream >> AccData[i].sEMail[j];
            }
        }
    }

    return true;
};


void PrintAccounts(AccountInfo AccData[iAccRows]) {
    cout << "| Index # | Account Number | Name | Address | District | State | Zip | Phone | E-Mail |" << endl;
    for (int i = 0; i < iAccRows; i++) {
        cout << i << ") "                               // Make sure to check if this print out a number > 1 or it will break the DeleteAcc() function (0 exits without change)
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

bool GetTransHist(string sFNTransHist, TransHist TransData[iTHRows])
{

    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(sFNTransHist); // inpustStream will open the filename called BowlingScores.txt.

    while (inputStream.good()) // this while loop will only loop to check if the file is good.
    {
        for (int i = 0; i < iTHCols; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {
            inputStream >> TransData[i].sAccType; // inputs data into the Players array.

            for (int j = 0; j < iTHRows; j++) // this loop will each player and there 4 points for each round.
            {
                inputStream >> TransData[i].sDate;
                inputStream >> TransData[i].sDesc;
                inputStream >> TransData[i].dChange;
                inputStream >> TransData[i].dBalance;

            }
        }
    }

    return true;
};


void PrintTransHist(TransHist TransData[iTHRows])
{
    cout << "| # | Account Type | Date | Description | Balance Change | New Balance |" << endl;
    for (int i = 0; i < iAccRows; i++) {
        cout << i << ") "
            << TransData[i].sAccType << " "
            << TransData[i].sDate << " "
            << TransData[i].sDesc << " "
            << TransData[i].dChange << " "
            << TransData[i].dBalance << endl;
    }
    cout << endl;
};

int CountAccLines(string sFNAccounts, int iAccNum) {
    ifstream fsAcc;
    fsAcc.open(sFNAccounts);
    string sA;

    if (!fsAcc) {
        cout << "File read error: " << sFNAccounts << endl;

    }
    while (!fsAcc.eof()) {
        getline(fsAcc, sA);
        iAccNum++;
    }
    fsAcc.close();
    iAccNum = iAccNum - 1;
    return iAccNum;
}

int CountTHLines(string sFNTransHist, int iTHNum) {
    ifstream fsTH;
    fsTH.open(sFNTransHist);
    string sT;

    if (!fsTH) {
        cout << "File read error: " << sFNTransHist << endl;

    }
    while (!fsTH.eof()) {
        getline(fsTH, sT);
        iTHNum++;
    }
    fsTH.close();
    iTHNum = iTHNum - 1;
    return iTHNum;

}

void DeleteAccount(string sFNAccounts, int iAccNum) {
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
    if (AccIndexNum < iAccNum && AccIndexNum > 0) {			// If the number is above 0 and less than the number of accounts..
        ifstream ifs(sFNAccounts);							// Open the accounts file as read only

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
        cout << "Entry must be a number and less than " << iAccNum << endl;
    }
}





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

    AccountInfo AccData[iAccRows];              // Initialize the data structure array for the Accounts List file
    TransHist TransData[iTHRows];               // Initialize the data structure array for the Transaction History file
    char cMenu = 'M';                           // Default menu option to show the menu on first run

    ShowHeader();

    while (toupper(cMenu) != 'Q') {                         // Stay in the loop unless the user enters Q/q to exit
        switch (toupper(cMenu)) {
        case 'M':                                           // User entered M (or first run by default)
            ShowMenu();                                     // Call the ShowMenu() function to display the menu options
            MenuCmd();                                      // MenuCmd() function to show the menu
            cin >> cMenu;                                   // Get the user's option
            break;                                          // Break the case to go back to the top of the loop
        case 'A':                                           // Function 1
            GetAccountList(sFNAccounts, AccData);         // Get the account list
            PrintAccounts(AccData);                                 // Print the accounts list
            MenuCmd();
            cin >> cMenu;
            break;
        case 'T':
            GetTransHist(sFNTransHist, TransData);                                  // Get transaction history
            PrintTransHist(TransData);                                // Print trasaction history for specific account
            MenuCmd();
            cin >> cMenu;
            break;
        case 'D':
            DeleteAccount(sFNAccounts, iAccNum);         // Delete account from AccountList.csv
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
