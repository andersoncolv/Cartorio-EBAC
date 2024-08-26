#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis e strings
	char arquivo[40]; //cria a variável arquivo, onde serão armazenadas as informações
	char cpf[11]; //cria a variável CPF
	char nome[40]; //cria a variável nome
	char sobrenome[40]; //cria a variável sobrenome
	char cargo[40]; //cria a variável cargo
	//fim da criação de variáveis e strings
	
	setlocale(LC_ALL, "Portuguese"); //definindo local
	
	printf("Digite o CPF a ser cadastrado: "); //exibição na tela para o usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //strcpy copia os valores das string (por ex copia para a variável arquivo o dado cpf)
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //fopen abre o arquivo, arquivo do tipo write, arquivo novo, sem dados inseridos
	fprintf(file,cpf); //salva o valor da variável cpf dentro do arquivo file //fprintf = file printf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando "a" atualiza os dados do arquivo, (vai inserir mais informações no arquivo); comando "w" cria arquivo novo
	fprintf(file,", "); //comando que insere um "vírgula-espaço" entre as informações
	fclose(file); //comando para fechar o arquivo que foi consultado
	
	printf("Digite o nome a ser cadasatrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva o conteúdo da variável nome dentro do arquivo file
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salva o valor da variável sobrenome no arquivo file
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause"); //aguarda comando do usuário, permitindo que ele leia o que está na tela
}

int consulta() //função responsável por consultar os usuários cadastrados
	{
	setlocale(LC_ALL, "Portuguese"); //definindo local
	
	char cpf[11]; //consulta será através do CPF cadastrado
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo e leia (r) o que está armazenado na variável cpf
	
	if (file == NULL) //se o arquivo não existir...
	{
		printf("Arquivo não localizado!\n"); //...informar que não foi localizado
	}
	
	while(fgets(conteudo, 100, file) != NULL) //fgets = vá buscar o arquivo "conteúdo", e enqto ele tiver conteudo na string, não pare
	{
		printf("\nEssas são as informações do usuário: "); //comandos de exibição
		printf("%s", conteudo);							   //das informações	
		printf("\n\n");									   //ao usuário
	}
	fclose(file);
	system("pause"); //aguarda comando do usuário, permitindo que ele leia o que está na tela
	}
	
int apagar() //função responsável por deletar dados do banco
	{
	char cpf[11];
	printf("Digite o CPF a ser excluído: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo "file", capture a informação de CPF e a leia (r)
	
	if(file == NULL) //se o arquivo não for encontrado (usuário não cadastrado), informe:
		{
		fclose(file);
		printf("Usuário não encontrado!\n");
		system("pause");
		}	
	else if(file != NULL) //se o arquivo foi encontrado, apague-o e informe:
		{
		fclose(file);
		printf("Usuário removido com sucesso! :)\n");
		system("pause");
		remove(cpf);
		}
	}
	
int main()
	{
	int opcao=0; //definindo variáveis
	int laco=1; //criando a variável x para poder usar no comando "for"
	
	for(laco=1;laco=1;) //ex: for(x=1;x=10;x++); (faz o cód ser repetido da vez 1 até a vez 10 // x++ acrescenta 1 a x
		{
		
		system("cls"); //comando para limpar a tela para o usuário
		
		setlocale(LC_ALL, "Portuguese"); //definindo local
	
		printf("~~ Cartório da EBAC ~~\n\n");
		printf("Escolha a opção desejada:\n\n");
		printf("\t1) Registrar nomes \n");
		printf("\t2) Consultar nomes \n");
		printf("\t3) Apagar nomes \n\n");
		printf("Digite aqui: "); //fim do menu

		scanf("%d", &opcao); //armazena a opção do usuário 
	
		system("cls"); //limpa a tela
		
		switch(opcao) //definindo as opções que o usuário pode escolher
			{
				case 1: //se o usuário digitar "1",
				registro(); //execute a função "registro"
				break; //pare
				
				case 2: //se o usuário digitar "2",
				consulta(); //execute a função "consulta"
				break; //pare
				
				case 3: //se o usuário digitar "3",
				apagar(); //execute a função "apagar"
				break;
				
				default: //para qualquer outra situação, informe:
				printf("Esta opção não está disponível :( \n");
				system("pause"); //aguarde o comando do usuário
				break; //pare
			}
		}	
	}	
