#pragma once


bool GetAccountList(string sFNAccounts, AccountInfo AccData[iTHRows]) {

    /*string sTemp;
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


        getline(sAccDetail, sTemp, ',');
        arrAccList[i].iAccountNum = atoi(sTemp.c_str())

        getline(sAccDetail, arrAccList[i].sName, ',');
        getline(sAccDetail, arrAccList[i].sAddress, ',');
        getline(sAccDetail, arrAccList[i].sState, ',');
        getline(sAccDetail, arrAccList[i].sZip, ',');
        getline(sAccDetail, arrAccList[i].sPhone, ',');
        getline(sAccDetail, arrAccList[i].sEMail, ',');



        i++;
        //sAccDetail = "";
    }

    fs.close();*/



	return true;
};


void PrintAccounts(AccountInfo AccData[iAccRows]) {
    cout << "| Index # | Account Number | Name | Address | State | Zip | Phone | E-Mail |" << endl;
    for (int r = 0; r < iAccRows; r++) {
        cout << r << ") "                               // Make sure to check if this print out a number > 1 or it will break the DeleteAcc() function (0 exits without change)
            << AccData[r].iAccountNum << " "
            << AccData[r].sName << " "
            << AccData[r].sAddress << " "
            << AccData[r].sState << " "
            << AccData[r].sZip << " "
            << AccData[r].sPhone << " "
            << AccData[r].sEMail << endl;        
    }
    cout << endl;
};