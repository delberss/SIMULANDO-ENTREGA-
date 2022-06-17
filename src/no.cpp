#include "include/no.h"

No::No(){
    this->repeticoes = 0;
    this->colisoes = 0;
    this->proximo = nullptr;
}

No* No::getProximo(){
    return this->proximo;
}
void No::setProximo(No* novoNo){
    this->proximo = novoNo;
}

int No::contaColisoes(){
    this->colisoes++;
}

int No::getColisoes(){
    return this->colisoes;
}

int No::contaRepeticoes(){
    this->repeticoes++;
}

int No::getRepeticoes(){
    return this->repeticoes;
}

void No::setChave(string chave){
    this->chave = chave;
}
string No::getChave(){
    return this->chave;
}