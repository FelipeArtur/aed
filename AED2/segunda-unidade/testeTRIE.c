//Breno Bog�a Alves Passos
//Felipe Artur Macedo Lima
#include "arvtrie2.h"
int main()
{
    tp_no *raiz;
    raiz = cria_no('\0');
    char palavra[30];

    strcpy(palavra, "es");
    raiz = insere_no_trie(raiz, palavra);
    raiz = insere_no_trie(raiz, "escola");
    raiz = insere_no_trie(raiz, "pasta");
    raiz = insere_no_trie(raiz, "escada");
    raiz = insere_no_trie(raiz, "abacaxi");
    raiz = insere_no_trie(raiz, "esperanca");

    completa(raiz, palavra);
    return 0;
}
