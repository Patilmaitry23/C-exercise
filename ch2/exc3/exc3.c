/*convert hex to decimal
1A2= (16^2 x 1) + (16^1 x (10)) + (16^0 x 2)
*/

#include <stdio.h>

int htoi(char hex[])
{
    int i;
    int dec=0, val;

    if(hex[0]=='0' && (hex[1]=='x' || hex[1]=='X')) //for 0x or 0X
    {
        for(i=2;hex[i]!='\0';i++)
        {
            if (hex[i] >= '0' && hex[i] <= '9')
                val = hex[i] - '0';
            else if (hex[i] >= 'a' && hex[i] <= 'f')
                val = hex[i] - 'a' + 10;
            else if (hex[i] >= 'A' && hex[i] <= 'F')
                val = hex[i] - 'A' + 10;
            else
                break;

            dec = 16*dec + val;
        }
    }



    return dec;
}

int main()
{
    char hex[] = "0x1A2";

    printf("%s in hex is %d in decimal",hex, htoi(hex));

    return 0;
}

