// użyte biblioteki
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

//procesy potomne
void proces1_main();
void proces2_main();
void proces3_main();

//funkcje współdzielone