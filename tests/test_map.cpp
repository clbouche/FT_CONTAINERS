#include "test.hpp"
#include "../utils/utils_pair.hpp"
#include "../RBTree/RBTree.hpp"
#include "../containers/map.hpp"

#include <map>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"

template <typename T1, typename T2>
void	M_printContent(ft::pair<T1, T2>& my_pair, std::pair<T1, T2>& std_pair)
{
	std::cout << BLUE3 << "content of my pair : " << END << std::endl;
	std::cout << "first element is : " << my_pair.first << std::endl;
	std::cout << "second element is : " << my_pair.second << std::endl;

	std::cout << std::endl;
	
	std::cout << BLUE3 << "content of std pair : " << END << std::endl;
	std::cout << "first element is : " << std_pair.first << std::endl;
	std::cout << "second element is : " << std_pair.second << std::endl;

	std::cout << std::endl;
}


void	M_testPairConstructors(void) 
{
	std::cout << BLUE1 << "/*__________________________Constructors__________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Constructors: " << END << std::endl;
	ft::pair < std::string, std::string > my_pair1;				//default constructor
	ft::pair < std::string, int > my_pair2("temperature", 25);	//value init
	ft::pair < std::string, int > my_pair3(my_pair2);					//copy constuctor

	std::pair < std::string, std::string > std_pair1;			//default constructor
	std::pair < std::string, int > std_pair2("temperature", 25);	//value init
	std::pair < std::string, int > std_pair3(std_pair2);			//copy constructor

	M_printContent(my_pair1, std_pair1);
	std::cout << "___________________________________" << std::endl;
	M_printContent(my_pair2, std_pair2);
	std::cout << "___________________________________" << std::endl;
	M_printContent(my_pair3, std_pair3);

	std::cout << BLUE3 << "Operator= : " << END << std::endl;
	ft::pair <std::string, int> my_pair4;
	my_pair4 = my_pair3;

	std::pair <std::string, int> std_pair4;
	std_pair4 = std_pair3;

	M_printContent(my_pair4, std_pair4);

}

void	M_testPairComparaisons(void)
{
	std::cout << BLUE1 << "/*__________________________Comparaisons__________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Operator==: " << END << std::endl;
	ft::pair < int, char> my_pair1_1(1, 'a');
	ft::pair < int, char> my_pair1_2(1, 'a');
	ft::pair < int, char > my_pair2(2, 'b');
	ft::pair < float, char > my_pair3(4.6, 'c');

	std::pair < int, char> std_pair1_1(1, 'a');
	std::pair < int, char> std_pair1_2(1, 'a');
	std::pair < int, char > std_pair2(2, 'b');
	std::pair < float, char > std_pair3(4.6, 'c');

	std::cout << "1 - ";
	if (my_pair1_1 == my_pair1_2) 
		std::cout << "my pairs are equals";
	std::cout << std::endl << "1 - ";
	if (std_pair1_1 == std_pair1_2)
		std::cout << "std pairs are equals";

	std::cout << std::endl << "2 - ";
	if (my_pair1_1 == my_pair2) 
		std::cout << "my pairs are equals";
	std::cout << std::endl << "2 - ";
	if (std_pair1_1 == std_pair2) 
		std::cout << "std pairs are equals"; 

	//NE PEUT PAS COMPILER - comportement normal
	// std::cout << std::endl << "3 - ";
	// if (my_pair1_1 == my_pair3) 
	// 	std::cout << "my pairs are equal";
	// std::cout << std::endl << "3 - ";
	// if (std_pair1_1 == std_pair3) 
	// 	std::cout << "std pairs are equal"; 
	
	std::cout << std::endl << std::endl;

	std::cout << BLUE3 << "Operator!=: " << END << std::endl;

	std::cout << "4 - ";
	if (my_pair1_1 != my_pair2) 
		std::cout << "my pairs are differents";
	std::cout << std::endl << "4 - ";
	if (std_pair1_1 != std_pair2) 
		std::cout << "std pairs are differents"; 

	std::cout << std::endl;
	//tester les autres comparaisons mais j'ai la flemme la en vrai 
}

void	M_testMakePair(void)
{
	std::cout << BLUE1 << "/*__________________________MAKE PAIR_________________________*/" << END << std::endl;

	ft::pair<int, int> my_pair;
	std::pair<int, int> std_pair;

	my_pair = ft::make_pair(10, 20);
	std_pair = std::make_pair(10, 20);

	M_printContent(my_pair, std_pair);
}

void	M_testRBTconstructors(void)
{
	// ft::RBTree my_rbt;
	ft::RBTree< ft::pair<int,int> > my_rbt;
}

void	M_testRBTInsert(void)
{
	ft::RBTree< ft::pair<int,int> > my_rbt;

	my_rbt.insert(ft::pair < int, int>(3, 3) );
}

void	testMap(void)
{
	/* ------------------------------------------------------------- */
	/* --------------------------- PAIR ---------------------------- */	
	/* ------------------------------------------------------------- */

	// M_testPairConstructors();
	// std::cout << std::endl;

	// M_testPairComparaisons();
	// std::cout << std::endl;

	// M_testMakePair();
	// std::cout << std::endl;

	/* ------------------------------------------------------------- */
	/* --------------------------- RBTree -------------------------- */	
	/* ------------------------------------------------------------- */

	M_testRBTconstructors();
	std::cout << std::endl;

	M_testRBTInsert();
	std::cout << std::endl;

	/* ------------------------------------------------------------- */
	/* --------------------------- MAP ----------------------------- */	
	/* ------------------------------------------------------------- */

}