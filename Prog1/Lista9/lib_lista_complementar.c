/*
  Feito por Marcos Castiho para a disciplina CI1001 - Programacao I
  Em 18/10/2019.
  Biblioteca auxiliar que manipula o TAD lista. 
*/

/*
  Funcao que imprime todos os elementos da lista, do inicio ao fim.
  Caso a lista seja vazia nao imprime nada, nem um \n
*/
#include "lib_lista_complementar.h"

void imprime_lista(t_lista *l){
    
    int i, item, tamanho;

    tamanho_lista(&tamanho, l);
    
    if (lista_vazia(l))
        return;

    inicializa_atual_inicio(l);

    for(i = 0; i < tamanho; i++){
        consulta_item_atual(&item,l);
        printf("%d ", item);
        incrementa_atual(l);
    } 
    
    printf("\n");

}

/*
  Funcao que copia todos os elementos da lista l na lista c.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int copia_lista(t_lista *l, t_lista *c){
    
  int i, item, tamanho;
  tamanho_lista(&tamanho, l);
  
  if (lista_vazia(l))
    return 0;

  inicializa_atual_inicio(l);

  for (i = 0; i < tamanho; i++){
    consulta_item_atual(&item, l);
    insere_fim_lista(item, c);
    incrementa_atual(l);
  }

  return 1;
}

/*
  Concatena os elementos da lista m (na mesma ordem) ao final
  da lista l e destroi a lista m.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int concatena_listas(t_lista *l, t_lista *m){
  if (lista_vazia(l) && lista_vazia(m))
    return 0;

  int i, item, tamanhom;

  tamanho_lista(&tamanhom, m);

  inicializa_atual_inicio(m);

  for (i = 0; i < tamanhom; i++){
    consulta_item_atual(&item, m);
    insere_fim_lista(item, l);
    incrementa_atual(m);
  }

  destroi_lista(m);

  return 1;
}

/*
  Ordena a lista l em ordem crescente.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int ordena_lista(t_lista *l);

/*
  Funcao que cria uma nova lista i pela intercalacao dos elementos
  das listas l e c. As listas l e c devem estar ordenadas.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int intercala_listas(t_lista *l, t_lista *m, t_lista *i);
