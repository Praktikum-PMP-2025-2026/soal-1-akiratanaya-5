//Nama: Akira Kenji Tanaya
// NIM : 13224046

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
    char nama[100];
    int id; 
    char shift[100];
    int skor; 
} Penjaga;

void input (int size, Penjaga* penjaga){
    for (int i =0 ; i<size; i++){
        scanf("%s", penjaga[i].nama);
        scanf("%d", &penjaga[i].id);
        scanf("%s", penjaga[i].shift);
        scanf("%d", &penjaga[i].skor);        
    }
}

void output (int size, Penjaga* penjaga){
    for (int i =0 ; i<size; i++){
        printf("%s ", penjaga[i].nama);
        printf("%d ", penjaga[i].id);
        printf("%s ", penjaga[i].shift);
        printf("%d\n", penjaga[i].skor);        
    }
}

// void swapPenjaga (Penjaga *penjaga1, Penjaga *penjaga2){
//     Penjaga temp;
//     temp= *penjaga1;
//     *penjaga1= *penjaga2;
//     *penjaga2=temp;


// }

void sorted (Penjaga* penjaga, int size){
    for (int i=0; i<size-1; i++){
        for (int j=i+1; j<size; j++){
            if (penjaga[j].skor>penjaga[i].skor){
                    Penjaga temp = penjaga[i];
                    penjaga[i]=penjaga[j];
                    penjaga[j]=temp;
            }
            if (penjaga[i].skor==penjaga[j].skor){
                if (penjaga[i].nama<penjaga[j].nama){
                    Penjaga temp = penjaga[i];
                    penjaga[i]=penjaga[j];
                    penjaga[j]=temp;
                }
            }
        }
    }
}

int idxhighestpagi(Penjaga* penjaga, int size){
    int top ;
    for (int i=0; i<size; i++){
        if (strcmp(penjaga[i].shift,"PAGI")==0){
            top = i;
            break;
        }


    }
    return top; 
    

}

int idxhighestsiang(Penjaga* penjaga, int size){
    int top ;
    for (int i=0; i<size; i++){
        if (strcmp(penjaga[i].shift,"SIANG")==0){
            top = i;
            break;
        }
    }
    return top;
}

int idxhighestmalam(Penjaga* penjaga, int size){
    int top ;
    for (int i=0; i<size; i++){
        if (strcmp(penjaga[i].shift,"MALAM")==0){
            top = i;
            break;
        }
    }
    return top; 
}



int main(void) {
    int size ;
    int idxsiang;
    int idxpagi;
    int idxmalam;
    Penjaga* penjaga;
    scanf("%d", &size);
    penjaga= (Penjaga*) malloc(size * sizeof(Penjaga));
    input(size, penjaga);
    sorted(penjaga, size);

    // swapPenjaga(&penjaga[1], &penjaga[2]);
    // printf("%s", temp.nama);
    idxpagi= idxhighestpagi(penjaga,size);
    idxsiang= idxhighestsiang(penjaga, size);
    idxmalam= idxhighestmalam(penjaga, size);

    if (strcmp(penjaga[idxpagi].shift,"PAGI")==0){
        printf("PAGI %s %d %d\n", penjaga[idxpagi].nama, penjaga[idxpagi].id, penjaga[idxpagi].skor);
    }
    else {
        printf("PAGI -\n");
    }
    if (strcmp(penjaga[idxsiang].shift,"SIANG")==0){
    printf("SIANG %s %d %d\n", penjaga[idxsiang].nama, penjaga[idxsiang].id, penjaga[idxsiang].skor);
    }
    else {
        printf("SIANG -\n");
    }

    if (strcmp(penjaga[idxmalam].shift,"MALAM")==0){
    printf("MALAM %s %d %d\n", penjaga[idxmalam].nama, penjaga[idxmalam].id, penjaga[idxmalam].skor);
    }
    else {
        printf("MALAM -\n");
    }

    // printf("%d\n",strcmp(penjaga[1].shift,"PAGI"));
    // output(size, penjaga);

    free(penjaga);
    return 0;
}
