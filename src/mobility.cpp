#define mobility_probability   100

#include "mobility.h"
#include <bits/stdc++.h>
using namespace std;

mobility::mobility()
{
      int du=rand()%100 +1;
      if(du<=mobility_probability)m=1;
      else m=0;
}
int mobility::mobilit(int mob_prob)
{
      int du=rand()%100 +1;
      if(du<=mob_prob)m=1;
      else m=0;
}

int mobility::quaren(int status)
{
      if(status==3){
            m=0;
            return 1;
      }
      else if(m==0){
            return 1;
      }

      else{
            m=1;
            return 0;
      }
}
