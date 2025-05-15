#include "share.h"

void proces3_main(){
    printf("proces 3: %d\n",getpid());
    for (int i=0; i<2; i++){
        printf("licznik: %d\n", i);
    }

    exit(0);
}