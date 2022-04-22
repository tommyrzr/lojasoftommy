#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

//Variaveis globais
int i=0, j, opcao, sair, limite, qtdanuncios,status=0,l=0;
int c = 0, limiteclin, qtdclientes, limitevend, qtdvendedor, escolha, sair;

//Estrutura para pedir os dados do cliente
struct cadastro_de_cliente{
    char nome [100];
    char datanasci [10];
    char email [100];
    int senha;
    char telefone [13];
    char sexo [10];
    int cpf;
    char rua [100];
    int numero;
    char bairro [100];
    char cidade [50];
    char sigla_estado [3];
    long int cep ;
}cadastrocli[10];
//Estrutura para pedir os dados do vendedor
struct cadastro_de_vendedor{
    char usuario [20];
    char nome [100];
    char datanasci [10];
    char email [100];
    int senha;
    char telefone [13];
    char sexo [10];
    int cpf;
    char rua [100];
    int numero;
    char bairro [100];
    char cidade [50];
    char sigla_estado [3];
    long int cep;
    int aval;
}cadastroven[10];
//Estrutura para cadastrar anuncio
struct cadastro_anuncio {
		char nome_vendedor[20];
		char nomeproduto[20];
		char datapub[9];
		char condicaoproduto[8];
		char telefone[13];
		float preco;
		char descricao[500];
	}anunciar[5];
//Estrutura para localizar anuncio
struct buscar_anuncio{
	char localizaranuncio[20];
	int publiencontradas;
	int numerodoanuncio;
}localizar;
// Estrutura para avaliar o vendedor
struct avaliacao{
		char nomeusuario[20];
		int quantidadeavaliacao;
		int notavendedor;
		float mediavendedor;
	} nota;

//Funções
void cadastro_de_vendedor(); //Cadastra o vendedor no sistema
void cadastro_de_cliente(); //Cadastra o cliente no sistema
void cadastro_de_anuncio(); //Cadastra o anuncio no sistema
void verificacao_de_login_cliente(); // Faz login do cliente no sistema
void verificacao_de_login_vendedor(); // Faz login do vendedor no sistema
void localanuncio(); // Localiza o anuncio no sistema
void excluir_anuncio(); // Exclui o anuncio do sistema
void alteraranuncio(); // Altera dados basicos do anuncio do sistema
void confirmar_compra(); // Confirma a compra após ser vendida fora do sistema
void avaliacaovendedor(); // Função para deixar o cliente avaliar o vendedor após a compra.

int main (){

	int escolher,escolher2,escolher3;

	setlocale(LC_ALL,"Portuguese");


	while(1){
		escolher=escolher2=escolher3=0;
		status=0;
		printf("___________________________________- Bem vindo a loja -___________________________________\n");
		printf("Se você é cliente Digite 1 -- Se você é vendedor Digite 2 -- Caso nao tenho conta Digite 3\n \n");
		printf("Qual é sua opção: ");
		scanf("%d", &escolher);
		if(escolher==1){
			verificacao_de_login_cliente();
			system("cls");
			if(status==1){
				while(escolher3!=3){
					printf("Qual opção você deseja escolher? \n1) Buscar Anuncio; \n2) Avaliar Vendedor; \n3) Voltar para o inicio; \nDigite: ");
					scanf("%d", &escolher3);
					if(escolher3==1){
						system("cls");
						localanuncio();
						system("cls");
						continue;
					}
					else if(escolher3==2){
						system("cls");
						avaliacaovendedor();
						system("cls");
						continue;
					}
					else if(escolher3==3){
						system("cls");
						status==0;
						break;
					}
				}
			}
			}
		else if(escolher==2){
			verificacao_de_login_vendedor();
			system("cls");
			if(status==1){
				while(escolher3!=5){
					printf("Qual opção você deseja escolher? \n1) Cadastrar anuncio; \n2) Alterar anuncio; \n3) Excluir anuncio; \n4) Confirmar compra; \n5) Voltar para o inicio; \nDigite: ");
					scanf("%d", &escolher3);
					if(escolher3==1){
						system("cls");
						cadastro_de_anuncio();
						system("cls");
					}
					else if(escolher3==2){
						system("cls");
						alteraranuncio();
						system("cls");
					}
					else if(escolher3==3){
						system("cls");
						excluir_anuncio();
						system("cls");
					}
					else if(escolher3==4){
						system("cls");
						confirmar_compra();
						system("cls");
					}
					else if(escolher3==5){
						system("cls");
						break;
					}
				}
			}
		}
		else if(escolher==3){
			printf("Se você deseja ser vendedor Digite 1 -- Se você deseja ser cliente  Digite 2 ? \n");
			scanf("%d", &escolher2);
			if(escolher2==1){
				cadastro_de_vendedor();
				system("cls");
				continue;
			}
			else if(escolher2==2){
				cadastro_de_cliente();
				system("cls");
				continue;
			}
		}

	}

	return 0;
}

