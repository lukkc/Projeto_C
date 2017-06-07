
void iMenu(char * opcao){

  system("clear");
  printf("\n======================================================\n\n");
  printf(" ALUNO: LUCAS ALVES DE CALDAS\n");
  printf(" DISCIPLINA: ESTRUTURA DE DADOS I\n");
  printf(" PROFESSOR: WALACE BONFIM\n\n\n\n");


  printf("-------- EDITOR DE ÁRVORE BINÁRIA DE PESQUISA --------\n\n\n");

  printf(" [ 1 ] - INSERIR\n");
  printf(" [ 2 ] - REMOVER APENAS UM NÓ\n");
  printf(" [ 3 ] - PESQUISAR\n");
  printf(" [ 4 ] - ESVAZIAR A ÁRVORE\n");
  printf(" [ 5 ] - EXIBIR A ÁRVORE\n");
  printf(" [ 0 ] - SAIR\n\n\n\n");

  printf("ESCOLHA UMA DAS OPÇÕES ACIMA: ");
  scanf(" %c", opcao);
  setbuf(stdin, NULL);
}


void iMenuExibirArvore(char * opcao){

  system("clear");
  printf("-------- EXIBIR ÁRVORE --------\n\n\n");

  printf(" [ 1 ] - EXIBIR EM PRÉ-ORDEM\n");
  printf(" [ 2 ] - EXIBIR EM PÓS-ORDEM\n");
  printf(" [ 3 ] - EXIBIR EM IN-ORDEM\n");
  printf(" [ 4 ] - EXIBIR EM GRAFICAMENTE\n");
  printf(" [ 0 ] - VOLTAR PARA O MENU\n\n\n\n");

  printf("ESCOLHA UMA DAS OPÇÕES ACIMA: ");
  scanf(" %c", opcao);
  setbuf(stdin, NULL);
}



void iCarregarArvore(char * load){

  system("clear");
  strcat(load, ".");
  printf("\n\tINICIANDO O SISTEMA, AGUARDE ENQUANTO CARREGAMOS A ÁRVORE.\n\n\n");
  printf("\n\tCARREGANDO ÁRVORE %s\n\n", load);
}




void iExibirPreOrdem(t_arvore * arvore){

  if((*arvore) != NULL){
    printf("%s - ", (*arvore)->dado.nome);
    iExibirPreOrdem(&((*arvore)->esquerda));
    iExibirPreOrdem(&((*arvore)->direita));
  }
}


void iExibirPosOrdem(t_arvore * arvore){

  if((*arvore) != NULL){
    iExibirPosOrdem(&((*arvore)->esquerda));
    iExibirPosOrdem(&((*arvore)->direita));
    printf("%s - ", (*arvore)->dado.nome);
  }
}


void iExibirInOrdem(t_arvore * arvore){

  if((*arvore) != NULL){
    iExibirInOrdem(&((*arvore)->esquerda));
    printf("%s - ", (*arvore)->dado.nome);
    iExibirInOrdem(&((*arvore)->direita));
  }
}


void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}


void iExibirGraficamente(t_arvore * arvore, int coluna, int linha, int desloc){

  if ((*arvore) == NULL) {
    return;
  }

  gotoxy(coluna, linha);

  printf("%s", (*arvore)->dado.nome);

  if((*arvore)->esquerda != NULL){
    iExibirGraficamente(&((*arvore)->esquerda), coluna - desloc, linha + 2, desloc / 2+1);
  }

  if((*arvore)->direita != NULL){
    iExibirGraficamente(&((*arvore)->direita), coluna + desloc, linha + 2, desloc / 2+1);
  }
}


void exibirArvore(t_arvore arvore){

int loop = 1;
char sair[1000];
char opcao;

do {

  opcao = ' ';
  iMenuExibirArvore(&opcao);

  switch (opcao) {
    case '0':
      loop = 0;
      break;

    case '1':
      do{
        system("clear");
        printf("ÁRVORE PRÉ-ORDEM: ");
        printf("\n\n\t\t[ ");
        iExibirPreOrdem(&arvore);
        printf("]");

        printf("\n\n\n\n\nDIGITE ZERO PARA SAIR:");
        scanf("%s", sair);
      }while(strcmp(sair, "0"));
      break;

    case '2':
      do{
        system("clear");
        printf("ÁRVORE PÓS-ORDEM: ");
        printf("\n\n\t\t[ ");
        iExibirPosOrdem(&arvore);
        printf("]");

        printf("\n\n\n\n\nDIGITE ZERO PARA SAIR:");
        scanf("%s", sair);
      }while(strcmp(sair, "0"));
      break;

    case '3':
      do{
        system("clear");
        printf("ÁRVORE IN-ORDEM: ");
        printf("\n\n\t\t[ ");
        iExibirInOrdem(&arvore);
        printf("]");

        printf("\n\n\n\n\nDIGITE ZERO PARA SAIR:");
        scanf("%s", sair);
      }while(strcmp(sair, "0"));
      break;

    case '4':
      do{
        system("clear");
        printf("ÁRVORE GRAFICAMENTE: ");
        iExibirGraficamente(&arvore, 30, 5, 5);

        printf("\n\n\n\n\nDIGITE ZERO PARA SAIR:");
        scanf("%s", sair);
      }while(strcmp(sair, "0"));
      break;

    default:
      system("clear");
      printf("\n\tOPÇÃO INVÁLIDA, ESCOLHA ALGUMA OPÇÃO VÁLIDA.\n");
      sleep(2);
      break;

  }
} while(loop);

}
