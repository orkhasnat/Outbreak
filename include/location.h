#ifndef LOCATION_H
#define LOCATION_H


class location
{
      public:
            int x,y;
            int  x1,y1;
            location();
            int movee(int vel);
            int infect_other(location other);

      protected:

      private:
};

#endif // LOCATION_H
