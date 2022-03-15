#include "test.hpp"
#include "../containers/vector.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/utils_iterator.hpp"

#include <vector>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"

/*DELETE*/
#include <iterator>


void	testVector(void)
{
	/* ------------------------------------------------------------- */
	/* -------------------------- VECTOR ---------------------------- */	
	/* ------------------------------------------------------------- */
	
	std::cout << BLUE1 << "DEFAULT CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_default_vector1;
	std::vector<int>	std_default_vector1;

	std::cout << "content of my default constructor : " << std::endl;
	std::ostream_iterator<int> out_it1 (std::cout,", ");
	std::copy ( my_default_vector1.begin(), my_default_vector1.end(), out_it1 );
	std::cout << std::endl;

	std::cout << "content of std default contructor : " << std::endl;
	std::ostream_iterator<int> out_it2 (std::cout,", ");
	std::copy ( std_default_vector1.begin(), std_default_vector1.end(), out_it2 );
	std::cout << std::endl;


	std::cout << BLUE1 << "FILL CONSTRUCTOR" << END << std::endl;
	std::cout << BLUE2 << "/* empty fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector1(0);
	// std::vector<int>	std_fill_vector1(0);
	std::cout << std::endl;

	std::cout << BLUE2 << "/* sized fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector2(6);
	// std::vector<int> std_fill_vector2(6);
	std::cout << std::endl;

	std::cout << BLUE2 << "/* sized fill constructor with value */" << END << std::endl;
	ft::vector<int>		my_fill_vector3(6, 4);
	std::vector<int>	std_fill_vector2(6, 4);
	std::cout << std::endl;

	std::cout << BLUE1 << "RANGE CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_range_iterator(my_fill_vector3.begin() + 1, my_fill_vector3.end());
	std::vector<int>	std_range_iterator;
	std::cout << std::endl;
}