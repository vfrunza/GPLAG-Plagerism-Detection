#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


int main ()
{
	cout<<"Koliko zelite elemenata: ";
	int n;
	cin>>n;
	vector<double> brojevi(n);
	cout<<"Unesite elemente: ";
	for(int i=0; i<n; i++) cin>>brojevi.at(i);
	transform(brojevi.begin(), brojevi.end(), brojevi.begin(), bind(std::divides<double>(),1,placeholders::_1));
	cout<<"Transformirani elementi: ";
	for(int i=0; i<n; i++) cout<<brojevi.at(i)<<" ";
	return 0;
}