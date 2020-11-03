#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void merge(int vetor[], int inicio, int meio, int fim) {
    int *vetAux = (int*) malloc((fim - inicio + 1) * sizeof(int));
    int aux = inicio, aux2 = meio + 1, aux3 = 0;

    while(aux <= meio && aux2 <= fim){
        if(vetor[aux] < vetor[aux2]) {
            vetAux[aux3] = vetor[aux];
            aux++;
        } else {
            vetAux[aux3] = vetor[aux2];
            aux2++;
        }
        aux3++;
    }

    while(aux <= meio) {
        vetAux[aux3] = vetor[aux];
        aux3++;
        aux++;
    }

    while(aux2 <= fim) {
        vetAux[aux3] = vetor[aux2];
        aux3++;
        aux2++;
    }

    for(aux3 = inicio; aux3 <= fim; aux3++){
        vetor[aux3] = vetAux[aux3 - inicio];
    }
}

void merge_sort(int vetor[], int inicio, int fim){
    if(inicio < fim) {
        int meio = (fim + inicio) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void generate_vetor(int tamanho, char metodo[], int *vetor) {
  if(strcmp("Aleatorio", metodo) == 0) {
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = rand() % 10;
  }

  if(strcmp("Crescente", metodo) == 0) {
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = i;
  }

  if(strcmp("Decrescente", metodo) == 0) {
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = -i;
  }
}

void imprime_lista(int lista[], int tamanho){
  for(size_t i = 0; i<tamanho; i++){
    printf("%2d ", lista[i]);
  } printf("\n");
}

int main(){
  clock_t startTime, endTime;
  double deltaTime;

  // Aleatorio, Crescente or Decrescente
  char metodo[] = "Aleatorio";
  int tamanho = 10;
  int lista[tamanho];

  generate_vetor(tamanho, metodo, &lista[0]);
  startTime = clock();
  imprime_lista(lista, tamanho);
  merge_sort(lista, 0, tamanho-1);
  imprime_lista(lista, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  // printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);
  printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  return 0;
}
