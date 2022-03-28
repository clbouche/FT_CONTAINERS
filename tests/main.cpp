#include "../containers/map.hpp"
#include "../containers/stack.hpp"
#include "../containers/vector.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"
#define SIZE 52
#include <iostream>
#include <iomanip>
#include "test.hpp"

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

int main(void)
{

	printTitle("vector");
	testVector();
	std::cout << std::endl;

	// printTitle("stack");
	// testStack();
	// std::cout << std::endl;

	// printTitle("map");
	// testMap();
	// std::cout << std::endl;

	return (0);
}