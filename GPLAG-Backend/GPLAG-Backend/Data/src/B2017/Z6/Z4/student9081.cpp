/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>

template <typename T>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner (const std::string &ime);
    void DodajNoviElement (const T &element);
    int DajBrojElemenata ();
    T DajElement (int pozicija);
    void IzmijeniElement (int pozicija, const T &element);
    void Sortiraj (std::function<bool(const T &,const T &)> kriterij=std::less<T> ());
};

template <typename T>
DatotecniKontejner<T>::DatotecniKontejner (const std::string &ime)
{
    tok.open(ime,std::ios::binary | std::ios::in);
    if (!tok)
    {
        tok.clear();
        tok.open(ime,std::ios::binary | std::ios::out);
    }
    tok.close();
    tok.open(ime,std::ios::binary | std::ios::in | std::ios::out);
    if (tok.bad() || tok.fail()) throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
}

template <typename T>
void DatotecniKontejner<T>::DodajNoviElement (const T &element)
{
    tok.seekp(0,std::ios::end);
    tok.write(reinterpret_cast<const char *> (&element),sizeof element);
    tok.seekg(0,std::ios::end);
    if (tok.bad() || tok.fail()) throw std::logic_error ("Problemi prilikom pristupa datoteci");
}

template <typename T>
int DatotecniKontejner<T>::DajBrojElemenata()
{
    tok.seekg(0,std::ios::end);
    if (tok.bad() || tok.fail()) throw std::logic_error ("Problemi prilikom pristupa datoteci");
    return tok.tellg()/(sizeof (T));
}

template <typename T>
T DatotecniKontejner<T>::DajElement (int pozicija)
{
    if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error ("Neispravna pozicija");
    T pomocna;
    tok.seekg(pozicija*sizeof (T));
    tok.read(reinterpret_cast<char *> (&pomocna), sizeof pomocna);
    if (tok.bad() || tok.fail()) throw std::logic_error ("Problemi prilikom pristupa datoteci");
    return pomocna;
}

template <typename T>
void DatotecniKontejner<T>::IzmijeniElement (int pozicija, const T &element)
{
    if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error ("Neispravna pozicija");
    tok.seekp(pozicija*sizeof(T));
    tok.write(reinterpret_cast<const char *> (&element),sizeof element);
    if (tok.bad() || tok.fail()) throw std::logic_error ("Problemi prilikom pristupa datoteci");
}

template <typename T>
void DatotecniKontejner<T>::Sortiraj (std::function<bool(const T &,const T &)> kriterij)
{
    int br(DajBrojElemenata());
    for (int i=0;i<br;i++)
    {
        T temp(DajElement(i));
        T temp2(temp);
        int poz(i);
        for (int j=i+1;j<br;j++)
        {
            T temp3(DajElement(j));
            if (kriterij(temp3,temp2))
            {
                temp2=temp3;
                poz=j;
            }
        }
        IzmijeniElement(i,temp2);
        IzmijeniElement(poz,temp);
    }
}


int main ()
{
    try {
    DatotecniKontejner<int> tok("pom.DAT");
    for (;;)
    {
        int n;
        std::cout<<"Odaberite jednu od opcija\n1 - Dodaj novi element\n2 - Pronadji element\n3 - Izmijeni element\n4 - Sortiraj\n5 - Kraj\n";
        std::cin>>n;
        try{
            if (n==1)
            {
                int x;
                std::cout<<"Unesite element koji se dodaje u datoteku: ";
                std::cin>>x;
                tok.DodajNoviElement(x);
            }
            else if (n==2)
            {
                int x;
                std::cout<<"Unesite poziciju elementa: ";
                std::cin>>x;
                    try{
                        std::cout<<"Element na poziciji "<<x<<" je "<<tok.DajElement(x)<<std::endl;}
                    catch(std::range_error r) {
                        std::cout<<r.what()<<std::endl;
                    }
            }
            else if (n==3)
            {
                int x,novi;
                std::cout<<"Unesite poziciju elementa: ";
                std::cin>>x;
                std::cout<<"Unesite novi element: ";
                std::cin>>novi;
                try{
                    tok.IzmijeniElement(x,novi);
                }
                catch(std::range_error r1) {
                    std::cout<<r1.what()<<std::endl;
                }
            }
            else if (n==4)
            {
                tok.Sortiraj();
                int br(tok.DajBrojElemenata());
                std::cout<<"Elementi sortirani u rastuci poredak glase: \n";
                for (int i=0;i<br;i++) std::cout<<tok.DajElement(i)<<" ";
                std::cout<<"\n";
            }
            else if (n==5) break;
        }
        catch(std::logic_error e1)
        {
            std::cout<<e1.what()<<std::endl;
        }
    }}
    catch (std::logic_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
