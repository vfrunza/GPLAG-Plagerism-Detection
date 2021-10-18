#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c;
	cout << "Unesite tri broja: ";
	cin >> a >> b >> c;
	if (a+b>c && a+c>b && b+c>a &&a>0 && b>0 && c>0) {
		double s=(a+b+c)/2;
		double P=sqrt(s*(s-a)*(s-b)*(s-c));
		const double PI=4*atan(1);
		double alfa, beta, gama;
		gama=acos((a*a+b*b-c*c)/(2*a*b));
		alfa=acos((c*c+b*b-a*a)/(2*b*c));
		beta=acos((a*a+c*c-b*b)/(2*a*c));
		double max=0;
		if (alfa>beta && alfa>gama) max=alfa;
		if (beta>alfa && beta>gama) max=beta;
		if (gama>alfa && gama>beta) max=gama;
		double step;
		step= (max*180)/PI;
		double stepeni = int (step);
		double min=(step-stepeni)*60;
		double minute = int (min);
		double sek = int (min);
		int sekunde=(min-sek)*60;
		cout << "Povrsina trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi"<<P<<"."<<endl;
		cout << "Njegov najveci ugao ima "<<stepeni<<" stepeni, "<<minute<<" minuta i "<<sekunde<< "sekundi.";
	} else cout << "Ne postoji trougaao cije su duzine stranica: "<<a<<", "<<b<<" i "<<c<<endl;
	return 0;
}