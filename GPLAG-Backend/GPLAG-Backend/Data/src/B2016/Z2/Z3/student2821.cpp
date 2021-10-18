/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<int> Vektor;
typedef std::vector<std::vector<int>>Matrica;

template <typename IterTip1, typename IterTip2>
[] int (int x){
    int suma=0;
    int n=0;
    while(x!=0){
        n=x%10;
        suma+=n;
        x=x/10;
        
    }
    return suma;
}

Matrica UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 p3, IterTip2 p4,int (*fun)(int) ){
    while(p1!=p2 and p3!=p4){
        for(int i=0;i<(p4-p3);i++){
        if(fun(*p1)==fun(*p3))
    }
    
}


int main ()
{   int n;
    Vektor jedan;
    Vektor dva;
    cout<<"Unesite broj elemenata prvog kontejnera: ";
    cin>>n;
    jedan.resize(n);
    int r;
    r=jedan.size();
    cout<<"Uesite elemente prvog kontejnera: ";
    int element1;
    for(int i=0;i<r;i++){
    	cin>>element1;
    	jedan.push_back(element1);
    }
    int x;
    cout<<"Unesite broj elemenata drugog kontejnera: ";
    cin>>x;
    dva.resize(x);
    cout<<"Unesite elemente drugog vektora: ";
    int element2;
    int a=dva.size();
    for(int i=0;i<a;i++){
    	cin>>element2;
    	dva.push_back(element2);
    }
    cout<<"Uvrnuti presjek kontejnera: ";
    
    
	return 0;
}