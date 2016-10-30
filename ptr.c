
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

//function prototypes
int mystrlen(char *string);
char* mystrcpy(char *string);
char* mystrconcat(char *s1, char *s2);

//Main code
int main()
{
//Define Variables
char *String1, *String2, *newstring1, *newstring2, *concat;

//Allocate memory for String1 and String2
String1=malloc(sizeof(char)* MAX);
String2=malloc(sizeof(char)* MAX);

//Prompt User
printf("\nEnter string1:");
scanf("%s", String1);
printf("\nEnter string2:");
scanf("%s", String2);

//Copy strings using mystrcpy function
newstring1=mystrcpy(String1);
newstring2=mystrcpy(String2);

//Print copies of strings
printf( "\nCopy of String1: %s", newstring1 );
printf( "\nCopy of String2: %s", newstring2);

//Concatenate the copied strings using mystrconcat
concat=mystrconcat(newstring1, newstring2);

//Print the concatenated string
printf( "\nConcatenated: %s", concat);

}

//Function that gets the lenghts of that string and returns this length
int mystrlen(char* string)
{
int i=0;
	while ( *string!='\0')
	{
		i++;
		string++;
	}
return i;
}

//Function that takes a pointer to a string that needs to be copied.
//The function determines the length of the string using mystrlen function.
//Allocates a new string of same length and then copies each character to this new string and returns it.
char* mystrcpy(char* string)
{
int size=mystrlen(string);

char* newString= malloc((size+ 1)* sizeof (char));
char*head=newString;
	while ( *string !='\0')
	{
		*newString=*string;
		newString++;
		string++;
	}
	*newString = '\0';
return head;
}

//Inputs a pointer of two strings that needs to be concatenated. 
//Function determines the length of each string and allocates space to hold it. Returns concatenated string.
char* mystrconcat(char *s1, char *s2)
{
int size=mystrlen(s1);
int size2=mystrlen(s2);
char* catString= (char*)malloc((size+ size2 + 1)* sizeof (char));
char*head=catString;

	while ( *s1!='\0')
	{
		*catString=*s1;
		s1++;
		catString++;
	}
	while ( *s2!='\0')
	{
		*catString=*s2;
		s2++;
		catString++;
	}
	return head;
}