#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <type_traits>

template <typename Iter1, typename Iter2, typename Iter3> 
void SortirajPodrucjeVrijednosti(Iter1 p1, Iter1 k1, Iter2 p2, Iter3 p3, 
                                typename std::remove_reference<decltype(*p3)>::type fun(typename std::remove_reference<decltype(*p1)>::type a, 
                                typename std::remove_reference<decltype(*p2)>::type), bool krit(typename std::remove_reference<decltype(*p1)>::type a,
                                typename std::remove_reference<decltype(*p2)>::type))
{
    bool slozi=true;
    int n=k1-p1;
    std::stable_sort(p1,k1,krit);
    std::stable_sort(p2,p2+n,krit);/*
    std::cout<<std::endl;
    std::for_each(p1,k1,[](int x){std::cout<<x<<" ";});
    std::cout<<std::endl;
    std::for_each(p2,p2+n,[](int x){std::cout<<x<<" ";});
    std::cout<<std::endl;*/
    for(int i=0;i<n;i++)
    {
        auto a=fun(*(p1+i),*(p2+i));
        bool nasao=false;
        for(int j=0;j<n;j++)
        {
            if(a==*(p3+j)) { nasao=true; break; }
        }
        if(!nasao) { slozi=false; break; }
    }
    if(slozi)
    {
        for(int i=0;i<n;i++)
        {
            auto a=fun(*(p1+i),*(p2+i));
            *(p3+i)=a;
        }
    }
    else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
  
}
bool kriterij(int a, int b)
{
    int tempa=a,tempb=b;
    int br1=0;
    int br2=0;
    int i=2;
    if(tempa==0 || tempa==1 || tempa==-1) br1=1;
    if(tempb==0 || tempb==1 || tempb==-1) br2=1;
    while(tempa!=1 && tempa!=-1 && tempa!=0)
    {
        if(tempa%i==0)
        {
            br1++;
            tempa/=i;
        }
        else i++;
    }
    i=2;
    while(tempb!=1 && tempb!=-1 && tempb!=0)
    {
        if(tempb%i==0)
        {
            br2++;
            tempb/=i;
        }
        else i++;
    }
    if(br1==br2) return a>b;
    return br1>br2;
}

int fja(int a, int b)
{
    return -1*2*a+b;
}
int main ()
{
    try
    {
        std::vector<int> v1;
        std::vector<int> v2;
        std::vector<int> v3;
        
        std::cout<<"Unesite broj elemenata: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite elemente prvog vektora: ";
        for(int i=0;i<n;i++) 
        { 
            int unos; 
            bool dodaj=true;
            std::cin>>unos; 
            for(int j=0;j<v1.size();j++) if(unos==v1.at(j)) { dodaj=false; break; }
            if(dodaj) v1.push_back(unos);
            else i--;
        }
        if(std::cin.peek()!='\n') std::cin.ignore(10000,'\n');
        std::cout<<"Unesite elemente drugog vektora: ";
        for(int i=0;i<n;i++) 
        { 
            int unos; 
            bool dodaj=true;
            std::cin>>unos; 
            for(int j=0;j<v2.size();j++) if(unos==v2.at(j)) { dodaj=false; break; }
            if(dodaj) v2.push_back(unos);
            else i--;
        }
        if(std::cin.peek()!='\n') std::cin.ignore(10000,'\n');
        std::cout<<"Unesite elemente treceg vektora: ";
        for(int i=0;i<n;i++) 
        { 
            int unos; 
            bool dodaj=true;
            std::cin>>unos; 
            for(int j=0;j<v3.size();j++) if(unos==v3.at(j)) { dodaj=false; break; }
            if(dodaj) v3.push_back(unos);
            else i--;
        }
        if(std::cin.peek()!='\n') std::cin.ignore(10000,'\n');
        SortirajPodrucjeVrijednosti(std::begin(v1),std::end(v1),std::begin(v2),std::begin(v3),fja,kriterij);
        std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
        for(int i=0;i<n;i++)
        {
            std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
        }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}