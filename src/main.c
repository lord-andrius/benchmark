#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

const char *ordem_crescente[] = {"Blissful", "Cascade", "Effervescent", "Elysium", "Enchanting", "Enigmatic", "Ephemeral", "Epiphany", "Epoch", "Ethereal", "Euphoria", "Evanescent", "Exquisite", "Grandiose", "Halcyon", "Incandescent", "Ineffable", "Inquisitive", "Jubilant", "Labyrinth", "Luminescent", "Luminosity", "Luminous", "Lustrous", "Mellifluous", "Mellifluous", "Mellifluous", "Mellifluous", "Mellifluous", "Nebula", "Nebulous", "Opulent", "Panorama", "Peculiar", "Petrichor", "Quintessential", "Quixotic", "Radiant", "Resplendent", "Serendipity", "Solitude", "Sonorous", "Surreptitious", "Symbiosis", "Tranquil", "Twilight", "Utopia", "Velocity", "Whimsical", "Zephyr"};
const char *ordem_aleatoria[] = {"Radiant", "Peculiar", "Tranquil", "Nebula", "Luminous", "Cascade", "Whimsical", "Velocity", "Enchanting", "Jubilant", "Serendipity", "Petrichor", "Resplendent", "Panorama", "Zephyr", "Blissful", "Labyrinth", "Effervescent", "Halcyon", "Ethereal", "Ineffable", "Mellifluous", "Ephemeral", "Symbiosis", "Quixotic", "Evanescent", "Epiphany", "Grandiose", "Mellifluous", "Solitude", "Luminosity", "Euphoria", "Inquisitive", "Twilight", "Sonorous", "Epoch", "Elysium", "Enigmatic", "Lustrous", "Utopia", "Exquisite", "Nebulous", "Mellifluous", "Luminescent", "Surreptitious", "Opulent", "Mellifluous", "Mellifluous", "Quintessential", "Incandescent"};
const char *ordem_decrescente[] = {"Zephyr", "Whimsical", "Velocity", "Utopia", "Twilight", "Tranquil", "Symbiosis", "Surreptitious", "Sonorous", "Solitude", "Serendipity", "Resplendent", "Radiant", "Quixotic", "Quintessential", "Petrichor", "Peculiar", "Panorama", "Opulent", "Nebulous", "Nebula", "Mellifluous", "Mellifluous", "Mellifluous", "Mellifluous", "Mellifluous", "Lustrous", "Luminous", "Luminosity", "Luminescent", "Labyrinth", "Jubilant", "Inquisitive", "Ineffable", "Incandescent", "Halcyon", "Grandiose", "Exquisite", "Evanescent", "Euphoria", "Ethereal", "Epoch", "Epiphany", "Ephemeral", "Enigmatic", "Enchanting", "Elysium", "Effervescent", "Cascade", "Blissful"};

const size_t TAMANHO_LISTA = 50;

int compara_palavra(const char *str, const char *str2){
    size_t tamanho_da_menor_string;

    if (strlen(str) > strlen(str2)) 
    {
        tamanho_da_menor_string = strlen(str2);
    }
    else
    {
        tamanho_da_menor_string = strlen(str);
    }


    for (size_t index = 0; index < tamanho_da_menor_string; index++)
    {
        int str_char = toupper(str[index]);
        int str2_char = toupper(str2[index]);

        if (str_char < str2_char) return 1;
        else if (str_char > str2_char) return -1;
    }

    if (strlen(str) > strlen(str2)) return -1;
    else if (strlen(str) > strlen(str2)) return 1;
    else return 0;
}

bool compara_listas(const char *lista[], const char *lista2[])
{
    for (int i = 0; i <  TAMANHO_LISTA; i++)
        if (strcmp(lista[i], lista2[i]) != 0) return false;
    return true;
}

void copia_lista(char *dst[], const char *source[])
{

    for (int i = 0; i <  TAMANHO_LISTA; i++)
        dst[i] = source[i];
}

void quicksort(char *lista[], int comeco, int fim)
{
    int pivo = comeco;
    if (fim == comeco || fim < comeco) return;
    for (int c = comeco; c <= fim; c++)
    {
        if(compara_palavra(lista[c], lista[pivo]) == 1)
        {
            for (int i = c; i > pivo; i--)
            {
                char *tmp = lista[i - 1];
                lista[i - 1] = lista[i];
                lista[i] = tmp;
            }
            pivo++;
        }
    }
    quicksort(lista, comeco, pivo);
    quicksort(lista, pivo + 1, fim);
}

