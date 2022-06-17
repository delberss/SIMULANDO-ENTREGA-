#ifndef TRABALHO_PRATICO_PARTE_1_DNP_HASH_H
#define TRABALHO_PRATICO_PARTE_1_DNP_HASH_H

#include <string.h>
#include "list.h"
#include "no.h"


using namespace std;

class Hash{
private:
    int tamanho;
    int quantidadeItens;
    const float K = 0.4;
    List * tabela;
    int funcaoHashPorDivisao(string chave);
    int funcaoHashMultiplicacao(string chave);
    int metodoFuncaoHash; // Pode ser escolhido qual metodo hash usar ao inserir chave

public:
    Hash(int tam);
    ~Hash();

    void inserir(string chave, int metodo);
    No* buscar(string chave);
    void buscarComInfos(string chave);
    void remover(string chave);
    int repeticaoPalavra(string chave);
    int colisaoPalavra(string chave);
    int totalDeRepeticoes();
    int totalDeColisao();
    int totalDeItens();
    void imprimir();

};
#endif //TRABALHO_PRATICO_PARTE_1_DNP_HASH_H

