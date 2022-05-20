#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ponto.h"

int main(){
    
    FILE * fp;
    char* id;
    int i = 0;
    int sizePontos = 10,numCoord = 0;
   
    fp = fopen("teste.txt", "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    // Leitura dos pontos
    Ponto **pontos = (Ponto**)malloc(sizePontos * sizeof(Ponto*));
    while(!feof(fp)){     
        if(i== sizePontos-1){
            sizePontos *= 2;
            pontos = (Ponto**)realloc(pontos, sizePontos * sizeof(Ponto*));
        }  
        pontos[i] = readLine(fp);
        i++;
    }

    int numPontos = i+1;

    // Calculando a matriz das distâncias entre os pontos
    double **matriz = (double**)malloc(i * sizeof(double*));
    for(int j = 0; j < i; j++){
        matriz[j] = (double*)malloc(i * sizeof(double));
    }

    for(int j = 0; j < i; j++){
        for(int k = 0; k < i; k++){
            matriz[j][k] = distanciaPontos(pontos[j], pontos[k]);
            printf("%.2f ", matriz[j][k]);
        }
    }


    
    // Liberação dos pontos
    for(int j = 0;j < i;j++){
        DestroiPonto(pontos[j]);
    }

    free(pontos);

    fclose(fp);
    
    return 0;
}
    
   

