#include <stdio.h>
#include <stdlib.h>
struct lista
{
    float info;
    struct lista * prox;
};
typedef struct lista Lista;
struct pilha
{
    Lista * prim;
};
typedef struct pilha Pilha;

Pilha * cria_pilha();
int pilha_vazia(Pilha *p);
void push_pilha(Pilha *p, float valor);
float pop_pilha(Pilha *p);
void libera_pilha(Pilha * p);
int main()
{
    
    return 0;
}
Pilha * cria_pilha()
{
    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}
int pilha_vazia(Pilha *p)
{
    return p->prim == NULL;
}
void push_pilha(Pilha *p, float valor)
{
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = p->prim;
    p->prim = novo;
}
float pop_pilha(Pilha *p)
{
    Lista * tira;
    float valor;
    if(pilha_vazia(p))
    {
        printf("PILHA VAZIA\n");
        exit(1);
    }
    tira = p->prim;
    valor = tira->info;
    p->prim = tira->prox;
    free(tira);
    return valor;
}
void libera_pilha(Pilha * p)
{
    Lista *q;
    while(q!=NULL)
    {
        Lista *t;
        t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}