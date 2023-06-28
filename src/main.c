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

Tema do trabalho === Bicicletas
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Macros
#define QTDBICICLETAS 100
#define QTDFABRICANTES 100
#define TEXTO 150
#define TELEFONE 12
#define UNIDADEFEDERATIVA 4

#define MENSAGEMINVALIDA printf("Valor inválido, por favor insira novamente!\n");

// Estruturas
typedef struct {
	int bike_id;
     char descricao[TEXTO];
     float peso;
     float valor_compra;
     float valor_venda;
     float valor_lucro;
     float percentual_lucro;
     int fabricante_id;
} Bicicleta;

typedef struct {
     char nome_fabricante[TEXTO];
     char site_fabricante[TEXTO];
     char telefone_fabricante[TELEFONE];
     char uf_fabricante[UNIDADEFEDERATIVA];
} Fabricante;

// Função(s)
void exibirMenu() {
     printf("==========================================================================\n");
     printf("=========== Bem vindo a nossa loja de bicicletas Pedal de Ouro ===========\n");
     printf("==========================================================================\n\n");
     printf("Escolha umas das opções abaixo caso deseje realizar alguma ação:\n");
     printf("|1| - Cadastrar Produtos\n");
     printf("|2| - Relatório de marcas(s).\n");
     printf("|3| - Relatório de produto(s).\n");
     printf("|4| - Relatório de produto(s) por estado.\n");
     printf("|5| - Relatório de produto(s) por fabricante.\n");
     printf("|6| - Relatório de estado de produto(s) mais caro(s).\n");
     printf("|7| - Relatório de fabricante de o produto(s) mais barato(s).\n");
     printf("|8| - Relatório de produtos do menor para o maior valor.\n");
     printf("|9| - Relatório de produtos do maior para o menor valor.\n");
     printf("|10| - Relatório de produtos de maior valor de lucro.\n");
     printf("|11| - Sair do sistema!\n\n");
     printf("===============================================================\n");
}

