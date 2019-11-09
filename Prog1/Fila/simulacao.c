#include "lib_fila.h"

int main(){

    t_fila aterrisagem[4];
    t_fila decolagem[3];

    int i, j, k; 
    int rodadas, nr_aterr, temp_aterr, nr_decol, fila_aterr_empilha, fila_decol_empilha,fila_aterr_desempilha, fila_decol_desempilha, aterrisados, alternado, avioes_desesperados;
    int id_aterr_enfileira, id_decol_enfileira, id_aterr_desenfileira, id_decol_desenfileira, avioes_caidos;
    int ids_pousar_urgente[3], id_avios_caidos[100];

    /* 
    decide se a pista 2 vai ser usada para pouso ou decolagem, alterna a cada rodada de tempo a nao ser que seja necessário pousar 3 aviões, nesse caso ela vai ficar para pouso obrigatoriamente. A pista 1 será destinada sempre para pouso e a pista 3 sera destinada sempre para decolagens (a nao ser igual ao caso da pista 2)
    */
    alternado = 0; 

    fila_aterr_empilha = 0;
    fila_decol_empilha = 0;
    fila_aterr_desempilha = 0;
    fila_decol_desempilha = 0;

    id_aterr_enfileira = 1;
    id_decol_enfileira = 2;   

    id_aterr_desenfileira = 1;
    id_decol_desenfileira = 2;     

    avioes_desesperados = 0;
    avioes_caidos = 0;


    /* Inicializa Filas */
    for (i = 0; i < 4; i++)
        inicializa_fila(&aterrisagem[i]);

    for (i = 0; i < 3; i++)
        inicializa_fila(&decolagem[i]);

    /* Lê a quantidade de rodadas*/
    scanf("%d", &rodadas);

    /* Loop Principal */
    for (i = 1; i <= rodadas; i++){
        
        /* Lê a quantidade de aviões que querem pousar*/
        scanf("%d", &nr_aterr);
        for (j = 0; j < nr_aterr; j++){
            scanf("%d", &temp_aterr);
            enfileira(id_aterr_enfileira, temp_aterr, &aterrisagem[fila_aterr_empilha]);
            fila_aterr_empilha = (fila_aterr_empilha + 1) % 4; /* Para alternar entre as filas */
            id_aterr_enfileira += 2;
        }
        /* Le a quantidade de avioes que entraram pra fila de decolagem */
        scanf("%d", &nr_decol);
        for (j = 0; j < nr_decol; j++){
            enfileira(id_decol_enfileira, 0, &decolagem[fila_decol_empilha]);
            fila_decol_empilha = (fila_decol_empilha + 1) % 3; /* Para alternar entre as filas */
        }

        /*********** Processamento das Informações **********/

        /* Ve se algum avião vai cair (tempo = 0) */
        avioes_desesperados = 0;
        for (j = 0; j < 4; j++){
            int tam_fila = tamanho_fila(&aterrisagem[j]);
            inicializa_atual_inicio(&aterrisagem[j]);
            for (k = 0; k <tam_fila; k++){
                int tempo_item;
                consulta_tempo_atual(&tempo_item, &aterrisagem[j]);
                if ((avioes_desesperados < 3) && (tempo_item == 0)){
                    int id_item;
                    consulta_id_atual(&id_item, &aterrisagem[j]);
                    ids_pousar_urgente[avioes_desesperados++] =  id_item;
                }
            }
        }

        /* Caso tenham 3 aviões necessitados para pousar, pousa os 3 e não decola nenhum*/
        if (avioes_desesperados == 3){
            for (j = 0; j < 4; j++){
                for (k = 0; k < 3; k++){
                    remove_fila(ids_pousar_urgente[k], &aterrisagem[j]); /* Procura os ids salvos em todas as filas de aterrisagem e retira os elementos */
                }
            }
        /* Caso tenham 2 aviões desesperados, usa as pistas 1 e 2 para pousar eles e a 3 para decolar um que está na fila de decolagem*/
        } else if (avioes_desesperados == 2){ 
            for (j = 0; j < 4; j++){
                for (k = 0; k < 2; k++){
                    remove_fila(ids_pousar_urgente[k], &aterrisagem[j]); /* Procura os ids salvos em todas as filas de aterrisagem e retira os elementos */
                }
            }

            /* Se nao tiver avioes para decolar, pousa um avião extra */
            if (desenfileira(id_decol_desenfileira)

        }
        

    }

    return 0;
}