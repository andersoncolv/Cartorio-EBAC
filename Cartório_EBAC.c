#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis e strings
	char arquivo[40]; //cria a vari�vel arquivo, onde ser�o armazenadas as informa��es
	char cpf[11]; //cria a vari�vel CPF
	char nome[40]; //cria a vari�vel nome
	char sobrenome[40]; //cria a vari�vel sobrenome
	char cargo[40]; //cria a vari�vel cargo
	//fim da cria��o de vari�veis e strings
	
	setlocale(LC_ALL, "Portuguese"); //definindo local
	
	printf("Digite o CPF a ser cadastrado: "); //exibi��o na tela para o usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //strcpy copia os valores das string (por ex copia para a vari�vel arquivo o dado cpf)
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //fopen abre o arquivo, arquivo do tipo write, arquivo novo, sem dados inseridos
	fprintf(file,cpf); //salva o valor da vari�vel cpf dentro do arquivo file //fprintf = file printf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando "a" atualiza os dados do arquivo, (vai inserir mais informa��es no arquivo); comando "w" cria arquivo novo
	fprintf(file,", "); //comando que insere um "v�rgula-espa�o" entre as informa��es
	fclose(file); //comando para fechar o arquivo que foi consultado
	
	printf("Digite o nome a ser cadasatrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva o conte�do da vari�vel nome dentro do arquivo file
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salva o valor da vari�vel sobrenome no arquivo file
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause"); //aguarda comando do usu�rio, permitindo que ele leia o que est� na tela
}

int consulta() //fun��o respons�vel por consultar os usu�rios cadastrados
	{
	setlocale(LC_ALL, "Portuguese"); //definindo local
	
	char cpf[11]; //consulta ser� atrav�s do CPF cadastrado
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo e leia (r) o que est� armazenado na vari�vel cpf
	
	if (file == NULL) //se o arquivo n�o existir...
	{
		printf("Arquivo n�o localizado!\n"); //...informar que n�o foi localizado
	}
	
	while(fgets(conteudo, 100, file) != NULL) //fgets = v� buscar o arquivo "conte�do", e enqto ele tiver conteudo na string, n�o pare
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //comandos de exibi��o
		printf("%s", conteudo);							   //das informa��es	
		printf("\n\n");									   //ao usu�rio
	}
	fclose(file);
	system("pause"); //aguarda comando do usu�rio, permitindo que ele leia o que est� na tela
	}
	
int apagar() //fun��o respons�vel por deletar dados do banco
	{
	char cpf[11];
	printf("Digite o CPF a ser exclu�do: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo "file", capture a informa��o de CPF e a leia (r)
	
	if(file == NULL) //se o arquivo n�o for encontrado (usu�rio n�o cadastrado), informe:
		{
		fclose(file);
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
		}	
	else if(file != NULL) //se o arquivo foi encontrado, apague-o e informe:
		{
		fclose(file);
		printf("Usu�rio removido com sucesso! :)\n");
		system("pause");
		remove(cpf);
		}
	}
	
int main()
	{
	int opcao=0; //definindo vari�veis
	int laco=1; //criando a vari�vel x para poder usar no comando "for"
	
	for(laco=1;laco=1;) //ex: for(x=1;x=10;x++); (faz o c�d ser repetido da vez 1 at� a vez 10 // x++ acrescenta 1 a x
		{
		
		system("cls"); //comando para limpar a tela para o usu�rio
		
		setlocale(LC_ALL, "Portuguese"); //definindo local
	
		printf("~~ Cart�rio da EBAC ~~\n\n");
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1) Registrar nomes \n");
		printf("\t2) Consultar nomes \n");
		printf("\t3) Apagar nomes \n\n");
		printf("Digite aqui: "); //fim do menu

		scanf("%d", &opcao); //armazena a op��o do usu�rio 
	
		system("cls"); //limpa a tela
		
		switch(opcao) //definindo as op��es que o usu�rio pode escolher
			{
				case 1: //se o usu�rio digitar "1",
				registro(); //execute a fun��o "registro"
				break; //pare
				
				case 2: //se o usu�rio digitar "2",
				consulta(); //execute a fun��o "consulta"
				break; //pare
				
				case 3: //se o usu�rio digitar "3",
				apagar(); //execute a fun��o "apagar"
				break;
				
				default: //para qualquer outra situa��o, informe:
				printf("Esta op��o n�o est� dispon�vel :( \n");
				system("pause"); //aguarde o comando do usu�rio
				break; //pare
			}
		}	
	}	
