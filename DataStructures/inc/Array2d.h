#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <cstdlib>


/*! 
 * Klasa modelujaca dwuwymiarowa tablice liczb calkowitych. Wymiary tablicy 
 * jak i zakres do ktorego maja bys wybierane wartosci zostaja wprowadzone 
 * z klawiatury. Klasa zawiera pola odpowiedzialne za przechowywanie wiadomosci
 * o szerokosci, dlugosci tablicy, jej najmniejszym oraz najwiekszym elemencie 
 * oraz najwiekszej mozliwej wartosci jaka moze byc wylosowana. Do zarzadzania
 * tymi wiadomosciami udostepniony zostal szereg metod pozwalajacych na 
 * odpowiednie zarzadzanie klasa.
 *
 */
struct Array2d {
       
    /*
     * Konstruktor bezparametryczny inicjujacy pola klasy 
     * domyslnymi wartosciami. Dla ulatwienia pola max_valu oraz min_value
     * zostaly wyzerowane jako ze tabela nie ma elementu najwiekszego ani
     * elementu najwiekszego. Konstruktor tworzy tez dynamiczna tablice
     * dwuwymiarowa z domyslnymi parametrami.
     */ 
    Array2d(){}
    
    /*
     * Konstruktor parametryczny pozwalajacy zainicjowac pola klasy 
     * dowolnymi wartosciami wprowadzonymi przez uzytkownika. Po wprowadzeniu
     * i wykonaniu tego konstruktora zostanie utworzona dwuwymiarowa tablica
     * dynamiczna "tab" o wymiarach tab[_width][_height]. 
     * 
     * Parametry:
     *   _width  - parametr reprezentujacy pierwszy wymiar (szerokosc) 
     *             tablicy "tab",
     *   _height - parametr reprezentujacy drugi wymiar (wysokosc) 
     *             tablicy "tab",
     *   _max    - parametr mowiacy o maksymalnej wartosci jaka moga posiadac
     *             rekordy tablicy "tab".
     */    
    Array2d(int _width, int _height, int _max);
    
    /* 
     * Destruktor usowajacy tablice dynamiczna z pamieci.
     */ 
    ~Array2d();
    
    /*
     * Metoda inicjujaca tablice losowymi wartosciami z zakresu 0-max.
     */ 
    void InitArray();
    
    /*
     * Metoda wyswietlajaca dane o tablicy "tab" (odpowiednio: szerokosc,
     * wysokosc, wartosc maksymalna rekordu tablicy oraz wartosc maksymalna
     * i minimalna zawarta w tablicy).
     */
    void ShowFieldsValues();
    
    /*
     * Metoda wyszukujaca wartosc najmniejsza w talicy "tab".
     *
     * Zwracana wartosc:
     *   - liczba calkowita bedaca najmniejsz wartoscia w talicy "tab".
     */
    int FindMinValue();
    
    /*
     * Metoda wyszukujaca wartosc najwieksza w talicy "tab".
     *
     * Zwracana wartosc:
     *   - liczba calkowita bedaca najwieksza wartoscia w talicy "tab".
     */
    int FindMaxValue();
    
    /*
     * Metoda wyswietlajaca minimalna wartosc tablicy "tab".
     */
    void ShowMinValue(){std::cout << " Min: " << FindMinValue() << std::endl;}
    
    /*
     * Metoda wyswietlajaca maksymalna wartosc tablicy "tab".
     */
    void ShowMaxValue(){std::cout << " Max: " << FindMaxValue() << std::endl;}
    
    /*
     * Metoda wyswietlajaca na standardowe wyjscie wartosci tabeli "tab".
     */
    void ShowArrayValues();
    
    /*
     * Metoda odpowiedzialna za wylosowalie liczby z zakresu 0-max. 
     *
     * Zwracana wartosc:
     *   - liczba ca³kowita generowana ze wzoru rand()%(max+1), 
     *     gdzie rand() to funkcja losujaca liczbe calkowita oraz max
     *     zmienna mowiaca o maksymalnej wartosci wylosowanej liczby.
     */
    int ReturnRandValue(){return (rand()%(max+1));}
    
    /*
     * Metoda wyswietlajaca informacje o poczatku i koncu danej klasy
     * w zaleznosci od podanego parametru wejsciowego.
     * 
     * Parametry:
     *    _value - '1' mowi o wyswietleniu naglowka, natomiast '0' 
     *             o wyswietleniu stopki.
     */
    void ShowSeparator(bool _value);
    
  private:
          
    int width;     // szerokosc tablicy, pierwszy wymiar
    int height;    // wysokosc tablicy, drugi wymiar
    int max;       // wartosc maksymalna jaka moze zawierac rekord tablicy
    int min_value; // wartosc minimalna
    int max_value; // wartosc maksymalna
    int **tab;     // wskaznik na dwuwymiarowa tablice liczb calkowitych
};

#endif
