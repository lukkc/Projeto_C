typedef struct elemento{
  char nome[100];
}t_elemento;

typedef struct no{
  struct no * esquerda;
  t_elemento dado;
  struct no * direita;
}t_no;

typedef t_no * t_arvore;



t_no * criar(){

  t_no * no = (t_no*) malloc(sizeof(t_no));

  if(no){
    no->esquerda = no->direita = NULL;
  }

  return no;
}




int comparar(t_elemento dado1, t_elemento dado2){
  return strcmp(dado1.nome, dado2.nome);
}




int inserir(t_arvore * arvore, t_elemento dado, int alert){

  int resultado;
  int falso = 0;


  if(*arvore == NULL){
    *arvore = criar();
    if(*arvore == NULL){
      system("clear");
      printf("\n\t\tNÃO FOI POSSÍVEL INSERIR NA ÁRVORE\n");
      sleep(2);
      return 0;
    }
    (*arvore)->dado = dado;
    printf("\t\t- RAIZ DA ÁRVORE.\n");
    sleep(1);
    return 1;
  }

  if(comparar((*arvore)->dado, dado) < 0){
    resultado = inserir(&((*arvore)->direita), dado, falso);

    if(resultado){
      printf("\t\t- INSERIDO A DIREITA.\n");
      sleep(1);
    }
  }else{
    if (comparar((*arvore)->dado, dado) > 0){
      resultado = inserir(&((*arvore)->esquerda), dado, falso);

      if(resultado){
        printf("\t\t- INSERIDO A ESQUERDA.\n");
        sleep(1);
      }
    }else{
      resultado = 0;
      system("clear");
      printf("\n\t\tNÃO FOI POSSÍVEL INSERIR NA ÁRVORE,\n");
      printf("\t\tESSE NOME JÁ EXISTE\n");
      sleep(3);
    }
  }

  if (resultado && alert) {
    aInserindoNo();
  }

  return resultado;
}


t_elemento criarElemento(){
  t_elemento dado;
  char nome[100];

  printf("\nDIGITE UM NOME: ");
  scanf("%s", nome);

  strcpy(dado.nome, nome);

  return dado;
}



t_no * buscaSetPai(t_arvore arvore, t_elemento dado, t_no ** pai){

  if(arvore == NULL){
    *pai = NULL;
    return NULL;
  }

  if(comparar(arvore->dado, dado) == 0){
    return arvore;
  }

  if(comparar(arvore->dado, dado) > 0){
    *pai = arvore;
    return buscaSetPai(arvore->esquerda, dado, pai);
  }else{
    *pai = arvore;
    return buscaSetPai(arvore->direita, dado, pai);
  }
}


t_no * buscar(t_arvore * arvore, t_elemento dado) {

  aBuscandoNo();

  if((*arvore) == NULL){

    system("clear");
    printf("\n\t\tESSE DADO NÃO EXISTE NA ÁRVORE!!\n");
    sleep(3);
    return NULL;
  }



  if(comparar((*arvore)->dado, dado) == 0){
    system("clear");
    printf("\n\t\t '%s' FOI ENCONTRADO NA ÁRVORE!!\n", dado.nome);
    sleep(3);
    return *arvore;
  }

  if(comparar((*arvore)->dado, dado) < 0){
    return buscar(&((*arvore)->direita), dado);
  }else{
    return buscar(&((*arvore)->esquerda), dado);
  }
}


int remover(t_arvore * arvore, t_elemento dado){

  t_no * no,
       * pai,
       * substitutoNo,
       * paiSucessor,
       * sucessor;

  no = *arvore;
  pai = NULL;
  no = buscaSetPai(*arvore, dado, &pai);

  aRemovendoNo();

  if(no == NULL){
    system("clear");
    printf("\n\t\tNÃO FOI POSSÍVEL REMOVER\n");
    sleep(2);
    return 0;
  }

  if(no->esquerda == NULL){
    substitutoNo = no->direita;
  }else{
    if(no->direita == NULL){
      substitutoNo = no->esquerda;
    }else{
      paiSucessor = no;
      substitutoNo = no->direita;
      sucessor = substitutoNo->esquerda;

      while (sucessor != NULL) {
        paiSucessor = substitutoNo;
        substitutoNo = sucessor;
        sucessor = substitutoNo->esquerda;
      }

      if(paiSucessor != no){
        paiSucessor->esquerda = substitutoNo->direita;
        substitutoNo->direita = no->direita;
      }

      substitutoNo->esquerda = no->esquerda;
    }
  }

  if(pai == NULL){
    *arvore = substitutoNo;
  }else{
    if(no == pai->esquerda){
      pai->esquerda = substitutoNo;
    }else{
      pai->direita = substitutoNo;
    }
  }

  aRemovidoSucesso();

  free(no);
  return 1;
}



int esvaziarArvore(t_arvore * arvore){

  aEsvaziandoArvore();

  if(*arvore == NULL){
    printf("A ÁRVORE JÁ ESTÁ VAZIA\n");
    return 0;
  }

  esvaziarArvore(&((*arvore)->esquerda));
  esvaziarArvore(&((*arvore)->direita));

  free(*arvore);
  *arvore = NULL;

  return 1;
}
