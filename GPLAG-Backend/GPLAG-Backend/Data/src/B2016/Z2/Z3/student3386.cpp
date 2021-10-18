#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <iomanip>

using std::deque;
using std::vector;
using std::cin;
using std::cout;
using std::begin;
using std::end;

template <typename Tip1, typename Tip2, typename povratna, typename prima>
auto UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 q1, Tip2 q2,povratna fun(prima))-> vector<vector< typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef vector<vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
    typedef typename std::remove_reference<decltype(*p1)>::type Element;
    Matrica vracam;
    Tip1 a(p1);
    int duzina1(0),duzina2(0);
    while(a++!=p2)
        duzina1++;
    a=q1;
    while(a++!=q2)
        duzina2++;
    if(duzina1==0 or duzina2==0)
        return vracam;
    Tip2 pok=q1;
    for(int i=0;i<duzina1;i++)
    {
        for(int j=0;j<duzina2;j++)
        {
            if(fun(*p1)==fun(*q1))
            {
                vector<Element> pomoc;
                pomoc.push_back(*p1);
                pomoc.push_back(*q1);
                pomoc.push_back(fun(*p1));
                vracam.push_back(pomoc);
            }
            q1++;
        }
        q1=pok;
        p1++;
    }
    if(vracam.size()==0 or vracam.size()==1)
        return vracam;
    sort(begin(vracam),end(vracam),[](vector<Element> x,vector<Element> y){if(x[2]==y[2])
    {
        if(x[0]==y[0])
            return x[1]<y[1];
        return x[0]<y[0];
    }return x[2]<y[2];});
    for(int i=0;i<vracam.size()-1;i++)
    {
        if(vracam[i]==vracam[i+1])
        {
            for(int k=i+1;k<vracam.size()-1;k++)
                    vracam[k]=vracam[k+1];
                vracam.resize(vracam.size()-1);
                i--;
        }
    }
    return vracam;
}
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 q1, Tip2 q2)-> vector<vector< typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef vector<vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
    typedef typename std::remove_reference<decltype(*p1)>::type Element;
    Matrica vracam;
    Tip1 a(p1);
    int duzina1(0),duzina2(0);
    while(a++!=p2)
        duzina1++;
    a=q1;
    while(a++!=q2)
        duzina2++;
    if(duzina1==0 or duzina2==0)
        return vracam;
    Tip2 pok=q1;
    for(int i=0;i<duzina1;i++)
    {
        for(int j=0;j<duzina2;j++)
        {
            if(*p1==*q1)
            {
                vector<Element> pomoc;
                pomoc.push_back(*p1);
                pomoc.push_back(0);
                pomoc.push_back(0);
                vracam.push_back(pomoc);
            }
            q1++;
        }
        q1=pok;
        p1++;
    }
    if(vracam.size()==0 or vracam.size()==1)
        return vracam;
    for(int i=0;i<vracam.size()-1;i++)
    {
            if(vracam[i]==vracam[i+1])
            {
                for(int k=i+1;k<vracam.size()-1;k++)
                    vracam[k]=vracam[k+1];
                vracam.resize(vracam.size()-1);
                i--;
            }
    }
    return vracam;
}
template <typename Tip1, typename Tip2, typename povratna, typename prima>
auto UvrnutaRazlika(Tip1 p1,Tip1 p2,Tip2 q1,Tip2 q2,povratna fun(prima))-> vector<vector< typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef vector<vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
    typedef typename std::remove_reference<decltype(*p1)>::type Element;
    Matrica vracam;
    Tip1 a(p1);
    int duzina1(0),duzina2(0);
    while(a++!=p2)
        duzina1++;
    a=q1;
    while(a++!=q2) 
        duzina2++;
    if(duzina1==0 or duzina2==0)
        return vracam;
    Tip2 pok=q1;
    Tip1 pok2=p1;
    for(int i=0;i<duzina1;i++)
    {
        bool imal=false;
        for(int j=0;j<duzina2;j++)
            if(fun(*p1)==fun(*q1++))
                imal=true;
        if(!imal)
        {
            vector<Element> pomoc;
            pomoc.push_back(*p1);
            pomoc.push_back(fun(*p1));
            vracam.push_back(pomoc);
        }
        q1=pok;
        p1++;
    }
    p1=pok2;
    for(int i=0;i<duzina2;i++)
    {
        bool imal=false;
        for(int j=0;j<duzina1;j++)
            if(fun(*q1)==fun(*p1++))
                imal=true;
        if(!imal)
        {
            vector<Element> pomoc;
            pomoc.push_back(*q1);
            pomoc.push_back(fun(*q1));
            vracam.push_back(pomoc);
        }
        p1=pok2;
        q1++;
    }
    if(vracam.size()==0 or vracam.size()==1)
        return vracam;
    sort(begin(vracam),end(vracam),[](vector<Element> x,vector<Element> y){if(x[0]==y[0])return x[1]>y[1];
        return x[0]>y[0];});
    
    for(int i=0;i<vracam.size()-1;i++)
    {
            if(vracam[i]==vracam[i+1])
            {
                for(int k=i+1;k<vracam.size()-1;k++)
                    vracam[k]=vracam[k+1];
                vracam.resize(vracam.size()-1);
                i--;
            }
    }
    return vracam;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1,Tip1 p2,Tip2 q1,Tip2 q2)-> vector<vector< typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef vector<vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
    typedef typename std::remove_reference<decltype(*p1)>::type Element;
    Matrica vracam;
    Tip1 a(p1);
    int duzina1(0),duzina2(0);
    while(a++!=p2)
        duzina1++;
    a=q1;
    while(a++!=q2)
        duzina2++;
    if(duzina1==0 or duzina2==0)
        return vracam;
    Tip2 pok=q1;
    Tip1 pok2=p1;
    for(int i=0;i<duzina1;i++)
    {
        bool imal=false;
        for(int j=0;j<duzina2;j++)
            if(*p1==*q1++)
                imal=true;
        if(!imal)
        {
            vector<Element> pomoc;
            pomoc.push_back(*p1);
            pomoc.push_back(0);
            vracam.push_back(pomoc);
        }
        q1=pok;
        p1++;
    }
    p1=pok2;
    q1=pok;
    for(int i=0;i<duzina2;i++)
    {
        bool imal=false;
        for(int j=0;j<duzina1;j++)
            if(*q1==*p1++)
                imal=true;
        if(!imal)
        {
            vector<Element> pomoc;
            pomoc.push_back(*q1);
            pomoc.push_back(0);
            vracam.push_back(pomoc);
        }
        p1=pok2;
        q1++;
    }
    if(vracam.size()==0 or vracam.size()==1)
        return vracam;
    sort(begin(vracam),end(vracam),[](vector<Element> x,vector<Element> y){if(x[0]==y[0])return x[1]>y[1];
        return x[0]>y[0];
    });
    for(int i=0;i<vracam.size()-1;i++)
    {
        if(vracam[i]==vracam[i+1])
        {
            for(int k=i+1;k<vracam.size()-1;k++)
                vracam[k]=vracam[k+1];
            vracam.resize(vracam.size()-1);
            i--;
        }
    }
    return vracam;
}
bool Prost(long long int n)
{
    if(n<=1)
        return false;
    for(long long int i=2;i<=int(std::sqrt(n));i++)
        if(n%i==0)
            return false;
    return true;
}
int Suma(long long int x)
{
    auto a=x;
    int suma=0;
    while(a)
    {
        int c=a%10;
        suma+=c;
        a/=10;
    }
    return suma;
}
int SumaDjelilaca(long long int x)
{
    int suma(0);
    x=std::abs(x);
    for(long long int i=1;i<=x/2;i++)
        if(x%i==0)
            suma+=i;
    suma+=x;
    return suma;
}
int BrojProstihFaktora(long long int x)
{
    int broj(0);
    if(x<0)
        x=-x;
    int i=2;
    while(x!=1)
    {
        if(x%i==0)
        {
            broj++;
            x/=i;
        }
        else
            i++;
    }
    return broj;
}

