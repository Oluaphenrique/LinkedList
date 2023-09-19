#include "lista.c" //fazendo a junção da lista.c com a main.c

int main() {
    Lista *lista = lst_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    lista = lst_insere(lista, 42); // lista de inserir elementos na lista 42
    lista = lst_insere(lista, 17); // lista de inserir elementos na lista 17
    lista = lst_insere(lista, 65); // lista de inserir elementos na lista 65
    lista = lst_insere(lista, 23); // lista de inserir elementos na lista 23

    printf("Lista apos insercao de elementos:\n"); //exibir mensagem
    lst_imprime(lista); // imprimir lista
	printf("\n"); //exibir

    // Verifica se a lista está vazia
    if (lst_vazia(lista)) { //lista vazia
        printf("A lista esta vazia.\n"); // exibir mensagem de lista vazia
    } else { 
        printf("A lista nao esta vazia.\n"); // exibir mensagem que lista não está vazia
    }
	printf("\n"); //exibir

    // Busca um elemento na lista
    Lista *resultadoBusca = lst_busca(65, lista); //Buscar elemento 65 na lista  
    if (resultadoBusca != NULL) { // resultado de busca ser diferente de NULL 
        printf("Elemento %d encontrado na lista.\n", resultadoBusca->info); // exibir se o elemento foi encontrado dentro da lista  
    } else {
        printf("Elemento não encontrado na lista.\n");  // caso não tenha sido encontrado o elemento 65, exibir mensagem "elemento não encontrado na lista"
    }
	printf("\n"); // exibir 

    // Remove um elemento da lista
    lista = lst_retira(lista, 17); //remover elemento listado
    printf("Lista apos a remocao do elemento %d:\n", 17); // exibir lista após a remoção do elemento 17
    lst_imprime(lista); // imprimir lista
	printf("\n"); //exibir

    // Insere um elemento de forma ordenada na lista
    int elementoOrdenado = 10;  // inserindo elemento de ordem 10
    lista = lst_insere_ordenada(lista, elementoOrdenado); //atualização da lista de ordenação
    printf("Lista apos a insercao ordenada do elemento %d:\n", elementoOrdenado); // ebixir lista após a inclusão do elemento 10
    lst_imprime(lista); //imprimir lista
	printf("\n"); //exibir

    // Libera a memória da lista
    lst_libera(lista); 

    // Lê valores de um arquivo e insere na lista
    lista = lst_ler_arquivo("entrada.txt"); // ler arquivo de entrada 
    printf("Lista apos a leitura do arquivo:\n"); // exibir mensagem
    lst_imprime(lista);  //imprime a lista 

    // Libera a memória da lista novamente
    lst_libera(lista);

    return 0; // retorno
}