void cadastro_de_cliente(){
	while(1){
		printf("\n");
		printf("__________________________Entre com seus dados para fazer cadastro__________________________ \n \n \n");
        printf("\n");

		printf("Digite o seu nome: \n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].nome,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Digite a data do seu nascimento, (Ex 03/05/2001)\n");
		printf("Digite (Maximo de 10 caracteres):\n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].datanasci,10,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu email: \n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].email,100,stdin);

		printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Crie uma senha numerica: \n");
		printf("Digite (Maximo de 21 caracteres):\n");
		scanf("%d", &cadastrocli[qtdclientes].senha);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu telefone\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].telefone,11,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Digite o seu genero Masculino ou Feminino\n");
		printf("Digite (Maximo de 10 caracteres):\n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].sexo,10,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu cpf\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		scanf("%d", &cadastrocli[qtdclientes].cpf);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome da sua rua: \n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].rua,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o numero da sua casa\n");
		printf("Digite (Maximo de 5 caracteres):\n");
		scanf("%d", &cadastrocli[qtdclientes].numero);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome do seu bairro: \n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].bairro,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome da sua cidade: \n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].cidade,50,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite a sigla do seu estado\n");
		printf("Digite (Maximo de 3 caracteres):\n");
		fflush(stdin);
		fgets(cadastrocli[qtdclientes].sigla_estado,3,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu cep\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		scanf("%d",&cadastrocli[qtdclientes].cep);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Conta cadastrado com sucesso! \n\n");
		limiteclin++;
		qtdclientes++;
		printf("Deseja cadastrar outro conta ? Se for SIM Digite 1 -- Se for NAO qualquer outro numero: ");
		scanf("%d", &sair);
		if(sair == 1){
			continue;
		}
		else if(limiteclin > 10){
			printf("Você preencheu o limite maximo de clientes. Por favor exclua algum antes de cadastrar um novo usuario. /n");
			break;
		}
		else{
			break;
		}

    }
		qtdclientes++;
}

void cadastro_de_vendedor(){
	while(1){
		printf("\n");
		printf("__________________________Entre com seus dados para fazer cadastro__________________________ \n \n \n");
        printf("\n");

		printf("Digite o seu usuario\n");
		printf("Digite (Maximo de 20 caracteres):\n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].usuario,20,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu nome: \n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].nome,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Digite oa data do seu nascimento, (Ex 03/05/2001)\n");
		printf("Digite (Maximo de 10 caracteres):\n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].datanasci,10,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu email: \n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].email,100,stdin);

		printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Crie uma senha numerica\n");
		printf("Digite (Maximo de 21 caracteres):\n");
		scanf("%d", &cadastroven[qtdvendedor].senha);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu telefone\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].telefone,11,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

        printf("Digite o seu genero Masculino ou Feminino\n");
		printf("Digite (Maximo de 10 caracteres):\n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].sexo,10,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu cpf\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		scanf("%d", &cadastroven[qtdvendedor].cpf);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome da sua rua: \n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].rua,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o numero da sua casa\n");
		printf("Digite (Maximo de 5 caracteres):\n");
		scanf("%d", &cadastroven[qtdvendedor].numero);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome do seu bairro: \n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].bairro,100,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o nome da sua cidade: \n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].cidade,50,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite a sigla do seu estado\n");
		printf("Digite (Maximo de 3 caracteres):\n");
		fflush(stdin);
		fgets(cadastroven[qtdvendedor].sigla_estado,3,stdin);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Digite o seu cep\n");
		printf("Digite (Maximo de 11 caracteres):\n");
		scanf("%d", &cadastroven[qtdvendedor].cep);

        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("\n");

		printf("Conta de vendedor cadastrado com sucesso! \n\n");
		qtdvendedor++;
		limitevend++;
		printf("Deseja cadastrar outro conta ? Se for SIM Digite 1 -- Se for NAO qualquer outro numero: ");
		scanf("%d", &sair);
		if(sair == 1){
			continue;
		}
		else if(limitevend > 10){
			printf("Você preencheu o limite maximo de vendedores. Por favor exclua algum antes de cadastrar um novo vendedor. \n");
			break;
		}
		else{
			break;
		}

    }
		qtdvendedor++;
}

