#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct TpPont{
	char elemento[15];
	char prioridade;
	TpPont *prox;
	TpPont *ant;
};

struct TpDesc{
	TpPont *inicio, *fim;
};

void inicializarDesc(TpDesc &desc){
	desc.inicio = desc.fim = NULL;
}

TpPont *NC(char elemento[],char prioridade){
	TpPont *nc = new TpPont;
	strcpy(nc->elemento,elemento);
	nc->prioridade = prioridade;
	nc->prox = NULL;
	nc->ant = NULL;
	return nc;
}

void inserir(TpDesc &desc, char elemento[], char prioridade) {
    TpPont *nc = NC(elemento, prioridade);
    if (desc.inicio == NULL) {
        desc.inicio = desc.fim = nc;
    } else {
        if (desc.inicio->prioridade > nc->prioridade) {
            nc->prox = desc.inicio;
            desc.inicio->ant = nc;
            desc.inicio = nc;
        } else if (desc.fim->prioridade <= nc->prioridade) {
            nc->ant = desc.fim;
			desc.fim->prox = nc;
            desc.fim = nc;
        } else {
            TpPont *aux = desc.inicio;
            
            while (aux->prox != NULL && aux->prox->prioridade <= nc->prioridade) {
                aux = aux->prox;
            }
            nc->prox = aux->prox;
            nc->ant = aux;
            aux->prox->ant = nc;
            aux->prox = nc;
        }
    }
}

void retirar(TpDesc &desc){
	TpPont *aux = desc.inicio;
	desc.inicio = desc.inicio->prox;
	if(desc.inicio == NULL)
		desc.fim = NULL;
	delete(aux);
}

void imprimir(TpDesc desc){
	while(desc.inicio != NULL){
		printf("\t%s - %c", desc.inicio->elemento, desc.inicio->prioridade);
		desc.inicio = desc.inicio->prox;
	}
	getch();
}

void menu() {
    TpDesc desc;
    inicializarDesc(desc);

    int escolha;
    char elemento[15];
    char prioridade;

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
                printf("Digite a prioridade do elemento: \n");
                scanf("%c", &prioridade);
                getchar(); // Limpa o caractere de nova linha do buffer
                inserir(desc, elemento, prioridade);
                break;

            case 2:
                printf("Excluindo elemento do inicio! \n");
                retirar(desc);
                break;

            case 3:
                printf("Fila atual:\n");
                imprimir(desc);
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
