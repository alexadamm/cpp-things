#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct transaction {
    string date;
    string customer;
    string pCode;
    string pName;
    string unitQty;
    string unitPrice;
    string total;
} salesTransactions[10];

struct mobileSale {
    string code;
    string mobile;
    int unitQty = 0;
    int total = 0;
} mobileSales[4];

int main() {
    ifstream infile;
    infile.open("sales-transaction.txt");
    string line;

    for(int i=0;i < 10; i++ ){
        getline(infile, salesTransactions[i].date, ',');
        getline(infile, salesTransactions[i].customer, ',');
        getline(infile, salesTransactions[i].pCode, ',');
        getline(infile, salesTransactions[i].pName, ',');
        getline(infile, salesTransactions[i].unitQty, ',');
        getline(infile, salesTransactions[i].unitPrice, ',');
    }
    
    mobileSales[0].mobile = "Samsung";
    mobileSales[1].mobile = "Vivo";
    mobileSales[2].mobile = "I-Phone";
    mobileSales[3].mobile = "Nokia";

    for(int i=0; i<10; i++) {
        for (int j=0; j < 4; j++) {
            if (mobileSales[j].mobile == salesTransactions[i].pName) {
                mobileSales[j].code = salesTransactions[i].pCode;
                mobileSales[j].unitQty += stoi(salesTransactions[i].unitQty);
                mobileSales[j].total += stoi(salesTransactions[i].unitPrice) * stoi(salesTransactions[i].unitQty);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << mobileSales[i].code << " " << mobileSales[i].mobile << " " << mobileSales[i].unitQty << " " << mobileSales[i].total << endl;
    }
}