#include <iostream>
//allows standard input and output
#include <math.h>
//allows a bunch of useful math functions like cos, sin, pow, etc.


int main()
{
	float a;
	float b;
	float c;
	float p;
	float n;
	float squareroot;
	
	//Initialize Variables as floating point numbers.
	
	std::cout << "Input A \n";
	std::cin >> a;
	std::cout<< "Input B \n";
	std::cin >> b;
	std::cout << "Input C \n";
	std::cin >> c;
	//Input Variables

	squareroot=pow(((b*b)-(4*a*c)),.5);
	//pow lets you find the square of an exponent, even fractional ones.
	
	p=((-b+squareroot)/(2*a));
	n=((-b-squareroot)/(2*a));
	//Find Roots
	
	std::cout << "The root associated with the positive component of the square root is: ";
	std::cout << p;
	
	std::cout << "The root associated with the negative component of the square root is: ";
	std::cout << n;
	//Outputs the roots 
	
	
	
	return 0;
	// ends program
}