
//THE generic component
class component
{
		//Basic properties. pos_"blank" variables describe the position of the center of the component. 
		
		//length, width and hight describe physical dimensions. 
		
		//number_of_"blank" variables determine how many connection points are generated, and of what type. For the time being, and for readability, I'll use bools to describe what type of connector a connection is. For simplicity, for now all components are POLARIZED! They will only allow electricity to flow one way, i.e from input to output.
		
		float voltage, current, resistance, length, width, height, pos_x, pos_y, pos_z, number_of_inputs, number_of_outputs;
		struct connector 
		{
			int name;
			float 
		}
	Public:
		
		
}