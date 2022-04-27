#include "test.hpp"
#include "../utils/utils_pair.hpp"
#include "../RBTree/algo.hpp"
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
void	M_printContentPair(ft::pair<T1, T2>& my_pair, std::pair<T1, T2>& std_pair)
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
	std::cout << BLUE1 << "/*__________________________Constructors pair __________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Constructors: " << END << std::endl;
	ft::pair < std::string, std::string > my_pair1;				//default constructor
	ft::pair < std::string, int > my_pair2("temperature", 25);	//value init
	ft::pair < std::string, int > my_pair3(my_pair2);					//copy constuctor

	std::pair < std::string, std::string > std_pair1;			//default constructor
	std::pair < std::string, int > std_pair2("temperature", 25);	//value init
	std::pair < std::string, int > std_pair3(std_pair2);			//copy constructor

	M_printContentPair(my_pair1, std_pair1);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(my_pair2, std_pair2);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(my_pair3, std_pair3);

	std::cout << BLUE3 << "Operator= : " << END << std::endl;
	ft::pair <std::string, int> my_pair4;
	my_pair4 = my_pair3;

	std::pair <std::string, int> std_pair4;
	std_pair4 = std_pair3;

	M_printContentPair(my_pair4, std_pair4);

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

	M_printContentPair(my_pair, std_pair);
}

void	M_testRBTInsertAndDelete(void)
{

	std::cout << BLUE1 << "/*_________________________ INSERTION _________________________*/" << END << std::endl;

	ft::RBTree<int, ft::pair<int, std::string> >	my_rbt1;
	ft::RBTree<int, ft::pair<int, int> >			my_rbt2;


	std::cout << BLUE3 << std::endl << "/* increasing insertion with int and string*/" << END << std::endl;
	my_rbt1.insert(ft::make_pair<int, std::string> (1, "un"));
	my_rbt1.insert(ft::make_pair<int, std::string>(2, "deux"));
	my_rbt1.insert(ft::make_pair<int, std::string>(3, "trois"));	
	my_rbt1.insert(ft::make_pair<int, std::string>(4, "quatre"));
	
	std::cout << "INSERT - my_rbt1" << std::endl;
	my_rbt1.printTree();

	std::cout << BLUE3 << std::endl << "/* insertion with pair of int */" << END << std::endl;
	my_rbt2.insert(ft::make_pair<int, int>(1, 1));
	// my_rbt2.insert(ft::make_pair<int, int>(12, 12));
	my_rbt2.insert(ft::make_pair<int, int>(5, 5));
	// my_rbt2.insert(ft::make_pair<int, int>(44, 44));


	std::cout << "INSERT - my_rbt2" << std::endl;
	my_rbt2.printTree();
	/**
	 * @todo change to : delete_tree
	 * 
	 */
	my_rbt2.delete_node(ft::make_pair <int, int>(1, 1));
	my_rbt2.delete_node(ft::make_pair <int, int>(5, 5));
	std::cout << "check if empty : ";
	my_rbt2.printTree(); //check if empty 

	std::cout << BLUE3 << std::endl << std::endl << "/* re insertion in the same tree (but empty) */" << END << std::endl;
	my_rbt2.insert(ft::make_pair<int, int>(3, 3));
	my_rbt2.insert(ft::make_pair<int, int>(4, 4));

	my_rbt2.printTree();

	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ DELETION _________________________*/" << END << std::endl;

	std::cout << BLUE3 << std::endl << "/* delete node with pair value */" << END << std::endl;
	my_rbt1.delete_node(ft::make_pair <int, std::string> (2, "deux"));

	std::cout << "DELETE NODE - my_rbt1" << std::endl;
	my_rbt1.printTree();

	std::cout << BLUE3 << std::endl << "/* delete all node of the tree without using delete_tree */" << END << std::endl;
	my_rbt2.printTree();
	my_rbt2.delete_node(ft::make_pair <int, int> (3, 3));
	my_rbt2.delete_node(ft::make_pair <int, int> (4, 4));
	std::cout << "check if empty :";
	my_rbt2.printTree();

	std::cout << std::endl << std::endl << BLUE3 << "/* delete node with unexistante value */" << END << std::endl;
	my_rbt1.delete_node(ft::make_pair <int, std::string> (5, "cinq"));


	// std::cout << std::endl << BLUE3 << "/* delete node with node value */" << END << std::endl;
	/**
	 * @todo use delete_node with node value
	 * 
	 */
	//my_rbt1.delete_node();

	// std::cout << BLUE3 << std::endl << "/* delete_tree */" << END << std::endl;
	// my_rbt1.delete_tree();
	// std::cout << "check if empty : ";
	// my_rbt1.printTree();
}

void	testMap(void)
{
	/* ------------------------------------------------------------- */
	/* --------------------------- PAIR ---------------------------- */	
	/* ------------------------------------------------------------- */

	/*____________________________ ft::pair ____________________________ */

	// M_testPairConstructors();
	// std::cout << std::endl;

	// M_testPairComparaisons();
	// std::cout << std::endl;

	// M_testMakePair();
	// std::cout << std::endl;

	/* ------------------------------------------------------------- */
	/* --------------------------- RBTree -------------------------- */	
	/* ------------------------------------------------------------- */

	M_testRBTInsertAndDelete();
	std::cout << std::endl;

	/* ------------------------------------------------------------- */
	/* --------------------------- MAP ----------------------------- */	
	/* ------------------------------------------------------------- */

}