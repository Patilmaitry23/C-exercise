#include <stdio.h>

int main()
{
	float fahr, cels;
	float lower, upper, step;
	
	upper=300;
	step=20;
	lower=0;
	fahr=lower;
	printf("Fahr\t Cels\n");
	while(fahr<=upper)
	{
		cels = (5.0/9.0)*(fahr-32.0);
		printf("%3.0f\t %6.1f\n", fahr, cels);
		fahr=fahr+step;
	}
	return 0;
}
