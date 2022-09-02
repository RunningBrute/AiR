#include <iostream>
#include <fstream>

using namespace std;

const int inf = 999999999;

int n;
int *p;
int *w;
int *d;

void go_witi(int display=1)
{	
	unsigned int Ci = 0;
	unsigned int Ti = 0;
	int tab_size = 1<<n;//pow(2.0,n);
	unsigned int *tab = new unsigned int [tab_size];
	unsigned int *save_j = new unsigned int [tab_size];
	int *perm = new int [n];

	tab[0] = 0;

	int tmp, tmp2;

	for(int i=1; i<tab_size; i++)
		tab[i]=inf;

	for(int i=1; i<tab_size; i++)
	{
		for(int k=0; (k<n)&&(k<i); k++)
		{
			if(i & 1<<k)
				Ci += p[k]; //Ci=const			
		}
	
		for(int j=0; (j<n)&&(j<i) ; j++)//jazda po n bitach (tyle ile zadan), j<i - ograniczenie na ilosc wykonan sie petli
		{
				if(i & 1<<j)
				{
					tmp = i & ~(1<<j);

					tmp2 = (Ci-d[j]);

					Ti = max(0, tmp2);

					if(j==0)
					{
						tab[i] = tab[tmp]+Ti*w[(j)];
						save_j[i]=j;
					}

					else
						if(tab[i]>tab[tmp]+(Ti*w[j]))//
						{
							tab[i] = tab[tmp]+Ti*w[(j)];//na koniec zostaje najmniejsza wartosc
							save_j[i]=j;
						}
				}					
		}
		Ci=0;
	}

	//permuta
	int a = n;
	for(int i=tab_size-1; a!=0 ; )//zaczamy od konca
	{
		perm[--a]=(save_j[i]+1);
		i &= ~(1<<save_j[i]);

	}

	cout<<tab[(1<<n)-1]<<endl;//wiTi

	if(display)//drukuj permutacje
	{
		for(int j=0; j<n ; j++)
			cout<<perm[j]<<" ";
		cout<<endl<<endl;
	}

	delete [] tab;
	delete [] save_j;
	delete [] perm;
}


int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	fstream in_file(argv[1], ios::in);
	
	in_file >> n;
	p = new int [n];
	w = new int [n];
	d = new int [n];

	for(int i=0; i<n; i++)
	{
		in_file >> p[i];
		in_file >> w[i];
		in_file >> d[i];
	}

	go_witi();
	
	delete [] p;
	delete [] w;
	delete [] d;

	system("pause");
}