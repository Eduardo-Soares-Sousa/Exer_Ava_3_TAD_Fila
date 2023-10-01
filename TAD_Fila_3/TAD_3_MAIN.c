#include "TAD_3.h"

int main(int argc, char const *argv[]){

    Queue fila;
    init(&fila);

    char nome[20];
    int i;

    i = 0;
    while(i < QUEUE_MAX_SIZE){
        printf("Digite o %dº nome: ", i + 1);
        scanf("%s", nome);
        enqueue(fila, strdup(nome));
        printf("\n");

        i++;
    }

    for (int i = 0; i < 2; i++) {
        Element kill = dequeue(fila);
        enqueue(fila, kill);
    }

    Element removido = dequeue(fila);

    Element sobreviveu = dequeue(fila);
    printf("Sobrevivente: %s\n", sobreviveu);

    return 0;
}