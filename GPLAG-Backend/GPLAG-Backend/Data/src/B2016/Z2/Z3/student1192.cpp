/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using std :: cin;
using std:: cout;
using std :: vector;
template <typename tip1, typename tip2, typename tip3 >
vector< vector<int>> UvrnutiPresjek (tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip3 f){
	vector<vector <int>> m ;
	int i(0);
	while (p1!=k1){
		tip2 p22(p2);
		while (p22!=k2){
			if(f(*p1)== f(*p22)){
				m.resize(i+1);
				m[i].push_back(*p1); m[i].push_back(*p22); m[i].push_back(f(*p1));
				i++;
				
			}
			p22++;
		}
		p1++;
		
	}
	
//	sort (m.begin(), m.begin()+i,[] (vector <tip1> x,vector<tip1> y){return x[2]>y[2]; });
	return m;
}
int SumaDjelilaca (int x){
	int suma(0);
	for(int i=0; i<=x; i++){
		if(x%i==0){
		   suma+=i;
		}
	}
	return suma;
}
int main ()
{
	std :: deque<int > d{1,2,4,2,5,8}, d2 {2,78,8,7,57};
   std:: vector<std::vector<int>> m(UvrnutiPresjek (d.begin(), d.end(), d2.begin(), d2.end(), SumaDjelilaca));
    for (vector<int> red: m){
    	for (int x:red){
    		cout << x << " ";
    	}
    	cout << std :: endl;
    }
	return 0;
}