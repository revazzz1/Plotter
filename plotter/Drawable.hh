#ifndef _DRAWABLE_HH_
#define _DRAWABLE_HH_

#include <string>
#include <vector>

struct Point{
    double x, y, yerr;
};

class Drawable {
protected:
    std::string _Name;
    std::vector<Point> _Data;
    std::string _FileName;
    static bool _ToBeOrNotToBe;
public:
    int GetN();
    Drawable(const char* name);
    void draw();
    void print();
    virtual ~Drawable();
};

#endif
