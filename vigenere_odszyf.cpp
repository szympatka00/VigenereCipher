#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    string haslo, jawne, tajne;
    char tab[26][26];
    char c='a';

    //robie tablice 26x26 z przesunietymi alfabetami
    for (int i=0; i<26; i++)
    {
        c='a';
        c=c+i;
        for (int j=0; j<26; j++)
        {
            if (c>'z')
            {
                c='a';
            }
                tab[i][j]=c;
                c++;
        }
    }

    cout << endl << "Podaj haslo i slowo tajne. Haslo:" << endl;
    cin >> haslo;
    cout << endl << "Slowo tajne:" <<endl;
    cin >> tajne;
    cout << endl;

    int i_haslo[tajne.length()];

    //tworze tablice indexow liter z hasla
    for (int i=0; i<haslo.length(); i++)
    {
        for(int j=0;j<26; j++)
        {
            if (haslo[i] == tab[0][j])
            {
                i_haslo[i]=j;
                cout << i_haslo[i] << endl;
            }
        }
    }

        cout << endl << "Dopisane indeksy w hasle:";

    //wydluzam indexy, zeby tablica miala taka sama dlugosc jak tajne
    for(int i=haslo.length(); i<tajne.length(); i++)
    {
        i_haslo[i]=i_haslo[i-haslo.length()];
        cout << "[" << i << "]" << i_haslo[i] << endl;
    }

    int i_tajne[tajne.length()];
    cout << "Tajne: ";
    //tworze tablice indexow liter z tajnego
    for (int i=0; i<tajne.length(); i++)
    {
        for(int j=0;j<26; j++)
        {
            if (tajne[i] == tab[0][j])
            {
                i_tajne[i]=j;
                cout << i_tajne[i] << endl;
            }
        }
    }

    //odszyfruje
    cout << endl << "Indexy jawne: ";
    int i_jawne[tajne.length()];
   for (int j=0; j<tajne.length(); j++) //j to indeks litery slowa, ktora jest szyfrowana
    {
        for(int i=0; i<26; i++)
        {
            if(tajne[j] == tab[i_haslo[j]][i])
            {
                i_jawne[j]=i;
                cout << i_jawne[j];
            }
        }

    }
    cout << endl << "Jawne: ";
    for(int i=0; i<tajne.length(); i++)
    {
        jawne[i]=tab[0][i_jawne[i]];
        cout << jawne[i];
    }
}
