#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings (%s)

int registro(){
	
	char arquivo[40];
	char cpf[40]; // colchetes significa "string"
	char nome [40]; // tanto de variaveis -> "40"
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //"%s" refere-se a string
	
	if (strcmp(cpf, "Cancelar") ==0 ){
		return 0;
	}
	
	strcpy(arquivo, cpf); //copiar o arquivo "cpf" para "arquivo"
	
	FILE *file; // Cria um arquivo
	file = fopen(arquivo ,"W"); // cria o arquivo e "W" significa "Write" (escrever)
	fprintf(file, cpf); // Salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "A" significa atualizar oq ja tem
	fprintf(file,"\nCPF: %s\n\n",cpf);
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome & sobrenome: %s", nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, "\n\n");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: %s", cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
}

int consulta(){
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n\n");
	printf("CPF procurado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" signfica read
	
	if(file == NULL){
		printf("CPF n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("CPF n�o encontrado\n");
	}
	if(file != NULL){
		printf("CPF removido com sucesso\n\n");
	}
	fclose(file);
	remove(cpf);
	
	system("pause");
}

int invalido(){
	printf("Op��o n�o dispon�vel, tente novamente\n\n");
	system("pause");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;     //Definindo a vari�vel
	int R = 1;
	char senhadigitada[10] = "a";
	
	system("cls");
	printf("<===> Cart�rio da EBAC <===>\n\n");
	printf("Login de administrador.\n\nDigite a sua senha para acessar as op��es: ");
	scanf("%s", senhadigitada);
	
	if(strcmp(senhadigitada, "admin") == 0){  // 0 significa true, outro numero seria false
		for(R = 1; R == 1;){     // Se "R" = 1 e "R" for igual a 1
	
			system("cls"); //Limpar o prompt antes de continuar
			
			printf("<===> Cart�rio da EBAC <===>\n\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");
		
			scanf("%d", &opcao);     //Scanear oque a pessoa disse e mudar "opcao" pro valor digitado e continuar script
			system("cls");           //Limpar o prompt
		
			switch(opcao){ 
				case 1:     // Abrir o "case"
				registro();
				break;     // Fechar o "case"
				
				case 2:    // N�mero depois de "case" � o n�mero a ser comparado com "opcao"
				consulta();
				break;
				
				case 3:    // "Ex: if (case == 3) "
				deletar();
				break;
				
				case 4:
				printf("Saindo...\n");
				return 0;
				break;
				
				default:
				invalido();
				break;			
			}
		}
	}
	
	else
		system("cls");
		printf("Senha incorreta\n\n");
		system("pause");
		main();
}
