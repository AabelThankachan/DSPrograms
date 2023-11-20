// sorting a structure
#include <stdio.h>
struct student
{
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int total;
    int roll_no;
} s[50];

void main()
{
    int i, n;
    printf("enter number of students:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter roll number of student:");
        scanf("%d", &s[i].roll_no);
        printf("enter marks in five subjects: \n");
        scanf("%d %d %d %d %d", &s[i].s1, &s[i].s2, &s[i].s3, &s[i].s4, &s[i].s5);
        s[i].total = s[i].s1 + s[i].s2 + s[i].s3 + s[i].s4 + s[i].s5;
    }
    int arr[20];
    for (i = 0; i < n; i++)
    {
        arr[i] = s[i].total;
    }

    int j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Total marks is %d \n", arr[i]);
    }
}
