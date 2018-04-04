#include <math.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	double i;
	double j;
	i = 0;
	scanf("%lf", &j);
	i = asinf(j);
	printf("%f %f", j, i);
	return 0;
}

