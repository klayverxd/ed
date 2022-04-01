#include <stdio.h>
#include <stdlib.h>  //funcoes
#include "pilha.h"

#define MAX 3

typedef struct pilha {
	int n;
	int v[MAX];
} Pilha;

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p==NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	p->n = 0;   //n � o contador da pilha
	
	return p;
}

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	if(p->n==MAX) {   //verificando se a pilha est� cheia
		printf("Capacidade da Pilha Estourou!!!\n");
		exit(1);
	}
	
	p->v[p->n]= info;   //vetor p na posi��o escalar n
	
	p->n = p->n + 1;   //incrementando o contador
}

/*Fun��o que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	int i;
	//n � o �ndice da posi��o acima do topo (posi��o "livre")
	for(i = p->n-1; i>=0; i--){    //imprime do topo para a base
		printf("%f\n", p->v[i]);
	}
}

/*Libera o espa�o alocado para uma pilha.*/
//foi criada dinamicamente
void pilha_libera(Pilha *p){
	free(p);
}

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p){
	return p->n==0;   //retorno l�gico
}

/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	
	if(pilha_vazia(p)){   //verificando se a pilha est� vazia
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	
	a = p->v[p->n-1];   //elemento do topo
	
	p->n--;   //decrementando o contador
	
	return a;   //retornando o valor que foi "retirado"
}	

