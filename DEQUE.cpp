#include <stdio.h>
#include <stdlib.h>

struct TpPont {
    char Elem;
    TpPont *ant, *prox;
};

struct TpDEQUE {
    TpPont *Cab, *Cauda;
};

void inicializarDeque(TpDEQUE &deque) {
    deque.Cab = NULL;
    deque.Cauda = NULL;
}

TpPont* NC_Pont(char Elem) {
    TpPont *novaCaixa = new TpPont;
    novaCaixa->Elem = Elem;
    novaCaixa->ant = NULL;
    novaCaixa->prox = NULL;
    return novaCaixa;
}

char dequeVazio(TpDEQUE deque) {
    return deque.Cab == NULL;
}

void inserirInicio(char Elem, TpDEQUE &deque) {
    TpPont *novaCaixa = NC_Pont(Elem);

    if (deque.Cab == NULL) {
        deque.Cab = deque.Cauda = novaCaixa;
    } else {
        novaCaixa->prox = deque.Cab;
        deque.Cab->ant = novaCaixa;
        deque.Cab = novaCaixa;
    }
}

void inserirFim(char Elem, TpDEQUE &deque) {
    TpPont *novaCaixa = NC_Pont(Elem);

    if (deque.Cauda == NULL) {
        deque.Cab = deque.Cauda = novaCaixa;
    } else {
        novaCaixa->ant = deque.Cauda;
        deque.Cauda->prox = novaCaixa;
        deque.Cauda = novaCaixa;
    }
}

char retirarFim(TpDEQUE &deque) {
    if (deque.Cauda) {
        TpPont *aux = deque.Cauda;
        char elem = deque.Cauda->Elem;

        deque.Cauda = deque.Cauda->ant;
        if (deque.Cauda == NULL) {
            deque.Cab = NULL;
        } else {
            deque.Cauda->prox = NULL;
        }
        delete(aux);
        return elem;
    }
    return '\0'; // null
}

char retirarInicio(TpDEQUE &deque) {
    if (deque.Cab) {
        char elem = deque.Cab->Elem;
        TpPont *aux = deque.Cab;
        deque.Cab = deque.Cab->prox;
        if (deque.Cab == NULL) {
            deque.Cauda = NULL;
        } else {
            deque.Cab->ant = NULL;
        }
        delete(aux);
        return elem;
    }
    return '\0'; // null
}

void exibirCabecaParaCauda(TpDEQUE deque) {
    TpPont *atual = deque.Cab;
    while (atual != NULL) {
        printf("%c ", atual->Elem);
        atual = atual->prox;
    }
    printf("\n");
}

void exibirCaudaParaCabeca(TpDEQUE deque) {
    TpPont *atual = deque.Cauda;
    while (atual != NULL) {
        printf("%c ", atual->Elem);
        atual = atual->ant;
    }
    printf("\n");
}

int main() {
    TpDEQUE deque;
    inicializarDeque(deque);

    inserirInicio('A', deque);
    inserirInicio('B', deque);
    inserirInicio('C', deque);

    printf("\nDeque apos insercao no inicio: ");
    exibirCabecaParaCauda(deque); 

    inserirFim('X', deque);
    inserirFim('Y', deque);
    inserirFim('Z', deque);

    printf("\nDeque apos insercao no fim: ");
    exibirCabecaParaCauda(deque); 

    retirarFim(deque);
    printf("\nDeque apos remocao do fim: ");
    exibirCabecaParaCauda(deque);

    retirarInicio(deque);
    printf("\nDeque apos remocao do inicio: ");
    exibirCabecaParaCauda(deque); 
    
    printf("\nDeque exibido da cauda para a cabeca: ");
    exibirCaudaParaCabeca(deque); 

    return 0;
}

