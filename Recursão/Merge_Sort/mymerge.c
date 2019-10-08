#define MAX 10

void merge(int v[], int ini, int meio, int fim){

    int vtemp[MAX];
    int p1 = ini, p2 = meio+1, f1 = 1, f2 = 1, tam = fim-ini+1;
    int i, j;
    for(i = 0; i < tam; i++){
        if (f1 && f2){
            if (v[p1] < v[p2])
                vtemp[i] = v[p1++];
            else
                vtemp[i] = v[p2++];

            if (p1 > meio) f1 = 0;
            if (p2 >  fim) f2 = 0; 
        } else {
            if (f1)
                vtemp[i] = v[p1++];
             else
                vtemp[i] = v[p2++];
        }
    }

    for (i = 0, j = ini; i < tam; i++,j++){
        v[j] = vtemp[i];
    }


}

void merge_sort(int v[], int ini, int fim){
    if(ini < fim){
        int meio = (ini+fim) / 2;
        merge_sort(v, ini   , meio);
        merge_sort(v, meio+1, fim );
        merge(v, ini, meio, fim);
    }
}