#include <stdio.h>
#include <stdlib.h>
#include "filapri.h"

struct Pilha{	
	int *vetor;
	int qtde, tp;	
};

TPilha *criar_pilha(int n){	
	TPilha *pilha;
	pilha = (TPilha *)malloc(sizeof(TPilha));
	pilha->vetor = malloc(n * sizeof(int));
	pilha->qtde = n;
	pilha->tp = -1;	
	return pilha;
}

void empilhar(TPilha *pilha, int x){ // empilhar	
	if(pilha->tp < pilha->qtde - 1){ //verifica se não esta cheio	
		pilha->tp = pilha->tp + 1;	 // incrementa o topo
		pilha->vetor[pilha->tp] = x; // inclui o elemento x
	}
}
int desempilhar(TPilha *pilha){	//desempilhar
	if(pilha->tp > -1){	// verifica se não esta vazia	
		pilha->tp -= 1;
		return pilha->vetor[pilha->tp+1];		
	}
}


int tamanho_pilha(TPilha *pilha){
	return pilha->qtde;
}

int topo(TPilha *pilha){
	return pilha->vetor[pilha->tp];
}

int esta_vazia(TPilha *pilha){
	if(pilha->tp == -1){
		return 0;
	}
	else{
		return 1;
	}
}

void inverter_pilha(TPilha *pilha){
	TPilha *f, *r;

	f = criar(pilha->qtde);
	r = criar(pilha->qtde);
	int n = pilha->tp+1;
	
	int i;
	for(i = 0; i < (n); i++){
		empilhar(f, desempilhar(pilha));
	}
	for(i = 0; i < (n); i++){
		empilhar(r, desempilhar(f));
	}
	for(i = 0; i < (n); i++){
		empilhar(pilha, desempilhar(r));
	}	
}

void percorrer_lista(TPilha *pilha){
	int i;
	for(i = 0; i < (pilha->tp+1); i++){
		printf("%d\n", pilha->vetor[i]);
	}
}

void primeira_ocorrencia(TPilha *pilha, int n){
	TPilha *aux1, *aux2; 
	int i, j, k, cont;
	
	k = pilha->tp+1;
//	k = topo(pilha);
//	k = tamanho(pilha);
	aux1 = criar_pilha(pilha->qtde);
//	aux2 = criar(pilha->qtde);
//	inverter(pilha);
	
	
	for(i = 0; i < (k); i++){
		empilhar(aux1, desempilhar(pilha));
	}
	
	cont = 0;
	for(i = 0; i < (k); i++){
		int v = desempilhar(aux1);
		if(v != n || cont ==1){
				empilhar(pilha, v);
		}
		else{
			cont = 1;
		}	
	}
	
	
}

