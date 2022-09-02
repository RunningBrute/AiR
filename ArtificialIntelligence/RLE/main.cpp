#include <stdlib.h>
#include "RLE.h" 

int main(){ 
    
    int x;               // przechowuje opcje programu 
    char inPath[1000];   // sciezka pliku wejsciowego
    char outPath[1000];  // sciezka pliku wyjsciowego
    FILE *in, *out;      // wskazniki na plik wejsciowy i wyjsciowy
 
    // wybor kompresji lub dekompresji algorytmem RLE
    printf("1 - kompresja\n"); 
    printf("2 - dekompresja\n"); 
    scanf("%d", &x); 
 
    // wczytanie lokalizacji plikow
    printf("Plik wejsciowy:\n"); 
    scanf("%s", inPath); 
    printf("Plik wyjsciowy:\n"); 
    scanf("%s", outPath);    
 
    // otworzenie plikow
    in = fopen(inPath, "rb"); 
    out = fopen(outPath, "wb"); 
 
    // taka asercja jak by nie bylo plikow albo sciezki byly zle podane
    if (in == NULL){ 
        printf("Nie moge otworzyc pliku wejsciowego\n"); 
        return -1; 
    } 
    if (out == NULL){ 
        printf("Nie moge utworzyc pliku wyjsciowego\n"); 
        return -1; 
    }    
 
    // uruchomienie odpowiedniej funkcji w zaleznosci od wybranej opcji
    if (x == 1) 
        compress(in, out); 
    else
        decompress(in, out); 
 
    // zamkniecie plikow
    fclose(in); 
    fclose(out); 
 
    system("PAUSE");
}
