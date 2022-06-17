#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "include/hash.h"

using namespace std;

int main(){
    Hash hash(11503);

    int funcaoHash = 0;
    do{
        cout << "      FUNCAO HASH      \n[1] FUNCAO DE DIVISAO\n[2] FUNCAO DE MULTIPLICACAO\nESCOLHA:";
        cin >> funcaoHash;
        switch (funcaoHash) {
            case 1:
                cout << "-------------------------------\n";
                cout << "  FUNCAO DE DIVISAO ESCOLHIDA  \n";
                cout << "-------------------------------\n";
                break;
            case 2:
                cout << "FUNCAO DE MULTIPLICACAO ESCOLHIDA\n";
                break;
            default:
                cout << "------------------\n";
                cout << "  ESCOLHA 1 OU 2  \n";
                cout << "------------------\n";
                break;
        }
    }while(funcaoHash != 1 && funcaoHash != 2);

    // ABRE O ARQUIVO NOME_ARQUIVOS
    ifstream arquivo_NomeArquivos;
    arquivo_NomeArquivos.open("../input/nome_arquivos.txt");


    // ABRE ARQUIVO PARA SALVAR AS PALAVRAS DOS LIVROS
    ofstream palavras_book;
    palavras_book.open("palavras_book.txt", ios::out | ios::app );

    if(arquivo_NomeArquivos.is_open()){
        string line_nomeArquivos;

        // ENQUANTO O ARQUIVO NOME_ARQUIVOS NAO CHEGAR AO FIM
        while(!arquivo_NomeArquivos.eof()){
            line_nomeArquivos.clear();
            getline(arquivo_NomeArquivos, line_nomeArquivos);

            // ABRE ARQUIVO COM O LIVRO
            ifstream arquivo_livro;
            arquivo_livro.open("../input/"+line_nomeArquivos);

            if(arquivo_livro.is_open()){
                int quantidade_palavras = 0;
                string line_book;
                string word_book;
                string word_book_correta;
                stringstream auxiliar;

                // ENQUANTO O LIVRO NAO CHEGAR AO FIM
                string comeco = "*** START OF";
                string fim = "*** END OF TH";

                bool pulaInicio = false;
                bool pulaFinal = false;
                while (arquivo_livro.peek() != EOF && !pulaFinal) {
                    line_book.clear();
                    auxiliar.clear();

                    // PEGA UMA LINHA DO LIVRO E COLOCA EM LINE_BOOK
                    getline(arquivo_livro, line_book );

                    // PULA O COMECO DOS LIVROS ATE ACHAR A LINHA: *** START OF...
                    if(!pulaInicio){
                        while(!(strstr(line_book.c_str(),comeco.c_str()))){
                            getline(arquivo_livro, line_book );
                        }
                        getline(arquivo_livro, line_book );
                        pulaInicio = true;
                    }

                    // PULA PARA O FIM DOS LIVROS AO ACHAR A LINHA *** END OF
                    if((strstr(line_book.c_str(),fim.c_str()))){
                        while(arquivo_livro.peek() != EOF){
                            getline(arquivo_livro, line_book );
                        }
                        pulaFinal = true;
                    }

                    // COLOCA A LINHA NO stringstream
                    auxiliar << line_book;

                    // PERCORRE A LINHA SEPARANDO POR PALAVRA - WORD_BOOK
                    while(getline(auxiliar, word_book, ' ')){

                        // COLOCA PALAVRA EM MINUSCULO
                        for(int i=0; i < word_book.length(); i++){
                            if(isupper(word_book[i]))
                                word_book[i] = tolower(word_book[i]);
                        }

                        // REMOVE VIRGULAS,ACENTOS,HIFENS, ETC
                        for(int i=0; i < word_book.length(); i++){
                            if(word_book[i] >= 97 && word_book[i] <= 122){
                                word_book_correta+= word_book[i];
                            }
                        }

                        // VERIFICA SE TEM ALGO NA PALAVRA CORRETA E SE TEM MAIS DE 3 LETRAS
                        if(!word_book_correta.empty() && word_book_correta.length() > 3 && word_book_correta != "para"){
                            if(!pulaFinal){
                                hash.inserir(word_book_correta, funcaoHash);
                                quantidade_palavras++;
                            }
                        }
                        // GARANTE QUE LIMPOU AS VARIAVEIS DE WORD
                        word_book.clear();
                        word_book_correta.clear();
                    }
                }
            }
            else{
                cerr << "Nao foi possivel abrir o livro!";
            }
        }

        if(funcaoHash == 1){
            cout << "FUNCAO HASH DE DIVISAO" << endl;
            cout << "NUMERO DE PALAVRAS: " << hash.totalDeItens() << endl;
            cout << "NUMERO DE COLISOES: " << hash.totalDeColisao() << endl;
        }
    }
    else{
        cerr << "Nao foi possivel abrir o arquivo!";
    }
    return 0;
}