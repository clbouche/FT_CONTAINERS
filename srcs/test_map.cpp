#include "../includes/utils/utils_pair.hpp"
#include "../includes/RBTree/algo.hpp"
#include "../includes/RBTree/RBT_node.hpp"
#include "../includes/map.hpp"

#include <map>
#include <cstdlib>
#include <iostream>
#include <iomanip>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"

using namespace NS;

#define SIZE 52

template <typename T1, typename T2>
void	M_printContentPair(NS::pair<T1, T2>& pair)
{
	std::cout << BLUE3 << "content of pair : " << END << std::endl;
	std::cout << "first element is : " << pair.first << std::endl;
	std::cout << "second element is : " << pair.second << std::endl;
	
	std::cout << std::endl;
}


void	M_testPairConstructors(void) 
{
	std::cout << BLUE1 << "/*__________________________Constructors pair __________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Constructors: " << END << std::endl;
	NS::pair < std::string, std::string > pair1;				//default constructor
	NS::pair < std::string, int > pair2("temperature", 25);	//value init
	NS::pair < std::string, int > pair3(pair2);					//copy constuctor


	M_printContentPair(pair1);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(pair2);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(pair3);

	std::cout << BLUE3 << "Operator= : " << END << std::endl;
	NS::pair <std::string, int> pair4;
	pair4 = pair3;

	M_printContentPair(pair4);

}

// void	M_testPairComparaisons(void)
// {
// 	std::cout << BLUE1 << "/*__________________________Comparaisons__________________________*/" << END << std::endl;

// 	std::cout << BLUE3 << "Operator==: " << END << std::endl;
// 	ft::pair < int, char> my_pair1_1(1, 'a');
// 	ft::pair < int, char> my_pair1_2(1, 'a');
// 	ft::pair < int, char > my_pair2(2, 'b');
// 	ft::pair < float, char > my_pair3(4.6, 'c');

// 	std::pair < int, char> std_pair1_1(1, 'a');
// 	std::pair < int, char> std_pair1_2(1, 'a');
// 	std::pair < int, char > std_pair2(2, 'b');
// 	std::pair < float, char > std_pair3(4.6, 'c');

// 	std::cout << "1 - ";
// 	if (my_pair1_1 == my_pair1_2) 
// 		std::cout << "my pairs are equals";
// 	std::cout << std::endl << "1 - ";
// 	if (std_pair1_1 == std_pair1_2)
// 		std::cout << "std pairs are equals";

// 	std::cout << std::endl << "2 - ";
// 	if (my_pair1_1 == my_pair2) 
// 		std::cout << "my pairs are equals";
// 	std::cout << std::endl << "2 - ";
// 	if (std_pair1_1 == std_pair2) 
// 		std::cout << "std pairs are equals"; 

// 	//NE PEUT PAS COMPILER - comportement normal
// 	// std::cout << std::endl << "3 - ";
// 	// if (my_pair1_1 == my_pair3) 
// 	// 	std::cout << "my pairs are equal";
// 	// std::cout << std::endl << "3 - ";
// 	// if (std_pair1_1 == std_pair3) 
// 	// 	std::cout << "std pairs are equal"; 
	
// 	std::cout << std::endl << std::endl;

// 	std::cout << BLUE3 << "Operator!=: " << END << std::endl;

// 	std::cout << "4 - ";
// 	if (my_pair1_1 != my_pair2) 
// 		std::cout << "my pairs are differents";
// 	std::cout << std::endl << "4 - ";
// 	if (std_pair1_1 != std_pair2) 
// 		std::cout << "std pairs are differents"; 

// 	std::cout << std::endl;
// 	//tester les autres comparaisons mais j'ai la flemme la en vrai 
// }

// void	M_testMakePair(void)
// {
// 	std::cout << BLUE1 << "/*__________________________MAKE PAIR_________________________*/" << END << std::endl;

// 	ft::pair<int, int> my_pair;
// 	std::pair<int, int> std_pair;

// 	my_pair = ft::make_pair(10, 20);
// 	std_pair = std::make_pair(10, 20);

// 	M_printContentPair(my_pair, std_pair);
// }

