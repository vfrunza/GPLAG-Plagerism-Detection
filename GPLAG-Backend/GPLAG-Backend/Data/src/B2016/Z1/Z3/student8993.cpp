#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

typedef vector<vector<double>> Vektor_vektora;
typedef vector<double> Vektor;


Vektor_vektora RastuciPodnizovi(Vektor niz)
{
    Vektor_vektora podnizovi;
    podnizovi.resize(niz.size());
    Vektor pomocni;
    int brojac_redova = 0;
    int brojac_podnizova = 0;
    if(niz.size() == 0)
        throw domain_error("Poslali ste prazan niz");
    for(int i(1); i < niz.size(); i++)
    {
        if(niz[i-1] < niz[i])
        {
            pomocni.push_back(niz[i-1]);
        }
        if(i > 2)
        {
            if((niz[i] < niz[i-1] || fabs(niz[i] - niz[i-1]) < 0.0000000001) && (niz[i-1] > niz[i-2] || fabs(niz[i-1] - niz[i-2]) < 0.0000000001))
            {
                pomocni.push_back(niz[i-1]);
                podnizovi[brojac_redova].resize(pomocni.size());
                podnizovi[brojac_redova++] = pomocni;
                pomocni.clear();
                brojac_podnizova++;
            }
            if(i == niz.size() - 1)
            {
                if(niz[i] > niz[i-1] || fabs(niz[i] - niz[i-1]) < 0.0000000001)
                {
                    pomocni.push_back(niz[i]);
                    podnizovi[brojac_redova++] = pomocni;
                    brojac_podnizova++;
                }
            }
        }
    }
    podnizovi.resize(brojac_podnizova);

    return podnizovi;
}

Vektor_vektora OpadajuciPodnizovi(Vektor niz)
{
    Vektor_vektora podnizovi;
    podnizovi.resize(niz.size());
    Vektor pomocni;
    int brojac_redova = 0;
    int brojac_podnizova = 0;
    for(int i(1); i < niz.size(); i++)
    {
        if(niz[i-1] > niz[i] || fabs(niz[i-1] - niz[i]) < 0.0000000001)
        {
            pomocni.push_back(niz[i-1]);
        }
        if(i > 2)
        {
            if((niz[i] > niz[i-1] || fabs(niz[i] - niz[i-1]) < 0.0000000001) && (niz[i-1] < niz[i-2] || fabs(niz[i-1] - niz[i-2]) < 0.0000000001))
            {
                pomocni.push_back(niz[i-1]);
                podnizovi[brojac_redova].resize(pomocni.size());
                podnizovi[brojac_redova++] = pomocni;
                pomocni.clear();
                brojac_podnizova++;
            }
            if(i == niz.size() - 1)
            {
                if(niz[i] < niz[i-1] || fabs(niz[i] - niz[i-1]) < 0.0000000001)
                {
                    pomocni.push_back(niz[i]);
                    podnizovi[brojac_redova++] = pomocni;
                    brojac_podnizova++;
                }
            }
        }
    }
    podnizovi.resize(brojac_podnizova);

    return podnizovi;
}

int main()
{
    try{
        Vektor test;
        int broj_elemenata;
        cout << "Unesite broj elemenata vektora: ";
        cin >> broj_elemenata;
    
        cout << "Unesite elemente vektora: ";
    
        for(int i = 0; i < broj_elemenata; i++)
        {
            double n;
            cin >> n;
            test.push_back(n);
        }
    
        Vektor_vektora v = RastuciPodnizovi(test);
    
        cout << "Maksimalni rastuci podnizovi: " << endl;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    
        v = OpadajuciPodnizovi(test);
        cout << "Maksimalni opadajuci podnizovi: " << endl;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }    
    }
    catch(domain_error err){
        cout << "Izuzetak: " << err.what();
    }
    

    return 0;
}
