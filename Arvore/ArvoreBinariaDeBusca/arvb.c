ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
	
		return NULL;
	
	else if(a->info < c)
	
		return arvb_busca(a->dir,c);
	
	else if(a->info > c)
	
		return arvb_busca(a->esq,c);
	
	else //(a->info == c)
	
		return a;

}

void arvb_imprime(ArvB *a){  //impress�o sim�trica (em ordem)
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		
		printf("%d ",a->info);
		
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
		
	}else if(a->info > c)   //se o valor for menor que o n�
		a->esq = arvb_insere(a->esq, c);
		
	else if (a->info < c)  //se o valor for menor que o n�
		a->dir = arvb_insere(a->dir, c);
		
	else
		printf("\nElemento Ja Pertence a Arvore");
		
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq, c);
			
		else if (a->info < c)
			a->dir = arvb_remove(a->dir, c);
			
		else {   //quando encontra o valor a ser removido
			ArvB* t;   //estrutura auxilixar para o n� que vai ser removido
			
			if (a->esq == NULL){
				t = a;   //aponta pro n� a ser removido
				a = a->dir;   //aponta para o lado direito
				
				free(t);  //libera o n� do valor a ser removido
			} else if (a->dir == NULL){
				t = a;   //aponta pro n� a ser removido
				a = a->esq;   //aponta para o lado esquerdo
				
				free(t);   //libera o n� do valor a ser removido
			} else {
				t = a->esq;   //trabalhando na sub�rvore esquerda
				
				while(t->dir!=NULL)  //enquanto puder ir pra direita, vai indo
					t = t->dir;   //no final ele apontar� para o valor mais � direita
					
				a->info = t->info;   //o n� recebe o valor mais � direita
				t->info = c;   //o n� mais � direita recebe o valor a ser removido
				
				a->esq = arvb_remove(a->esq, c);   //removendo o n� mais � direita da sub�rvore
			}
		}
	}
	
	return a;
}
