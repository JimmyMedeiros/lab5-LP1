/**
 * @file	questão03.cpp
 * @brief	Função que recebe como parâmetro um container, um label e um separador e imprime todos os elementos do container
 *
 * @author	Josivan Medeiros da Silva Gois
 * @since	05/11/2017
 * @date	05/11/2017
 */
#include <complex>	//std::sqrt
#include <algorithm>    // std::find_if
#include <vector>
#include <string>     // std::string, std::stoi
#include <iostream>
using namespace std;

/*
 * @brief	Functor para verificar se o número é primo
 */
class IsPrime
{
public:
	IsPrime(){};
	~IsPrime(){};
	bool operator()(int n)
	{
		int max = sqrt(n)+1;
		if ( n == 2 )
			return true;

		if ( n == 1 or n%2 == 0 )
			return false;

		for(int i = 3; i < max; i+=2)
			if(n % i == 0)
				return false;

		return true;
	}
};

int main( int argc, char const *argv[] ) {
	int intervalo;
	vector<int> numeros;

	if ( argc < 2 )
	{
		cerr << "Lacking argument" << endl;
		return EXIT_FAILURE;
	}
	if ( argc > 2 )
	{
		cerr << "Too many argument" << endl;
		return EXIT_FAILURE;
	}

	try 
	{
		intervalo = stoi( (argv[1]) );
    }
	catch (const std::invalid_argument& ia) 
	{
		std::cerr << "Invalid argument: " << ia.what()<< '\n';
		return EXIT_FAILURE;
	}

	for ( int i = 1; i <= intervalo; ++i )
		numeros.push_back(i);

	auto it_init = find_if( numeros.begin(), numeros.end(), IsPrime() );
	auto it_end = numeros.end();

	cout << "Numeros primos [1-" << intervalo <<"]: ";

	while ( it_init != it_end )
	{
		cout << *it_init << " ";
		it_init = find_if(it_init+1, numeros.end(), IsPrime() );
	}
	cout << endl;

	return 0;
}