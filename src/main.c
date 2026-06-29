#include <stdio.h>
#include <stdlib.h>

void Merge(int vet[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* esq = (int*)malloc(sizeof(int) * n1);
    int* dir = (int*)malloc(sizeof(int) * n2);

    for(i = 0; i < n1; i++){
        esq[i] = vet[inicio + i];
    }

    for(j = 0; j < n2; j++) {
        dir[j] = vet[meio + 1 + j];
    }

    i = 0, j = 0, k = inicio;

    while(i < n1 && j < n2) {
        if(esq[i] < dir[j]) {
            vet[k++] = esq[i++];
        } else {
            vet[k++] = dir[j++];
        }
    }

    while(i < n1) {
        vet[k++] = esq[i++];
    }

    while(j < n2) {
        vet[k++] = dir[j++];
    }

    free(esq);
    free(dir);
}


void MergeSort(int vet[], int inicio, int fim) {
    if(inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        MergeSort(vet, inicio, meio);
        MergeSort(vet, meio + 1, fim);
        Merge(vet, inicio, meio, fim);
    }
}


int maximumGap(int* nums, int numsSize) {
   
    if(numsSize < 2) {
        return 0;
    } 

    int maiorDistancia = 0;

    MergeSort(nums, 0, numsSize - 1);

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i+1] - nums[i] > maiorDistancia) {
            maiorDistancia = nums[i+1] - nums[i];
        }
    }

    return maiorDistancia;
}

int main() {
    int nums[] = {2, 5, 45, 3, 10};
    printf("\nMaior Distancia: %d", maximumGap(nums, 5));
    return 0;
}
