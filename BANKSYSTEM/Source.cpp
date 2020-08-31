#include<iostream>
#include <string.h>
using namespace std;

class Account {

public:
    int accountNumber;
    string givenName, lastName;
    double balance;


    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void setFirstName(string name) {
        givenName = name;
    }

    string getFirstName() {
        return givenName;
    }
    void setLastName(string surname) {
        lastName = surname;
    }

    string getLastName() {
        return lastName;
    }

    void setBalance(int bal) {
        balance = bal;
    }

    double getBalance() {
        return balance;
    }

    Account() { // Default Constructor

    }

    Account(int acc, string name, string surname, double bal) {      //Constructor with four paremeters
        accountNumber = acc;
        givenName = name;
        lastName = surname;
        balance = bal;
    }

    double readDouble()
    {
        double cinDouble;
        cin >> cinDouble;
        while (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << " Error: enter a numerical value" << endl;
            cin >> cinDouble;
        }
        return cinDouble;
    }


    void displayAll(Account acc[]) {
        string name;
        Account accc;
        int length = accc.size(acc);
        cout << "Account details : " << endl;
        for (int i = 0; i < length; i++) {
            //name = acc[i].getFirstName();
            cout << acc[i].getAccountNumber() << "," << acc[i].getFirstName() << "," << acc[i].getLastName() << "," << acc[i].getBalance() << endl;
        }
    }

    void sort(Account acc[]) {

        int choice;
        cout << "Enter 1 to sort using balance or 2 to sort using first name" << endl;
        cin >> choice;

        Account accc, accArr[100];
        int length = accc.size(acc);
        double temp;
        int accountNumber;
        string firstname, lastname;

        if (choice == 1) {
            for (int i = 0; i < length; i++) {                    // 0 to 6 if i =0 then j = 1
                for (int j = i + 1; j < length; j++) {            // 0th element compared with 1st element of array
                    if (acc[i].getBalance() > acc[j].getBalance()) {

                        temp = acc[i].getBalance();                // temp = acc[i];
                        acc[i].setBalance(acc[j].getBalance());    // acc[i] = acc[j];
                        acc[j].setBalance(temp);                  // acc[j] = temp;


                        accountNumber = acc[i].getAccountNumber();
                        acc[i].setAccountNumber(acc[j].getAccountNumber());
                        acc[j].setAccountNumber(accountNumber);

                        firstname = acc[i].getFirstName();
                        acc[i].setFirstName(acc[j].getFirstName());
                        acc[j].setFirstName(firstname);

                        lastname = acc[i].getLastName();
                        acc[i].setLastName(acc[j].getLastName());
                        acc[j].setLastName(lastname);

                    }
                }
            }
        }

        else if (choice == 2) {
            for (int i = 0; i < length; i++) {
                for (int j = i + 1; j < length; j++) {
                    if (acc[i].getFirstName() > acc[j].getFirstName()) {

                        temp = acc[i].getBalance();
                        acc[i].setBalance(acc[j].getBalance());
                        acc[j].setBalance(temp);


                        accountNumber = acc[i].getAccountNumber();
                        acc[i].setAccountNumber(acc[j].getAccountNumber());
                        acc[j].setAccountNumber(accountNumber);

                        firstname = acc[i].getFirstName();
                        acc[i].setFirstName(acc[j].getFirstName());
                        acc[j].setFirstName(firstname);

                        lastname = acc[i].getLastName();
                        acc[i].setLastName(acc[j].getLastName());
                        acc[j].setLastName(lastname);

                    }
                }
            }

        }

        else if (choice == 3) {
            for (int i = 0; i < length; i++) {
                for (int j = i + 1; j < length; j++) {
                    if (acc[i].getLastName() > acc[j].getLastName()) {

                        temp = acc[i].getBalance();
                        acc[i].setBalance(acc[j].getBalance());
                        acc[j].setBalance(temp);


                        accountNumber = acc[i].getAccountNumber();
                        acc[i].setAccountNumber(acc[j].getAccountNumber());
                        acc[j].setAccountNumber(accountNumber);

                        firstname = acc[i].getFirstName();
                        acc[i].setFirstName(acc[j].getFirstName());
                        acc[j].setFirstName(firstname);

                        lastname = acc[i].getLastName();
                        acc[i].setLastName(acc[j].getLastName());
                        acc[j].setLastName(lastname);

                    }
                }
            }

        }
        for (int i = 0; i < length; i++) {
            cout << acc[i].getAccountNumber() << "," << acc[i].getFirstName() << "," << acc[i].getLastName() << "," << acc[i].getBalance() << endl;
        }
    }

