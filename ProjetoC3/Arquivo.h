void salvarInOrdem(t_arvore arvore, FILE * arquivo){

  if(arvore != NULL){
    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s - ", arvore->dado.nome);
    salvarInOrdem(arvore->esquerda, arquivo);
    salvarInOrdem(arvore->direita, arquivo);
  }

}



int salvarArquivo(t_arvore * arvore){

  FILE * arquivo;

  arquivo = fopen("ArvoreBinariaPesquisa.csv", "w+");

  if(arquivo == 0){
    printf("ERRO AO ABRIR O ARQUIVO");
    return 0;
  }

  salvarInOrdem(*arvore, arquivo);
  fclose(arquivo);

  return 1;
}



void lerInOrdem(FILE * arquivo, t_arvore * arvore){
  t_elemento dado;
  char load[1000] = { };
  int falso = 0;

  while (!feof(arquivo)) {
    fscanf(arquivo, "%s - ", dado.nome);
    iCarregarArvore(load);
    inserir(&(*arvore), dado, falso);
  }
  sleep(2);
}



int lerArquivo(t_arvore * arvore){

  FILE * arquivo;

  arquivo = fopen("ArvoreBinariaPesquisa.csv", "r");

  if(arquivo == 0){
    return 0;
  }

  lerInOrdem(arquivo, &(*arvore));
  fclose(arquivo);

  return 1;
}
