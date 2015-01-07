
//useful data types
struct position
{
	float x, y, z;
} ;

struct dimensions
{
	float length, width, height;
} ;

//names are built from a prefix and middle, both chars, and a suffix, a long. Mileage may vary, but this should give us loads of possible names.
struct name
{
	char prefix;
	char middle;
	long suffix;
} ;

struct input
{

	float voltage;
	float current;
	
};

struct output
{
	
	float voltage;
	float current;
	
};
//THE connector
class connector
{

	input input;
	output output;
	
};



//THE generic component
class component
{
		
		
		//number_of_"blank" variables determine how many connection points are generated, and of what type. For the time being, and for readability, I'll use bools to describe what type of connector a connection is. For simplicity, for now all components are POLARIZED! They will only allow electricity to flow one way, i.e from input to output.
		
		float in_voltage, in_current, out_voltage, out_current, resistance, number_of_inputs, number_of_outputs;
	Public:
		
		
};