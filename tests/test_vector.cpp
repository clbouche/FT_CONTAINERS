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
	std::cout << BLUE3 << "content of my vector : " << END << std::endl;
	typename ft::vector<T>::iterator it1;
	for	(it1 = my_vector.begin(); it1 != my_vector.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;
	std::cout << BLUE3 << "content of std vector : " << END << std::endl;
	typename std::vector<T>::iterator it2;
	for	(it2 = std_vector.begin(); it2 != std_vector.end(); it2++)
		std::cout << *it2 << " ";
	std::cout << std::endl;
}

template <typename T>
void	printInfos(ft::vector<T>& my_vector, std::vector<T> std_vector)
{
	std::cout << BLUE3 << "infos of my vector : " << END << std::endl;
	std::cout << "capacity : " << my_vector.capacity() << std::endl;
	std::cout << "size : " << my_vector.size() << std::endl;

	std::cout << BLUE3 << "infos of std vector : " << END << std::endl;
	std::cout << "capacity : " << std_vector.capacity() << std::endl;
	std::cout << "size : " << std_vector.size() << std::endl;
}

void	testConstructors(void)
{

	std::cout << BLUE1 << "/*__________________________CONSTRUCTOR__________________________*/" << END << std::endl;

	std::cout << BLUE2 << "DEFAULT CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_default_vector1;
	std::vector<int>	std_default_vector1;

	printContent(my_default_vector1, std_default_vector1);
	std::cout << std::endl;

	std::cout << BLUE2 << "FILL CONSTRUCTOR" << END << std::endl;
	std::cout << BLUE3 << "/* empty fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector1(0);
	std::vector<int>	std_fill_vector1(0);

	printContent(my_fill_vector1, std_fill_vector1);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* sized fill constructor */" << END << std::endl;
	ft::vector<int>		my_fill_vector2(6);
	std::vector<int> 	std_fill_vector2(6);

	printContent(my_fill_vector2, std_fill_vector2);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* sized fill constructor with value */" << END << std::endl;
	ft::vector<int>		my_fill_vector3(6, 4);
	std::vector<int>	std_fill_vector3(6, 4);

	printContent(my_fill_vector3, std_fill_vector3);
	std::cout << std::endl;

	std::cout << BLUE2 << "RANGE CONSTRUCTOR" << END << std::endl;
	ft::vector<int>		my_range_iterator(my_fill_vector3.begin() + 1, my_fill_vector3.end());
	std::vector<int>	std_range_iterator;

	printContent(my_range_iterator, std_range_iterator);
	std::cout << std::endl;
}

