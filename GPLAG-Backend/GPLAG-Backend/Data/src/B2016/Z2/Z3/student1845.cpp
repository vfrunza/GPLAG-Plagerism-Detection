/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//UvrnutiPresjek(5 parametara)
template<typename tip1>
tip1 f(tip1 x){
	return x;
}


template<typename it2,typename it1,typename tip>
auto UvrnutiPresjek(it1 p1, it1 p2, it2 p3, it2 p4, tip f)->deque<deque<decltype(*p1+*p3)>>{
it1 poc1=p1, kraj2=p2;
it2 poc3=p3, kraj4=p4;
int red=1;
deque<deque<tip>> matrica(0,vector<tip>(0));


while(poc1!=kraj2){
	while(poc3!=kraj4){
		if(f(*poc1)==f(*poc3)){
			matrica.resize(red);
			matrica[red-1].resize(3);
			
			matrica[0]=*poc1;
			matrica[1]=*poc3;
			matrica[2]=f(poc1);
			
			red++;
		}
		poc3++;
	}
	poc3=p3;
	poc1++;
}	
	//sortiranje
	
	sort(matrica.begin(), matrica.end(),[](vector<decltype(*p1+*p1)>a , vector<decltype(*p1+*p1)> b){
	if(a[2]==b[2]){
		if(a[1]==b[1]){
			if(a[0]==b[0]){
			return false;	
			}else{
				return true;
			}
			
		}else{
			return true;
		}
		
	}else{
		return true;
	}
		return false;
	});
	
	
	
	//kako
	
	
	
	
	return matrica;
}
//UvrnutaRazlika


int main (){
deque<int> v1;
deque<int> v2;
deque<int> filter;
deque<int> filter2;
cout<<"Unesite broj elemenata prvog kontejnera: ";
int n;
cin>>n;
int i=0;
int a;
cout<<"Unesite elemente prvog kontejnera: ";
for(;;){
	if(i==n)break;
	cin>>a;
	bool ima=false;
	for(int x: filter){
		if(x==a){
			ima=true;
			break;
		}
	}
	if(ima)continue;
	
		filter.push_back(a);
		v1.push_back(a);
		i++;
	
	
}

cout<<"Unesite broj elemenata drugog kontejnera: ";
int n1;
cin>>n1;
i=0;
cout<<"Unesite elemente drugog kontejnera: ";
for(;;){
	if(i==n1)break;
	cin>>a;
	bool ima=false;
	for(int x: filter2){
		if(x==a){
			ima=true;
			break;
		}
	}
	if(ima)continue;
	
		filter2.push_back(a);
		v2.push_back(a);
		i++;
	
	
}

deque<deque<remove_reference<decltype(v1.begin())>>> fin(UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),f));


	return 0;
}