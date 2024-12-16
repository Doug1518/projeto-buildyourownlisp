#include "mpc.h"

int main(int argc, char** argv) {

  mpc_parser_t* Adjetivo = mpc_new("adjetivo");
  mpc_parser_t* Substantivo = mpc_new("substantivo");
  mpc_parser_t* Frase = mpc_new("frase");
  mpc_parser_t* Doge = mpc_new("doge");

  mpca_lang(MPCA_LANG_DEFAULT,
    "                                           \
      adjetivo : \"wow\" | \"many\"            \
                |  \"so\" | \"such\";           \
      substantivo : \"lisp\" | \"language\"       \
                | \"book\" | \"build\" | \"c\"; \
      frase    : <adjetivo> <substantivo>;           \
      doge     : <frase>*;                    \
    ",
    Adjetivo, Substantivo, Frase, Doge);

  /* Realizar algum parsing aqui... */

  mpc_cleanup(4, Adjetivo, Substantivo, Frase, Doge);
  
  return 0;
  
}
