#include<stdlib.h>
#include<stdio.h>

// declaração da estrutura de dados
struct ElementoDaArvoreBinaria {
	int nru;
	char nome[50];
	char email[50];
	struct ElementoDaArvoreBinaria* direita, * esquerda;
};

//declarando funções
int menu();
ElementoDaArvoreBinaria* Buscar(ElementoDaArvoreBinaria** ElementoVarredura, int num);
void Listar_EmOrdem(ElementoDaArvoreBinaria*);

//cadastrando os dados
struct ElementoDaArvoreBinaria C = { 2027751, "JOSE", "jose@uni.com" };
struct ElementoDaArvoreBinaria D = { 2328654, "MARIA", "maria@uni.com" };
struct ElementoDaArvoreBinaria E = { 2823688, "DANIEL VITOR VILAS BOAS MATOS", "dedomatos12@gmail.com" }; //meu cadastro
struct ElementoDaArvoreBinaria F = { 3025659, "MARCELO", "marcelo@uni.com" };
struct ElementoDaArvoreBinaria G = { 3727454, "JULIA", "julia@uni.com" };
struct ElementoDaArvoreBinaria H = { 3928454, "PAULA", "paula@uni.com" };
struct ElementoDaArvoreBinaria J = { 4020655, "CRISTINA", "cristina@uni.com" };
struct ElementoDaArvoreBinaria K = { 4221133, "MARIO", "mario@uni.com" };
struct ElementoDaArvoreBinaria L = { 4312123, "TERESA", "teresa@uni.com" };
struct ElementoDaArvoreBinaria M = { 4521959, "PEDRO", "pedro@uni.com" };



int main() {

	//direcionando ponteiros para formar a arvore
	C.direita = NULL;
	C.esquerda = NULL;
	D.direita = &E;
	D.esquerda = &C;
	E.direita = NULL;
	E.esquerda = NULL;
	F.direita = &G;
	F.esquerda = &D;
	G.direita = NULL;
	G.esquerda = NULL;
	H.direita = &K;
	H.esquerda = &F;
	J.direita = NULL;
	J.esquerda = NULL;
	K.direita = &L;
	K.esquerda = &J;
	L.direita = &M;
	L.esquerda = NULL;
	M.direita = NULL;
	M.esquerda = NULL;

	// declarando variaveis e ponteiros 
	int op, num, c;

	ElementoDaArvoreBinaria* root;
	root = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));
	root = &H;

	ElementoDaArvoreBinaria* ElementoBusca;
	ElementoBusca = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o numero do RU ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			ElementoBusca = Buscar(&root, num);
			if (ElementoBusca != 0)
				printf("\n");
			else
				printf("Aluno não encontrado.\n");
			system("pause");
			break;
		case 2:
			Listar_EmOrdem(root);
			printf("\n\n");
			system("pause");
			break;
		case 3:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

// função menu
int menu() {
	int op, c;
	system("Cls");

	printf("1.Buscar aluno pelo RU\n");
	printf("2.Listar Alunos pelo nome\n");
	printf("3.Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

// função busca
ElementoDaArvoreBinaria* Buscar(ElementoDaArvoreBinaria** ElementoVarredura, int num)
{
	if (*ElementoVarredura == NULL)
		return NULL;

	if (num < (*ElementoVarredura)->nru)
	{
		Buscar(&((*ElementoVarredura)->esquerda), num);
	}
	else
	{
		if (num > (*ElementoVarredura)->nru)
		{
			Buscar(&((*ElementoVarredura)->direita), num);
		}
		else
		{
			if (num == (*ElementoVarredura)->nru) {
				printf("RU: %d \nNome do aluno: %s \nE-mail: %s \n", (*ElementoVarredura)->nru, (*ElementoVarredura)->nome, (*ElementoVarredura)->email);
				return *ElementoVarredura;
			}
		}
	}
}

// função consulta
void Listar_EmOrdem(ElementoDaArvoreBinaria* ElementoVarredura)
{
	if (ElementoVarredura)
	{
		Listar_EmOrdem(ElementoVarredura->esquerda);
		printf("RU: %d , Nome: %s , E-mail:%s\n", ElementoVarredura->nru, ElementoVarredura->nome, ElementoVarredura->email);
		Listar_EmOrdem(ElementoVarredura->direita);
	}
}

