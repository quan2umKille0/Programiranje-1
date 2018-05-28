/*
  Napisati program koji �e u�itati cijeli broj n (1 <= n <= 10), (ukoliko unesena vrijednost 
  nije unutar intervala, u�itavanje treba ponavljati sve dok se ne unese ispravna vrijednost)  
  i elemente matrice dimenzije nxn te ispisati da li je matrica centralno simetri�na s obrzirom na
  sredi�nji element. Ako jeste, program treba ispisati 1, ako nije ispisati 0, a ako je
  broj redova paran (pa nema sredi�njeg elementa) ispisati -1. Koristite posebne funkcije
  za unos elemenata i provjeru simetri�nosti.
  
  Primjer centralno simetri�ne matrice:
  
  3 1 2             [1]  4  [5]  8  [7]
  5 4 5              3  [1] [2] [4]  6
  2 1 3             [7] [5] [3] [5] [7]
                     6  [4] [2] [1]  3
                    [7]  8  [5]  4  [1]
*/

#include <iostream>
#include <iomanip>

using namespace std;

void upis(int niz[][10], int dimenzija)
{
    for(int i = 0; i < dimenzija; i++)
    {
        for(int j = 0; j < dimenzija; j++)
        {
            cout << "Unesite ["<< i << "][" << j << "] element: ";
            cin >> niz[i][j];
        }
    }
}

void ispis(int niz[][10], int dimenzija)
{
    cout << "Unijeli ste sljedecu matricu: " << endl;
    for(int i = 0; i < dimenzija; i++)
    {
        for(int j = 0; j < dimenzija; j++)
        {
            cout << setw(4) << niz[i][j];
        }
        cout << "\n";
    }
}

int provjera(int niz[][10], int dimenzija)
{
    
    if(dimenzija % 2 == 0)
        return -1;
    else
    {
        for(int i = 0; i < dimenzija; i++)
        {
            for(int j = 0; j < dimenzija; j++)
            {
                if(niz[i][i] != niz[dimenzija-1-i][dimenzija-1-i]) 
                    return 0;
                if(i+j == dimenzija - 1 && niz[i][j] != niz[j][i]) 
                    return 0;
                if(niz[i][dimenzija/2] != niz[dimenzija-1-i][dimenzija/2]) 
                    return 0;
                if(niz[dimenzija/2][j] != niz[dimenzija/2][dimenzija-1-j]) 
                    return 0;
            }
        }
        
        return 1;
    }
}

int main()
{
    int niz[10][10];
    int dimenzija;
    
    do
    {
        cout << "Unesite broj elemenata: ";
        cin >> dimenzija;
        
    }while(dimenzija < 1 || dimenzija > 10);
    
    upis(niz, dimenzija);
    cout << endl;
    ispis(niz, dimenzija);
    
    cout << provjera(niz, dimenzija) << endl;
    
    return 0;
}