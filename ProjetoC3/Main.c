#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "alerts.h"
#include "ArvoreBinariaPesquisa.h"
#include "Interface.h"
#include "Arquivo.h"


int main() {

  t_arvore arvore = NULL;
  t_elemento dado;
  int loop = 1;
  char opcao;
  int truue = 1;
  int alert;

  lerArquivo(&arvore);

do {

  opcao = ' ';
  iMenu(&opcao);

  switch (opcao) {
    case '0':

      loop = 0;
      break;

    case '1':

      dado = criarElemento();
      inserir(&arvore, dado, truue);
      salvarArquivo(&arvore);
      break;

    case '2':

      dado = criarElemento();
      remover(&arvore, dado);
      salvarArquivo(&arvore);
      break;

    case '3':

      dado = criarElemento();
      buscar(&arvore, dado);
      break;

    case '4':

      alert = esvaziarArvore(&arvore);
      salvarArquivo(&arvore);
      aEsvaziadoSucesso(alert);
      break;

    case '5':

      exibirArvore(arvore);
      break;

    default:
      system("clear");
      printf("\n\tOPÇÃO INVÁLIDA, ESCOLHA ALGUMA OPÇÃO VÁLIDA NO MENU.\n");
      sleep(2);
      break;

  }
} while(loop);
}
