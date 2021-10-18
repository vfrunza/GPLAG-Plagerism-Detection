#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
	int n1;
	cout<<"Unesite broj elemenata prvog deka: ";
	cin>>n1;
	deque<double>p(n1);
	cout<<"Unesite elemenate prvog deka: ";
	for(int i=0;i<n1;i++){
		cin>>p[i]; //kako da ignorisem duplikate?
		if(p[i]==p[i-1]) n1++;
	}
	return 0;
}