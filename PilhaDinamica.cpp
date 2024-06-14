#include <stdio.h>
#include <stdlib.h>


struct TpPilhaDinamica{
	char Elemento;
	TpPilhaDinamica *prox;
};

TpPilhaDinamica *inicializa(TpPilhaDinamica *Cab){
	return Cab = NULL;
}

TpPilhaDinamica *novaCaixa(char elemento){
	TpPilhaDinamica *caixa = new TpPilhaDinamica;
	caixa -> Elemento = elemento;
	caixa -> prox = NULL;
	return caixa;
}

TpPilhaDinamica *inserir(TpPilhaDinamica *Cab, char elemento){
	TpPilhaDinamica *novaC, *aux;
	
	novaC = novaCaixa(elemento);
	if(Cab == NULL){
		Cab = novaC;
	}else{
		novaC -> prox = Cab;
		Cab = novaC;
	}
	return Cab;
}

TpPilhaDinamica *retirar(TpPilhaDinamica *Cab){
	TpPilhaDinamica *aux = Cab;
	Cab = Cab -> prox;
	delete(aux);
	return Cab;
}

void exibir(TpPilhaDinamica *Cab){
	while(Cab -> prox != NULL){
		printf("%c ", Cab -> Elemento);
		Cab = Cab -> prox; 
	}
	printf("%c ", Cab -> Elemento);
}

char elementoTopo(TpPilhaDinamica *Cab){
	return Cab -> Elemento;
}

int main() {
    TpPilhaDinamica *Pilha = inicializa(Pilha);
    
    Pilha = inserir(Pilha, 'A');
    Pilha = inserir(Pilha, 'B');
    Pilha = inserir(Pilha, 'C');
    
    printf("Elemento do topo: %c\n", elementoTopo(Pilha));
    
    printf("Exibindo a pilha: ");
    exibir(Pilha);
    printf("\n");
    
    Pilha = retirar(Pilha);
    
    printf("Exibindo a pilha apos a retirada do elemento do topo: ");
    exibir(Pilha);
    printf("\n");
    printf("Elemento do topo: %c\n", elementoTopo(Pilha));
    
    return 0;
}