void	testReserve(void)
{

	std::cout << BLUE1 << "/*__________________________CAPACITY__________________________*/"<< END << std::endl;
	ft::vector<int> 		my_vector(3, 8);
	std::vector<int>		std_vector(3, 8);
	std::cout << BLUE2 << "BEFORE RESERVE" << END << std::endl;
	printInfos(my_vector, std_vector);
	my_vector.reserve(46); //ERROR OF CAPACITY
	std_vector.reserve(46);
	std::cout << std::endl << BLUE2 << "AFTER RESERVE" << END << std::endl;
	printInfos(my_vector, std_vector);

	std::cout << std::endl << BLUE2 << "TRY MAX SIZE" << END << std::endl;
	try
	{
		std::cout << BLUE3 << "try max_size my_vector" << END << std::endl;
		my_vector.reserve(my_vector.max_size() + 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << BLUE3 << "try max_size std_vector" << END << std::endl;
		std_vector.reserve(std_vector.max_size() + 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


void	testElementAccess(void)
{
	std::cout << BLUE1 << "/*________________________ELEMENT ACCESS________________________*/"<< END << std::endl;
	ft::vector<int>		my_vector(5, 3);
	std::vector<int>	std_vector(5, 3);

	std::cout << BLUE2 << "BEFORE ELEMENT ACCESS" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* operator[] */" << END << std::endl;
	std::cout << "ft::vector[3] is : " << my_vector[3] << std::endl;
	std::cout << "std::vector[3] is : " << std_vector[3] << std::endl;

	ft::vector<int>::iterator it1 = my_vector.insert(my_vector.begin() + 1, 155);
	std::vector<int>::iterator it2 = std_vector.insert(std_vector.begin() + 1, 155);
	printContent(my_vector, std_vector);

	std::cout << BLUE3 << "/* function at */" << END << std::endl;
	std::cout << "ft::vector at position 2 is : " << my_vector.at(1) << std::endl;
	std::cout << "std::vector at position 2 is : " << std_vector.at(1) << std::endl << std::endl;

	it1 = my_vector.insert(my_vector.begin(), 12);
	it2 = std_vector.insert(std_vector.begin(), 12);
	printContent(my_vector, std_vector);

	std::cout << BLUE3 << "/* function front */" << END << std::endl;
	std::cout << "first element of my_vector : " << my_vector.front() << std::endl;
	std::cout << "first element of std_vector : " << std_vector.front() << std::endl << std::endl;

	it1 = my_vector.insert(my_vector.end(), 369);
	it2 = std_vector.insert(std_vector.end(), 369);
	printContent(my_vector, std_vector);

	std::cout << BLUE3 << "/* function back */" << END << std::endl;
	std::cout << "last element of my_vector : " << my_vector.back() << std::endl;
	std::cout << "last element of std_vector : " << std_vector.back() << std::endl;

}

void	testAssign(void)
{
	std::cout << BLUE1 << "/*________________________ASSIGN________________________*/"<< END << std::endl;
	ft::vector<int>		my_vector;
	std::vector<int>	std_vector;

	std::cout << std::endl << BLUE3 << "BEFORE ASSIGN" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << std::endl << BLUE3 << "AFTER ASSIGN" << END << std::endl;
	my_vector.assign(6, 100);
	std_vector.assign(6, 100);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
}

void	testResize(void)
{
	std::cout << BLUE1 << "/*________________________RESIZE________________________*/"<< END << std::endl;
	ft::vector<int>		my_vector(10, 15);
	std::vector<int>	std_vector(10, 15);

	std::cout << BLUE2 << "BEFORE RESIZE" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;

	std::cout << BLUE3 << std::endl << "/* resize to less than size */" << END << std::endl;
	my_vector.resize(5);
	std_vector.resize(5);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << BLUE3 << std::endl << "/* resize to more than size */" << END << std::endl;
	my_vector.resize(15);
	std_vector.resize(15);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << BLUE3 << std::endl << "/* resize to more than size & val specified*/" << END << std::endl;
	my_vector.resize(15, 5);
	std_vector.resize(15, 5);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
}

void	testPop_Push_Back(void)
{
	std::cout << BLUE1 << "/*________________________POP & PUSH BACK ________________________*/"<< END << std::endl;
	ft::vector<int>		my_vector(1, 50);
	std::vector<int>	std_vector(1, 50);

	std::cout << BLUE2 << "BEFORE PUSH & POP BACK" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;


	std::cout << BLUE2 << "AFTER PUSH BACK" << END << std::endl;
	my_vector.push_back(60);
	std_vector.push_back(60);
	my_vector.push_back(70);
	std_vector.push_back(70);
	my_vector.push_back(80);
	std_vector.push_back(80);
	my_vector.push_back(90);
	std_vector.push_back(90);
	my_vector.push_back(100);
	std_vector.push_back(100);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << BLUE2 << "AFTER POP BACK" << END << std::endl;
	my_vector.pop_back();
	std_vector.pop_back();
	my_vector.pop_back();
	std_vector.pop_back();
	my_vector.pop_back();
	std_vector.pop_back();
	my_vector.pop_back();
	std_vector.pop_back();
	my_vector.pop_back();
	std_vector.pop_back();

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
}

void	testInsert(void)
{
	std::cout << BLUE1 << "/*__________________________INSERT__________________________*/"<< END << std::endl;
	ft::vector<int>		my_vector(6, 10);
	std::vector<int>	std_vector(6, 10);

	std::cout << BLUE2 << "BEFORE INSERT" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;
	
	std::cout << BLUE3 << "/* function insert with 1 value */" << END;
	ft::vector<int>::iterator it1 = my_vector.insert(my_vector.begin() + 1, 12);
	std::vector<int>::iterator it2 = std_vector.insert(std_vector.begin() + 1, 12);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << BLUE3 << std::endl << "/* function insert with several values */" << END;
	my_vector.insert(my_vector.begin(), 3, 30);
	std_vector.insert(std_vector.begin(), 3, 30);

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);

	std::cout << BLUE3 << std::endl << "/* function insert with a range of values */" << END;

	ft::vector<int>	my_input_iterator(5, 104);
	std::vector<int>	std_input_iterator(5, 104);

	my_vector.insert(my_vector.begin() + 3, my_input_iterator.begin(), my_input_iterator.end());
	std_vector.insert(std_vector.begin() + 3, std_input_iterator.begin(), std_input_iterator.end());

	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
}

void	testSwap(void)
{
	std::cout << BLUE1 << "/*__________________________SWAP__________________________*/"<< END << std::endl;
	ft::vector<int> my_vector (3,100);
	std::vector<int> std_vector (3,100);	
	ft::vector<int> my_new_vector (5,200); 	
	std::vector<int> std_new_vector (5,200); 

	std::cout << BLUE2 << "BEFORE SWAP" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;

	my_vector.swap(my_new_vector);
	std_vector.swap(std_new_vector);

	std::cout << BLUE2 << "AFTER INSERT" << END << std::endl;
	printContent(my_vector, std_vector);
	printInfos(my_vector, std_vector);
	std::cout << std::endl;
}

void	testRelationalOperators(void)
{
	std::cout << BLUE1 << "/*__________________________RELATIONAL OPERATORS__________________________*/"<< END << std::endl;
	ft::vector<int>		my_first_vector (20, 30);
	ft::vector<int>		my_second_vector(20, 30);
	ft::vector<int>		my_third_vector(10, 6);
	ft::vector<int>		my_fourth_vector(50, 3);

	std::vector<int>	std_first_vector (20, 30);
	std::vector<int>	std_second_vector(20, 30);
	std::vector<int>	std_third_vector(10, 6);
	std::vector<int>	std_fourth_vector(50, 3);

	std::cout << "__________FIRST VECTOR" << std::endl;
	printContent(my_first_vector, std_first_vector);
	std::cout << "__________SECOND VECTOR" << std::endl;
	printContent(my_second_vector, std_second_vector);
	std::cout << std::endl;

	std::cout << BLUE2 << " MY OPERATOR== : " << END << (my_first_vector == my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR== : " << END  << (std_first_vector == std_second_vector) << std::endl;


	std::cout << BLUE2 << " MY OPERATOR!= : " << END << (my_first_vector != my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR!= : " << END << (std_first_vector != std_second_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (my_first_vector < my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR<  : " << END << (std_first_vector < std_second_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (my_first_vector < my_third_vector);
	std::cout << BLUE2 << " STD OPERATOR<  : " << END << (std_first_vector < std_third_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (my_first_vector < my_fourth_vector);
	std::cout << BLUE2 << " STD OPERATOR<  : " << END << (std_first_vector < std_fourth_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR<= : " << END << (my_first_vector <= my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR<= : " << END << (std_first_vector <= std_second_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR<= : " << END << (my_first_vector <= my_third_vector);
	std::cout << BLUE2 << " STD OPERATOR<= : " << END << (std_first_vector <= std_third_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (my_first_vector > my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR>  : " << END << (std_first_vector > std_second_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (my_first_vector > my_third_vector);
	std::cout << BLUE2 << " STD OPERATOR>  : " << END << (std_first_vector > std_third_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (my_first_vector > my_fourth_vector);
	std::cout << BLUE2 << " STD OPERATOR>  : " << END << (std_first_vector > std_fourth_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (my_first_vector > my_second_vector);
	std::cout << BLUE2 << " STD OPERATOR>= : " << END << (std_first_vector > std_second_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (my_first_vector > my_third_vector);
	std::cout << BLUE2 << " STD OPERATOR>= : " << END << (std_first_vector > std_third_vector) << std::endl;

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (my_first_vector > my_fourth_vector);
	std::cout << BLUE2 << " STD OPERATOR>= : " << END << (std_first_vector > std_fourth_vector) << std::endl;
}

void	testReverseIterator(void)
{
	std::cout << BLUE1 << "/*__________________________REVERSE ITERATORS__________________________*/"<< END << std::endl;
	ft::vector<int> vct;
	ft::vector<int>::iterator it = vct.begin();
	ft::vector<int>::iterator cit = vct.begin();

	ft::vector<int>::reverse_iterator rit(it);

	ft::vector<int>::const_reverse_iterator crit(rit);
	ft::vector<int>::const_reverse_iterator crit_(it);
	ft::vector<int>::const_reverse_iterator crit_2(cit);


	ft::vector<int> myvector (5);  // 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit1 = myvector.rbegin();

	int i=0;
	for (rit1 = myvector.rbegin(); rit1 != myvector.rend(); ++rit1)
	*rit1 = ++i;

	std::cout << BLUE1 << "/*____________________________________________________*/"<< END << std::endl;
	std::vector<int> stdvector (5);  // 5 default-constructed ints

	std::vector<int>::reverse_iterator rit2 = stdvector.rbegin();

	i=0;
	for (rit2 = stdvector.rbegin(); rit2!= stdvector.rend(); ++rit2)
	*rit2 = ++i;

	printContent(myvector, stdvector);

}

void	testInception(void)
{
	ft::vector<int>			test(3, 3);

// 	std::cout << "self assignation test\n";
// 	ft::vector<ft::vector<int> >	self_assign;
// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;

// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// //	self_assign = self_assign; //compiler doesn't like it!



// 	ft::vector<ft::vector<int> > JOHN;
	ft::vector<ft::vector<int> > BOB(5, test);
// 	std::cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			std::cout << BOB[i][j] << ' ';
// 		std::cout << '\n';
// 	}
// 	ft::vector<ft::vector<int> > MIKE(BOB);

// 	// CTORs
// 	std::cout << "\nCTORS\n";
// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';

// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

// 	// RESIZE
// 	size_t	bob_resize = 2;
// 	std::cout << "\nRESIZE\n";
// 	BOB.resize(bob_resize);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

// 	size_t	mike_resize = 9;
// 	bob_resize = 0;
	
// 	BOB.resize(bob_resize);
// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
// 	MIKE.resize(mike_resize, test);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_resize)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 		{
// 			std::cout << MIKE[i][j] << ' ';
// 		}
// 	std::cout << std::endl;
// 	}
// 	// RESERVE
// 	std::cout << "\nRESERVE\n";

// 	size_t	john_reserve = 0;
// 	size_t	bob_reserve = 3;
// 	size_t	mike_reserve = 4;

// 	JOHN.reserve(john_reserve);
// 	BOB.reserve(bob_reserve);
// 	MIKE.reserve(mike_reserve);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= john_reserve)
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_reserve)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_reserve)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}

// 	//AT
// 	std::cout << "\nAT\n";
// 	try
// 	{
// 		std::cout << MIKE.at(2).front() << '\n';
// 		std::cout << MIKE.at(87).back() << '\n';
// 	}
// 	catch (std::out_of_range& oor)
// 	{
// 		(void)oor;
// 		std::cout << "OOR error caught\n";
// 	}

// 	// FRONT / BACK
// 	std::cout << "\nFRONT / BACK\n";
// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

// 	//ASSIGN
// 	std::cout << "\nASSIGN\n";
// 	test.assign(3, 17);
// 	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	ft::vector<ft::vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	// //EMPTY
	// std::cout << "\nEMPTY\n";
	// std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	// std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	// //PUSH/POP_BACK
	// std::cout << "\nPUSH/POP_BACK\n";
	// test.assign(2, 42);
	// BOB.push_back(test);
	// std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	// BOB.pop_back();
	// std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	// //INSERT
	// std::cout << "\nINSERT\n";
	// ft::vector<ft::vector<int> >	insert_in_me;
	// for (int i = 0; i < 15; i++)
	// {
	// 	ft::vector<int>	j(2, i);
	// 	insert_in_me.push_back(j);
	// }
	// for (size_t i = 0; i < insert_in_me.size(); i++)
	// {
	// 	for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 		std::cout << insert_in_me.at(i).at(j) << ' ';
	// 	std::cout << '\n';
	// }

	// ft::vector<ft::vector<int> >::iterator	tmp;
	// test.assign(23, 19);
	// tmp = insert_in_me.begin() + 4;
	// insert_in_me.insert(tmp, 8, test);
	// for (size_t i = 0; i < insert_in_me.size(); i++)
	// {
	// 	for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 		std::cout << insert_in_me.at(i).at(j) << ' ';
	// 	std::cout << '\n';
	// }

	// ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
	// std::cout << "Const it.front() : " << std::endl;
	// std::cout << (*const_it).front() << '\n';


	// //INSERT
	// std::cout << "\nINSERT\n";
	// ft::vector<ft::vector<int> >	std_insert_in_me;
	// for (int i = 0; i < 15; i++)
	// 	std_insert_in_me.push_back(test);
	// for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 	std::cout << std_insert_in_me.at(i).front() << ' ';
	// std::cout << '\n';

	// ft::vector<ft::vector<int> >::iterator	std_tmp;
	// std_tmp = std_insert_in_me.begin() + 4;
	// std_insert_in_me.insert(std_tmp, 8, test);
	// for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 	std::cout << std_insert_in_me.at(i).back() << ' ';
	// std::cout << '\n';


	// //INSERT RANGE
	// std::cout << "\nINSERT RANGE\n";
	// ft::vector<ft::vector<int> >	insert_bis;
	// for (int i = 0; i < 7; i++)
	// {
	// 	ft::vector<int>	j(2, i * 3);
	// 	insert_bis.push_back(j);
	// }
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i].back() << ' ';
	// std::cout << '\n';

	// insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i].back() << ' ';
	// std::cout << '\n';


	// //ERASE
	// std::cout << "\nERASE\n";
	// ft::vector<ft::vector<int> >	erase_in_me;
	// for (int i = 0; i < 15; i++)
	// {
	// 	ft::vector<int>	j(1, i);
	// 	erase_in_me.push_back(j);
	// }
	// for (size_t i = 0; i < erase_in_me.size(); i++)
	// 	std::cout << erase_in_me.at(i).front() << ' ';
	// std::cout << '\n';

	// erase_in_me.erase(erase_in_me.begin() + 7);
	// for (size_t i = 0; i < erase_in_me.size(); i++)
	// 	std::cout << erase_in_me.at(i).front() << ' ';
	// std::cout << '\n';
	// erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	// for (size_t i = 0; i < erase_in_me.size(); i++)
	// 	std::cout << erase_in_me.at(i).front() << ' ';
	// std::cout << '\n';

	// //SWAP
	// std::cout << "\nSWAP\n";
	// john_reserve = 4;
	// JOHN.reserve(john_reserve);
	// BOB.swap(MIKE);
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// {
	// 	for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		std::cout << MIKE[i][j] << ' ';
	// std::cout << std::endl;
	// }

	// MIKE.swap(JOHN);
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// {
	// 	for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		std::cout << MIKE[i][j] << ' ';
	// std::cout << std::endl;
	// }

	// //CLEAR
	// std::cout << "\nCLEAR\n";
	// JOHN.clear();
	// MIKE.clear();
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// {
	// 	for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		std::cout << MIKE[i][j] << ' ';
	// std::cout << std::endl;
	// }

	// //NON MEMBER Functions
	// std::cout << "\nNON MEMBER functions\n";
	// swap(BOB, MIKE);
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// {
	// 	for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		std::cout << MIKE[i][j] << ' ';
	// std::cout << std::endl;
	// }
	
	// //RELATIONAL OPERATORS
	// std::cout << "\nRELATIONAL OPERATORS\n";
	// ft::vector<ft::vector<int> > MIKE_2(MIKE);
	// std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	// std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	// std::cout << "\nReal vector\n";
	// ft::vector<ft::vector<int> > real;
	// real.assign(5, test);
	// for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
	// 	std::cout << (*it).front() << " ";
	// std::cout << '\n';

	// std::cout << std::endl;
}



void	testVector(void)
{
	/* ------------------------------------------------------------- */
	/* -------------------------- VECTOR ---------------------------- */	
	/* ------------------------------------------------------------- */
	
	// testConstructors();
	// std::cout << std::endl;

	// testResize();
	// std::cout << std::endl;
	
	// testReserve();
	// std::cout << std::endl;

	// testElementAccess();
	// std::cout << std::endl;

	// testPop_Push_Back();
	// std::cout << std::endl;

	// testInsert();
	// std::cout << std::endl;

	// // testErase();
	// // std::cout << std::endl;

	// testSwap();
	// std::cout << std::endl;

	// testRelationalOperators();
	// std::cout << std::endl;

	//testReverseIterator();
	//std::cout << std::endl;
	
	// testAssign();
	// std::cout << std::endl;

	testInception();
	std::cout << std::endl;
}
