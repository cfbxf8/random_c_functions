
#include <stdio.h>
#include <time.h>

#define MAXSIZE 10

//function prototypes
int three_digit();
int two_digit();
void create_array(int a[][2] , int size);
void print_array(int a[][2] , int size);
int search_info(int a[][2], int size);
void sort_array(int a[][2], int size);
int generate_digit();
int check_digit(int x);

//Main code
int main()
{
//Define variables
int size; 
int a[MAXSIZE][2];

srand(time(NULL));

//Prompt user
printf("\nEnter the size of the array:");
scanf("%d", &size);

//Create array
create_array(a , size);
//Print array
print_array(a, size);
//Print out highest grade and ID
int row=search_info(a, size);
printf("\nStudent with the highest grade has an ID %d \n with the grade %d", a[row][0], a[row][1]);
//Sort array based on ID and print
sort_array(a,size);
}

//Function that returns a 3-digit student ID
int three_digit()
{
int x3= generate_digit();
int y3= generate_digit();
int z3= generate_digit();
	
	//Check for nonzero first number
	while ( check_digit(x3)==1)
	{
		x3= generate_digit();
	}
	
int num3= 100*x3 +10*y3 + z3;

return num3;
}

//Function that returns a 2-digit student ID
int two_digit()
{
int x2= generate_digit();
int y2= generate_digit();

int num2= 10*x2+y2;

return num2;
}

//Function that creates a n by 2 array
void create_array(int a[][2] , int size)
{
int i;
	for ( i = 0; i < size; i++ )
			{
				a[i][0]= three_digit();	
			}
			
		for ( i = 0; i < size; i++ )
			{
				a[i][1]= two_digit();
			}
	}

//Function that prints n by 2 array
void print_array(int a[][2] , int size)
{
int i,j;
printf("\nInput array\nID  Grade\n");

	for ( i = 0; i < size; i++ )
			{
			printf( "%d ", a[ i ][ 0] );
			printf("%d \n", a[i][1]);
			}

}

//Function that searches array for largest grade and returns that row
int search_info(int a[][2], int size)
{
int i,row;
int big=0;
	for (i=0; i<size; i++)
	{ 
		if (a[i][1]> big)
		{
			big=a[i][1];
			row=i;
		}
	}
return row;
}

//Function that sorts array by using bubble sorting and prints array after sorting
void sort_array(int a[][2], int size)
{
int i,pass,hold1,hold2;
/* bubble sort */
/* loop to control number of passes */
for ( pass = 1; pass < size; pass++ ) {
	/* loop to control number of comparisons per pass */
		for ( i = 0; i < size - 1; i++ ) {
			/* compare adjacent elements and swap them if first
			element is greater than second element */
			if ( a[ i ][0] > a[ i + 1 ][0] ) {
			hold1 = a[ i ][0];
			a[ i ][0] = a[ i + 1 ][0];
			a[ i + 1 ][0] = hold1;
			hold2 = a[ i ][1];
			a[ i ][1] = a[ i + 1 ][1];
			a[ i + 1 ][1] = hold2;
			} /* end if */
	} /* end inner for */
} /* end outer for */

int j;
printf("\n\nArrays after sorting\nID  Grade\n");

	for ( i = 0; i < size; i++ )
			{
			printf( "%d ", a[ i ][ 0] );
			printf("%d \n", a[i][1]);
			}
}

//Function that generates a random digit between 0 and 9 and returns it
int generate_digit()
{
int x= rand() % 10;
return x;
}

//Function that checks to make sure digit is not 0 and returns 1 for 0 and 0 for anything else
int check_digit(int x)
{
int digit;
if (x==0) 
	digit=1;
else 
	digit = 0;
return digit;
}


