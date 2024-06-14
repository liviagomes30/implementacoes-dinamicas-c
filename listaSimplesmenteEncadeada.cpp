#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct TpPonteiro{
	char Elemento;
	TpPonteiro *prox;
};

TpPonteiro *CriaCaixa(char Elem){
	TpPonteiro *pCaixa = new TpPonteiro;
	pCaixa -> Elemento = Elem;
	pCaixa -> prox = NULL;
	return pCaixa;
}

// inserindo tipo pilha
TpPonteiro *InserirNoInicio(TpPonteiro *CabLista){ // * passando por valor (a lista passada por parâmetro vai ser uma cópia)
	char Elemento;
	TpPonteiro *NovaCaixa;
	system("cls");
	printf("\n### Inserir no Inicio ###\n");
	printf("\nElemento: ");
	Elemento = getche();
	while(Elemento != 27){
		NovaCaixa = CriaCaixa(Elemento); // NovaCaixa apontando para a caixa nova
		if(CabLista == NULL){ // vazia
			// ligar cabeça em quem acabou de ser criado (endereço no qual NovaCaixa aponta)
			CabLista = NovaCaixa; // lista aponta para NovaCaixa aponta
		}else{
			NovaCaixa -> prox = CabLista; // elemento novo passa a apontar para o início da lista
			CabLista = NovaCaixa; // início da lista passa a apontar para o elemento novo
		}
		printf("\nElemento: ");
		Elemento = getche();
	}
	return CabLista; // sabe endereço do primeiro elemento da lista (último colocado)
}

//inserção no final
TpPonteiro *InserirNoFinal(TpPonteiro *CabLista){ 
	char Elemento;
	TpPonteiro *NovaCaixa, *ptr;
	system("cls");
	printf("\n### Inserir no Final ###\n");
	printf("\nElemento: ");
	Elemento = getche();
	while(Elemento != 27){
		NovaCaixa = CriaCaixa(Elemento); 
		if(CabLista == NULL){ 
			// só mexe na cabeça da lista no primeiro elemento
			CabLista = NovaCaixa; 
		}else{
			ptr = CabLista;
			// para chegar no último elemento
			while(ptr -> prox != NULL){
				ptr = ptr -> prox;
			}
			ptr -> prox = NovaCaixa;
		}
		printf("\nElemento: ");
		Elemento = getche();
	}
	return CabLista; 
}

TpPonteiro *InserirOrdenado(TpPonteiro *CabLista){
	char elemento;
	TpPonteiro *NovaCaixa, *ptr, *ant = NULL;
	system("cls");
	printf("\n### Inserir Ordenado ###\n");
	printf("\nElemento: ");
	elemento = getche();
	while(elemento != 27){
		NovaCaixa = CriaCaixa(elemento);

		if(CabLista == NULL || elemento < CabLista -> Elemento){
			NovaCaixa -> prox = CabLista;
			CabLista = NovaCaixa;
		}else{
			ptr = CabLista;
			while(ptr != NULL  && ptr -> Elemento < elemento){
				ant = ptr;
				ptr = ptr -> prox;
			}

			ant -> prox = NovaCaixa;
			NovaCaixa -> prox = ptr;
		}
		printf("\nElemento: ");
		elemento = getche();
	}
	return CabLista;
}

TpPonteiro *inserirEntreElementos(TpPonteiro *CabLista){
	char elementoAnterior, elementoPosterior, novoElemento;
	TpPonteiro *NovaCaixa, *ptr = CabLista, *ant = NULL;
	system("cls");
	printf("\n### Inserir entre dois elementos ###\n");
	printf("\nElemento anterior: ");
	elementoAnterior = getche();
	printf("\nElemento posterior: ");
	elementoPosterior = getche();
	
	while(ptr != NULL && ptr -> Elemento != elementoAnterior){
		ant = ptr;
		ptr = ptr -> prox;
	}
	if(ptr == NULL){
		printf("\nElemento anterior nao encontrado!");
	}else{
		if(ptr -> prox == NULL || ptr -> prox -> Elemento != elementoPosterior){
			printf("\nElemento posterior nao encontrado na posicao correta!");
		}else{
			printf("\nNovo elemento:");
			novoElemento = getche();
			
			NovaCaixa = CriaCaixa(novoElemento);
			NovaCaixa -> prox = ptr -> prox; // O novo elemento aponta para o elemento posterior
			ptr -> prox = NovaCaixa; // O elemento anterior aponta para o novo elemento
		}
	}
	return CabLista;
}

void imprimirRecursivo(TpPonteiro *CabLista){
	if(CabLista == NULL){
		return;
	}
	printf("%c ", CabLista -> Elemento);
	imprimirRecursivo(CabLista -> prox);
}

void consultar(TpPonteiro *CabLista){
	char elemento;
	system("cls");
	printf("\n### Consultar elemento ###\n");
	printf("\nElemento: ");
	elemento = getche();
	while(CabLista != NULL && CabLista -> Elemento != elemento){
		CabLista = CabLista -> prox;
	}
	if(CabLista != NULL && CabLista -> Elemento == elemento){
		printf("\nO elemento %c foi encontrado na lista!", CabLista->Elemento);
	}else{
		printf("\nElemento nao encontrado!");
	}
	getch();
}

