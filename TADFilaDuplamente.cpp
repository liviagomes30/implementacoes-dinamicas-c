#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct TpPont{
	char info[30];
	TpPont *ant, *prox;
};

TpPont *NC(char info[]){
	TpPont *nc = new TpPont;
	strcpy(nc->info, info);
	nc->ant = NULL;
	nc->prox = NULL;
}

TpPont *inserirNaFila(TpPont *Cab,char info[]){
	TpPont *novaC = NC(info);
	if(Cab == NULL){
		Cab = novaC;
	}else{
		TpPont *atual = Cab;
		while(atual->prox != NULL)
			atual = atual->prox;
		novaC->ant = atual;
		atual->prox = novaC;
	}
	return Cab;
}

TpPont *retirarFila(TpPont *Cab){
	TpPont *aux = Cab;
	Cab = Cab -> prox;
	Cab->ant = NULL;
	delete(aux);
	return Cab;
}

char filaVazia(TpPont *Cab){
	return Cab == NULL;
}

void imprimir(TpPont *Cab){
	if(Cab == NULL)
		return;
	printf("%s ", Cab->info);
	imprimir(Cab->prox);
}

int main() {
    TpPont *fila = NULL;
    char info[30];
    int opcao;

    do {
        system("cls");
        printf("1 - Inserir na fila\n");
        printf("2 - Retirar da fila\n");
        printf("3 - Imprimir fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Informe o elemento: ");
                gets(info);
                fila = inserirNaFila(fila, info);
                break;
            case 2:
                fila = retirarFila(fila);
                break;
            case 3:
                imprimir(fila);
                getch(); // Aguarda o usuário pressionar uma tecla
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                getch(); // Aguarda o usuário pressionar uma tecla
        }
    } while (opcao != 4);


    return 0;
}
