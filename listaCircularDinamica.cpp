#include <stdio.h>
#include <stdlib.h>

struct TpListaCircularDinamica{
	char Elemento;
	TpListaCircularDinamica *prox;
};

TpListaCircularDinamica *novaCaixa(char elemento){
	TpListaCircularDinamica *caixa = new TpListaCircularDinamica;
	caixa -> Elemento = elemento;
	caixa -> prox = NULL;
	return caixa;
}

TpListaCircularDinamica *inserir(TpListaCircularDinamica *Cab, char elemento){
	TpListaCircularDinamica *novaC, *aux;
	novaC = novaCaixa(elemento);
	if(Cab == NULL){
		Cab = novaC;
	}else{
		aux = Cab;
		while(aux -> prox != NULL && aux -> prox != Cab){
			aux = aux -> prox;
		}
		aux -> prox = novaC;
		novaC -> prox = Cab;
	}
	return Cab;
}

/*
fila circular: 
void Retirar(TpFila &F){
	char elemento;
	elemento = F.FILA[F.INICIO++];
	if(F.INICIO == MAXFILA-1)
		F.INICIO=0;
	F.CONT--;
	return elemento;
}

*/

TpListaCircularDinamica *retirar(TpListaCircularDinamica *Cab, char elemento){
	TpListaCircularDinamica *atual, *anterior;
	if(Cab != NULL){
		if(Cab -> Elemento == elemento){
			atual = Cab;
			Cab = Cab -> prox;
			delete(atual);
		}else{
			
		}
	}
}
