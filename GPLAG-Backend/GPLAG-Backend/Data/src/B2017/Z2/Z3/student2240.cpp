/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename tip>
int Pronalazak_Perioda (const std::vector<tip> &v)
{
    int T = 0;
    int razlika = 2;
    while (true)
    {
        bool periodican = true;
        int a = razlika;
        int b = razlika+razlika;
        
        while (true)
        {
            for (int i{}; i<razlika;i++)
            {
                if (a == v.size())
                    break;
                    
                if (v[a]!=v[i])
                {
                    periodican = false;
                    break;
                }
                
                a++;
            }
            
            if (periodican == false)
                break;
                
            if (a == v.size())
                break;
            
            a = b;
            b += razlika;
        }
        
        if (periodican == true)
        {
            T = razlika;
            break;
        }
        
        
        razlika++;
    }
    
    if (T == v.size())
        T = 0;
    
    
    return T;
}

template <typename tip>
int** AlocirajFragmentirano (const std::vector<tip> &v, int &koliko_puta)
{
    if (v.size() == 0)
        throw std::domain_error ("Prazan vektor!");
        
    
    for (int i{};i<v.size();i++)
    {
        if (v[i]<=0)
            throw std::domain_error ("Neispravan vektor!");
    }
    
    int T = Pronalazak_Perioda(v);
    
    if (T != 0)
    {
        int a = v.size();
        
        while(true)
        {
            if (a%T == 0)
            {
                koliko_puta = a/T;
                break;
            }
            
            a++;
        }
    }
    else
    {
        T = v.size();
        koliko_puta = 2;
    }
    
    int** matrica = nullptr;
    int redovi = koliko_puta*T;
    
    int najveci = 0;
    
    for (int i{};i<T;i++)
    {
        if (v[i] > najveci)
            najveci = v[i];
    }
    
    
    try
    {
        matrica = new int* [redovi];
        for (int i{};i<redovi;i++)
            matrica[i] = nullptr;
    }
    catch(...)
    {
        delete [] matrica;
        matrica = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    int k = 0;
    try
    {
        for (int i{};i<koliko_puta;i++)
        {
            for (int j{};j<T;j++)
            {
                matrica[k] = new int [v[j]];
                k++;
            }
        }
    }
    catch(...)
    {
        for (int i{};i<redovi;i++)
            delete [] matrica[i];
        delete [] matrica;
        matrica = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    k = 0;
    for (int i{}; i<redovi;i++)
    {
        if (k == T)
            k = 0;
        
        int granica = v[k];
        int pomocni = najveci-v[k]+1;
        for (int j{};j<granica;j++)
            matrica[i][j] = pomocni++;
            
        k++;
    }
    
    
    return matrica;
}

template <typename tip>
int** AlocirajKontinualno (const std::vector<tip> &v, int &koliko_puta)
{
    if (v.size() == 0)
        throw std::domain_error ("Prazan vektor!");
        
    
    for (int i{};i<v.size();i++)
    {
        if (v[i]<=0)
            throw std::domain_error ("Neispravan vektor!");
    }
    
    int T = Pronalazak_Perioda(v);
    
    if (T != 0)
    {
        int a = v.size();
        
        while(true)
        {
            if (a%T == 0)
            {
                koliko_puta = a/T;
                break;
            }
            
            a++;
        }
    }
    else
    {
        T = v.size();
        koliko_puta = 2;
    }
    
    int** matrica = nullptr;
    int redovi = koliko_puta*T;
    
    int najveci = 0;
    
    for (int i{};i<T;i++)
    {
        if (v[i] > najveci)
            najveci = v[i];
    }
    
    
    try
    {
        matrica = new int* [redovi];
        for (int i{};i<redovi;i++)
            matrica[i] = nullptr;
    }
    catch(...)
    {
        delete [] matrica;
        matrica = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    int k = 0;
    try
    {
        matrica[0] = new int [redovi*najveci];
        
        for (int i{};i<koliko_puta;i++)
        {
            for (int j{};j<T;j++)
            {
                if (i == 0 && j == 0)
                    k++;
                else
                {
                    if (i == 1 && j == 0)
                        matrica[k] = matrica[k-1] + v[j]+1;
                    else
                        matrica[k] = matrica[k-1] + v[j];
                    k++;
                }
            }
        }
    }
    catch(...)
    {
        delete [] matrica[0];
        delete [] matrica;
        matrica = nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    k = 0;
    for (int i{}; i<redovi;i++)
    {
        if (k == T)
            k = 0;
        
        int granica = v[k];
        int pomocni = v[k];
        for (int j{};j<granica;j++)
            matrica[i][j] = pomocni--;
            
        k++;
    }
    
    
    return matrica;
}








int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    
    try
    {
        std::cout<<"Unesite elemente vektora: ";
        std::vector<int> v (n);
        for (int i{};i<n;i++)
            std::cin>>v[i];
        
        
        std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        int f;
        std::cin>>f;
        
        int koliko_puta;
        int **matrica = nullptr;
        if (f == 1)
            matrica = AlocirajFragmentirano(v,koliko_puta);
        else
            matrica = AlocirajKontinualno(v,koliko_puta);
            
        std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
        int T = Pronalazak_Perioda(v);
        
        if (T == 0)
            T = v.size();
            
        int k = 0;
        for (int i{};i<koliko_puta*T;i++)
        {
            if (k == T)
                k = 0;
                
            int granica = v[k];
            for (int j{};j<granica;j++)
                std::cout<<std::left<<std::setw(3)<<matrica[i][j];
            std::cout<<std::endl;
            k++;
        }
        
        if (f == 1)
        {
            for (int i{};i<koliko_puta*T;i++)
                delete [] matrica[i];
            delete [] matrica;
            matrica = nullptr;
        }
        else
        {
            delete [] matrica[0];
            delete [] matrica;
            matrica = nullptr;
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch (...)
    {
        std::cout<<"Izuzetak: Nedovoljno memorije.";
    }
    
    
    
    
    
    
    
    
	return 0;
}