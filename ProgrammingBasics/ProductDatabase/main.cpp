#include <iostream>

using namespace std;

/*
 * Opisac jakie wartosci ma ten enum i do czego bede przydatne.
 */
enum opcje_sortowania {CENA, DATA, NAZWA};

/*
 * Opis struktury: co modeluje, jakie ma pola, ich opis.
 */
struct Produkt{
  float cena;
  char nazwa_produktu [15]; // Jezeli nazwa zawiera 15 znakow wywala dziwne rzeczy na koncu
  char data [8]; // Wywala blad jak sie da tego short. Narazie tylko z char dziala
};

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
Produkt WprowadzProdukt(Produkt *Prd){
  cout << "   Wprowadz cene produktu [w PLN]: ";
  cin >> Prd->cena;
  
  cout << "   Wprowadz nazwe produktu [max. 15 znakow]: ";
  cin >> Prd->nazwa_produktu;
  
  cout << "   Wspowadz date produktu [format: DD:MM:RR, gdzie DD - dzien," << endl; 
  cout << "     MM - miesiac, RR - dwie ostatnie cyfry roku]: ";
  cin >> Prd->data;
  cout << endl;
  
  return *Prd;
}

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
void WyswietlInfoProduktu(Produkt *Prd){
  cout << "    Cena produktu: " << Prd->cena << endl;
  cout << "    Nazwa produktu: " << Prd->nazwa_produktu << endl;
  cout << "    Data produktu: " << Prd->data << endl;
  cout << endl;
}

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
void WprowadzProduktyDoTabeli(Produkt *Prd, 
                              Produkt *Tab_produktow, 
                              int liczProduktow){
  int i=0;
  
  for (i=0;i<liczProduktow;i++){ 
    cout << " ***** Wprowadz dane produktu nr " << i+1 << " ***** " << endl;
    cout << endl;
    Tab_produktow[i] = WprowadzProdukt(Prd); 
  }
}

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
void WyswietlInfoProduktowZTabeli(Produkt *Tab_produktow, int liczProduktow){
  Produkt Prd;
  int i=0;
  
  cout << endl;
  for (i=0;i<liczProduktow;i++){ 
    Prd = Tab_produktow[i];
    cout << " ***** Informacja o produkcie nr " << i+1 << " ***** " << endl;
    cout << endl;
    WyswietlInfoProduktu(&Prd);
  }
}

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
void WyswietlSeparator(){
  cout << "------------------------------------------------------------------";
  cout << endl;
}

/*
 * Opis funkcji: jakie parametry, jakie zwracane wartosci i co robi.
 */
int WprowadzLiczbeProdukow(int *liczProduktow){
  while ((*liczProduktow == 0) or (*liczProduktow < 0)){
    cout << endl;
    cout << " Ile produktow ma zostac wprowadzonych? ";
    cin >> *liczProduktow;
    cout << endl;
    if (*liczProduktow > 0) return 1;
    else return 0;
  }
}
                                         
int main(){

  Produkt Prd;
  int liczProduktow = 0;
  Produkt *Tab_produktow;

  if (WprowadzLiczbeProdukow(&liczProduktow)==1){
    Tab_produktow = new Produkt[liczProduktow];
  }
  else cerr << "     Wprowadz liczbe wieksza od zera! " << endl;
  
  WprowadzProduktyDoTabeli(&Prd,Tab_produktow,liczProduktow);
  WyswietlSeparator();
  WyswietlInfoProduktowZTabeli(Tab_produktow,liczProduktow);

  system("PAUSE");
  return EXIT_SUCCESS;
}
