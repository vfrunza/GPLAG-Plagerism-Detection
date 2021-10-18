#include <iostream>
#include <vector>
#include <algorithm>
template <typename T1, typename T2,typename T3>
template <typename T>
T f(T n) {
	T suma=0;
	while (n!=0) {
		suma=suma+n%10;
		n/=10;
	}
	return suma;
}

std::vector<std::vector<T1>UvrnutiPresjek (T1 p1, T1 p2, T2 p3, T2 p4, T f())   {
	std::vector<std::vector<T1>>mat;
	int n=0;
	T1 *q1=p1; T2 *q2=p3;
	while (q1!=p2 && q2!=p4) {
		if (f(*q1)==f(*q2)) n++;
		q1++; q2++;
	}
	mat.resize(n);
	for (int i=0; i<mat.size(); i++) mat[i].resize(3);
	int a=0;
	while (p1!=p2 && p3!=p4) {
		if (f(*p1)==f(*p3)) {
			i=0;
			mat[a][i]=*p1; i++;
			mat[a][i]=*p3; i++;
			mat[a][i]=f(*p1);
			a++;
		}
		p1++; p3++;
	}
	std::sort(mat[0],mat+n, bool [](int a,int b) {
		int s1=0, s2=0; int a1=a, b1=b;
		s1=f(a1); s2=f(a2);
		return ()
	})
}

int main () {
	
	return 0;
}