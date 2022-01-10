//Library function for Input/Output & String function
#include<stdio.h>
#include<string.h>

//Custum data type (Account)
struct Account {
    int balance;
    char name[100];
    char email[100];
    char password[100];
};

//state = 1 for logged in
int state = 0;
//length holds data size
int length = 0;
//position holds logged in users position
int position = 0;

//data(array) contains user information
struct Account data[100];

//Call this function when logged out
int home() {
    int choice;
    printf("--------------------------------------------------------------\n");
    printf("---------------  Welcome to Bank of Munshigonj  --------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\t1. Create an account\t\t\t\t     -\n");
    printf("-\t2. Login to your account\t\t\t     -\n");
    printf("-\t3. Exit the program\t\t\t\t     -\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tEnter your choice -> ");
    scanf("%d", &choice);
    if (choice == 3) choice = 0;
    else if (choice > 3) {
        system("cls");
        home();
    }
    return choice;
}

//Call this function when logged in
int menu() {
    int choice;
    printf("--------------------------------------------------------------\n");
    printf("------------------  Welcome to your account  -----------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    //data[position].name returns User Name
    printf("-\tHello, %s\n", data[position].name);
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\t1. Deposite some ammount\t\t\t     -\n");
    printf("-\t2. Withdraw some ammount\t\t\t     -\n");
    printf("-\t3. Check your balance\t\t\t\t     -\n");
    printf("-\t4. Log out\t\t\t\t\t     -\n");
    printf("-\t5. Exit the program\t\t\t\t     -\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tEnter your choice -> ");
    scanf("%d", &choice);
    //choice = 0 will stop the loop in  main funtion
    if (choice == 5) 
        choice = 0;
    //choice += 2 (previous function already holds 2 option)
    else choice+=2;
    return choice;
}

//Call this function for deposite
void deposite() {
    int amount;
    printf("--------------------------------------------------------------\n");
    printf("------------------  Welcome to your account  -----------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tYour ammount to deposite -> ");
    scanf("%d", &amount);
    //data[position].balance will add amount
    data[position].balance+=amount;
    system("cls");
}

//Call this function for withdraw
void withdraw() {
    int amount;
    printf("--------------------------------------------------------------\n");
    printf("------------------  Welcome to your account  -----------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tYour ammount to withdraw -> ");
    scanf("%d", &amount);
    //check if you do have enough balance
    if(amount > data[position].balance) {
        system("cls");
        printf("--------------------------------------------------------------\n");
        printf("--------------   You do not have enough balance   ------------\n");
        withdraw();
        return;
    } else data[position].balance-=amount;
    system("cls");
}

//Call this function to check balance
void check() {
    printf("--------------------------------------------------------------\n");
    printf("--------------------   Check your balance  -------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tYour balance is -> %d\n", data[position].balance);
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tPress any key to continue...\t\t\t     -");
    getch();
    system("cls");
}

//Call this function to login existing user
void login() {
    char email[100], password[100];
    printf("--------------------------------------------------------------\n");
    printf("-------------------  Login to your account  ------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\tEnter your email -> ");
    fflush(stdin);
    gets(email);
    printf("-\tEnter your password -> ");
    fflush(stdin);
    gets(password);
    for(int x = 0; x < length; x++) {
        if(strcmp(email, data[x].email)==0) {
            if(strcmp(password, data[x].password)==0) {
                state = 1;
                position = x;
                break;
            } else {
                state = 0;
                system("cls");
                printf("--------------------------------------------------------------\n");
                printf("-------------------   Password missmatch   -------------------\n");
                login();
                break;
            }
        }
    }
    system("cls");
    printf("--------------------------------------------------------------\n");
    printf("--------------   No user found with this email   -------------\n");
}

//Call this function to create a now account
void create() {
    struct Account temp;
    printf("--------------------------------------------------------------\n");
    printf("---------------------  Create an account  --------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("-\t\t\t\t\t\t\t     -\n");
    printf("-\tEnter your name -> ");
    fflush(stdin);
    gets(temp.name);
    printf("-\tEnter your email -> ");
    fflush(stdin);
    gets(temp.email);
    printf("-\tEnter your password -> ");
    fflush(stdin);
    gets(temp.password);
    for(int x = 0; x < length; x++) {
        if(strcmp(temp.email, data[x].email)==0) {
            system("cls");
            printf("--------------------------------------------------------------\n");
            printf("-------------------   Email already exist   ------------------\n");
            create();
            break;
        }
    }
    position = length;
    temp.balance = 0;
    data[length] = temp;
    state = 1;
    length++;
    system("cls");
}

int main() {
    int choice = home();
    while (choice) {
        system("cls");
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                login();
                break;
            case 3:
                deposite();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                check();
                break;
            case 6:
                state = 0;
                break;
            default:
                printf("--------------------------------------------------------------\n");
                printf("---------------------   Wrong choice !!   --------------------\n");
                break;
        }
        if (state == 0)
            choice = home();
        else choice = menu();
    }
    
    return 0;
}