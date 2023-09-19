// Bibliotecas declarada em lista.h
#include "lista.h"

struct lista // declaração da struct lista
{
	int info; // recebe uma informação do tipo inteiro
	struct lista *prox; // lista ponteiro proximo
};

Lista *lst_cria(void) // função cria lista
{
	return NULL; // retorna 
}

Lista *lst_insere(Lista *l, int v) // função para inserir lista 
{
	Lista *novo = (Lista *)malloc(sizeof(Lista)); // função criar lista 
	if (novo == NULL)
	{
		printf("[ERRO] memoria insuficiente!"); // exibir mensagem de erro, caso não tenha memoria suficiente.
		exit(1); // encerra a execução
	}
	novo->info = v; // sera o primeiro elemento da lista v 
	novo->prox = l; // sera o primeiro elemento da lista l
	return novo; // retorna nova

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l) // função para verificar se a lista está vazia
{
	return (l == NULL); // retorno
}

void lst_imprime(Lista *l) // função para fazer a impressão da lista 
{
	Lista *p; //
	for (p = l; p != NULL; p = p->prox) // enquanto o p for diferente de NULL, ele continuarar fazendo o laço p->prox
	{
		printf("\tInfo = %d \n", p->info); // exibir  
	}
}

Lista *lst_busca(int elemento, Lista *l) // função para buscar listar 
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox) // enquanto o p for diferente de NULL, ele continuarar fazendo o laço p = p->prox
	{
		if (p->info == elemento) 
			return p; // retorno
	}

	return NULL; // retorno
}

Lista *lst_retira(Lista *l, int v) // função retirar da lista
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
	free(p); // 
	return l; // retorna a lista de origem 
}

void lst_libera(Lista *l) // função libera lista 
{
	Lista *p = l;
	Lista *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p); //
		p = t;
	}
}

Lista *lst_insere_ordenada(Lista *l, int v) // função ordenar a lista inserida 
{
	Lista *novo;  // lista nova
	Lista *ant = NULL; // lista anterior
	Lista *p = l; // lista
	while (p != NULL && p->info < v) // 
	{
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista)); // 
	novo->info = v; // ponteiro apontando para informação que tem dentro de v
	if (ant == NULL)
	{
		novo->prox = l; // novo ponteiro apontando para proximo ponteiro
		l = novo; // novo agora sera o primeiro elemento da lista l
	}
	else
	{
		novo->prox = ant->prox; // novo ponteiro apontando para para proximo ponteiro 
		ant->prox = novo; // ponteiro anterior apontando para o novo ponteiro
	}
	return l; // retorna a lista de origem 
}

Lista *lst_ler_arquivo(char *nome_arquivo) // função para ler os arquivos listados
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria(); 
	arquivo = fopen(nome_arquivo, "r"); // função para abrir arquivo 
	if (arquivo == NULL) 
	{
		printf("Erro ao abrir o arquivo!\n"); // exibir mensagem de erro
		exit(1); //encerrar excecurcao
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor); // lista inserir 
	}
	fclose(arquivo); // fechar arquivo
	return l; // retorna a lista de origem 
}

=======
Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"

struct lista
{
	int info;
	struct lista *prox;
};

Lista *lst_cria(void)
{
	return NULL;
}

Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	if (novo == NULL)
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;
	novo->prox = l;
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l)
{
	return (l == NULL);
}

void lst_imprime(Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		printf("\tInfo = %d \n", p->info);
	}
}

Lista *lst_busca(int elemento, Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == elemento)
			return p;
	}

	return NULL;
}

Lista *lst_retira(Lista *l, int v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* n�o achou: retorna lista original */
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
	Lista *p = l;
	Lista *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	while (p != NULL && p->info < v)
	{
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = v;
	if (ant == NULL)
	{
		novo->prox = l;
		l = novo;
	}
	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}

>>>>>>> e4bca856317f21c1c9f5c54f4b760b44057c4981