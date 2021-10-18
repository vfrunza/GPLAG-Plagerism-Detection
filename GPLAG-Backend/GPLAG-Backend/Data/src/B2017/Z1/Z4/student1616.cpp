#include <iostream>
#include <string>
#include <vector>


using namespace std;

string OkreniNaopacke( string s) {
	string rec(s);
	int j(0);
	for( int i = s.size() - 1; i >= 0; i-- ) {
		rec[j] = s[i];
		j++;
	}
	return rec;
}

string NapraviPalindrom ( string s, vector<string> v ) {
	int br(0);
	string rec;
	for( int i = 0; i < v.size(); i++ ) {
		for( int j = 0; j < s.size(); j++ ) {
			if( s.substr( j, v[i].size() ) == v[i] ) {
				//cout << s.substr( j, v[i].size() );
				s = s.substr( 0, j ) + s.substr( j, v[i].size() ) + s.substr( j, s.size() - 1 );
			}
		}
	}
	return s;
}

int main ()
{
	vector<string> v = {"sunce","Danas", "je", "kisa","meso od sira"};
	string s = {" Danas je kisa ali vec sutra je sunce "};
	s = NapraviPalindrom(s, v);
	cout << s << endl;
	return 0;
}
/*
string NapraviPalindrom ( string s, vector<string> v ) {
	int br(0);
	string rec;
	deque<string> pom;
	for( int i = 0; i < v.size(); i++ ) {
		for( int j = 0; j < s.size(); j++ ) {
			if( ( s[j] >= 'A' && s[j] <='Z' ) || ( s[j] >= 'a' && s[j] <='z' ) ) {
				int poz (j);
			    while( ( s[j] >= 'A' && s[j] <='Z' ) || ( s[j] >= 'a' && s[j] <='z' ) ) {
			    	br++;
				    j++;
			    }
			if( s.substr( poz, br ) == v[i] ) {
				s = s.substr( 0, j ) + OkreniNaopacke( s.substr(poz, br) ) + s.substr( j, s.size() - j );
			}
			br = 0;
			}
		}
	}
	return s;
}
*/