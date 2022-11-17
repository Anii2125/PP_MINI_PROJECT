#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Functions
//  void login();
void clearScreen();
void mainMenu();
void checkBalance(float Total_balance);
float moneyDeposit(float Total_balance);
float moneyWithdraw(float Total_balance);
void printReceipt();
void exitMenu();
void errorMessage();

int main()
{

    int option;
    float Total_balance = 25000.00;
    int choice;

    int flag = 1;
    printf("\n***WELCOME TO THE SBI ATM (BODKHI)***\n\n");

    while (flag)
    {
        void clearScreen();
        mainMenu();

        printf("____________________________\n");
        printf("____________________________\n");
        printf("Your Selection:\t");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            checkBalance(Total_balance);
            break;
        case 2:
            system("cls");
            Total_balance = moneyDeposit(Total_balance);
            break;
        case 3:
            system("cls");
            Total_balance = moneyWithdraw(Total_balance);
            break;
        case 4:
            system("cls");
            printReceipt();
            return 0;

        default:
            errorMessage();
            break;
        }

        printf("_________________________________________\n");
        printf("_________________________________________\n\n");

        printf("Press:\n 1 to continue \n");
        printf(" 2 to exit \n");
        printf("\nYour Selection :");
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

// Functions

void mainMenu()
{
    printf("Please choose one of the options below\nPress:\n\n");
    printf(" 1   To Check your Balance\n");
    printf(" 2   To Deposit\n");
    printf(" 3   To Withdraw\n");
    printf(" 4   Exit\n");
}
void clearScreen()
{
    system("cls");
}

void checkBalance(float Total_balance)
{
    printf("You Choose to See your Balance\n");
    printf("\n\nYour Available Balance is:   %.2f Rs\n\n", Total_balance);
}

float moneyDeposit(float Total_balance)
{
    float deposit_amount;
    printf("You choose to Deposit Money\n");
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

    printf("You choose to Withdraw Money\n");
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

            printf("!!INSUFFICIENT BALANCE!!\n");

            printf("!!Your Account Balance is:   %.2f Rs\n\n!!", Total_balance);
        }
    }
    return Total_balance;
}
void printReceipt()
{
    int reciept;
    printf("Do you want a receipt..???\n");
    printf("Press:\n\n 1 to print reciept\n 2 to Exit without the receipt \n");

    printf("_______________________________________\n");
    printf("_______________________________________\n\n");

    printf("\nYour Selection :");
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
} // error message