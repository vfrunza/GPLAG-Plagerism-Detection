#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <vector>
 
bool TestPerioda(const std::vector<int> &brojevi, int p) //copy paste sa tuta
{
    int n=brojevi.size();
    if(n==1 || p>=n) return false;
    for(int i=0;i<n-p;i++)
    {
        if(brojevi.at(i)!=brojevi.at(i+p)) return false;
    }
    return true;
}
 
int OdrediOsnovniPeriod(const std::vector<int> &brojevi) //copy paste sa tuta
{
    int n=brojevi.size();
    for(int i=1;i<n;i++)
    {
        if(TestPerioda(brojevi,i)) return i;
    }
    return 0;
}
 
int** AlocirajKontinualno(const std::vector<int> &brojevi, int &koliko_puta)
{
    int **mat=nullptr;
    try
    {
        int p=OdrediOsnovniPeriod(brojevi);
        int n=brojevi.size();
        if(n==0) throw ("Prazan vektor!");
        if(p==0) p=n;
        int m=p-n%p;
        if(p==n) n*=2;
        if(m<p)
        {
            n+=m;
        }
       
        koliko_puta=n/p;
       
        int broj=0;
        for(int i=0;i<p;i++)
        {
            broj+=brojevi.at(i);
            if(brojevi.at(i)<=0) throw std::domain_error("Neispravan vektor!");
        }
        broj*=koliko_puta;
       
        mat=new int*[p*koliko_puta];
        mat[0]=new int[broj];
       
        int br(0);
        for(int i=0;i<brojevi.at(0);i++)
        {
            mat[0][i]=brojevi.at(0)-i;
            br++;
        }
        for(int i=1;i<p;i++)
        {
            mat[i]=mat[i-1]+br;
            br=0;
            for(int j=0;j<brojevi.at(i);j++)
            {
                mat[i][j]=brojevi.at(i)-j;
                br++;
            }
        }
        for(int i=1;i<koliko_puta;i++)
        {
            for(int j=0;j<p;j++)
            {
                mat[i*p+j]=mat[i*p+j-1]+br;
                br=0;
                for(int k=0;k<brojevi.at(j);k++)
                {
                    mat[i*p+j][k]=brojevi.at(j)-k;
                    br++;
                }
            }
        }
    }
    catch(std::bad_alloc)
    {
        delete[] mat;
        throw(std::bad_alloc());
    }
    return mat;
}
 
int** AlocirajFragmentirano(const std::vector<int> &brojevi, int &koliko_puta)
{
    int **mat=nullptr;
    int brojac(0); //brojac za brisanje memorije u catchu
    try
    {
        int p=OdrediOsnovniPeriod(brojevi);
        int n=brojevi.size();
        if(n==0) throw ("Prazan vektor!");
        if(p==0) p=n;
        int m=p-n%p;
        if(p==n) n*=2;
        if(m<p)
        {
            n+=m;
        }
       
        koliko_puta=n/p;
        int max=brojevi.at(0);
        for(int i=0;i<p;i++)
        {
            if(brojevi.at(i)>max) max=brojevi.at(i);
            if(brojevi.at(i)<=0) throw std::domain_error("Neispravan vektor!");
        }
       
        mat=new int*[p*koliko_puta];
       
        for(int i=0;i<p;i++)
        {
            mat[brojac++]=new int[brojevi.at(i)];
            for(int j=0;j<brojevi.at(i);j++)
            {
                mat[i][brojevi.at(i)-j-1]=max-j;
            }
        }
       
        for(int i=1;i<koliko_puta;i++)
        {
            for(int j=0;j<p;j++)
            {
                mat[brojac++]=new int[brojevi.at(j)];
                for(int k=0;k<brojevi.at(j);k++)
                {
                    mat[i*p+j][brojevi.at(j)-k-1]=max-k;
                }
            }
        }
    }
    catch(std::bad_alloc)
    {
        for(int i=0;i<brojac;i++) delete[] mat[i];
        delete[] mat;
        throw(std::bad_alloc());
    }
    return mat;
}
int main ()
{
    int **p=nullptr;
   
    try
    {
        int n;
        std::cout<<"Unesite broj elemenata vektora: ";
        std::cin>>n;
        std::vector<int> v;
        std::cout<<"Unesite elemente vektora: ";
        for(int i=0;i<n;i++)
        {
            int unos;
            std::cin>>unos;
            v.push_back(unos);
        }
        std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        int unos;
        std::cin>>unos;
        if(unos==0)
        {
            int koliko_puta;
            p=AlocirajKontinualno(v,koliko_puta);
            int m=OdrediOsnovniPeriod(v);
            if(m==0) m=v.size();
            std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
            for(int i=0;i<koliko_puta;i++)
            {
                for(int j=0;j<m;j++)
                {
                    for(int k=0;k<v.at(j);k++)
                    {
                        std::cout<<std::setw(3)<<std::left<<p[i*m+j][k];
                    }
                    std::cout<<std::endl;
                }
            }
            delete[] p[0];
            delete[] p;
        }
        else if(unos==1)
        {
            int koliko_puta;
            p=AlocirajFragmentirano(v,koliko_puta);
            int m=OdrediOsnovniPeriod(v);
            if(m==0) m=v.size();
            std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
            for(int i=0;i<koliko_puta;i++)
            {
                for(int j=0;j<m;j++)
                {
                    for(int k=0;k<v.at(j);k++)
                    {
                        std::cout<<std::setw(3)<<std::left<<p[i*m+j][k];
                    }
                    std::cout<<std::endl;
                    delete[] p[i*m+j];
                }
            }
            delete[] p;
        }
    }
    catch(std::domain_error ex)
    {
        std::cout<<"Izuzetak: "<<ex.what();
    }
    catch(std::bad_alloc)
    {
        std::cout<<"Nema dovoljno memorije";
    }
   
    return 0;
}