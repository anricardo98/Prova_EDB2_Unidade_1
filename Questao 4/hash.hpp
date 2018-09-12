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

//Cria��o da tabela de dispers�o, caso n�o seja indicado o valor est� ser� composta por 5 buckets
Hash::Hash(int tamanho = 5){
	this->tamanho = tamanho; //determinando o tamanho da tabela
	tabela = new list<int>[this->tamanho]; //cria��o de uma lista com a determinada quantidade de buckets
}

//fun��o de inser��o de elementos
void Hash::insercao(int chave){
	int posicao = funcao_hash(chave); //determina��o da posi��o onde o elemento ser� alocado
	tabela[posicao].push_back(chave); //aloca��o do elemento na �ltima posi��o daquele bucket
	cout << "Elemento adicionado" << endl;
}

//fun��o de remo��o de elementos
void Hash::remocao(int chave){
	list<int>::iterator itr; //determina��o de um iterador que ir� percorrer as listas
	int posicao = funcao_hash(chave); //determina��o da posi��o onde determinado elemento deveria est�.
	//verificando se o elemento est� presente na tabela
	for(itr = tabela[posicao].begin(); itr != tabela[posicao].end(); itr++){
		if (*itr == chave){ //se o iterador for igual a chave, sai do loop.
			break;
		}
	}

    //se o elemento estava presente na lista, este ser� apagado. Sen�o, ser� printado a mensagem
	if (itr != tabela[posicao].end()){
		tabela[posicao].erase(itr);
	} else{
        cout << "Elemento n�o encontra-se na lista" << endl;
	}
}

//Implementa��o da chave de inser��o, que devolver� o resto da divis�o inteira da chave pela quantidade de buckets
int Hash::funcao_hash(int chave){
	return (chave%(tamanho));
}

//Fun��o respons�vel por printar os valores na tela.
void Hash::imprimir(){
    //percorre todos os buckets, imprimindo os elementos nele presentes
	for (int i = 0; i < tamanho; i++){
		cout << i;

		for (auto x: tabela[i]){
			cout << "- " << x;
		}

        cout << endl;
	}
}

#endif
