/**
 * @file	questão01.cpp
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