#include<iostream>
#include<vector>
#include<deque>
#include<stdexcept>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip>
auto IzdvojiDijagonale3D(tip v,SmjerKretanja t)->typename std::remove_reference<decltype(*v.begin())>::type{
    int n,k;
    for(int i=0;i<v.size();i++)     //  Provjera da li svaki red ima isti broj elemenata.
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(i==0&&j==0)
                n=v[0][0].size();
            if(v[i][j].size()!=n)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i=0;i<v.size();i++)     //  Provjera da li svaka ploha ima isti broj elemenata.
    {
        if(i==0) k=v[0].size();
        if(v[i].size()!=k)
            throw std::domain_error("Plohe nemaju isti broj redova");
    }
    typename std::remove_reference<decltype(*v.begin())>::type q;       //  q nam je matrica koju vracamo iz ove funkcije.
    if(t==SmjerKretanja::NaprijedNazad||t==SmjerKretanja::NazadNaprijed)    //  Princip rada je takav, da se u svaka 2 smjera kretanja vidimo slicnost (izmedju NaprijedNazad, NazadNaprijed itd..). Mijenjaju se samo neke ove granice, a i nacin na koji gledamo date redove, odnosno kolone.
    {
        q.resize(v.size());
        for(int i=0;i<q.size();i++)
            q[i].resize(v[0].size());
        int n=0,k=0,p=1;    // n ovdje sluzi za prolazak kroz redove, k je tu za clanove u redu, a p je neki brojac pomocu kog se krecemo gore, dolje, lijevo ili desno.
        if(t==SmjerKretanja::NazadNaprijed)
        {
            p=-1;
            n=v.size()-1;
        }
        for(int i=0;i<v.size();i++)
        {    
            if(t==SmjerKretanja::NazadNaprijed)
                k=v[0][0].size()-1;
            else
                k=0;
            for(int j=0;j<v[i].size();j++)
            {    
                q.at(i).at(j)=v.at(n).at(j).at(k);
                k+=p;
            }
            n+=p;
        }
    }
    else if(t==SmjerKretanja::GoreDolje||t==SmjerKretanja::DoljeGore)
    {
        q.resize(v[0].size());
        for(int i=0;i<v[0].size();i++)
            q.at(i).resize(v.size());
        int n=0,k=0,p=1;
        if(t==SmjerKretanja::DoljeGore)
        {
            p=-1;
            n=v[0][0].size()-1;
        }
        for(int i=0;i<v.size();i++)
        {
            if(t==SmjerKretanja::DoljeGore)
                k=v[0].size()-1;
            else
                k=0;
            for(int j=0;j<v[0].size();j++)
            {
                q.at(j).at(i)=v.at(v.size()-1-i).at(k).at(n);
                k+=p;
            }
            n+=p;
        }
    }
    else if(t==SmjerKretanja::LijevoDesno||t==SmjerKretanja::DesnoLijevo)
    {
        q.resize(v[0][0].size());
        for(int i=0;i<q.size();i++)
            q.at(i).resize(v.size());
        int n=v.size()-1,p=1,k=0;
        if(t==SmjerKretanja::DesnoLijevo)
        {
            k=v[0][0].size()-1;
            p=-1;
            n=0;
        }
        for(int i=0;i<v.size();i++)
        {
            if(t==SmjerKretanja::DesnoLijevo)
                k=v[0][0].size()-1;
            else
                k=0;
            for(int j=0;j<v[0][0].size();j++)
            {
                q.at(j).at(i)=v.at(n).at(i).at(k);
                k+=p;
            }
            n-=p;
        }
    }
    return q;
}
int main ()
{                                           //  Obicni main za unos, ispitivanje tacnosti podataka, hvatanje izuzetaka i ispisivanja elemenata na ekran. 
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<0||y<0||z<0)
    {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> q;
    q.resize(x);
    for(int i=0;i<x;i++)
    {    q.at(i).resize(y);
            for(int j=0;j<y;j++)
                q.at(i).at(j).resize(z);
    }
                
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            for(int k=0;k<z;k++)
                std::cin>>q[i][j][k];
    std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
    int n;
    std::cin>>n;
    if(n<0||n>5)
    {
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    SmjerKretanja t=SmjerKretanja(n);
    try{
    auto p=IzdvojiDijagonale3D (q, t);
    switch(n)
    {
        case 0 :std::cout<<"NaprijedNazad:"<<std::endl; break;
        case 1 :std::cout<<"NazadNaprijed:"<<std::endl; break;
        case 2 :std::cout<<"GoreDolje:"<<std::endl; break;
        case 3 :std::cout<<"DoljeGore:"<<std::endl; break;
        case 4 :std::cout<<"LijevoDesno:"<<std::endl; break;
        case 5 :std::cout<<"DesnoLijevo:"<<std::endl; break;
    }
    for (const auto &red : p)
        {
            for (const auto &x : red)
                std::cout.width (4), std::cout << x;
            std::cout << std::endl;
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
	return 0;
}