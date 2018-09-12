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

//Construtor da lista encadeada
Lista_encadeada::Lista_encadeada(){
	//definindo os indicadores de início e fim e fazendo um apontar para o outro, já que a lista encontra-se vazia.
	inicio = new Node();
	fim = new Node();
	inicio->prox = fim;
	fim->ant = inicio;
	tamanho = 0;
	cout << "lista criada" << endl;
}

//Destrutor da lista encadeada
Lista_encadeada::~Lista_encadeada(){
	Node *iterador = inicio->prox; //definição de um iterador
	//este que passa por todos os elementos e apaga eles
	while(iterador != fim){
		iterador = iterador->prox;
		delete iterador->ant;
	}
    //deletando os indicadores de início e fim
	delete inicio;
	delete fim;
}

//função que retorna o tamanho da lista
int Lista_encadeada::getTamanho(){
	return tamanho;
}

//Função que imprime os valores da lista
void Lista_encadeada::imprimir(){
    //se a lista tiver vazia, imprime esta mensagem e acaba o processo.
	if (tamanho == 0){
        cout << "Lista vazia" << endl;
        abort();
	}
	//define um iterador apontando para o primeiro elemento da lista
	Node *iterador = inicio->prox;

	//enquanto for diferente do fim, passará por todos os elementos imprimindo eles.
	while (iterador != fim){
		cout << iterador->chave << endl;
		iterador = iterador->prox;
	}

}

//Função que recebe uma chave e insere um novo nó
void Lista_encadeada::insercao(int chave){
	//se a lista estiver vazia, insere na primeira posição da lista
	if (tamanho == 0){
		Node *novo = new Node(chave);
		inicio->prox = novo;
		fim->ant = novo;
		novo->ant = inicio;
		novo->prox = fim;
	} else { //senão, o nó será inserido no final da lista
		Node *iterador = fim->ant;
		Node *novo = new Node(chave);
		iterador->prox = novo;
		fim->ant = novo;
		novo->ant = iterador;
		novo->prox = fim;
	}

	tamanho++; //adiciona mais um ao valor da variável tamanho
	cout << "Chave adicionada" << endl; //imprime a seguinte mensagem
}

void Lista_encadeada::remocao(){
    //se houver algum elemento na lista, apagará o primeiro elemento dele
	if (tamanho > 0){
		Node *iterador = inicio->prox;
		iterador->ant->prox = iterador->prox;
		iterador->prox->ant = iterador->ant;
		delete iterador;
		tamanho--; //tira um da quantidade de nós na lista
		cout << "primeiro elemento removido" << endl; // imprime a seguinte mensagem
	} else {//caso a lista esteja vazia, apenas imprimirá a seguinte mensagem
		cout << "Não ha elemento para ser removido" << endl;
	}
}

//função que troca os nós nas posições indicadas
//assim como nos demais casos, consideramos a primeira posição como 1 e não como 0.
void Lista_encadeada::swap(int posicao_1, int posicao_2){
    //se nenhuma das posições forem maior que o tamanho e se os elementos forem diferentes, realizará a troca dos elementos
	if (posicao_1 <= tamanho && posicao_2 <= tamanho && posicao_1 != posicao_2){
		//iterador1 armazena o elemento que se encontra na primeira posição indicada
		//e o temp1 armazena o elemento na posição anterior
		Node *iterador1 = inicio->prox;
		Node *temp1 = iterador1->ant;
		//iterador2 armazena o elemento encontra na segunda posição indicada e o temp2 armazena o elemento na posição anterior
		Node *iterador2 = inicio->prox;
		Node *temp2 = iterador2->ant;

        //atribuição do valor ao iterador1 e do temp1
		for (int i = 0; i < posicao_1 - 1; i++){
            temp1 = iterador1;
			iterador1 = iterador1->prox;
		}

		//atribuição do valor ao iterador2 e do temp2
		for (int i = 0; i < posicao_2 - 1; i++){
            temp2 = iterador2;
			iterador2 = iterador2->prox;
		}

        //realização das trocas
        //temp é um valor auxiliar, que auxilia nessa troca
		temp1->prox = iterador2;
		temp2->prox = iterador1;
		Node *temp = iterador2->prox;
		iterador2->prox = iterador1->prox;
		iterador1->prox = temp;

	} else { //senão for possível realizar a troca, a mensagem abaixo será impressa
		cout << "Alguma das posicoes é incorreta" << endl;
	}

}

#endif
