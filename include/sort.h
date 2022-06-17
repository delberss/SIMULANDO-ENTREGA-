#ifndef TRABALHO_PRATICO_PARTE_1_DNP_SORT_H
#define TRABALHO_PRATICO_PARTE_1_DNP_SORT_H

#include <chrono>
#include "No.h"
#include "iostream"
using namespace std;

/* ========================== METODO OBRIGATORIO QUICKSORT ========================== */

int partition(No * arr, int start, int end, int * numMov, int * numComp)
{
    No pivot = arr[end];

    int i = (start - 1);
    for (int j = start; j <= end - 1; j++)
    {
        *numComp = * numComp + 1;
        if (arr[j].getRepeticoes() > pivot.getRepeticoes())
        {
            i++;
            No aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            *numMov = *numMov + 3;
            *numComp = * numComp + 1;
        }
    }
    No aux = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = aux;
    *numMov = *numMov + 3;
    return (i + 1);
}

void Quicksort(No* arr, int start, int end, int * numMov, int * numComp)
{
    if (start < end)
    {
        int pi = partition(arr, start, end, numMov, numComp);

        Quicksort(arr, start, pi - 1, numMov, numComp);
        Quicksort(arr, pi + 1, end, numMov, numComp);
    }
}

void quick_sort(No * array, int size)
{
    int  numComp, numMov  = 0;

    // PARA TEMPO DE PROCESSAMENTO
    auto comeco_tempo = chrono::high_resolution_clock::now();

    Quicksort(array, 0, size-1, &numMov, &numComp);

    auto fim_tempo = chrono::high_resolution_clock::now();

    cout << "METODO QUICKSORT" << endl;
    cout << "COMPARACOES: " << numComp << endl;
    cout << "MOVIMENTACOES: " << numMov << endl;
    cout << "TEMPO DE PROCESSAMENTO: " << chrono::duration_cast<std::chrono::milliseconds>(fim_tempo-comeco_tempo).count()  << "ms" << endl;
}
/* ========================== FIM DO QUICKSORT ========================== */


/* ========================== METODO VISTO EM AULA - BUBBLESORT  ========================== */
void bubbleSort(No* array, int tamanho)
{
    int  numComp, numMov  = 0;

    auto comeco_tempo = chrono::high_resolution_clock::now();
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - 1; j++)
        {
            numComp++;
            if (array[j+1].getRepeticoes() > array[j].getRepeticoes())
            {
                No aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                numMov = numMov + 3;
            }
        }
    }
    auto fim_tempo = chrono::high_resolution_clock::now();

    cout << "METODO BUBBLESORT" << endl;
    cout << "COMPARACOES: " << numComp << endl;
    cout << "MOVIMENTACOES: " << numMov << endl;
    cout << "TEMPO DE PROCESSAMENTO: " << chrono::duration_cast<std::chrono::milliseconds>(fim_tempo-comeco_tempo).count()  << "ms" << endl;
}

/* ========================== FIM DO BUBBLESORT  ========================== */




/* ========================== METODO NAO VISTO EM AULA - COMB SORT  ========================== */

// Para encontrar o espaço entre os elementos
int getNextGap(int gap)
{
    // Encolher espaço por fator de encolhimento
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

// Função para classificar a[0..n-1] usando Comb Sort
void combSort(int a[], int n)
{
    // Inicializar intervalo
    int gap = n; //

    // Inicialize trocado como verdadeiro para garantir que
    // corridas de loop
    bool swapped = true;

    // Continue correndo enquanto o gap for maior que 1 e último
    // iteração causou uma troca
    while (gap != 1 || swapped == true)
    {
        // Encontre a próxima lacuna
        gap = getNextGap(gap);

        // Inicialize swapped como false para que possamos
        // verifique se a troca aconteceu ou não
        swapped = false;

        // Compare todos os elementos com a lacuna atual
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

/* EXEMPLO DE CHAMAR METODO:
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);

    combSort(a, n);
*/
/*=====================================================================================*/

#endif //TRABALHO_PRATICO_PARTE_1_DNP_SORT_H
