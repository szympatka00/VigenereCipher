#include <iostream>
#include <string>
#include <cmath>

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

    for (int i=0; i<26; i++)
    {
        cout << tab[0][i];
    }
    cout << endl << "Podaj haslo i slowo jawne. Haslo:" << endl;
    cin >> haslo;
    cout << endl << "Slowo jawne:" <<endl;
    cin >> jawne;
    cout << endl;

    int i_haslo[jawne.length()];

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

    for(int i=haslo.length()-1; i>=0; i--)
    {
        for (int j=0; j<haslo.length(); j++)
        {
            if (haslo[i] == haslo[j])
            {

            }
        }

    }

    int i_jawne[jawne.length()];
    cout << "Jawne: ";
    //tworze tablice indexow liter z jawnego
    for (int i=0; i<jawne.length(); i++)
    {
        for(int j=0;j<26; j++)
        {
            if (jawne[i] == tab[0][j])
            {
                i_jawne[i]=j;
                cout << i_jawne[i] << endl;
            }
        }
    }

        cout << endl << "Dopisane indeksy w hasle:";

    //wydluzam indexy, zeby tablica miala taka sama dlugosc jak jawne
    for(int i=haslo.length(); i<jawne.length(); i++)
    {
        i_haslo[i]=i_haslo[i-haslo.length()];
        cout << "[" << i << "]" << i_haslo[i] << endl;
    }

    cout << endl << "Tajne: ";

    //szyfruje
   for (int j=0; j<jawne.length(); j++) //j to indeks litery slowa, ktora jest szyfrowana
    {
        tajne[j]=tab[i_haslo[j]][i_jawne[j]];
        cout << tajne[j];

    }

}