    void display(Account acc[]) {
        Account accc;
        int accountNumber, accnum;
        double amount;
        cout << "Enter your accountnumber :" << endl;     // Enter you acount number
        accountNumber = readInt();     //Validate an INT taking input from user
        if (accc.findAccount(acc, accountNumber)) {
            int index = accc.getIndexForDepositAndWithdraw(acc, accountNumber);    // give you the index at which 1002 is present
            cout << "Account details are as below : " << endl;
            cout << acc[index].getAccountNumber() << "," << acc[index].getFirstName() << "," << acc[index].getLastName() << "," << acc[index].getBalance() << endl;
        }
        else {
            cout << "Account number doesn't exists" << endl;
        }
    }

    int getIndexForAdd(Account acc[]) {
        string name;
        Account accc;
        int length = accc.size(acc);
        for (int i = 0; i < length + 1; i++) {
            name = acc[i].getFirstName();
            if (name == "") { //""       represents empty string
                return i;
            }
        }
    }

    int getIndexForDepositAndWithdraw(Account acc[], int accountNumber) {
        int accNum;
        Account accc;
        int length = accc.size(acc);
        for (int i = 0; i < length; i++) {
            accNum = acc[i].getAccountNumber();
            if (accNum == accountNumber) {         //1002 with 1002
                return i;
            }
        }
    }

    Account addAccount(Account acc[]) {           //return type
        Account accc;
        int accNum, index;
        double balance;
        string firstName, lastName, name;
        index = accc.getIndexForAdd(acc);              //index = 4
        cout << "\n Welcome Please enter the details prompted for :";
        cout << "\nEnter the Account Number : ";
        accNum = accc.readInt();
        if (accNum >= 10000 && accNum <= 10099) {
            if (!(accc.findAccount(acc, accNum)))
                acc[index].setAccountNumber(accNum);           // acc[4].setAccountNumber(accNum);
            else
                cout << "Account number already exists" << endl;
        }
        else {
            cout << " Please enter an Account number between 10000 and 10099" << endl;
        }
        cout << "\nEnter the First Name of the customer :";
        cin >> firstName; 
        acc[index].setFirstName(firstName);
        cout << "\nEnter the last Name of the customer :";
        cin >> lastName; 
        acc[index].setLastName(lastName);
        cout << "\nEnter the money deposited :$";
        balance = readDouble();
        acc[index].setBalance(balance);
        cout << "Account has been added successfully!!" << endl;
        cout << acc[index].getAccountNumber() << "," << acc[index].getFirstName() << "," << acc[index].getLastName() << "," << acc[index].getBalance() << endl;
        return acc[index];
    }

    void deposit(Account acc[]) {
        Account accc;
        int accountNumber, accnum;
        double amount;
        cout << "Enter your accountnumber :" << endl;
        accountNumber = readInt();
        if (accc.findAccount(acc, accountNumber)) {
            int index = accc.getIndexForDepositAndWithdraw(acc, accountNumber); //2
            double bal = acc[index].getBalance(); //200
            cout << "Enter the amount you wish to deposit : $";
            amount = readDouble();
            bal += amount; // 200 + 100 = 300
            cout << "\n$" << amount << "has been deposited successfully" << endl;
            acc[index].setBalance(bal);
            cout << "The Updated balance in this account is : $ " << acc[index].getBalance() << endl; //300 dollars
        }
        else {
            cout << "Account Number doesn't exists" << endl;
        }
    }