// void	M_testRBTInsertAndDelete(void)
// {

// 	std::cout << BLUE1 << "/*_________________________ INSERTION _________________________*/" << END << std::endl;

// 	ft::RBTree<int, ft::pair<int, std::string> >	my_rbt1;
// 	ft::RBTree<int, ft::pair<int, int> >			my_rbt2;


// 	std::cout << BLUE3 << std::endl << "/* increasing insertion with int and string*/" << END << std::endl;
// 	my_rbt1.insert(ft::make_pair<int, std::string> (1, "un"));
// 	my_rbt1.insert(ft::make_pair<int, std::string>(2, "deux"));
// 	my_rbt1.insert(ft::make_pair<int, std::string>(3, "trois"));	
// 	my_rbt1.insert(ft::make_pair<int, std::string>(4, "quatre"));
	
// 	std::cout << "INSERT - my_rbt1" << std::endl;
// 	my_rbt1.printTree();

// 	std::cout << BLUE3 << std::endl << "/* insertion with pair of int */" << END << std::endl;
// 	my_rbt2.insert(ft::make_pair<int, int>(1, 1));
// 	// my_rbt2.insert(ft::make_pair<int, int>(12, 12));
// 	my_rbt2.insert(ft::make_pair<int, int>(5, 5));
// 	// my_rbt2.insert(ft::make_pair<int, int>(44, 44));


// 	std::cout << "INSERT - my_rbt2" << std::endl;
// 	my_rbt2.printTree();
// 	/**
// 	 * @todo change to : delete_tree
// 	 * 
// 	 */
// 	my_rbt2.delete_node(ft::make_pair <int, int>(1, 1));
// 	my_rbt2.delete_node(ft::make_pair <int, int>(5, 5));
// 	std::cout << "check if empty : ";
// 	my_rbt2.printTree(); //check if empty 

// 	std::cout << BLUE3 << std::endl << std::endl << "/* re insertion in the same tree (but empty) */" << END << std::endl;
// 	my_rbt2.insert(ft::make_pair<int, int>(3, 3));
// 	my_rbt2.insert(ft::make_pair<int, int>(4, 4));

// 	my_rbt2.printTree();

// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ DELETION _________________________*/" << END << std::endl;

// 	std::cout << BLUE3 << std::endl << "/* delete node with pair value */" << END << std::endl;
// 	my_rbt1.delete_node(ft::make_pair <int, std::string> (2, "deux"));

// 	std::cout << "DELETE NODE - my_rbt1" << std::endl;
// 	my_rbt1.printTree();

// 	std::cout << BLUE3 << std::endl << "/* delete all node of the tree without using delete_tree */" << END << std::endl;
// 	my_rbt2.printTree();
// 	my_rbt2.delete_node(ft::make_pair <int, int> (3, 3));
// 	my_rbt2.delete_node(ft::make_pair <int, int> (4, 4));
// 	std::cout << "check if empty :";
// 	my_rbt2.printTree();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* delete node with unexistante value */" << END << std::endl;
// 	my_rbt1.delete_node(ft::make_pair <int, std::string> (5, "cinq"));
// }

// void	M_testRBTFixInsertionAndFixDeletion() 
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ FIX INSERTION _________________________*/" << END << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with croissant value (int) */" << END << std::endl;
// 	ft::RBTree<int, ft::pair<int, int> >	my_rbt1;
// 	int		int_array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
// 	int		int_array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

// 	for (int i = 0; i < 20; i++) {
// 		my_rbt1.insert(ft::make_pair(int_array1[i], int_array2[i]));
// 	}
// 	my_rbt1.printTree();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with random value (int) */" << END << std::endl;
// 	ft::RBTree<int, ft::pair<int, int> >	my_rbt2;

// 	int	int_array3[30];
// 	int	int_array4[30];
// 	srand(time(NULL));
// 	for (int i=0 ; i < 30; i++) {
// 		int_array3[i] = rand() % 100;
// 		int_array4[i] = rand() % 100;
// 	}

