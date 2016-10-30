


#include <stdio.h>

#include <time.h>







// Function Prototypes

int generate_digit();

int create_number(int x, int y, int z);

int check_digit(int x);

int check_error(int x);

int sum_digits(int x);

int reverse_number(int x, int y);





//Main program

int main()

{

srand(time(NULL));

int times;



//prompt user for number of times

printf("\nHow many times you want to run the program: ");

scanf("%d", &times);

//check to make sure user enters positive numeber

while (check_error(times)==1)

{

	printf("\nInvalid number renter the number again: ");

	scanf("%d", &times);

}

//run as many times as user asks for

while (times > 0)

{

//Generate random digits for six numbers

int x1= generate_digit();

int y1= generate_digit();

int z1= generate_digit();

int x2= generate_digit();

int y2= generate_digit();

int z2= generate_digit();

//check to make sure first digits are positive

	while ( check_digit(x1)==1)

	{

		x1= generate_digit();

	}

	while ( check_digit(x2)==1)

	{

		x2= generate_digit();

	}

//create two 3 digit numbers	

	int num1 = create_number(x1,y1,z1);

	int num2 = create_number(x2,y2,z2);

//break down and sum digits

	int sums1 = sum_digits(num1);

	int sums2 = sum_digits(num2);

// combine 2 numbers to make 1 six digit number

	int big= num1 *1000 + num2;

//Reverse number

	int reverse= reverse_number(num1, num2);

//Print

	printf("\n The first three digit numbers is %d and the sum of digits is %d", num1, sums1);

	printf("\n The second three digit numbers is %d and the sum of digits is %d", num2, sums2);

	printf("\n The six digit number obtained by using numbers %d and %d is %d and it's reverse is %d", num1, num2, big, reverse);

	times --;

}



return 0;

}



//Returns random number from 0 to 9

int generate_digit()

{

int x= rand() % 10;

return x;

}



//Creates 3 digit number using x,y,z and returns that number

int create_number(int x, int y, int z)

{

int num= 100*x +10*x + z;

return num;

}



//Returns 1 if number is equal to 0. returns 0 otherwise

int check_digit(int x)

{

int digit;

if (x==0) 

	digit=1;

else 

	digit = 0;

return digit;

}



//Returns 0 for positive numbers and 0 otherwise.

int check_error(int x)

{

int check;

if (x<=0)

	check = 1;

else

	check=0;

	return check;

}



//Returns the sum of a 3 digit number's digits

int sum_digits(int x)

{

int num1= x/100;

int num3= x %10;

int num2= (x % 100) / 10;

int sums = num1 + num2 + num3;

return sums;

}



//Reverses the digits of a six digit number

int reverse_number(int x, int y)

{

int a1= x/100;

int a3= x %10;

int a2= (x % 100) / 10;

int a4= y/100;

int a6= y %10;

int a5= (y % 100) / 10;



int reverse= (a6 * (10 *10*10*10*10)) + (a5 * (10*10*10*10)) + (a4 * (10*10*10)) + (a3 * (10*10)) + (a2 * 10) + a1;

return reverse;

}

