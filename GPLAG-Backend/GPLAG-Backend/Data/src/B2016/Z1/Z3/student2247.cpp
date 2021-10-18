#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef vector<vector<double>> matrica;

matrica RastuciPodnizovi (std::vector<double> vec) {
	int j(0),ubaci(0), postoji(0);
	matrica mat(j+1);
	for(int i=0; i<vec.size()-1; i++) {
		if(i==vec.size() && ubaci==1) {
			mat[j].push_back(vec[i]);
			break;
		}
		else if(i==vec.size() && ubaci==0) break;
		else if(vec[i]-vec[i+1]<=0.00001) {
			mat[j].push_back(vec[i]);
			ubaci=1;
			postoji=1;
		}
		else if(vec[i]-vec[i+1]>0.00001 && ubaci==0) {
			if(postoji==1) {
				if(!(mat[j].empty())) {
					j++;
					mat.resize(j+1);
				}	
			}
		}
		else if(vec[i]-vec[i+1]>0.00001 && ubaci==1) {
			mat[j].push_back(vec[i]);
			ubaci=0;
			j++;
			mat.resize(j+1);
		}
	}
	if(postoji==1 && ubaci==1) {
		mat[j].push_back(vec[vec.size()-1]);
	}
	return mat;
}

matrica OpadajuciPodnizovi (std::vector<double> vec) {
	int j(0),ubaci(0), postoji(0);
	matrica mat(j+1);
	for(int i=0; i<vec.size()-1; i++) {
		if(i==vec.size() && ubaci==1) {
			mat[j].push_back(vec[i]);
			break;
		}
		else if(i==vec.size() && ubaci==0) break;
		else if(vec[i]>=vec[i+1]) {
			mat[j].push_back(vec[i]);
			ubaci=1;
			postoji=1;
		}
		else if(vec[i]-vec[i+1]<0.00001 && ubaci==0) {
			if(postoji==1) {
				if(!(mat[j].empty())) {
					j++;
					mat.resize(j+1);
				}
			}	
		}
		else if(vec[i]-vec[i+1]<0.00001 && ubaci==1) {
			mat[j].push_back(vec[i]);
			ubaci=0;
			j++;
			mat.resize(j+1);
		}
	}
	if(postoji==1 && ubaci==1) {
		mat[j].push_back(vec[vec.size()-1]);
	}
	return mat;
}

int main ()
{
	int vel;
	cout << "Unesite broj elemenata vektora: ";
	while(!(cin >> vel, vel>=1)) {
		cout << "Velecina niza mora biti prirodan broj. Unesite ponovo: ";
		cin.clear();
        cin.ignore(10000, '\n');
	}
	std::vector<double> vecm(vel);
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<vel; i++) {
		while(!(cin >> vecm[i])) {
			cout << "Element niza mora biti realan broj. Unesite ponovo: ";
			cin.clear();
            cin.ignore(10000, '\n');
		}
	}
	matrica rast=RastuciPodnizovi(vecm);
	matrica opad=OpadajuciPodnizovi(vecm);

	cout << "Maksimalni rastuci podnizovi: ";
	for(int i=0; i<rast.size(); i++) {
		cout << endl;
		for(int j=0; j<rast[i].size(); j++) {
			cout << rast[i][j] << " ";
		}
	}

	cout << endl << "Maksimalni opadajuci podnizovi: ";
	for(int i=0; i<opad.size(); i++) {
		cout << endl;
		for(int j=0; j<opad[i].size(); j++) {
			cout << opad[i][j] << " ";
		}
	}
	return 0;
}