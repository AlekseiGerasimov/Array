#include "array.h"
#include <cstring>


template <class Type>
Array<Type>::Array() : arr(NULL),capacity(0){
    cout << "Constructor of object "<< this << endl;
}

template <class Type>
Array<Type>::Array(size_t capacity) : arr(new Type[capacity]),capacity(capacity){
    cout << "Constructor of object "<< this << endl;
    if(!arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
    for(int i=0;i<capacity;i++)
        this->arr[i] = 0;
}

template <class Type>
Array<Type>::Array(Type *arr,size_t capacity) : arr(new Type[capacity]),capacity(capacity){
    cout << "Constructor of object "<< this << endl;
    if(!arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
//  for(int i=0;i<capacity;i++)
//      this->arr[i] = arr[i];
    copy(arr,arr+capacity,this->arr);
}

template <class Type>
Array<Type>::Array(const Array &rv) : arr(new Type[rv.capacity]),capacity(rv.capacity){
    cout << "Create copy of object "<< &rv << " for " << this << endl;
    if(!arr){
        assert_ok("Memory error. Cant to create a new array.")
    }
//  for(int i=0;i<rv.capacity;i++)
//      this->arr[i] = rv.arr[i];
    copy(rv.arr,rv.arr + rv.capacity,arr);
}

/**********************************************************************************************************************/

template <class Type>
int Array<Type>::size() const{
    cout << "Call method size() of object " << this << endl;
    return capacity;
}

template <class Type>
bool Array<Type>::insert(const Type data){
    Type *tmp = new Type[++capacity];
    if(!tmp){
        assert_ok("memory error");
        return false;
    }
    for(int i=0;i<capacity-1;i++)
          tmp[i] = arr[i];
    tmp[capacity-1] = data;
    delete []arr;
    swap(arr,tmp);
    return true;
}

template <class Type>
Type Array<Type>::erase(const int position){
    cout << "Call method erase() of object " << this << endl;
    if(position >= capacity || position < 0){
        assert_ok("Can't remove element. Out of range.")
        Type tmp = 1.0 / 0.0;
        return tmp;
    }
    Type value = arr[position];
    arr[position] = 1.0 / 0.0;
    return value;
}

template <class Type>
bool Array<Type>::empty() const{
    cout << "Call method empty() of object " << this << endl;
    if(capacity == 0) return true;
    return false;
}

template <class Type>
void Array<Type>::print() const{
    cout << "Call method print() of object " << this << endl;
    if(capacity == 0){
        cout << "Capacity = 0. Array hasn't any members." << endl;
        return;
    }
    for(int i=0;i<capacity;i++)
        cout << arr[i] << endl;
}

template <class Type>
bool Array<Type>::fill(const Type data){
    if(capacity==0){
        assert_ok("Fill error. The Array is empty,cant fill it")
        return false;
    }
    cout << "Call method fill() of object " << this << endl;
    for(int i=0;i<capacity;i++)
        this->arr[i] = data;
    return true;
}

template <class Type>
bool Array<Type>::replaceItem(const int position,const Type data){
    cout << "Call method replaceItem() of object " << this << endl;
    if(position>=capacity || position<0){
        assert_ok("Position error.")
        return false;
    }
    arr[position] = data;
    return true;
}

template <class Type>
bool Array<Type>::setcapacity(const int data){
    cout << "Call method setcapacity() of object " << this << endl;
    if(data<0){
        assert_ok("Constructor error. The size of array cant be less 0.");
        return false;
    }
    if(capacity == data){
        return true;
    }
    Type *tmp = new Type[data];
    if(!tmp){
        assert_ok("Memory error. Cant to create a new array.")
        return false;
    }
    if(data > capacity){
        for(int i=0;i<capacity;i++)
            tmp[i] = arr[i];
        for(int i=capacity;i<data;i++)
            tmp[i] = 0;
        delete []arr;
        arr = tmp;
        capacity = data;
        return true;
    }
    if(data < capacity){
        for(int i=0;i<data;i++)
            tmp[i] = arr[i];
        delete []arr;
        arr = tmp;
        capacity = data;
        return true;
    }
}

template <class Type>
void Array<Type>::dump(const string str) const{
    cout << str << endl;
}

template <class Type>
Type & Array<Type>::first() const{
    cout << "Call method first() of object " << this << endl;
    if(capacity == 0){
    assert_ok("You cant get the first element, because this array has 0 elements.")
    Type tmp = 1.0 / 0.0;
    return tmp;
    }
    return arr[0];
}

template <class Type>
Type & Array<Type>::last() const{
    cout << "Call method last() of object " << this << endl;
    if(capacity == 0){
        assert_ok("Cant return the reference to last element. The capacity of array is 0");
        Type tmp = 1.0 / 0.0;
        return tmp;
    }
    return arr[capacity-1];
}

template <class Type>
Type & Array<Type>::at(const int position) const{
    cout << "Call method at() of object " << this << endl;
    if(position >= capacity || position < 0){
        assert_ok("Out of range");
        Type tmp = 1.0 / 0.0;
        return tmp;
    }
    return this->arr[position];
}

template <class Type>
void Array<Type>::swaps(Array &rv){
    swap(arr,rv.arr);
    swap(capacity,rv.capacity);
}

/**********************************************************************************************************************/

template <class Type>
Type & Array<Type>::operator[](const int position){
    cout << "Call opertor[] of object " << this << endl;
    if(position>=capacity || position<0) {
        assert_ok("Out of range");
        Type tmp = 1.0 / 0.0;
        return tmp;
    }
    return this->arr[position];
}

template <class Type>
const Array<Type> Array<Type>::operator+(const Array &rv) const{
    cout << "Call operator+, to object " << this << " add object " << &rv << endl;
    Array tmp(capacity + rv.capacity);
    for(int i=0;i<capacity;i++){
        cout << "Field " << &tmp.arr[i] << " add value field " << &arr[i] << endl;
        tmp.arr[i] = arr[i];
    }
    for(int i=0;i<rv.capacity;i++){
        cout << "Field " << &tmp.arr[i+capacity] << " add value field "  << &rv.arr[i]<< endl;
        tmp.arr[i+capacity] = rv.arr[i];
    }
    return tmp;
}

template <class Type>
const Array<Type> & Array<Type>::operator=(const Array &rv){
    if(&rv == this) return *this;
//    Array tmp(rv);
//    swaps(tmp);
    new(this)Array(rv);
    return *this;
}

template <class Type>
bool Array<Type>::operator==(const Array &rv) const{
    cout << "Call operator==, to object " << this << endl;
    if(capacity == rv.capacity){
        for(int i=0;i<capacity;i++){
            if(arr[i]==rv.arr[i])
                continue;
            return false;
        }
        return true;
    }
    return false;
}

template <class Type>
bool Array<Type>::operator!=(const Array<Type> &rv) const{
    cout << "Call operator!=, to object " << this << endl;
    if(capacity == rv.capacity){
        for(int i=0;i<capacity;i++){
            if(arr[i]==rv.arr[i])
                continue;
            return true;
        }
        return false;
    }
    return true;
}

template <class Type>
const Array<Type> Array<Type>::operator+(const Type data){
    cout << "Call operator+, to object " << this << endl;
    Array tmp(capacity+1);
    for(int i=0;i<capacity;i++)
          tmp.arr[i] = arr[i];
    tmp.arr[capacity] = data;
    tmp.capacity = capacity + 1;
    return tmp;
}

//template <class Type>
//ostream& operator<<(ostream &lv,const Array<Type> &rv){
//    cout << "Call operator<<" <<  endl;
//    for(int i=0;i<rv.capacity;i++)
//    cout << rv.arr[i] << " ";
//    cout << endl;
//    return lv;
//}


template <class Type>
void * Array<Type>::operator new(const size_t size){
    void *p = malloc(size);
    printf("Allocate a memory in size %d\n",size);
    return p;
}

template <class Type>
void * Array<Type>::operator new[](const size_t size){
    void *p = malloc(size);
    printf("Allocate a memory rwqrqr in size %d\n",size);
    return p;
}

template <class Type>
void * Array<Type>::operator new[](const size_t size,const int n){
    void *p = malloc(size);
    memset(p,0,size);
    printf("Allocate trololo a memory in size %d\n",size);
    return p;
}

template <class Type>
void * Array<Type>::operator new(const size_t size,void *where){
    printf("Allocate trololoshen'ka a memory in size %d\n",size);
    return where;
}

/**********************************************************************************************************************/

template <class Type>
Array<Type>::iterator::iterator() : it(0){

}

template <class Type>
Array<Type>::iterator::iterator(Type *it) : it(it){

}

template <class Type>
Array<Type>::iterator::iterator(Type &obj){
    it = &obj;
}

template <class Type>
Type & Array<Type>::iterator::operator++(){
    it++;
    return *it;
}

template <class Type>
Type Array<Type>::iterator::operator*(){
    return *it;
}

template <class Type>
bool Array<Type>::iterator::operator !=(Type &obj){
    Type *tmp = &obj;
    tmp++;
    if(it == tmp) return false;
    return true;
}

template <class Type>
Array<Type>::iterator::~iterator(){
    delete it;
}

template <class Type>
Type & Array<Type>::iterator::next(){
    ++it;
    return *it;
}


/**********************************************************************************************************************/

template <class Type>
Array<Type>::~Array(){
    cout << "Destroy of object " << this << endl;
    delete []arr;
}

/**********************************************************************************************************************/

template class Array<double>;
template class Array<int>;
template class Array<float>;
template class Array<char>;
