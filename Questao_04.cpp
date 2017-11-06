/**
 * @file	questão04.cpp
 * @brief	.
 *
 * @author	Josivan Medeiros da Silva Gois
 * @since	05/11/2017
 * @date	05/11/2017
 */
#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <algorithm>
using std::transform;

/*
 * @brief	Função que retorna o quadrado de um valor.
 */
int square(int val) {
	return val * val;
}

/*
 * @brief	O Programa aplica o quadrado nos valores de 1 até 9.
 *
 * @details	A função transform aplica a função square a cada elemento do vector col. O terceiro argumento deve ser um iterator para a primeira posição do container que vai receber os valores. Porém, como a função apenas acessa o container e o col2 não tem espaço alocado para receber os valores, é necessário usar a função back_inserter para inserir o valor criando um iterador para o fim do container.
 */

int main(int argc, char* argv[]) {
	vector<int> col;
	vector<int> col2;

	for (int i = 1; i <= 9; ++i) {
		col.push_back(i);
	}
	
	transform(col.begin(), col.end(), back_inserter(col2), square);
	
	for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
	
	return 0;
}