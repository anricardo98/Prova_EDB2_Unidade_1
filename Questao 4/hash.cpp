#include <iostream>
#include <list>
#include <string>
#include "hash.hpp"
using namespace std;

//Criação da tabela de dispersão, caso não seja indicado o valor está será composta por 5 buckets
Hash::Hash(int tamanho = 5){
	this->tamanho = tamanho; //determinando o tamanho da tabela
	tabela = new list<int>[this->tamanho]; //criação de uma lista com a determinada quantidade de buckets
}

//função de inserção de elementos
void Hash::insercao(int chave){
	int posicao = funcao_hash(chave); //determinação da posição onde o elemento será alocado
	tabela[posicao].push_back(chave); //alocação do elemento na última posição daquele bucket
	cout << "Elemento adicionado" << endl;
}

//função de remoção de elementos
void Hash::remocao(int chave){
	list<int>::iterator itr; //determinação de um iterador que irá percorrer as listas
	int posicao = funcao_hash(chave); //determinação da posição onde determinado elemento deveria está.
	//verificando se o elemento está presente na tabela
	for(itr = tabela[posicao].begin(); itr != tabela[posicao].end(); itr++){
		if (*itr == chave){ //se o iterador for igual a chave, sai do loop.
			break;
		}
	}

    //se o elemento estava presente na lista, este será apagado. Senão, será printado a mensagem
	if (itr != tabela[posicao].end()){
		tabela[posicao].erase(itr);
	} else{
        cout << "Elemento não encontra-se na lista" << endl;
	}
}

//Implementação da chave de inserção, que devolverá o resto da divisão inteira da chave pela quantidade de buckets
int Hash::funcao_hash(int chave){
	return (chave%(tamanho));
}

//Função responsável por printar os valores na tela.
void Hash::imprimir(){
    //percorre todos os buckets, imprimindo os elementos nele presentes
	for (int i = 0; i < tamanho; i++){
		cout << i;
		for (auto x: tabela[i]){
			cout << " - " << x;
		}

        cout << endl;
	}
}