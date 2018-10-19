#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void Capicue(char num[], int quant);

int main(void){
    setlocale(LC_ALL,"portuguese");
    
    char num[101];
    int quant;
    
    do{
        printf("Informe o número para verificar se ele é capicue ou não: ");
        fgets(num,100,stdin);
        
        if(num[0] == '0' &&  num[1] == '\0')
            break;
        else{
            quant = strlen(num);
            Capicue(num,quant);
        }
    }while((num[0] != '0') &&  (num[1] != '\0'));
    
    printf("\n\n");
    printf("Fim do Programa!\n\n");
    system("pause");
    return 0;
}

void Capicue(char num[], int quant){
    setlocale(LC_ALL,"portuguese");
    int check = 0;
    int j = quant - 2;
    
    for(int i = 0;i < quant - 1;i++, j--){
        if(num[i] != num[j])
            check++;
    }
    
    /*if(check > 0){
        printf("\t\t\tnão é capicue");
    }else
        if(check == 0){
            printf("\t\t\té capicue");
        }*/
    
    check > 0 ? printf("\t\tnão é capicue") : printf("\t\té capicue");
    
    printf("\n\n");
}