void cadastro_de_anuncio() {
	while(1){

		strcpy(anunciar[qtdanuncios].nome_vendedor,cadastroven[qtdanuncios].usuario);

		printf("__________________________Cadastre o seu produto__________________________ \n \n \n");

		printf("Informe aqui o que você deseja vender em poucas palavras. Ex: Celular, tv... \n");
		printf("Digite (Maximo de 15 caracteres): \n");
		fflush(stdin);
		fgets(anunciar[qtdanuncios].nomeproduto,20,stdin);


		printf("Informe aqui o seu numero de telefone: \n");
		fflush(stdin);
		fgets(anunciar[qtdanuncios].telefone,13,stdin);

		printf("Informe o valor que deseja vender o produto R$: \n");
		fflush(stdin);
		scanf("%f", &anunciar[qtdanuncios].preco);

		while(1){
			printf("Informe as condições do produto. \n1 - Novo; \n2 - Usado \nDigite o número:  ");
			scanf("%d", &opcao);
			if(opcao==1){
				strcpy(anunciar[qtdanuncios].condicaoproduto,"Novo");
					break;
			}
			else if(opcao==2){
				strcpy(anunciar[qtdanuncios].condicaoproduto,"Usado");
				break;
			}
			else{
				printf("Não entendi a sua opção. Digite novamente. \n");
				continue;
			}
		}
		printf("Escreva uma breve descrição sobre o seu produto (MAX 500 CARACTERES) \nDigite: ");
		fflush(stdin);
		fgets(anunciar[qtdanuncios].descricao,500,stdin);


		_strdate(anunciar[qtdanuncios].datapub);

		printf("Anuncio cadastrado com sucesso! \n\n");
		qtdanuncios++;
		printf("Deseja cadastrar outro anuncio Digite 1  --  Qualquer outro numero para não: ");
		scanf("%d", &sair);
		if(sair==1){
			continue;
		}
		else{
			break;
		}


}

}

void verificacao_de_login_cliente(){
        while(1){
        	char email1[100];
       		int restemail=0, restsenha=0,senha1=0;
        	printf("\n");
        	printf("Digite o seu email: \n");
			fflush(stdin);
			fgets(email1,100,stdin);

        	printf("\n");
        	printf("-------------------------------------------------------------\n");
        	printf("\n");

        	printf("Digite sua senha: \n");
			scanf("%d", &senha1);
        	printf("\n");
        	for(i=0;i<10;i++){
        		restemail = strcmp(cadastrocli[i].email, email1);
        		if(senha1==cadastrocli[i].senha && restemail==0){
        			restsenha = 0;
        			break;
				}
			}

        	if(restemail == 0)
            	{
            	printf("Email corresponde ao cadastro feito \n\n");
            	printf("Agora vamos verificar sua senha \n\n");
            	if(restsenha == 0)
                	{
                	printf("Senha corresponde ao cadastro feito \n\n");
                	printf("Tudo corresponde ao cadastro, aguarde e voce sera redirecionado \n\n");
                	status=1;
                	break;
                	}
            	else if(restsenha != 0)
                	{
                	printf("Senha nao corresponde ao cadastro feito \n");
                	break;
                	}
            	}
        	else if(restemail != 0)
            	{
            	printf("Email nao corresponde com o cadastrado \n");
            	break;
            	}
    }
}

