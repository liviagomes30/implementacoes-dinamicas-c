#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct TpPont{
	char info[15];
	TpPont *prox;
};

struct TpDesc{
	TpPont *Inicio;
	TpPont *Fim;
	int qtde;
};

void inicializarDesc(TpDesc &desc){
	desc.Fim = NULL;
	desc.Inicio = NULL;
	desc.qtde = 0;
}

TpPont *NC(char info[]){
	TpPont *nc = new TpPont;
	strcpy(nc->info, info);
	nc->prox = NULL;
	return nc;
}

void inserir(TpDesc &desc, char elemento[]){
	TpPont *nc = NC(elemento);
	if(desc.Inicio == NULL)
		desc.Fim = desc.Inicio = nc;
	else{
		desc.Fim->prox = nc;
		desc.Fim = nc;
	}
	desc.qtde++;
	if(desc.Fim == NULL)
		desc.Inicio = NULL;
}

void retirar(TpDesc &desc){
	TpPont *excluir = desc.Inicio;
	desc.Inicio = desc.Inicio->prox;
	delete(excluir);
	desc.qtde--;
}

void imprimir(TpDesc desc){
	while(desc.Inicio != NULL){
		printf("%s ", desc.Inicio->info);
		desc.Inicio = desc.Inicio->prox;
	}
	getch();
}

char isVazia(TpDesc desc){
	return desc.qtde == 0;
}

void menu() {
    TpDesc desc;
    inicializarDesc(desc);

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
        fflush(stdin); // Limpa o buffer do stdin

        switch (escolha) {
            case 1:
                printf("Digite o elemento a inserir: \n");
                gets(elemento);
                inserir(desc, elemento);
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
