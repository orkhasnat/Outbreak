#define hospfull_fatality_rate  15
#define not_hospfull_fatality_rate  5
#define Healthy    0
#define Infected   1
#define Recovered  2
#define Dead       3

#include<bits/stdc++.h>
#include "person.h"
using namespace std;

person::person()
{
      status=Healthy;
      recovery_time=15;
      vel=rand()%8 +2;
}
int person::alive_dead(int I,int n)
{
      int ru;
      ru=rand()%100 +1;
      if(n/5<=I){
            if(ru<=not_hospfull_fatality_rate)status = Dead;
            else status = Recovered;
      }
      else{
            if(ru<=hospfull_fatality_rate)status = Dead;
            else status = Recovered;
      }
}
