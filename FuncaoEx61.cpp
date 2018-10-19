#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float delta = 0;

void Delta(float a, float b, float c);
void Leitura();
void Result(float a, float b, float c);

int main(){
    int a;
    int b;
    int c;
    
    Leitura();
        
}

void Leitura(){
    float a;
    float b;
    float c;
    
    system("cls");
    printf("Digite 9999 no valor de 'a' para parar o programa\n");
    printf("\n\n");
    printf("Informe os de:\n");
    printf("a: ");    scanf("%f",&a);
    if(a == 9999)
        exit(1);
    printf("b: ");    scanf("%f",&b);
    printf("c: ");    scanf("%f",&c);
    
    Delta(a, b, c);
}

void Delta(float a, float b, float c){
    delta = pow(b,2) - (4 * a * c);
    
    Result(a, b, c);
}

void Result(float a, float b, float c){
    float x1 = 0.0, x2 = 0.0; 
    
    if(a == 0){
        printf("O valor de a não pode ser igual '0'!\n\n");
        system("pause");
        Leitura();
    }else
        if(delta < 0){
            printf("O valor de delta é menor que '0', não há raízes reais e distintas!\n\n");
            system("pause"); 
            Leitura();
        }else{
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            
            printf("\t\tValor das raizes:\n");
            printf("raiz 1: %g\n",x1);
            printf("raiz 2: %g\n\n",x2);
            printf("\t\tValor de Delta:\n");
            printf("Delta: %g\n\n",delta);
            system("pause");
            Leitura();
        }
}

