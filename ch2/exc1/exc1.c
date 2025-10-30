#include <stdio.h>


int main()
{
	unsigned char unchar = ~0; // all bits are taken as 11111111  so max is 255
	unsigned short unshort = ~0;//16 bits are 1 means 65535
	unsigned int unint = ~0;//32 bits 1
	unsigned long unlong = ~0;//64 bits 1

	printf("signed char from %d to %d\n", -(char)(unchar>>1) - 1, (char)(unchar>>1));
	printf("unsigned char from 0 to %u\n", unchar);

	printf("signed short from %d to %d\n", -(short)(unshort >> 1) - 1, (short)(unshort >> 1));
	printf("unsigned short from 0 to %u\n", unshort);

	printf("signed int from %d to %d\n", -(int)(unint >> 1) - 1, (int)(unint >> 1));
	printf("unsigned int from 0 to %u\n", unint);

	printf("signed long from %ld to %ld\n", -(long)(unlong >> 1) - 1, (long)(unlong >> 1));
	printf("unsigned long from 0 to %lu\n", unlong);

return 0;
}

