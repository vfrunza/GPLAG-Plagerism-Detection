// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <iomanip>
#include <vector>
#include <type_traits>
#include <deque>

using namespace std;

enum class SmjerKretanja
{
    NaprijedNazad = 0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5
};

template <typename kont>
auto IzdvojiDijagonale3D (kont kontejner, SmjerKretanja Smjer) -> typename remove_reference<decltype(kontejner.at(0))>::type
{
    typename remove_reference<decltype(kontejner.at(0))>::type rezultat; 
    
    int j = 0;
    int k = 0;
    
    int max_i = kontejner.size()-1;
    int max_j = kontejner.at(0).size()-1;
    int max_k = kontejner.at(0).at(0).size()-1;
    
    if (Smjer == SmjerKretanja::GoreDolje)
    {
        for(int razina = 0; razina <= max_j; razina++)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            k = 0;
            for(int redovi = 0; redovi <= max_i; redovi++)
            {
                unutarnji.push_back(kontejner[max_i-redovi][razina][k]);
                k++;
            }
                
            rezultat.push_back(unutarnji);
        }
    }
    else if(Smjer == SmjerKretanja::DoljeGore)
    {
        for(int razina = max_j; razina >= 0; razina--)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            k = max_k;
            for(int redovi = 0; redovi <= max_i; redovi++)
            {
                unutarnji.push_back(kontejner[max_i-redovi][razina][k]);
                k--;
            }
            
            rezultat.push_back(unutarnji);
        }
    }
    else if(Smjer == SmjerKretanja::NaprijedNazad)
    {
        for(int razina = 0; razina <= max_i; razina++)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            k = 0;
            for(int redovi = 0; redovi <= max_j; redovi++)
            {
                unutarnji.push_back(kontejner[razina][redovi][k]);
                k++;
            }
            
            rezultat.push_back(unutarnji);
        }
    }
    else if(Smjer == SmjerKretanja::NazadNaprijed)
    {
        for(int razina = max_i; razina >= 0; razina--)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            k=max_k;
            for(int redovi = 0; redovi <= max_j; redovi++)
            {
                unutarnji.push_back(kontejner[razina][redovi][k]);
                k--;
            }
            rezultat.push_back(unutarnji);
        }
    }
    else if(Smjer == SmjerKretanja::DesnoLijevo)
    {
        for(int razina = max_k; razina >= 0; razina--)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            j = 0;
            for(int redovi = 0; redovi <= max_i; redovi++)
            {
                unutarnji.push_back(kontejner[redovi][j][razina]);
                j++;
            }
            rezultat.push_back(unutarnji);
        }
    }
    else if(Smjer == SmjerKretanja::LijevoDesno)
    {
        for(int razina = 0; razina <= max_k; razina++)
        {
            typename remove_reference<decltype(kontejner.at(0).at(0))>::type unutarnji;
            j = 0;
            for(int redovi = 0; redovi <= max_i; redovi++)
            {
                unutarnji.push_back(kontejner[max_i-redovi][j][razina]);
                j++;
            }
            rezultat.push_back(unutarnji);
        }
    }
    
    return rezultat;
}

int main ()
{
    vector<deque<deque<int> > > uneseni ;
    
    int x,y,z;
    
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    
    if(x < 0 || y < 0 || z < 0)
    {
        cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    cout << "Unesite elemente kontejnera: " << endl;
    
    for(int i = 0; i < x; i++)
    {
        deque<deque<int>> temp1;
        for(int j = 0; j < y; j++)
        {
            deque<int> temp2;
            for(int k = 0; k < z; k++)
            {
                int temp;
                cin >> temp;
                temp2.push_back(temp);
            }
            
            temp1.push_back(temp2);
        }
        uneseni.push_back(temp1);
    }
    
    int pravac;
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    cin >> pravac;
    
    if(pravac < 0 || pravac > 5 )
    {
        cout << "Smjer kretanja nije ispravan!" << endl;
        return 0;
    }
    
    SmjerKretanja s = (SmjerKretanja)pravac;
    
    auto matrica = IzdvojiDijagonale3D (uneseni, s);
    
    switch(pravac)
    {
        case 0:
            cout << "NaprijedNazad: " << endl;
            break;
            
        case 1:
            cout << "NazadNaprijed: " << endl;
            break;
            
        case 2:
            cout << "GoreDolje: " << endl;
            break;
            
        case 3:
            cout << "DoljeGore: " << endl;
            break;
            
        case 4:
            cout << "LijevoDesno: " << endl;
            break;
            
        case 5:
            cout << "DesnoLijevo: " << endl;
            break;
    }
    
    for(int i = 0; i < matrica.size(); i++)
    {
        for(int j = 0; j < matrica.at(i).size(); j++)
        {
            cout << setw(4) << matrica[i][j] ;
        }
        cout << endl;
    }
    
	return 0;
}