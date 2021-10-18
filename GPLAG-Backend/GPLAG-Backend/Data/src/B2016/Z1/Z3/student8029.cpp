#include <iostream>
#include <vector>
#include <limits>
typedef std::vector<std::vector<double>> matrica;

matrica kreiraj_matricu(int broj_redova,int broj_kolona)
{
    return matrica(broj_redova,std::vector<double> (broj_kolona));
}


matrica RastuciPodnizovi(std::vector<double> v)
{
    int red=0;
    matrica vrati;
    for(int i=0;i<v.size();i++)
    {
        if(i<v.size()-1 && v[i]<=v[i+1])
        {
            vrati.resize(red+1);
           while (v[i]<=v[i+1] ) {
               vrati[red].push_back(v[i]);
               if(i<v.size()-1)
               i++;
                 if(i>=v.size()-1)
                break;
           } 
            vrati[red].push_back(v[i]);
          red++;
        }
    }
   return vrati;
}



matrica OpadajuciPodnizovi(std::vector<double>v)
{
    matrica vrati;
    int red=0;
    for(int i=0;i<v.size();i++)
    {
        if(i<v.size()-1)
        if(v[i]>=v[i+1])
        {
            vrati.resize(red+1);
            while (v[i]>=v[i+1]) {
                vrati[red].push_back(v.at(i));
                if(i<v.size()-1)
                i++;
                if(i>=v.size()-1)
                break;

            }
    
            vrati[red].push_back(v[i]);
            red++;
        }

    }
    return vrati;
    
}

void ispisi(matrica m)
{
    
    for(auto red: m)
    {
        for(auto x: red)
         std::cout<<x<<" ";
         std::cout<<"\n";
    }
}

int main()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int broj_elemenata;
    std::cin>>broj_elemenata;
    double broj;
    std::vector<double>v;
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<broj_elemenata;i++)       
    {
        std::cin>>broj;
        v.push_back(broj);
    }
    auto ispis1=RastuciPodnizovi(v);
   std::cout<<"Maksimalni rastuci podnizovi:\n";
  ispisi(ispis1);
  
  auto ispis=OpadajuciPodnizovi(v);
  std::cout<<"Maksimalni opadajuci podnizovi:\n";
   ispisi(ispis);
    
    return 0;
}
