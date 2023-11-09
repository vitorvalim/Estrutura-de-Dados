#include <iostream>
using namespace std;
typedef char TInfo;
typedef struct no
{
    TInfo info;
    no *esq, *dir;
} TNo;
typedef TNo *PNo;
typedef PNo TArv;
void inicia(TArv *a)
{
    *a = NULL;
}
void imprime(TArv a, int n)
{
    int i;
    if (a != NULL)
    {
        imprime(a->dir, n + 5);
        for (i = 0; i < n; i++)
        {
            cout << " ";
        }
        cout << a->info << endl;
        imprime(a->esq, n + 5);
    }
}
void mostra(TArv a)
{
    imprime(a, 5);
    cout << endl
         << "--------------------" << endl;
    getchar();
}
void termina(TArv *a)
{
    if (*a != NULL)
    {
        termina(&(*a)->esq);
        termina(&(*a)->dir);
        free(*a);
        *a = NULL;
    }
}
void insere(TArv *a, TInfo x)
{
    TArv *aux = (TArv *)malloc(sizeof(TNo));
    if(a == NULL)
    {
        (*a)->info = x;
        (*a)->esq = (*a)->dir = NULL;  
    }
    else if (x < (*a)->info)
    {
        (*a)->esq = insere((*a)->esq,x);
    }
    else if (x > (*a)->info)
    {
        (*a)->dir = insere((*a)->dir,x);        
    }
} 
TArv busca(TArv a, TInfo x)
{

}
TArv pegamaior(TArv *a)
{
    TArv aux;
    if ((*a)->dir == NULL)
    {
        aux = *a;
        *a = (*a)->esq;
        return aux;
    }
    else
    {
        return pegamaior(&(*a)->dir);
    }
}
int remove(TArv *a, TInfo x)
{
    TArv aux;
    if (*a == NULL)
    {
        return 0;
    }
    else
    {
        if (x == (*a)->info)
        {
            aux = *a;
            if ((*a)->esq == NULL)
            {
                *a = (*a)->dir;
            }
            else
            {
                if ((*a)->dir == NULL)
                {
                    *a = (*a)->esq;
                }
                else
                {
                    aux = pegamaior(&(*a)->esq);
                    (*a)->info = aux->info;
                }
            }
            free(aux);
            return 1;
        }
        else
        {
            if (x < (*a)->info)
            {
                return remove(&(*a)->esq, x);
            }
            else
            {
                if (x > (*a)->info)
                {
                    return remove(&(*a)->dir, x);
                }
            }
        }
    }
    return 0;
}
int main() {
TArv arv, aux;
inicia(&arv);
mostra(arv);
insere(&arv, 'd');
mostra(arv);
insere(&arv, 'b');
mostra(arv);
cout << "valor a?" << endl;
aux = busca(arv, 'a');
if (aux) {
cout << "valor encontrado: " << aux->info << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
insere(&arv, 'a');
mostra(arv);
cout << "valor a?" << endl;
aux = busca(arv, 'a');
if (aux) {
cout << "valor encontrado: " << aux->info << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
insere(&arv, 'c');
mostra(arv);
insere(&arv, 'f');
mostra(arv);
cout << "valor e?" << endl;
aux = busca(arv, 'e');
if (aux) {
cout << "valor encontrado: " << aux->info << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
insere(&arv, 'e');
mostra(arv);
cout << "valor e?" << endl;
aux = busca(arv, 'e');
if (aux) {
cout << "valor encontrado: " << aux->info << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
insere(&arv, 'g');
mostra(arv);
cout << "remove x" << endl;
if (remove(&arv, 'x')) {
cout << "valor removido." << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
mostra(arv);
cout << "remove d" << endl;
if (remove(&arv, 'd')) {
cout << "valor removido." << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
mostra(arv);
cout << "remove e" << endl;
if (remove(&arv, 'e')) {
cout << "valor removido." << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
mostra(arv);
cout << "remove b" << endl;
if (remove(&arv, 'b')) {
cout << "valor removido." << endl << endl;
} else {
cout << "valor nao encontrado." << endl << endl;
}
cout << "--------------------" << endl;
getchar();
mostra(arv);
termina(&arv);
mostra(arv);
return 0;
}