void verificacao_de_login_vendedor(){
        while(1){
        	char email1[100];
			int restemail=0, restsenha=0,senha1=0;
        	printf("\n");
        	printf("Digite o seu email: \n");
        	fflush(stdin);
        	fgets(email1,100,stdin);

        	printf("\n");
        	printf("-------------------------------------------------------------\n");
        	printf("\n");

        	printf("Digite a sua senha: \n");
        	scanf("%d", &senha1);
        	printf("\n");

        	for(i=0;i<10;i++){
        		restemail = strcmp(cadastroven[i].email, email1);
        		if(senha1==cadastroven[i].senha){
        			restsenha = 0;
					break;
				}
			}
    		if(restemail == 0)
       		{
        	printf("Email corresponde ao cadastro feito \n\n");
        	printf("Agora vamos verificar sua senha \n\n");
       			if(restsenha == 0)
            		{
            		printf("Senha corresponde ao cadastro feito \n\n");
            		printf("Tudo corresponde ao cadastro, aguarde e voce sera dedirecionado \n\n");
            		status=1;
            		break;
            	}
        		else if(restsenha != 0)
            	{
            		printf("Senha nao corresponde ao cadastro feito \n");
            		break;
            	}
       		}
    		else if(restemail != 0)
        	{
       			printf("Email nao corresponde com o cadastrado \n");
       			break;
        	}
        }
}

void alteraranuncio(){
	while(1){
		j=0;
		opcao=0;
		printf("Deseja voltar Digite 1 -- Para continuar basta digitar outro numero: \n");
		scanf("%d", &c);
		if(c==1){
			break;
		}
		printf("Digite qual anuncio você deseja alterar: \n");
		for(i=0;i<=qtdanuncios;i++){
			if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
				printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
			}
		}
		printf("\nDigite: ");
		scanf("%d", &j);
		printf("Digite qual opção você deseja alterar. \n1 - Preço; \n2 - Descrição. \nDigite: ");
		scanf("%d",&opcao);
		if(opcao==1){
			printf("Digite o novo preço R$: ");
			scanf("%f", &anunciar[j].preco);
			for(i=0;i<=qtdanuncios;i++){
				if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
					printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
			}
		}
			sleep(5);
			break;
		}
		else if(opcao==2){
			printf("Digite a nova descrição. Até 500 caracteres: ");
			fflush(stdin);
			fgets(anunciar[j].descricao,500,stdin);
			for(i=0;i<=qtdanuncios;i++){
				if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
					printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
			}
		}
			sleep(5);
			break;
		}
		else{
			("Não entendi a sua opção \n");
			continue;
		}
	}

}

void excluir_anuncio(){

	while(1){
		j=0;
		opcao=0;
		printf("Deseja voltar Digite 1 -- Para continuar basta digitar outro numero: \n");
		scanf("%d", &c);
		if(c==1){
			break;
		}
		printf("Digite qual anuncio você deseja excluir: \n");
		for(i=0;i<=qtdanuncios;i++){
			if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
				printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
				j++;
			}
		}
		if(j==0){
			printf("Nenhum Anuncio encontrado. \n");
			break;
		}
		printf("\n \n \nDigite: ");
		scanf("%d", &opcao);
		printf("Tem certeza que deseja excluir o anuncio? 1 - sim, 2 - não : ");
		scanf("%d", &sair);
		if(sair==1){
			for(c=0;c<=qtdanuncios;c++){
				anunciar[opcao]=anunciar[c+1];
				opcao++;
			}
			for(i=0;i<=qtdanuncios;i++){
				if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
					printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
				}
			sleep(5);
			break;
		}
	}
		else if(sair==2){
			break;
			sair=0;
		}
		else{
			printf("Não entendi a sua opção. \n");
			continue;
		}

 	}
}

