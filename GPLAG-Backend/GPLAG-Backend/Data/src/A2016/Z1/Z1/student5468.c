#include <stdio.h>

int main() {
	double Ipt,IIpt,pt,zt,zit,ubt,ubb,ubm,Ipb,IIpb,zb,pb,zib,Ipm,IIpm,pm,zm,zim;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Ipt);
	if ((Ipt<0)||(Ipt>20)){
printf("Neispravan broj bodova");
return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIpt);
	if ((IIpt<0)||(IIpt>20)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&pt);
	if ((pt<0)||(pt>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zadace: ");
	scanf("%lf",&zt);
	if ((zt<0||zt>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zit);
	if ((zit<0||zit>40)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Ipb);
	if ((Ipb<0||Ipb>20)){
printf("Neispravan broj bodova");
return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIpb);
	if ((IIpb<0)||(IIpb>20)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&pb);
	if ((pb<0)||(pb>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zadace: ");
	scanf("%lf",&zb);
	if ((zb<0)||(zb>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zib);
	if ((zib<0)||(zib>40)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Ipm);
	if ((Ipm<0)||(Ipm>20)){
printf("Neispravan broj bodova");
return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIpm);
	if ((IIpm<0)||(IIpm>20)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&pm);
	if ((pm<0)||(pm>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zadace: ");
	scanf("%lf",&zm);
	if ((zm<0)||(zm>10)){
printf("Neispravan broj bodova");
return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zim);
	if ((zim<0)||(zim>40)){
printf("Neispravan broj bodova");
return 0;
}
ubt=Ipt+IIpt+zt+pt+zit;
ubm=Ipm+IIpm+zm+pm+zim;
ubb=Ipb+IIpb+zb+pb+zib;
	if(ubt<55 && ubb<55 && ubm<55)
	printf("Nijedan student nije polozio.");
	else if((ubt<55 && ubb<55)||(ubt<55 && ubm<55)||(ubb<55 && ubm<55))
	printf("Jedan student je polozio.");
	else if(ubt<55 || ubm<55 || ubb<55)
	printf("Dva studenta su polozila.");
	else
	printf("Sva tri studenta su polozila.");
	if(ubt>=55&&ubb>=55&&ubm>=55){
		if((ubt<65 && ubb<65 && ubm<65)||(ubt>=65 && ubb>=65 && ubm>=65 && ubt<75 && ubb<75 && ubm<75)||(ubt>=75 && ubm>=75 && ubb>=75 && ubt<85 && ubb<85 && ubm<85)||(ubt>=85 && ubm>=85 && ubb>=85 && ubt<92 && ubb<92 && ubm<92)||(ubt>=92 && ubb>=92 && ubm>=92 &&ubt<=100 && ubb<=100 && ubm<=100))
		printf("\nSva tri studenta imaju istu ocjenu.");
		else if((ubt<65&&ubb<65&&ubm>=65)||(ubt<65&&ubm<65&&ubb>=65)||(ubm<65&&ubb<65&&ubt>=65)||(ubt>=65&&ubt<75&&ubb<75&&ubb>=65&&(ubm<65||ubm>=75))||(ubt<75&&ubt>=65&&ubm<75&&ubm>=65&&(ubb<65||ubb>=75))||(ubm>=65&&ubm<75&&ubb<75&&ubb>=65&&(ubt<65||ubt>=75))||(ubt>=75&&ubt<85&&ubb<85&&ubb>=75&&(ubm<75||ubm>=85))||(ubt>=75&&ubt<85&&ubm<85&&ubm>=75&&(ubb<75||ubb>=85))||(ubm>=75&&ubm<85&&ubb<85&&ubb>=75&&(ubt<75||ubt>=85))||(ubt>=85&&ubt<92&&ubb<92&&ubb>=85&&(ubm<85||ubm>=92))||(ubt>=85&&ubt<92&&ubm<92&&ubm>=85&&(ubb<85||ubb>=92))||(ubm>=85&&ubm<92&&ubb<92&&ubb>=85&&(ubt<85||ubt>=92))||(ubt>=92&&ubb>=92&&ubm<92)||(ubt>=92&&ubm>=92&&ubb<92)||(ubm>=92&&ubb>=92&&ubt<92))
		printf("\nDva od tri studenta imaju istu ocjenu.");
		else
		printf("\nSvaki student ima razlicitu ocjenu.");
	}
return 0;
}
