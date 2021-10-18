#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;




int Funkcija (int x) {
	return x;
}

template <typename Tip1, typename Tip2>
vector<vector<Tip1>> UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 q1, Tip2 q2) {
	vector<vector<Tip1>> vec(1, vector<Tip1>(3));
	int j=0;
	Tip2 *pamti(q1);
	while(p1!=p2) {
		q1=pamti;
		while(q1!=q2) {
			if(Funkcija(*p1)==Funkcija(*q1)) {
				vec[j][0]=*p1;
				vec[j][1]=*q1;
				vec[j][2]=Funkcija(*p1);
				j++;
				vec.resize(vec.size()+1);
			}
			q1++;
		}
		p1++;
	}

	return vec;
}


int main ()
{
	int n1, n2;
	cout << "Unesite broj elemenata prvog deka: ";
	cin >> n1;
	vector<int> dek1, dek2;
	cout << "Unesite elemente prvog deka: ";
	for(int i=0; i<n1; i++) {
		cin >> dek1[i];
	}
	cout << "Unesite broj elemenata drugog deka: ";
	cin >> n2;
	cout << "Unesite elemente drugog deka: ";
	for(int i=0; i<n2; i++) {
		cin >> dek2[i];
	}
	sort(dek1.begin(), dek1.end());
	sort(dek2.begin(), dek2.end());
	unique(dek1.begin(), dek1.end());
	unique(dek2.begin(), dek2.end());
	vector<vector<int>> vec(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end()));
	for(int i=0; i<vec.size(); i++) {
		for(int j=0; j<vec[0].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}