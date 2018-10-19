#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Primo(int num);

int main(){
    setlocale(LC_ALL,"portuguese");
    int num;
    
    printf("Se o número for primo o computador retornará 1, se não, retornará 0!\n");
    do{
        printf("\nEntre com um número maior que Zero(entre com '0' para sair do programa):\n");
        printf("\t\t\tNumero: ");
        scanf("%d",&num);
        
        if(num == 0)
            break;
        else
            if(num > 0)
                Primo(num);
            else
                printf("\n\nEntrada inválida, nenhum número primo pode ser negativo!\n\n");
                    
    }while(num != 0);
    
    printf("\n\n");
    printf("Fim do Programa!\n\n");
    system("pause");
    
    return 0;
}

void Primo(int num){
    int aux = 0;
    
    for(int i = 2; i < num;i++){
        if((num % i ) == 0)
            aux++;
    }
    
    aux > 0 ? printf("\t\t\tResultado: 0\n\n") : printf("\t\t\tResultado: 1\n\n");
    system("pause");
    system("cls");
}
