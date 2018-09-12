#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

//Função responsável por desenvolver a lista encadeada
class Lista_encadeada{
private:
    //struct responsável pela criação dos nós
	struct Node{
	public:
		int chave; //armazena a chave do nó
		Node *prox; //armazena o endereço do nó que vem após este
		Node *ant; // armazena o endereço do nó anterior a este
		Node () = default; //construtor de um nó, definindo como comum
		Node (int _chave): //construtor de um nó que recebe o valor da chave como parâmetro
			chave(_chave), //define a chave
			prox(nullptr), //define como nulo o prox e o ant
			ant(nullptr){}
	};
	int tamanho; //variável que armazena o tamanho da lista
	Node *inicio; //nó que indica o início da lista
	Node *fim; //nó que indica o fim da lista

public:
	Lista_encadeada(); //construtor da lista encadeada
	~Lista_encadeada(); //destrutor da lista encadeada
	int getTamanho(); //função que retorna o tamanho da lista
	void imprimir(); //função que imprime a lista
	void insercao(int chave); //função que insere o elemento na ultima posição da lista
	void remocao();//função que remove o primeiro elemento da lista
	void swap(int posicao_1, int posicao_2); //função que troca dois nós
};

#endif
