#include<stdio.h>
#include<stdlib.h>
#include "fila.h"
#define TAM 10

struct fila{
	int vetor[TAM];
	int ini,fim,qtd;
};

TFila* criar(){
	TFila * fila = (TFila*)malloc(sizeof(TFila));
	fila->ini = -1;
	fila->fim= -1;
	fila->qtd= 0; 
	
	return fila;
}

void enfileirar (TFila *f, int v){
	if (!((f->fim+1) % TAM == f->ini )) {
		if (f->ini == -1) f->ini=0;
		f->fim = (f->fim+1)%TAM;
		f->vetor[f->fim] = v;
		f->qtd = f->qtd+1;
	}
}

int desenfileirar(TFila *f){
	int d = -1;
	
	if (f->ini > -1){
		d= f->vetor[f->ini];
		if(f->ini == f->fim) f->ini=f->fim=-1;
		else f->ini = (f->ini + 1) % TAM;
		
		f->qtd = f->qtd-1;
	}
	return d;
}

void exibir (TFila *f){
	int i, ind;
	ind = f->ini;
	
	printf("\n Inicio indice: %d \n", f->ini);
	printf("    Fim indice: %d \n" ,f->fim);
	printf("\n");
	
	printf("[");
	for (i=0 ; i<f->qtd;i++){
		printf(" %d", f->ini + i);
	}
	printf(" ]\n");
	
	
	printf("[");
	for (i=0 ; i<f->qtd;i++){
		printf(" %d", f->vetor[ind]);
		ind= (ind+1)%TAM;
	}
	printf(" ]\n");
	
	printf("\n");	
}

int tamanho_fila(TFila *f){
	return f->qtd;
}

int posiInic(TFila *f){
	int ind = f->ini;
	return	f->vetor[ind];
}

void vazia(TFila *f){

	if (f->qtd == 0){
		printf("esta vazia ");
		printf("%d \n", 1);
	}
	
	else{
		printf("nao esta vazia ");
		printf("%d \n", 0);
	  }

}

void cheia(TFila *f){
	if (f->qtd == TAM){
		printf("esta cheia ");
		printf("%d \n", 1);
	}
	
	else{
		printf("esta nao esta cheia ");
		printf("%d \n", 0);
	}
}

void esvaziar_fila(TFila *f){
	int i;
	for(i=0; i < TAM; i++){
		exibir(f);
		desenfileirar(f);
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
	
	
//	for(j = 0; j < TAM; j++){
//		printf("[");
//		
//		for (i=0 ; i<f->qtd;i++){
//			printf(" %d", f->vetor[ind+j]);
//			ind= (ind+1)%TAM;
//		}
//		printf(" ]\n");	
//	}	
	printf("\n");	
}

int imprimir(TFila *f){
	int ind = f->ini;
	int ind2= f->fim;
//	int a;
	
	if (f->vetor[ind] == f->vetor[ind2]){
		//printf("vazio \n");
		return 1;	
	}
	
 	else{
		return 0;
	}
	
//	return a; 
}

void removerValor(TFila *f, int v){
	int i, qtdi;
	qtdi = tamanho(f);
	TFila *aux = criar();
	
	for(i = 0; i < qtdi; i++){
		int n = desenfileirar(f);
		enfileirar(aux, n);
	}
	
	for(i=0;i<qtdi;i++){
		int n = desenfileirar(aux);
		if (n != v)
		enfileirar(f, n);
	}
}

void inverter(TFila *f){
	TPilha *pilha;
	TFila *r;
	pilha = criar_pilha(f->qtd);
	int n = f->fim+1;
	int i;
	for(i = 0; i < (n); i++){
		empilhar(pilha, desenfileirar(f));
	}
	desenfileirar(f);
	for(i = 0; i < (n); i++){
		enfileirar(f, desempilhar(pilha));
	}
}

/*
void inverter_fila(TFila *f){
	int i, j, tam, ind;
	tam = tamanho(f);
	TFila *aux1 = criar();
	TFila *aux2 = criar();
	
//	for (i=0 ; i<f->qtd;i++){
//		printf(" %d", f->vetor[ind]);
//		ind= (ind+1)%TAM;
//	}
	
	
	for(i = 0; i < tam; i++){
		
		enfileirar(aux1, f->vetor[5]);
	//	ind= (ind-1)%TAM;
		//aux[j++] = f->vetor[i];
	}
	
//	for(j = 0; j < tam; j++){
//		enfileirar(aux2, desenfileirar(aux1));
//	}
	
	for(j = 0; j < tam; j++){
		enfileirar(f, desenfileirar(aux1));
	}
}*/

