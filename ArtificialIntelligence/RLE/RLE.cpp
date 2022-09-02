#include "RLE.h"

/* kompresja RLE */
void compress(FILE *in, FILE *out){ 
     char cur, prev, tmp; 
     unsigned char cnt = 0; 
     int  cont; 
 
     cont = fread(&cur, sizeof(char), 1, in); 
     prev = cur + 1; 
     while (cont == 1){ 
        if (prev != cur){ 
            if (cnt == 0){ 
               /* znaki obok siebie rozne wrzuc do pliku wyjsciowego */
               fwrite(&cur, sizeof(char), 1, out); 
            } 
            else{ 
                /* skonczyla sie sekwencja powtarzajcych sie znakow */
                cnt--; 
                fwrite(&prev, sizeof(char), 1, out); 
                fwrite(&cnt, sizeof(char), 1, out); 
                fwrite(&cur, sizeof(char), 1, out);             
                cnt = 0; 
            } 
        } 
        else{ 
           /* liczbe powtarzajacych sie znakow zapisujemy na jednym bajcie 
           wypisz sekwencje jezeli ma ona maksymalna dlugosc */         
           if (cnt == 255){ 
               fwrite(&prev, sizeof(char), 1, out); 
               fwrite(&cnt, sizeof(char), 1, out); 
               cnt = 0; 
               cont = fread(&cur, sizeof(char), 1, in); 
               prev = cur + 1; 
               continue; 
           } 
           else{ 
               /* licz powtarzajace sie znaki */         
               cnt++;   
           } 
        } 
        /* odczytaj kolejny znak z pliku wejsciowego */
        cont = fread(&tmp, sizeof(char), 1, in); 
        if (cont == 1){ 
            prev = cur;       
            cur = tmp; 
        } 
     } 
 
    /* jezeli plik konczy sie sekwencja wypisz ja */
    if (prev == cur){ 
        cnt--; 
        fwrite(&prev, sizeof(char), 1, out); 
        fwrite(&cnt, sizeof(char), 1, out);    
    } 
} 
 
/* dekompresja RLE */
void decompress(FILE *in, FILE *out){ 
    char cur, prev; 
    unsigned char cnt = 0; 
    int  cont, i; 
 
    cont = fread(&cur, sizeof(char), 1, in); 
    prev = cur + 1; 
    while (cont == 1){ 
        if (prev != cur){ 
            /* znaki obok siebie rozne wrzuc do pliku wyjsciowego */
            fwrite(&cur, sizeof(char), 1, out);       
            prev = cur; 
            /* odczytaj kolejny znak */         
            cont = fread(&cur, sizeof(char), 1, in); 
        }    
        else{ 
           /* znaki obok siebie sa rowne - mamy sekwencje */
           /* odczytaj dlugosc sekwencji i wrzuc ja do pliku wyjsciowego */
           cont = fread(&cnt, sizeof(char), 1, in); 
           for (i=0; i<=cnt; i++){ 
               fwrite(&cur, sizeof(char), 1, out); 
           } 
           /* odczytaj kolejny znak */ 
           cont = fread(&cur, sizeof(char), 1, in); 
           prev = cur + 1;          
        } 
    } 
} 
