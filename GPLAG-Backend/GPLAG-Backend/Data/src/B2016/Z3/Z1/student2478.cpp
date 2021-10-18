#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#if 0
std::function<double(double)> BaricentricnaInterpolacija(
  std::vector<std::pair<double, double>> cvorovi, int d) {
    int n(cvorovi.size());
    std::vector<double> w(n);
    if(d < 0 || d >= n) throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i < n; i++)
      for(int k = std::max(0, i - d); k < std::min(i + 1, n - d); k++) {
        double p(1);
        for(int j = k; j <= k + d; j++)
          if(i != j) p *= cvorovi[i].first - cvorovi[j].first;
        if(p == 0) throw std::domain_error("Neispravni cvorovi");
        if(k % 2 == 0) w[i] += 1 / p;
        else w[i] -= 1 / p;
      }
    return [cvorovi, w](double x) {
      double p(0), q(0);
      for(int i = 0; i < cvorovi.size(); i++) {
        if(x == cvorovi[i].first) return cvorovi[i].second;
        double u = w[i] / (x - cvorovi[i].first);
        p += u * cvorovi[i].second; q += u;
      }
      return p / q;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(
  std::function<double(double)> fn, double xmin, double xmax, double dx, int d) {
    std::vector<std::pair<double, double>> cvorovi;
    for(double x = xmin; x <= xmax; x += dx)
      cvorovi.push_back(std::make_pair(x, fn(x)));
    return BaricentricnaInterpolacija(cvorovi, d);
}
#endif
#if 1
typedef std::function<double (double)> FunDblDbl;
FunDblDbl BaricentricnaInterpolacija (
             const std::vector<std::pair<double, double>> &v, int d)
{
    int n = v.size();
    if (d < 0 || d >= n)
        throw std::domain_error ("Nedozvoljen red");
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = i + 1; j < v.size(); ++j)
            if (v.at(i).first == v.at(j).first)
                throw std::domain_error ("Neispravni cvorovi");
    std::vector<double> w (n);
    for (int i = 1; i <= n; ++i)
        for (int k = std::max (1, i - d); k <= std::min (i, n - d); ++k)
        {
            double p = 1;
            for (int j = k; j <= k + d; ++j)
                (i == j) || (p *= 1. / (v.at(i - 1).first - v.at(j - 1).first));
            w.at(i - 1) += std::pow (-1, k - 1) * p;

        }

    return [n, v, w] (double x)
    {
        double br = 0, na = 0;
        for (size_t i = 1; i <= n; ++i)
        {
            double r = x - v.at(i - 1).first;
            if (r == 0) return v.at(i - 1).second;
            br += w.at(i - 1) / r * v.at(i - 1).second;
            na += w.at(i - 1) / r;
        }
        return br / na;
    };
}
FunDblDbl BaricentricnaInterpolacija (FunDblDbl f, double xmin, double xmax, double dx, int d)
    {
        if (xmin > xmax || dx <= 0) throw std::domain_error ("Nekorektni parametri");
        std::vector<std::pair<double, double>> p;
        for (double i = xmin; i <= xmax; i += dx)
            p.emplace_back(i, f(i));
//        std::cout << "vektor: \n{";
//        for (auto i : p) std::cout << "{" << i.first << ", " << i.second << "}, ";
//        std::cout << "}\n";
        return BaricentricnaInterpolacija(p, d);
    }
