#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()// fun��o reaponsavel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];	
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s" , cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o 'w' significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");		
		
}

int consultar()

{
    setlocale(LC_ALL, "Portuguese");// definindo a linguagem

	char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    { 
      printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar ()
{   
  char cpf[40];
  
  printf("Digite o CPF do usu�rio a ser deletado: ");
  scanf("%s", cpf);
  
  FILE *file;
  file = fopen(cpf,"r");
  	
  if(file == NULL)	
  {
  	fclose(file);
    printf("O usu�rio n�o se encontra no sistema!.\n");
   	system("pause");  	
  }
  
  else if (file!=NULL)
  {fclose(file);
  printf("O arquivo foi deletado!");
  remove(cpf);
 
  }
  
}


int main() 
{	
	int opcao=0; // Denifindo vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
		system("cls");// respons�vel por limpar a tela
	 		
	 setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	 
	 printf("### Cart�rio da EBAC ###\n\n");// inicio do menu
	 printf("Escolha a op��o deseja no menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");// fim do menu
  
      scanf("%d" , &opcao); // armazenando a escolha do usu�rio
	               	   
  	system("cls");
	                         
	 switch(opcao)// inicio da sele��o do menu
	    {
		
     	 case 1:
         registro();// chamda de fun��es
	     break;
		 
	  	 case 2:
	     consultar();
		 break;
		 
	 	 case 3:
	     deletar();
		 break;
		  		
	 	 default:
	 	 printf("Esta op��o n�o existe.\n");
		 system("pause");
		 break;
	     }// fim da sele��o
}
}

	

