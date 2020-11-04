#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>




struct cliente {
	
	
	char nome[30];
	char end[30];
	char email[30];
	char sexo [10];
	long unsigned int tel;
	char cpf[20];
	char rg[20];
};

struct cliente cadastro; 



void login()
{
	
	int a=0,i=0;
    char usuario[10],c=' '; 
    char senha[10], code[10];
    char user[10]="user"; //login
    char pass[10]="pass"; //senha
    
    
    
    do
{
	system("cls");
	
    printf("\n  **************************  LOGIN  **************************  ");
    printf(" \n                       	Usuario:");
	scanf("%s", &usuario); 
	printf(" \n                       Senha:");
	while(i<10)
	{
	    senha[i]=getch();
	    c=senha[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	senha[i]='\0';
	
	i=0;
		if(strcmp(usuario,user)==0 && strcmp(senha,pass)==0)
	{
	printf("  \n\n\n  CONECTADO...");
	
	break;
	}
	else
	{
		printf("\n    LOGIN NAO REALIZADO...TENTE NOVAMENTE!");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nTENTATIVA DE LOGIN ERRADO MUITAS VEZES, TENTE MAIS TARDE.");
		
		getch();
		
		}
		system("cls");	
}


void add_cad(){
	
	system("cls");
    printf("\t\t\t...Adicionar Novo Cadastro...\n");
    FILE *fp;
    fp = fopen("cadastros.dll","ab+");
    if(fp == NULL){
        printf("ERRO AO CADASTRAR.\n\n");

    }else{
        fflush(stdin);
	
       
         	printf("\nNome:\t");
			gets(cadastro.nome);
           	printf("CPF:\t");
			gets(cadastro.cpf);
            printf("RG:\t");
			gets(cadastro.rg);
			printf("Endereco:\t");
			gets(cadastro.end);
			printf("E-mail:\t");
			gets(cadastro.email);
           	printf("Sexo:\t");
			gets(cadastro.sexo);
			printf("Telefone:\t");
			scanf("%ld",&cadastro.tel);
			printf("\n");
        fwrite(&cadastro, sizeof(cadastro), 1, fp);
        printf("\n\t\tCADASTRO REALIZADO COM SUCESSO.\n");
    }
    

    fclose(fp);
    return;
}




void procurar_cad(){
	system("cls");
	char cpf[20];
	int encontrado=0 ;
	fflush(stdin);
	printf("\n\n\t...PROCURAR CADASTRO...\n\t\n\t.Insira o CPF do cliente para procurar cadastro:  ");
	fflush(stdin);
    gets(cpf);
    FILE *fp;
    fp = fopen("cadastros.dll","rb");
    ;
    while(fread(&cadastro,sizeof(cadastro),1,fp) == 1){
        if(strcmp(cpf,cadastro.cpf) == 0){
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 1){
        printf("\nNome\t: %s\nCPF\t: %s\nRG\t: %s\nTelefone\t: %ld\nEndereco\t: %s\nE-mail\t: %s\nSexo\t: %s\n",cadastro.nome,cadastro.cpf,cadastro.rg, cadastro.tel, cadastro.end,cadastro.email,cadastro.sexo);



    }else{
        printf("\t\tNenhum cadastro encontrado .\n\n");
    }
    
    fclose(fp);
    return;
	
	
	
	
}

void editar_cad() {
	
	system("cls");
	char cpf[20];
	FILE *fp, *ft;

        fp=fopen("cadastros.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("...Editar cadastros...\n\n\n\t..Digite o CPF do cadastro a ser editado: ");

        gets(cpf);

        while(fread(&cadastro,sizeof(cadastro),1,fp)==1)

        {

            if(stricmp(cpf,cadastro.cpf)!=0)

                fwrite(&cadastro,sizeof(cadastro),1,ft);

        }

        fflush(stdin);

        printf("\n\n...Cadastro a ser editado: '%s'\n\n",cpf);
	
		printf("Nome:\t");
	
		scanf("%s",&cadastro.nome);
        
		printf("CPF:\t");

        scanf("%ld",&cadastro.cpf);
        
        fflush(stdin);
        
        printf("RG:\t");

        scanf("%ld",&cadastro.rg);
        
        fflush(stdin);
        
		printf("Telefone:\t");

        scanf("%ld",&cadastro.tel);

        fflush(stdin);

        printf("Endereco:\t");

        gets(cadastro.end);

        fflush(stdin);

        printf("E-mail:\t");

        gets(cadastro.email);
        
        printf("Sexo:\t");

        gets(cadastro.sexo);

        printf("\n");
        
        fwrite(&cadastro,sizeof(cadastro),1,ft);

        fclose(fp);

        fclose(ft);

        remove("cadastros.dll");

        rename("temp.dat","cadastros.dll");

        return;
}

void deletar_cad(){
	
	system("cls");
	char cpf[20];
	FILE *fp, *ft;
        fflush(stdin);

        printf("\n\n\t...Deletar Cadastro...\n\t\n\t..Digite o cpf do cadastro a ser deletado: ");

        gets(cpf);

        fp=fopen("cadastros.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&cadastro,sizeof(cadastro),1,fp)!=0)

            if (stricmp(cpf,cadastro.cpf)!=0)

                fwrite(&cadastro,sizeof(cadastro),1,ft);

        fclose(fp);

        fclose(ft);

        remove("cadastros.dll");

        rename("cadastros.dll","temp.dat");
		printf("\n...Cadastro deletado com sucesso...");
        return;
	
	
}

void menu_inicial(){
	system("cls");
	
    int opcao;
   
    while(1){
    	printf("\n\t **** BEM VINDO AO SISTEMA DE CADASTRO DE CLIENTES ****");
    	printf("\n\n\n\t\t\t*** MENU INICIAL***\n\t\t");
    	
        printf("\n\t\t\t\t[1] Adicionar novo Cadastro\n\t\t");
        
		printf("\t\t[2] Procurar Cadastro\n\t\t");
		
    	printf("\t\t[3] Editar Cadastro\n\t\t");
    	
        printf("\t\t[4] Deletar Cadastro\n\t\t");
        
        printf("\t\t[0] Sair\n\t\t");
        
        
		printf("\n\n\t...Digite uma opcao:..\t");
		scanf("%d",&opcao);
        switch(opcao){
            case 1:
                add_cad();
                break;
            
            case 2:
                procurar_cad();
                break;
           
            case 3:
                editar_cad();
                break;
    
    		case 4:
                deletar_cad();
                break;
                
            case 0:
            	printf("\n\n\t\tDeseja Sair? Pressione Enter!");
                exit(0);
                break;
            
			default:
				printf("Opcao invalida!");
                break;
        }

    }
}


int main(){
    
    system("cls");
    login();
    system("cls");
    menu_inicial();
    return 0;
}
