#ifndef ID_H
#define ID_H
#include <iostream>
class id{
protected:
    int _id;
public:
    id(){
        _id = 0;

    }
    ~id(){

    }
    void updateid(){
        _id++;
    }
    int getid(){
        return _id;
    }


};
#endif // ID_H
