#ifndef _HISTO_HH_
#define _HISTO_HH_
#include "Drawable.hh"


class Histo : public Drawable {

protected:
double _Min;
double _Max;
int _Nbins;
double _Binw;
double _OverFlow;
double _UnderFlow;

public:
Histo(const char* name, int nbins, double min, double max);
void Fill(double x);
double GetMean();
double GetRMS();
double GetIntegral();
double Clean();
double GetOverFlow();
double GetUnderFlow();
};

#endif