void merge(char *vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    char **vetAux;
    vetAux = (char **)malloc(tam * sizeof(char *));

    while(com1 <= meio && com2 <= fim){
        if(compara_palavra(vetor[com1], vetor[com2]) == 0) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(char * vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void insertion_sort(char *array[], int tamanho) {
  for(int i = 1; i < tamanho;i++)
  {
    if (compara_palavra(array[i - 1],array[i]) == 1)
    {
       int pos_i = i;
       for(int j = i - 1; j >= 0; j--)
       {
           if (compara_palavra(array[j],array[pos_i]) == 1)
           {
               int tmp = array[j];
               array[j] = array[pos_i];
               array[pos_i] = tmp;
               pos_i = j;
           }
       }
    }
  }
}


void selection_sort(char *array[], int tamanho) {
  int proxima_posicao = 0;
  while(proxima_posicao != tamanho - 1)
  {
    int menor_pos = proxima_posicao;
    for(int i = menor_pos; i < tamanho;i++)
    {
        if(compara_palavra(array[i],array[menor_pos]) == 1) menor_pos = i;
    }
    char *tmp = array[proxima_posicao];
    array[proxima_posicao] = array[menor_pos];
    array[menor_pos] = tmp;
    proxima_posicao++;
  }
}

void benchmark(void) 
{
    char *lista_ordem_crescente[TAMANHO_LISTA];   
    char *lista_ordem_aleatoria[TAMANHO_LISTA];   
    char *lista_ordem_decrescente[TAMANHO_LISTA];   
    
    copia_lista(lista_ordem_crescente, ordem_crescente);
    copia_lista(lista_ordem_aleatoria, ordem_aleatoria);
    copia_lista(lista_ordem_decrescente, ordem_decrescente);

    quicksort(lista_ordem_crescente, 0, TAMANHO_LISTA - 1);
    quicksort(lista_ordem_aleatoria, 0, TAMANHO_LISTA - 1);
    quicksort(lista_ordem_decrescente, 0, TAMANHO_LISTA - 1);

    assert(compara_listas(lista_ordem_crescente, ordem_crescente));
    assert(compara_listas(lista_ordem_aleatoria, ordem_crescente));
    assert(compara_listas(lista_ordem_decrescente, ordem_crescente));

    copia_lista(lista_ordem_crescente, ordem_crescente);
    copia_lista(lista_ordem_aleatoria, ordem_aleatoria);
    copia_lista(lista_ordem_decrescente, ordem_decrescente);

    mergeSort(lista_ordem_crescente, 0, TAMANHO_LISTA);
    mergeSort(lista_ordem_aleatoria, 0, TAMANHO_LISTA);
    mergeSort(lista_ordem_decrescente, 0, TAMANHO_LISTA);

    assert(compara_listas(lista_ordem_crescente, ordem_crescente));
    assert(compara_listas(lista_ordem_aleatoria, ordem_crescente));
    assert(compara_listas(lista_ordem_decrescente, ordem_crescente));


    copia_lista(lista_ordem_crescente, ordem_crescente);
    copia_lista(lista_ordem_aleatoria, ordem_aleatoria);
    copia_lista(lista_ordem_decrescente, ordem_decrescente);

    insertion_sort(lista_ordem_crescente, TAMANHO_LISTA);
    insertion_sort(lista_ordem_aleatoria, TAMANHO_LISTA);
    insertion_sort(lista_ordem_decrescente, TAMANHO_LISTA);

    assert(compara_listas(lista_ordem_crescente, ordem_crescente));
    assert(compara_listas(lista_ordem_aleatoria, ordem_crescente));
    assert(compara_listas(lista_ordem_decrescente, ordem_crescente));

    copia_lista(lista_ordem_crescente, ordem_crescente);
    copia_lista(lista_ordem_aleatoria, ordem_aleatoria);
    copia_lista(lista_ordem_decrescente, ordem_decrescente);

    selection_sort(lista_ordem_crescente, TAMANHO_LISTA);
    selection_sort(lista_ordem_aleatoria, TAMANHO_LISTA);
    selection_sort(lista_ordem_decrescente, TAMANHO_LISTA);

    assert(compara_listas(lista_ordem_crescente, ordem_crescente));
    assert(compara_listas(lista_ordem_aleatoria, ordem_crescente));
    assert(compara_listas(lista_ordem_decrescente, ordem_crescente));
}

int main(void)
{
    benchmark();
}
