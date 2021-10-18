#include <iostream>
#include <deque>
#include <vector>

template <typename Tip> Tip Kriterij1 (Tip n){
if(n==0 ) return 0;
return abs(n%10)+Kriterij1(n/10);
}



template <typename Tip1,typename Tip2> auto UvrnutiPresjek(Tip1 pocetak1, Tip1 iza_kraja1,Tip2 pocetak2,Tip2 iza_kraja2,Kriterij1)-> typename std::remove_reference<decltype(*pocetak1)>::type *  {
    
    
    int brpresjeka(0);
    
    std::vector<std::vector<Tip1>>Matrica (brpresjeka,std::vector<Tip1>(3));
    
}

int main ()
{
	return 0;
}