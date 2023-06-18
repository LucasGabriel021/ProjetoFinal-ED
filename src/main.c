#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Tema do trabalho === Bicicletas

typedef struct {
     char descricao[150];
     float peso;
     float valor_compra;
     float valor_venda;
     float valor_lucro;
     float percentual_lucro;
     int fabricante_id;
} Bicicleta;

typedef struct {
     char nome_fabricante[50];
     char site_fabricante[150];
     char telefone_fabricante[12];
     char uf_fabricante[4];
} Fabricante;


int main(void) {
     //printf("Ol� Mundo!");
     setlocale(LC_ALL, "Portuguese");
     
     printf("=========== Bem vindo a nosso Mercadinho das Bikes ===========\n\n");
     printf("Escolha umas das op��es abaixo para proseguir!\n\n");
     printf("|1| - Cadastros\n");
     printf("|2| - Relat�rios\n");
     printf("|3| - Sair\n\n");
     
     int menu_principal;
     
     do {
          
          printf("Insira a op��o que deseja realizar: ");
          scanf("%d", &menu_principal);
     
          switch(menu_principal) {
               case 1: 
                    printf("Op��o 01");
                    printf("\n\n");
                    break;
               case 2: 
                    printf("Op��o 02");
                    printf("\n\n");
                    break;
               case 3: 
                    printf("Op��o 03");
                    printf("\n\n");
                    break;
               default: 
                    printf("Op��o Inv�lida");
                    printf("\n\n");
          }
     
     } while (menu_principal != 3);
     
	return 0;
}
