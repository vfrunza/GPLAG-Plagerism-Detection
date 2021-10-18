#include <iostream>
#include <vector>
#include <deque>

typedef std::deque<std::vector<int>> DeqVec;

enum Smjer {Rastuci, Opadajuci};

bool jeStepenDvojke(int n)
{
    if(n<0) n*=-1;
    while(n>0)
    {
        if(n%2!=0 && n>1) return false;
        n/=2;
    }
    return true;
}

DeqVec MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer)
{
    DeqVec DV;
    if(smjer==Rastuci)
    {
        std::vector<int> p;
        for(int i=0;i<v.size();i++)
        {
            int x=v.at(i);
            if(jeStepenDvojke(x) && x>0)
            {
                if(p.size()==0) p.push_back(x);
                else
                {
                    if(x>=p.at(p.size()-1))
                    {
                        p.push_back(x);
                        if(i==v.size()-1)
                        {
                            if(p.size()>1) DV.push_back(p);
                        }
                    }
                    else
                    {
                        if(p.size()>1) DV.push_back(p);
                        p.clear();
                        p.push_back(x);
                    }
                }
            }
            else
            {
                if(p.size()>1) DV.push_back(p);
                p.clear();
            }
        }
    }
    if(smjer==Opadajuci)
    {
        std::vector<int> p;
        for(int i=0;i<v.size();i++)
        {
            int x=v.at(i);
            if(jeStepenDvojke(x) && x>0)
            {
                if(p.size()==0) p.push_back(x);
                else
                {
                    if(x<=p.at(p.size()-1))
                    {
                        p.push_back(x);
                        if(i==v.size()-1)
                        {
                            if(p.size()>1) DV.push_back(p);
                        }
                    }
                    else
                    {
                        if(p.size()>1) DV.push_back(p);
                        p.clear();
                        p.push_back(x);
                    }
                }
            }
            else
            {
                if(p.size()>1) DV.push_back(p);
                p.clear();
            }
        }
    }
    return DV;
}
DeqVec MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, bool smjer)
{
    DeqVec DV;
    if(smjer==true)
    {
        std::vector<int> p;
        for(int i=0;i<v.size();i++)
        {
            int x=v.at(i);
            if(jeStepenDvojke(x) && x>0)
            {
                if(p.size()==0) p.push_back(x);
                else
                {
                    if(x>p.at(p.size()-1))
                    {
                        p.push_back(x);
                        if(i==v.size()-1)
                        {
                            if(p.size()>1) DV.push_back(p);
                        }
                    }
                    else
                    {
                        if(p.size()>1) DV.push_back(p);
                        p.clear();
                        p.push_back(x);
                    }
                }
            }
            else
            {
                if(p.size()>1) DV.push_back(p);
                p.clear();
            }
        }
    }
    if(smjer==false)
    {
        std::vector<int> p;
        for(int i=0;i<v.size();i++)
        {
            int x=v.at(i);
            if(jeStepenDvojke(x) && x>0)
            {
                if(p.size()==0) p.push_back(x);
                else
                {
                    if(x<p.at(p.size()-1))
                    {
                        p.push_back(x);
                        if(i==v.size()-1)
                        {
                            if(p.size()>1) DV.push_back(p);
                        }
                    }
                    else
                    {
                        if(p.size()>1) DV.push_back(p);
                        p.clear();
                        p.push_back(x);
                    }
                }
            }
            else
            {
                if(p.size()>1) DV.push_back(p);
                p.clear();
            }
        }
    }
    return DV;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int> v;
    for(int i=0;i<n;i++)
    {
        long unos;
        std::cin>>unos;
        v.push_back(unos);
    }
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int unos;
    std::cin>>unos;
    if(unos==1)
    {
        DeqVec DV=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
        std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        for(auto d : DV)
        {
            for(int x : d)
            {
                std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }
    }
    else 
    {
        DeqVec DV=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
        std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        for(auto d : DV)
        {
            for(int x : d)
            {
                std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }
    }
	return 0;
}