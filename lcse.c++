#include <iostream>
using namespace std;
typedef char TInfo;
typedef struct no
{
    TInfo info;
    no *prox;
} TNo;
typedef TNo *PNo;
void criaListaC(PNo *l)
{
    *l = NULL;
}
void insereListaC(PNo *l, TInfo dado)
{
    PNo p, q;
    p = (PNo)malloc(sizeof(TNo));
    p->info = dado;
    if (*l)
    {
        p->prox = *l;
        q = *l;
        while (q->prox != *l)
        {
            q = q->prox;
        }
        q->prox = p;
    }
    else
    {
        p->prox = p;
    }
    *l = p;
}
int eliminaListaC(PNo *l, TInfo *dado)
{
    PNo p, q;
    if (*l)
    {
        p = *l;
        if (p->prox == p)
        {
            *dado = p->info;
            p = NULL;
            *l = p;
        }
        else
        {
            while(p->prox != p && p->prox != NULL)
            {

            }
        }
    return 1;
    }
    else
    {
    return 0;
    }
}
int contaNosListaC(PNo l)
{
    PNo p;
    int n = 0;
    if (l)
    {
        p = l;
        do
        {
            n++;
            p = p->prox;
        } while (p != l);
    }
    return n;
}
void mostraListaC(PNo l)
{
    PNo p;
    cout << "Lista (" << contaNosListaC(l) << "):";
    if (l)
    {
        p = l;
        do
        {
            cout << " " << p->info;
            p = p->prox;
        } while (p != l);
    }
}
void terminaListaC(PNo *l)
{
    TInfo v;
    while (eliminaListaC(l, &v))
        ;
}
int main() {
    PNo lista;
    TInfo valor;
    cout << endl << "Criando Lista...";
    criaListaC(&lista);
    cout << endl << "Criado!" << endl;
    cout << endl << "Inserindo Lista...";
    insereListaC(&lista, 'A');
    insereListaC(&lista, 'B');
    insereListaC(&lista, 'C');
    insereListaC(&lista, 'D');
    cout << endl << "Inserido!" << endl;
    cout << endl << "Mostrando Lista..." << endl;
    mostraListaC(lista);
    cout << endl << "Mostrado!" << endl;
    cout << endl << "Excluindo Lista..." << endl;
    if (eliminaListaC(&lista, &valor)) {
    cout << "Valor: " << valor;
    } else {
    cout << "Lista Vazia!";
    }
    cout << endl << "Excluido!" << endl;
    cout << endl << "Mostrando Lista..." << endl;
    mostraListaC(lista);
    cout << endl << "Mostrado!" << endl;
    cout << endl << "Terminando Lista...";
    terminaListaC(&lista);
    cout << endl << "Terminado!" << endl;
    cout << endl << "Mostrando Lista..." << endl;
    mostraListaC(lista);
    cout << endl << "Mostrado!" << endl;
    cout << endl << "*****" << endl;
return 0;
}
