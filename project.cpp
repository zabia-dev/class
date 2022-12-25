#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cstring>

using namespace std;

#define clear system("cls");

int accountNumber = 101;
int size = 0, auth[2] = {0};

/*
* Custom data type for storing user information
*/

struct Statement {
    int type;
    int starting;
    int amount;
    int ending;
};

struct User {
    int acn;
    int stp = 0;
    int balance;
    string name;
    string email;
    string phone;
    string password;
    Statement statement[100];
} userData[100];

/*
* This menu function prints all the initial options for user
*/
int menu() {
    int choice; clear; cout << "**********************************************\n";
    if (auth[0] == 0) {
        cout << "*       Welcome to Bank of Munshigonj        *\n";
        cout << "**********************************************\n";
        cout << "*  1. Login                                  *\n";
        cout << "*  2. Create an account                      *\n";
        cout << "*  3. Exit                                   *\n";
        cout << "*                                            *\n";
        cout << "*  Enter your choice -> ";
        cin >> choice;
        if(choice==3)
            return 0;
        return choice;
    } else {
        cout << "*       Welcome to Bank of Munshigonj        *\n";
        cout << "**********************************************\n";
        cout << "*                                            *\n";
        cout << "*\tWelcome, " << userData[auth[1]].name << endl;
        cout << "*                                            *\n";
        cout << "*  1. Check Balance                          *\n";
        cout << "*  2. Deposit Money                          *\n";
        cout << "*  3. Withdraw Money                         *\n";
        cout << "*  4. Change Password                        *\n";
        cout << "*  5. Check Statement                        *\n";
        cout << "*  6. Delete Account                         *\n";
        cout << "*  7. Logout                                 *\n";
        cout << "*  8. Exit                                   *\n";
        cout << "*                                            *\n";
        cout << "*  Enter your choice -> ";
        cin >> choice;
        if(choice==8)
            return 0;
        return choice;
    }
}

/*
* This function checks if the user have permission to access
*/
void logIn() {
    string email, password;
    clear;
    cout << "**********************************************\n";
    cout << "*                  Login to                 *\n";
    cout << "**********************************************\n";
    cout << "* Enter your email -> ";
    cin >> email;
    cout << "* Enter your password -> ";
    cin >> password;
    for(int i = 0; i < size; i++) {
        if (userData[i].email == email) {
            if (userData[i].password == password) {
                auth[0] = 1;
                auth[1] = i;
                return;
            } else {
                char inp;
                clear;
                cout << "**********************************************\n";
                cout << "*               Wrong password              *\n";
                cout << "*            Enter T to try again           *\n";
                cout << "**********************************************\n";
                cout << "*  Enter your choice -> ";
                cin >> inp;
                if (inp == 'T' || inp =='t')
                    logIn();
                return;
            }
        }
    }

    char inp;
    clear;
    cout << "**********************************************\n";
    cout << "*              No account found             *\n";
    cout << "*            Enter T to try again           *\n";
    cout << "**********************************************\n";
    cout << "*  Enter your choice -> ";
    cin >> inp;
    if (inp == 'T' || inp =='t')
        logIn();
}

/*
* This function creates a new user account
*/
void signUp() {
    string name, email, number, password;
    clear;
    cout << "**********************************************\n";
    cout << "*              Create an account             *\n";
    cout << "**********************************************\n";
    cout << "* Enter your name -> ";
    cin >> name;
    cout << "* Enter your email -> ";
    cin >> email;
    cout << "* Enter your number -> ";
    cin >> number;
    cout << "* Enter your password -> ";
    cin >> password;
    for(int i = 0; i < size; i++) {
        if (userData[i].email == email) {
            char inp; clear; cout << "**********************************************\n";
            cout << "*            Email already exist            *\n";
            cout << "*            Enter T to try again           *\n";
            cout << "**********************************************\n";
            cout << "*  Enter your choice -> ";
            cin >> inp;
            if (inp == 'T' || inp =='t')
                signUp();
            return;
        }
    }
    userData[size].name = name;
    userData[size].email = email;
    userData[size].phone = number;
    userData[size].acn = accountNumber;
    userData[size].password = password;
    auth[0] = 1;
    auth[1] = size;
    accountNumber++;
    size++;
}

/*
* This function decides with function to call when user choose
* an option (for un authenticated users only)
*/
void initial(int choice) {
    switch(choice) {
        case 1:
            logIn();
            break;
        case 2:
            signUp();
            break;
    }
}

