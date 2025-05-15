#include "share.h"

void proces2_main(){
    printf("proces 2: %d\n",getpid());
    for (int i=0; i<2; i++){
        printf("licznik: %d\n", i);
    }

    exit(0);
}