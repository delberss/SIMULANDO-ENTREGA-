#include <iostream>
#include <string>
#include "include/hash.h"

using namespace std;

int main(){
    int tamanhoHash;
    int quantidadePalavras;
    const float K = 0.4;

    cout << "      USANDO HASH      \n";
    cout << "DIGITE O QUANTIDADE DE PALAVRAS: ";
    cin >> quantidadePalavras;

    tamanhoHash = (1*quantidadePalavras) / K;

    Hash hash(tamanhoHash);

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

    string chave;
    int opcao = 0;
    do{
        cout << "\n    MENU    \n"
                "[0] ENCERRAR\n[1] INSERIR\n[2] BUSCAR - PONTEIRO\n"
                "[3] BUSCAR - INFOS\n[4] REMOVER\n[5] QUANTIDADE TOTAL DE REPETICOES\n[6] QUANTIDADE TOTAL DE COLISOES\n"
                "[7] QUANTIDADE ITENS\n[8] QUANTIDADE REPETICAO DA PALAVRA\n"
                "[9] QUANTIDADE DE COLISAO DA PALAVRA\n[10] IMPRIMIR\n";
        cout << "ESCOLHA: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "PROGRAMA ENCERRADO!\n";
                break;
            case 1:
                cout <<"Palavra a inserir:";
                cin >> chave;
                hash.inserir(chave,funcaoHash);
                break;

            case 2:
                cout <<"Buscar a palavra: ";
                cin >> chave;
                cout << "Ponteiro: " << hash.buscar(chave);
                break;

            case 3:
                cout <<"Buscar a palavra:";
                cin >> chave;
                hash.buscarComInfos(chave);
                break;

            case 4:
                cout <<"Remover a palavra:";
                cin >> chave;
                hash.remover(chave);
                break;
            case 5:
                cout << "Total de repeticoes = "  << hash.totalDeRepeticoes() << endl;
                break;
            case 6:
                cout << "Total de colisoes = "  << hash.totalDeColisao() << endl;
                break;
            case 7:
                cout << "Total de itens = "  << hash.totalDeItens() << endl;
                break;
            case 8:
                cout << "Escolha a palavra:";
                cin >> chave;
                cout << "Repeticoes da palavra " << chave << ": " << hash.repeticaoPalavra(chave) << endl;
                break;
            case 9:
                cout << "Escolha a palavra:";
                cin >> chave;
                cout << "Colisoes da palavra " << chave << ": " << hash.colisaoPalavra(chave) << endl;
                break;
            case 10:
                hash.imprimir();
                break;
            default:
                cout << " *** DIGITE UM NUMERO DE 0 A 5 ***\n";
        }
    }while(opcao !=0);

    return 0;
}