//B 2016/2017, Zadaća 1, Zadatak 3

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;
typedef std::vector<double> vektor;




matrica RastuciPodnizovi(vektor ulaz);
matrica OpadajuciPodnizovi(vektor ulaz);


int main ()
{

    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    
    std::cin >> n;

    std::cout << "Unesite elemente vektora: ";

    double broj;
    vektor ulaz;

    for(int i = 0; i < n; i++) {
        std::cin >> broj;
        ulaz.push_back(broj);
    }

    matrica Rastuci(RastuciPodnizovi(ulaz));
    std::cout << "Maksimalni rastuci podnizovi: ";

    for(auto x: Rastuci) {
        std::cout << std::endl;
        for(double y : x)
            std::cout << y << " ";
    }
    std::cout << std::endl << "Maksimalni opadajuci podnizovi: ";
    matrica Opadajuci(OpadajuciPodnizovi(ulaz));
    for(auto x: Opadajuci) {
        std::cout << std::endl;
        for(double y : x) //↓↓↓ maksimalan broj decimala koji neki broj može imati je 16, najveći int može imati 10 cifara pa zato obezbjeđujem 25 mjesta
            std::cout << std::setprecision(25) << y << " "; //ako budem koristio std::fixed onda će i brojevi koji ne trebaju imat decimale
            //uzeo sam sebi slobodu da pretpostavim da neće biti unošen broj sa više od 10 cifara bez decimala
    }

    return 0;
}

matrica RastuciPodnizovi(vektor ulaz)
{
           
                //↓↓↓↓ 16 decimala jer double moze primiti max 16 decimala 
    const double EPSILON(0.0000000000000001);
    matrica podniz(1);                  //potrebno da ima makar 1 red na početku
    int j(0);
    
    //ako je nula vektor onda nema potrebe da išta radi
    if (ulaz.size() < 1)
        return podniz;

    //pravimo rastući podniz
    for(int i = 0; i < ulaz.size()-1; i++) {

        if(ulaz[i] < ulaz[i+1] || fabs(ulaz[i]-ulaz[i+1]) < EPSILON)
            podniz[j].push_back(ulaz[i]);

        else if(podniz[j].size() != 0) {
            podniz[j].push_back(ulaz[i]);
            podniz.resize(podniz.size()+1);
            j++;
        }
    }

    //zadnji član ako ispunjava uslove dodaj                                                ↓↓↓↓ testire da li su varijable tipa double jednake
    if(podniz[j].size() != 0 && (podniz[j][podniz[j].size()-1] < ulaz[ulaz.size()-1] || fabs(podniz[j][podniz[j].size()-1] - ulaz[ulaz.size()-1]) < EPSILON))
        podniz[j].push_back(ulaz[ulaz.size()-1]);

    return podniz;
}

matrica OpadajuciPodnizovi(vektor ulaz)
{           //↓↓↓↓ 16 decimala jer double moze primiti max 16 decimala
    const double EPSILON(0.0000000000000001);

    matrica podniz(1);  //potrebno da ima makar 1 red na početku
    int j(0);
    
    if (ulaz.size() < 1)    //nema potrebe da išta radi ako je prazan ulaz
        return podniz;
        
    //pravimo opadajući podniz
    for(int i = 0; i < ulaz.size()-1; i++) {

        if(ulaz[i] > ulaz[i+1] || fabs(ulaz[i]-ulaz[i+1]) < EPSILON)
            podniz[j].push_back(ulaz[i]);

        else if(podniz[j].size() != 0) {
            podniz[j].push_back(ulaz[i]);
            podniz.resize(podniz.size()+1);
            j++;
        }
    }
    //zadnji član ako ispunjava uslove dodaj                                                ↓↓↓↓ testire da li su varijable tipa double jednake
    if(podniz[j].size() != 0 && (podniz[j][podniz[j].size()-1] > ulaz[ulaz.size()-1] || fabs(podniz[j][podniz[j].size()-1] - ulaz[ulaz.size()-1]) < EPSILON))
        podniz[j].push_back(ulaz[ulaz.size()-1]);

    return podniz;
}

