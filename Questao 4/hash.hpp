#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <list>
#include <vector>
using namespace std;

//definindo função responsável pela tabela de dispersão, nesse caso estamos desenvolvendo a inserção e remoção de elementos
class Hash{
private:
	list<int> *tabela; //criação de um ponteiro de listas
	int tamanho;// variável que determina a quantidade de buckets na tabela de dispersão

public:
	Hash(int tamanho); //construtor da tabela hash
	void insercao(int chave); //função responsável pela inserção de elementos
	void remocao(int chave); //função responsável pela inserção de elementos
	int funcao_hash(int chave); //função que determina aonde determinado elemento será alocado na tabela de dispersão
	void imprimir(); // função que printa os resultados
};

#endif
