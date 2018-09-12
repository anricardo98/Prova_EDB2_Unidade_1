#include <iostream>
#include <vector>
#include <string>
#include "lista_encadeada.hpp"
using namespace std;

int main(){ 
    //declaração de variáveis
	Lista_encadeada lista; //criação da lista
    int loop = 1; //variável responsável pela realização do loop de perguntas
    int resposta; //variável responsável por receber as acoes que o usuário deseja realizar
    int aux; //variável auxilar que recebe valores dados pelo usuário
    int aux1; //variável utilizada na função swap

    //declaração de elementos pré-determinados para não deixar a lista vazia
    lista.insercao(9);
    lista.insercao(5);
    lista.insercao(7);

    //realização de um loop para caso o usuário deseje realizar mais de uma operação
	while (loop == 1){
    
      //recebimento da ação que será realizada
      cout << "O que voce deseja fazer?" << endl;
      cout << "Digite '1' para inserir um novo item" << endl;
      cout << "Digite '2' para remover o ultimo item" << endl;
      cout << "Digite '3' para imprimir a lista" << endl;
      cout << "Digite '4' para imprimir o tamanho da lista" << endl;
      cout << "Digite '5' para realizar o swap entre dois elemento da lista" << endl;
      cin >> resposta;

      if (resposta == 1){ //operação de inserção de um elemento
        cout << "Qual numero inteiro voce deseja adicionar?" << endl;
        cin >> aux;
        lista.insercao(aux);
        lista.imprimir();

      } else if (resposta == 2){ //operação de remoçao do último elemento da lista
        lista.remocao();
        lista.imprimir();

      } else if (resposta == 3){ //impressão dos elementos da lista
        lista.imprimir();

      } else if (resposta == 4){ //impressão do tamanho da lista 
        cout << "A lista apresenta tamanho de " << lista.getTamanho() << endl;

      } else if (resposta == 5){ //realização da operação de troca pela indicação das suas posições
        cout << "Digite a posicao do primeiro elemento que voce deseja trocar" << endl;
        cout << "Considerando a primeira posicao como 1" << endl;
        cin >> aux;
        cout << "Digite a posicao do segundo elemento que voce deseja trocar" << endl;
        cin >> aux1;
        lista.swap(aux, aux1);
        lista.imprimir();

      }else {//caso a resposta tenha sido inválida, a mensagem a seguir será mostrada
        cout << "Resposta invalida" << endl;
      }
  
      //verificação de se o usuário deseja realizar mais alguma operação
      cout << "Deseja realizar mais alguma acao? Se sim, digite '1', senao digite outro numero" << endl;
      cin >> loop;

    }
  //Destrutor da lista
  lista.~Lista_encadeada();

  //termino da operação
  return 0;
}
