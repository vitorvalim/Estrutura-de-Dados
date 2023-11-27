#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char TInfo;
typedef struct no {
	TInfo info;
	no *prox;
} TNo;
typedef TNo *PNo;

void criaLista(PNo *l) {
	*l = NULL;
}

void inicializacao(PNo *l) {
	*l = NULL;
}
void insercaoFim(PNo *l, TInfo dado) {
	PNo p, q;
	p = (PNo)malloc(sizeof(TNo));
	p->info = dado;
	p->prox = NULL;
	if (*l) {
		q = *l;
		while (q->prox) {
			q = q->prox;
		}
		q->prox = p;
	} else {
		*l = p;
	}
}
int RemocaoTopoPilha(PNo *l, TInfo *dado) {
	PNo p, q;
	if (*l) {
		p = *l;
		q = NULL;
		while (p->prox) {
			q = p;
			p = p->prox;
		}
		if (q) {
			q->prox = NULL;
		} else {
			*l = NULL;
		}
		*dado = p->info;
		free(p);
		return 1;
	} else {
		return 0;
	}
}
int RemocaoInicioFila(PNo *l, TInfo *dado)
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
void impressao(PNo l) {
	cout << "Lista:";
	while (l) {
		cout << " " << l->info;
		l = l->prox;
	}
}

void Finalizacao(PNo *l) {
	TInfo v;
	while (RemocaoInicioFila(l, &v));
}


int main() {

	PNo pilha,fila;
	TInfo valor;
//Inicialização
	cout << endl << "Criando Pilha...";
	inicializacao(&pilha);
	cout << endl << "Criado!" << endl;
	cout << endl << "Mostrando Pilha..." << endl;
//Inserindo elemntos na pilha
	cout << endl << "Inserindo Pilha...";
	insercaoFim(&pilha, 'A');
	insercaoFim(&pilha, 'B');
	insercaoFim(&pilha, 'C');
	insercaoFim(&pilha, 'D');
	cout << endl << "Inserido!" << endl;
	cout << endl << "Mostrando Pilha..." << endl;
	impressao(pilha);
	cout << endl << "Mostrado!" << endl;
//Remoção do topo da pilha
	cout << endl << "Excluindo Pilha..." << endl;
	if (RemocaoTopoPilha(&pilha, &valor)) {
		cout << "Valor: " << valor;
	} else {
		cout << "Lista Vazia!";
	}
	cout << endl << "Excluido!" << endl;
//Inicialização da Fila	
	cout << endl << "Criando Fila...";
    inicializacao(&fila);
    cout << endl << "Criado!" << endl;
	cout << endl << "Inserindo Fila..." << endl;
//Inserindo valores na Fila
	insercaoFim(&fila, 'A');
	insercaoFim(&fila, 'B');
	insercaoFim(&fila, 'C');
	insercaoFim(&fila, 'D');
	impressao(fila);
//Remoção da fila, do primeiro a entrar.	
	cout << endl << "Excluindo Fila..." << endl;
	if (RemocaoInicioFila(&fila, &valor)) {
		cout << "Valor: " << valor;
	} else {
		cout << "Fila Vazia!";
	}
	cout << endl << "Excluido!" << endl;
//Mostra após Excluido
	cout << endl << "Mostrando Pilha..." << endl;
	impressao(pilha);
	cout << endl << "Mostrado!" << endl;

// Finalização da fila e da pilha
	cout << endl << "Terminando Pilha...";
	Finalizacao(&pilha);
	cout << endl << "Terminando Fila...";
	Finalizacao(&fila);
	cout << endl << "Terminado!" << endl;
	
	return 0;

}

