#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <string>
struct no
{
 int chave;
 struct no *esq, *dir;
};
void cabecalho();
void inserir(int n, struct no **raiz);
void remove(int n, struct no **raiz);
void emOrdem(struct no *raiz);
void posOrdem(struct no *raiz);
void preOrdem(struct no *raiz);
void decrescente(struct no *raiz);
int mydel(struct no **x);
int busca(int n, struct no *raiz);
int maior(struct no *raiz);
int menor(struct no *raiz);
int quantidade(struct no *raiz);
int soma(struct no *raiz);
float media(struct no *raiz);
int altura(struct no *raiz);
int par(struct no *raiz);
void multiplosK(int k, struct no *raiz);
float desvio(struct no *raiz, float media);
int null(struct no *raiz);
int umfilho(struct no *raiz);
int doisfilho(struct no *raiz);
int folha(struct no *raiz);
void largura(struct no *raiz);
void escrever(struct no *raiz, char *q);
void comparar(struct no *raiz1, struct no *raiz2, int *n);
void buscacomparar(struct no *raiz1, struct no *raiz2, int *n);
using namespace std;
int main(void)
{
 setlocale (LC_ALL,"Portuguese");
 //system("title Projeto Arvores");
 //system("color fd");
 char opcao;
 struct no *raiz1=NULL, *raiz2=NULL, *raiz3=NULL;
 int arvore=1;
 //ARVORE 1
 FILE* arquivo;
 if ((arquivo = fopen("arvore1.txt","r")) == NULL)
 {
 arquivo = fopen("arvore1.txt","w+");
 }
 char ch;
 int i;
 string str="";
 while((ch=fgetc(arquivo))!= EOF)
 {
 if(ch == '\n')
 {
 i = stoi(str);
 inserir(i, &raiz1);
 str="";
 }
 else{
 str += (ch);
 }
 }
 fclose(arquivo);
 //ARVORE 2
 if ((arquivo = fopen("arvore2.txt","r")) == NULL)
 {
 arquivo = fopen("arvore2.txt","w+");
 }
 str="";
 while((ch=fgetc(arquivo))!= EOF)
 {
 if(ch == '\n')
 {
 i = stoi(str);
 inserir(i, &raiz2);
 str="";
 }
 else{
 str += (ch);
 }
 }
 fclose(arquivo);
 //ARVORE 3
 if ((arquivo = fopen("arvore3.txt","r")) == NULL)
 {
 arquivo = fopen("arvore3.txt","w+");
 }
 str="";
 while((ch=fgetc(arquivo))!= EOF)
 {
 if(ch == '\n')
 {
 i = stoi(str);
 inserir(i, &raiz3);
 str="";
 }
 else{
 str += (ch);
 }
 }
 fclose(arquivo);
 do
 {
 cabecalho();
 cout<<"\n\n\t\t\t\t\t\tÁRVORES BINÁRIAS DE BUSCA";
 cout<<"\n\t\t\t\t Atualmente manipulando a árvore ";
 if(arvore == 1)
 cout<<"UM";
 else if(arvore == 2)
 cout<<"DOIS";
 else
 cout<<"TRÊS";
 cout<<"\n\t\t --------------------------------------------------------";
 cout<<"\n\t\tA) Inserir um elemento\n\t\tB) Remover um elemento\n\t\tC) Buscar um
elemento\n\t\tD) Encontrar maior elemento\n\t\tE) Encontrar menor elemento\n\t\tF)
Quantidade de elementos\n\t\tG) Altura da árvore\n\t\tH) Contagem de ímpares e pares\n\t\tI)
Encontrar múltiplos de K\n\t\tJ) Imprimir em ordem crescente\n\t\tK) Imprimir em ordem
decrescente\n\t\tL) Soma dos elementos\n\t\tM) Média dos elementos\n\t\tN) Calcular desvio
padrão dos elementos\n\t\tO) Quantidade de NULLs\n\t\tP) Quantidade de elementos com dois
filhos\n\t\tQ) Quantidade de elementos com um filho\n\t\tR) Quantidade de folhas\n\t\tS)
Árvore em ordem\n\t\tT) Árvore em preordem\n\t\tU) Árvore em posordem\n\t\tV) Árvore em
largura\n\t\tW) Trocar de árvore\n\t\tX) Comparar árvores\n\t\t0) SAIR";
 cout<<"\n\n\t\tInsira sua opção: ";
 cin>>opcao;
 opcao = tolower(opcao);
 switch (opcao)
 {
 case 'a':
 {
 //Inserir um elemento
 int n;
 cout<<"\n\t\tInsira o elemento para inserção: ";
 cin>>n;
 if(arvore == 1)
 inserir(n, &raiz1);
 else if(arvore == 2)
 inserir(n, &raiz2);
 else
 inserir(n, &raiz3);
 }
 break;
 case 'b':
 {
 //Remover um elemento
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 int n;
 cout<<"\n\t\tInsira o elemento para a remoção: ";
 cin>>n;
 remove(n, &raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 int n;
 cout<<"\n\t\tInsira o elemento para a remoção: ";
 cin>>n;
 remove(n, &raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 int n;
 cout<<"\n\t\tInsira o elemento para a remoção: ";
 cin>>n;
 remove(n, &raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'c':
 {
 //Buscar um elemento
 int n;
 cout<<"\n\t\tInsira o elemento para realizar a busca: ";
 cin>>n;
 if(arvore == 1)
 {
 if(busca(n, raiz1)==0)
 cout<<"\n\t\tElemento NÃO encontrado!";
 else
 cout<<"\n\t\tElemento encontrado!";
 }
 else if(arvore == 2)
 {
 if(busca(n, raiz2)==0)
 cout<<"\n\t\tElemento NÃO encontrado!";
 else
 cout<<"\n\t\tElemento encontrado!";
 }
 else
 {
 if(busca(n, raiz3)==0)
 cout<<"\n\t\tElemento NÃO encontrado!";
 else
 cout<<"\n\t\tElemento encontrado!";
 }
 }
 break;
 case 'd':
 {
 //Encontrar maior elemento
 int num;
 if(arvore == 1)
 num = maior(raiz1);
 else if(arvore == 2)
 num = maior(raiz2);
 else
 num = maior(raiz3);
 if(num!=-1)
 cout<<"\n\t\tMaior número da árvore: "<<num;
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 break;
 case 'e':
 {
 //Encontrar menor elemento
 int num;
 if(arvore == 1)
 num = menor(raiz1);
 else if(arvore == 2)
 num = menor(raiz2);
 else
 num = menor(raiz3);
 if(num!=-1)
 cout<<"\n\t\tMenor número da árvore: "<<num;
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 break;
 case 'f':
 {
 //Quantidade de elementos
 if(arvore == 1)
 cout<<"\n\t\tQuantidade de elementos na árvore: "<<quantidade(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tQuantidade de elementos na árvore: "<<quantidade(raiz2);
 else
 cout<<"\n\t\tQuantidade de elementos na árvore: "<<quantidade(raiz3);
 }
 break;
 case 'g':
 {
 //Altura da arvore
 if(arvore == 1)
 {
 if(raiz1 == NULL)
 cout<<"\n\t\tÁrvore vazia!";
 else
 cout<<"\n\t\tAltura da árvore: "<<altura(raiz1);
 }
 else if(arvore == 2)
 {
 if(raiz2 == NULL)
 cout<<"\n\t\tÁrvore vazia!";
 else
 cout<<"\n\t\tAltura da árvore: "<<altura(raiz2);
 }
 else
 {
 if(raiz3 == NULL)
 cout<<"\n\t\tÁrvore vazia!";
 else
 cout<<"\n\t\tAltura da árvore: "<<altura(raiz3);
 }
 }
 break;
 case 'h':
 {
 //Contagem de ímpares e pares
 if(arvore == 1)
 {
 int pares = par(raiz1);
 cout<<"\n\t\tNúmero de pares: "<<pares;
 cout<<"\n\t\tNúmero de ímpares: "<<quantidade(raiz1) - pares;
 }
 else if(arvore == 2)
 {
 int pares = par(raiz2);
 cout<<"\n\t\tNúmero de pares: "<<pares;
 cout<<"\n\t\tNúmero de ímpares: "<<quantidade(raiz2) - pares;
 }
 else
 {
 int pares = par(raiz3);
 cout<<"\n\t\tNúmero de pares: "<<pares;
 cout<<"\n\t\tNúmero de ímpares: "<<quantidade(raiz3) - pares;
 }
 }
 break;
 case 'i':
 {
 //Encontrar múltiplos de K
 int k;
 cout<<"\n\t\tInsira o valor de K: ";
 cin>>k;
 cout<<"\n\t\tMúltiplos de k: ";
 if(arvore == 1)
 multiplosK(k, raiz1);
 else if(arvore == 2)
 multiplosK(k, raiz2);
 else
 multiplosK(k, raiz3);
 }
 break;
 case 'j':
 {
 //Imprimir em rdem crescente
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem crescente:\n\t\t";
 emOrdem(raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem crescente:\n\t\t";
 emOrdem(raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem crescente:\n\t\t";
 emOrdem(raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'k':
 {
 //Imprimir em ordem decrescente
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem decrescente:\n\t\t";
 decrescente(raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem decrescente:\n\t\t";
 decrescente(raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem decrescente:\n\t\t";
 decrescente(raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'l':
 {
 //Soma dos elementos
 if(arvore == 1)
 cout<<"\n\t\tSoma dos elementos da árvore: "<<soma(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tSoma dos elementos da árvore: "<<soma(raiz2);
 else
 cout<<"\n\t\tSoma dos elementos da árvore: "<<soma(raiz3);
 }
 break;
 case 'm':
 {
 //Média dos elementos
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 cout<<"\n\t\tMédia dos elementos da árvore: "<<media(raiz1);
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 cout<<"\n\t\tMédia dos elementos da árvore: "<<media(raiz2);
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 cout<<"\n\t\tMédia dos elementos da árvore: "<<media(raiz3);
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'n':
 {
 //Calcular desvio padrão dos elementos
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 cout<<"\n\t\tDesvio padrão: "<<sqrt(desvio(raiz1,
media(raiz1))/(quantidade(raiz1)-1));
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tDesvio padrão: "<<sqrt(desvio(raiz2,
media(raiz2))/(quantidade(raiz2)-1));
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 cout<<"\n\t\tDesvio padrão: "<<sqrt(desvio(raiz3,
media(raiz3))/(quantidade(raiz3)-1));
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'o':
 {
 //Quantidade de NULLs
 if(arvore == 1)
 cout<<"\n\t\tQuantidade de NULLs presentes: "<<null(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tQuantidade de NULLs presentes: "<<null(raiz2);
 else
 cout<<"\n\t\tQuantidade de NULLs presentes: "<<null(raiz3);
 }
 break;
 case 'p':
 {
 //Quantidade de elementos com dois filhos
 if(arvore == 1)
 cout<<"\n\t\tQuantidade de elementos com dois filhos: "<<doisfilho(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tQuantidade de elementos com dois filhos: "<<doisfilho(raiz2);
 else
 cout<<"\n\t\tQuantidade de elementos com dois filhos: "<<doisfilho(raiz3);
 }
 break;
 case 'q':
 {
 //Quantidade de elementos com um filho
 if(arvore == 1)
 cout<<"\n\t\tQuantidade de elementos com um filho: "<<umfilho(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tQuantidade de elementos com um filho: "<<umfilho(raiz2);
 else
 cout<<"\n\t\tQuantidade de elementos com um filho: "<<umfilho(raiz3);
 }
 break;
 case 'r':
 {
 //Quantidade de folhas
 if(arvore == 1)
 cout<<"\n\t\tQuantidade de folhas: "<<folha(raiz1);
 else if(arvore == 2)
 cout<<"\n\t\tQuantidade de folhas: "<<folha(raiz2);
 else
 cout<<"\n\t\tQuantidade de folhas: "<<folha(raiz3);
 }
 break;
 case 's':
 {
 //Árvore em ordem
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem:\n\t\t";
 emOrdem(raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem:\n\t\t";
 emOrdem(raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 cout<<"\n\t\tÁrvore em ordem:\n\t\t";
 emOrdem(raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 't':
 {
 //Árvore em preordem
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 cout<<"\n\t\tÁrvore Pré ordem:\n\t\t";
 preOrdem(raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tÁrvore Pré ordem:\n\t\t";
 preOrdem(raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 cout<<"\n\t\tÁrvore Pré ordem:\n\t\t";
 preOrdem(raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'u':
 {
 //Árvore em pós ordem
 if(arvore == 1)
 {
 if(raiz1!=NULL)
 {
 cout<<"\n\t\tÁrvore Pós ordem:\n\t\t";
 posOrdem(raiz1);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else if(arvore == 2)
 {
 if(raiz2!=NULL)
 {
 cout<<"\n\t\tÁrvore Pós ordem:\n\t\t";
 posOrdem(raiz2);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 else
 {
 if(raiz3!=NULL)
 {
 cout<<"\n\t\tÁrvore Pós ordem:\n\t\t";
 posOrdem(raiz3);
 }
 else
 cout<<"\n\t\tÁrvore vazia!";
 }
 }
 break;
 case 'v':
 {
 //Árvore em lagura
 cout<<"\n\t\tÁrvore em largura: \n\t\t";
 if(arvore == 1)
 {
 if(raiz1 == NULL)
 {
 cout<<"\n\t\tÁrvore vazia!";
 break;
 }
 largura(raiz1);
 }
 else if(arvore == 2)
 {
 if(raiz2 == NULL)
 {
 cout<<"\n\t\tÁrvore vazia!";
 break;
 }
 largura(raiz2);
 }
 else
 {
 if(raiz3 == NULL)
 {
 cout<<"\n\t\tÁrvore vazia!";
 break;
 }
 largura(raiz3);
 }
 }
 break;
 case 'w':
 {
 cout<<"\n\t\tInsira o número da árvore: ";
 int num;
 cin>>num;
 if(num == 1)
 arvore = 1;
 else if(num == 2)
 arvore = 2;
 else if(num == 3)
 arvore = 3;
 else
 cout<<"\n\t\tNúmero de árvore inválido!";
 }
 break;
 case 'x':
 {
 cout<<"\n\t\tInsira o número da árvore para comparação: ";
 int avr;
 cin>>avr;
 int nn = 0;
 if(avr<1 || avr>3)
 {
 cout<<"\n\t\tNúmero de árvore inválido";
 break;
 }
 if(arvore == 1)
 {
 if(avr == 2)
 comparar(raiz1, raiz2, &nn);
 else if(avr == 3)
 comparar(raiz1, raiz3, &nn);
 }
 else if(arvore == 2)
 {
 if(avr == 1)
 comparar(raiz1, raiz2, &nn);
 else if(avr == 3)
 comparar(raiz2, raiz3, &nn);
 }
 else if(arvore == 3)
 {
 if(avr == 2)
 comparar(raiz3, raiz2, &nn);
 else if(avr == 1)
 comparar(raiz1, raiz3, &nn);
 }
 if(nn == 0)
 cout<<"\n\t\tÁrvores iguais e com mesmos valores";
 else if(nn == 1)
 cout<<"\n\t\tÁrvores iguais mas valores diferentes";
 else
 {
 int m = 1;
 if(arvore == 1)
 {
 if(avr == 2)
 buscacomparar(raiz1, raiz2, &m);
 else if(avr == 3)
 buscacomparar(raiz1, raiz3, &m);
 }
 else if(arvore == 2)
 {
 if(avr == 1)
 buscacomparar(raiz1, raiz2, &m);
 else if(avr == 3)
 buscacomparar(raiz2, raiz3, &m);
 }
 else if(arvore == 3)
 {
 if(avr == 2)
 buscacomparar(raiz3, raiz2, &m);
 else if(avr == 1)
 buscacomparar(raiz1, raiz3, &m);
 }
 if(m == 0)
 cout<<"\n\t\tÁrvores com estruturas diferentes";
 else
 cout<<"\n\t\tÁrvores com estruturas diferentes mas elementos iguais";
 }
 }
 break;
 case '0':
 break;
 default:
 {
 cout<<"\n\t\tDigite uma opção válida!";
 cout<<"\n\t\t --------------------------------------------------------\n";
 }
 }
 cin.ignore();
 cout<<"\n\n\t\t--------------------------------------------------------\n";
 cout<<"\n\t\tPressione enter para continuar";
 int c = getchar();
 system("clear");
 }
 while(opcao!='0');
 //ARVORE 1
 arquivo = fopen("arvore1.txt", "w+");
 char nome1[50] = "arvore1";
 strcat(nome1, ".txt");
 escrever(raiz1, nome1);
 fclose(arquivo);
 //ARVORE 2
 arquivo = fopen("arvore2.txt", "w+");
 char nome2[50] = "arvore2";
 strcat(nome2, ".txt");
 escrever(raiz2, nome2);
 fclose(arquivo);
 //ARVORE 3
 arquivo = fopen("arvore3.txt", "w+");
 char nome3[50] = "arvore3";
 strcat(nome3, ".txt");
 escrever(raiz3, nome3);
 fclose(arquivo);
}
void inserir(int n, struct no **raiz)
{
 if(*raiz == NULL)
 {
 *raiz = (struct no *)malloc(sizeof(struct no));
 if(*raiz == NULL)
 {
 cout<<"\n\t\tHeap overflow!";
 return;
 }
 (*raiz)->chave = n;
 (*raiz)->esq = (*raiz)->dir = NULL;
 }
 else if (n<(*raiz)->chave)
 {
 inserir(n, &(*raiz)->esq);
 }
 else if (n>(*raiz)->chave)
 {
 inserir(n, &(*raiz)->dir);
 }
 else
 {
 cout<<"\n\t\tNúmero existente";
 }
}
int busca(int n, struct no *raiz)
{
 if(raiz == NULL)
 {
 return 0;
 }
 else if(n == raiz->chave)
 {
 return 1;
 }
 else if(n<raiz->chave)
 {
 return busca(n, raiz->esq);
 }
 else
 {
 return busca(n, raiz->dir);
 }
}
void preOrdem(struct no *raiz)
{
 if(raiz!=NULL)
 {
 cout<<raiz->chave<<" ";
 preOrdem(raiz->esq);
 preOrdem(raiz->dir);
 }
}
void emOrdem(struct no *raiz)
{
 if(raiz!=NULL)
 {
 emOrdem(raiz->esq);
 cout<<raiz->chave<<" ";
 emOrdem(raiz->dir);
 }
}
void posOrdem(struct no *raiz)
{
 if(raiz!=NULL)
 {
 posOrdem(raiz->esq);
 posOrdem(raiz->dir);
 cout<<raiz->chave<<" ";
 }
}
int maior(struct no *raiz)
{
 if(raiz==NULL)
 {
 return -1;
 }
 else if(raiz->dir==NULL)
 {
 return raiz->chave;
 }
 else
 {
 return maior(raiz->dir);
 }
}
int menor(struct no *raiz)
{
 if(raiz==NULL)
 {
 return -1;
 }
 else if(raiz->esq==NULL)
 {
 return raiz->chave;
 }
 else
 {
 return maior(raiz->esq);
 }
}
int quantidade(struct no *raiz)
{
 if(raiz==NULL)
 {
 return 0;
 }
 return (1 + quantidade(raiz->esq) + quantidade(raiz->dir));
}
int soma(struct no *raiz)
{
 if(raiz==NULL)
 {
 return 0;
 }
 return (raiz->chave + soma(raiz->esq) + soma(raiz->dir));
}
float media(struct no *raiz)
{
 if(raiz==NULL)
 return 0;
 return (soma(raiz)/(float)quantidade(raiz));
}
void remove(int n, struct no **raiz)
{
 if(*raiz!=NULL)
 {
 if((*raiz)->chave == n)
 {
 if((*raiz)->esq == NULL)
 (*raiz) = (*raiz)->dir;
 else if((*raiz)->dir == NULL)
 (*raiz) = (*raiz)->esq;
 else
 (*raiz)->chave = mydel(&(*raiz)->esq);
 cout<<"\n\t\tElemento removido com sucesso";
 return;
 }
 else if(n>(*raiz)->chave)
 {
 remove(n, &(*raiz)->dir);
 }
 else if(n<(*raiz)->chave)
 {
 remove(n, &(*raiz)->esq);
 }
 }
 else
 cout<<"\n\t\tElemento não presente";
}
int mydel(struct no **x)
{
 if((*x)->dir != NULL)
 return mydel(&(*x)->dir);
 else
 {
 int n = (*x)->chave;
 struct no *aux = (*x);
 (*x) = (*x)->esq;
 free(aux);
 return n;
 }
}
int altura(struct no *raiz)
{
 if (raiz == NULL)
 {
 return -1;
 }
 else
 {
 int altDir = altura(raiz->dir);
 int altEsq = altura(raiz->esq);
 if (altEsq < altDir)
 {
 return altDir + 1;
 }
 else
 {
 return altEsq + 1;
 }
 }
}
int par(struct no *raiz)
{
 if(raiz == NULL)
 {
 return 0;
 }
 else if(raiz->chave%2 == 0)
 return (1 + par(raiz->esq) + par(raiz->dir));
 else
 return (par(raiz->esq) + par(raiz->dir));
}
void multiplosK(int k, struct no *raiz)
{
 if (raiz != NULL)
 {
 if (raiz->chave%k == 0)
 cout<<raiz->chave<<" ";
 multiplosK(k, raiz->esq);
 multiplosK(k, raiz->dir);
 }
}
float desvio(struct no *raiz, float media)
{
 if(raiz == NULL)
 return 0;
 return (pow(((raiz->chave)) - media, 2) + desvio(raiz->esq, media) + desvio(raiz->dir,
media));
}
void decrescente(struct no *raiz)
{
 if(raiz!=NULL)
 {
 decrescente(raiz->dir);
 cout<<raiz->chave<<" ";
 decrescente(raiz->esq);
 }
}
int null(struct no *raiz)
{
 if(raiz == NULL)
 return 1;
 else
 return (null(raiz->esq) + null(raiz->dir));
}
int doisfilho(struct no *raiz)
{
 if(raiz == NULL)
 return 0;
 else if(raiz->esq!=NULL && raiz->dir!=NULL)
 return (1 + doisfilho(raiz->esq) + doisfilho(raiz->dir));
 else
 return (doisfilho(raiz->esq) + doisfilho(raiz->dir));
}
int umfilho(struct no *raiz)
{
 if(raiz == NULL)
 return 0;
 else if(raiz->esq==NULL && raiz->dir!=NULL)
 return (1 + umfilho(raiz->dir));
 else if(raiz->dir==NULL && raiz->esq!=NULL)
 return (1 + umfilho(raiz->esq));
 else
 return (umfilho(raiz->esq) + umfilho(raiz->dir));
}
int folha(struct no *raiz)
{
 if(raiz == NULL)
 return 0;
 else if(raiz->esq==NULL && raiz->dir==NULL)
 return 1;
 else
 return (folha(raiz->esq) + folha(raiz->dir));
}
void largura(struct no *raiz){

if(raiz==NULL){
 return;
 }
 queue<no *> f;
 f.push(raiz);

 while(!f.empty()){
 no *prox = f.front();
 cout<<prox->chave<<" ";

 if((prox->esq)!=NULL)
 f.push(prox->esq);

 if((prox->dir)!=NULL)
 f.push(prox->dir);

 f.pop();
 }
}
void escrever(struct no *raiz, char *q)
{
 FILE *fp;
 fp = fopen (q, "a+");
 if(raiz!=NULL)
 {
 fprintf(fp, "%d\n", raiz->chave);
 escrever(raiz->esq, q);
 escrever(raiz->dir, q);
 }
 fclose(fp);
}
//n = 0 - iguais e mesmo valor
//n = 1 - iguais mas valores diferentes
//n = 2 - diferentes
void comparar(struct no *raiz1, struct no *raiz2, int *n)
{
 if(raiz1 != NULL || raiz2 !=NULL)
 {
 if(raiz1 != NULL && raiz2 != NULL)
 {
 if(raiz1->chave != raiz2->chave)
 *n = 1;
 comparar(raiz1->esq, raiz2->esq, n);
 comparar(raiz1->dir, raiz2->dir, n);
 }
 else
 *n = 2;
}
}
void buscacomparar(struct no *raiz1, struct no *raiz2, int *n)
{
 if(raiz1 != NULL)
 {
 int m = busca(raiz1->chave, raiz2);
 if(m == 0)
 *n = 0;
 buscacomparar(raiz1->esq, raiz2, n);
 buscacomparar(raiz1->dir, raiz2, n);
 }
}
void cabecalho()
{
 cout<<"\n\t\t --------------------------------------------------------";
 cout<<"\n\t\t| Pontifícia Universidade Católica de Campinas |";
 cout<<"\n\t\t| Curso de Engenharia de Software |";
 cout<<"\n\t\t| Disciplina: Algorítmos e Estruturas de Dados B |";
 cout<<"\n\t\t| Alunas: |";
 cout<<"\n\t\t| Anita Isabelly Gabionetta de Souza(20002515) |";
 cout<<"\n\t\t| Giulia Brocchi(20003778) |";
 cout<<"\n\t\t| Nicole Conti Bertin(20070744) |";
 cout<<"\n\t\t --------------------------------------------------------";
 cout<<"\n\t\t| Opcionais funcionando: OPCIONAIS de A) até Z) |";
 cout<<"\n\t\t| Valor do Projeto: 10 pontos |";
 cout<<"\n\t\t --------------------------------------------------------";
}
