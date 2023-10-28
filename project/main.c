#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include <time.h>


bool ModoPCD = false;
char NomeAudio[] = "";
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
    TocarAudio("audios\\salas.wav");
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
        TocarAudio("audios\\cliente.wav");
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]s", cliente.nome);

        // Solicita o CPF do cliente
        TocarAudio("audios\\CPF.wav");
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
        TocarAudio("audios\\IDInvalido.wav");
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
        TocarAudio("audios\\Gostou.wav");
        printf("De 1 a 10, quanto gostou da exposicao?\n ");
        scanf("%d", &(resposta->gostou));

        if (resposta->gostou < 1 || resposta->gostou > 10) {
            TocarAudio("audios\\ForaValor.wav");
            printf("Valor fora do intervalo permitido (1 a 10). Tente novamente.\n");
        }
    } while (resposta->gostou < 1 || resposta->gostou > 10);
    TocarAudio("audios\\ProxExp.wav");
    printf("A proxima exposicao eh daqui a 5 dias, podera comparecer? (Sim ou Nao):\n ");
    scanf("%s", resposta->proxima);

    // Escreve os dados da pesquisa no arquivo
    fprintf(arquivo, "%d,%s\n", resposta->gostou, resposta->proxima);

    // Fecha o arquivo
    fclose(arquivo);
    TocarAudio("audios\\PesqSucesso.wav");
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

     	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n *         Ola, bem vindo a bilheteria do museu PIM!     *\n");
        printf(" *Classificacao: Livre \t                                 *\n");
        printf(" *                                                       *\n");
        printf(" *                 EM CARTAZ:                            *\n");
        printf(" * 150 anos de Santos Dumont.                            *\n");
        printf(" * 100 Anos da semana da arte moderna.                   *\n");
        printf(" * Jogos olimpicos de Paris 2024.                        *\n");
        printf(" * Exploracao espacial futuristica.                      *\n ");
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n \t\t Escolha uma das opcoes abaixo \n\n");
        printf("\t\t\t  %c%c%c%c\n \n", 25,25,25,25);

    do {
        TocarAudio("audios\\Aperte.wav");
    	printf(" %c 1. Mostrar Ingressos Disponiveis\n", 175);
        printf(" %c 2. Comprar Ingresso\n", 175);
        printf(" %c 3. Iniciar excursao! \n", 175);
        printf(" %c 4. Pesquisa de satisfacao\n", 175);
        printf(" %c 5. Sair\n", 175);
        printf(" %c 6. Ligar/Desligar modo PCD\n", 175);
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
            	do {
                TocarAudio("audios\\Salas.wav");
            	printf(" %c Escolha a sala que deseja assistir! \n\n", 175);
            	printf(" %c Excurcoes disponiveis:\n\n", 175);
            	printf(" %c Sala 1: 100 Anos da semana da arte moderna. \n", 175);
            	printf(" %c Sala 2: 150 anos de Santos Dumont.  \n", 175);
            	printf(" %c Sala 3: Jogos olimpicos de Paris 2024. \n", 175);
            	printf(" %c Sala 4: Exploracao espacial futuristica. \n", 175);
            	printf(" %c 5: Voltar ao menu principal!\n", 175);
            	scanf("%d", &sala);
            	system("cls");
            	switch (sala){
            		case 1:
            		    TocarAudio("audios\\sala1.wav");
            			printf("\nApresentacao sobre 100 Anos da semana da arte moderna. \n\n ");
            		break;
					case 2:
					    TocarAudio("audios\\sala2.wav");
						printf("\nApresentacao sobre 150 anos de Santos Dumont. \n\n");
					break;
					case 3:
						printf("\nApresentacao sobre Jogos olimpicos de Paris 2024. \n\n ");
					break;
					case 4:
						printf("\nApresentacao sobre Exploracao espacial futuristica. \n\n");
					break;
					case 5:
						printf("Voltar ao menu principal!\n");
						break;
					default:
                printf("Opcao invalida. Tente novamente.\n");
                TocarAudio("audios\\invalida.wav");
					}
				} while (sala !=5);
				break;
		    case 4:{
                Pesquisa resposta;
                realizarPesquisa(&resposta);
                break;
            case 5:
            	printf("Obrigado por usar o sistema de bilheteria.\n");
            	TocarAudio("audios\\obrigado.wav");
                break;
            case 6:
                ModoPCD = !ModoPCD;
            	printf("Modo PCD esta: %s\n", ModoPCD ? "Ativado" : "Desativado");
                TocarAudio("audios\\ativado.wav");
                main();
            default:
                printf("Opcao invalida. Tente novamente.\n");
                TocarAudio("audios\\invalida.wav");
                break;
        }
    }
	} while (escolha != 6);
    return 0;
}

int TocarAudio(NomeAudio){
    if (ModoPCD == true){ // Checa se a o modo PCD está ligado, caso sim, o áudio toca
        PlaySound(NomeAudio, NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    }
    else // Caso contrário, nenhum áudio é tocado
    return 0;
}
