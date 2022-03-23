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

template <typename T>
void	printContent(ft::vector<T>& my_vector, std::vector<T>& std_vector)
{
	std::cout << "content of my default constructor : " << std::endl;
	typename ft::vector<T>::iterator it1;
	for	(it1 = my_vector.begin(); it1 != my_vector.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;
	std::cout << "content of std default contructor : " << std::endl;
	typename ft::vector<T>::iterator it2;
	for	(it2 = my_vector.begin(); it2 != my_vector.end(); it2++)
		std::cout << *it2 << " ";
	std::cout << std::endl;
}

void	testConstructors(void)
{

/*__________________________CONSTRUCTOR__________________________*/

	std::cout << BLUE1 << "DEFAULT CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_default_vector1;
	std::vector<int>	std_default_vector1;

	printContent(my_default_vector1, std_default_vector1);
	std::cout << std::endl;

	std::cout << BLUE1 << "FILL CONSTRUCTOR" << END << std::endl;
	std::cout << BLUE2 << "/* empty fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector1(0);
	std::vector<int>	std_fill_vector1(0);

	printContent(my_fill_vector1, std_fill_vector1);
	std::cout << std::endl;

	std::cout << BLUE2 << "/* sized fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector2(6);
	std::vector<int> 	std_fill_vector2(6);

	printContent(my_fill_vector2, std_fill_vector2);
	std::cout << std::endl;

	std::cout << BLUE2 << "/* sized fill constructor with value */" << END << std::endl;
	ft::vector<int>		my_fill_vector3(6, 4);
	std::vector<int>	std_fill_vector3(6, 4);

	printContent(my_fill_vector3, std_fill_vector3);
	std::cout << std::endl;

	std::cout << BLUE1 << "RANGE CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_range_iterator(my_fill_vector3.begin() + 1, my_fill_vector3.end());
	std::vector<int>	std_range_iterator;

	printContent(my_range_iterator, std_range_iterator);
	std::cout << std::endl;
}

void	testCapacity(void)
{

/*__________________________CAPACITY__________________________*/

	ft::vector<int> 		my_vec(3, 8);
	my_vec.reserve(46);
	std::cout << my_vec.capacity() << std::endl;

	ft::vector<int>::iterator it1;
	for (it1 = my_vec.begin(); it1 != my_vec.end(); it1++)
		std::cout << "my value is = " << *it1 << std::endl;

	try
	{
		my_vec.reserve(my_vec.max_size() + 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void	testVector(void)
{
	/* ------------------------------------------------------------- */
	/* -------------------------- VECTOR ---------------------------- */	
	/* ------------------------------------------------------------- */
	
	testConstructors();
	std::cout << std::endl;

	testCapacity();
	std::cout << std::endl;

}