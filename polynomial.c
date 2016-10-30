
#include <stdio.h>



// Function Prototypes

double getNum();

int getPow();

double power(double a, int p);

double f(double x);

double g(double y);

double polynomial(double x, int n, double y, int m, int delta);



int main()

{

//Declare variables 

double x,y, xm, a, yn, gy, fx, polys;

int delta, m, n, i, p;

printf("\nPlease enter value for delta: ");



//Get delta from user while delta is greater than or equal to 0 else quit program

scanf("%d", &delta);

while (delta >= 0)

{

//Get all of the other important variables from user

printf("\nPlease enter value between -100 and 100 for x:");

x=getNum();

printf("\nPlease enter value between -100 and 100 for y:");

y=getNum();

printf("\nPlease enter value between -10 and 10 for m: ");

m=getPow();

printf("\nPlease enter value between -10 and 10 for n: ");

n=getPow();

//Call functions to calculate powers and functions for x and y as well as calculate entire polynomial

xm=power(x, m);

yn=power(y, n);

fx= f(x);

gy=g(y);

polys=polynomial(x,n,y,m,delta);

//print and start over

printf("\nf(x) = %.2lf", fx);

printf("\npower: %.2lf", xm);

printf("\ng(y) = %.2lf", gy);

printf("\npower: %.2lf", yn);

printf("-----------------------------");

printf("\n Polynomial = %.2lf", polys);

printf("\nPlease enter value for delta: ");

scanf("%d", &delta);

}

}



// Function that error checks and scans for a variable between -100 and 100 returns double

double getNum()

{

double a;

scanf("%lf", &a);

	while((a <= -100) || (a >= 100))

	{

	printf("\n Invalid input. Try Again: \n");

	scanf("%lf", &a);

	}

return a;

}



// Function that error checks and scans for a variable between -10 and 10 returns integer

int getPow()

{

int n;

scanf("%d", &n);



	while ((n <= -10) || (n >= 10))

	{

	printf("\n Invalid input. Try Again: \n");

	scanf("%d", &n);

	}

return n;

}



//returns double a to the power p

double power (double a, int p)

{

double z=a;

int i=1;

					while (i<p)

					{

					z=z*a;

					i++;

					}

					

					return z;

}



//returns function based on f

double f(double x)

{

double fx;

fx=3*(x*x) +3.14;

return fx;

}



//returns function based on g

double g(double y)

{

double gy;

gy=(y*y*y) -3.14;

return gy;

}



//returns polynomial according to the formula given

double polynomial( double x, int n, double y, int m, int delta)

{

double polys, fx, xm, gy, yn;



xm=power(x, m); 

fx= f(x);

yn=power(y, n);

gy=g(y);



polys=((fx+ xm) / (gy + yn)) + delta;

return polys;

}