int main(void) {
     //printf("Olá Mundo!");
     setlocale(LC_ALL, "Portuguese");

     int i = 0;
     int j = 0;
     
     int menu_principal;
     
     Bicicleta bicicletas[QTDBICICLETAS];
     Fabricante fabricantes[QTDFABRICANTES]; 
     int contador_bicicletas = 0;
     int contador_fabricantes = 0;
     
     do {
          exibirMenu();
          printf("Insira a opção que deseja realizar: ");
          scanf("%d", &menu_principal);
     
          switch (menu_principal) {
               case 1:
                    system("cls");
                    printf("===============================================================\n");
                    printf("Selecionada a opção 01 - Cadastro\n");
                    printf("OBS: É permitido apenas 100 cadastros!\n");
                    printf("===============================================================\n\n");

                    Bicicleta nova_bicicleta;
                    Fabricante novo_fabricante;

//                    printf("Número de id da bicicleta: ");
//                    scanf("%d", &nova_bicicleta.bike_id);

                    printf("Insira as informações abaixo sobre o produto: \n\n");
                    printf("Informe a descrição do produto: ");
                    scanf(" %[^\n]s", nova_bicicleta.descricao);

                    printf("Informe o peso do produto: ");
                    scanf("%f", &nova_bicicleta.peso);

//                    printf("ID do fabricante: ");
//                    scanf("%i", &nova_bicicleta.fabricante_id);

                    printf("Informe o valor da compra do produto: ");
                    scanf("%f", &nova_bicicleta.valor_compra);

                    printf("Informe o valor da venda do produto: ");
                    scanf("%f", &nova_bicicleta.valor_venda);

                    nova_bicicleta.valor_lucro = nova_bicicleta.valor_venda - nova_bicicleta.valor_compra;

                    // Cálculo do lucro
                    if (nova_bicicleta.valor_compra > 0) {
                         nova_bicicleta.percentual_lucro = (nova_bicicleta.valor_lucro / nova_bicicleta.valor_compra) * 100;
                    } else {
                         nova_bicicleta.percentual_lucro = 0.0;
                    }

                    printf("\nInsira as informações abaixo sobre o fabricante deste produto: \n\n");
                    printf("Informe o nome do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.nome_fabricante);

                    printf("Informe o site de contato do fabricante: ");
                    scanf(" %[^\n]s", novo_fabricante.site_fabricante);

                    printf("OBS: o formato a ser inserido deve conter 11 caracteres!\n");
                    do {
                         printf("Informe o telefone do fabricante: ");
                         scanf(" %[^\n]s", novo_fabricante.telefone_fabricante);
                         if(strlen(novo_fabricante.telefone_fabricante) > 12) {
                              // Utilização de macro para exibir mensagem de erro!
                              MENSAGEMINVALIDA;
                         }
                    } while (strlen(novo_fabricante.telefone_fabricante) > 12);
                    
                    printf("OBS: Informe a sigla da Unidade Federativa (UF), apenas 2 caracteres!\n");
                    do {
                         printf("Estado do fabricante: ");
                         scanf(" %[^\n]s", novo_fabricante.uf_fabricante); 
                         if(strlen(novo_fabricante.uf_fabricante) > 2) {
                              MENSAGEMINVALIDA;
                         }
                    } while(strlen(novo_fabricante.uf_fabricante) > 2);
                    
                    nova_bicicleta.bike_id = contador_bicicletas + 1;
                    nova_bicicleta.fabricante_id = contador_fabricantes + 1;

                    bicicletas[contador_bicicletas] = nova_bicicleta;
                    fabricantes[contador_fabricantes] = novo_fabricante;

                    contador_bicicletas++;
                    contador_fabricantes++;
                    
//                    printf("\n\nId da bicicleta: %d", nova_bicicleta.bike_id);
//                    printf("\nId do fabricante: %d", nova_bicicleta.fabricante_id);
                    printf("\nUF informada: %s", novo_fabricante.uf_fabricante);

                    printf("\nCadastro realizado com sucesso!");
                    printf("\nConfira as informações acima ou nos relatórios.");
                    printf("\n\n\n");
                    break;
                    
               case 2:
                    system("cls");
                    printf("===============================================================\n");
                    printf("Selecionada a opção 02 - Relatório de fabricantes cadastrados\n");
                    printf("===============================================================\n\n");

                    if (contador_fabricantes == 0) {
                         printf("Nenhum fabricante foi encontado no sistema, por favor cadastre algum fabricante!");
                    } else {
                         for (i = 0; i < contador_fabricantes; i++) {
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do fabricante: %d\n", bicicletas[i].fabricante_id);
                              printf("Nome do fabricante: %s\n", fabricantes[i].nome_fabricante);
                              printf("Url do site do fabricante: %s\n", fabricantes[i].site_fabricante);
                              printf("Telefone do fabricante: %s\n", fabricantes[i].telefone_fabricante);
                              printf("Unidade Federativa do fabricante: %s\n", fabricantes[i].uf_fabricante);
                              printf("\n");
                         }     
                    }

                    printf("\n\n");
                    break;
                    
               case 3: 
                    system("cls");
                    printf("===============================================================\n");
                    printf("Selecionada a opção 03 - Relatório de produtos cadastrados\n");
                    printf("===============================================================\n\n");
                    
                    if (contador_bicicletas == 0) {
                         printf("Nenhum produto foi encontado no sistema, por favor cadastre algum produto!");
                    } else {
                         for (i = 0; i < contador_bicicletas; i++) {
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do produto: %d\n", bicicletas[i].bike_id);
                              printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                              printf("Peso do produto: %.2f \n", bicicletas[i].peso);
                              printf("Valor da compra: R$ %.2f\n", bicicletas[i].valor_compra);
                              printf("Valor da venda: R$ %.2f\n", bicicletas[i].valor_venda);
                              printf("Valor do lucro: R$ %.2f\n", bicicletas[i].valor_lucro);
                              printf("Percentual de lucro: %.2f%\n", bicicletas[i].percentual_lucro);
                              printf("\n");
                         }
                    }
                    
                    printf("\n\n");
                    break;
                    
               case 4:
                    system("cls");
                    printf("===========================================================================\n");
                    printf("Selecionada a opção 04 - Selecionar produtos de acordo com o estado (UF)\n");
                    printf("===========================================================================\n\n");
    
                    char estado_desejado[UNIDADEFEDERATIVA];
                    
                    printf("OBS: Informe a sigla da Unidade Federativa (UF), apenas 2 caracteres!\n");
                    printf("Informe o estado para realizar a busca: ");
                    scanf(" %[^\n]s", estado_desejado);

                    int produtos_encontrados = 0;
    
                    for (i = 0; i < contador_fabricantes; i++) {
                         if (strcmp(fabricantes[i].uf_fabricante, estado_desejado) == 0) {
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do fabricante %d: \n", bicicletas[i].fabricante_id);
                              printf("Nome do fabricante: %s\n", fabricantes[i].nome_fabricante);
                              printf("Url do site do fabricante: %s\n", fabricantes[i].site_fabricante);
                              printf("Telefone do fabricante: %s\n", fabricantes[i].telefone_fabricante);
                              printf("Unidade Federativa do fabricante: %s\n", fabricantes[i].uf_fabricante);
            
                              for (j = 0; j < contador_bicicletas; j++) {
                                   if (bicicletas[j].fabricante_id == i) {
                                        printf("Identificador do produto: %d\n", bicicletas[i].bike_id);
                                        printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                                        printf("Peso do produto: %2.f \n", bicicletas[i].peso);
                                        printf("Valor da compra: %2.f\n", bicicletas[i].valor_compra);
                                        printf("Valor da venda: %2.f\n", bicicletas[i].valor_venda);
                                        printf("Valor do lucro: %2.f\n", bicicletas[i].valor_lucro);
                                        printf("Percentual de lucro: %2.f\n", bicicletas[i].percentual_lucro);
                                   
                                        produtos_encontrados++;
                                   }
                              }
                           
                              printf("\n");
                         }
                    }

                    if (produtos_encontrados == 0) {
                         printf("Não foi encontrado produto(s) neste estado!\n");
                    }

                    printf("\n\n");
                    break;
                    
               case 5:
                    system("cls");
                    printf("=========================================================================\n");
                    printf("Selecionada a opção 05 - Selecionar produtos de acordo com o fabricante\n");
                    printf("=========================================================================\n\n");

                    char marca_desejada[50];
                    produtos_encontrados = 0;

                    printf("Digite o nome da marca desejada: ");
                    scanf(" %[^\n]s", marca_desejada);

                    for (i = 0; i < contador_bicicletas; i++) {
                         if (strcmp(fabricantes[bicicletas[i].fabricante_id - 1].nome_fabricante, marca_desejada) == 0) {
                              printf("\nItem %d:", i + 1);
                              printf("\nIdentificador do produto: %d\n", bicicletas[i].bike_id);
                              printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                              printf("Peso do produto: %.2f \n", bicicletas[i].peso);
                              printf("Valor da compra: R$ %.2f\n", bicicletas[i].valor_compra);
                              printf("Valor da venda: R$ %.2f\n", bicicletas[i].valor_venda);
                              printf("Valor do lucro: R$ %.2f\n", bicicletas[i].valor_lucro);
                              printf("Percentual de lucro: %.2f%\n", bicicletas[i].percentual_lucro);
                              
                              printf("\n");
                              produtos_encontrados++;
                         }
                    }

                    if (produtos_encontrados == 0) {
                         printf("O fabricante informado não tem possue nenhum produto cadastrado!\nFabricante informado: %s\n\n", marca_desejada);
                    }

                    printf("\n\n");
                    break;
                    
               case 6:
                    system("cls");
                    printf("===============================================================\n");
                    printf("Selecionada a opção 06 - Encontrar produto de maior valor\n");
                    printf("===============================================================\n\n");
               
                    float maior_valor = bicicletas[0].valor_venda;
                    int estado_mais_caro_encontrado = 0;
               
                    for (i = 1; i < contador_bicicletas; i++) {
                         if (bicicletas[i].valor_venda > maior_valor) {
                              maior_valor = bicicletas[i].valor_venda;
                         }
                    }

                    for (i = 0; i < contador_bicicletas; i++) {
                         if (bicicletas[i].valor_venda == maior_valor) {
                              int fabricante_id = bicicletas[i].fabricante_id;
                              printf("Estado: %s\n", fabricantes[fabricante_id - 1].uf_fabricante);
                              estado_mais_caro_encontrado = 1;
                         }
                    }

                    if (estado_mais_caro_encontrado == 0) {
                         printf("Nenhum produto encontrado!\n");
                    }

                    printf("\n\n");
                    break;
                    
               case 7:
                    system("cls");
                    printf("===============================================================\n");
                    printf("Selecionada a opção 07 - Encontrar produto de menor valor\n");
                    printf("===============================================================\n\n");	
               
                    float menor_valor = bicicletas[0].valor_venda;
                    int fabricante_mais_barato_encontrado = 0;
               
                    for (i = 1; i < contador_bicicletas; i++) {
                         if (bicicletas[i].valor_venda < menor_valor) {
                              menor_valor = bicicletas[i].valor_venda;
                         }
                    }

                    for (i = 0; i < contador_bicicletas; i++) {
                         if (bicicletas[i].valor_venda == menor_valor) {
                              int fabricante_id = bicicletas[i].fabricante_id;
                              printf("Fabricante: %s\n", fabricantes[fabricante_id - 1].nome_fabricante);
                              fabricante_mais_barato_encontrado = 1;
                         }
                    }

                    if (fabricante_mais_barato_encontrado == 0) {
                         printf("Nenhum produto encontrado.\n");
                    }

                    printf("\n\n");
                    break;
                    
               case 8:
                    system("cls");
                    printf("==============================================================================\n");
                    printf("Selecionada a opção 08 - Relatório de produtos do menor para o maior valor\n");
                    printf("==============================================================================\n\n");

                    if (contador_bicicletas == 0) {
                         printf("Nenhum produto foi encontrado no sistema, por favor cadastre algum produto!");
                    } else {
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
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do produto: %d\n", bicicletas[i].bike_id);
                              printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                              printf("Peso do produto: %.2f \n", bicicletas[i].peso);
                              printf("Valor da compra: R$ %.2f\n", bicicletas[i].valor_compra);
                              printf("Valor da venda: R$ %.2f\n", bicicletas[i].valor_venda);
                              printf("Valor do lucro: R$ %.2f\n", bicicletas[i].valor_lucro);
                              printf("Percentual de lucro: %.2f%\n", bicicletas[i].percentual_lucro);
                              printf("\n");
                         }
                    }

                    printf("\n\n");
                    break;
                    
               case 9:
                    system("cls");
                    printf("==============================================================================\n");
                    printf("Selecionada a opção 09 - Relatório de produtos do maior para o menor valor\n");
                    printf("==============================================================================\n\n");

                    if (contador_bicicletas == 0) {
                         printf("Nenhum produto foi encontrado no sistema, por favor cadastre algum produto!");
                    } else {
                         for (i = 0; i < contador_bicicletas - 1; i++) {
                              for (j = 0; j < contador_bicicletas - i - 1; j++) {
                                   if (bicicletas[j].valor_venda < bicicletas[j + 1].valor_venda) {
                                        Bicicleta temp = bicicletas[j];
                                        bicicletas[j] = bicicletas[j + 1];
                                        bicicletas[j + 1] = temp;
                                   }
                              }
                         }

                         for (i = 0; i < contador_bicicletas; i++) {
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do produto: %d\n", bicicletas[i].bike_id);
                              printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                              printf("Peso do produto: %.2f \n", bicicletas[i].peso);
                              printf("Valor da compra: R$ %.2f\n", bicicletas[i].valor_compra);
                              printf("Valor da venda: R$ %.2f\n", bicicletas[i].valor_venda);
                              printf("Valor do lucro: R$ %.2f\n", bicicletas[i].valor_lucro);
                              printf("Percentual de lucro: %.2f%\n", bicicletas[i].percentual_lucro);
                              printf("\n");
                         }  
                    }
                    
                    printf("\n\n");
                    break;
                    
               case 10: 
                    system("cls");
                    printf("===========================================================================\n");
                    printf("Selecionada a opção 10 - Relatório de produtos de maior valor de lucro\n");
                    printf("===========================================================================\n\n");
                    
                    if (contador_bicicletas == 0) {
                         printf("Nenhum produto foi encontrado no sistema, por favor cadastre algum produto!");
                    } else {
                         // bubble sort novamente
                         for (i = 0; i < contador_bicicletas - 1; i++) {
                              for (j = 0; j < contador_bicicletas - i - 1; j++) {
                                   if (bicicletas[j].valor_lucro > bicicletas[j + 1].valor_lucro) {
                                        Bicicleta temp = bicicletas[j];
                                        bicicletas[j] = bicicletas[j + 1];
                                        bicicletas[j + 1] = temp;
                                   }
                              }
                         }
     
                         for (i = 0; i < contador_bicicletas; i++) {
                              printf("Item %d:", i + 1);
                              printf("\nIdentificador do produto: %d\n", bicicletas[i].bike_id);
                              printf("Descrição do produto: %s\n", bicicletas[i].descricao);
                              printf("Peso do produto: %.2f \n", bicicletas[i].peso);
                              printf("Valor da compra: R$ %.2f\n", bicicletas[i].valor_compra);
                              printf("Valor da venda: R$ %.2f\n", bicicletas[i].valor_venda);
                              printf("Valor do lucro: R$ %.2f\n", bicicletas[i].valor_lucro);
                              printf("Percentual de lucro: %.2f%\n", bicicletas[i].percentual_lucro);
                              printf("\n");
                         }
                    }

                    printf("\n\n");
                    break;
                    
               case 11:
                    printf("===============================================================\n");
                    printf("Selecionada a opção 11 - Encerrar programa\n");
                    printf("===============================================================\n\n");
                    break;
                    
               default: 
                    printf("===============================================================\n");
                    printf("Opção Inválida!\n");
                    printf("===============================================================\n\n");
                    printf("\n\n");
          }
     
     } while (menu_principal != 11);
     
	return 0;
}
