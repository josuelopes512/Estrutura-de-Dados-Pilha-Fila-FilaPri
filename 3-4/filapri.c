#include <stdio.h>
#include <stdlib.h>
#include "filapri.h"
#define TAM 10

struct filaPri{
	int vetor[TAM + 1];
	int qtde;	
};

TFilaPri *criarFilaPri(){
	TFilaPri *fp =  (TFilaPri *)malloc(sizeof(TFilaPri));
	fp->qtde = 0;
	return fp;
}

void corrigirSubindo(TFilaPri *fp){
	int i = fp->qtde;
	while(i >= 2 && fp->vetor[i/2] < fp->vetor[i]){
		int temp = fp->vetor[i/2];
		fp->vetor[i/2] = fp->vetor[i];
		fp->vetor[i] = temp;
		i = i / 2;
	}
}

void inserirFilaPri(TFilaPri *fp, int n){
	if(fp->qtde < TAM){
		fp->qtde = fp->qtde+1;
		fp->vetor[fp->qtde] = n;
		corrigirSubindo(fp);
	}
}

void corrigirDescendo(TFilaPri *fp){
	int j = 1;
	while(2 * j <= fp->qtde){
		int f = 2 * j;
		if(f < fp->qtde && fp->vetor[f] < fp->vetor[f+1]){
			f = f+1;
		}
		
		if(fp->vetor[j] >= fp->vetor[f]){
			j = fp->qtde;
		}
		else{
			int temp = fp->vetor[j];
			fp->vetor[j] = fp->vetor[f];
			fp->vetor[f] = temp;
			j = f;
		}
	}
}

int extrairMaxFilaPri(TFilaPri *fp){
	if(fp->qtde > 0){
		int max = fp->vetor[1];
		fp->vetor[1] = fp->vetor[fp->qtde];
		fp->qtde = fp->qtde - 1;
		corrigirDescendo(fp);
		return max;
	}
}

int encontrarMaxFilaPri(TFilaPri *fp){
	//int len = tamanhoFilaPri(fp);
	int i, max;
	
	for(i = 0; i < TAM; i++){ 
		if(fp->vetor[i] > max){
			max = fp->vetor[i];
		} 
	}

	
	
//	int max = extrairMaxFilaPri(fp);
	
	return max;
}

int tamanhoFilaPri(TFilaPri *fp){
	return TAM;
}


int qtde(TFilaPri *fp){
	return fp->qtde;
}
