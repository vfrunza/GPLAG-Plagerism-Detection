/B2016/2017: Zadaća3, Zadatak 6
#include <iostream>
#include<list>
using namespace std; 

bool Dalijelistasim(list<int>l)
{
    int velicina=l.size(); 
    for(auto i=l.begin(); i<velicina/2; i++) 
     for(auto j=l.end(); j<velicina/2; j--) 
        if(*i==*j) return true; 
        return false; 
    
}
int main ()
{
    list<int>l{2,3,4,3,2}; 
    cout<<Dalijelistasim(l); 
	return 0;
}