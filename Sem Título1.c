void inverter(TFila *f){
        TPilha *pilha;
        TFila *r;
        pilha = criarP(f->qtd);
        int n = f->fim+1;
    
        int i;
        for(i = 0; i < (n); i++){
            empilhar(pilha, desenfileirar(f));
        }
        for(i = 0; i < (n); i++){
            desenfileirar(f);
        }
        for(i = 0; i < (n); i++){
            enfileirar(f, desempilhar(pilha));
        }
    }
