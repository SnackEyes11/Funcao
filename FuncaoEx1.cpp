#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float pi = 3.14;

void VolumeEsfera(double raio);

int main(){
    double raio;
    
    printf("Informe  '0' como raio da esfera para o programa parar!\n\n");
    
    do{
        printf("Informe o raio da esfera: ");        
        scanf("%lf",&raio);
        
        if(raio == 0){
            break;
        }else{
            VolumeEsfera(raio);
        }
    }while(raio != 0);
    
    printf("\n\nFim do Programa\n");
    return 0;
}

void VolumeEsfera(double raio){
    double vol = 0;
    
    vol =(double) (3.0 / 4.0)* pi * raio * raio;
    printf("Volume da esfera de raio %.2lf = %.2lf\n\n",raio,vol);
}'''
