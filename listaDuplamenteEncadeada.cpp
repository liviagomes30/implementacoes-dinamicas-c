#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct TpPont{
	char Elemento;
	TpPont *ant, *prox;
};

TpPont *CriaCaixa(char Elem){
	TpPont *pCaixa = new TpPont;
	pCaixa -> Elemento = Elem;
	pCaixa -> prox = NULL;
	pCaixa -> ant = NULL;
	return pCaixa;
}

TpPont *inserirOrdenado(TpPont *CabLista, char elemento){
	TpPont *NovaCaixa = CriaCaixa(elemento);
	TpPont *atual;
	if(CabLista == NULL){
		CabLista = NovaCaixa;
	}else{
		if(CabLista -> Elemento >= NovaCaixa -> Elemento){
			NovaCaixa -> prox = CabLista;
			CabLista -> ant = NovaCaixa; // NovaCaixa -> prox -> ant = NovaCaixa;
			CabLista = NovaCaixa;
		}else{
			atual = CabLista;
			while(atual -> prox != NULL && atual -> Elemento <= elemento)
				atual = atual -> prox;
			if(elemento <= atual -> Elemento){
				NovaCaixa->prox = atual;
				NovaCaixa->ant = atual->ant;
				atual->ant = NovaCaixa;
				NovaCaixa -> ant -> prox = NovaCaixa;
			}else{
				atual -> prox = NovaCaixa;
				NovaCaixa -> ant = atual;
			}
		}
	}
	return CabLista;
}


void imprimirCrescenteIterativo(TpPont *CabLista){
	system("cls");
	printf("\n### Elementos da Lista Crescente Iterativo ###\n");
	if(CabLista == NULL){
		printf("\nLista Vazia!");
	}else{
		while(CabLista -> prox != NULL){
			printf("%c ", CabLista -> Elemento);
			CabLista = CabLista -> prox; 
		}
		printf("%c ", CabLista -> Elemento);
	}
	getch();
}

void imprimirDecrescenteIterativo(TpPont *CabLista){
	system("cls");
	printf("\n### Elementos da Lista Decrescente Iterativo ###\n");
	if(CabLista == NULL){
		printf("\nLista Vazia!");
	}else{
		TpPont *atual = CabLista;
		// chegar no ultimo
		while(atual -> prox != NULL)
			atual = atual -> prox;
		while(atual != NULL){
			printf("%c ", atual -> Elemento);
			// voltando
			atual = atual -> ant;
		}
	}
	getch();
}

void imprimirCrescenteRecursivo(TpPont *CabLista){
	if(CabLista == NULL)
		return;
	printf("%c ", CabLista -> Elemento);
	imprimirCrescenteRecursivo(CabLista -> prox);
}

void imprimirDecrescenteRecursivo(TpPont *CabLista){
	if(CabLista == NULL)
		return;
	imprimirDecrescenteRecursivo(CabLista -> prox); // Chama a si mesma para percorrer at� o final da lista
	printf("%c ", CabLista -> Elemento); // Imprime o elemento ap�s retornar da recurs�o
}

TpPont* excluirElemento(TpPont *CabLista, char elemento) {
    TpPont *atual = CabLista;

    // Procurar o elemento na lista
    while(atual != NULL && atual->Elemento != elemento) {
        atual = atual->prox;
    }
    // Se o elemento n�o foi encontrado
    if (atual == NULL) {
        return CabLista;
    }
    // Se o elemento est� no in�cio da lista
    if (atual->ant == NULL) {
        CabLista = atual->prox; // liga cabe�a da lista ao segundo elemento
        if (CabLista != NULL) {
            CabLista->ant = NULL;
        }
    } else {
        atual->ant->prox = atual->prox;
        // Se o elemento n�o est� no final da lista
	    if (atual->prox != NULL) {
	        atual->prox->ant = atual->ant; // elemento da frente liga com o de tr�s
	    }
    }
    delete(atual);
    return CabLista;
}

// exclus�o de elemento qualquer
// exibir lista iterativo: crescente e decrescente
// exibir lista recursivo: crescente e decrescente

int main(void){
	TpPont *Lista = NULL;
	Lista = inserirOrdenado(Lista, 'A');
	Lista = inserirOrdenado(Lista, 'B');
	Lista = inserirOrdenado(Lista, 'C');
	Lista = excluirElemento(Lista,'B');
	imprimirCrescenteIterativo(Lista);
	imprimirDecrescenteIterativo(Lista);
	system("cls");
	printf("\n### Elementos da Lista Crescente Recursivo ###\n");
	imprimirCrescenteRecursivo(Lista);
	printf("\n### Elementos da Lista Decrescente Recursivo ###\n");
	imprimirDecrescenteRecursivo(Lista);
	return 0;
}
