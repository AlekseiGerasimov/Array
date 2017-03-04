#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "array.h"
#include <assert.h>


typedef float typearray;

using namespace std;

class Tests{
public:
    Tests(Array obj)
        {
        Tests::obj = obj;
        Tests::tmpsize = obj.size();}
    int debug(){
        if(tmpsize<0 || !tmpsize){
            assert(!"The error with size. The base Class is uncorrect.");
            return -1;
        }
        obj.insert(100);
        if(obj.size() != tmpsize+1){
            assert(!"The error with method size.");
            return -1;
        }
        if(!obj.fill(10)){
            assert(!"The error with method fill.");
            return -1;
        }
        if(obj.last() != 10){
            assert(!"The error with method last.");
            return -1;
        }
        if(obj.first() != 10){
            assert(!"The error with method first.");
            return -1;
        }
        if(obj.at(tmpsize)!= 10){
            assert(!"The error with method at.");
            return -1;
        }
        obj.replaceItem(tmpsize,100);
        if(obj.last()!=100){
            assert(!"The error with method replaceItem.");
            return -1;
        }
        for(int i=0;i<obj.size();i++){
            obj.erase(i);
        }
        if(obj.size()==0){
            assert(!"The error with method erase.");
            return -1;
        }
        if(obj.empty()){
            assert(!"The error with method empty.");
            return -1;
        }
        obj.setsize(10);
        if(obj.size()!=10){
            assert(!"The error with method setsize.");
            return -1;
        }
        return 0;
    }
private:
    Array obj;
    int tmpsize;
};

#endif // TESTS_H