// 	for (int i = 0; i < 29; i++) {
// 		my_rbt2.insert(ft::make_pair(int_array3[i], int_array4[i]));
// 	}
// 	my_rbt2.printTree();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with random value (int & std::string) */" << END << std::endl;
// 	ft::RBTree<int, ft::pair<int, std::string> >	my_rbt3;

// 	std::string	std_array1[5] = {"bonjour", "bonsoir", "salut", "hola", "hello"};

// 	for (int i = 0; i < 5; i++)
// 		my_rbt3.insert(ft::make_pair(int_array3[i], std_array1[i]));
	
// 	my_rbt3.printTree();

// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ FIX DELETION _________________________*/" << END << std::endl;

// 	my_rbt1.delete_node(ft::make_pair(7, 7));
// 	my_rbt1.printTree();
// }

// void	M_testRBTiterators(void)
// {
// 	ft::RBTree<int, ft::pair<int, int> >	my_rbt;

// 	for (int i = 0; i < 10; i++)
// 		my_rbt.insert(ft::make_pair(i, i));
	
// 	std::cout << "RBTree : " << std::endl;
// 	my_rbt.printTree();

// 	ft::RBTree<int, ft::pair<int, int> > my_copy_rbt(my_rbt);

// 	std::cout << "RBTree copy : " << std::endl;
// 	my_copy_rbt.printTree();
// }

// void	M_testConstructors(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ CONSTRUCTORS _________________________*/" << END << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* default constructor */" << END << std::endl;

// 	ft::map<int, int> 	my_map;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* range constructor */" << END << std::endl;

// 	int		int_array[5] = {1, 2, 3, 4, 5};

//   	for (int i = 0; i < 5; i++) {
// 		my_map.insert(ft::make_pair(int_array[i], int_array[i]));
// 	}

// 	std::cout << "My MAP 1 : " << std::endl;
// 	my_map.printMap();
//   	ft::map<int,int> my_map2 (my_map.begin(),my_map.end());

// 	std::cout << "My MAP 2 : " << std::endl;
// 	my_map2.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* copy constructor */" << END << std::endl;

// 	my_map2.insert(ft::make_pair<int, int>(6, 6));

// 	std::cout << "My MAP 2 + 1 node: " << std::endl;

// 	my_map2.printMap();


// 	ft::map<int, int> my_map3(my_map2);

// 	std::cout << "My MAP 3 : " << std::endl;
// 	my_map3.printMap(); 

// 	std::cout << std::endl << std::endl << BLUE3 << "/* assign operator */" << END << std::endl;

// 	my_map3.insert(ft::make_pair<int, int> (7, 7));

// 	std::cout << "My MAP 3 + 1 node : " << std::endl;
// 	my_map3.printMap(); 
	
// 	ft::map<int, int> my_map4;
	
// 	my_map4 = my_map3;

// 	std::cout << "My MAP 4 : " << std::endl;
// 	my_map4.printMap(); 

// }


// void	M_testElementAccess(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ ELEMENT ACCESS _________________________*/" << END << std::endl;

// 	ft::map<char, int> my_map;

// 	char	char_array[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
// 	int		int_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 	for(int i = 0; i < 10; i++)
// 		my_map.insert(ft::make_pair<char, int> (char_array[i], int_array[i]));
	
// 	my_map.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator[] - print element */" << END << std::endl;

// 	std::cout << "my_map['a'] is " << my_map['a'] << std::endl;
// 	std::cout << "my_map['b'] is " << my_map['b'] << std::endl;
// 	std::cout << "my_map['c'] is " << my_map['c'] << std::endl;
// 	std::cout << "my_map['d'] is " << my_map['d'] << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator[] - insert element if it doesn't exist*/" << END << std::endl;

// 	std::cout << "my_map['k'] is " << my_map['k'] << std::endl << std::endl;

// 	my_map['l'] = 12;

// 	my_map.printMap();
// }

// void	M_testCapacity(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ CAPACITY _________________________*/" << END << std::endl;

// 	ft::map<std::string, std::string>	my_map;
// 	ft::map<int, int> my_empty_map;

// 	std::string		string_array1[5] = {"bonjour", "hello", "hola", "hallo", "ciao"};
// 	std::string		string_array2[5] = {"FR", "EN", "ES", "GE", "IT"};

