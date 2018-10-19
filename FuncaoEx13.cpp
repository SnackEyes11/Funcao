#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX 1000

void Organiza(int array[]);
void Maior(int array[]);
void Menor(int array[]);
void Sorteia(int array[]);
void Mostrar(int array[]);
void NovoMenu(int array[]);
void Menu(int array[]);

int main(){
    setlocale(LC_ALL,"Portuguese");
    int vetor[MAX];    
    
    srand(time(NULL));
    
    Menu(vetor);
    
    return 0;
}

void Menu(int array[]){
    setlocale(LC_ALL,"Portuguese");
    
    int opcao;
    
    system("cls");
    
    printf("\t\t\tlista de op��es:\n");
    printf("(1) - Gerar n�meros aleat�rios\n");
    printf("(0) - Sair do programa\n");
    printf("\nOp��o: ");
    scanf("%d",&opcao);
    
    switch(opcao){
        case 1: Sorteia(array);
        case 0: exit(1);
        default:{
            system("cls");
            printf("op��o inv�lida\n");
            printf("Informe um op��o v�llida!");
            system("pause");
            Menu(array);
        }
    }
    
}

void NovoMenu(int array[]){
    setlocale(LC_ALL,"portuguese");
    int opcao;
    
    system("cls");
    
    printf("\t\t\tLista de novas op��es:\n");
    printf("(1) - Gerar n�meros aleat�rios no vetor\n");
    printf("(2) - Mostrar os elementos do vetor\n");
    printf("(3) - N�mero mais vezes sorteado\n");
    printf("(4) - N�mero menos vezes sorteado\n");
    printf("(0) - Sair\n");
    printf("\nOp��o: ");
    scanf("%d",&opcao);
    
    switch(opcao){
        case 1: Sorteia(array);
        case 2: Mostrar(array);
        case 3: Maior(array);
        case 4: Menor(array);
        case 0: exit(1);
        default:{
            system("cls");
            printf("op��o inv�lida\n");
            printf("Informe um op��o v�llida!");
            system("pause");
            NovoMenu(array);
        }   
    }
}

void Sorteia(int array[]){
    
    for(int i = 0;i < MAX;i++){
        array[i] = rand() % 100+1; 
    }
    
    NovoMenu(array);
}

void Organiza(int array[]){
    int guarda;
    
    for(int pass = 1;pass < MAX;pass++){
        for(int i = 0;i < MAX - 1;i++){
            if(array[i] > array[i + 1]){
                guarda = array[i];
                array[i] = array[i + 1];
                array[i + 1] = guarda; 
            }
        }
    }

}

void Maior(int array[]){
    int maior_indice=0;
    int cont1=1, cont2=1;
    
    Organiza(array);
    
    for(int i = 0;i < MAX-1;i++){
        if(array[i] == array[i + 1]){
            cont1++;
        }else{
            if(cont1 > cont2){
                cont2 = cont1;
                maior_indice = i; 
            }
            cont1 = 1;
        }
    }
    printf("N�mero que mais vezes foi sorteado %d.   %d\n\n",array[maior_indice], cont2);
    printf("\n\n");
    system("pause");
    NovoMenu(array);
}

void Menor(int array[]){
    int menor_indice=0;
    int cont1=1, cont2=1001;
    system("cls");
    Organiza(array);
    
    for(int i = 0;i < MAX-1;i++){
        if(array[i] == array[i + 1]){
            cont1++;
        }else{
            if(cont1 < cont2 ){
                cont2 = cont1;
                menor_indice = i; 
                cont1 = 1;
            }
        }
    }
    printf("N�mero que menos vezes foi sorteado %d.   %d",array[menor_indice], cont2);
    printf("\n\n");
    system("pause");
    NovoMenu(array);
}

void Mostrar(int array[]){
    system("cls");
    
    printf("Elementos do vetor:\n");
    
    for(int i = 0;i < MAX;i++)
        printf("%d\t",array[i]);
    printf("\n\n");
    system("pause");
    NovoMenu(array);
}
