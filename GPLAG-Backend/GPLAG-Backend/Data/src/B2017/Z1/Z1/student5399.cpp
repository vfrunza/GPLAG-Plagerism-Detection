#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool DaLiJeSimetrican( int n ) {
	vector<int> v;
	int a;
	while( n != 0 ) {
		a = n % 3;
		v.push_back(a);
		n = n / 3;
	}
	bool pret(true);
	for( int i = 0; i < v.size(); i++ ) {
		if( v.at(i) != v.at(v.size() - 1 - i) ) pret = false;
	}
	if( pret ) return true;
	else return false;
}

bool DaLiJeProst( int n ) {
	int br(0);
	for( int i = 2; i < n; i++ ) {
		if( n % i == 0 ) br ++;
	}
	if( br != 0 || n <= 2 ) return false;
	else return true;
}

vector<int> IzbaciDuple( vector<int> v ) {
	for( int i = 0; i < v.size(); i++ ) {
		for( int j = i + 1; j <= v.size() - 1; j++ ) {
			if( v.at(i) == v.at(j) ) {
				for( int k = j; k < v.size()-1; k++ ) v.at(k) = v.at(k+1);
				j--;
				v.resize(v.size() - 1);
			}
		}
	}
	return v;
}
vector<int> IzdvojiSimetricneTernarne( vector<int> v, bool n ) {
	vector<int> v1;
	v = IzbaciDuple(v);
	if( n ) {
		for( int i = 0; i < v.size(); i++ ) {
			if( DaLiJeProst(fabs( v.at(i) ) ) && DaLiJeSimetrican(fabs( v.at(i) ) ) ) v1.push_back( v.at(i) );
		}
	} else {
		for (int i = 0; i < v.size(); i++) {
			if( !DaLiJeProst( fabs( v.at(i) ) ) && DaLiJeSimetrican( fabs( v.at(i) ) ) ) v1.push_back( v.at(i) );
		}
	}
	return v1;
}

int main ()
{
	vector<int> v;
	int n;
	cout << "Unesite elemente vektora (-1 za kraj): ";
	do{
		cin >> n;
		if( n != -1 ) v.push_back(n);
		
	}
	while( n != -1 );
	int z;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: "; 
		while( 1 ) {
			cin >> z;
			if(z < 0 || z > 1) {
			cout << "Neispravan unos! ";
		    cout << "Unesite ponovo: ";}
		    else break;
		    
	    }
	
	v = IzdvojiSimetricneTernarne(v, z);
	if( z == 1 && v.size() != 0 ) {
		cout << "Prosti simetricni brojevi iz vektora su: ";
		for( int i = 0; i < v.size(); i++ ) {
			if( v.size() - 1 - i != 0 ) cout << v.at(i) <<", ";
			else cout << v.at(i) << ".";
		}
	}
	
	else if ( z == 0 && v.size() != 0 ) {
		cout << "Slozeni simetricni brojevi iz vektora su: ";
		for( int i = 0; i < v.size(); i++ ) {
			if( v.size() - 1 - i != 0 ) cout << v.at(i) <<", ";
			else cout << v.at(i) << ".";
		}
	}
	if( z == 1 && v.size() == 0 ) cout << "Nema prostih simetricnih brojeva u vektoru.";
	if( z == 0 && v.size() == 0 ) cout << "Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}