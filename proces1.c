#include "share.h"

int licz = 0;
int pojemnosc = 4;
char **dane = NULL;
int x;

void collect_data_plik() {
    char nazwa[16];
    printf("podaj nazwe pliku: \n");
    scanf("%s",nazwa);
    printf("Pobieram dane z pliku\n");

    FILE *plik;
    char linia[1024];
    plik = fopen(nazwa, "r");
    if (plik == NULL) {
        printf("Błąd otwarcia pliku\n");
        exit(1);
    }

    // alokacja początkowa
    dane = malloc(pojemnosc * sizeof(char*));
    if (!dane) {
        printf("błąd alokacji pamięci");
        exit(1);
    }

    while (fgets(linia, sizeof(linia), plik)) {
        linia[strcspn(linia, "\n")] = '\0'; // usunięcie znaku końca wiersza

        //dynamicznie alokowanie pamięci
        if (licz >= pojemnosc) {
            pojemnosc *= 2;
            dane = realloc(dane, pojemnosc * sizeof(char*));
            if (!dane) {
                printf("błąd alokacji pamięci");
                exit(1);
            }
        }

        dane[licz] = malloc(strlen(linia) + 1);
        strcpy(dane[licz], linia);
        licz++;
    }

    fclose(plik);
}

void collect_data_klaw() {
    printf("Pobieram dane z klawiatury\n");
    // tu można dodać analogiczne wczytywanie z klawiatury
}

void print_dane() {
    for (int i = 0; i < licz; i++) {
        printf("linia %d: %s\n", i + 1, dane[i]);
    }
}

void proces1_main() {
    printf("Uruchomiono proces 1. PID: %d\n", getpid());
    printf("1 - pobranie danych z pliku\n2 - pobranie danych z klawiatury\nW jaki sposób pobrać dane: ");
    scanf("%d", &x);

    if (x == 1) {
        collect_data_plik();
    } else {
        collect_data_klaw();
    }

    print_dane();

    exit(0);
}