void localanuncio(){
	opcao=0;
	printf("Digite em poucas palavras, o que você gostaria de comprar: ");
	fflush(stdin);
	fgets(localizar.localizaranuncio,20,stdin);
	for (i=0;i<=qtdanuncios;i++){
		if(strncmp(localizar.localizaranuncio,anunciar[i].nomeproduto,2)==0){
			localizar.publiencontradas++;
		}
		else if(i>0 && localizar.publiencontradas<1){
			printf("Nenhum anuncio foi localizado. Por favor, tente novamente. \n");
			continue;
		}
	}
	printf("Localizamos %d anuncios relacionados a sua pesquisa. \n", localizar.publiencontradas);
	for (i=0;i<=qtdanuncios;i++){
		if(strncmp(localizar.localizaranuncio,anunciar[i].nomeproduto,2)==0){
			printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
		}
	}
	while(1){
		printf("Qual anuncio deseja visualizar?\nDigite o numero: ");
		scanf("%d", &l);
		printf(" %s           condição do produto: %s \n  preço: %.2f reais \n telefone: %s \n Usuario: %s \nDescrição: %s \nAvaliação do vendedor: %d",anunciar[l].nomeproduto,anunciar[l].condicaoproduto,anunciar[l].preco,anunciar[l].telefone,cadastroven[l].usuario,anunciar[l].descricao,cadastroven[l].aval);
		printf("\n Deseja sair: 1 - Sim, 2 - Não");
		scanf("%d", &opcao);
		if(opcao==1){
			break;
		}
		else if(opcao==2){
			continue;
	}
	}

}

void confirmar_compra(){
	while(1){
		j=0;
		opcao=0;
		printf("Deseja voltar Digite 1 -- Para continuar basta digitar outro numero: \n");
		scanf("%d", &c);
		if(c==1){
			break;
		}
		printf("Digite qual anuncio você vendeu: \n");
		for(i=0;i<=qtdanuncios;i++){
			if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
				printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
				j++;
			}
		}
		if(j==0){
			printf("Nenhum Anuncio encontrado. \n");
			break;
		}
		printf("\n \n \nDigite: ");
		scanf("%d", &opcao);
		printf("Tem certeza que vendeu esse anuncio? 1 - sim, 2 - não : ");
		scanf("%d", &sair);
		if(sair==1){
			for(c=0;c<=qtdanuncios;c++){
				anunciar[opcao]=anunciar[c+1];
				opcao++;
			}
			for(i=0;i<=qtdanuncios;i++){
				if(strcmp(anunciar[i].nome_vendedor,cadastroven[i].usuario)==0){
					printf("%d) %s           condição do produto: %s \n  preço: %.2f reais \n",i,anunciar[i].nomeproduto,anunciar[i].condicaoproduto,anunciar[i].preco);
				}
			sleep(5);
			break;
			}
		}
		else if(sair==2){
			break;
			sair=0;
		}
		else{
			printf("Não entendi a sua opção. \n");
			continue;
		}

 	}
}

void avaliacaovendedor(){
	opcao=0;
	while(1){
		printf("Deseja avaliar o vendedor?: 1 -sim ou 2 - não");
		scanf("%d", &opcao);
		if(opcao==1){
			printf("Digite o nome de usuario do vendedor: ");
			fflush(stdin);
			fgets(nota.nomeusuario,20,stdin);
			for(i=0;i<=qtdvendedor;i++){
				if(strcmp(nota.nomeusuario,cadastroven[i].usuario)==0){
					printf("Informe um numero de 1 a 5, sendo 5 a melhor nota: ");
					scanf("%d", &nota.notavendedor);
					if(nota.notavendedor>0 && nota.notavendedor<6){
						printf("Obrigada por avaliar! \n");
						nota.mediavendedor=(nota.mediavendedor+nota.notavendedor)/nota.quantidadeavaliacao;
						cadastroven[i].aval=nota.mediavendedor;
						break;
					}
					else{
						printf("O valor não foi identificado. Por favor, digite novamente. \n");
						continue;
					}
				}
			}
		}
		else if(opcao==2){
			printf("Obrigada! \n");
			break;
		}
		else{
			printf("Não entendi a sua opção. Digite novamente. \n");
			continue;
		}

	}

}
