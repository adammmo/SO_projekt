#include "share.h"

int main()
{
    pid_t pid;
    printf("proces macierzysty: %d\n", getpid());
    

    switch(pid=fork()){ //proces potomny 1
        case 0:
            proces1_main();
        case -1:
            printf("błąd forka");
            exit(1);
        default:
            break;
    }

    //zaznacz obszar i kliknij ctrl+/ by odrazu odkomentować wszystko
    // switch(pid=fork()){ //proces potomny 2
    //     case 0:
    //         proces2_main();
    //     case -1:
    //         printf("błąd forka");
    //         exit(1);
    //     default:
    //         break;
    // }

    // switch(pid=fork()){ //proces potomny 3
    //     case 0:
    //         proces3_main();
    //     case -1:
    //         printf("błąd forka");
    //         exit(1);
    //     default:
    //         break;
    // }
    
    for (int i = 0; wait(NULL)>0; i++){
        wait(NULL);
        printf("koniec procesu\n");
    }

    return 0;
}