/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
  
*/
#include <iostream>
#include <vector>
#include <iomanip>

using  std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::setprecision;

vector<vector<double> > RastuciPodnizovi(vector<double> n){
	vector<vector<double> > matrica;
	if(n.size()<=1) return {};
	int k=0,brojredova=1;
matrica.resize(1);//mijenjamo velicinu na 1 red
	for(int i=0;i<n.size();i++){
		if(i!=n.size()-1 && n.at(i)<=n.at(i+1))
		{
		matrica[k].push_back(n.at(i));
		}
	
		else if(i!=0 && i!=n.size()-1 && n.at(i)>=n.at(i+1) && n.at(i)>=n.at(i-1) )
		{
		matrica[k].push_back(n.at(i));
			k++;
			brojredova++;//svaki put kada prelazimo u novi red, k moramo povecati za 1 jer nam k oznacava u koji red matrice ubacujemo
			
			matrica.resize(brojredova);//resize-amo matricu na velicinu koja je za 1 veca od prethodne jer nam treba jos jedan red
		}
			else if(i==n.size()-1 && n.at(i)>=n.at(i-1)){matrica[k].push_back(n.at(i));}
		
	 }	
	 return matrica;
		
	
} 
vector <vector<double> > OpadajuciPodnizovi(vector<double> n){//princip slican prethodnoj funkciji uz izmjenu znaka nejednakosti jer se sada radi o opadajucim podnizovima
	vector<vector<double> > matrica;
	if(n.size()<=1) return {};//ukoliko je velicina vektora manja ili jednaka 1, tj. 1 ili 0 necemo imati sa cime porediti pa vraca prazan
	int k=0,brojredova=1;
	matrica.resize(1);
	for(int i=0;i<n.size();i++){
		if(i!=n.size()-1 && n.at(i)>=n.at(i+1)){
			matrica[k].push_back(n.at(i));
		}
	
		else if(i!=0 && i!=n.size()-1 && n.at(i)<=n.at(i+1) && n.at(i)<=n.at(i-1)  ){
			matrica[k].push_back(n.at(i));
			k++;
			brojredova++;
		matrica.resize(brojredova);
		}
			else if(i==n.size()-1 && n.at(i)<=n.at(i-1)){matrica[k].push_back(n.at(i));}
	}return matrica;
}
int main(){
	
cout<<"Unesite broj elemenata vektora: ";
int n;
cin>>n;
cout<<"Unesite elemente vektora: ";
vector<double> nekivektor;
double x;
for(int i=0;i<n;i++){
	cin>>x;
	nekivektor.push_back(x);
}
vector<vector<double> > rastuci;
vector<vector<double> > opadajuci;
rastuci=RastuciPodnizovi(nekivektor);
opadajuci=OpadajuciPodnizovi(nekivektor);
cout<<"Maksimalni rastuci podnizovi: "<<endl;
for(int i=0;i<rastuci.size();i++){
	for(int j=0;j<rastuci[i].size();j++){ 
		cout<<setprecision(12)<<rastuci[i][j]<<" ";//ispis elemenata rastuceg podniza
	}cout<<endl;
}
 
cout<<"Maksimalni opadajuci podnizovi: "<<endl;
for(int i=0;i<opadajuci.size();i++){
	for(int j=0;j<opadajuci[i].size();j++){
		cout<<setprecision(12)<<opadajuci[i][j]<<" ";//ispis opadajuceg
	}
}
		return 0;
	}