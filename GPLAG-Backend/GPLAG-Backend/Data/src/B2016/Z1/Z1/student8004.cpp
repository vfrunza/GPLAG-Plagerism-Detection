#include <iostream>
#include <vector>
using namespace std;
int stepen(int x, int n)
{
    int s=1;
    while( n!=0) { s*=x; n--;}
    return s;
}
int dokogstepena(int n)
{
    int s=0;
    while(1)
    {
        if(stepen(3,s)>=n) break;
        s++;
    }
    return --s;
}
vector<int> tern(int n)
{
   if(n<0) n=-n;
   int s=dokogstepena(n);
   vector<int> suma;
   while(1)
   {
       if(s<0) break;
       if(2*stepen(3,s)<=n) {suma.push_back(2); n-=2*stepen(3,s);}
       else if(stepen(3,s)<=n) {suma.push_back(1); n-=stepen(3,s);}
       else suma.push_back(0);
       s--;
   }
   return suma;
}
bool opak(int n)
{
    vector<int> x=tern(n);
    int brn=0, brj=0, brd=0;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]%10==2) brd++;
        if(x[i]%10==1) brj++;
        if(x[i]%10==0) brn++;
    }
    if(brd%2==0 && brj%2==0 && brn%2==0) return true;
    return false;
}
bool odvratan(int n)
{
    vector<int> x=tern(n);
    int brn=0, brj=0, brd=0;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]%10==2) brd++;
        if(x[i]%10==1) brj++;
        if(x[i]%10==0) brn++;
    }
    if((brd%2!=0||brd==0) && (brj%2!=0||brj==0) && (brn%2!=0||brn==0)) return true;
    return false;
}
vector <int> IzdvojiGadne(vector<int> v, bool t)
{
   vector<int>v1;
   for(int i=0; i<v.size(); i++)
   {
       if(t==true && opak(v[i])) v1.push_back(v[i]);
       if(t==false && odvratan(v[i])) v1.push_back(v[i]);
   }
   if(v1.size()!=0)
   {
      for(int i=0;i<v1.size(); i++)
   {
       for(int j=i+1; j<v1.size(); j++)
       if(v1[i]==v1[j])
       {
           for(int k=j; k<v1.size()-1; k++) v1[k]=v1[k+1];
           v1.resize(v1.size()-1);
           j--;
       }
   } 
   }
   return v1;
}
int main ()
{
	vector<int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1)
	{
	    int n; cin>>n;
	    if(n==0) break;
	    v.push_back(n);
	}
	vector<int> v1=IzdvojiGadne(v,true);
	vector<int> v2=IzdvojiGadne(v,false);
	cout<<"Opaki: ";
	for(int i=0; i<v1.size(); i++) cout<<v1[i]<<" ";
	cout<<endl<<"Odvratni: ";
	for(int i=0; i<v2.size(); i++) cout<<v2[i]<<" ";
	return 0;
}