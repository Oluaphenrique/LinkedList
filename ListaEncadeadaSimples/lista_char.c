/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista_char.h"

struct lista
{
	char info[100];
	struct lista *prox;
};

Lista *lst_cria(void) // cria lista
{
	return NULL;
}

Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista)); // Aloca memoria para um tipo estruturado Lista 
	if (novo == NULL)						     // verificar alocação
	{
		printf("[ERRO] memoria insuficiente!");	// memoria não alocada
		exit(1); // para execução 
	}
	strycp(novo->info , v); // Inserir o item na nó
	novo->prox = l; // aponando para a posição anterior
	return novo; // retorna novo nó

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l) // função para verificar se a lista está vazia
{
	return (l == NULL); // se a lista estiver vazia retorna a primeira seção
}

void lst_imprime(Lista *l) // função para imprimição de lista
{
	Lista *p; // contador do tipo lista
	for (p = l; p != NULL; p = p->prox) // p recebe o nó da lista; contador recebe o proximo nó 
	{
		printf("\tInfo = %d \n", p->info); // exibir a nó
	}
}

Lista *lst_busca(int elemento, Lista *l) //  função lista de busca
{
	Lista *p; // contador do tipo lista
	for (p = l; p != NULL; p = p->prox) // laço para pecorrer os nó
	{
		if (strcmp(p->info == elemento) == 0) // 
			return p; // retorna o nó atual 
	}

	return NULL; // elemento não encontrado
}

Lista *lst_retira(Lista *l, int v) // função para retirar da lista
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* nao achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

void lst_libera(Lista *l)
{
	Lista *p = l; // ponteiro para percorrer a lista
	Lista *t; //ponteiro para receber o nó seguinte 
	while (p != NULL) // enquanto p nao for o ultimo nó 
	{
		t = p->prox; // t aponta para o proximo nó
		free(p);  //  libera nó
		p = t; // p recebe o proximo no 
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo; // nó a ser inserido na lista
	Lista *ant = NULL; //ponteira aponta para elemento anterior
	Lista *p = l; // ponteiro para percorrer a lista
	while (p != NULL && strcpy (p->info , v) <0) //função de ordenação 
	{
		ant = p; // nó anterior vai receber o próximo nó
		p = p->prox; //p aponta para proximo nó 
	}
	novo = (Lista *)malloc(sizeof(Lista)); //alocação de memoria
	strcpy (novo->info, v); //inicializa 
	if (ant == NULL) //se nó estiver vazio
	{
		novo->prox = l; // nó aponta para posição da raiz
		l = novo; // nó vai assumir a posição 1 da raiz
	}
	else
	{
		novo->prox = ant->prox; // novo no aponta para no anterior
		ant->prox = novo; //no anterior aponta para proximo no
	}
	return l; // retorno 
}

Lista *lst_ler_arquivo(char *nome_arquivo) // função lista e ler arquivo 
{
	FILE *arquivo; //cria arquivo
	int valor; //vai receber o valor contido no arquivo
	Lista *l = lst_cria(); // função para criar lista vazia
	arquivo = fopen(nome_arquivo, "r"); // abrir arquivo "r" modo de leitura
	if (arquivo == NULL) // verificar alocação do arquivo 
	{
		printf("Erro ao abrir o arquivo!\n"); //
		exit(1); // 
	}
	while (fscanf(arquivo, "%d", &valor) != EOF) // ler valor e armazena
	{
		l = lst_insere(l, valor); // inserir o valor na lista 
	}
	fclose(arquivo); // fecha arquivo 
	return l; // retorna lista nova
}
