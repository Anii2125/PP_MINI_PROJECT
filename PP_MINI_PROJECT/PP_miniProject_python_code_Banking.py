import os

# Functions
# clearScreen()
# mainMenu()
# checkBalance(Total_balance)
# moneyDeposit(Total_balance)
# moneyWithdraw(Total_balance)
# printReceipt()
# exitMenu()
# errorMessage()


# Main function !!!!

def main():

    Total_balance = 25000.00

    flag = True
    clearScreen()
    print("\n***WELCOME TO THE SBI ATM (BODKHI)***\n\n")

    while (flag):

        mainMenu()

        print("____________________________")
        print("____________________________\n")
        print("Your Selection:\t", end="")

        option = int(input())

        # in place of switch cases in c code
        if option == 1:

            clearScreen()
            checkBalance(Total_balance)

        elif option == 2:

            clearScreen()
            Total_balance = moneyDeposit(Total_balance)

        elif option == 3:

            clearScreen()
            Total_balance = moneyWithdraw(Total_balance)

        elif option == 4:

            clearScreen()
            printReceipt()
            return False

        else:
            errorMessage()

        print("_________________________________________")
        print("_________________________________________\n")

        print("Press:\n 1 to continue ")
        print(" 2 to exit \n")
        print("\nYour Selection :", end="")
        choice = int(input())
        os.system("cls")

        if (choice == 2):
            flag = False
            printReceipt()


# Defination of Functions

def mainMenu():
    print("Please choose one of the options below\nPress:\n")
    print(" 1   To Check your Balance")
    print(" 2   To Deposit")
    print(" 3   To Withdraw")
    print(" 4   Exit")


def clearScreen():
    os.system("cls")


def checkBalance(Total_balance):

    print("\nYou Choose to See your Balance\n")
    print(f"Your Available Balance is:  {Total_balance} Rs\n")


def moneyDeposit(Total_balance):

    print("\nYou choose to Deposit Money\n")
    print(f"Your Previous Balance is: {Total_balance} Rs\n")
    print("Enter Deposit Amount")
    deposit_amount = float(input())

    Total_balance += deposit_amount

    print(f"Your New Balance is:  {Total_balance} Rs\n ")
    return Total_balance


def moneyWithdraw(Total_balance):

    flag1 = True

    print("\nYou choose to Withdraw Money\n")
    print(f"Your Balance is: {Total_balance} Rs\n")

    while (flag1):

        print("Enter Withdraw Amount:\n")
        withdraw_amount = float(input())

        if (withdraw_amount <= Total_balance):

            flag1 = False
            Total_balance -= withdraw_amount
            print(f"\nYour withdrawing money is:  {withdraw_amount} Rs\n")
            print(f"Your New Balance is:  {Total_balance} Rs\n")

        else:
            clearScreen()
            print("!!INSUFFICIENT BALANCE!!\n")

            print(f"!!Your Account Balance is:  {Total_balance} Rs!!\n\n")

    return Total_balance


def printReceipt():

    print("Do you want a receipt..???\n")
    print("Press:\n\n 1 to print reciept\n 2 to Exit without the receipt \n")

    print("_______________________________________")
    print("_______________________________________\n")

    print("\nYour Selection :", end="")
    reciept = int(input())

    if (reciept == 1):

        print("\n!!!Take your receipt!!!\n")
        exitMenu()

    elif (reciept == 2):

        exitMenu()


def exitMenu():

    print("\n!!!Thank you for using ATM (Bodkhi Branch)!!!\n\n")


def errorMessage():

    print("!!!Invalid number!!!\n")


main()
