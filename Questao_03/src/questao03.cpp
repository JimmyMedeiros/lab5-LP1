/**
 * @file	questão03.cpp
 * @brief	Função que recebe como parâmetro um container, um label e um separador e imprime todos os elementos do container
 *
 * @author	Josivan Medeiros da Silva Gois
 * @since	05/11/2017
 * @date	05/11/2017
 */
#include <complex>	//std::sqrt
using std::sqrt;
#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::cin;
using std::endl;

class IsPrime
{
public:
	IsPrime();
	~IsPrime();
	bool operator()(int n)
	{
		int max = sqrt(n)+1;
		bool isPrime = true;

		if ( n%2 == 0 )
			return false;

		for(int i = 3; i < max; i+=2)
			if(n % i == 0)
				return false;

		return true;
	}
};


int main() {
	int intervalo;
	vector<int> numeros;

	cout << "Digite um valor máximo ara o intervalo" << endl;
	cin >> intervalo;

	for (int i = 1; i <= intervalo; ++i)
	{
		numeros.push_back(i);
	}

	for (auto i = num.begin(); i != .end(); ++i)
	{
		
	}

	return 0;
}