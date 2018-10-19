#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//O define MAX será usado para especificar os flags de que FOR dentro das funções

#define MAX 10

//Como em cada função, iremos usar um indice 'i' de tipo inteiro dentro de um for
//foi cridado uma varivel global que será usada em todos os for de todas as funções
int i;

//Protipo de cada função usada como pedido na questão
void NovoMenu(int vetor[]);
void Menu(int vetor[]);
void Soma(int vetor[]);
void Media(int vetor[]);
void Negativos(int vetor[]);
void Iguais(int vetor[]);
void Entrada(int vetor[]);

int main(){
    int array[MAX];
    
    //Chama a função menu, para dar as opções aos usuário
    Menu(array);

    return 0;
}

void Menu(int vetor[]){
    setlocale(LC_ALL,"portuguese");
    int opcao;
    
    system("cls");
    //A abaixo está listado as opções de entradas que o usuário pode fornecer 
    printf("Opções de entrada:\n");
    printf("(1) - Entrada de elementos\n");
    printf("(0) - Sair do programa\n");
    printf("\nOpção: ");
    scanf("%d",&opcao); //leitura da opção de entrada
    
    //caso que podem acontecer dependo da entrada do usuário
    switch(opcao){
        case 1: Entrada(vetor);
        case 0: exit(1);
        default:{                                        // se o usuário entrar com um opção de entrada             
            system("cls");                               //diferente das que foram disponibilizadas a ele,     
            printf("\t\t\tOpção inválida!\n");           //o compilador informará que a opção de entrada é 
            printf("Informe uma opção válida! PLMD\n\n");//inválida e retornará com a leitura de opção 
            system("pause");                             //novamente
            Menu(vetor);
        }
    }
}

//Novo menu após o usuário ter informado a quantidade de numero que você mandou ele informar
void NovoMenu(int vetor[]){
    setlocale(LC_ALL,"portuguese");
    
    int opcao;
    system("cls");
    //lista de opções disponíveis
    printf("As novas opções de entrada estão abaixo:\n");
    printf("(1)- Entrada de novos valores\n");
    printf("(2)- Soma dos valores digitados\n");
    printf("(3)- Media dos valores\n");
    printf("(4)- Substituição dos valores iguais\n");
    printf("(5)- Substituição dos valores negativos\n");
    printf("(0)- Saída de dados\n\n");
    printf("Opção: "); 
    scanf("%d",&opcao); //leitura da entrada
    
    //caso que podem acontecer dependo da entrada do usuário
    switch(opcao){
        case 1: Entrada(vetor);
        case 2: Soma(vetor);
        case 3: Media(vetor);
        case 4: Iguais(vetor);
        case 5: Negativos(vetor);
        case 0: exit(1);
        default:{
            system("cls");                                //diferente das que foram disponibilizadas a ele,     
            printf("\t\t\tOpção inválida!\n");            //o compilador informará que a opção de entrada é 
            printf("Informe uma opção válida! PLMD\n\n"); //inválida e retornará com a leitura de opção 
            system("pause");                              //novamente
            NovoMenu(vetor);//retorná a função NovoMenu    
        }
    }
}

// A função Entrada faz a leitura dos números que o programador disponibilizou ao usuário
void Entrada(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    
    printf("\n\nEntre com %d valores:\n",MAX);
    
    for(i = 0;i < MAX;i++){
        printf("Valor %d = ",i + 1);
        scanf("%d",&vetor[i]);  //leitura dos numeros informados pelo usuário
    }
    
    printf("\n\n");
    system("pause");
    NovoMenu(vetor);//retorná a função NovoMenu    
}

// A função void Soma irá somar todos os elementos do vetor e mostrar a mesma
void Soma(int vetor[]){
    int soma = 0;
    
    for(i = 0;i < MAX;i++){
        soma += vetor[i]; //soma dos elementos
    }
    
    printf("\n\n Soma dos valores digitados %d\n\n",soma); 
    system("pause");
    NovoMenu(vetor);//retorná a função NovoMenu    
}

//A função void Media irá fazer a média dos valores do vetor e mostrar a mesma
void Media(int vetor[]){
    auto float media;
    
    for(i = 0;i < MAX;i++){
        media += vetor[i]; //calculando primeiro a soma de todos os elementos do vetor
    }
    media /= (float) MAX; //ele calcula a média divindo a soma de todos os número pela quantidade de
                          // números existentes no vetor 
    
    printf("\n\n Media dos valores digitados %.2f\n\n",media);
    system("pause");
    NovoMenu(vetor);    //retorná a função NovoMenu    
}

//A função void Negativos substitui todos os numero menor que Zero por '0'
void Negativos(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    
    printf("\n\nvalores antes de seres motificados:\n");
    for(i = 0;i < MAX;i++){
        printf("%d\t",vetor[i]);    //primero o compilador mostra os valores do vetor antes de serem 
    }                               // substotuidos por '0' caso sejam menores que o mesmo
    
    for(i = 0;i < MAX;i++){
        if(vetor[i] < 0)
            vetor[i] = 0;   // processo de substituição dos valores menores que zero por '0'
    }
    
    printf("\n\nvalores depois de seres motificados:\n");
    for(i = 0;i < MAX;i++){
        printf("%d\t",vetor[i]);  //mostra como o vetor ficou depois da subtituição 
    }

    printf("\n\n");
    system("pause");
    NovoMenu(vetor);    //retorná a função NovoMenu    
    
}

//A função void Iguais substitui por '0' todos os números do vetor que se repetem e são maiores que zero
void Iguais(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    auto int check = 0;
    
    printf("\n\n");
    printf("Modificação dos valores que são iguais e maiores que Zero:\n");
    printf("\nValores antes de serem modificados:\n");

    for(i = 0;i < MAX;i++)
        printf("%d\t",vetor[i]);  //primero o compilador mostra os valores do vetor antes de serem 
                                  //modificados por '0' os número que se repetem  e são maiores que zero
    for(i = 0;i < MAX - 1;i++){     
        for(int j = i + 1;j < MAX;j++){ //o for fará  cada elemento do vetor percorré por todo ele, menos pelo própio elemento
            if(vetor[i] == vetor[j]){   //caso o elemento encontre algum outro igual a ele
                    vetor[j] = 0;       //o elemento encontrado receberá o valor de '0'
                    check++;            //e uma variavel de verificação "check" igual ser incrementada
            }
        }
        if(check > 0){      // se a variavel check foir maior que zero, significa que a elementos
            vetor[i] = 0;   //do vetor[i] que se repetem, e o vetor[i] receberá o valor de '0'
            check = 0;      //check reberá '0' novamente para verificar o proximo elemento do vetor "vetor[i++];"
        }
    }
    printf("\n\nValores depois de serem modificados:\n");
    for(i = 0;i < MAX;i++)
        printf("%d\t",vetor[i]);    //amostra do novo vetor
    
    printf("\n\n");
    system("pause");
    NovoMenu(vetor);    //retorná a função NovoMenu    
}
