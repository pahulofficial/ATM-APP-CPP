#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu(){
    cout << "WELCOME TO CRORE PATEEE BANK\n" << endl;
    cout << "**********MENU**********" << endl;

    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "************************" << endl;
}
bool account()
{
    int choose;
    fstream data;
    cout << "1.Register" << endl;
    cout << "2.Login" << endl;
    cout << "Choose 1 or 2: " << endl;

    cin >> choose;
    string username;// registeration username
    string password;// regusteration password

    if(choose == 1)
    {
        system("cls");
        cout << "REGISTER (MAKE YOUR ACCOUNT)" << endl;
        cout << "ENTER USERNAME : " << endl;
        cin >> username;
        cout << "MAKE A PASSWORD : " << endl; 
        cin >> password;

        data.open("data.txt", ios::out);//write
        if(data.is_open()){
            data << username << "\n";
            data << password << "\n";
            data.close();
        }else{
            cout << "Error occured " << endl;
        }
        cout << "ACCOUNT CREATED SUCCESSFULLY" << endl;
    }else if(choose == 2)
    {
        ifstream read;
        string user;
        string pass;

        system("cls");
        cout << "LOGIN TO YOUR ACCOUNT" << endl;
        cout << "Enter Username: ";
        cin >> user;
        
        cout << "Enter Password: ";
        cin >> pass;

        read.open("data.txt",ios::in);
        if(read.is_open())
        {
            string getData;
            string getPass;
            getline(read,getData);
            getline(read,getPass);
            if(user == getData && pass == getPass)
            {
                cout << "LOGIN SUCCESSFULLY" << endl;
            }
            else
            {
                cout << "WRONG PASSWORD" << endl;
                exit(0);
            }
        }else{
            cout << "FILE NOT FOUND" << endl; 
            exit(0);
        }

    }else{
        cout << "WRONG OPTION" << endl;
        exit(0);
    }
}

int main(){
    account();

    int option;
    double  Balance = 10;   
    
    do{
    // checkingAccount();
    menu();
    cout << "Option: ";
    cin >> option;
    system("cls");

    switch(option){
        case 1: cout << "Balance is " << Balance << "$" << endl;
        break;

        case 2: cout<< "Deposit amount: ";
            double depositAmount;

            cin >> depositAmount;
            Balance += depositAmount;
            cout<< "Total Balance = " << Balance << "$" << endl;
            break;
        
        case 3: cout << "Withdraw amount: ";
            double withdrawAmount;
            cin >> withdrawAmount;
            if(withdrawAmount<=Balance){
                Balance -= withdrawAmount;
                cout << "Total Balance = " << Balance << "$" << endl;
                
            }else{
                cout << "You don't have money fool!\n" << endl;
            }

            break;
    }
    }while(option!=4);

}
