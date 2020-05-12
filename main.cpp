///zadacha 6 is predlogennih, zadaetsja koordinati vhoda i vihoda lucha, kol-vo razbienij na uchastki (N)
///koeficienty: 0-koeficient v meste vhoda, ot 1 do N-1 v mestah razbienij, N-v meste vihoda
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double d_y(double h, double n1, double n2, double s)
{
    double y=0;
    for (int i=0; i<10; i++)
    {
        y+=h/10*tan(asin(20*s/(n1*(19-2*i)+n2*(1+2*i))));
    }
    return y;
}

int main()
{
    int k=0;
    double y1, y2, h;
    double f=0;
    int N;
    double n[1000];
    cout<<"koordinata vhoda: ";
    cin>>y1;
    cout<<"koordinata vihoda: ";
    cin>>y2;
    cout<<"tolschina: ";
    cin>>h;
    cout<<"kol-vo promejutkov: ";
    cin>>N;
    cout<<"koeficienty: ";
    for(int i=0; i<=N; i++)
    {
        cin>>n[i];
    }
    if (y1!=y2)
    {
        double y00=0;
        for (int j=0; j<N; j++)
        {
            y00+=d_y(h/N, n[j], n[j+1], 1);
        }
        if (y00<fabs(y1-y2))
        {
            k=1;
            cout<<"net takogo ugla";
        }
        else
        {
           double f0;
           double f1;
           if (y2<y1)
           {
               f1=-3.14159/2;
               f0=0;
           }
           else
           {
               f0=3.14159/2;
               f1=0;
           }
           for (int i=0; i<15; i++)
           {
               double y=y1;
               f=(f0+f1)/2;
               for (int j=0; j<N; j++)
               {
                   y+=d_y(h/N, n[j], n[j+1], sin(f));
               }
               if (y==y2)
               {
                   break;
               }
               else
               {
                   if (y>y2)
                   {
                       f0=f;
                   }
                   else
                   {
                       f1=f;
                   }
               }
           }
       }
    }
    if (k==0)
    {
       cout<<f<<endl;
    }
    return 0;
}
