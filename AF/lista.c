#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista ? vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no in?cio da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

/* Insere um elemento em ordem */
Lista* lst_insere_ordem(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	Lista* lAux = l;
	
	ln->info = info;
	
	//se tiver inicialmente vazia
	if(l == NULL) {
		ln->prox = l;
		return ln;
	}
	
	//se o primeiro numero já for maior do que info
	if(l->info > info) {
		ln->prox = l;
		return ln;
	}
	
	//se info precisar ser inserido entre o primeiro e o ultimo elemento
	while(lAux != NULL) {
		if(lAux->prox->info >= info) {
			ln->prox = lAux->prox;
			lAux->prox = ln;
			
			return l;
		}
		
		lAux = lAux->prox;
	}
	
	//se info precisar ser inserido no ultimo elemento
	if(lAux == NULL) {
		lAux->prox = ln;
		ln->prox = NULL;
		
		return lAux;
	}
}

/* Busca um elemento em uma lista (retorna o endere?o ou NULL).*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		
		lAux = lAux->prox;
	}
	
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux != NULL){
		printf("Info = %d\n",lAux->info);
		
		lAux = lAux->prox;
	}
}

/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else {
		lst_imprime_invertida_rec(l->prox);
		printf("Info = %d\n",l->info);
	}
}

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		
		if(l->info==info){
			free(l);
			return lAux;
		} else {
			Lista* lAnt = l;
			
			while(lAux!=NULL ){
				if(lAux->info == info){
					lAnt->prox = lAux->prox;
					free(lAux);
					
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

/* Libera o espa?o alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l != NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

int duas_lst_mesmo_val(Lista* l1, Lista* l2) {
	Lista* lAux;
	Lista* lAuxl1 = l1;
	
	//verificando os valores de l1 em l2
	while(lAuxl1 != NULL){   //enquanto nao chegar no fim da "primeira lista"
		lAux = lst_busca(l2, lAuxl1->info);   //retorna o endereco encontrado ou nulo
		
		if (lAux == NULL ){ //se não existir igual
			return 0;
		}
		
		lAuxl1 = lAuxl1->prox;
	}
	
	//verificando os valores de l2 em l1
	Lista* lAuxl2 = l2;
	
	while(lAuxl2 != NULL){
		lAux = lst_busca(l1, lAuxl2->info);
		
		if (lAux == NULL ){
			return 0;
		}
		
		lAuxl2 = lAuxl2->prox;
	}
	
	//caso contenha todos os valores de l1 em l2
	return 1;
}

// nova lista com os valores de l1 divisível por n
Lista* lst_div_n(Lista* l, int n) {
	Lista* lAux = l;
	Lista* l2 = lst_cria();
	
	while(lAux != NULL){		
		if (lAux->info % n == 0) {
			l2 = lst_insere_ordem(l2, lAux->info);
		}
		
		lAux = lAux->prox;
	}
	
	return l2;
}


