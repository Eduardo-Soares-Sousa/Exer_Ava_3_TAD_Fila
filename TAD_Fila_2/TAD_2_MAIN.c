#include "TAD_2.h"

int menu();

int main(int argc, char const *argv[]){

    Queue fila_normal;
    init(&fila_normal);

    Queue fila_priori;
    init(&fila_priori);

    Caixa caixa[10];
    for (int i = 0; i < 10; i++) {
        caixa[i].numero = i + 1;
    }

    int proximo_caixa = 0;

    int option;
    do{
        option = menu();

        switch(option){
        case 1:
            printf("\n----------------------------------------------\n\n");
    
            enqueue(fila_normal, option);
            
            break;
        
        case 2:
            printf("\n----------------------------------------------\n\n");

            enqueue(fila_priori, option);
            
            break;

        case 3:
            printf("\n----------------------------------------------\n\n");
            
            if(!is_empty(fila_priori)){
                Element cliente_prioritario = dequeue(fila_priori);
                printf("Caixa %d chamou o próximo cliente: %d (Prioritário)\n", caixa[proximo_caixa].numero, cliente_prioritario);

                proximo_caixa = (proximo_caixa + 1) % 10;

                if(proximo_caixa == 3){
                    proximo_caixa = 0;
                }
            }else if (!is_empty(fila_normal)){
                Element cliente_normal = dequeue(fila_normal);
                printf("Caixa %d chamou o próximo cliente: %d (Normal)\n", caixa[proximo_caixa].numero, cliente_normal);

                proximo_caixa = (proximo_caixa + 1) % 10;
            } else {
                printf("Ambas as filas acabaram.\n");
            }
            
            break;
        }
    
    }while(option > 0 && option <= 3);

    if(option == 0){
        printf("\n\n=====SISTEMA ENCERRADO=====\n\n");
    }else{
        if( (option > 3) || (option < 0) ){
            printf("\n-=-=-=-=-=-OPÇÃO INVÁLIDA-=-=-=-=-=-\n\n");
            printf("Tente novamente :(\n\n");
        }
    }


    return 0;
}

int menu(){
    int option;

    printf("\t--------------------------------------------------------------------\n\n");
    printf("\t=====Selecione a opção que deseja=====\n");
    printf("\t1 - Pegar ficha normal......:\n");
    printf("\t2 - Pegar ficha prioritária.........:\n");
    printf("\t3 - Chamar próximo cliente................:\n");
    printf("\t0 - Sair.\n\n");
    printf("Digite a opção desejada...: ");
    scanf("%d", &option);

    return option;
}