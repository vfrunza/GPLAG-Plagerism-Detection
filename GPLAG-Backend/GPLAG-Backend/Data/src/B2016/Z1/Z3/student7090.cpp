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

vector<vector<double>> RastuciPodnizovi(vector<double>&niz){
	vector<vector<double>> rezultat;
	if(niz.empty()) return rezultat;
	
	int startIndex = 0, endIndex = 0, k = 0;
	while(true){
		if( endIndex == niz.size() ) break;
		
		while( niz[endIndex+1] > niz[endIndex] && endIndex < niz.size()-1) endIndex++;
		
		if( startIndex != endIndex ){
			rezultat.push_back(vector<double>());
			for(int j = startIndex; j <= endIndex; j++){
				rezultat[k].push_back(niz[j]);
			}
			k++;
		}
		startIndex = ++endIndex;
	}
	return rezultat;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double>&niz){
	vector<vector<double>> rezultat;
	if(niz.empty()) return rezultat;
	
	int startIndex = 0, endIndex = 0, k = 0;
	while(true){
		if( endIndex == niz.size() ) break;
		
		while( niz[endIndex+1] < niz[endIndex] && endIndex < niz.size() - 1 ) endIndex++;
		
		if( startIndex != endIndex){
			rezultat.push_back(vector<double>());
			for( int j = startIndex; j<= endIndex; j++){
				rezultat[k].push_back(niz[j]);
			}
			k++;
		}
		startIndex = ++endIndex;
	}
	return rezultat;
}

void ispisiMatricu(vector<vector<double>>&mat){
	if(mat.empty()) {
		cout << "Prazno" <<endl;
	} else {
		for( vector<double>& red : mat){
			if( red.empty() ) break;
			for( double element : red ){
				cout << element << " ";
			}
			cout << endl;
		}
	}
}

void unesiNiz(vector<double>& niz){
	int n;
	double element;
	cout << "Unesite broj elemenata vektora:";
	cin >> n;
	for( int i = 0; i < n; i++){
		cout << "Unesite elemente vektora:";
		cin >> element;
		niz.push_back(element);
	}
}

int main(){
	vector<double> testVec = {1,3,2,6,7,9,10,4,3,1,7};
	
	while(true) { // Prekinuti sa ctrl break
	vector<double> vec;
	unesiNiz(vec);
	cout << endl;
	
	vector<vector<double>> rpn = RastuciPodnizovi(vec);
	cout << "Maksimalni rastuci podnizovi:" << endl;
	ispisiMatricu(rpn);
	cout << endl;
	
	vector<vector<double>> opn = OpadajuciPodnizovi(vec);
	cout << "Maksimalni opadajuci podnizovi:" << endl;
	ispisiMatricu(opn);
	cout << endl;
	}
  }
  
