#include <iostream>
#include <vector> 
#include <deque>

using namespace std;

enum Smjer { Rastuci, Opadajuci };

bool DaLiJeStepenDvojke( int n ) {
	if( n == 1 ) return true;
	while ( n > 2 ) {
		if( n % 2 != 0 ) return false;
		n = n / 2;
	}
	if( n == 2 ) return true;
	else return false;
}

vector<int> Provjera ( vector<int> v ) {
	bool n(true);
	int pol( v.size() );
	for( int i = 0; i < v.size(); i++ ) {
		if( !DaLiJeStepenDvojke( v.at(i) ) ) {
			n = false;
			pol = i;
		}
	}
	if( pol >= 2 && n == false ) {
		v.resize(pol);
		return v;
	}
	if( pol < 2 && n == false ) {
		v.resize(0);
	    return v;
	}
	else return v;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke( vector<int> v, Smjer smjer ) {
	int br(0);
	deque<vector<int>> mat;
	vector<int> pom_vec;
	if( smjer == Rastuci ) {
		for( int i = 0; i < v.size()-1; i++ ) {
			if( v.at(i) < v.at(i+1) ) {
				while( i != v.size()-1 && v.at(i) < v.at(i+1) ) {
					if( br == 0 ) pom_vec.push_back( v.at(i) );
				    pom_vec.push_back( v.at(i+1) );
				    i ++;
				    br ++;
			    }
			pom_vec.push_back(-1);
			br = 0;
			}
		}
		vector<int> pom;
		int j(0), k(1);
		for( int i = 0; i < pom_vec.size(); i++ ) {
			pom.resize(0);
			while( pom_vec.at(i) != -1 ) {
				pom.push_back( pom_vec.at(i) );
				i++;
			}
			 pom = Provjera( pom );
			if( pom.size() > 0 ) {
				mat.resize(k++);
				for( int k = 0; k < pom.size(); k++ ) mat.at(j).push_back( pom.at(k) );
				j++;
			}
		}
	}
	if( smjer == Opadajuci ) {
		for( int i = 0; i < v.size()-1; i++ ) {
			if( v.at(i) > v.at(i+1) ) {
				while( i != v.size() - 1 && v.at(i) > v.at(i+1) ) {
				    if( br == 0 ) pom_vec.push_back( v.at(i) );
				    pom_vec.push_back( v.at(i+1) );
				    i ++;
				    br ++;
				}
			pom_vec.push_back(-1);
			br = 0;
			}
		}
		vector<int> pom;
		int j(0), k(1);
		for( int i = 0; i < pom_vec.size(); i++ ) {
			pom.resize(0);
			while( pom_vec.at(i) != -1 ) {
				pom.push_back( pom_vec.at(i) );
				i++;
			}
			 pom = Provjera( pom );
			if( pom.size() > 0 ) {
				mat.resize(k++);
				for( int k = 0; k < pom.size(); k++ ) mat.at(j).push_back( pom.at(k) );
				j++;
			}
		}
	}
	return mat;
}

int main ()
{
	int n;
	deque<vector<int>>mat;
	cout << "Unesite broj elemenata vektora: "; cin >> n;
	vector<int> v(n);
	cout << "Unesite elemente vektora: ";
	for( int i = 0; i < v.size(); i++ ) cin >> v.at(i);
	int m;
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: "; cin >> m;
	if( m == 1 ) {
		mat = MaksimalniPodnizoviStepenaDvojke( v, Rastuci );
		cout << "Maksimalni rastuci podnizovi: " << endl;
	} else if( m == 2 ) {
		mat = MaksimalniPodnizoviStepenaDvojke( v, Opadajuci );
		cout << "Maksimalni opadajuci podnizovi: " << endl;
	}
	for( int i = 0; i < mat.size(); i++ ) {
		for( int j = 0; j < mat[i].size(); j++ ) {
			cout << mat.at(i).at(j) << " ";
		}
		cout << endl;
	}
	return 0;
}