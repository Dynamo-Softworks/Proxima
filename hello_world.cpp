#include <iostream>
//Includes the standard input and output library. So cout and cin work.

//compile with g++, not gcc.

using namespace std;
//I guess this puts 'cout' in the 'namespace' of 'std', because taking out line 5, and putting 'std::cout <<' instead of 'cout <<' does the same thing.

int main(){
int a;
cout << "Hello World!\n";
cin >> a;
cout << a;
cout << " Woah! Inputting stuff.\n";

return 0;
}