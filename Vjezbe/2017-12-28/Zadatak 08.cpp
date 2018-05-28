/*
  Napi�ite program koji �e omogu�iti kreiranje matrice prirodnih brojeva 2x3. 
  Pretpostavka je da postoji funkcija koja omogu�ava unos prirodnih brojeva (ne treba 
  ju definirati); 
  Kreirajte funkcije:
  � void kopiraj(int[][3], int [][5]); zada�a funkcije da kopira sve elemente iz 
    jedne  matrice  (2x3)  u  drugu  matricu  (2x5)  pri  �emu  se  prve  dvije  kolone  prve 
    matrice kopiraju dva puta;
    Npr.        matrica1      matrica2
                1  2  3     1  2  3  1  2
                4  5  6     4  5  6  4  5
  � funkcije:  int  suma(int  [],  int);  �ija  je  zada�a  izra�unati  sumu  retka  kojeg 
    izabere korisnik za matricu koju izabere korisnik;   obavezno onemogu�iti korisnika 
    da izabere nepostoje�u matricu i nepostoje�i redak;
    
  Ispis sume i izbor matrice i retka vr�ite u funkciji main.
*/

#include <iostream>

using namespace std;



void upis(int niz[][3])
{
    cout << "Unesite matricu: " << endl;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            cin >> niz[i][j];
}

void ispis3(int niz[][3])
{
    cout << "Niz1: " << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << niz[i][j];
        }
        cout << endl;
    }
}

void ispis5(int niz[][5])
{
    cout << "Niz2: " << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << " " << niz[i][j];
        }
        cout << endl;
    }
}

void kopiraj(int niz1[][3], int niz2[][5])
{
    //Niz1  // Niz2
    //1 2 3 // 1 2 3 1 2
    //4 5 6 // 4 5 6 4 5
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j <= 2) niz2[i][j] = niz1[i][j];
            else niz2[i][j] = niz1[i][j-3];
        }
    }
}

int suma(int niz[], int r)
{
    int s = 0;
    for(int i = 0; i < r; i++)
        s += niz[i];
        
    return s;
    
}

int main()
{
    int niz1[2][3];
    int niz2[2][5];
    int matrica, red;
    int s;
    
    upis(niz1);
    kopiraj(niz1, niz2);
    ispis3(niz1);
    ispis5(niz2);
    
    do
    {
        cout << "Izaberite matricu (1/2)" << endl;
        cin >> matrica;
        cout << "Izaberite red (1/2)" << endl;
        cin >> red;
    }while((matrica < 1 || matrica > 2) && (red < 1 || red > 2));
    
    if(matrica == 1)
        s = suma(niz1[red-1], 3);
    else
        s = suma(niz2[red-1], 5);
    
    cout << "Suma " << red << ". reda " << matrica << ". matrice je " << s << endl;
    
    
    return 0;
}