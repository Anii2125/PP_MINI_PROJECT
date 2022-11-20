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
# checkPin()
# changePin()


# Main function !!!!

def main():

    Total_balance = 25000.00
    set_pin = 1234
    flag = True
    clearScreen()
    print("\n***WELCOME TO THE SBI ATM (BODKHI)***\n")
    checkPin(set_pin)
    while (flag):

        mainMenu()

        print("____________________________")
        print("____________________________\n")
        print("Your Selection:\t", end="")

        option = int(input())

        # in place of switch cases in c code
        if option == 1:

            clearScreen()
            checkPin(set_pin)
            checkBalance(Total_balance)

        elif option == 2:

            clearScreen()
            checkPin(set_pin)
            Total_balance = moneyDeposit(Total_balance)

        elif option == 3:

            clearScreen()
            checkPin(set_pin)
            Total_balance = moneyWithdraw(Total_balance)

        elif option == 4:
            clearScreen()
            checkPin(set_pin)
            set_pin = changePin(set_pin)

        elif option == 5:

            clearScreen()
            printReceipt()
            return False

        else:
            errorMessage()

        print("_______________________________________")
        print("_______________________________________\n")

        print("Press:\n 1 to continue ")
        print(" 2 to exit \n")
        print("\nYour Selection:\t", end="")
        choice = int(input())
        os.system("cls")

        if (choice == 2):
            flag = False
            printReceipt()


# Defination of Functions

def mainMenu():
    print("\t!! MENU !!\n")
    print("Please choose one of the options below\nPress:\n")
    print(" 1   To Check your Balance")
    print(" 2   To Deposit")
    print(" 3   To Withdraw")
    print(" 4   To change your pin")
    print(" 5   Exit")


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

    print("_____________________________________")
    print("_____________________________________\n")

    print("\nYour Selection:\t", end="")
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


def checkPin(set_pin):

    print("\nEnter your 4 Digit ATM PIN\n")
    get_pin = int(input())
    if (set_pin == get_pin):

        print("checked and compared\n")
        clearScreen()

    else:

        print("\n!!!INCORRECT PIN!!!!\nTry AGAIN!!!!\n")
        checkPin(set_pin)


def changePin(set_pin):

    print("Enter new pin\n")
    new_pin = int(input())
    set_pin = new_pin
    print(f"Your new pin is : {set_pin}")

    return set_pin


main()
