#pragma once

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>

using namespace std;

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
    //cout << "To purchase a surfboard press \'P\'" << endl;
    //cout << "To display current purc hases press \'C\'" << endl;
    //cout << "To display total amount due press \'T\'" << endl;
    cout << "Quit: \'Q\'" << endl << endl;

}