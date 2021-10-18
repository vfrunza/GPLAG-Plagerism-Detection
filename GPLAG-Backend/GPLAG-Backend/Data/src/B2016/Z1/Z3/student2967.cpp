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

vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> mat;
	int k=0;
	int a;
	a=v.size();
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<10; j++){
			if(v[k]<v[k+1]){
				mat[i][j]=v[k];
			}
			
			else if((v[k]>v[k+1] && v[k+1]<v[k+2]) || k==a-1){
				mat[i][j]=v[k];
			}
			k++;
		}
	}
	return mat;
}
int main ()
{
    int n;
    cout << "Unesite broj elemenata vektora: ";
    cin >> n;
    vector<double> v(n);
    cout << "Unesite elemente vektora: ";
    for(int i=0; i<n; i++){
    	cin >> v[i];
    }
    cout << "Maksimalni rastuci podnizovi: " << endl;
    vector<vector<double>> a;
    a=RastuciPodnizovi(v);
    for(int i=0; i<v.size(); i++){
    	for(int j=0; j<10; j++){
    		cout << a[i][j];
    	}
    	cout << endl;
    }
    cout << "Maksimalni opadajuci podnizovi: " << endl;

	return 0;
}