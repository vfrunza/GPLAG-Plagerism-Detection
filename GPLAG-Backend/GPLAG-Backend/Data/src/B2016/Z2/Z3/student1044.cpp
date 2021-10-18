/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

       	void IzbaciDuple (vector<string>&v){
		
			
			for(int i(0);i<int(v.size());i++){ 
			for(int j(i+1);j<int(v.size());j++){
				if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
				}
				
			}
			}

		
			
		
       
       	}
int main ()
{
	vector<string>v{"Ja","se","Lejla", "Lejla","se", "zovem", "Lejla", "Lejla"};
	IzbaciDuple(v);
	for(int i(0);i<v.size();i++)
	cout<<v[i];
	return 0;
}