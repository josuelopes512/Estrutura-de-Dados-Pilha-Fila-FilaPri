#include<stdio.h>
#include<stdlib.h>
#include "fila.h"
#include "pilha.h"
#define TAM 10


void compararSaoIguais(TPilha *pilha, TFila *fila){
    int i;
    if(tamanho_pilha(pilha) != tamanho_fila(fila)){
        printf("Não São Iguais");
    }
    if(tamanho_pilha(pilha) == tamanho_fila(fila)){
        TPilha *aux;
        aux = criar(tamanho_pilha(pilha));

        int tam = tamanho_pilha(pilha);
        for (i = 0; i < tam; i++){
            if(pilha->vetor[i] == f->ini + i){
                empilhar(aux, f->ini + i);
            }
        }

        if()  
    }
}


void percorrer_lista(TPilha *pilha){
	int i;
	for(i = 0; i < (pilha->tp+1); i++){
		printf("%d\n", pilha->vetor[i]);
	}
}

void pecorrer_fila(TFila *f){
	int i, j, ind;
	ind = f->ini;
	
	for(j = 0; j < f->qtd; j++){
		
		printf("[");
		for (i = 0 ; i < f->qtd ;i++){
			printf(" %d", f->ini + i);
		}
		printf(" ]\n");
		ind++;
		
	}
	printf("\n");	
}
