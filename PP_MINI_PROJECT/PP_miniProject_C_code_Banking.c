#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declaration of functions

void clearScreen();
void mainMenu();
void checkBalance(float Total_balance);
float moneyDeposit(float Total_balance);
float moneyWithdraw(float Total_balance);
void printReceipt();
void exitMenu();
void errorMessage();
void checkPin(int set_pin);
int changePin(int set_pin);

// Main function !!!!

int main()
{
    int set_pin = 1234;
    int option;
    float Total_balance = 25000.00;

    int choice;

    int flag = 1;
    clearScreen();

    printf("\n*WELCOME TO THE SBI ATM (BODKHI)*\n\n");
    checkPin(set_pin);

    while (flag)
    {

        mainMenu();

        printf("___________________\n");
        printf("___________________\n\n");
        printf("Your Selection:\t");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            checkPin(set_pin);
            checkBalance(Total_balance);
            break;
        case 2:
            system("cls");
            checkPin(set_pin);
            Total_balance = moneyDeposit(Total_balance);
            break;
        case 3:
            system("cls");
            checkPin(set_pin);
            Total_balance = moneyWithdraw(Total_balance);
            break;
        case 4:
            system("cls");
            checkPin(set_pin);
            set_pin = changePin(set_pin);
            break;

        case 5:
            system("cls");
            printReceipt();
            return 0;

        default:
            errorMessage();
            break;
        }

        printf("__________________________\n");
        printf("__________________________\n\n");

        printf("Press:\n 1 to continue \n");
        printf(" 2 to exit \n");
        printf("\nYour Selection:\t");
        scanf("%d", &choice);

        system("cls");

        if (choice == 2)
        {
            flag = 0;
            printReceipt();
        }
    }
    return 0;
}

// Defination of Functions

void mainMenu()
{
    printf("\t!! MENU !!\n\n");
    printf("Please choose one of the options below\nPress:\n\n");
    printf(" 1   To Check your Balance\n");
    printf(" 2   To Deposit\n");
    printf(" 3   To Withdraw\n");
    printf(" 4   To Change your pin\n");
    printf(" 5   Exit\n");
}

void clearScreen()
{
    system("cls");
}

void checkBalance(float Total_balance)
{
    printf("\nYou Choose to See your Balance\n");
    printf("\nYour Available Balance is:   %.2f Rs\n\n", Total_balance);
}

float moneyDeposit(float Total_balance)
{
    float deposit_amount;

    printf("\nYou choose to Deposit Money\n\n");
    printf("Your Previous Balance is: %.2f Rs\n\n", Total_balance);
    printf("Enter Deposit Amount\n");
    scanf("%f", &deposit_amount);

    Total_balance += deposit_amount;

    printf("\nYour New Balance is:   %.2f Rs\n\n ", Total_balance);
    return Total_balance;
}

float moneyWithdraw(float Total_balance)
{
    float withdraw_amount;
    int flag1 = 1;

    printf("\nYou choose to Withdraw Money\n\n");
    printf("Your Balance is: %.2f Rs\n\n", Total_balance);

    while (flag1)
    {
        printf("Enter Withdraw Amount:\n");
        scanf("%f", &withdraw_amount);

        if (withdraw_amount <= Total_balance)
        {
            flag1 = 0;
            Total_balance -= withdraw_amount;
            printf("\nYour withdrawing money is:  %.2f Rs\n", withdraw_amount);
            printf("Your New Balance is:   %.2f Rs\n\n", Total_balance);
        }
        else
        {
            clearScreen();

            printf("\n!!INSUFFICIENT BALANCE!!\n\n");
            printf("!!Your Account Balance is:   %.2f Rs !!\n\n", Total_balance);
        }
    }
    return Total_balance;
}

void printReceipt()
{
    int reciept;
    printf("Do you want a receipt..???\n");
    printf("Press:\n\n 1 to print reciept\n 2 to Exit without the receipt \n");

    printf("__________________\n");
    printf("__________________\n\n");

    printf("\nYour Selection:\t");
    scanf("%d", &reciept);

    if (reciept == 1)
    {
        printf("\n!!!Take your receipt!!!\n");
        exitMenu();
    }
    else if (reciept == 2)
    {
        exitMenu();
    }
}

void exitMenu()
{
    printf("\n!!!Thank you for using ATM (Bodkhi Branch)!!!\n\n");
}

void errorMessage()
{
    printf("!!!Invalid number!!!\n");
}

void checkPin(int set_pin)
{
    int get_pin;
    printf("\nEnter your 4 Digit ATM PIN\n\n");
    scanf("%d", &get_pin);
    if (set_pin == get_pin)
    {
        printf("checked and compared\n");
        clearScreen();
    }
    else
    {
        printf("\n!!!INCORRECT PIN!!!!\nTry AGAIN!!!!\n");
        checkPin(set_pin);
    }
}

int changePin(int set_pin)
{
    int new_pin;
    printf("Enter new pin\n\n");
    scanf("%d", &new_pin);
    set_pin = new_pin;
    printf("\nYour new pin is : %d\n\n", set_pin);

    return set_pin;
}