#include "mpc.h"

int main() {

  /* Criar um parser 'Adjetivo' para reconhecer descrições */
  mpc_parser_t* Adjetivo = mpc_or(4, 
    mpc_sym("wow"), mpc_sym("many"),
    mpc_sym("so"),  mpc_sym("such")
  );

  /* Criar um parser 'Substantivo' para reconhecer coisas */
  mpc_parser_t* Substantivo = mpc_or(5,
    mpc_sym("lisp"), mpc_sym("language"),
    mpc_sym("book"), mpc_sym("build"), 
    mpc_sym("c")
  );
  
  mpc_parser_t* Frase = mpc_and(2, mpcf_strfold, 
    Adjetivo, Substantivo, free);
  
  mpc_parser_t* Doge = mpc_many(mpcf_strfold, Frase);

  /* Realizar algum parsing aqui... */
  
  mpc_delete(Doge);
  
  return 0;
  
}
