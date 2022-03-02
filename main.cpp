#include "containers/map.hpp"
#include "containers/stack.hpp"
#include "containers/vector.hpp"
#include <vector>
#include <stack>
#include <map>

int main(void)
{
	/* ------------------------------------------------------------- */
	/* ------------------------- VECTOR --------------------------- */	
	/* ------------------------------------------------------------- */

	// DEFAULT CONSTRUCTOR 

	ft::vector<int>		my_vector_int0;
	std::vector<int>	std_vector_int0;
	
	// FILL CONSTRUCTOR
	ft::vector<int>		my_vector_int1(6);
	std::vector<int>	std_vector_int1(6);

	ft::stack stack_int;
	ft::map map_int;


	return (0);
}