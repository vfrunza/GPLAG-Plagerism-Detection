#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

string pomocna_fja(string rijec)
{
    int i = 0, j = rijec.length() - 1;
    string obrnuta = rijec;
    while(rijec[i] != 0)
    {
        obrnuta[j--] = rijec[i++];
    }

    return obrnuta;
}

string obrni_rijec(string rijec)
{
    int i = 0;
    int brojac = 0;
    string obrnut;
    vector<string> vise_njih;
    string obrnuta;
    do
    {
        while(rijec[i] != ' ' && rijec[i] != '\0')
        {
            brojac++;
            i++;
        }

        string nova = rijec.substr(i-brojac, brojac);

        obrnut = pomocna_fja(nova);

        vise_njih.push_back(obrnut);

        if(i != (rijec.length()) && rijec[i+1] != 0)
        {
            string razmak = " ";
            vise_njih.push_back(razmak);
        }

        brojac = 0;
    }
    while(rijec[i++] != 0);

    for(string dio : vise_njih)
    {
        obrnuta += dio;
    }

    return obrnuta;
}

string ObrniFraze(string recenica, vector<string> fraze)
{
    for(string r : fraze)
    {
        int i = 0, j = 0;
        while(i < recenica.length())
        {
            if(recenica[i] == r[j])
            {
                while(j < r.length())
                {
                    if(r[j] == recenica[i])
                    {
                        j++;
                        i++;
                    }
                    else
                        break;
                }

                if(j == r.length())
                {
                    int brojac = i - j;
                    string obrnuta = obrni_rijec(r);
                    int k = 0;
                    while(obrnuta[k] != 0)
                    {
                        recenica[brojac++] = obrnuta[k++];
                    }
                }
                else continue;
            }
            i++;
        }
    }

    return recenica;
}

bool ispitaj(string rijec)
{
    int i = 0;
    while(rijec[i] != 0)
    {
        if((rijec[i] > 90 && rijec[i] < 97) || rijec[i] < 65 || rijec[i] > 122)
            return false;
        i++;
    }

    return true;
}

string dodaj_ay(string rijec)
{
    string dodatak = rijec;
    char prvo_slovo = rijec[0];
    dodatak.resize(rijec.length()+1);
    dodatak[rijec.length()] = prvo_slovo;
    
    for(int i(0); i < dodatak.length(); i++){
        dodatak[i] = dodatak[i+1];
        if(i == dodatak.length() - 2)
            dodatak.resize(dodatak.length() - 1);
    }

    return dodatak;
}

string IzmijeniUPigLatin(string recenica, vector<string> rijeci)
{
    for(string provjera : rijeci)
    {
        if(!ispitaj(provjera))
            throw domain_error("Nekorektan izbor rijeci");
    }

    for(string provjera : rijeci)
    {
        int i = 0, j = 0;
        while(i < recenica.length())
        {
            if(recenica[i] == provjera[j])
            {
                while(j < provjera.length())
                {
                    if(recenica[i] == provjera[j])
                    {
                        i++;
                        j++;
                    }
                    else break;
                }

                if(j == provjera.length())
                {
                    int brojac = i - j;
                    string dodatak = dodaj_ay(provjera);
                    int k = 0;
                    while(k < dodatak.length())
                    {
                        recenica[brojac++] = dodatak[k++];
                    }

                    string ay = "ay";
                    recenica.insert(brojac, ay);
                }
                else continue;
            }
            i++;
        }
    }

    return recenica;
}

int main()
{
    cout << "Unesite recenicu: ";
    string recenica, rijec;
    vector<string> fraze;
    
    getline(cin, recenica);
    cout << "Unesite fraze: ";
    while(1){
        getline(cin, rijec);
        fraze.push_back(rijec);
        if(rijec.size() == 0)
            break;
    }
    string pigtolatin;
    try{
        pigtolatin = IzmijeniUPigLatin(recenica, fraze);
    }
    catch(domain_error err){
        cout << "Izuzetak: " << err.what() << endl;
        cout << "Recenica nakon obrtanja fraza: ";
        string obrni = ObrniFraze(recenica, fraze);
        cout << obrni;
        return 0;
    }
    cout << "Recenica nakon PigLatin transformacije: ";
    cout << pigtolatin << endl;
    
    cout << "Recenica nakon obrtanja fraza: ";
    string obrni = ObrniFraze(recenica, fraze);
    cout << obrni;

    return 0;
}
