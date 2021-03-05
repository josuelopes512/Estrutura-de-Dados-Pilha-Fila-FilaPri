#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "funcoes.h"
#include "fila.h"
#define TAM 10

int main(int argc, char *argv[]){

	TFila *f = criar();
	int i;
	for(i =0; i < TAM; i++){
		enfileirar(f, i);
	}

	TPilha *p = criar_pilha();
//	enfileirar(f, 33);
//	enfileirar(f, 4);
//	enfileirar(f, 6);
//	enfileirar(f, 2);
//	enfileirar(f, 9);
//	exibir(f);
//	pecorrer_fila(f);
//	esvaziar_fila(f);
//	exibir(f);	
//	inverter_fila(f);
	exibir(f);
	inverter(f);
//	removerValor(f, 0);
//	printf("tamanho %d, posicao inicial %d", tamanho(f), posiInic(f));
	exibir(f);
//	desenfileirar(f);
//	desenfileirar(f);
//	desenfileirar(f);
//	exibir(f);
//	tamanho(f);
//	posiInic(f);
//	vazia(f);
//	cheia(f);
	return 0;
}

