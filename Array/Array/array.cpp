#include "array.h"


Array::Array() : arr(NULL),n(0){
    cout << "Constructor of object "<< this << endl;
}

Array::Array(int n){
    cout << "Constructor of object "<< this << endl;
    if(n<0){
        assert_ok("Constructor error. The size of array cant be less 0");
    }
    this->n = n;
    this->arr = new typearray[n];
    if(!this->arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
    for(int i=0;i<n;i++)
        this->arr[i] = 1.0 / 0.0;
}

Array::Array(typearray *arr,int n){
     cout << "Constructor of object "<< this << endl;
    if(n<0){
        assert_ok("Constructor error. The size of array cant be less 0");
    }
    this->n = n;
    this->arr = new typearray[n];
    if(!this->arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
    for(int i=0;i<n;i++)
        this->arr[i] = arr[i];
}

Array::Array(const Array &rv){
    cout << "Create copy of object "<< &rv << " for " << this << endl;
    this->n = rv.n;
    this->arr = new typearray[rv.n];
    if(!this->arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
    for(int i=0;i<rv.n;i++)
        this->arr[i] = rv.arr[i];
}

/**********************************************************************************************************************/

int Array::size() const{
    cout << "Call method size() of object " << this << endl;
    return this->n;
}

bool Array::insert(typearray data){
    cout << "Call method insert() of object " << this << endl;
    typearray *tmp = new typearray[n++];
    if(!tmp){
        assert_ok("Memory error. Cant to create a new array.")
        return false;
    }
    for(int i=0;i<n-1;i++)
        tmp[i] = arr[i];
    tmp[n-1] = data;
    delete []arr;
    arr = tmp;
    return true;
}

typearray Array::erase(int position){
    cout << "Call method erase() of object " << this << endl;
    if(this->n == 0 && position == 0){
        assert_ok("Can't remove element from empty array.")
        typearray tmp = 1.0 / 0.0;
        return tmp;
    }
    if(position >= this->n){
        assert_ok("Can't remove element. Out of range.")
        typearray tmp = 1.0 / 0.0;
        return tmp;
    }
    typearray value;
    typearray *tmp = new typearray[--n];
    if(!tmp){
        assert_ok("Memory error. Cant to create a new array.")
        typearray tmp = 1.0 / 0.0;
        return tmp;
    }
    for(int i=0,j=0;i<n+1;){
        if(i==position){
            value = arr[i++];
            continue;
        }
        tmp[j++] = arr[i++];
    }
    delete []arr;
    arr = tmp;
    return value;
}

bool Array::empty() const{
    cout << "Call method empty() of object " << this << endl;
    if(this->n == 0) return true;
    return false;
}


void Array::print() const{
    cout << "Call method print() of object " << this << endl;
    for(int i=0;i<n;i++)
        cout << arr[i] << endl;
}

bool Array::fill(typearray data){
    cout << "Call method fill() of object " << this << endl;
    for(int i=0;i<this->n;i++)
        this->arr[i] = data;
    return true;
}

bool Array::replaceItem(int position,typearray data){
    cout << "Call method replaceItem() of object " << this << endl;
    if(position>=this->n || position < 0){
        assert_ok("Position error. The position cant be less 0 or more size of array.")
        return false;
    }
    this->arr[position] = data;
    return true;
}

bool Array::setsize(int data){
    cout << "Call method setsize() of object " << this << endl;
    if(data<0){
        assert_ok("Constructor error. The size of array cant be less 0.");
        return false;
    }
    if(data >= this->n){
    typearray *tmp = new typearray[data];
    if(!tmp){
        assert_ok("Memory error. Cant to create a new array.")
        return false;
    }
    for(int i=0;i<this->n;i++)
        tmp[i] = this->arr[i];
    for(int i=this->n;i<data;i++)
        tmp[i] = 1.0 / 0.0;
    delete []arr;
    arr = tmp;
    this->n = data;
    return true;
    }
    if(data < this->n){
    typearray *tmp = new typearray[data];
    if(!tmp){
        assert_ok("Memory error. Cant to create a new array.")
        return false;
    }
    for(int i=0;i<data;i++)
        tmp[i] = this->arr[i];
    delete []arr;
    arr = tmp;
    this->n = data;
    return true;
    }
}

void Array::dump(string str) const{
    cout << str << endl;
}

typearray & Array::first() const{
    cout << "Call method first() of object " << this << endl;
    if(this->n == 0){
    assert_ok("You cant get the first element, because this array has 0 elements.")
    typearray tmp = 1.0 / 0.0;
    return tmp;
    }
    return arr[0];
}

typearray & Array::last() const{
    cout << "Call method last() of object " << this << endl;
    if(this->n == 0){
    typearray tmp = 1.0 / 0.0;
    return tmp;
    }
    return arr[n-1];
}

typearray & Array::at(int position) const{
    cout << "Call method at() of object " << this << endl;
    if(position < 0 || position >= this->n){
    assert_ok("Out of range");
    typearray tmp = 1.0 / 0.0;
    return tmp;
    }
    return this->arr[position];
}

/**********************************************************************************************************************/

typearray & Array::operator[](int position){
    cout << "Call opertor[] of object " << this << endl;
    if(position>=this->n || position < 0) {
        assert_ok("Out of range");
        typearray tmp = 1.0 / 0.0;
        return tmp;
    }
    return this->arr[position];
}

const Array Array::operator+(const Array &rv) const{
    cout << "Call operator+, to object " << this << " add object " << &rv << endl;
    Array tmp(this->n + rv.n);
    for(int i=0;i<this->n;i++){
        cout << "Field " << &tmp.arr[i] << " add value field " << &this->arr[i] << endl;
        tmp.arr[i] = this->arr[i];
    }
    for(int i=0;i<rv.n;i++){
        cout << "Field " << &tmp.arr[i+this->n] << " add value field "  << &rv.arr[i]<< endl;
        tmp.arr[i+this->n] = rv.arr[i];
    }
    return tmp;
}

const Array & Array::operator=(const Array &rv){
    cout << "Call operator=, to object " << this << " assign object " << &rv << endl;
    delete []arr;
    this->n = rv.n;
    this->arr = new typearray[rv.n];
    for(int i=0;i<n;i++){
        cout << "Field " << &this->arr[i] << " assign value field " << &rv.arr[i] << endl;
        this->arr[i] = rv.arr[i];
    }
    return *this;
}

bool Array::operator==(const Array &rv) const{
    cout << "Call operator==, to object " << this << endl;
    if(this->n == rv.n){
        for(int i=0;i<this->n;i++){
            if(this->arr[i]==rv.arr[i])
                continue;
            return false;
        }
        return true;
    }
    return false;
}

bool Array::operator!=(const Array &rv) const{
    cout << "Call operator!=, to object " << this << endl;
    if(this->n == rv.n){
        for(int i=0;i<this->n;i++){
            if(this->arr[i]==rv.arr[i])
                continue;
            return true;
        }
        return false;
    }
    return true;
}

const Array Array::operator+(typearray data){
    cout << "Call operator+, to object " << this << endl;
    this->insert(data);
    return *this;
}

ostream& operator<<(ostream &lv,const Array &rv){
    cout << "Call operator<<" <<  endl;
    for(int i=0;i<rv.n;i++)
    cout << rv.arr[i] << " ";
    cout << endl;
    return lv;
}

/**********************************************************************************************************************/

Array::~Array(){
    cout << "Destroy of object " << this << endl;
    delete []arr;
}

/**********************************************************************************************************************/
