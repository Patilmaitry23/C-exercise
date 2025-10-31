#include <stdio.h>
#include <ctype.h>
#include<math.h>

float calc(int a, int b, char s)
{
    float temp=0;
    switch(s)
    {
    case '+':
        temp=a+b;
        break;
    case '-':
        temp = a-b;
        break;
    case '*':
        temp=a*b;
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: Division by zero!\n");
            return 0;
        }
        temp = (float)a / b;
        break;
    case '%':
        if (b == 0)
        {
            printf("Error: Division by zero!\n");
            return 0;
        }
        temp = a % b;
        break;

    default:
        printf("Invalid operator!\n");
        return 0;
    }

    return temp;
}
int main()
{
    char s;
    int a,b;
    float output;
    printf("Enter 1st number: ");
    scanf("%d", &a);

    printf("Enter 2nd number: ");
    scanf("%d", &b);

    printf("Enter operation to be done: ");
    scanf(" %c", &s);

    output = calc(a,b,s);
    printf("Output is: %f\n", output);

    return 0;
}

