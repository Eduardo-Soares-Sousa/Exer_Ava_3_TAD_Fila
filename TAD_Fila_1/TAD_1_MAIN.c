#include "TAD_1.h"

int main(int argc, char const *argv[]){
    
    Queue fila;

    Queue fila2;

    int n;
    int i;
    int aux;
    int array_aux[QUEUE_MAX_SIZE];

    init(&fila);

    i = 0;
    while(i < QUEUE_MAX_SIZE){
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &n);
        enqueue(fila, n);
        printf("\n");

        i++;
    }

    init(&fila2);
    
    i = 0;
    while(i < QUEUE_MAX_SIZE){
        aux = dequeue(fila);
        if(aux % 2 != 0 || aux == 0){
            enqueue(fila2, aux);
            
        }
        
        i++;
    }

    printf("\n\n---------------------------------------------\n\n");
    printf("Fila com apenas os números ímpares e nulo:\n");
    
    while(!is_empty(fila2)){
       printf("%d\n", dequeue(fila2));
    }
    
    return 0;
}