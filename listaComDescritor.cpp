#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct TpPont{
	char Elemento;
	TpPont *prox;
};

struct TpDesc{
	TpPont *inicio;
	TpPont *fim;
	int qtde;
	// pode ter a  qtde de elementos, nome da lista, saída para terceira lista, etc.
};

void inicializaDesc(TpDesc &desc){
	desc.inicio = NULL;
	desc.fim = NULL;
	desc.qtde = 0;
}

// descritor é um registro, struct. Passado por refrência, para a variável ser atualizada
void inserirOrdenado(TpDesc &desc){
	TpPont *caixa, *ant, *atual;
	char Elem;
	printf("\nElemento: ");
	Elem = getche();
	while(Elem != 27){
		// criar caixa
		caixa = new TpPont;
		caixa -> Elemento = Elem;
		caixa -> prox = NULL;
		desc.qtde++; //inicializar antes
		// se estiver vazia
		if(desc.inicio == NULL){
			desc.inicio = desc.fim = caixa;
		}else{
			// inserir antes do primeiro
			if(caixa -> Elemento <= desc.inicio -> Elemento){
				caixa -> prox = desc.inicio;
				desc.inicio = caixa;
			}else{
				// inserir no fim
				if(caixa -> Elemento >= desc.fim -> Elemento){
					desc.fim -> prox = caixa; // coloca no fim
					desc.fim = caixa; // atualiza o fim
				}else{
					// entre elementos
					// busca posição ideal
					ant = desc.inicio;
					atual = desc.inicio -> prox;
					while(atual != NULL && atual -> Elemento <= Elem){
						ant = atual;
						atual = atual -> prox;
					}
					caixa -> prox = atual;
					ant -> prox = caixa;
				}
				
			}
		}
		printf("\nElemento: ");
		Elem = getche();
	}
}

void excluirElemento(TpDesc &desc) {
    TpPont *atual = desc.inicio;
    TpPont *ant = NULL;
    
    char elemento;
	printf("\nElemento para excluir: ");
	elemento = getche();

    // Procurar o elemento na lista
    while (atual != NULL && atual->Elemento != elemento) {
        ant = atual;
        atual = atual->prox;
    }

    // Se o elemento não foi encontrado
    if (atual == NULL) {
        printf("\nElemento '%c' não encontrado!", elemento);
        return;
    }

    // Ajustar os ponteiros e remover o elemento
    if (atual == desc.inicio) { // se é o primeiro elemento
        desc.inicio = atual->prox;
        if (desc.inicio == NULL) { // Se a lista ficou vazia
            desc.fim = NULL;
        }
    } else {
        ant->prox = atual->prox;
        // se for o último
        if (atual == desc.fim) {
            desc.fim = ant;
        }
    }

    delete(atual);
    desc.qtde--;
    printf("\nElemento '%c' excluido com sucesso!", elemento);
    getch();
}

void exibirEstrutura(TpDesc desc) {
    TpPont *atual = desc.inicio;
    printf("\n### Estrutura da Lista ###\n");
    printf("Quantidade de elementos: %d\n", desc.qtde);
    printf("\nElementos: ");
    while (atual != NULL) {
        printf("%c ", atual->Elemento);
        atual = atual->prox;
    }
    if (desc.inicio != NULL) {
    	printf("\nInicio: %c\n", desc.inicio->Elemento);
	} else {
	    printf("\nInicio: NULL\n");
	}
    if (desc.fim != NULL) {
    	printf("\nFim: %c\n", desc.fim->Elemento);
	} else {
	    printf("\nFim: NULL\n");
	}
}

int main(void){
	TpDesc descritor;
	inicializaDesc(descritor);
	inserirOrdenado(descritor);
	exibirEstrutura(descritor);
	excluirElemento(descritor);
	exibirEstrutura(descritor);
}
