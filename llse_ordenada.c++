#include <iostream>
using namespace std;
typedef int TInfo;
typedef struct no
{
    TInfo info;
    no *prox;
} TNo;
typedef TNo *PNo;
void criaLista(PNo *l)
{
    *l = NULL;
}

void insereInicioLista(PNo *l, TInfo dado)
{
     PNo p = (PNo)malloc(sizeof(TNo));
     p->info = dado;
     p->prox = *l;
     *l = p;
}
//Insere na Lista Ordenada
void insereListaOrdenada(PNo *l, TInfo dado)
{
    PNo aux, p = (PNo)malloc(sizeof(TNo));
    p->info = dado;
        if (*l == NULL || (*l)->info >= p->info) 
    {
        p->prox = *l;
        *l = p;
    }
    else {
     
        aux = *l;
        while (aux->prox != NULL && aux->prox->info < p->info) {
            aux = aux->prox;
        }
        p->prox = aux->prox;
        aux->prox = p;
    }
}


void insereFimLista(PNo *l, TInfo dado)
{
    PNo aux, p = (PNo)malloc(sizeof(TNo));
    p->info = dado;
    p->prox = NULL;
    if (*l == NULL)
    {
        *l = p;
    }
    else
    {
        aux = *l;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = p;
    }
}
int eliminaInicioLista(PNo *l, TInfo *dado)
{
    PNo p;
    if (*l)
    {
        p = *l;
        *dado = p->info;
        *l = p->prox;
        free(p);
        return 1;
    }
    else
    {
        return 0;
    }
}

//Elimina Um elemento da lista ordenada 
int eliminaListaOrdenada(PNo *l, TInfo dado)
{
    PNo anterior, p = (PNo)malloc(sizeof(TNo));
    anterior = NULL;
    p = *l;
    while (p != NULL && p->info != dado)
    {
        anterior = p;
        p = p->prox;
    }
    if(p == NULL)
    {
    return 0;
    }
    if(anterior == NULL)
    {
        *l = p->prox;
    }
    else
    {
        anterior->prox = p->prox;
    }

    free(p);

    return 1;    
}
int eliminaFimLista(PNo *l, TInfo *dado)
{
    PNo p, ult, penult;
    if (*l)
    {
        p = *l;
        ult = p->prox;
        penult = p;
        while (ult->prox != NULL)
        {
            penult = ult;
            ult = ult->prox;
        }
        *dado = ult->info;
        penult->prox = NULL;
        free(ult);
        return 1;
    }
    else
    {
        return 0;
    }
}
int contaNosLista(PNo l)
{
    PNo p;
    int n;
    n = 0;
    p = l;
    while (p)
    {
        n++;
        p = p->prox;
    }
    return n;
}
void mostraLista(PNo l)
{
    cout << "Lista (" << contaNosLista(l) << "):";
    while (l)
    {
        cout << " " << l->info;
        l = l->prox;
    }
}
int mostraUltimoLista(PNo l, TInfo *dado)
{
    PNo p;
    if (l)
    {
        p = l;
        while (p->prox)
        {
            p = p->prox;
        }
        *dado = p->info;
        return 1;
    }
    else
    {
        return 0;
    }
}

int mostraEnesimoLista(PNo l, int n, TInfo *dado)
{
    PNo p;
    int i;
    p = l;
    i = 1;
    while (p && (i < n))
    {
        p = p->prox;
        i++;
    }
    if (p)
    {
        *dado = p->info;
        return 1;
    }
    else
    {
        return 0;
    }
}
void terminaLista(PNo *l)
{
    while (eliminaListaOrdenada(l, 8))
        ;
}

int main()
{
 PNo lista;
 TInfo valor;
 cout << endl << "Criando Lista...";
 criaLista(&lista);
 cout << endl << "Criado!" << endl;
 cout << endl << "Inserindo Lista...";
 insereListaOrdenada(&lista, 1);
 insereListaOrdenada(&lista, 4);
 insereListaOrdenada(&lista, 2);
 insereListaOrdenada(&lista, 8);
 insereListaOrdenada(&lista, 16);
 cout << endl << "Inserido!" << endl;
 cout << endl << "Mostrando Lista..." << endl;
 mostraLista(lista);
 cout << endl << "Mostrado!" << endl;
 cout << endl << "Excluindo Lista..." << endl;
 if (eliminaListaOrdenada(&lista, 8))
 {
 cout << "Valor: " << 8;
 }
 else
 {
 cout << "Lista Vazia!";
 }
 cout << endl << "Excluido!" << endl;
 cout << endl << "Mostrando Lista..." << endl;
 mostraLista(lista);
 cout << endl << "Mostrado!" << endl;
 cout << endl << "Mostrando Ultimo Lista..." << endl;
 if (mostraUltimoLista(lista, &valor))
 {
 cout << "Valor: " << valor;
 }
 else
 {
 cout << "Lista Vazia!";
 }
 cout << endl << "Mostrado!" << endl;
 cout << endl << "Mostrando Segundo Lista..." << endl;
 if (mostraEnesimoLista(lista, 2, &valor))
 {
 cout << "Valor: " << valor;
 }
 else
 {
 cout << "Nao Encontrado!";
 }
 cout << endl << "Mostrado!" << endl;
 cout << endl << "Terminando Lista...";
 terminaLista(&lista);
 cout << endl << "Terminado!" << endl;
 cout << endl << "Mostrando Lista..." << endl;
 mostraLista(lista);
 cout << endl << "Mostrado!" << endl;
 cout << endl << "*****" << endl;
 return 0;
}
