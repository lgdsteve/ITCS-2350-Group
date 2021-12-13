#pragma once

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>

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