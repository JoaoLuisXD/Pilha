#include <stdio.h>
#include <stdlib.h>

struct no_lista
{
    float info;
    struct no_lista * prox;
};
typedef struct no_lista No_lista;
typedef No_lista * NNo_lista;

struct pilha
{
    NNo_lista * topo;
};
typedef struct pilha Pilha;
typedef Pilha * PPilha;

PPilha cria_pilha();
int verifica_vazia(PPilha p);
void push_pilha(PPilha p, float valor);
float pop_pilha(PPilha p);
void imprime_pilha(PPilha p);
void libera_pilha(PPilha p);




int main()
{
    PPilha primeira_pilha = cria_pilha();
    push_pilha(primeira_pilha, 1);
    push_pilha(primeira_pilha, 2);
    push_pilha(primeira_pilha, 3);
    imprime_pilha(primeira_pilha);
    pop_pilha(primeira_pilha);
    imprime_pilha(primeira_pilha);
    libera_pilha(primeira_pilha);
    return 0;
}

PPilha cria_pilha()
{
    PPilha p = (PPilha)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
int verifica_vazia(PPilha p)
{
    return p->topo == NULL;
}
void push_pilha(PPilha p, float valor)
{
    NNo_lista novo = (NNo_lista)malloc(sizeof(No_lista));
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
}
float pop_pilha(PPilha p)
{
    if(!verifica_vazia(p))
    {
        float valor;
        NNo_lista aux = p->topo;

        p->topo = aux->prox;
        valor = aux->info;
        free(aux);
        return valor;
    }
    else
    {
        printf("pilha vazia");
        exit(1);
    }
}
void imprime_pilha(PPilha p)
{
    NNo_lista percorre = p->topo;
    if(!verifica_vazia(percorre))
    {
        while(percorre != NULL)
        {
            printf("%f\n",percorre->info);
            percorre = percorre->prox;
        }
    }
    else
    {
        printf("pilha vazia");
        exit(1);
    }
}
void libera_pilha(PPilha p)
{
    NNo_lista percorre = p->topo;
    while(percorre != NULL)
    {
        NNo_lista aux = percorre->prox;
        free(percorre);
        percorre = aux;
    }
    free(p);
}