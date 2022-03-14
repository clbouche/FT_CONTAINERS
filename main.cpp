#include "containers/map.hpp"
#include "containers/stack.hpp"
#include "containers/vector.hpp"
#include "iterators/iterator_traits.hpp"
#include "iterators/random_access_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/utils_iterator.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>
int main(void)
{
	/* ------------------------------------------------------------- */
	/* ------------------------- VECTOR --------------------------- */	
	/* ------------------------------------------------------------- */

	// DEFAULT CONSTRUCTOR 

	ft::vector<int>		my_vector_int0;
	// std::vector<int>	std_vector_int0;
	
	// FILL CONSTRUCTOR
	ft::vector<int>		my_vector_int1(6);
	ft::vector<int>		my_vector_int2(6, 4);
	// std::vector<int>	std_vector_int1(6);

	//RANGE CONSTRUCTOR
	//ft::vector<>	
	// ft::stack stack_int;
	// ft::map map_int;


	return (0);
}