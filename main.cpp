#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

struct transportas
{
    string pav;
    double km;
};

void nuskaitymas();
void skaiciavimai();
void spausdinimas();
int laikas(double ats, int gr);

int n, greit, val, minu, L[100];
transportas A[100];

int main()
{
    nuskaitymas();
    skaiciavimai();
    spausdinimas();
    return 0;
}

void nuskaitymas()
{
    char eil[15];
    ifstream fd("duom.txt");
    fd>> n>> greit >> val >> minu;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 15); // zahvatyvaju 15 simvolov na etoj strochke chto by sohranit ih kak nazvanie
        A[i].pav = eil; // vvozhu v structuru massive eto nazvanie
        fd >> A[i].km; //vvozhu rastojanie v structuru v massive
        fd.ignore();
    }
    fd.close();
}

int laikas(double ats, int gr)
{
    int trukme;
    trukme = round(ats/gr*60);
    return trukme;
}

void skaiciavimai()
{
     for(int i=0; i<n; i++)
        L[i] = laikas(A[i].km, greit);
}

void spausdinimas()
{
    ofstream fr("rez.txt");
    for(int i = 0; i<n; i++)
    {
        val = val + (minu + L[i])/60;
        minu = (minu + L[i]) % 60;
        fr << A[i].pav << val << " val." << minu << " min." << endl;
    }
    fr.close();
}
