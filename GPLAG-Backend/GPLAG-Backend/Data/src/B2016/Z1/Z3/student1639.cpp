#include <iostream>
#include <vector>
#include <cmath>
#define EPS 0.0000000000000001

using namespace std;

typedef vector<vector<double>> Matrica;
typedef vector<double> Vektor;

void IspisiMatricu (Matrica matrica)
{
    for(unsigned int i=0; i<matrica.size(); i++) {
        for(unsigned int j=0; j<(matrica.at(i)).size(); j++ ) {
            cout << (matrica.at(i)).at(j) << " ";
        }
        cout << endl;
    }
}

bool Prethodnik (double a, double b)
{
    return b < a or abs(b - a) < EPS;
}

Matrica OpadajuciPodnizovi (Vektor pocetni)
{
    Matrica opadajuci;
    Vektor pomocni, maksimalni;
    int i(0);
    
    while(i not_eq pocetni.size()) //dok nismo dosli do kraja originalnog niza
    {
        if(i not_eq pocetni.size()-1 and Prethodnik(pocetni.at(i), pocetni.at(i+1))) pomocni.push_back(pocetni.at(i)); // ako je naredni element veci od trenutnog to je rastuci niz
        else if (i==pocetni.size()-1 and Prethodnik(pocetni.at(i-1), pocetni.at(i))) pomocni.push_back(pocetni.at(i)); // ako smo dosli do kraja provjeriti jel krajnji veci od prethodnika jer nemamo sljedbenika da usporedimo
        else if (pomocni.size() not_eq 0 )
        {
            pomocni.push_back(pocetni.at(i));
            if(pomocni.size()>maksimalni.size()) // ako je pronadeni vektor veci i nema veceg negdje drugo unutar orig niza
            {
                maksimalni.resize(pomocni.size());
                maksimalni=pomocni;
            }
        
         opadajuci.push_back(pomocni);
         pomocni.resize(0); // oslobodi za nove maksimalne nebitno jel pronadeni maksimalan ili obican podniz maksimalnog
        
        }
        
        i++; // prolazimo kroz elemente
    }
    if ( pomocni.size() not_eq 0 )
        opadajuci.push_back( pomocni );
   
    return opadajuci;
}


bool Sljedbenik (double a, double b)
{
    return b>a or abs(b-a) < EPS;
}

Matrica RastuciPodnizovi (Vektor pocetni)
{
    Matrica rastuci;
    Vektor pomocni, maksimalni;
    int i(0);
    
    while(i not_eq pocetni.size()) //dok nismo dosli do kraja originalnog niza
    {
        if(i not_eq pocetni.size()-1 and Sljedbenik(pocetni.at(i), pocetni.at(i+1))) pomocni.push_back(pocetni.at(i)); // ako je naredni element veci od trenutnog to je rastuci niz
        else if (i==pocetni.size()-1 and Sljedbenik(pocetni.at(i-1), pocetni.at(i))) pomocni.push_back(pocetni.at(i)); // ako smo dosli do kraja provjeriti jel krajnji veci od prethodnika jer nemamo sljedbenika da usporedimo
        else if (pomocni.size() not_eq 0 )
        {
            pomocni.push_back(pocetni.at(i));
            if(pomocni.size()>maksimalni.size()) // ako je pronadeni vektor veci i nema veceg negdje drugo unutar orig niza
            {
                maksimalni.resize(pomocni.size());
                maksimalni=pomocni;
            }
        
         rastuci.push_back(pomocni);
         pomocni.resize(0); // oslobodi za nove maksimalne nebitno jel pronadeni maksimalan ili obican podniz maksimalnog
        
        }
        
        i++; // prolazimo kroz elemente
    }
    if ( pomocni.size() not_eq 0 )
        rastuci.push_back( pomocni );
   
    return rastuci;
}

int main()
{
    int brel(0);
    double element(0);
    Vektor pocetni;
    cout << "Unesite broj elemenata vektora: ";
    cin >> brel;
    cout << "Unesite elemente vektora: " ;
    while(brel>0) {
        cin >> element;
        pocetni.push_back(element);
        brel--;
    }
    cout << "Maksimalni rastuci podnizovi: " << endl;
    IspisiMatricu(RastuciPodnizovi(pocetni));

    cout << "Maksimalni opadajuci podnizovi: " << endl;
    IspisiMatricu(OpadajuciPodnizovi(pocetni));
    cout << endl;
    return 0;
}