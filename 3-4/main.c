#include <stdio.h>
#include <stdlib.h>
#include "filapri.h"
#define TAM 10

int main(int argc, char *argv[]){

	TFilaPri *f = criarFilaPri();
	int i;
	
	
	inserirFilaPri(f, 5);
	inserirFilaPri(f, 35);
	inserirFilaPri(f, 45);
	inserirFilaPri(f, 15);
	inserirFilaPri(f, 51);
	inserirFilaPri(f, 52);
	inserirFilaPri(f, 9);

	
	printf("%d\n", extrairMaxFilaPri(f));
	printf("%d\n", encontrarMaxFilaPri(f));
	



	//exibeFilaPri(f);

	return 0;
}
