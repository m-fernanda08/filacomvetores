#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int fila[MAX];
int f = -1;
int t = -1;

bool cheia(){
    if ((f == 0 && t == MAX - 1) || f == t + 1){
        return true;
    }else{
        return false;
    }
}

bool vazia(){
    if(f == - 1){
        return true;
    }else{
        return false;
    }
}

void enfileirar(int val){
    if(cheia()){
        printf("fila cheia. não é possível enfileirar.\n");
    }else{
        if(f == 1){
            f = 0;
        }
        t = (t + 1) % MAX;
        fila[t] = val;
        printf("%d foi enfileirado.\n", val);
    }
}

int desinf(){
    int val;
    if(vazia()){
        printf("fila vazia. não é possível desinfileirar.\n");
        return -1;
    }else{
        val = fila[f];
        if(f == t){
            f = -1;
            t = -1;
        }else{
            f = (f + 1) % MAX;
        }
        return val;
    }
}

void exbfila(){
    int i;
    if(vazia()){
        printf("a fila está vazia.\n");
    }else{
        printf("elementos da fila: ");
        for(i = f; i != t; i = (i + 1) % MAX){
            printf("%d", fila[i]);
        }
        printf("%d\n", fila[i]);
    }
}

int main(){
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);

    exbfila();

    int valrmv = desinf();
    if(valrmv != 1){
        printf("%d foi removido da fila.\n", valrmv);
    }
    exbfila();
}