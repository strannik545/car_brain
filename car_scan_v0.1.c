#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>



struct carposition
{
	double plaseX;
	double plaseY;
	double plaseZ;
	
	double speedX;
	double speedY;
	double speedZ;
	
	double acseleratorX;
	double acseleratorY;
	double acseleratorZ;
};

struct coordinate
{
	double X;
	double Y;
	double Z;
};

struct vector
{
	double X1;
	double Y1;
	double Z1;
	
	double X2;
	double Y2;
	double Z2;
}

struct carposition creatmap(int time, int fi, struct carposition old , double detect1, double detect2)
{
	struct carposition new;
	new.plaseX = old.plaseX + old.speedX * time + old.acseleratorX * time * time / 2;
	new.plaseY = old.plaseY + old.speedY * time + old.acseleratorY * time * time / 2;
	new.plaseZ = old.plaseZ + old.speedZ * time + old.acseleratorZ * time * time / 2;
	
	new.speedX = old.speedX + old.acseleratorX * time / 2;
	new.speedY = old.speedY + old.acseleratorY * time / 2;
	new.speedZ = old.speedZ + old.acseleratorZ * time / 2;
	
	struct coordinate dat1;
	dat1.X = new.plaseX - new.speedX * detect1 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY);
	dat1.Y = new.plaseY + new.speedY * detect1 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY); 
	
	struct coordinate dat2;
	dat2.X = new.plaseX + new.speedX * detect2 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY);
	dat2.Y = new.plaseY - new.speedY * detect2 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY);
	
	printf("Detectors  :1:%f 2:%f\n", detect1, detect2);
	printf("Plase      :X:%f Y:%f\n", dat1.X, dat1.Y);
	printf("Plase      :X:%f Y:%f\n", dat2.X, dat2.Y);
	printf("Plase      :X:%f Y:%f\n", new.plaseX, new.plaseY);
	printf("Speeds     :%f %f\n", new.speedX, new.speedY);
	printf("Acselerator:%f %f\n", new.acseleratorX, new.acseleratorY);
	
	return(new);
};

struct vector createvector(struct vector old1, struct vector koren, struct carposition new, double detect1, double detect2)
{
	struct vector new1, new2;
	
	new1.X1 = new.plaseX - new.speedX * detect1 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY);
	new1.Y1 = new.plaseY + new.speedY * detect1 / sqrt(new.speedX*new.speedX+new.speedY*new.speedY); 
	new1.Z1 = 0
	
	new1.X2 = old1.X1;
	new1.Y2 = old1.Y1;
	new1.Z2 = 0;
	
	if(sqrt((koren.X1 - koren.X2)^2 + (koren.X1 - koren.X2)^2) > 0)
	{
		
	}
	else
	{
		
	}
}

int main(int argc, char **argv)
{
	struct carposition start;
	
	start.plaseX = 0;
	start.plaseY = 90;
	start.plaseZ = 0;
	
	start.speedX = -10;
	start.speedY = -10;
	start.speedZ = 0;
	
	start.acseleratorX = 0;
	start.acseleratorY = 0;
	start.acseleratorZ = 0;
	
	struct carposition now;
	
	double detect1, detect2;
	
	FILE * det;
FILE * acs;
	
	det = fopen("detectors.txt", "r");
		
	fscanf(det, "%lf", &detect1);
	fscanf(det, "%lf", &detect2);
	
	old = creatmap(1, 0, start, detect1, detect2);
	printf("\n");
	
	int i = 0;
	
	for (i; i < 3; i+=1)
	{
		acs = fopen("acselerator.txt", "r");
		
		fscanf(acs, "%lf %lf", &now.acseleratorX, &now.acseleratorY);
			
		fscanf(det, "%lf %lf", &detect1, &detect2);
		
		now = creatmap(1, 0, old, detect1, detect2);
		
		
		
		old = new;
		
		printf("\n");
	}
	
	fclose(acs);
	fclose(det);
	
	return 0;
}

