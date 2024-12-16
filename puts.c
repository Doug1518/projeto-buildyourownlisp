#include <stdio.h>

#include <stdio.h>

int main(void){
	int rc = puts("Hello World");
 
    if (rc == EOF)
        perror("puts()"); // POSIX requires that errno is set
	puts("estou escrevendo com essa função que no final pula linha automáticamente");
}