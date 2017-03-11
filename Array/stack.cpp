#include "stack.h"

/*******************************************************************************/

template <class Type>
Stack<Type>::Stack() : stk(new Type[10]),maxsize(10),cursize(0){
    if(!stk){
        assert_ok("Memory error. Cant reserve memory for new object.");
    }
    for(int i=0;i<maxsize;i++)
        stk[i] = 0;
}

template <class Type>
Stack<Type>::Stack(size_t size) : stk(new Type[size]),maxsize(size),cursize(0){
    if(!stk){
        assert_ok("Memory error. Cant reserve memory for new object.");
    }
    for(int i=0;i<maxsize;i++)
        stk[i] = 0;
}

template <class Type>
Stack<Type>::Stack(Type *stk,size_t size) : stk(new Type[size]),maxsize(size),cursize(size){
    if(!stk){
        assert_ok("Memory error. Cant reserve memory for new object.");
    }
    for(int i=0;i<maxsize;i++)
        this->stk[i] = stk[i];
}

template <class Type>
Stack<Type>::Stack(Array<Type> &obj) : stk(new Type[obj.size()]),maxsize(obj.size()),cursize(obj.size()){
    if(!stk){
        assert_ok("Memory error. Cant reserve memory for new object.");
    }
    for(int i=0;i<maxsize;i++)
        stk[i] = obj[i];
}

/*******************************************************************************/

template <class Type>
size_t Stack<Type>::capacity() const{
    return maxsize;
}

template <class Type>
size_t Stack<Type>::size() const{
    return cursize;
}

template <class Type>
bool Stack<Type>::empty() const{
    if(cursize==0) return true;
    return false;
}

template <class Type>
bool Stack<Type>::push(const Type data){
    if(cursize == maxsize){
        assert_ok("The stack is full");
        return false;
    }
    stk[cursize++] = data;
    return true;
}

template <class Type>
Type Stack<Type>::top() const{
    if(cursize==0) return 1.0/0.0;
    return stk[cursize-1];
}

template <class Type>
void Stack<Type>::pop(){
    if(cursize == 0){
        assert_ok("The stack is empty");
    }
    stk[--cursize] = 1.0/0.0;
}

template <class Type>
Type Stack<Type>::getelement(const size_t number) const{
    if(number>=maxsize) assert(!"You can't get this element. A number of element isn't valid.Check the maxsize of stack.");
    return stk[number];
}

template <class Type>
void Stack<Type>::print() const{
    cout << "maxsize: " << maxsize << endl;
    cout << "cursize: " << cursize << endl;
    for(int i=maxsize-1;i>=0;--i)
        cout << "stk[" << i << "]=" << stk[i] << endl;
}

/*******************************************************************************/

template <class Type>
void Stack<Type>::dump(const string str) const{
    cout << str << endl;
}


/*******************************************************************************/

template <class Type>
Stack<Type>::~Stack(){
    delete []stk;
}

/*******************************************************************************/

template class Stack<double>;
template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
