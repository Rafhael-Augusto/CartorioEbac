#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings (%s)

int registro(){
	
	char arquivo[40];
	char cpf[40]; // colchetes significa "string"
	char nome [40]; // tanto de variaveis -> "40"
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //copiar o arquivo "cpf" para "arquivo"
	
	FILE *file; // Cria um arquivo
	file = fopen(arquivo ,"W"); // cria o arquivo e "W" significa "Write" (escrever)
	fprintf(file, cpf); // Salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "A" significa atualizar oq ja tem
	fprintf(file,"CPF: %s",cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
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
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: %s", cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" signfica read
	
	if(file == NULL){
		printf("CPF não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\n Informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("CPF não encontrado\n");
	}
	if(file != NULL){
		printf("CPF removido com sucesso\n\n");
	}
	fclose(file);
	remove(cpf);
	
	system("pause");
}

int invalido(){
	printf("Opção não disponível, tente novamente\n\n");
	system("pause");
}

int main(){
	
	int opcao = 0;     //Definindo a variável
	int R = 1;
	
	setlocale(LC_ALL, "Portuguese");     //Definindo a linguagem
	
	for(R = 1; R == 1;){     // Se "R" = 1 e "R" for igual a 1
	
		system("cls"); //Limpar o prompt antes de continuar
		
		printf("<===> Cartório da EBAC <===>\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao);     //Scanear oque a pessoa disse e mudar "opcao" pro valor digitado e continuar script
		system("cls");           //Limpar o prompt
	
		switch(opcao){ 
			case 1:     // Abrir o "case"
			registro();
			break;     // Fechar o "case"
			
			case 2:    // Número depois de "case" é o número a ser comparado com "opcao"
			consulta();
			break;
			
			case 3:    // "Ex: if (case == 3) "
			deletar();
			break;
			
			default:
			invalido();
			break;
			
		}
	}
}
