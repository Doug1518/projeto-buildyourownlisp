#include <stdio.h>
#include <stdlib.h>

/* Se estivermos compilando no Windows, compilamos estas funcoes */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Funcao readline falsa (simulada) */
char* readline(char* prompt) {
  fputs(prompt, stdout); // Exibe o prompt "lispy> "
  fgets(buffer, 2048, stdin); // Le uma linha de entrada do usuario
  char* cpy = malloc(strlen(buffer) + 1); // Aloca memoria para a entrada
  strcpy(cpy, buffer); // Copia a entrada do buffer para a nova memoria
  cpy[strlen(cpy) - 1] = '\0'; // Remove o caractere de nova linha (\n)
  return cpy; // Retorna a string de entrada
}

/* Funcao add_history falsa (simulada) */
void add_history(char* unused) {
    (void) unused; // Diz ao compilador que "sabemos" que esse parâmetro não será usado
}


/* Caso contrario, incluimos os cabecalhos de editline */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main() {

  puts("Versao Comando 0.0.0.0.1 beta");
  puts("Pressione Ctrl+c para sair do programa\n");

  while (1) {
    /* Agora, em ambos os casos, readline sera definido corretamente */
    char* entrada = readline("Comando> "); // Exibe o prompt "lispy> " e le a entrada
    add_history(entrada); // Adiciona a entrada ao historico

    printf("voce digitou, %s\n", entrada); // Repete a entrada de volta para o usuario
    free(entrada); // Libera a memoria alocada para a entrada
  }

  return 0;
}
