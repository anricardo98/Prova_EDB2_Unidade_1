#include <iostream>
#include <list>
#include <string>
#include "hash.hpp"
using namespace std;

int main(){

  //declaracao de variáveis
  int lista_base[] = {3, 11, 4, 1, 22}; //declaracao de uma lista base para já ter elementos inseridos
  int tamanho = sizeof(lista_base)/sizeof(lista_base[0]); //armazena a quantidade de elementos na lista
  int resposta; //variável responsável por receber as acoes que o usuário deseja realizar
  int loop = 1; //variável responsável pela realização do loop de perguntas
  int aux; //variável auxilar que recebe valores dados pelo usuário
  
  //recebimento do número de buckets da tabela
  cout << "Quantos buckets serao adicionados?" << endl;
  cin >> aux;

  if(resposta < 0){ //se o numero indicado for inválido, apenas ocorrerá a impressão da mensagem
    cout << "Resposta invalida. Reinicie o programa" << endl;

  } else {
    //criação da tabela de dispersão e inserção dos elementos pré-determinados
    Hash tabela(resposta);
    for (int i = 0; i < tamanho; i++){
      tabela.insercao(lista_base[i]);
    }
  
    //realização de um loop para caso o usuário deseje realizar mais de uma operação
    while (loop == 1){
    
      //recebimento da ação que será realizada
      cout << "O que voce deseja fazer?" << endl;
      cout << "Digite '1' para inserir um novo item" << endl;
      cout << "Digite '2' para remover um item" << endl;
      cout << "Digite '3' para imprimir a lista" << endl;
      cin >> resposta;

      if (resposta == 1){ //operação de inserção de um elemento
        cout << "Qual numero inteiro voce deseja adicionar?" << endl;
        cin >> aux;
        tabela.insercao(aux);
        tabela.imprimir();

      } else if (resposta == 2){ //operação de remoçao de um elemento
        cout << "Qual numero inteiro voce deseja remover?" << endl;
        cin >> aux;
        tabela.remocao(aux);
        tabela.imprimir();

      } else if (resposta == 3){ //impressão dos elementos da tabela
        tabela.imprimir();

      } else {//caso a resposta tenha sido inválida, a mensagem a seguir será mostrada
        cout << "Resposta invalida" << endl;
      }
  
      //verificação de se o usuário deseja realizar mais alguma operação
      cout << "Deseja realizar mais alguma acao? Se sim, digite '1', senao digite outro numero" << endl;
      cin >> loop;

    }
  }

  //termino da operação
  return 0;
}
