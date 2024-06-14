#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


struct TpPont{
	char elemento[15];
	TpPont *prox, *ant;
};

TpPont *NC(char elemento[]){
	TpPont *nc = new TpPont;
	strcpy(nc->elemento, elemento);
	nc->ant = NULL;
	nc->prox = NULL;
	return nc;
}


TpPont *inserir(TpPont *Cab, char elemento[]){
	TpPont *nc = NC(elemento);
	if(Cab == NULL){
		Cab = nc;
		// Lista vazia, novo nó aponta para si mesmo
        Cab->prox = Cab;
        Cab->ant = Cab;
	}
	else{
		TpPont *aux = Cab;
		while(aux->prox != NULL && aux->prox != Cab)
			aux = aux->prox;
		
		nc->prox = Cab;
		nc->ant = aux;
		aux->prox = nc;
		Cab->ant = nc;
	}
	return Cab;
}

TpPont *retirar(TpPont *Cab, char elemento[]){
	TpPont *atual = Cab;
	
	do{
		if(strcmp(atual->elemento, elemento) == 0){
			if(atual == Cab && atual->prox == Cab){
				// ultimo elemento
				delete(atual);
				return NULL;
			}
			atual->ant->prox = atual->prox;
			atual->prox->ant = atual->ant;
			if(atual == Cab)
				Cab = atual->prox;
			delete(atual);
			return Cab;
		}
		atual = atual->prox;
	}while(atual != Cab);
	return Cab;
}

void imprimir(TpPont *Cab){
	TpPont *aux = Cab;
	while(aux->prox != NULL && aux->prox != Cab){
		printf("%s ", aux->elemento);
		aux = aux->prox;
	}
	printf("%s ", aux->elemento);
	getch();
}

void menu() {
    TpPont *Cab = NULL;
    int escolha;
    char elemento[15];

    do {
    	system("cls");
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Excluir elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar(); // Limpa o caractere de nova linha do buffer

        switch (escolha) {
            case 1:
                printf("Digite o elemento a inserir: \n");
                gets(elemento);
                Cab = inserir(Cab, elemento);
                break;

            case 2:
                printf("Digite o elemento a excluir: \n");
                gets(elemento);
                Cab = retirar(Cab, elemento);
                break;

            case 3:
                printf("Lista atual:\n");
                imprimir(Cab);
                getch();
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 4);
}

int main() {
    menu();
    return 0;
}
