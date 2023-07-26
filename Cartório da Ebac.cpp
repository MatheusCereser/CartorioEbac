#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texo por regi�o
#include <string.h> //biblioteca das strings
//As bibliotecas precisam estar no in�cio do c�digo para que o PC leia corretamente o c�digo
	
int registro()//Fun��o respons�vel por cadastrar os usu�rios
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //O "%s" refere-se �s strings
	
	strcpy(arquivo, cpf); //� o que copia os valores das strings
	
	FILE *file; //Comando para criar o arquivo
	file = fopen(arquivo, "w"); //comando para criar o arquivo novo que � "w" de "write"
	fprintf(file, cpf); //Aqui salva o valor da variv�vel
	fclose(file); //Aqui fecha o file
	
	file = fopen(arquivo, "a"); //Abre um novo arquivo. Neste caso o "a" � de atualiza��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //Abre um novo arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //Abre um novo arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system("pause");
		
}

	int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - serve para que os acentos em portugu�s apare�am
	//In�cio das vari�veis
	char cpf[40];
	char conteudo[200];
	//Fim das vari�veis
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //O "r" significa que vai ler o arquivo - necess�rio pois � uma consulta
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto, "fgets"=vai buscar o arquivo, busca o conte�do, tamanho m�ximo � "200", busca no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
	int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Qual arquivo � para ser aberto? o CPF e o "r" � para o PC lero arquivo CPF
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da Ebac##\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\nOp��o: \n\n");//Fim do menu
	
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao) //In�cio do menu
		{
			case 1:
			registro(); //Aqui chama as fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	}
}