// 	for (int i = 0; i < 5; i++)
// 		my_map.insert(ft::make_pair(string_array1[i], string_array2[i]));

// 	my_map.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* check if empty */" << END << std::endl;
	
// 	if (my_map.empty() == 0)
// 		std::cout << "map not empty" << std::endl;
// 	else 
// 		std::cout << "map empty" << std::endl;

// 	if (my_empty_map.empty() == 0)
// 		std::cout << "map not empty" << std::endl;
// 	else 
// 		std::cout << "map empty" << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* check size */" << END << std::endl;

// 	std::cout << "size of my_map : " << my_map.size() << std::endl;
// 	std::cout << "size of my_empty_map : " << my_empty_map.size() << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* check max_size */" << END << std::endl;
	
// 	std::cout << "max_size of my_map : " << my_map.max_size() << std::endl;
// 	std::cout << "max_size of my_empty_map : " << my_empty_map.max_size() << std::endl;
// }

// void	M_testInsertAndErase(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ INSERT _________________________*/" << END << std::endl;

// 	ft::map<int, int> my_map;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* insert with value */" << END << std::endl;

// 	my_map.insert(ft::make_pair<int, int>(1, 1));
// 	my_map.insert(ft::make_pair<int, int>(2, 2));
// 	my_map.insert(ft::make_pair<int, int>(3, 3));
// 	my_map.insert(ft::make_pair<int, int>(4, 4));
// 	my_map.insert(ft::make_pair<int, int>(5, 5));

// 	my_map.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* insert range */" << END << std::endl;

// 	ft::map<int, int> my_map2(my_map.begin(), my_map.end());

// 	my_map2.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* insert with value & position*/" << END << std::endl;

// 	ft::map<int, int> my_map3;

// 	my_map3.insert (my_map.begin(), ft::make_pair<int,int>(6, 6)); 
// 	my_map3.insert (my_map.begin(), ft::make_pair<int,int>(7, 7)); 

// 	my_map3.printMap();

// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ ERASE _________________________*/" << END << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* erase with position */" << END << std::endl;

// 	std::cout << "first print : " << std::endl;
// 	my_map.printMap();

// 	std::cout << std::endl << "erase of my_map.begin() " << std::endl;
// 	my_map.erase(my_map.begin());

// 	std::cout << std::endl << "second print : " << std::endl;
// 	my_map.printMap();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* erase range */" << END << std::endl;

// 	ft::map<int, int>::iterator it = my_map2.begin();

// 	it++;
// 	it++;
// 	std::cout << "first print : " << std::endl;
// 	my_map2.printMap();

// 	std::cout << std::endl << "erase of range between my_map.begin() & my_mapbegin()++ " << std::endl;
// 	my_map2.erase(my_map2.begin(), it);

// 	std::cout << std::endl << "second print : " << std::endl;
// 	my_map2.printMap();


// 	std::cout << std::endl << std::endl << BLUE3 << "/* erase with key */" << END << std::endl;

// 	std::cout << "first print : " << std::endl;
// 	my_map3.printMap();

// 	std::cout << std::endl << "erase of 6" << std::endl;
// 	my_map3.erase(6);

// 	std::cout << std::endl << "second print : " << std::endl;
// 	my_map3.printMap();

// }

// void	M_testSwap(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ SWAP _________________________*/" << END << std::endl;

// 	ft::map<char, char> my_map1;
// 	ft::map<char, char> my_map2;

// 	char	char_array1_1[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
// 	char	char_array1_2[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
// 	char	char_array2_1[] = {'s', 'a', 'l', 'u', 't', 'y', 'o'};
// 	char	char_array2_2[] = {'s', 'a', 'l', 'u', 't', 'y', 'o'};

// 	for(int i = 0; i < 7; i++) {
// 		my_map1.insert(ft::make_pair(char_array1_1[i], char_array1_2[i]));
// 		my_map2.insert(ft::make_pair(char_array2_1[i], char_array2_2[i]));
// 	}

// 	std::cout << "print my_map1 :" << std::endl;
// 	my_map1.printMap();
// 	std::cout << std::endl << "print my_map2 :" << std::endl;
// 	my_map2.printMap();

