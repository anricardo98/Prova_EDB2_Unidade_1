#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <list>
#include <vector>
using namespace std;

//definindo fun��o respons�vel pela tabela de dispers�o, nesse caso estamos desenvolvendo a inser��o e remo��o de elementos
class Hash{
private:
	list<int> *tabela; //cria��o de um ponteiro de listas
	int tamanho;// vari�vel que determina a quantidade de buckets na tabela de dispers�o

public:
	Hash(int tamanho); //construtor da tabela hash
	void insercao(int chave); //fun��o respons�vel pela inser��o de elementos
	void remocao(int chave); //fun��o respons�vel pela inser��o de elementos
	int funcao_hash(int chave); //fun��o que determina aonde determinado elemento ser� alocado na tabela de dispers�o
	void imprimir(); // fun��o que printa os resultados
};

#endif
