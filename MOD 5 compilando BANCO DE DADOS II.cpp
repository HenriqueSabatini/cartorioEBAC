#include <stdio.h> //BIBLIOTECA DE COMUNICAÇÃO COM O USUARIO
#include <stdlib.h> // BIBLIOTECA DE ALOCAÇÃO DE ESPAÇO EM MEMORIA
#include <locale.h> // BIBLIOTECA DE IDENTIFICAÇÃO DE TEXTO POR REGIÃO (BRASIL) ACENTOS E ESCRITA
#include <string.h> // BIBLIOTECA RESPONSAVEL POR CUIDAR DAS STRINGS

int registro() // função segundaria (responsavel por cadastrar o usuario no sistema
{
	// INICIO CRIAÇÃO CONJUNTO DE VARIAVEL = STRINGS
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// FIM CRIAÇÃO CONJUNTO DE VARIAVEL = STRINGS
		
	printf("Digite o seu CPF: "); // COLETANDO INFORMAÇÃOES DO USUARIO
	scanf("%s", cpf); // "%s" ARMAZENA STRING / Tudo depois disso vai ser salvo como string até 40 caracteries
	
	strcpy(arquivo, cpf); // aqui o que for digitado como CPF vai para o arquivo
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo / "w" é write = ESCREVER
	fprintf(file,"\nCPF: ");
	fprintf(file, cpf); //salvo o valor da variavel			
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a" ); // "a" adicionar = atualizar o arquivo
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a" );
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a" );
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta() // função segundaria
{
	setlocale(LC_ALL, "Portuguese"); // COMANDO QUE VAI ENTENDER OS ACENTOS DA LINGUA
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = 	fopen(cpf, "r"); // "r" = Read = Ler o arquivo
	
	if(file == NULL)
	{
		printf("Não localizado!\n");
	}
	printf("\nEssas são as informações do usuario: ");
	
	while(fgets(conteudo, 200, file) != NULL)
	{		
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	system("pause");	
}

int deletar() // função segundaria
{
	
	char cpf[40];
	
	printf("Qual CPF deseja deletar? ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" = Read = Ler o arquivo
	
	if(file == NULL)
	{
		printf("Usuario não existe!\n");
		system("pause");
	}
	
		
} 

int main() // Função PRINCIPAL
{
	 
	 int opcao = 0; // Definindo as variaveis
	 int laco=1;
	 
	 for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // COMANDO QUE VAI INTENDER OS ACENTOS DA LINGUA
	
	
		printf("### Cartório Sabatinis ###\n\n"); // Inicio do menu
		printf("Escolha a opção no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); // Fim do menu
	
	 	scanf("%d", &opcao); // armanezando a escolha do usuario
	 
		system("cls"); //LIMPA TELA
		
		switch(opcao) //INICIO DO MENU
		{
			case 1:
			registro(); //CHAMADA DE FUNÇOES
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Não Existe!\n");
			system("pause");
			break;	
				
			
		}
	
		
	}
} 
