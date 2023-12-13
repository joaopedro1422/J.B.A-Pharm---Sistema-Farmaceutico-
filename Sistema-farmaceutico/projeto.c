#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BG_RED "\033[41m"
#define NONE "\033[0m"
#define BOLD "\033[1m"
#define HALFBRIGHT "\033[2m"
#define UNDERSCORE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"
#define C_GRAY "\033[37m"
#define C_RED "\033[31m"

int x,cont,cont_f=1,y,a,b,d,salario,cadastro_,existe,existeprod,contvenda=1,cadastronovo[10];
int codigo_novo,idade_novo,quant_novo,matrizcodigo[2][10],matrizqntd[2][10];
int cod_venda,qntd_prod;
float valortotal,saldodia;
FILE * pFile;
int n;
char name [100];
float preco_novo,c,matrizpreco[2][10];
char nome_novo[20],nome_pessoa[20],e[20],matriznome[10][10];
//cadastro do funcionário
typedef struct{
    char nome[20];
    int salario;
    int idade;
    int cadastro;
}novo_cadastro;
//cadastro dos medicamentos
typedef struct { 
    char remedio[20];
    int codigo;
    int qntd;
    float valor;
}medicamento;
//cadastro dos clientes
typedef struct lista {
    char cpf_cliente[12];
    char nome_cliente[40];
    float valor;
    struct lista* prox;
} Lista;

int cpf(char cpf_cliente){
  
}
Lista *primeiro= NULL;
medicamento prod[1000];
Lista* inserir_cadastros(Lista* primeiro);
void listar_cadastros(Lista* primeiro);
void limpa_linha(void);

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}
//verificação da existência dos produtos
void produto_existe(int cod_venda){
    if(cod_venda==prod[cod_venda].codigo){
      existeprod=2;
    }
    else{
      existeprod=5;
    }


}
Lista cliente;

void listar_cadastros(Lista* primeiro) {

    Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.

    //Imprimindo os restaurantes da lista, e suas repectivas informações.
        atual = primeiro ;
        //printf(BG_RED BLINK BOLD"\n\n\n");
        
        pFile = fopen ("extrato.txt","a");
  
        fprintf(pFile,"->NOME : %s", atual->nome_cliente);
        fprintf(pFile,"   CPF : [%s]\n", atual->cpf_cliente);
        fprintf(pFile,"   VALOR DA COMPRA: R$%.2f\n", atual->valor);
        
        fclose (pFile);
    
    if ( primeiro == NULL)
        fprintf(pFile,"  Nenhum Cliente Cadastrado.");
    
}

Lista* inserir_cadastros(Lista* primeiro) {

    Lista cliente;
    Lista *atual = primeiro;
    char identificador = 'F';

    //Lendo as informações do cliente.
    printf(BG_RED BLINK BOLD"\n-> CPF(CLIENTE): ");
    scanf("%s", &cliente.cpf_cliente);
    while (1 > 0) {
    if (strlen(&cliente.cpf_cliente) != 11) {
      printf(" FORMATO INVÁLIDO, TENTE NOVAMENTE!");
      printf(BG_RED BLINK BOLD"\n-> CPF(CLIENTE): ");
      scanf("%s",&cliente.cpf_cliente);
    }
    if (strlen(&cliente.cpf_cliente) == 11) {
      limpa_linha();
    printf ("\n");
    printf("-> PRIMEIRO NOME: ");
    fgets(cliente.nome_cliente,40,stdin);
    printf(BG_RED BLINK BOLD"\n  - PRESSIONE ENTER PARA CONFIRMAR -");
    cliente.valor=valortotal;
    limpa_linha();


    //Verificando se o cadastro já existe.
    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->cpf_cliente == cliente.cpf_cliente) {
            identificador = 'V';
            break;
        }
    }

    if ( identificador != 'V' && (strlen(cliente.nome_cliente) != 1)) {

        //Alocando os espaços e guardando as informações do cliente.
        Lista* NovoCliente = malloc (sizeof(Lista));
        strcpy(NovoCliente->nome_cliente, cliente.nome_cliente);
        NovoCliente->valor = cliente.valor;
        strcpy(NovoCliente->cpf_cliente, cliente.cpf_cliente);
        NovoCliente->prox = primeiro;
        
        
        return NovoCliente;
    } else {
        printf("  Cadastro invalido!");
        
        return primeiro;
    }
}
    }
  }
    

