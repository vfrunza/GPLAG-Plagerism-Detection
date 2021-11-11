#include <stdio.h> 
#include <math.h> 
#define e 0.0001
#define C 57.29577957 //180/PI

int main() 
{
  double t1x, t1y, t2x, t2y, t3x, t3y, d1, d2, d3, pu, pum;
  int u, um, us, prolaz = 0;

  printf("Unesite koordinate tacke t1:");
  scanf("%lf%lf", &t1x, &t1y);

  printf("Unesite koordinate tacke t2:");
  scanf("%lf%lf", &t2x, &t2y);

  printf("Unesite koordinate tacke t3:");
  scanf("%lf%lf", &t3x, &t3y);
  
  d1 = sqrt((t1x - t2x) * (t1x - t2x) + (t1y - t2y) * (t1y - t2y));
  d2 = sqrt((t1x - t3x) * (t1x - t3x) + (t1y - t3y) * (t1y - t3y));
  d3 = sqrt((t3x - t2x) * (t3x - t2x) + (t3y - t2y) * (t3y - t2y));


  if ((fabs((t1x * (t2y - t3y) + t2x * (t3y - t1y) + t3x * (t1y - t2y)) / 2)) < 0.1) 
  {
    printf("Linija");
    u = 180;
    um = 0;
    us = 0;
  } 
  else 
  {
    if ((fabs((pow(d1, 2) + pow(d2,2)) - pow(d3,2)) < 0.1) || (fabs((pow(d1, 2) + pow(d3,2)) - pow(d2,2)) < 0.1) || (fabs((pow(d3, 2) + pow(d2,2)) - pow(d1,2)) < 0.1)) 
    {
      printf("Pravougli\n");
      u = 90;
      um = 0;
      us = 0;
      prolaz = 1;
    }
    if ((fabs(d1 - d2) < e && (fabs(d2 - d3) < e) && (fabs(d1 - d3) < e))) 
    {
      printf("Jednakostranicni");
      u = 60;
      um = 0;
      us = 0;
    } 
    else if (((fabs(d1 - d2) < e) && (fabs(d1 - d3) >= e)) || ((fabs(d1 - d3) < e) && (fabs(d1 - d2) >= e)) || ((fabs(d2 - d3) < e) && (fabs(d2 - d1) >= e))) 
    {
      printf("Jednakokraki");
      if (prolaz == 0) 
      {
        if ((d1 >= d2) && (d1 >= d3)) 
        {
          //pu-privremeni ugao kao double
          pu = acos(((d2 * d2) + (d3 * d3) - (d1 * d1) / (2 * d2 * d3))) * C;
        } 
        else
        if ((d2 >= d1) && (d2 >= d3)) 
        {
          pu = acos(((d1 * d1) + (d3 * d3) - (d2 * d2) / (2 * d1 * d3))) * C;
        } else 
        {
          pu = (acos(((d2 * d2) + (d1 * d1) - (d3 * d3) / (2 * d1 * d2))) * C);
        }
        u = pu;
        //pum-privremeni ugao (minute) kao double
        pum = (pu - u) * 60;
        um = pum;
        us = (pum - um) * 60;
      }
    } 
    else 
    {
      printf("Raznostranicni");
      if (prolaz == 0); 
      {
        if ((d1 >= d2) && (d1 >= d3)) 
        {
          //pu-privremeni ugao kao double
          pu = acos(((d2 * d2) + (d3 * d3) - (d1 * d1)) / (2 * d2 * d3)) * C;
        } 
        else if ((d2 >= d1) && (d2 >= d3)) 
        {
          pu = acos(((d1 * d1) + (d3 * d3) - (d2 * d2)) / (2 * d1 * d3)) * C;
        } 
        else
          pu = acos(((d2 * d2) + (d1 * d1) - (d3 * d3)) / (2 * d1 * d2)) * C;
      }
      u = pu;
      //pum-privremeni ugao (minute) kao double
      pum = (pu * u) * 60;
      um = pum;
      us = (pum - um) * 60;
    }
  }
  printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", u, um, us);
  return 0;
}