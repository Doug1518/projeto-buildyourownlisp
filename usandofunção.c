#include <stdio.h>



int hello_world(int n){
    int i = 0;
    
    while(i < n){
        printf("hello world\n");
        i++;
    }
    return 0; 
}





int main(){
    
    
   hello_world(5);
}