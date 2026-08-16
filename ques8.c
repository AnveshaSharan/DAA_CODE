#include <stdio.h>

struct Student
{
    int rollNo;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main()
{
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        printf("Enter marks in 5 subjects:\n");

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].percentage >= 90)
        {
            s[i].grade = 'A';
        }
        else if (s[i].percentage >= 75)
        {
            s[i].grade = 'B';
        }
        else if (s[i].percentage >= 60)
        {
            s[i].grade = 'C';
        }
        else if (s[i].percentage >= 40)
        {
            s[i].grade = 'D';
        }
        else
        {
            s[i].grade = 'F';
        }
    }

    int topper = 0;

    for (i = 1; i < n; i++)
    {
        if (s[i].percentage > s[topper].percentage)
        {
            topper = i;
        }
    }

    printf("\nStudent Details:\n");

    for (i = 0; i < n; i++)
    {
        printf("\nRoll Number: %d", s[i].rollNo);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    printf("\nClass Topper:\n");
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);

    printf("\nStudents who failed in one or more subjects:\n");

    for (i = 0; i < n; i++)
    {
        int failed = 0;

        for (j = 0; j < 5; j++)
        {
            if (s[i].marks[j] < 40)
            {
                failed = 1;
                break;
            }
        }

        if (failed)
        {
            printf("%s\n", s[i].name);
        }
    }

    float classTotal = 0;

    for (i = 0; i < n; i++)
    {
        classTotal += s[i].percentage;
    }

    printf("\nClass Average: %.2f",
           classTotal / n);

    return 0;
}