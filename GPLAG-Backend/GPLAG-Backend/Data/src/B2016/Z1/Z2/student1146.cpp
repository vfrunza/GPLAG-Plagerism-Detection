/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<double> Red;
typedef std::vector<Red> Mat;

void provjeri(Mat osumnjiceni) {
	if (osumnjiceni.size() == 0) return;
	int sir = osumnjiceni[0].size();
	for (const auto red : osumnjiceni) 
		if (red.size() != sir)
			throw std::domain_error("Matrica nije korektna");
}

Mat h(Mat in) {
	provjeri(in);
	Mat rez;
	for (const auto red : in) {
		int sir = red.size();
		Red r(sir);
		for (int i = 0; i < sir; i++)
			r[i] = red[sir - i - 1];
		rez.push_back(r);
	}
	return rez;
}

Mat v(Mat in) {
	provjeri(in);
	int vis = in.size();
	Mat rez(vis);
	for (int i = 0; i < vis; i++)
		rez[i] = in[vis - i - 1];
	return rez;
}

Mat hv(Mat in) {
	return h(v(in));
}

Mat hor(Mat kuda, const Mat sta) {
	for (int i = 0; i < kuda.size(); i++) 
		for (auto a : sta[i])	
			kuda[i].push_back(a);
	return kuda;
}

Mat ver(Mat kuda, const Mat sta) {
	for (const Red red : sta) 
		kuda.push_back(red);
	return kuda;
}

Mat OgledaloMatrica(Mat in) {	
	provjeri(in);
	auto mhv = hv(in), mh = h(in), mv = v(in);
	
	Mat m1 = hor(hor(mhv, mv), mhv);
	Mat m2 = hor(hor(mh , in), mh );
	Mat m3 = hor(hor(mhv, mv), mhv);
	
	return ver(ver(m1, m2), m3);
}

int main () {
	using std::cout;
	using std::cin;
	
	cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	cin >> m >> n;
	
	if (m < 0 || n < 0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	Mat mat(m, Red(n));
	cout << "Unesite elemente matrice: ";
	for (int i = 0; i < mat.size(); i++)
		for (int j = 0; j < mat[i].size(); j++)
			cin >> mat[i][j];
	
	cout << "\nRezultantna matrica: \n";	
	
	for (const auto red : OgledaloMatrica(mat)) {
		for (const auto x : red)
			cout << std::setw(4) << x;
		cout << '\n';
	}
	
	return 0;
}