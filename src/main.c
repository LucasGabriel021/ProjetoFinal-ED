/*
Os estudantes deverão implementar os projetos conforme descrição a seguir:

Descrição do Projeto de Estrutura de Dados

Produto: Descrição, peso, valor de compra, valor de venda, valor do lucro (calculado automaticamente), percentual do lucro (calculado automaticamente) e fabricante.

Fabricante: Marca(nome), site, telefone, UF (AC, AM, AP, SP, TO).

Por fim crie um menu para emitir os relatórios abaixo:

Listar todas as marcas.
Listar todos os produtos.
Listar os produtos de um determinado estado.
Listar os produtos de uma determinada marca.
Apresentar o(s) estado(s) onde está registrado o produto mais caro.
Apresentar o(s) fabricante(s) onde está registrado o produto mais barato.
Listar todos os produtos em ordem crescente de valor.
Listar todos os produtos em ordem crescente de maior "valor do lucro".

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Tema do trabalho === Bicicletas

typedef struct {
	int bike_id;
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
     //printf("Olá Mundo!");
     setlocale(LC_ALL, "Portuguese");
     printf("==============================================================\n");
     printf("=========== Bem vindo a nosso Mercadinho das Bikes ===========\n\n");
     printf("Escolha umas das opções abaixo para proseguir!\n\n");
     printf("==============================================================\n");
     printf("|1| - Cadastros\n");
     printf("|4| - marcas\n");
     printf("|5| - produtos\n");
     printf("===============================================================\n");
     printf("|6| - Selecionar produtos por Estado\n");
     printf("|7| - Selecionar produtos por Marca\n");
     printf("|8| - estado(s) onde está registrado o produto mais caro\n");
     printf("|9| - fabricante(s) onde está registrado o produto mais barato\n");
     printf("|10| - produtos em ordem crescente de valor\n");
     printf("|11| - produtos em ordem crescente de maior valor de lucro.\n");
     printf("|3| - Sair\n\n");
     printf("===============================================================\n");

     //---------------------------------------------------------------------------------------------------------------------------------
     int i = 0;
     int j = 0;
     
     int menu_principal;
     
     Bicicleta bicicletas[100];
     Fabricante fabricantes[100]; 
     int contador_bicicletas = 0;
     int contador_fabricantes = 0;
     
     do {
          printf("===============================================================\n");
          printf("Insira a opção que deseja realizar: ");
          scanf("%d", &menu_principal);
          printf("===============================================================\n");

          switch (menu_principal) {
               case 1:
                    printf("Opção 01 - Cadastro\n\n");
     
                    Bicicleta nova_bicicleta;
                    Fabricante novo_fabricante;
     
                    printf("Número de id da bicicleta: ");
                    scanf("%d", &nova_bicicleta.bike_id);
     
                    printf("Descrição: ");
                    scanf(" %[^\n]s", nova_bicicleta.descricao);
     
                    printf("Peso: ");
                    scanf("%f", &nova_bicicleta.peso);
     
                    printf("ID do fabricante: ");
                    scanf("%i", &nova_bicicleta.fabricante_id);
     
                    printf("Valor da compra: ");
                    scanf("%f", &nova_bicicleta.valor_compra);
     
                    printf("Valor da venda: ");
                    scanf("%f", &nova_bicicleta.valor_venda);
     
                    nova_bicicleta.valor_lucro = nova_bicicleta.valor_venda - nova_bicicleta.valor_compra;
     
                    if (nova_bicicleta.valor_compra > 0) {
                         nova_bicicleta.percentual_lucro = (nova_bicicleta.valor_lucro / nova_bicicleta.valor_compra) * 100;
                    } else {
                         nova_bicicleta.percentual_lucro = 0.0;
                    }
     
                    printf("Nome do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.nome_fabricante);
     
                    printf("Site do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.site_fabricante);
     
                    printf("Telefone do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.telefone_fabricante);
     
                    printf("UF do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.uf_fabricante);
     
                    bicicletas[contador_bicicletas] = nova_bicicleta;
                    fabricantes[contador_fabricantes] = novo_fabricante;
     
                    contador_bicicletas++;
                    contador_fabricantes++;
     
                    // Voltar ao menu principal
                    printf("\n");
                    break;
                
               case 2: 
                    printf("Opção 02");
                    printf("\n\n");
                    break;
                    
               case 4:
                    printf("===============================================================\n");
                    printf("Opção marcas\n\n");
                    printf("===============================================================\n");
               
                    if (contador_fabricantes == 0) {
                         printf("nenhuma marca cadastrada .\n");
                    } else {
                         for (i = 0; i < contador_fabricantes; i++) {
                              printf("Fabricante %d: \n", i + 1);
                              printf("Nome: %s\n", fabricantes[i].nome_fabricante);
                              printf("Site: %s\n", fabricantes[i].site_fabricante);
                              printf("Telefone: %s\n", fabricantes[i].telefone_fabricante);
                              printf("UF: %s\n", fabricantes[i].uf_fabricante);
                              printf("\n");
                        }
                    }
               
                   printf("\n");
                   break;
                    
               case 5: 
                    printf("Opção produtos");
                    
                    if (contador_bicicletas == 0) {
                         printf("nenhum produto cadastrado .\n");
                    } else {
                         for (i = 0; i < contador_bicicletas; i++) {
               
                              printf("Fabricante %d: \n", i + 1);
                              printf("id d produto: %s\n", bicicletas[i].bike_id);
                              printf("descrição: %s\n", bicicletas[i].descricao);
                            
                              printf("\n");
                         }
                    }
                                   
                    printf("\n\n");
                    break;
                    
               case 6: 
                    printf("Opção Selecionar produtos por Estado");
                    printf("\n\n");
                    break;
                    
               case 7: 
                    printf("Opção Selecionar produtos por Marca");
                    printf("\n\n");
                    break;
                    
               case 8: 
                    printf("Opção estado(s) onde está registrado o produto mais caro");
                    printf("\n\n");
                    break;
                    
               case 9: 
                    printf("Opção fabricante(s) onde está registrado o produto mais barato");
                    printf("\n\n");
                    break;
                    
               case 10:
                    printf("Opção produtos em ordem crescente de valor\n\n");

                   //bubble sort
                    for (i = 0; i < contador_bicicletas - 1; i++) {
                         for (j = 0; j < contador_bicicletas - i - 1; j++) {
                              if (bicicletas[j].valor_venda > bicicletas[j + 1].valor_venda) {
                                   Bicicleta temp = bicicletas[j];
                                   bicicletas[j] = bicicletas[j + 1];
                                   bicicletas[j + 1] = temp;
                              }
                         }
                    }

                    for (i = 0; i < contador_bicicletas; i++) {
                            printf("Bicicleta %d:\n", i + 1);
                            printf("Descrição: %s\n", bicicletas[i].descricao);
                            printf("Valor de venda: %.2f\n", bicicletas[i].valor_venda);
                            printf("\n");
                    }
               
                   printf("\n");
                   break;
                    
               case 11: 
                    printf("Opção produtos em ordem crescente de maior valor de lucro");
                    printf("\n\n");
                    break;
                    
               case 3:
                    printf("Opção 03");
                    printf("\n\n");
                    break;
                    
               default: 
                    printf("Opção Inválida");
                    printf("\n\n");
          }
     
     } while (menu_principal != 3);
     
	return 0;
}