bool Savrsen(long long int x)
{
    long long int suma(0);
    for(long long int i=1;i<=x/2;i++)
        if(x%i==0)
            suma+=i;
    return suma==x;
}
int BrojSavrsenihDjelilaca(long long int x)
{
    int broj(0);
    for(long long int i=1;i<=x;i++)
        if(x%i==0 and Savrsen(i))
            broj++;
    return broj;
}
int main()
{
    cout<<"Unesite broj elemenata prvog kontejnera: ";
    int vel1(0);
    cin>>vel1;
    deque<int> prvi(vel1);
    cout<<"Unesite elemente prvog kontejnera: ";
    for(int i=0;i<vel1;i++)
    {
        int n;
        cin>>n;
        bool bio=false;
        for(int j=0;j<i;j++)
            if(prvi[j]==n)
                bio=true;
        if(bio)
        {
            i--;
            continue;
        }
        prvi[i]=n;
    }
    cout<<"Unesite broj elemenata drugog kontejnera: ";
    int vel2(0);
    cin>>vel2;
    deque<int> drugi(vel2);
    cout<<"Unesite elemente drugog kontejnera: ";
    for(int i=0;i<vel2;i++)
    {
        int n;
        cin>>n;
        bool bio=false;
        for(int j=0;j<i;j++)
            if(drugi[j]==n)
                bio=true;
        if(bio)
        {
            i--;
            continue;
        }
        drugi[i]=n;
    }
    //deque<int> prvi{15,16,17,12,13,14,15,13,99};
    //deque<int> drugi{31,51,91,71,21,23,24,22,22};
    auto a=UvrnutiPresjek(begin(prvi),end(prvi),begin(drugi),end(drugi),Suma);//suma
    auto c=UvrnutaRazlika(begin(prvi),end(prvi),begin(drugi),end(drugi),BrojProstihFaktora);//BrojProstihFaktora
    cout<<"Uvrnuti presjek kontejnera: \n";
    for(auto x:a)
    {
        for(auto b:x)
            cout<<std::setw(6)<<b<<" ";
        cout<<"\n";
    }
    cout<<"Uvrnuta razlika kontejnera: \n";
    for(auto x:c)
    {
        for(auto d:x)
            cout<<std::setw(6)<<d<<" ";
        cout<<"\n";
    }
    cout<<"Dovidjenja!";
    return 0;
}