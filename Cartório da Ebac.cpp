#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texo por região
#include <string.h> //biblioteca das strings
//As bibliotecas precisam estar no início do código para que o PC leia corretamente o código
	
int registro()//Função responsável por cadastrar os usuários
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //O "%s" refere-se às strings
	
	strcpy(arquivo, cpf); //É o que copia os valores das strings
	
	FILE *file; //Comando para criar o arquivo
	file = fopen(arquivo, "w"); //comando para criar o arquivo novo que é "w" de "write"
	fprintf(file, cpf); //Aqui salva o valor da varivável
	fclose(file); //Aqui fecha o file
	
	file = fopen(arquivo, "a"); //Abre um novo arquivo. Neste caso o "a" é de atualização
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
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - serve para que os acentos em português apareçam
	//Início das variáveis
	char cpf[40];
	char conteudo[200];
	//Fim das variáveis
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //O "r" significa que vai ler o arquivo - necessário pois é uma consulta
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, arquivo não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto, "fgets"=vai buscar o arquivo, busca o conteúdo, tamanho máximo é "200", busca no arquivo
	{
		printf("\nEssas são as informações do usuário: ");
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
	file = fopen(cpf,"r"); //Qual arquivo é para ser aberto? o CPF e o "r" é para o PC lero arquivo CPF
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da Ebac##\n\n"); //Início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\nOpção: \n\n");//Fim do menu
	
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao) //Início do menu
		{
			case 1:
			registro(); //Aqui chama as funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}
	}
}
