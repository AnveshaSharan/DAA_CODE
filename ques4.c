#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100], temp[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            temp[j] = tolower(str[i]);
            j++;
        }
    }

    temp[j] = '\0';

    int start = 0;
    int end = strlen(temp) - 1;
    int palindrome = 1;

    while (start < end)
    {
        if (temp[start] != temp[end])
        {
            palindrome = 0;
            break;
        }

        start++;
        end--;
    }

    if (palindrome)
    {
        printf("The string is a palindrome.");
    }
    else
    {
        printf("The string is not a palindrome.");
    }

    return 0;
}