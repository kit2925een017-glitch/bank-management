#include <stdio.h>
#include <string.h>

struct Bank
{
    int accNo;
    char name[50];
    float balance;
};

struct Bank customer[100];
int count = 0;

void createAccount()
{
    printf("\nEnter Account Number: ");
    scanf("%d", &customer[count].accNo);

    printf("Enter Customer Name: ");
    scanf("%s", customer[count].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &customer[count].balance);

    count++;

    printf("\nAccount Created Successfully!\n");
}

void depositMoney()
{
    int acc, i;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    for(i = 0; i < count; i++)
    {
        if(customer[i].accNo == acc)
        {
            customer[i].balance += amount;

            printf("\nAmount Deposited Successfully!");
            printf("\nUpdated Balance = %.2f\n", customer[i].balance);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nAccount Not Found!\n");
    }
}

void withdrawMoney()
{
    int acc, i;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    for(i = 0; i < count; i++)
    {
        if(customer[i].accNo == acc)
        {
            if(customer[i].balance >= amount)
            {
                customer[i].balance -= amount;

                printf("\nWithdrawal Successful!");
                printf("\nRemaining Balance = %.2f\n", customer[i].balance);
            }
            else
            {
                printf("\nInsufficient Balance!\n");
            }

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nAccount Not Found!\n");
    }
}

void displayAccount()
{
    int acc, i;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    for(i = 0; i < count; i++)
    {
        if(customer[i].accNo == acc)
        {
            printf("\n===== Account Details =====\n");
            printf("Account Number : %d\n", customer[i].accNo);
            printf("Customer Name  : %s\n", customer[i].name);
            printf("Balance        : %.2f\n", customer[i].balance);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nAccount Not Found!\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== Bank Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                displayAccount();
                break;

            case 5:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}