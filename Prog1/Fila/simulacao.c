#include "lib_fila.h"

int main(){

    t_fila aterrisagem[4];
    t_fila decolagem[3];

    int i, j, k; 
    int rodadas, nr_aterr, temp_aterr, nr_decol, fila_aterr_empilha, fila_decol_empilha, avioes_desesperados, avioes_caidos;
    int id_aterr_enfileira, id_decol_enfileira, id_aterr_desenfileira, id_decol_desenfileira;
    int ids_pousar_urgente[3], id_avioes_caidos[100];
    int id_item, tam_fila, tempo_item;

    fila_aterr_empilha = 0;
    fila_decol_empilha = 0;

    id_aterr_enfileira = 1;
    id_decol_enfileira = 2;   

    id_aterr_desenfileira = 1;
    id_decol_desenfileira = 2;     

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
            id_decol_enfileira += 2;
        }

        /*********** Processamento das Informações ***********/

        /* diminui um UT de cada aviao que quer aterrisar */
        for (j = 0; j < 4; j++){
            inicializa_atual_inicio(&aterrisagem[j]);
            tam_fila = tamanho_fila(&aterrisagem[j]);
            
            for (k = 0; k < tam_fila; k++){
                decrementa_tempo_atual(&aterrisagem[j]);
                incrementa_atual(&aterrisagem[j]);
            }

        }

        /* Ve se algum avião vai cair (tempo = 0) */
        avioes_caidos = 0;
        avioes_desesperados = 0;

        for (j = 0; j < 4; j++){
            tam_fila = tamanho_fila(&aterrisagem[j]);
            inicializa_atual_inicio(&aterrisagem[j]);

            for (k = 0; k < tam_fila; k++){
                consulta_tempo_atual(&tempo_item, &aterrisagem[j]);

                if ((avioes_desesperados <= 2) && (tempo_item == 0)){
                    consulta_id_atual(&id_item, &aterrisagem[j]);
                    ids_pousar_urgente[avioes_desesperados] =  id_item;
                    avioes_desesperados++;

                } else if ((avioes_desesperados > 2) && (tempo_item <= 0)){
                    consulta_id_atual(&id_item, &aterrisagem[j]);
                    id_avioes_caidos[avioes_caidos] = id_item;
                    avioes_caidos++;
                    remove_fila(id_item, &aterrisagem[j]);
                }
                incrementa_atual(&aterrisagem[j]);
            }
        }

        printf("QUANTIDADE DE AVIOPES DESESPERADOS: %d \n", avioes_desesperados);

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
                    printf("procurando o id %d na fila %d \n", ids_pousar_urgente[k], j);
                    if(remove_fila(ids_pousar_urgente[k], &aterrisagem[j])){
                        printf("ACHEI\n");
                    } /* Procura os ids salvos em todas as filas de aterrisagem e retira os elementos */
                }
            }

            for (j = 0; j < 3; j++){
                if (remove_fila(id_decol_desenfileira, &decolagem[j])){
                    id_decol_desenfileira += 2;
                    break;
                } 
            }
            
        /* Caso tenho apenas 1 avião desesperado, tira ele na pista 1, pousa outro na pista 2 e decola um na pista 3*/
        } else if (avioes_desesperados == 1){

            for (j = 0; j < 4; j++){
                remove_fila(ids_pousar_urgente[0], &aterrisagem[j]); /* Procura os ids salvos em todas as filas de aterrisagem e retira os elementos */
            }

            for (j = 0; j < 4; j++){
                if (remove_fila(id_aterr_desenfileira, &aterrisagem[j])){
                    id_aterr_desenfileira += 2;
                    break;
                } 
            }

            for (j = 0; j < 3; j++){
                if (remove_fila(id_decol_desenfileira, &decolagem[j])){
                    id_decol_desenfileira += 2;
                    break;
                } 
            }
        /* Caso nao tenha nenhum aviao para cair, pousa dois avioes e decola 1*/
        } else {
            for (j = 0; j < 4; j++){
                if (remove_fila(id_aterr_desenfileira, &aterrisagem[j])){
                    id_aterr_desenfileira += 2;
                    break;
                } 
            }
            for (j = 0; j < 4; j++){
                if (remove_fila(id_aterr_desenfileira, &aterrisagem[j])){
                    id_aterr_desenfileira += 2;
                    break;
                } 
            }
            for (j = 0; j < 3; j++){
                if (remove_fila(id_decol_desenfileira, &decolagem[j])){
                    id_decol_desenfileira += 2;
                    break;
                } 
            }
        }



        printf("Unidade de tempo %d\n", i);
        for (j = 0; j < 4; j++){
            printf("fila aterrisagem %d: ", j+1);
            imprime_fila(&aterrisagem[j], 0);
            printf("\n");
        }
        for (j = 0; j < 3; j++){
            printf("fila decolagem %d: ", j+1);
            imprime_fila(&decolagem[j], 1);
            printf("\n");
        }
        printf("numero de aeronaves que aterrisaram sem combustivel: %d\n", avioes_desesperados);
        printf("IDS das aeronaves que cairam: ");
        for (j = 0; j < avioes_caidos; j++){
            printf("%d ", id_avioes_caidos[j]);
        } 
        printf("\n");
    }

    for(i = 0; i < 4; i++)
        destroi_fila(&aterrisagem[i]);

    for(i = 0; i < 3; i++)
        destroi_fila(&decolagem[i]);

    return 0;
}