// podemos fazer movimentacoes, pois a lista está sendo passada como valor e não está sendo retornada na função
void imprimirLista(TpPonteiro *CabLista){
	system("cls");
	printf("\n### Elementos da Lista ###\n");
	if(CabLista == NULL){
		printf("\nLista Vazia!");
	}else{
		// parando no último elemento
		while(CabLista -> prox != NULL){ // pode ser somente "CabLista -> prox" || Passando por todos: CabLista != NULL (dessa forma não precisa exibir  último elemento no final)
			printf("%c ", CabLista -> Elemento);
			CabLista = CabLista -> prox; 
		}
		// exibindo ultimo elemento
		printf("%c ", CabLista -> Elemento);
	}
	getch();
}

TpPonteiro *Exclusao(TpPonteiro *CabLista){
	char elemento;
	TpPonteiro *aux, *anterior;
	system("cls");
	printf("\n### Exclusao ###\n");
	printf("\nElemento a excluir:");
	elemento = getche();
	while(CabLista != NULL && elemento != 27){
		if(elemento == CabLista -> Elemento){ // verificar se é o primeiro elemento
			aux = CabLista;
			CabLista = CabLista -> prox; // ligando no segundo elemento
			delete(aux); // deletando quem aux aponta
			printf("\nElemento [%c] deletado!\n", elemento);
		}else{
			// busca exaustiva
			aux = CabLista -> prox; // pulando primeiro elemento 
			anterior = CabLista; // para caso não entrar no while abaixo
			while(aux != NULL && aux -> Elemento != elemento){
				anterior = aux;
				aux = aux -> prox;
			}
			if(aux -> Elemento == elemento){
				anterior -> prox = aux -> prox;
				delete(aux);
				printf("\nElemento [%c] deletado!\n", elemento);
			}else{
				printf("\nElemento nao encontrado!");
			}
		}
		printf("\nElemento a excluir:");
		elemento = getche();
	}
	return CabLista;
}

void exclusaoIterativa(TpPonteiro *CabLista){
	TpPonteiro *aux;
	while(CabLista != NULL){
		aux = CabLista;
		CabLista = CabLista -> prox;
		delete(aux);
	}
	printf("\nLista excluida com sucesso!");
	getch();
}

void exclusaoRecursiva(TpPonteiro *CabLista){
	if(CabLista == NULL){
        return; 
    }
    
    exclusaoRecursiva(CabLista -> prox); // percorre at� o final
    delete(CabLista);
}

void exibirUltimo(TpPonteiro *CabLista){
	system("cls");
	printf("\n### Ultimo elemento ###\n");
	if(CabLista == NULL){
		printf("\nLista vazia!");
	}else{
		while(CabLista -> prox != NULL){
			CabLista = CabLista -> prox;
		}
		printf("%c ", CabLista -> Elemento);
	}
	getch();
}

void exibirPrimeiro(TpPonteiro *CabLista){
	system("cls");
	printf("\n### Primeiro elemento ###\n");
	if(CabLista == NULL){
		printf("\nLista vazia!");
	}else{
		printf("%c", CabLista -> Elemento);
	}
	getch();
}


void menu(TpPonteiro *Lista) {
    char opcao;
    
    do {
        system("cls");
        printf("\n### Menu ###\n");
        printf("0. Inserir no Inicio\n");
        printf("1. Inserir no Final\n");
        printf("2. Inserir Ordenado\n");
        printf("3. Inserir Entre Elementos\n");
        printf("4. Excluir Elemento\n");
        printf("5. Excluir Lista (Iterativamente)\n");
        printf("6. Excluir Lista (Recursivamente)\n");
        printf("7. Exibir Lista\n");
        printf("8. Exibir Ultimo Elemento\n");
        printf("9. Exibir Primeiro Elemento\n");
        printf("A. Consultar elemento\n");
        printf("[ESC] Sair\n");
        printf("\nEscolha uma opcao: ");
        opcao = getche();
        
        switch(opcao) {
            case '0':
                Lista = InserirNoInicio(Lista);
                break;
            case '1':
                Lista = InserirNoFinal(Lista);
                break;
            case '2':
                Lista = InserirOrdenado(Lista);
                break;
            case '3':
                Lista = inserirEntreElementos(Lista);
                break;
            case '4':
                Lista = Exclusao(Lista);
                break;
            case '5':
                exclusaoIterativa(Lista);
                Lista = NULL; // Lista exclu�da, ent�o aponta para NULL
                break;
            case '6':
                exclusaoRecursiva(Lista);
                Lista = NULL; // Lista exclu�da, ent�o aponta para NULL
                break;
            case '7':
               	imprimirLista(Lista);
               	//imprimirRecursivo(Lista);
                break;
            case '8':
                exibirUltimo(Lista);
                break;
            case '9':
                exibirPrimeiro(Lista);
                break;
            case 'A':
            	consultar(Lista);
            	break;
            case 27:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
        printf("\nPressione qualquer tecla para continuar...");
        getch();
        
    } while(opcao != 27);
}

int main(void){
    TpPonteiro *Lista = NULL; // Lista é apenas uma variável que guarda um endereço, não guarda nenhum elemento, pois não foi alocado
    menu(Lista);
    return 0;
}

