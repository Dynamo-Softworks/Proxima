#include <iostream>
#include <math.h>

int primefind(long double number)
{
	long double prime;
	long double c=1;
	int test=1;
	
	long double temp,temp2,temp3;
	
	

	
	
	while(c<number && test==1)
	{
		
		/*temp=number%c;
		if(temp==0&&number!=1)
		{
			test=0;
			
		}
		else
		{
		}
		*/
		temp=number/c;
		//std::cout<< temp<<"\n";
		
		temp2=round(temp);
		
		//std::cout<< temp2<< "\n";
		
		temp3=temp2-temp;
		
		//std::cout<< temp3<<"\n";
		if(temp3==0 && c!=1 && c!=number)
		{
		test=0;
		}
		else
		{
		}
		c++;
	}

	if(test==0)
	{
		prime=0;
	}
	else
	{
		prime=number;
	}
	
	return prime;
	
		
}

int main()
{
	int check, output;
	
	std::cout << "Enter a number to check if it is prime.\n";
	std::cin >> check;
	output=primefind(check);
	if(output==0)
	{
		std::cout<< "no";
	
		
	}
	else
	{
		std::cout<< "yes";
	}
	return 0;
	
}
