#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Definindo uma estrutura para representar os ingressos
typedef struct {
    int id;
    char tipo[50];
    double preco;
} Ingresso;
// Definindo estrutura para representar o cliente em registro
typedef struct {
    char nome[50];
    char cpf[12];
    int numeroBilhete;
} Cliente;

// definindo estrutura para pesquisa
typedef struct {
	int gostou;
	char proxima[3];
}Pesquisa;


// Função para exibir informações sobre os ingressos disponíveis
void mostrarIngressos(Ingresso ingressos[], int tamanho) {
    printf("Ingressos disponiveis:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d\n", ingressos[i].id);
        printf("Tipo: %s\n", ingressos[i].tipo);
        printf("Preco: R$%.2lf\n", ingressos[i].preco);
        printf("\n");
    }
}

// Função para vender um ingresso
void venderIngresso(Ingresso ingressos[], int tamanho) {
    int id;
    printf("Digite o ID do ingresso que deseja comprar: ");
    scanf("%d", &id);

    // Verifica se o ID é válido
    if (id >= 1 && id <= tamanho) {
        // Cadastro do cliente e registro da compra
        srand(time(NULL)); // função para que o número gerado seja aleatório
        Cliente cliente;
        FILE *arquivo;

        // Abre o arquivo de bilhetes em modo de escrita
        arquivo = fopen("bilhetes.csv", "a+");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo de bilhetes.\n");
            return;
        }

        // Solicita o nome do cliente
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]s", cliente.nome);

        // Solicita o CPF do cliente
        printf("Digite o CPF do cliente: ");
        scanf("%s", cliente.cpf);

        // Gera um número de bilhete aleatório
        cliente.numeroBilhete = rand() % 1000;

        // Grava os dados do cliente e o número de bilhete no arquivo
        fprintf(arquivo, "Nome: %s\n", cliente.nome);
        fprintf(arquivo, "CPF: %s\n", cliente.cpf);
        fprintf(arquivo, "Número de Bilhete: %d\n\n", cliente.numeroBilhete);

        // Fecha o arquivo
        fclose(arquivo);

        printf("Bilhete registrado com sucesso!\n");
        printf("Seu numero de bilhete e: %d\n", cliente.numeroBilhete);
        printf("Ingresso comprado com sucesso:\n");
        printf("Tipo: %s\n", ingressos[id - 1].tipo);
        printf("Preco: R$%.2lf\n", ingressos[id - 1].preco);
    } else {
        printf("ID de ingresso invalido.\n");
    }
}

// função para mostar a pesquisa

void realizarPesquisa(Pesquisa *resposta) {
    FILE *arquivo;

    // Abre o arquivo de pesquisa em modo de escrita "a+"
    arquivo = fopen("pesquisa.csv", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pesquisa.\n");
        return;
    }
	do {
	
    printf("De 1 a 10, quanto gostou da exposicao?\n ");
    scanf("%d", &(resposta->gostou));
    
	if (resposta->gostou<1 || resposta->gostou> 10);{
		printf("Valor fora do intervalo permitido (1 a 10). Tente novamente.\n");
	}
}while (resposta->gostou < 1 || resposta->gostou > 10);
    printf("A proxima exposicao eh daqui a 5 dias, podera comparecer? (Sim ou Nao):\n ");
    scanf("%s", resposta->proxima);

    // Escreve os dados da pesquisa no arquivo
    fprintf(arquivo, "%d,%s\n", resposta->gostou, resposta->proxima);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Pesquisa registrada com sucesso.\n");
}


int main(){
    // Defina seus ingressos com tipos e preços
    Ingresso ingressos[] = {
        {1, "Ingresso Normal", 10.0},
        {2, "Ingresso Estudante", 7.0},
        {3, "Ingresso Crianca", 5.0},
    };

    int tamanho = sizeof(ingressos) / sizeof(ingressos[0]); 
    int escolha, sala;
    
     	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n*         Ola, bem vindo a bilheteria do museu!                         *\n");
        printf("* Estamos apresentando uma fantastica viagem no mundo pre-historico     *\n");
        printf("*         nos dias 18-19/10/2023, venha conferir!                       *\n");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n \t\t Escolha uma das opcoes abaixo \n\n");
        printf("\t\t\t  %c%c%c%c\n \n", 25,25,25,25);
    
    do {
    	
    	printf(" %c 1. Mostrar Ingressos Disponiveis\n", 175);
        printf(" %c 2. Comprar Ingresso\n", 175);
        printf(" %c 3. Iniciar excurcao! \n", 175);
        printf(" %c 4. Pesquisa de satistacao\n", 175);
        printf(" %c 5. Sair\n", 175);
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
			system("cls");
        switch (escolha) {
            case 1:
                mostrarIngressos(ingressos, tamanho);
                break;
            case 2:
                venderIngresso(ingressos, tamanho);
                break;
            case 3:
            	printf(" %c Escolha a sala que deseja assistir! \n", 175);
            	printf(" %c Excurcoes disponiveis:\n", 175);
            	printf(" %c ADICIONAR OPCAO 1\n", 175);
            	printf(" %c ADICIONAR OPCAO 2\n", 175);
            	printf(" %c ADICIONAR OPCAO 3\n", 175);
            	printf(" %c ADICIONAR OPCAO 4\n", 175);
            	printf("%c 5. Voltar ao menu principal!", 175);
            	scanf("%d", &sala);
            	system("cls");
            	switch (sala){
            		case 1:
            		break;
					case 2:
					break;
					case 3:
					break;
					case 4:
					break;
					case 5:
						printf("Voltar ao menu prncipal!\n");
						break;
					default:
                printf("Opcao invalida. Tente novamente.\n");	
				}
				break;
		    case 4:{	
                Pesquisa resposta;
                realizarPesquisa(&resposta);
                break;
            case 5:
            	printf("Obrigado por usar o sistema de bilheteria.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
	} while (escolha != 5);
    return 0;
}

