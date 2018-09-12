#include <iostream>
#include <list>
#include <string>
#include "C:\Users\anric\Prova_EDB2_Unidade_1\Questao 4\hash.hpp"
using namespace std;

int main(){
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(3);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insercao(a[i]);

  h.imprimir();
  // delete 12 from hash table
  h.remocao(13);

  // display the Hash table
  h.imprimir();

  return 0;
}
