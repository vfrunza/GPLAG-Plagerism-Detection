/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename pok_it_1, typename pok_it_2, typename pok_it_3, typename tip1, typename tip2>
void SortirajPodrucjeVrijednosti (pok_it_1 p1, pok_it_1 p2, pok_it_2 p3, pok_it_3 p4, tip2 f1 (tip1,tip1), bool f2(tip1,tip1))
{
    
    std::sort(p1,p2,f2);
    
    pok_it_2 kraj_drugog = p3;
    pok_it_1 brojac = p1;
    
    while(brojac != p2)
    {
        brojac++;
        kraj_drugog++;
    }
    
    std::sort(p3,kraj_drugog,f2);
    
    brojac = p1;
    kraj_drugog = p3;
    
    pok_it_3 kraj_treceg = p4;
    while (brojac != p2)
    {
        brojac++;
        kraj_treceg++;
    }
    
    brojac = p1;
    
    
    while(brojac != p2)
    {
        tip2 rezultat = f1(*brojac, *kraj_drugog);
        
        auto pok = std::find(p4,kraj_treceg,rezultat);
        
        if (pok == kraj_treceg)
           throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
            
        pok_it_3 pozicija_treceg = p4;
        int n = 0;
        
        pok_it_1 pozicija_prvog = p1;
        
        while (pozicija_prvog != brojac)
        {
            pozicija_prvog++;
            pozicija_treceg++;
            n++;
        }
        
        tip2 temp = *pozicija_treceg;
        *pozicija_treceg = *pok;
        *pok = temp;
        
        brojac++;
        kraj_drugog++;
    }
}

bool Prost (int x)
{
    int brojac = 0;
    for (int i{2};i<=x;i++)
    {
        if (x%i==0)
            brojac++;
    }
    
    if (brojac == 1)
        return true;
        
    return false;
}


int Proracun (int x, int y)
{
    return -2*x+y;
}

bool Sortiranje (int x, int y)
{
    int kopija_x = x, kopija_y = y;
    
    int brojac_x = 0;
    
    if (x>1)
    {
        for (int i{2};i<=x;i++)
        {
            for (int j{i};j<=x;j++)
            {
                if (i*j == x)
                    brojac_x++;
            }
        }
    }
    
    int brojac_y = 0;
    
    if (y>1)
    {
        for (int i{2};i<=y;i++)
        {
            for (int j{i};j<=y;j++)
            {
                if (i*j == y)
                    brojac_y++;
            }
        }
    }
    
    if (brojac_x > brojac_y)
        return true;
        
    if (brojac_x == brojac_y)
        return kopija_x>kopija_y;
        
    return false;
}


int main ()
{
    std::cout<<"Unesite broj elemenata: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    
    std::cout<<"Unesite elemente prvog vektora: ";
    std::vector<int> v1;
    int i = 0;
    while (true)
    {
        if (v1.size() == n)
            break;
            
        int x;
        std::cin>>x;
        
        bool upisan = false;
        for (int j{};j<v1.size();j++)
        {
            if (x == v1[j])
                upisan = true;
        }
        
        if (upisan == false)
            v1.push_back(x);
    }
    
    std::cin.ignore(10000, '\n');
    
    std::cout<<"Unesite elemente drugog vektora: ";
    std::vector<int> v2;
    i = 0;
    while(true)
    {
        if (v2.size() == n)
            break;
        
        int x;
        std::cin>>x;
        
        bool upisan = false;
        for (int j{};j<v2.size();j++)
        {
            if (x == v2[j])
                upisan = true;
        }
        
        if (upisan == false)
            v2.push_back(x);
            
        i++;
    }
    
    std::cout<<"Unesite elemente treceg vektora: ";
    std::vector<int> v3;
    i = 0;
    while (true)
    {
        if (v3.size() == n)
            break;
            
        int x;
        std::cin>>x;
        
        bool upisan = false;
        for (int j{};j<v3.size();j++)
        {
            if (x == v3[j])
                upisan = true;
        }
        
        if (upisan == false)
            v3.push_back(x);
    }
    
    
    
    try
    {
        SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(), Proracun, Sortiranje);
    }
    catch(std::logic_error e)
    {
        std::cout<<std::endl<<"Izuzetak: "<<e.what();
        return 0;
    }
    
    std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
    
    for (i = 0;i<v1.size();i++)
        std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
    
    
    
	return 0;
}