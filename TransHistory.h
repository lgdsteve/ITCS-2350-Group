#pragma once


bool GetTransHist() {



    return true;
};


void PrintTransHist(TransHist TransData[iTHRows]) {
    cout << "| # | Account Type | Date | Description | Balance Change | New Balance |" << endl;
    for (int r = 0; r < iAccRows; r++) {
        cout << r << ") "
            << TransData[r].sAccType << " "
            << TransData[r].sDate << " "
            << TransData[r].sDesc << " "
            << TransData[r].dChange << " "
            << TransData[r].dBalance << endl;
    }
    cout << endl;
};