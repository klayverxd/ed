#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
	Lista* l1 = lst_cria();
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,13);
	l1 = lst_insere(l1,25);
	l1 = lst_insere(l1,28);
	l1 = lst_insere(l1,40);
	lst_imprime(l1);
	
	Lista* l2 = lst_cria();
	l2 = lst_insere(l2,25);
	l2 = lst_insere(l2,13);
	l2 = lst_insere(l2,6);
	l2 = lst_insere(l2,40);
	l2 = lst_insere(l2,28);
	lst_imprime(l2);
	
	Lista* l3 = lst_div_n(l1, 2);
	lst_imprime(l3);
	
	printf("mesmos valores %d\n", duas_lst_mesmo_val(l1, l2));
	printf("mesmos valores %d\n", duas_lst_mesmo_val(l1, l3));
	
	system("PAUSE");
	return 0;
}

