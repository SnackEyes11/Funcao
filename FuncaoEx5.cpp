#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//O define MAX ser� usado para especificar os flags de que FOR dentro das fun��es

#define MAX 10

//Como em cada fun��o, iremos usar um indice 'i' de tipo inteiro dentro de um for
//foi cridado uma varivel global que ser� usada em todos os for de todas as fun��es
int i;

//Protipo de cada fun��o usada como pedido na quest�o
void NovoMenu(int vetor[]);
void Menu(int vetor[]);
void Soma(int vetor[]);
void Media(int vetor[]);
void Negativos(int vetor[]);
void Iguais(int vetor[]);
void Entrada(int vetor[]);

int main(){
    int array[MAX];
    
    //Chama a fun��o menu, para dar as op��es aos usu�rio
    Menu(array);

    return 0;
}

void Menu(int vetor[]){
    setlocale(LC_ALL,"portuguese");
    int opcao;
    
    system("cls");
    //A abaixo est� listado as op��es de entradas que o usu�rio pode fornecer 
    printf("Op��es de entrada:\n");
    printf("(1) - Entrada de elementos\n");
    printf("(0) - Sair do programa\n");
    printf("\nOp��o: ");
    scanf("%d",&opcao); //leitura da op��o de entrada
    
    //caso que podem acontecer dependo da entrada do usu�rio
    switch(opcao){
        case 1: Entrada(vetor);
        case 0: exit(1);
        default:{                                        // se o usu�rio entrar com um op��o de entrada             
            system("cls");                               //diferente das que foram disponibilizadas a ele,     
            printf("\t\t\tOp��o inv�lida!\n");           //o compilador informar� que a op��o de entrada � 
            printf("Informe uma op��o v�lida! PLMD\n\n");//inv�lida e retornar� com a leitura de op��o 
            system("pause");                             //novamente
            Menu(vetor);
        }
    }
}

//Novo menu ap�s o usu�rio ter informado a quantidade de numero que voc� mandou ele informar
void NovoMenu(int vetor[]){
    setlocale(LC_ALL,"portuguese");
    
    int opcao;
    system("cls");
    //lista de op��es dispon�veis
    printf("As novas op��es de entrada est�o abaixo:\n");
    printf("(1)- Entrada de novos valores\n");
    printf("(2)- Soma dos valores digitados\n");
    printf("(3)- Media dos valores\n");
    printf("(4)- Substitui��o dos valores iguais\n");
    printf("(5)- Substitui��o dos valores negativos\n");
    printf("(0)- Sa�da de dados\n\n");
    printf("Op��o: "); 
    scanf("%d",&opcao); //leitura da entrada
    
    //caso que podem acontecer dependo da entrada do usu�rio
    switch(opcao){
        case 1: Entrada(vetor);
        case 2: Soma(vetor);
        case 3: Media(vetor);
        case 4: Iguais(vetor);
        case 5: Negativos(vetor);
        case 0: exit(1);
        default:{
            system("cls");                                //diferente das que foram disponibilizadas a ele,     
            printf("\t\t\tOp��o inv�lida!\n");            //o compilador informar� que a op��o de entrada � 
            printf("Informe uma op��o v�lida! PLMD\n\n"); //inv�lida e retornar� com a leitura de op��o 
            system("pause");                              //novamente
            NovoMenu(vetor);//retorn� a fun��o NovoMenu    
        }
    }
}

// A fun��o Entrada faz a leitura dos n�meros que o programador disponibilizou ao usu�rio
void Entrada(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    
    printf("\n\nEntre com %d valores:\n",MAX);
    
    for(i = 0;i < MAX;i++){
        printf("Valor %d = ",i + 1);
        scanf("%d",&vetor[i]);  //leitura dos numeros informados pelo usu�rio
    }
    
    printf("\n\n");
    system("pause");
    NovoMenu(vetor);//retorn� a fun��o NovoMenu    
}

// A fun��o void Soma ir� somar todos os elementos do vetor e mostrar a mesma
void Soma(int vetor[]){
    int soma = 0;
    
    for(i = 0;i < MAX;i++){
        soma += vetor[i]; //soma dos elementos
    }
    
    printf("\n\n Soma dos valores digitados %d\n\n",soma); 
    system("pause");
    NovoMenu(vetor);//retorn� a fun��o NovoMenu    
}

//A fun��o void Media ir� fazer a m�dia dos valores do vetor e mostrar a mesma
void Media(int vetor[]){
    auto float media;
    
    for(i = 0;i < MAX;i++){
        media += vetor[i]; //calculando primeiro a soma de todos os elementos do vetor
    }
    media /= (float) MAX; //ele calcula a m�dia divindo a soma de todos os n�mero pela quantidade de
                          // n�meros existentes no vetor 
    
    printf("\n\n Media dos valores digitados %.2f\n\n",media);
    system("pause");
    NovoMenu(vetor);    //retorn� a fun��o NovoMenu    
}

//A fun��o void Negativos substitui todos os numero menor que Zero por '0'
void Negativos(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    
    printf("\n\nvalores antes de seres motificados:\n");
    for(i = 0;i < MAX;i++){
        printf("%d\t",vetor[i]);    //primero o compilador mostra os valores do vetor antes de serem 
    }                               // substotuidos por '0' caso sejam menores que o mesmo
    
    for(i = 0;i < MAX;i++){
        if(vetor[i] < 0)
            vetor[i] = 0;   // processo de substitui��o dos valores menores que zero por '0'
    }
    
    printf("\n\nvalores depois de seres motificados:\n");
    for(i = 0;i < MAX;i++){
        printf("%d\t",vetor[i]);  //mostra como o vetor ficou depois da subtitui��o 
    }

    printf("\n\n");
    system("pause");
    NovoMenu(vetor);    //retorn� a fun��o NovoMenu    
    
}

//A fun��o void Iguais substitui por '0' todos os n�meros do vetor que se repetem e s�o maiores que zero
void Iguais(int vetor[]){
    setlocale(LC_ALL,"Portuguese");
    auto int check = 0;
    
    printf("\n\n");
    printf("Modifica��o dos valores que s�o iguais e maiores que Zero:\n");
    printf("\nValores antes de serem modificados:\n");

    for(i = 0;i < MAX;i++)
        printf("%d\t",vetor[i]);  //primero o compilador mostra os valores do vetor antes de serem 
                                  //modificados por '0' os n�mero que se repetem  e s�o maiores que zero
    for(i = 0;i < MAX - 1;i++){     
        for(int j = i + 1;j < MAX;j++){ //o for far�  cada elemento do vetor percorr� por todo ele, menos pelo pr�pio elemento
            if(vetor[i] == vetor[j]){   //caso o elemento encontre algum outro igual a ele
                    vetor[j] = 0;       //o elemento encontrado receber� o valor de '0'
                    check++;            //e uma variavel de verifica��o "check" igual ser incrementada
            }
        }
        if(check > 0){      // se a variavel check foir maior que zero, significa que a elementos
            vetor[i] = 0;   //do vetor[i] que se repetem, e o vetor[i] receber� o valor de '0'
            check = 0;      //check reber� '0' novamente para verificar o proximo elemento do vetor "vetor[i++];"
        }
    }
    printf("\n\nValores depois de serem modificados:\n");
    for(i = 0;i < MAX;i++)
        printf("%d\t",vetor[i]);    //amostra do novo vetor
    
    printf("\n\n");
    system("pause");
    NovoMenu(vetor);    //retorn� a fun��o NovoMenu    
}
