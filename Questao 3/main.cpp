#include <iostream>
#include <vector>
#include <string>
#include "C:\Users\anric\Prova_EDB2_Unidade_1\Questao 3\lista_encadeada.hpp"
using namespace std;

int main(){
	Lista_encadeada lista;
	lista.remocao();
    lista.insercao(5);
    lista.insercao(6);
    lista.insercao(7);
    lista.insercao(8);
    lista.insercao(9);

    lista.imprimir();

    lista.swap(1,2);

    lista.imprimir();
    lista.getTamanho();

	return 0;

}
