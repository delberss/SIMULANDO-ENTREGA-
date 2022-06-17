#ifndef TRABALHO_PRATICO_PARTE_1_DNP_NO_H
#define TRABALHO_PRATICO_PARTE_1_DNP_NO_H

#include "string"
using namespace std;


class No{
private:
    string chave;
    No* proximo;
    int colisoes;
    int repeticoes;
public:
    No();
    ~No();

    int contaRepeticoes();

    int contaColisoes();
    int getColisoes();

    No* getProximo();
    void setProximo(No* novoNo);

    int getRepeticoes();
    void setChave(string chave);
    string getChave();

};
#endif //TRABALHO_PRATICO_PARTE_1_DNP_NO_H
