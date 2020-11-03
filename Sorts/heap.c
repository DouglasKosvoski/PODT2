#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void heap_sort(int arr[], int tamanho) {
  int i = tamanho / 2;
  int pai, filho, t;

  while(true) {
      if(i > 0){
          i--;
          t = arr[i];
      }
      else {
          tamanho--;
          if(tamanho <= 0) {
            return;
          }
          t = arr[tamanho];
          arr[tamanho] = arr[0];
      }
      pai = i;
      filho = (i * 2) + 1;

      while(filho < tamanho) {
          if((filho + 1 < tamanho) && (arr[filho + 1] > arr[filho])) {
            filho++;
          }
          if(arr[filho] > t) {
              arr[pai] = arr[filho];
              pai = filho;
              filho = pai * 2 + 1;
          }
          else {
            break;
          }
      }
      arr[pai] = t;
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
  int tamanho = 100000;
  int lista[tamanho];

  generate_vetor(tamanho, metodo, &lista[0]);
  startTime = clock();
  // imprime_lista(lista, tamanho);
  heap_sort(lista, tamanho);
  // imprime_lista(lista, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  // printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);
  printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  return 0;
}