#endif
double fun (double x) {return x * x + std::sin (x);}
int __main() {
  int opcija;
  std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
  std::cin >> opcija;
  if(opcija == 1) {
    int n, d;
    std::cout << "Unesite broj cvorova: ";
    std::cin >> n;
    std::vector<std::pair<double, double>> cvorovi(n);
    std::cout << "Unesite cvorove kao parove x y: ";
    for(auto &par : cvorovi) std::cin >> par.first >> par.second;
    std::cout << "Unesite red interpolacije: ";
    std::cin >> d;
    auto f(BaricentricnaInterpolacija(cvorovi, d));
    for(;;) {
      double x;
      std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
      std::cin >> x;
      if(!std::cin) break;
      std::cout << "f(" << x << ") = " << f(x) << std::endl;
    }
  }
  else {
    double xmin, xmax, dx;
    auto testfn([](double x) { return x * x + std::sin(x); });
    std::cout << "Unesite krajeve intervala i korak: ";
    std::cin >> xmin >> xmax >> dx;
    int d;
    std::cout << "Unesite red interpolacije: ";
    std::cin >> d;
    auto f(BaricentricnaInterpolacija(testfn, xmin, xmax, dx, d));
    for(;;) {
      double x;
      std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
      std::cin >> x;
      if(!std::cin) break;
      std::cout << "f(" << x << ") = " << testfn(x)
        << " fapprox(" << x << ") = " << f(x) << std::endl;
    }
  }
}

