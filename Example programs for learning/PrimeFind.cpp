#include <iostream>
#include <math.h>

int primefind(long long number)
{
	long double temp,temp2,temp3;
	//values used in calculating primes. long double to handle large values
	long long c=1;
	//values used in displaying primes.
	int test=1, prime;
	//test value used to show if tested value is a prime
	while(c<number && test==1)
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
		c++;
		//adds one to the count value to repeat the cycle.
	}

	return test;
		
}



using namespace std;
int main()
{
	long long stop, check=1;
	//values used in counting up to primes.
	int output;
	//values used in transmitting state.
	
	
	cout << "Enter a number to find all prime less than entered number.\n";
	cin >> stop;
	//gets stop value
	
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
		check++;
	}
	return 0;
	
}