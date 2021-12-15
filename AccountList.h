#pragma once


bool GetAccountList(string sFNAccounts, AccountInfo arrAccList[]) {

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


void PrintAccounts() {

};