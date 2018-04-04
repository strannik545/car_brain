#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct vector{
	double x;
	double y;
} vector;
struct linfun{
	double a;
	double b;
	vector nap;
	vector first;
	vector last;
} linfun;
vector calpos(vector old, vector speed, vector acs, int t){             // считаем новую позицию
	
	vector new;
	
	new.x = old.x + speed.x * t + acs.x * t^2 / 2;
	new.y = old.y + speed.y * t + acs.y * t^2 / 2;
	
	return new;
}
vector calspe(vector old, vector acs, int t){                           // считаем навую скорость
	
	vector new;
	
	new.x = old.x + acs.x *t;
	new.y = old.y + acs.y *t;
	
	return new;
}
vector coostaR(vector pos, vector speed, double det){                   // считаем показания правого датчика
	
	vector coostaR;
	
	coostaR.x = pos.x + det * speeed.y / sqrt(speed.x^2 + speed.y^2);
	coostaR.y = pos.x - det * speeed.x / sqrt(speed.x^2 + speed.y^2);
	
	return coostaR;
}
vector coostaL(vector pos, vector speed, double det){                   // считаем показания левого датчика
	
	vector coostaL;
	
	coostaL.x = pos.x - det * speeed.y / sqrt(speed.x^2 + speed.y^2);
	coostaL.y = pos.x + det * speeed.x / sqrt(speed.x^2 + speed.y^2);
	
	return coostaL;
}
linfun createfun(vector first, vector last){                            // создание первого вектора границы
	
	linfun fun;
	
	fun.nap.x = last.x - first.x;
	fun.nap.y = last.y - first.y;
	
	fun.a = fun.nap.y / fun.nap.x;
	fun.b = first.y - first.x * fun.a;
	
	fun.first.x = first.x;
	fun.first.y = first.y;
	
	fun.last.x = last.x;
	fun.last.y = last.y;
	
	return fun;}
linfun modfun(linfun fun, vector new, int dfi){                         // добавление вектора
	
	if(acos(((fun.first.x - new.x)^2 + (fun.first.y - new.y)^2- ((fun.last.x - new.x)^2 + (fun.last.y - new.y)^2) - ((fun.first.x - fun.last.x)^2 + (fun.first.y - fun.last.y)^2))/(sqrt((fun.first.x - fun.last.x)^2 + (fun.first.y - fun.last.y)^2) * ((fun.last.x - new.x)^2 + (fun.last.y - new.y)^2)) < 115){
	}
	else if((fun.nap.x / fun.nap.y > (new.x - fun.first.x) / (new.y - fun.first.y) - dfi) && (fun.nap.x / fun.nap.y < (new.x - fun.first.x) / (new.y - fun.first.y) + dfi)){
		
		fun.a = ( new.y - fun.first.y ) / (  new.x - fun.first.x );
		fun.b = fun.first.y - fun.a * fun.first.x;
		
		fun.last.x = new.x;
		fun.last.y = new.y;
	}
	else{
		FILE Fun;
		
		Fun = fopen("vectors.txt", a);
		
		fprintf( Fun, "a= %f \nb= %f \first.x= %f \nfirst.y= %f \nlast.x= %f \nlast.y= %f \n", fun.a, fun.b, fun.first.x, fun.first.y, fun.last.x, fun.last.y);
		
		fclose(Fun); 
		
		fun = createfun(fun.last, new);
	}
	return fun;

}
}
int stop(vector new, int stope){                            // остановка постраения гранницы
	if( (new.x - stope < 0) && (new.y - stope < 0) ){
		return 1;
	}
	else{
		return 0;
	}
}
void finfun(linfun fun, int dfi){                                     // замыкание кривой
	Fun = fopen("vectors.txt", r);
		
	vector first;
		
	char str[15];
	
	fscanf(Fun,"%s%lf", &str, &first.x}; 
	fscanf(Fun,"%s%lf", &str, &first.x};
	fscanf(Fun,"%s%lf", &str, &first.x};
	fscanf(Fun,"%s%lf", &str, &first.y};
	
	fun = modfun(fun, first, dfi);
	
	fclose(Fun);
	
	Fun = fopen("vectors.txt", a);
		
	fprintf( Fun, "a= %f \nb= %f \first.x= %f \nfirst.y= %f \nlast.x= %f \nlast.y= %f \n", fun.a, fun.b, fun.first.x, fun.first.y, fun.last.x, fun.last.y};
		
	fclose(Fun); 
}	
int main(int argc, char **argv)
{
	vector first;
	linfun funL;
	linfun funR;
	
	newpos.x = 0;
	newpos.y = 0;
	
	last.x = 1;
	last.y = 0;

	int i = 0;
	int j = 0;
	int t = 1;
	int dfi = 1;
	int stope = 10;
	
	while(i < 0){                                                       // тело сканера
		
		// приём данных от датчиков
		
		newpos = calpos(newpos, newspeed, acs, t);
		newspeed = calspe(newspeed, acs, t);
		posR = coostaR(newpos, newspeed, detR);
		posL = coostaL(newpos, newspeed, detL);
		
		if(j > 1){
			funL = modfun(funL, posL, dfi);
			funR = modfun(funR, posR, dfi);
		}
		else if(j == 1){
			funL = createfun(firstL, posL);
			funR = createfun(firstR, posR);
			j++;
		}
		else{
			vector firstL = posL;
			vector firstR = posR;
			j++;
		}
		if(stop(newpos, stope)){
			finfun(finL, dfi); 
			finfun(finR, dfi);
	}
	
	// построение закончилось
}



	return 0;
