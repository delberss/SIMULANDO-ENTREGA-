#ifndef TRABALHO_PRATICO_PARTE_1_DNP_LIST_H
#define TRABALHO_PRATICO_PARTE_1_DNP_LIST_H

#include "no.h"

class List{
private:
    No* inicio;
    int tamanho;

public:
    List();

    void iniciarLista();
    void inserir(string chave);
    void remover(string chave);
    No* buscar(string chave);
    bool buscarBool(string chave);
    int buscarId(string chave);
    void imprimir();


    int repeticaoPalavra(string chave);
    int colisaoPalavra(string chave);

    No* getInicio();
    int getTamanho();
};
#endif //TRABALHO_PRATICO_PARTE_1_DNP_LIST_H

