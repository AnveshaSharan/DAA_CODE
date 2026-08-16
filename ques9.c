#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main()
{
    struct Book books[100];

    int count = 0;
    int choice, i, id;
    int found;

    while (1)
    {
        printf("\n1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter Book ID: ");
            scanf("%d", &books[count].id);

            printf("Enter Title: ");
            scanf("%s", books[count].title);

            printf("Enter Author: ");
            scanf("%s", books[count].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[count].totalCopies);

            books[count].availableCopies =
                books[count].totalCopies;

            count++;

            break;

        case 2:

            printf("Enter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    printf("\nBook Found\n");

                    printf("ID: %d\n",
                           books[i].id);

                    printf("Title: %s\n",
                           books[i].title);

                    printf("Author: %s\n",
                           books[i].author);

                    printf("Available Copies: %d\n",
                           books[i].availableCopies);

                    found = 1;
                }
            }

            if (!found)
            {
                printf("Book not found.\n");
            }

            break;

        case 3:

            printf("Enter Book ID to issue: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    if (books[i].availableCopies > 0)
                    {
                        books[i].availableCopies--;

                        printf("Book issued successfully.\n");
                    }
                    else
                    {
                        printf("Book unavailable.\n");
                    }
                }
            }

            break;

        case 4:

            printf("Enter Book ID to return: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    if (books[i].availableCopies <
                        books[i].totalCopies)
                    {
                        books[i].availableCopies++;

                        printf("Book returned successfully.\n");
                    }
                }
            }

            break;

        case 5:

            printf("\nUnavailable Books:\n");

            for (i = 0; i < count; i++)
            {
                if (books[i].availableCopies == 0)
                {
                    printf("%s\n",
                           books[i].title);
                }
            }

            break;

        case 6:

            return 0;

        default:

            printf("Invalid choice.\n");
        }
    }

    return 0;
}