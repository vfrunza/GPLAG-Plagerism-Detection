/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> PretvoriUTernarni(int n)
{
    vector<int> niz;
    int temp=0,x=n;
    if(n<0)
    {
        n=-n;
    }
    if(n==0) niz.push_back(0);
    while(n!=0)
    {
        temp=n%3;
        niz.push_back(temp);
        n/=3;
    }
    return niz;
}

int ispitivanje(vector<int> broj )
{
    int isti=0,i=0;
    vector<int> niz;
    niz.resize(3);
    while(i<broj.size())
        niz[broj[i++]%3]++;
    if(niz[0]%2==0 && niz[1]%2==0 && niz[2]%2==0) isti=1;
    else if((niz[0]==0 || niz[0]%2==1)&& (niz[1]%2==1||niz[1]==0) && (niz[2]%2==1||niz[2]==0)) isti=2;
    return isti;
}

vector<int>IzdvojiGadne(vector<int> v, bool istina)
{
    vector<int> opaki,odvratni;
    int i=0,j=0,k=0;
    int pamti=v.size();
    if(pamti==0)return opaki;
    bool p=false;
    for(int k=0;k<v.size();k++)
    {
        for(int h=k+1;h<v.size();h++)
        {
            if(v[k]==v[h]) {v.erase(v.begin()+h);h--;}

        }
    }
    pamti = v.size()+1;
    while(i<pamti-1)
    {
        switch(ispitivanje(PretvoriUTernarni(v[i++])))
        {
        case 0:
            continue;
            break;
        case 1:
            opaki.push_back(v[i-1]);
            break;
        case 2:
            odvratni.push_back(v[i-1]);
            break;
        }
    }
    if(istina!=false)   return opaki ;
    else return odvratni;
}
int main()
{
    int i=0, temp=1;
    vector<int> a,c;
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    while(temp!=0)
    {
        cin>>temp;
        if(temp!=0)a.push_back(temp);
    }
    c=IzdvojiGadne(a, true);
    cout<<"Opaki: ";
    for(int i=0; i<c.size(); i++)
        cout<<c[i]<<" ";
    cout<<endl;
    c=IzdvojiGadne(a,false);
    cout <<"Odvratni: ";
    for(int i=0; i<c.size(); i++)
        cout<<c[i]<<" ";
    return 0;
}