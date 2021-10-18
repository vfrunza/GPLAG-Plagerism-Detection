#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//Sa ovom funkcijom provjeravamo da li se neki broj ponavlja više od jednom u vektoru, ukoliko da, preskačemo ga i ne smještamo u vektor ponovo

bool duplikat(vector<int>v, int br)
{
    
    for(int i=0;i<v.size();i++){
    if(v[i]==br)
    return true;
        
    }
    
    return false;
}

vector<int> IzdvojiGadne(vector<int> v,bool t)
{
    vector<int>a;
    vector<int>b;
    int x=0,y=0,z=0;
    for(int i=0;i<v.size();i++)
    {
        //Napravit ćemo dvije nove varijable: n za opake, m za odvratne
        int n=v[i];
        int m=v[i];
        //Ukoliko je broj negativan, pomnozit ćemo ga sa -1 
        if(n<0) n*=-1;
        if(m<0) m*=-1;
        
        //Posto je u pitanju ternarni brojni sistem imamo 3 brojača i tri mogućnosti ostatka pri dijeljenju broja sa 3 (0,1 i 2)
        while(n!=0)
        {
            if(n%3==0) x++;
            if(n%3==1) y++;
            if(n%3==2) z++;
            n/=3;
        }
        //Ukoliko su svi brojaci istovremeno parni,tj sve cifre u broju se javljaju paran broj puta, onda je u pitanju opaki broj
        if(x%2==0 && y%2==0 && z%2==0)
        {
            if( !(duplikat(a,v[i]))) a.push_back(v[i]);
        }
        //resetujemo brojace jer nam trebaju i za odvratne
        x=0; y=0;z=0;
        while(m!=0)
        {
            if(m%3==0) x++;
            if(m%3==1) y++;
            if(m%3==2) z++;
            m/=3;
        }
        //Sve cifre u broju se javljaju neparan broj puta-odvratni brojevi
         if((x%2!=0 || x==0) && (y%2!=0 || y==0) && (z%2!=0|| z==0)) 
         {
            if(!(duplikat(b,v[i]))) b.push_back(v[i]);
        }
        //opet resetujemo brojace na 0, jer nam trebaju za sljedeci broj iz vektora
        x=0;y=0;z=0;
    }
    if(t) return a;
    else return b;
}




int main()
{
 vector<int> v(10000);
 
 cout<<"Unesite brojeve (0 za prekid unosa): ";
 int i;
 for( i=0;i<10000;i++)
 {
     cin>>v[i];
     if(v[i]==0) break;
 }
 int n=i;
 v.resize(n);
 
 vector<int> a=IzdvojiGadne(v,true);
 vector<int> b=IzdvojiGadne(v,false);
 cout<<"Opaki: ";
 for(int i=0;i<a.size();i++)
 {
     cout<<a[i]<<" ";
 }
 cout<<endl;
 cout<<"Odvratni: ";
 for(int i=0;i<b.size();i++)
 {
     cout<<b[i]<<" ";
 }
 
 return 0;
}