void matriz()
{
  for (int i=0;i<cont;i++)
    {
      matrizcodigo[1][i]=codigo_novo;
      matrizqntd[1][i]=quant_novo;
      matrizpreco[1][i]=preco_novo;
      matriznome[2][i]=nome_novo;
    }
}
novo_cadastro pessoa[10];

medicamento nova()
{
  medicamento prod[codigo_novo];
    
  for (int i=0;i<=cont;i++){
    
    prod[codigo_novo].codigo=codigo_novo;
    strcpy(prod[codigo_novo].remedio,nome_novo);
    prod[codigo_novo].qntd=quant_novo;
    prod[codigo_novo].valor=preco_novo;
    
 }
  return prod[codigo_novo];
}

//realização das vendas
void vendas() {
  printf(BG_RED BOLD BLINK C_GRAY" \n");
  sleep(1);
  system("cls");
  
  printf(REVERSE
              "  ===================> J.B.A PHARMACY <================== \n\n\t\t\t  VENDAS \n"NONE);
  //primeiro= inserir_cadastros(primeiro);
  printf(BG_RED BLINK BOLD"\n-> INFORME O CODIGO DO PRODUTO:");
  scanf("%d",&cod_venda);
  produto_existe(cod_venda);
  if (existeprod==2)
  {
    printf("\n\t\t\t -%s- \n\n\t\t\t Codigo: %d \n\t\t\t Quant: %d \n\t\t\t R$: %.2f \n\t\t\t\t\n",prod[cod_venda].remedio,prod[cod_venda].codigo,prod[cod_venda].qntd,prod[cod_venda].valor);
  //mostrar produto
  

  //quantidade
  printf("-> INFORME A QUANTIDADE DO PRODUTO: ");
  scanf("%d",&qntd_prod);
  valortotal= prod[cod_venda].valor*qntd_prod;
  saldodia= saldodia+valortotal;
  primeiro = inserir_cadastros(primeiro);
  printf(REVERSE"\n ---> VALOR A PAGAR: R$%.2f \n"NONE BG_RED BLINK BOLD,valortotal);
  printf("VENDEDOR: %s\n",pessoa[cadastro_].nome);
  listar_cadastros(primeiro);
  pFile = fopen ("extrato.txt","a"); 
  
  fprintf(pFile,"   VENDEDOR : %s\n\n\n", pessoa[cadastro_].nome);
  
  fclose (pFile);
  system("pause");
  contvenda++;
  menu();
  }
  else{
        system("cls");
        
        printf(BG_RED BLINK BOLD REVERSE
              "  ===================> J.B.A PHARMACY <================== \n\n\t\t\tVENDAS \n\n"NONE);
        printf(BG_RED BOLD BLINK C_GRAY"\t\t*PRODUTO NAO REGISTRADO* \n\n-> DIGITE 5 PARA VOLTAR AO MENU.\n\n-> INFORME NOVAMENTE O CODIGO DO PRODUTO:\n->"NONE);
        scanf("%d",&cod_venda);
        if (existeprod==5)
        {
          menu();
        }
        if (existeprod==2)
      {
        printf("\n\n -%s- \t\t\t\t\t\t \n\nCodigo: %d \t\t\t\t\t \nQuant: %d \t\t\t\t\t\t \nR$: %.2f \t\t\t\t\n",prod[cod_venda].remedio,prod[cod_venda].codigo-1,prod[cod_venda].qntd,prod[cod_venda].valor);
      //mostrar produto
      system("pause");
      //quantidade
      printf("\t\t\t\n\n-> INFORME A QUANTIDADE DO PRODUTO DESEJADO: ");
      scanf("%d",&qntd_prod);
      valortotal= prod[cod_venda].valor*qntd_prod;
      saldodia= saldodia+valortotal;
      printf("\t---> VALOR A PAGAR: R$%.2f",valortotal);
      sleep(4);
      menu();
      }
  }

}
//consulta de funcionários cadastrados
void consulta_func()
{
  int op_fun2;
      
      system("cls");
      printf( REVERSE
           "  ===================> J.B.A PHARMACY <================== \n\n\t   TAMANHO DA ATUAL EQUIPE:%d FUNCIONARIO(S)  \n\n",cont_f);
      printf(NONE BG_RED BOLD BLINK "->DIGITE '1' PARA SAIR.\n\n\t\t       _%s_\n\n\t\t      SALARIO: R$%d\n\t\t      IDADE:%d anos\n\t\t      CADASTRO:%d\n",pessoa[111].nome,pessoa[111].salario,pessoa[111].idade,pessoa[111].cadastro );
      for (int i=0;i<(cont_f-1);i++)
      {
        
        printf(BG_RED BOLD BLINK "\n\n\n\t\t       _%s_\n\n\t\t      SALARIO :R$%d\n\t\t      IDADE:%d anos\n\t\t      CADASTRO:%d\n->",pessoa[cadastronovo[i+2]].nome,pessoa[cadastronovo[i+2]].salario,pessoa[cadastronovo[i+2]].idade,pessoa[cadastronovo[i+2]].cadastro );
      }
      scanf("%d",&op_fun2);
      if (op_fun2==1)
      {
        system("cls");
        menu();
      }
}
// adicionar funcionarios no sistema
void func()
{
  system("cls");
  int op_func;
  printf(BG_RED BOLD BLINK C_GRAY" \n");
    system("clear||cls");
    printf( REVERSE
           "  ===================> J.B.A PHARMACY <================== \n\n\t\t    CONTROLE DE FUNCIONARIOS   "NONE BG_RED BOLD BLINK"\n\n-> INFORME A FUNCAO DESEJADA.\n\n  (1) ADICIONAR FUNCIONARIO\n  (2) CONSULTAR LISTA DE FUNCIONARIOS\n\n->\n");     
    scanf("%d",&op_func);
    if(op_func==1)
    {
        
        system("cls");
        cont_f=cont_f+1;
        printf( REVERSE
              "  ===================> J.B.A PHARMACY <================== \n\n\t\t CADASTRO DE FUNCIONARIOS  \n\n"NONE );
        printf(BG_RED BOLD BLINK"->DEFINA O CADASTRO (3 digitos):\n-> ");
        scanf("%d",&cadastronovo[cont_f]);
        pessoa[cadastronovo[cont_f]].cadastro=cadastronovo[cont_f];
        printf("->INSIRA O PRIMEIRO NOME DO FUNCIONARIO A SER CADASTRADO:\n->");
        scanf("%s",pessoa[cadastronovo[cont_f]].nome);
        printf("->DIGITE A IDADE PARA PROSSEGUIR:\n-> ");
        scanf("%d",&pessoa[cadastronovo[cont_f]].idade);
        printf("->INFORME O SALARIO MENSAL:\n-> ");
        scanf("%d",&pessoa[cadastronovo[cont_f]].salario);
        printf( "\n\n\t\t    %s\n\n\t\t  SALARIO:%d\n\t\t  IDADE:%d anos\n\t\t  CADASTRO:%d\n",pessoa[cadastronovo[cont_f]].nome,pessoa[cadastronovo[cont_f]].salario,pessoa[cadastronovo[cont_f]].idade,pessoa[cadastronovo[cont_f]].cadastro );
        
        sleep(1);
        system("cls");
        consulta_func();
        }
    if(op_func==2)
    {
      consulta_func();
      
    }
}
// mostra os remedios na lista
void controle()
{ 
  

    
    prod[cod_venda].qntd=prod[cod_venda].qntd-qntd_prod;
    
    printf(BG_RED BOLD BLINK C_GRAY" \n");
    sleep(1);
    system("clear||cls");
    printf( REVERSE
           "  ===================> J.B.A PHARMACY <================== \n\n\t\t    CONTROLE DE ESTOQUE     "NONE BG_RED BOLD BLINK UNDERSCORE "\n\nFUNC. ATIVO: %s\n\n"NONE,pessoa[cadastro_].nome);

    printf(BG_RED BOLD BLINK"->DIGITE '1' PARA ADICIONAR NOVO PRODUTO.\n\n->DIGITE '2' PARA SAIR.\n\n   -%s- \t\t\t\t -%s-\n\n  Codigo: %d \t\t\t\tCodigo: %d \n  Quant: %d \t\t\t\tQuant: %d \n  R$: %.2f \t\t\t\tR$: %.2f\n",prod[207].remedio,prod[194].remedio,prod[207].codigo,prod[194].codigo,prod[207].qntd,prod[194].qntd,prod[207].valor,prod[194].valor);
    
    printf("\n\n  -%s-\t\t\t\t -%s-\n\n  Codigo: %d \t\t\t\tCodigo: %d \n  Quant: %d \t\t\t\tQuant: %d \n  R$: %.2f  \t\t\t\tR$: %.2f\n",prod[602].remedio,prod[234].remedio,prod[602].codigo,prod[234].codigo,prod[602].qntd,prod[234].qntd,prod[602].valor,prod[234].valor);
    printf("\n\n  -%s- \t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[003].remedio,prod[103].remedio,prod[003].codigo,prod[103].codigo,prod[003].qntd,prod[103].qntd,prod[003].valor,prod[103].valor);
    printf("\n-%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[105].remedio,prod[122].remedio,prod[105].codigo,prod[122].codigo,prod[105].qntd,prod[122].qntd,prod[105].valor,prod[122].valor);
    printf("\n -%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[165].remedio,prod[121].remedio,prod[165].codigo,prod[121].codigo,prod[165].qntd,prod[121].qntd,prod[165].valor,prod[121].valor);
    printf("\n -%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[290].remedio,prod[130].remedio,prod[290].codigo,prod[130].codigo,prod[290].qntd,prod[130].qntd,prod[290].valor,prod[130].valor);
    printf("\n -%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[133].remedio,prod[204].remedio,prod[133].codigo,prod[204].codigo,prod[133].qntd,prod[204].qntd,prod[133].valor,prod[204].valor);
    printf("\n -%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[151].remedio,prod[299].remedio,prod[151].codigo,prod[299].codigo,prod[151].qntd,prod[299].qntd,prod[151].valor,prod[299].valor);
    printf("\n -%s- \t\t\t  -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[126].remedio,prod[285].remedio,prod[126].codigo,prod[285].codigo,prod[126].qntd,prod[285].qntd,prod[126].valor,prod[285].valor);
    printf("\n -%s- \t\t\t\t -%s-\n\nCodigo: %d \t\t\t\tCodigo: %d \nQuant: %d \t\t\t\tQuant: %d \nR$: %.2f \t\t\t\tR$: %.2f\n",prod[127].remedio,prod[299].remedio,prod[127].codigo,prod[299].codigo,prod[127].qntd,prod[299].qntd,prod[127].valor,prod[299].valor);
     for(int i=0;i<cont;i++)
      {
        medicamento remedio;
        remedio= nova();
        
        //nova();
        printf("\n -%s- \t\t\t\t\t\t \n\nCodigo: %d \t\t\t\t\t \nQuant: %d \t\t\t\t\t\t \nR$: %.2f \t\t\t\t\n",remedio.remedio,remedio.codigo-1,remedio.qntd,remedio.valor);
      }
    int novo_produto;
    
  scanf("%d",&novo_produto);
  if(novo_produto==1)
  {
    printf("oi \n");
    sleep(1);
    system("clear||cls");
    printf(BG_RED BOLD BLINK C_GRAY
           "  \n===================> J.B.A PHARMACY <=================== \n NOVO PRODUTO\n");
//cadastro de produtos
    printf("-INFORME O NOME DO PRODUTO A SER CADASTRADO\n-");
    scanf("%s",nome_novo);
    printf("-INFORME O CODIGO,QUANTIDADE E VALOR DO PRODUTO A SER ADICIONADO (COD,QNTD,PRECO)\n-");
    scanf("%d,%d,%f",&codigo_novo,&quant_novo,&preco_novo);
    cont++;
    matriz();
   // nova();
    prod[codigo_novo].codigo=codigo_novo;
    strcpy(prod[codigo_novo].remedio,nome_novo);
    prod[codigo_novo].qntd=quant_novo;
    prod[codigo_novo].valor=preco_novo;
    
    printf("\n -%s- \t\t\t\t\t\t \n\nCodigo: %d \t\t\t\t\t \nQuant: %d \t\t\t\t\t\t \nR$: %.2f \t\t\t\t\n",prod[codigo_novo].remedio,prod[codigo_novo].codigo,prod[codigo_novo].qntd,prod[codigo_novo].valor);
    medicamento remedio;
    remedio= nova();
    
    sleep(3);
    system("clear||cls");
    controle();
  }
  if (novo_produto==2)
  {
    sleep(1);
    system("cls");
    menu();
  }
} 

void cadastro(){
printf(BG_RED BOLD BLINK C_GRAY" \n");
sleep(1);
system("clear||cls");
printf( REVERSE"  ===================> J.B.A PHARMACY <================== \n\n\t\t    CADASTRO DE FUNCIONARIO    \n\n"NONE BG_RED BOLD BLINK);
char nome[25],sobrenome[25];

//verificação de cadastro
printf("\n\n\t-> INFORME O SEU CADASTRO: ");
scanf("%d",&cadastro_);



confere(cadastro_);//chama função que faz a verificação

if(existe==3)
{
  printf("\n\t\t\t*ACESSO VALIDO!*");
  
    
}
if(existe==2) {
    sleep(2);
    printf("\n\n\t*USUARIO NAO CADASTRADO,RETORNE AO MENU E TENTE NOVAMENTE!*");
    sleep(2);
    menu();
}
if(existe==4){
  sleep(1);
  printf("\n\n\t*FORMATO INVALIDO!  DIGITE O CODIGO DE CADASTRO");
  printf("\n\n\t-> INFORME O SEU CADASTRO: ");
  scanf("%d",&cadastro_);



confere(cadastro_);
}

}
void confere(int cadastro)
{
  existe= 0;
  if(pessoa[cadastro].cadastro !=cadastro)
    {
      existe= 2;
      
    }
  else if(pessoa[cadastro].cadastro == cadastro){
    existe=3;
  }
  else {
    existe=4;
  }
}

void menu() 
  {
    int resposta_menu;
    system("clear||cls");
    printf(BG_RED BOLD BLINK REVERSE C_GRAY
           "===================> J.B.A PHARMACY <=================== \n\n");
    printf("\t\t  <MENU PRINCIPAL>  \n\n"NONE BG_RED BOLD BLINK "->DIGITE A OPERACAO QUE DESEJA REALIZAR:\n\n\t (1) EFETUAR VENDA \n\t (2) CONTROLE DE PRODUTOS \n\t (3) CONTROLE DE FUNCIONARIOS/CADASTRO\n\t (4) HISTORICO DE CLIENTES / SALDO DO DIA\n\t (5) SAIR\n\n->");
    scanf("%d", &resposta_menu);
    switch (resposta_menu) //funções a serem usadas de acordo com a opção selecionada no menu
    {
    case 1: {
      cadastro();
      vendas();
    }
    case 2: {
      cadastro();
      controle();
     }
     case 3:
     {
      func();
     }
     case 4:{
      system("clear||cls");
      printf(BG_RED BOLD BLINK REVERSE C_GRAY
           "===================> J.B.A PHARMACY <=================== \n\n");
      printf("\t\t  REGISTRO DE VENDAS  \n\n"NONE);
      printf(BG_RED BOLD BLINK"-> PARA ACESSAR O REGISTRO COMPLETO DE VENDAS \n  ABRA O ARQUIVO 'EXTRATO' EM SEU COMPUTADOR." UNDERSCORE "\n\n\n\t\t SALDO DO DIA:%.2f \n\n"NONE BG_RED BLINK BOLD,saldodia);
      system("pause");
      menu();
     }
     case 5:{
      sair();
     }
    }
  }

// função para sair do sistema
void sair(){
   char espaco[4]= "   ";
    printf(BG_RED BOLD BLINK REVERSE C_GRAY "_\n");
    sleep(1);
    system("cls");
 for(int i=0;i<4;i++)
    {
      printf(BOLD BLINK REVERSE C_GRAY"===================> J.B.A PHARMACY <=================== \n\n \t\t SISTEMA FARMACEUTICO "NONE BG_RED BOLD BLINK C_GRAY"\n\n\n\n\t\t      " 
 "DESLIGANDO%s",espaco);
      espaco[i]='.';
      sleep(1);
      system("cls");
      
    }
    exit(0);
}

int main() {
  //definição dos produtos disponiveis em estoque
    strcpy(prod[207].remedio,"DORFLEX");
    prod[207].codigo=207;
    prod[207].qntd=20;
    prod[207].valor=18.50;
    strcpy(prod[194].remedio,"NEOSORO");
    prod[194].codigo=194;
    prod[194].qntd=5;
    prod[194].valor=3.75;

    strcpy(prod[003].remedio,"MONTELUCASTE");
    prod[003].codigo=003;
    prod[003].qntd=12;
    prod[003].valor=38.50;
    strcpy(prod[103].remedio,"GELOL");
    prod[103].codigo=103;
    prod[103].qntd=15;
    prod[103].valor=32.30;
    
    strcpy(prod[602].remedio,"DIPIRONA");
    prod[602].codigo=602;
    prod[602].qntd=15;
    prod[602].valor=6.90; 
    strcpy(prod[234].remedio,"ASPIRINA");
    prod[234].codigo=234;
    prod[234].qntd=10;
    prod[234].valor=15.00;

    strcpy(prod[105].remedio,"LORATADINA");
    prod[105].codigo=105;
    prod[105].qntd=30;
    prod[105].valor=9.99;
    strcpy(prod[122].remedio,"CALMAN");
    prod[122].codigo=122;
    prod[122].qntd=25;
    prod[122].valor=35.05;

    strcpy(prod[165].remedio,"IBUPROFENO");
    prod[165].codigo=165;
    prod[165].qntd=33;
    prod[165].valor=12.99;
    strcpy(prod[121].remedio,"LUFTAL");
    prod[121].codigo=121;
    prod[121].qntd=20;
    prod[121].valor=19.90;
   
    strcpy(prod[290].remedio,"HISTAMIN");
    prod[290].codigo=290;
    prod[290].qntd=25;
    prod[290].valor=10.69;
    strcpy(prod[130].remedio,"SOMINEX");
    prod[130].codigo=130;
    prod[130].qntd=30;
    prod[130].valor=16.19;
    

    strcpy(prod[133].remedio,"GLICOZEN");
    prod[133].codigo=133;
    prod[133].qntd=40;
    prod[133].valor=99.99;
    strcpy(prod[204].remedio,"VITAMINA C");
    prod[204].codigo=204;
    prod[204].qntd=30;
    prod[204].valor=19.90;

    strcpy(prod[151].remedio,"CYSTEX");
    prod[151].codigo=151;
    prod[151].qntd=40;
    prod[151].valor=30.39;
    strcpy(prod[299].remedio,"AZITROMICINA");
    prod[299].codigo=299;
    prod[299].qntd=30;
    prod[299].valor=65.99;

    strcpy(prod[126].remedio,"NORETISTERONA");
    prod[126].codigo=126;
    prod[126].qntd=25;
    prod[126].valor=6.59;
    strcpy(prod[285].remedio,"CETOCONAZOL");
    prod[285].codigo=285;
    prod[285].qntd=15;
    prod[285].valor=13.81;

    strcpy(prod[127].remedio,"FRALDA");
    prod[127].codigo=127;
    prod[127].qntd=30;
    prod[127].valor=28.49;
    strcpy(prod[299].remedio,"CREME DENTAL");
    prod[299].codigo=299;
    prod[299].qntd=15;
    prod[299].valor=13.81;
    strcpy(pessoa[111].nome,"KLAUDIO");
    pessoa[111].cadastro=111;
    pessoa[111].idade=34;
    pessoa[111].salario=2500;
    pFile = fopen ("extrato.txt","a");

    //cabeçalho para arquivo, ao iniciar o programa
    fprintf(pFile,"\t\t\tREGISTRO DE CLIENTES (novo dia)\n\n\n");
    
    fclose (pFile);
    
    char espaco[9]= "     ";
    printf(BG_RED BOLD BLINK REVERSE C_GRAY "_\n");
    sleep(1);
    system("cls");
    
    
    //detalhe para o "carregamento" do inicio do programa
    for(int i=0;i<9;i++)
    {
      printf(BOLD BLINK REVERSE C_GRAY"===================> J.B.A PHARMACY <=================== \n\n \t\t SISTEMA FARMACEUTICO "NONE BG_RED BOLD BLINK C_GRAY"\n\n\n\n\t\t      " 
 "INICIANDO\n\t\t      %s\n\n\n",espaco);
      espaco[i]='-';
      sleep(1);
      system("cls");
      
    }
    //chamada do menu principal
    menu();
}