/*
* This function check the balance from array named 'userData'
* and use auth[1] value for the user data location in array
*/
void checkBalance() {
    clear; cout << "**********************************************\n";
    cout << "*       Welcome to Bank of Munshigonj        *\n";
    cout << "**********************************************\n";
    cout << "*                                            *\n";
    cout << "* Your current balance is -> " << userData[auth[1]].balance << " TAKA";
    cout << "\n*                                            *\n";
    cout << "**********************************************\n";
    cout << "\nEnter any key to continue...";
    getch();
}

/*
* This function changes the password in array named 'userData'
* and use auth[1] value for the user data location in array
*/
void changePassword() {
    string password;
    clear; cout << "**********************************************\n";
    cout << "*           Change your password             *\n";
    cout << "**********************************************\n";
    cout << "*                                            *\n";
    cout << "* Enter your current password -> ";
    cin >> password;
    cout << "*                                            *\n";
    if (userData[auth[1]].password == password) {
        cout << "* Enter new password -> ";
        cin >> password;
        userData[auth[1]].password.assign(password);
        cout << "*                                            *\n";
        cout << "*       Password changed successfully        *\n";
        cout << "*                                            *\n";
        cout << "\nEnter any key to continue...";
    } else
        cout << "* Password miss match !";
    getch();
}

void deposite() {
    int amount;
    clear; cout << "**********************************************\n";
    cout << "*             Deposit some money             *\n";
    cout << "**********************************************\n";
    cout << "* Enter amount to deposit -> ";
    cin >> amount;
    if (amount < 1) {
        clear;
        cout << "\n* Amount cannot be 0 or less.";
        cout << "\n* Press any key to continue...";
        getch();
        return;
    }
    int pos = userData[auth[1]].stp;
    userData[auth[1]].statement[pos].amount = amount;
    userData[auth[1]].statement[pos].type = 0;
    userData[auth[1]].statement[pos].starting = userData[auth[1]].balance;
    userData[auth[1]].balance += amount;
    userData[auth[1]].statement[pos].ending = userData[auth[1]].balance;
    userData[auth[1]].stp++;
}

void withdraw() {
    int amount;
    clear; cout << "**********************************************\n";
    cout << "*            Withdraw some money             *\n";
    cout << "**********************************************\n";
    cout << "* Enter amount to withdraw -> ";
    cin >> amount;
    if (amount < 1) {
        clear;
        cout << "\n* Amount cannot be 0 or less.";
        cout << "\n* Press any key to continue...";
        getch();
        return;
    }

    int pos = userData[auth[1]].stp;
    userData[auth[1]].statement[pos].amount = amount;
    userData[auth[1]].statement[pos].type = 1;
    userData[auth[1]].statement[pos].starting = userData[auth[1]].balance;
    userData[auth[1]].balance -= amount;
    userData[auth[1]].statement[pos].ending = userData[auth[1]].balance;
    userData[auth[1]].stp++;
}

void statement() {
    clear;
    cout << "|\tType\t|\tStating Balance\t|\tEnding Balance\t|\tAmount\t|\n";
    cout << "********************************************************************************|\n";
    for (int i = 0; i < userData[auth[1]].stp; i++) {
        if ( userData[auth[1]].statement[i].type == 0)
            cout << "|    Deposit    ";
        else cout << "|    Withdraw   ";
        cout << "|\t" << userData[auth[1]].statement[i].starting << "\t\t";
        cout << "|\t" << userData[auth[1]].statement[i].ending << "\t\t";
        cout << "|\t" << userData[auth[1]].statement[i].amount << "\t|\n";
    cout << "--------------------------------------------------------------------------------|\n";
    }
    cout << "\n* Press any key to continue...";
    getch();
}
void deleteAc()
{
    for(int i=auth[1]; i< size; i++)
    {
        userData[i]=userData[i+1];
    }
    size--;
    auth[0]=0;
}

/*
* This function decides with function to call when user choose
* an option (for authenticated users only)
*/
void loggedIn(int choice) {
    switch(choice) {
        case 1:
            checkBalance();
            break;
        case 2:
            deposite();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            changePassword();
            break;
        case 5:
            statement();
            break;
        case 6:
            deleteAc();
            break;
        case 7:
            auth[0] = 0;
            auth[1] = 0;
            break;
        case 8:
            exit(0);
    }
}

/*
* Programe Executes from here
*/
int main() {
    int choice;
    do {
        choice = menu();
        (auth[0] == 1) ? loggedIn(choice) : initial(choice);
    } while(choice);
    clear; cout << "**********************************************\n";
    cout << "*       Thank you for banking with us        *\n";
    cout << "**********************************************\n"; return 0;
}
