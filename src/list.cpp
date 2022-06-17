#include "include/list.h"
#include <iostream>
#include <cstring>

using namespace std;

List::List() {
    this->tamanho = 0;
    this->inicio = nullptr;
}


void List::iniciarLista(){
    this->tamanho = 0;
    this->inicio = nullptr;
}

void List::inserir(string chave){
    No* auxiliar = this->inicio;

    if(this->buscarBool(chave)){
        for(int i=0; i < this->tamanho; i++){
            if(auxiliar->getChave() == chave){
                auxiliar->contaRepeticoes();
                auxiliar->contaColisoes();
            }
            else{
                auxiliar->contaColisoes();
            }
            auxiliar = auxiliar->getProximo();
        }
    }

    else{
        for(int i=0; i < this->tamanho; i++){
            auxiliar->contaColisoes();
            auxiliar = auxiliar->getProximo();
        }

        No* novo = new No;
        novo->setChave(chave);
        novo->setProximo(this->inicio);

        this->inicio = novo;
        tamanho++;
    }
}

void List::remover(string chave) {
    if(buscarBool(chave)){
        if(strcmp(this->inicio->getChave().c_str(), chave.c_str()) == 0){
            cout << this->inicio->getChave() << " foi removido!";
            this->inicio = this->inicio->getProximo();
            this->tamanho--;
            return;
        }

        No *anterior = this->inicio;
        No *auxiliar = this->inicio->getProximo();

        while(auxiliar){
            if(this->inicio->getProximo()){

                if(strcmp(auxiliar->getChave().c_str(), chave.c_str()) == 0){
                    cout << auxiliar->getChave() << " foi removido!";
                    No *no = auxiliar->getProximo();
                    anterior->setProximo(no);
                    this->tamanho--;
                }
            }
            anterior = auxiliar;
            auxiliar = auxiliar->getProximo();
        }
    }
    else{
        cout << "Item nao encontrado para ser removido!\n";
    }
}

No* List::buscar(string chave) {
    if(this->getInicio() != nullptr){
        No* auxiliar = this->inicio;
        while (auxiliar){
            if(auxiliar->getChave() == chave){
                return auxiliar;
            }
            auxiliar = auxiliar->getProximo();
        }
        return nullptr;
    }
    else{
        return nullptr;
    }
}

bool List::buscarBool(string chave) {
    if(this->getInicio() != nullptr){
        No* auxiliar = this->inicio;
        while (auxiliar){
            if(auxiliar->getChave() == chave){
                return true;
            }
            auxiliar = auxiliar->getProximo();
        }
        return false;
    }
    else{
        return false;
    }
}


int List::buscarId(string chave) {
    No* auxiliar = this->inicio;
    for(int i=0; i < this->tamanho; i++){
        if(auxiliar->getChave() == chave){
            return i;
        }
        auxiliar = auxiliar->getProximo();
    }
}

void List::imprimir(){
    cout << "Itens na lista: = " << this->tamanho;

    if(this->inicio != nullptr){
        No* auxiliar = this->inicio;
        while (auxiliar){
            cout << "\nPalavra: " << auxiliar->getChave()  << " | Colisoes: " << auxiliar->getColisoes() << " | Repeticoes: " << auxiliar->getRepeticoes();
            auxiliar = auxiliar->getProximo();
        }
    }
}

int List::repeticaoPalavra(string chave) {
    No* auxiliar = this->inicio;
    while (auxiliar){
        if(auxiliar->getChave() == chave){
            return auxiliar->getRepeticoes();
        }
        auxiliar = auxiliar->getProximo();
    }
}

int List::colisaoPalavra(string chave) {
    No* auxiliar = this->inicio;
    while (auxiliar){
        if(auxiliar->getChave() == chave){
            return auxiliar->getColisoes();
        }
        auxiliar = auxiliar->getProximo();
    }
}

No* List::getInicio(){
    return this->inicio;
}
int List::getTamanho(){
    return this->tamanho;
}
