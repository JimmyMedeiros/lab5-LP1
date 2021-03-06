/*
 * @file	questao01.cpp
 * @brief	Função que recebe dois iteradores de um intervalo e retorna o valor mais próximo da média desse intervalor
 *
 * @author	Josivan Medeiros da Silva Gois
 * @since	05/11/2017
 * @date	05/11/2017
 */

#include <vector>
using std::vector;

#include <numeric>	// std::accumulate
#include <iterator>	// std::distance
#include <algorithm>// std::for_each
#include <complex>	// std::complex, std::abs
using std::complex;
using std::abs;

template <typename InputIterator>
/*
 * @brief	Função que retorna o valor mais próximo da média de um dado intervalo.
 * @details	Dado um intervalor [first, last), onde first e last são iteradores de containers, a função calcula a média desse intervalo e retorna um iterador para a posição do primeiro elemento encontrado mais próximo do intervalo.
 * @param	first	InputIterator que aponta para o início do intervalo.
 * @param	last	InputIterator que aponta para a posição após o último elemento do intervalo.
 */
InputIterator closest2mean( InputIterator first, InputIterator last )
{
	InputIterator closest = first;
	float mean = std::accumulate( first, last, 0 ) / std::distance(first, last);

	for (auto it = first; it != last; ++it)
	{
		auto diff1 = abs( *it - mean );
		auto diff2 = abs( *closest - mean );
		if ( diff1 < diff2 )
		{
			closest = it;
		}
	}
	//std::for_each(first, last, closest);

	return closest; 
}

#include <iostream>
using std::cout;
using std::endl;

int main() {
	vector<int> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());
	cout << (*result) << endl;
	return 0;
}