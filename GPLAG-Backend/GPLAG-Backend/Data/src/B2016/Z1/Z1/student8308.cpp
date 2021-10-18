#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int jeli_opak_odvratan(int n)
{
    n=fabs(n);
    int br0,br1,br2,l;
    l=-1;
    br0=0;
    br1=0;
    br2=0;
    while(n != 0)
    {
        if(n%3==0)
            br0++;
        else if(n%3==1)
            br1++;
        else if(n%3==2)
            br2++;
            n=n/3;
    }
    if (((br0%2==0) || (br0==0)) && ((br1%2==0) || (br1==0)) && ((br2%2==0) || (br2==0)))
        return 1;
    else if (((br0%2!=0) || (br0==0)) && ((br1%2!=0) || (br1==0)) && ((br2%2!=0) || (br2==0)))
        return 0;
    return l;

}

vector<int>IzdvojiGadne(vector<int>v,bool n)
{
    int l;
    l=-1;
    vector<int>a;
    for(int i=0; i<v.size(); i++)
    {
        l=jeli_opak_odvratan(v[i]);
        if(l==n)
            a.push_back(v[i]);
    }

    for(int i=0; i<a.size(); i++)
    {
        for(int j=i+1; j<a.size(); j++)
        {
            if(a[i]==a[j])
            {
                for(int k=j; k<a.size()-1; k++)
                {
                    a[k]=a[k+1];
                }
                j--;
                a.resize(a.size()-1);
            }

        }
    }
    return a;
}

int main()
{
    vector<int>v1;
    int broj;
    cout << "Unesite brojeve (0 za prekid unosa): ";
    do
    {
        cin >>broj;
        if(broj != 0) v1.push_back(broj);
    } while(broj != 0);
    auto opaki = IzdvojiGadne(v1, true), odvratni = IzdvojiGadne(v1, false);
    cout << "Opaki: ";
    for (const auto &x : opaki) std::cout << x << " ";
    cout << std::endl << "Odvratni: ";
    for (const auto &x : odvratni) std::cout << x << " ";
    return 0;
}

/*{
    vector<int>v1;
    int broj,opaki,odvratni;
    cout << "Unesite brojeve (0 za prekid unosa): ";
    do
    {
        cin >>broj;
        if(broj != 0) v1.push_back(broj);
    } while(broj != 0);
    cout << "Unesite 1 ili 0: ";
    cin >>a;
    v1=IzdvojiGadne(v1,a);
    cout <<"Nakon modifikacije niz glasi: ";
    for(int i=0; i<v1.size(); i++)
    {
        cout <<" "<<v1[i];
    }
    return 0;
}*/