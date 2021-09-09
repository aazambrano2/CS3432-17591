#include <stdio.h>
/**
Aaron Zambrano
Homework 1
Dr. Shirley Moore
Last edited: September 4, 2021
*/

//Conversion function
float convert(float fahr){
	return ((5.0/9.0) * (fahr-32));	
}

int main()
{
	float fahr; 
	printf("Enter Degrees Fahrenheit:\n");
	scanf("%f",&fahr);
	printf("Conversion Successful.\n %6.1f Fahrenheit is%6.1f degrees Celsius\n",fahr,convert(fahr));
}
