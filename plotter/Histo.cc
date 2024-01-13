#include <iostream>
#include <vector>
#include <math.h>
#include "Histo.hh"

Histo::Histo(const char* name, int nbins, double min, double max): Drawable(name) {
 _Nbins = nbins;
 _Min = min;
 _Max = max;
 _Binw = (_Max - _Min) / _Nbins;
 _Data.resize(nbins);
 for(int i = 0; i < _Nbins; i++){
    _Data[i].x = _Min + _Binw / 2 + _Binw*i;
    _Data[i].y = 0;
    _Data[i].yerr = 0;
}
}

double Histo::GetUnderFlow(){
  return _UnderFlow;
}


double Histo::GetOverFlow(){
  return _OverFlow;
}

double Histo::GetIntegral(){
    double integral;

    for(int i = 0; i < _Data.size(); i++){
        integral += _Data[i].y;
    }

    return integral;
}

void Histo::Fill(double x){
    int i = (x - _Min) / _Binw;

    if(x < _Min) {
    _UnderFlow += 1;
    }
    else if(x >= _Max){
    _OverFlow += 1;
    }
    else {
    _Data[i].y++;
    }

}

double Histo::GetMean(){
   double sum = 0, middle, frequency;

    for(int i = 0; i < _Data.size(); i++){
        middle = _Data[i].x;
        frequency = _Data[i].y;
        sum += middle * frequency;
    }

    return sum/GetIntegral();
}

double Histo::GetRMS(){
   double sum = 0, middle, frequency;

       for(int i = 0; i < _Data.size(); i++){
        middle = _Data[i].x * _Data[i].x;
        frequency = _Data[i].y;
        sum += middle * frequency;
    }

    double SquaredMean = sum / GetIntegral();

    double mean = GetMean();
    return sqrt(SquaredMean - mean * mean);
}
