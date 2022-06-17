#include "include/hash.h"
#include "iostream"
#include <math.h>

using namespace std;

Hash::Hash(int tam) {
    this->tamanho = tam;
    this->tabela = new List[this->tamanho];
    this->metodoFuncaoHash = 1;

    for(int i = 0; i < this->tamanho; i++)
        tabela[i].iniciarLista();
}

Hash::~Hash(){
    delete [] this->tabela;
}

int Hash::funcaoHashPorDivisao(string chave){
    unsigned int auxiliar = 0;

    for(int i = 0; i < chave.length(); i++){
        auxiliar += chave[i] * (i + 1);
    }
    return (auxiliar % this->tamanho);
}

int Hash::funcaoHashMultiplicacao(string chave){
    unsigned int auxiliar = 0;

    for(int i = 0; i < chave.length(); i++){
        auxiliar += chave[i] * (i + 1);
    };

    return this->tamanho * ( fmod(auxiliar * this->K, 1));
}

void Hash::inserir(string chave, int metodo) {
    this->metodoFuncaoHash = metodo;
    int id;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    this->tabela[id].inserir(chave);
}

void Hash::remover(string chave) {
    int id;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    this->tabela[id].remover(chave);
}

No* Hash::buscar(string chave) {
    int id;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    return this->tabela[id].buscar(chave);
}


void Hash::buscarComInfos(string chave){
    int id;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    if(this->tabela[id].buscarBool(chave)){
        cout << "Lista: " << id <<  " | Posicao: " << tabela[id].buscarId(chave) << endl;
    }
    else{
        cout << "Item nao encontrado!" << endl;
    }
}

int Hash::totalDeColisao() {
    int soma = 0;
    for(int i = 0 ; i < this->tamanho; i++){
        No* auxiliar = this->tabela[i].getInicio();
        while(auxiliar){
            soma += auxiliar->getColisoes();
            auxiliar = auxiliar->getProximo();
        }
    }
    return soma;
}

int Hash::totalDeRepeticoes() {
    int soma = 0;
    for(int i = 0 ; i < this->tamanho; i++){
        No* auxiliar = this->tabela[i].getInicio();
        while(auxiliar){
            soma += auxiliar->getRepeticoes();
            auxiliar = auxiliar->getProximo();
        }
    }
    return soma;
}

int Hash::totalDeItens() {
    int soma = 0;
    for(int i = 0 ; i < this->tamanho; i++){
        soma+= this->tabela[i].getTamanho();
    }
    return soma;
}

int Hash::repeticaoPalavra(string chave) {
    int id;
    int repeticoes = 0;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    if(this->tabela[id].buscarBool(chave)){
        repeticoes = this->tabela[id].repeticaoPalavra(chave);
    }
    else{
        return -1;
    }
    return repeticoes;
}

int Hash::colisaoPalavra(string chave) {
    int id;
    int colisoes = 0;

    if(this->metodoFuncaoHash == 1)
        id = funcaoHashPorDivisao(chave);
    else
        id = funcaoHashMultiplicacao(chave);

    if(this->tabela[id].buscarBool(chave)){
        colisoes = this->tabela[id].colisaoPalavra(chave);
    }
    else{
        return -1;
    }
    return colisoes;
}

void Hash::imprimir() {

    for(int i = 0; i < this->tamanho; i++){
        cout  << "\nLista: " << i << " - ";
        this->tabela[i].imprimir();
    }
}
