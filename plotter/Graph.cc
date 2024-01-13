#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.hh"

Graph::Graph(const char* name): Drawable(name){};

Graph::Graph(const char* name, int sizeOfVector) : Drawable(name){
    _Data.resize(sizeOfVector);
}

void Graph::AddPoint(double x, double y, double yerr){
     Point p{x,y,yerr};
    _Data.push_back(p);
}

void Graph::SetPoint(int i, double x, double y, double yerr){
    if(i >= 0){
        if(i > _Data.size()){
            _Data.resize(i);
            AddPoint(x,y,yerr);
        }

        else{
            _Data[i].x = x;
            _Data[i].y = y;
            _Data[i].yerr = yerr;
        }

    }
}

void Graph::Sort(){
        std::sort(_Data.begin(), _Data.end(),
                  [](Point a, Point b) { return a.x < b.x; }
                  );
}
