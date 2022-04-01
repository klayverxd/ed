typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Testa se uma lista eh vazia.*/
int lst_vazia(Lista *l);

/* Insere um elemento no inicio da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Insere um elemento em ordem */
Lista* lst_insere_ordem(Lista *l, int info);

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Libera o espaco alocado por uma lista.*/
void lst_libera(Lista *l);

int duas_lst_mesmo_val(Lista* l1, Lista* l2);

Lista* lst_div_n(Lista* l, int n);

