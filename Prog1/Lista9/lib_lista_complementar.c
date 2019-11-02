
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

int ordena_lista(t_lista *l){
  
  if (lista_vazia(l))
    return 0;
  
  t_lista auxiliar;
  int i, tamanho, item;

  inicializa_lista(&auxiliar);

  tamanho_lista(&tamanho, l);  
  inicializa_atual_inicio(l);

  for (i = 0; i < tamanho; i++){
    consulta_item_atual(&item, l);
    insere_ordenado_lista(item, &auxiliar);
    incrementa_atual(l);
  }

  esvazia_lista(l);

  copia_lista(&auxiliar, l);
  destroi_lista(&auxiliar);

  return 1;

}

int intercala_listas(t_lista *l, t_lista *m, t_lista *i){
  
  int tamanhol, tamanhom, iteml, itemm, menor, j;
  
  if (lista_vazia(l) && lista_vazia(m))
    return 0;

  ordena_lista(l);
  ordena_lista(m);

  tamanho_lista(&tamanhol, l);
  tamanho_lista(&tamanhom, m);

  (tamanhol < tamanhom) ? (menor = tamanhol) : (menor = tamanhom);

  inicializa_atual_inicio(l);
  inicializa_atual_inicio(m);

  for (j = 0; j < menor; j++){
    consulta_item_atual(&iteml, l);
    consulta_item_atual(&itemm, m);

    insere_fim_lista(iteml, i);
    insere_fim_lista(itemm, i);

    incrementa_atual(l);
    incrementa_atual(m);

    }

  if (tamanhol < tamanhom){
    for (j = 0; j < tamanhom - tamanhol; j++){
      consulta_item_atual(&itemm, m);
      insere_fim_lista(itemm, i);
      incrementa_atual(m);
    }
  } else {
    for (j = 0; j < tamanhol - tamanhom; j++){
      consulta_item_atual(&iteml, l);
      insere_fim_lista(iteml, i);
      incrementa_atual(l);
    }
  }

  return 1;
}
