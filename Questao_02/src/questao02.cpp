/**
 * @file	questão02.cpp
 * @brief	Função que recebe como parâmetro um container, um label e um separador e imprime todos os elementos do container
 *
 * @author	Josivan Medeiros da Silva Gois
  * @since	05/11/2017
  * @date	05/11/2017
  */
#include <set>
using std::set;
#include <iostream>
using std::cout;
using std::endl;

template<typename TContainer>
void print_elementos(const TContainer& collection, const char* label="",
const char separator=' ')
{
	cout << label;
	for (auto it = collection.begin(); it != collection.end(); ++it)
	{
		cout << *it << separator;
	}
	cout << endl;
}


int main() {
	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);
	print_elementos(numeros, "Set: ");
	print_elementos(numeros, "CSV Set: ", ';');
	return 0;
}