// 	my_map1.swap(my_map2);

// 	std::cout << std::endl << "print my_map1 :" << std::endl;
// 	my_map1.printMap();
// 	std::cout << std::endl << "print my_map2 :" << std::endl;
// 	my_map2.printMap();
// }

// void	M_testRelationalOperators(void)
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ RELATIONAL OPERATORS _________________________*/" << END << std::endl;

// 	ft::map<char, int> my_map1;
// 	ft::map<char, int> my_map2;
// 	ft::map<char, int> my_map3;


// 	my_map1['a'] = 2; my_map1['b'] = 3; my_map1['c'] = 4; my_map1['d'] = 5;
// 	my_map2['a'] = 2; my_map2['b'] = 3; my_map2['c'] = 4; my_map2['d'] = 5;
// 	my_map3['a'] = 2;  my_map3['b'] = 3; my_map3['c'] = 4; my_map3['e'] = 6;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator== */" << END << std::endl;
// 	std::cout << "(my_map1 == my_map2) = " << (my_map1 == my_map2) << std::endl;
// 	std::cout << "(my_map1 == my_map3) = " << (my_map1 == my_map3) << std::endl;
	
// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator!= */" << END << std::endl;
// 	std::cout << "(my_map1 != my_map2) = " << (my_map1 != my_map2) << std::endl;
// 	std::cout << "(my_map1 != my_map3) = " << (my_map1 != my_map3) << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator< */" << END << std::endl;
// 	std::cout << "(my_map1 < my_map2) = " << (my_map1 < my_map2) << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator<= */" << END << std::endl;
// 	std::cout << "(my_map1 <= my_map2) = " << (my_map1 <= my_map2) << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator> */" << END << std::endl;
// 	std::cout << "(my_map1 > my_map2) = " << (my_map1 > my_map2) << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* operator>= */" << END << std::endl;
// 	std::cout << "(my_map1 >= my_map2)  = " << (my_map1 >= my_map2) << std::endl;
// }

// void		M_testObservers(void)
// {

// }

static void	printTitle(std::string title)
{
	static int		first;
	std::string		toPrint;
	unsigned int	size = (SIZE > 10 ? SIZE : 10);
	char			c = '=';
	unsigned int	n;

	if (first > 0)
		std::cout << std::endl;
	else
		first++;

	toPrint = " " + title + " ";
	for (int i = 0; toPrint[i]; i++)
		toPrint[i] = toupper(toPrint[i]);
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << PURPLE << std::setfill(c) << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n - n / 2);
	std::cout << std::setfill(c) << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill(c) << std::setw(size) << "" << END << std::endl << std::endl;
}

int	main(void)
{

	printTitle("map");

	/* ------------------------------------------------------------- */
	/* --------------------------- PAIR ---------------------------- */	
	/* ------------------------------------------------------------- */

	/*____________________________ ft::pair ____________________________ */

	M_testPairConstructors();
	std::cout << std::endl;

	// M_testPairComparaisons();
	// std::cout << std::endl;

	// M_testMakePair();
	// std::cout << std::endl;

	// /* ------------------------------------------------------------- */
	// /* --------------------------- RBTree -------------------------- */	
	// /* ------------------------------------------------------------- */

	// M_testRBTInsertAndDelete();
	// std::cout << std::endl;

	// M_testRBTFixInsertionAndFixDeletion();
	// std::cout << std::endl;

	// M_testRBTiterators();
	// std::cout << std::endl;

	// /* ------------------------------------------------------------- */
	// /* --------------------------- MAP ----------------------------- */	
	// /* ------------------------------------------------------------- */

	// M_testConstructors();
	// std::cout << std::endl;

	// M_testElementAccess();
	// std::cout << std::endl;

	// M_testCapacity();
	// std::cout << std::endl;

	// M_testInsertAndErase();
	// std::cout << std::endl;

	// M_testSwap();
	// std::cout << std::endl;

	// M_testRelationalOperators();
	// std::cout << std::endl;

	// M_testObservers();
	// std::cout << std::endl;

	std::cout << std::endl;

	return (0);
}