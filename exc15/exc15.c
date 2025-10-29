#include <stdio.h>
void tofahrenheit(float a)
{
    float temp;
    temp = (a*(9.0/5.0)+32.0);
    printf("value of %f celsius in fahrenheit is: %f",a,temp);
}
void tocelsius(float a)
{
    float temp;
    temp = (5.0/9.0)*(a-32.0);
    printf("value of %f fahrenheit in celsius is: %f",a,temp);
}
int main()
{
    float a;
    int c;
    printf("To convert to Fahrenheit press F and to Celsius press C:\n");
    c=getchar();
    printf("Enter value:\n");
    scanf("%f",&a);

    if(c=='f' || c=='F'){
        tofahrenheit(a);}
    else if(c=='c' || c=='C')
    {
        tocelsius(a);
    }
    else
        printf("wrong input");

    return 0;

}

