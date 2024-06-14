#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct TpPont{
	char elemento[15];
	char prioridade;
	TpPont *ant, *prox;
};

struct TpDesc{
	TpPont *inicio, *fim;
	int qtde;
};

void inicializarDesc(TpDesc &desc){
	desc.inicio = desc.fim = NULL;
	desc.qtde = 0;
}

TpPont *NC(char elemento[],char prioridade){
	TpPont *nc = new TpPont;
	strcpy(nc->elemento, elemento);
	nc->ant = NULL;
	nc->prox = NULL;
	nc->prioridade = prioridade;
	return nc;
}

void inserir(TpDesc &desc, char elemento[15], char prioridade){
	TpPont *nc = NC(elemento, prioridade);
	TpPont *aux;
	
	if(desc.inicio == NULL){
		desc.inicio = desc.fim = nc;
	}else{
		if(prioridade < desc.inicio->prioridade){
			nc->prox = desc.inicio;
			nc->ant = desc.fim;
			desc.inicio = nc;
			desc.fim->prox = desc.inicio;
		}else if(prioridade >= desc.fim->prioridade){
			nc->ant = desc.fim;
			nc->prox = desc.inicio;
			desc.fim->prox = nc;
			desc.fim = nc;
			desc.inicio->ant = desc.fim;
		}else{
			aux = desc.inicio;
			while(aux->prox != NULL && aux->prox != desc.inicio && prioridade >= aux->prox->prioridade){
				aux = aux->prox;
			}
			nc->prox = aux->prox;
			nc->ant = aux;
			aux->prox->ant = nc;
			aux->prox = nc;
		}
	}
	desc.qtde++;
}

void retirar(TpDesc &desc){
	TpPont *aux = desc.inicio;
	
	desc.inicio = desc.inicio->prox;
	desc.inicio->ant = desc.fim;
	desc.fim->prox = desc.inicio;
	delete(aux);
	desc.qtde--;
}

void imprimir(TpDesc desc){
	TpPont *aux = desc.inicio;
	while(aux->prox != NULL && aux->prox != desc.inicio){
		printf("%s - %c ", aux->elemento, aux->prioridade);
		aux = aux->prox;
	}
	printf("%s - %c ", aux->elemento, aux->prioridade);
	getch();
}

int main(){
    TpDesc desc;
    inicializarDesc(desc);

    int opcao;
    char elemento[15];
    char prioridade;

    do {
        system("cls"); // Limpa a tela
        printf("Menu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Retirar elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao) {
            case 1:
                printf("Digite o elemento: ");
                gets(elemento);
                printf("Digite a prioridade: ");
                scanf(" %c", &prioridade); // O espaço antes do %c é para ignorar o caractere de nova linha
                inserir(desc, elemento, prioridade);
                break;
            case 2:
                retirar(desc);
                break;
            case 3:
                imprimir(desc);
                getch(); // Espera uma tecla para continuar
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                getch(); // Espera uma tecla para continuar
                break;
        }
    } while(opcao != 4);

    return 0;
}
