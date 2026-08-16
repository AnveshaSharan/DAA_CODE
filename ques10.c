#include <stdio.h>

int main()
{
    int choice, i;
    float balance = 0, amount;
    float transactions[5] = {0};

    while (1)
    {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last Five Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Current Balance: %.2f\n", balance);

            break;

        case 2:

            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            balance += amount;

            for (i = 0; i < 4; i++)
            {
                transactions[i] = transactions[i + 1];
            }

            transactions[4] = amount;

            printf("Money deposited successfully.\n");

            break;

        case 3:

            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                balance -= amount;

                for (i = 0; i < 4; i++)
                {
                    transactions[i] = transactions[i + 1];
                }

                transactions[4] = -amount;

                printf("Money withdrawn successfully.\n");
            }

            break;

        case 4:

            printf("Last Five Transactions:\n");

            for (i = 0; i < 5; i++)
            {
                if (transactions[i] != 0)
                {
                    if (transactions[i] > 0)
                    {
                        printf("Deposited: %.2f\n",
                               transactions[i]);
                    }
                    else
                    {
                        printf("Withdrawn: %.2f\n",
                               -transactions[i]);
                    }
                }
            }

            break;

        case 5:

            return 0;

        default:

            printf("Invalid choice.\n");
        }
    }

    return 0;
}