double xxxsinx (double x) {return x * x + std::sin(x);}
int main5()
{
    /* 
    Autotest koji testira efikasnost vaseg rjesenja. Pri tome se ne misli
    bas na efikasnost nego na logicno rezonovanje prilikom implementacije.
    
    Naime, kao sto se moze vidjeti, koeficijenti Wi su konstantni za identican
    skup cvorova odnosno, ne zavise od parametra funkcije - neovisni su od
    interpolirane funkcije. Stoga bi logicno rjesenje bilo da se ti koeficijenti
    tako i tretiraju - da su konstantni u interpoliranoj funkciji.
    
    Shodno tome, kada neko pozove funkciju BaricentricnaInterpolacija, trebaju se ti
    koeficijenti izracunati i *tako izracunati koeficijenti* proslijediti u
    lambda funkciju koju vracamo iz funkcije (lambda ih treba zarobiti).
    Gledajmo to na ovom primjeru:
        auto fun = BaricentricnaInterpolacija (veliki_vektor, veliko_d);
    Ovdje je kreiran objekat 'fun' (koji je polimorfni funkcijski omotac, u njega
    je smjestena funkcija koji smo vratili).
    Ako je rjesenje uradjeno "pametno", u ovom gore pozivu su izracunati Wi koeficijenti
    i smjesteni u 'fun'. Znaci, racunanje koeficijenata je trebalo uraditi JEDNOM!
    
    Pogledajmo sada pozive 'fun' funkcije:
        for (int i = 1; i <= 10000; ++i)
            std::cout << fun (i * korak + konstanta) << " ";
    
    Ocito je da ovaj poziv iznad efikasan: imamo VEC izracunate Wi koeficijente
    i 10 hiljada puta ih iskoristimo da bismo interpolirali funkciju...
    
    Sada, zamislimo isti ovaj primjer ali da Wi racunamo U LAMBDI: morali bismo
    10 hiljada puta (u ovom pozivu gore) racunati Wi!? A ako se sjetimo,
    za racunanje svih Wi (i = 1..n) koeficijenata, treba trostruka (ugnijezdena)
    petlja! Za racunanje i-tog W-a, nam trebaju dvije petlje, ugnijezdene,
    za proizvod i sumu.
    
    Ako su n (velicina vektora) i d veliki onda za racunanje svih Wi (i = 1..n)
    treba bas puno vremena. Ali, kod "pametne" (i logicne) implementacije, 
    student zakljuci da to racunanje treba SAMO JEDNOM, a ne pri svakom pozivu
    lambde!
    
    Malo vise matematsko-algoritamski: za racunanje W koeficijenta imamo
    O (n * d * d) algoritamski slozenost. Za priblizno n == d, to je O (n ^ 3).
    Ako je n >> 1, npr. 1000, imamo da je potrebno uraditi 1000^3 iteracija, sto
    je jedna milijarda. Milijarda za racunanje Wi koeficijenta.
    Jos je potrebna jedna petlja (1..n) za interpoliranje (onaj kolicnih suma).
    
    Ako je neko radio racunanje Wi koeficijenata u lambdi, onda neka tu lambdu
    pozovemo 1000 puta, za n = d = 1000, imamo O (n ^ 4) slozenost, tj. bit ce
    potrebno 1000^4 racunanja sto je trilion (10^12).
    
    Na racunaru sa standardnim karakteristikama, za 1000 poziva lambda funkcije,
    i za velicinu vektora od 1000 cvorova, programu treba VISE OD 3h da se izvrsi.
    Dok, ukoliko smo Wi racunali van lambde (odnosno, samo jednom), program se zavrsi
    za manje od 1 sekunde. Ovo je ZAISTA NEZANEMARLJIVA razlika: 1s vs 3h+.
    O (n) vs O (n ^ 3)

    */
    auto funkcija = [](double x) {return x * 3 + 17;}; //linearna funkcija, fini brojevi
    const int N = 1000;
    std::vector<std::pair<double, double>> vek;
    vek.reserve (N);
    double x = -205, param = 72;
    for (int i = 1; i <= N; ++i, x += 0.5)
        vek.emplace_back (x, funkcija (x));
    auto f = BaricentricnaInterpolacija(vek, N - 1);
    //sada dolazi "problematican" dio. Pozovimo lambdu 1000 puta.
    for (int i = 1; i <= N; ++i)
        f (i * param + 2.5); //ignoriramo rezultat funkcije
    //za svaki slucaj provjerimo da li je interpolacija ispravna:
    std::cout << "f (55.5) = " << f (55.5) << std::endl
              << "f (1.5) = " << f (1.5);
}   
int main ()
{
    int a;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> a;

    std::vector<std::pair<double, double>> vek;
    if(a == 1)
    {
        int n, r;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < n; i++)
        {
            double x, y;
            std::pair<double, double> p;
            std::cin >> x >> y;
            p = std::make_pair(x, y);
            vek.push_back(p);
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> r;
        double arg;
        double vr = 0;
        try
        {
            std::function<double(double)> fu = BaricentricnaInterpolacija(vek, r);

            for(; ;)
            {
                vr = 0;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;

                if(!std::cin)
                    break;

                vr = fu(arg);
                std::cout << "f(" << arg << ") = " << vr << std::endl;
            }
        }
        catch(std::domain_error e)
        {
            std::cout << e.what();
        }
    }

    if(a == 2)
    {
        double poc, kr, dx, arg;
        int r; 
        double vr1 = 0, vr2 = 0;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> poc >> kr >> dx;

        std::cout << "Unesite red interpolacije: ";
        std::cin >> r;

        try
        {
            std::function<double(double)> fu = BaricentricnaInterpolacija(xxxsinx, poc, kr, dx, r);
            for(; ;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;

                if(!std::cin)
                    break;

                vr1 = xxxsinx(arg);
                vr2 = fu(arg);
                std::cout << "f(" << arg << ") = " << vr1 << " fapprox(" << arg << ") = " << vr2 << std::endl;
            }
        }

        catch(std::domain_error e)
        {
            std::cout << e.what();
        }
    }
	return 0;
}
#include <fstream>
#include <cmath>
#if 0
std::streambuf *Redirect (const char *ime)
{
    static std::ofstream out(ime);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    return coutbuf;
}
double x3 (double x) {return x * x * x;}
int main3()
{

    //goto AT;
    Redirect("AT20.txt");
{//AT10 (neaktivan): da li main baca izuzetak (2)?
    main();
}
return 20;
{//AT19 (neaktivan): da li main baca izuzetak (1)?
    main();
}
return 19;
{//AT18 (skriveni): povratni tip + (x - xi == 0) + samo jedan par
    std::function<double(double)> fun =
        BaricentricnaInterpolacija({{5, 7.777}}, 0);
    std::cout << fun (5);
}//7.777
return 18;

{//AT17 (zamger): random parovi, preveliko d?
    auto fun = BaricentricnaInterpolacija({
        {1, 2}, {0, 4}, {-5, 2}, {11, 5},
        {3, 2}, {5, 4}, {4.3, 50}, {2, 5},
        {-3, 2}, {-4, 4}, {24.1, 25}, {12, 15}
    }, 11);
    for (double i = -8; i <= 15.1; i += 1.37)
        std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;

}/*
fun (-8) = -267379.8225
fun (-6.6300) = -27503.8421
fun (-5.2600) = -447.6533
fun (-3.8900) = -14.3603
fun (-2.5200) = 59.5185
fun (-1.1500) = 67.8889
fun (0.2200) = -0.1430
fun (1.5900) = 6.1883
fun (2.9600) = 1.5350
fun (4.3300) = 50.5912
fun (5.7000) = -303.8701
fun (7.0700) = -2496.4858
fun (8.4400) = -6472.9606
fun (9.8100) = -6848.2176
fun (11.1800) = 1130.0719
fun (12.5500) = -15790.0247
fun (13.9200) = -221563.8145
*/
return 17;
{//AT16 (skriven): prazan vektor cvorova, Vd -> izuzetak
    for (int d = 0; d <= 6; ++d)
        try {BaricentricnaInterpolacija({}, d); std::cout << "NOK_d = " << d << std::endl;}
        catch (const std::domain_error &r) {std::cout << "E_d" << d << ": '" << r.what() << "'" << std::endl;}
        catch (...) {std::cout << "Pogresan izuzetak_d = " << d << std::endl;}
    std::cout << BaricentricnaInterpolacija({{1, 1}, {5, 5}}, 1)(2.7);
} /*
E_d0: 'Nedozvoljen red'
E_d1: 'Nedozvoljen red'
E_d2: 'Nedozvoljen red'
E_d3: 'Nedozvoljen red'
E_d4: 'Nedozvoljen red'
E_d5: 'Nedozvoljen red'
E_d6: 'Nedozvoljen red'
2.7
*/
return 16;
{//AT15 (skriveni): izuzetak, xmin > xmax + dx < 0 + red 0 (d = 0) + xmin = xmax
    try {BaricentricnaInterpolacija([](double a){return a;}, 1.1, 1.0, 0.1, 2); std::cout << "Ne smije_1 ";}
    catch (const std::domain_error &r) {std::cout << "E1: '" << r.what() << "'" << std::endl;}
    catch (...) {std::cout << "Pogresan tip izuzetka_1 ";}

    try {BaricentricnaInterpolacija([](double a){return a;}, 1.1, 2.0, -0.1, 2); std::cout << "Ne smije_2 ";}
    catch (const std::domain_error &r) {std::cout << "E2: '" << r.what() << "'" << std::endl;}
    catch (...) {std::cout << "Pogresan tip izuzetka_2 ";}

    auto fun = BaricentricnaInterpolacija([](double x){return 1 / x;}, 0.5, 0.5, 0.1, 0);
    for (double i = 0.3; i < 0.7; i += 0.1)
        std::cout << "fun (" << i << ") = " << fun (i) << std::endl;
} /*
E1: 'Nekorektni parametri'
E2: 'Nekorektni parametri'
fun (0.3) = 2
fun (0.4) = 2
fun (0.5) = 2
fun (0.6) = 2
*/
return 15;

{//AT14 (neaktivan): saljemo funktor (funkcijski objekat - klasu) u funkciju
 //i capturing-lambda je funktor.. stoga, kao parametar funkcije je trebao ici
 //std::function<double(double)> a ne pokazivac na fun, npr: double f (double)
 int dummy = 7;
 auto fun = BaricentricnaInterpolacija([dummy](double x){return x * x + 2 * x - x * x * x + 1;}, -2, 2, 0.35, 4);
 for (double i = -1.9; i <= 1.4; i += 0.17)
    std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;
} /*
fun (-1.9) = 7.6690
fun (-1.7300) = 5.7106
fun (-1.5600) = 4.1100
fun (-1.3900) = 2.8377
fun (-1.2200) = 1.8642
fun (-1.0500) = 1.1601
fun (-0.8800) = 0.6959
fun (-0.7100) = 0.4420
fun (-0.5400) = 0.3691
fun (-0.3700) = 0.4476
fun (-0.2000) = 0.6480
fun (-0.0300) = 0.9409
fun (0.1400) = 1.2969
fun (0.3100) = 1.6863
fun (0.4800) = 2.0798
fun (0.6500) = 2.4479
fun (0.8200) = 2.7610
fun (0.9900) = 2.9898
fun (1.1600) = 3.1047
fun (1.3300) = 3.0763
*/
return 14;

{//AT13 (neaktivan): saljemo funktor (funkcijski objekat - klasu) u funkciju
 //i capturing-lambda je funktor.. stoga, kao parametar funkcije je trebao ici
 //std::function<double(double)> a ne pokazivac na fun, npr: double f (double)
 int dummy = 7;
 auto fun = BaricentricnaInterpolacija([dummy](double x){return x * x + 2;}, -1, 1, 0.2, 3);
 for (double i = -1; i <= 1.2; i += 0.15)
    std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;
}/*
fun (-1) = 3.0000
fun (-0.8500) = 2.7225
fun (-0.7000) = 2.4900
fun (-0.5500) = 2.3025
fun (-0.4000) = 2.1600
fun (-0.2500) = 2.0625
fun (-0.1000) = 2.0100
fun (0.0500) = 2.0025
fun (0.2000) = 2.0400
fun (0.3500) = 2.1225
fun (0.5000) = 2.2500
fun (0.6500) = 2.4225
fun (0.8000) = 2.6400
fun (0.9500) = 2.9025
fun (1.1000) = 3.2100
*/
return 13;
{//AT12 (skriveni): izuzetak, isti x-ovi kod cvorova
    try
    {
        BaricentricnaInterpolacija({{1, 1}, {1, 2}, {3, 3}}, 1);
        std::cout << "Ne smije se ispisati_1" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E1: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati_1" << std::endl;}

    std::cout << std::endl;

    try
    {
        BaricentricnaInterpolacija({{1, 1}, {2, 2}, {1, 3}}, 1);
        std::cout << "Ne smije se ispisati_2" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E2: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati_2" << std::endl;}

    std::cout << std::endl;

    try
    {
        BaricentricnaInterpolacija({{1, 1}, {5, 2}, {3, 1}, {3, 0}}, 1);
        std::cout << "Ne smije se ispisati_3" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E3: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati_3" << std::endl;}

}/*
E1: 'Neispravni cvorovi'
E2: 'Neispravni cvorovi'
E3: 'Neispravni cvorovi'
*/
return 12;
{//AT11 (skriveni): izuzetak, d == n
    try
    {
        BaricentricnaInterpolacija({{1, 1}, {2, 2}, {3, 3}}, 3);
        std::cout << "Ne smije se ispisati" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati" << std::endl;}
}//E: 'Nedozvoljen red'
return 11;
{//AT10 (zamger): izuzetak (d < 0 | d = 5 (n = 3))
    try
    {
        BaricentricnaInterpolacija({{1, 1}, {2, 2}, {3, 3}}, -2);
        std::cout << "Ne smije se ispisati_1" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E1: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati_1" << std::endl;}
    std::cout << std::endl;
    try
    {
        BaricentricnaInterpolacija({{1, 1}, {2, 2}, {3, 3}}, 5);
        std::cout << "Ne smije se ispisati_2" << std::endl;
    }
    catch (const std::domain_error &r) {std::cout << "E2: '" << r.what() << "'";}
    catch (...) {std::cout << "Ni ovo se ne smije ispisati_2" << std::endl;}
}/*
E1: 'Nedozvoljen red'
E2: 'Nedozvoljen red'
*/
return 10;
{//AT9 (zamger): aproksimacija x * x * x funkcije
    auto fun = BaricentricnaInterpolacija([](double x){return x * x * x;}, -1, 1, 0.1, 3);
    for (double i = -2; i <= 2; i += 0.35)
        std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;
}/*fun (-2) = -8.0000
fun (-1.6500) = -4.4921
fun (-1.3000) = -2.1970
fun (-0.9500) = -0.8574
fun (-0.6000) = -0.2160
fun (-0.2500) = -0.0156
fun (0.1000) = 0.0010
fun (0.4500) = 0.0911
fun (0.8000) = 0.5120
fun (1.1500) = 1.5209
fun (1.5000) = 3.3750
fun (1.8500) = 6.3316
*/
return 9;
AT:
{//AT8 (c9): parovi x^3 funkcije
    std::vector<std::pair<double, double>> pairs = {
        {-1, -1}, {-0.9, -0.729}, {-0.8, -0.512},
        {-0.7, -0.343}, {-0.6, -0.216}, {-0.5, -0.125},
        {-0.4, -0.064}, {-0.3, -0.027}, {-0.2, -0.008},
        {-0.1, -0.001}, {0, 0},
        {0.1, 0.001}, {0.2, 0.008}, {0.3, 0.027},
        {0.4, 0.064}, {0.5, 0.125}, {0.6, 0.216},
        {0.7, 0.343}, {0.8, 0.512}, {0.9, 0.729}, {1, 1}
    };
    auto fun = BaricentricnaInterpolacija(pairs, 3);
    for (double i = -2; i <= 2; i += 0.35)
        std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;
}/*
fun (-2) = -8.0000
fun (-1.6500) = -4.4921
fun (-1.3000) = -2.1970
fun (-0.9500) = -0.8574
fun (-0.6000) = -0.2160
fun (-0.2500) = -0.0156
fun (0.1000) = 0.0010
fun (0.4500) = 0.0911
fun (0.8000) = 0.5120
fun (1.1500) = 1.5209
fun (1.5000) = 3.3750
fun (1.8500) = 6.3316
*/
return 8;
#if 1
{//redirect ATs


{//AT7 (c9): test maina (2/3) (prekid necim sto nije 'kraj')
 //aproksimacija bi trebala biti dobra! (d = 4, korak 0.05)
    main();
}/*
2
0 1 0.05
4
1
2
3
4
5
0.3
0.57
-2
-4
-7
-0.7
0.1
0.2
0.333B

*/

return 7;
{//AT6 (c9): test maina (2/3)
    main();

}/*
2
0 1 0.1
0.3
0.57
5
kraj

*/

return 6;
{//AT5 (c9): test maina (1/3)
    main();
}/*1
5
1 3
2 5
4 4
5 2
7 1
2
2.5
4
5.32
kraj

*/

}
#endif
return 5;
{//AT4 (c9): primjer iz postavke zadatka (2.2)
    auto fun = BaricentricnaInterpolacija(xxsinx, 0, 1, 0.1, 2);
    double tacke[] = {0.3, 0.57, 5};
    for (const auto &i : tacke)
        std::cout << "fun (" << i << ") = " << fun (i) << std::endl;
}//fun (0.3) = 0.38552
//fun (0.57) = 0.864515
//fun (5) = 24.289

return 4;
{//AT3 (c9): primjer iz postavke zadatka* (1.1)
    auto fun = BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2);
    double tacke[] = {2.5, 4, 5.32};
    for (const auto &i : tacke)
        std::cout << "fun (" << i << ") = " << fun (i) << std::endl;
}//fun (2.5) = 5.425
//fun (4) = 4
//fun (5.32) = 1.47372
return 3;
{//AT2 (c9): primjer iz postavke zadatka (2.1)
    auto fun = BaricentricnaInterpolacija(xxsinx, 0, 1, 0.1, 2);
    std::cout << "fun (0.3) = " << fun (.3);
}//fun (0.3) = 0.38552
return 2;
{//AT1 (c9): primjer iz postavke zadatka (1.1)
    auto fun = BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2);
    std::cout << "fun (2.5) = " << fun (2.5);
}//fun (2.5) = 5.425

}
#endif