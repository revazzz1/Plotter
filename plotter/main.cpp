#include <iostream>
#include "Drawable.hh"
#include "Graph.hh"
#include "Histo.hh"

int main(int argc, char** argv){
Graph graph("one");
graph.AddPoint(1,2);
graph.AddPoint(3,4);

Graph graph1("two");
graph1.AddPoint(5,6);
graph1.AddPoint(2,1);
graph1.AddPoint(10,1);
graph1.AddPoint(7,1);
graph1.AddPoint(1,5);
graph1.AddPoint(11,52);

graph1.Sort();

graph.draw();
graph1.draw();

Histo histo("three",5, 1, 100);
histo.Fill(5.15);
histo.Fill(2.15);
histo.Fill(3.15);
histo.Fill(30.15);
histo.Fill(99.15);
histo.draw();

std::cout<< "size is: " << graph.GetN()  <<"Mean: " << histo.GetMean() << std::endl << histo.GetRMS() << std::endl;
return 0;
}