    void withdraw(Account acc[]) {
        Account accc;
        int accountNumber, accnum;
        double amount;
        cout << "Enter your accountnumber :" << endl;
        accountNumber = readInt();
        if (accc.findAccount(acc, accountNumber)) {
            int index = accc.getIndexForDepositAndWithdraw(acc, accountNumber);
            double bal = acc[index].getBalance();
            cout << "Enter the amount you wish to deposit : $";
            amount = readDouble();
            if (amount <= bal)
                bal -= amount;
            else
                cout << "Insufficient Funds" << endl;
            cout << "\n$" << amount << "has been deposited successfully" << endl;
            acc[index].setBalance(bal);
            cout << "The Updated balance in this account is : $ " << acc[index].getBalance() << endl;
        }
        else {
            cout << "Account Number doesn't exists" << endl;
        }
    }

    bool findAccount(Account acc[], int accNum) {
        int accountNumber, accnum;
        Account accc;
        int length = accc.size(acc);
        for (int i = 0; i < length; i++) {
            accnum = acc[i].getAccountNumber();
            if (accnum == accNum)
                return true;
            else
                return false;
        }
    }

    int readInt() {
        //Validating Integers

        int cinInt;
        cin >> cinInt;
        while (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << " Error: enter a numerical value" << endl;
            cout << "\n Enter Valid Account number : " << endl;
            cin >> cinInt;
        }
        return cinInt;
    }

    void options(Account accArr[], int action) {
        Account accc;
        switch (action) {
        case 1:
            accc.addAccount(accArr);
            break;
        case 2:
            accc.withdraw(accArr);
            break;
        case 3:
            accc.deposit(accArr);
            break;
        case 4:
            accc.display(accArr);
            break;
        case 5:
            accc.displayAll(accArr);
            break;
        case 6:
            accc.total(accArr);
            break;
        case 7:
            accc.average(accArr);
            break;
        case 8:
            accc.sort(accArr);
            break;
        case 9:
            cout << "We wish to see you again Bye!!" << endl;
            exit;
        }
    }
    double total(Account acc[]) {
        Account accc;
        int length = accc.size(acc);
        string name;
        double total = 0;
        for (int i = 0; i < length; i++) {
            total += acc[i].getBalance();
        }
        cout << "The total balance is :" << total << endl;
        return total;
    }

    void average(Account acc[]) {
        Account accc;
        int length = accc.size(acc);
        string name;
        double sum = accc.total(acc);
        int count = 0;
        for (int i = 0; i < length; i++) {
            count++;
        }
        cout << "The Average balance is :" << sum / count << endl;
    }

    int size(Account acc[]) {
        int count = 0;
        string name;
        for (int i = 0; i < 100; i++) {
            name = acc[i].getFirstName();
            if (!(name == ""))
                count++;
        }
        return count;
    }

};

int main()
{

    Account accArr[100];
    Account accc;            // creating an object for my Account class inorder to access the functions of account class
    accArr[0] = { 10000,"Jestin","Mathews",100000 };          //valid Account datatype
    accArr[1] = { 10001,"sumanth","Chintala",30000 };
    accArr[2] = { 10002,"sujji","Chintala",20000 };
    accArr[3] = { 10003,"vamsi","Krishna",10000 };
    accArr[4] = { 10004,"A","J",10000 };

    int length = accc.size(accArr); // This will fetch the size of the array
    int action;
    bool show = true;
    //write Those cout statements here related to bank
    while (show) {
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\tWELCOME TO JMKIVANAIM BANK OF CANADA" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\tMENU" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << " 1.Add Account \n 2.withdraw \n 3.Deposit \n 4.Display \n 5.Display All \n 6.Total Balance \n 7.Average \n 8.Sort \n 9.Exit" << endl;
        cout << "choose an action that you would you like to perform" << endl;
        cin >> action; //Validate an Int
        if (action == 9)
            show = false;
        else
            accc.options(accArr, action);
    }
}

