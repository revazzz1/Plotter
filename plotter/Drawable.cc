#include <fstream>
#include <iostream>
#include "Drawable.hh"

using std::ofstream;

bool Drawable::_ToBeOrNotToBe = true;

Drawable::Drawable(const char* name){
 _Name = name;
}

int Drawable::GetN(){
    return _Data.size();
}
void Drawable::print(){
    for(int i = 0; i < _Data.size(); i++){

        std::cout <<"Point" << i + 1 <<": x is :" <<_Data[i].x;
        std::cout << "  y is :" <<_Data[i].y;
        std::cout << "  Yerr is :" <<_Data[i].yerr << std::endl;
    }
}

void Drawable::draw(){
     if(_FileName.size() == 0){
        _FileName = _Name;
        ofstream fout(_FileName);

    for(int j = 0; j < _Data.size(); j++){
        fout <<_Data[j].x << " " << _Data[j].y << " " << _Data[j].yerr << std::endl;
    }

    fout.close();

    std::string command = "kst2 " + _FileName + " -x 1 -y 2&";

    system(command.c_str());
    }
}

Drawable::~Drawable(){
    std::string tmp;
 if(_ToBeOrNotToBe == true) {
    std::getline(std::cin, tmp);
    _ToBeOrNotToBe = false;
 }
 if(_FileName.length() != 0){
    std::string command1 = "rm -f " + _FileName;
    std::string command = "pkill -f 'kst2 " + _FileName + "'";

    system(command1.c_str());
    system(command.c_str());
 }
}
