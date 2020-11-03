#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int particiona(int arr[], int inicio, int fim) {
  int pivo = arr[fim];
  int i = (inicio - 1);

  for (int j = inicio; j <= fim- 1; j++) {
      if (arr[j] < pivo) {
          i++;
          swap(&arr[i], &arr[j]);
      }
  }
  swap(&arr[i + 1], &arr[fim]);
  return (i + 1);
}

void quick_sort(int arr[], int inicio, int fim) {
  if(inicio < fim) {
    int pivo = particiona(arr, inicio, fim);
    quick_sort(arr, inicio, pivo - 1);
    quick_sort(arr, pivo + 1, fim);
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
  char metodo[] = "Crescente";
  int tamanho = 50000;
  int lista[tamanho];

  generate_vetor(tamanho, metodo, &lista[0]);
  startTime = clock();
  // imprime_lista(lista, tamanho);
  quick_sort(lista, 0, tamanho-1);
  // imprime_lista(lista, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);
  printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  return 0;
}
