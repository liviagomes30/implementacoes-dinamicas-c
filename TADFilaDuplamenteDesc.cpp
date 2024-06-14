#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct TpPont{
	char info[30];
	TpPont *ant, *prox;
};

struct TpDesc{
	TpPont *inicio;
	TpPont *fim;
};

TpPont *NC(char info[]){
	TpPont *nc = new TpPont;
	strcpy(nc->info, info);
	nc->ant = NULL;
	nc->prox = NULL;
}

void inicializarDesc(TpDesc &desc){
	desc.inicio = NULL;
	desc.fim = NULL;
}

void inserirFila(char elemento[], TpDesc &desc){
	TpPont *nc = NC(elemento);
	if(desc.inicio == NULL){
		desc.inicio = desc.fim = nc;
	}else{
		nc->ant = desc.fim;
		desc.fim->prox = nc;
		desc.fim = nc;
	}
}

void retirarFila(TpDesc &desc){
	TpPont *aux = desc.inicio;
	desc.inicio = desc.inicio->prox;
	if(desc.inicio == NULL)
		desc.fim = NULL;
	else
		desc.inicio->ant = NULL;
	
	delete(aux);
}

char filaVazia(TpDesc &desc){
	return desc.inicio == NULL;
}

void imprimir(TpDesc desc){
	TpPont *aux = desc.inicio;
	while(aux != NULL){
		printf("%s ", aux->info);
		aux = aux->prox;
	}
}

int main() {
    TpDesc desc;
    inicializarDesc(desc);
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
                inserirFila(info, desc);
                break;
            case 2:
                retirarFila(desc);
                break;
            case 3:
                imprimir(desc);
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

