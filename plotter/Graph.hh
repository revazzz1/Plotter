#ifndef _GRAPH_HH_
#define _GRAPH_HH_
#include "Drawable.hh"


class Graph : public Drawable {

public:
Graph(const char* name);
Graph(const char* name, int sizeOfVector);
void AddPoint(double x, double y, double yerr = 0);
void SetPoint(int i, double x, double y, double yerr = 0);
void Sort();
};

#endif
