const int ROZ_TAB = 4;

//============================================================================
//----------------------------------Wektor------------------------------------
struct Wektor{
  
    Wektor(){x=y=z=w=0;}
    Wektor operator - (const Wektor & Odjemnik);
    Wektor operator / (const double & Dzielnik);
    double operator & (const Wektor & Mnoznik);
  
    double x,y,z,w;
  
};
//----------------------------------Wektor------------------------------------
//============================================================================

//============================================================================
//----------------------------------Macierz-----------------------------------
struct Macierz{
  
    bool WczytajDoMacierzy(Wektor WektorDoMacierzy, int i);
    void WyswietlMacierz();
  
    Wektor _Wspol[ROZ_TAB];
  
};
//-----------------------------------Macierz----------------------------------
//============================================================================

//============================================================================
//-----------------------------------Rownanie---------------------------------
struct Rownanie{

    bool ZapiszDoMacierzy(Wektor WektorDoMacierzy, int i);
    bool WczytajWyrazyWolne(Wektor WektorWyrWolnych);
    void WyswietlMacierz();
    void WyswietlWyrazyWolne();
    void WyswietlNiewiadome();
    bool RozwiazRownanie();
    bool Gauss();
    bool Norma();
    
  private:
    
    Macierz  _Macierz;
    Wektor   _WektorNormy;
    Wektor   _Niewiadome;
    double   _WyrazyWolne[ROZ_TAB];
    double   _Blad;
         
};
//-----------------------------------Rownanie---------------------------------
//============================================================================


