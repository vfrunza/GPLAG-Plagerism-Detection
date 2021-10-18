/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using namespace std;
typedef vector < vector <double> > Matrica;

Matrica RastuciPodnizovi(vector<double> vek){
Matrica rastuci;
int red(0);
	for(int i = 0 ;i < vek.size()-1 ;i++ ){
		int br(0);
			for(int j = i ;j < vek.size()-1 ;j++){
				if(vek[j+1] >= vek[j])	br++; 
				else break;
				}
		if(br!=0){
			int kolona(0);
			for(int j = i ;j<= i+br ;j++){
				rastuci.resize(red+1);
				  rastuci[red].resize(br+1);
				  
					rastuci[red][kolona]=vek[j];
							kolona++;
			}
			
			red++;
			i=i+br;
		}
	  }
	return rastuci;
}

Matrica OpadajuciPodnizovi(vector<double> vek){
Matrica opadajuci;
int red(0);
	for(int i = 0 ;i < vek.size() ;i++ ){
		int br(0);
			for(int j = i ;j < vek.size()-1 ;j++){
				if(vek[j+1] <= vek[j])	br++; 
				else break;
				}
		if(br!=0){
			int kolona(0);
			for(int j = i ;j <= i+br;j++){
				
				opadajuci.resize(red+1);
				  opadajuci[red].resize(br+1);
				  
					opadajuci[red][kolona]=vek[j];
							kolona++;
			}
			
			red++;
			i=i+br;
		}
	  }
	return opadajuci;
}

int main ()
{	
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double> vek;
	cout<<"Unesite elemente vektora: "; 
	for(int i = 0;i < n ;i++) {
		int a;
		cin >> a;
		vek.push_back(a);
	}
	Matrica rastuci { RastuciPodnizovi(vek) } , opadajuci { OpadajuciPodnizovi(vek) };
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i = 0 ;i<rastuci.size() ;i++) {
		for(int j = 0 ;j < rastuci[i].size() ;j++) 
		cout<<rastuci[i][j]<< " ";
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i = 0 ;i < opadajuci.size() ;i++) {
		for(int j = 0 ;j <  opadajuci[i].size() ;j++) 
		cout<<opadajuci[i][j]<< " ";
		cout<<endl;
	}
	return 0;
}





