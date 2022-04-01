typedef struct arv Arv;

/*Fun��o que cria uma �rvore Bin�ria Vazia.*/
Arv* arv_cria_vazia(void);

/*Fun��o que cria um n� em uma �rvore Bin�ria.*/
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arv_vazia(Arv *a);

/*Fun��o que imprime os elementos de uma �rvore Bin�ria.*/
void arv_imprime(Arv *a);

/*Fun��o que determina se um caractere pertence � �rvore.*/
int arv_pertence(Arv *a,char c);

/*Libera o espa�o alocado para uma �rvore Bin�ria.*/
void arv_libera(Arv *a);

/*Fun��o quer retorna o tamanho de uma �rvore.*/
int arv_altura(Arv *a);
