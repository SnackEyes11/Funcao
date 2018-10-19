#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 10

void Menu(int array[]);
void NovosNumeros(int array[]);
void Somatorio(int array[]);
void Valores(int array[]);

int main(){
    int vetor[MAX];
    srand(time(NULL));

    Menu(vetor);

    return 0;
}

void Menu(int array[]){
    setlocale(LC_ALL,"Portuguese");
    int opcao;
    
    system("cls");
    printf("Lista de opções de entrada abaixo:\n");
    printf("(1) - Gerar novos números elementos ao vetor\n");
    printf("(2) - Informar a quantidade de números que participarão do somatório\n");
    printf("(3) - Mostrar números que se encontram no vetor\n");
    printf("(0) - Sair\n");
    
    printf("\nOpção: ");  scanf("%d",&opcao);
    
    switch(opcao){
        case 1: NovosNumeros(array);
        case 2: Somatorio(array);
        case 3: Valores(array);
        case 0: exit(1);
        default:{
            system("cls");
            printf("Entrada inválida! Informe uma entrada válida.\n\n");
            system("pause");
            Menu(array);
            break;
        }
    }
    
}

void NovosNumeros(int array[]){
    for(int i = 0;i < MAX;i++){
        array[i] = rand() % 100;
    }
    
    printf("\n\n");
    printf("Novos valores do vetor gerados com sucesso!");
    printf("\n\n");
    
    system("pause");
    Menu(array);
}

void Valores(int array[]){
    setlocale(LC_ALL,"Portuguese");
    
    printf("\n\nElementos que compõem o vetor:\n");
    for(int i = 0;i < MAX;i++){
        printf("%d\t",array[i]);
    }
    printf("\n\n");
    system("pause");
    Menu(array);
}

void Somatorio(int array[]){
    setlocale(LC_ALL,"Portuguese");
    int soma = 0;

    printf("\n\nSoma dos elementos que compõem o vetor: ");
    for(int i = 0;i < MAX;i++){
        soma += array[i];
    }    
    printf("%d",soma);
    
    printf("\n\n");
    system("pause");
    Menu(array);
}
