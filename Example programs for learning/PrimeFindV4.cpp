#include <iostream>
#include <math.h>

//Calls number by reference, rather than by value, using &. This reduces memory usage by reducing the memory used by the function, as if number is called by value (without &) then the function has to copy the value of the input variable to the function. This way, there is no copying, as the input variable IS the variable used in the function.
int primefind(long long& number)
{
	long double temp,temp2,temp3;
	//values used in calculating primes. long double to handle large values
	long long c=1;
	//values used in displaying primes.
	int test=1, primestop=(number/c)+1;
	//test value used to show if tested value is a prime
	while(c<primestop && test==1 && c<number)
	{
		temp=(float)number/(float)c;
		//divides tested value by the count
		temp2=round(temp);
		//rounds that value
		temp3=temp2-temp;
		//checks to see if the rounded value and the tested value are the same. If they are, then the tested number is divisible by the count value, if not the tested value is not divisible by the count value.
		if(temp3==0 && c!=1 && c!=number)
		{
			test=0;
		}
		else
		{
			test=1;
		}
		//checks to see if the tested value has been disproven to be prime. Stops the loop if the tested value has been disproven.
		if(c<3)
		{
			c++;
		}
		else
		{
			c=c+2;
		}
		
		//modifies count amount for efficiency
	}

	return test;
		
}


using namespace std;
int main()
{
	long long start=1, stop, check=1;
	//values used in counting up to primes.
	int output;
	//values used in transmitting state.
	
	
	
	cout << "Enter an end value.\n";
	cin>> stop;
	//gets stop and start values
	if(start>=1)
	{
		check=start;
	}
	else
	{
		cout<< "The start value is not grater than 1!";
		return 0;
	}
	
	while(stop>check)//while stop is greater than check...
	{
		
		output=primefind(check);
		if(output==0)
		{
			cout<< "";
	
		}
		else if(output==1)
		{
			cout<< check<< " ";
			
		}
		else
		{
			cout<< " !ERROR! ";
		}
		if (check>2)
		{
		check=check+2;
		}
		else
		{
			check++;
		}
	}
	return 0;
	
}