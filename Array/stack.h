#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>
#include "array.h"

/*!
    \brief Класс Стэк
    \author Герасимов А.А.
    \version 1.0
    \date 01.03.2017
*/

using namespace std;

/*!
    Вспомогательный макрос, который сообщает что пошло не так в программе и закрывает её.
*/

#define assert_ok(str)   				\
        dump(str);						\
        assert(!"Object is OK");		\

template <class Type>
class Stack{
    public:
/*!
    Конструкторы класса Массив
*/
        Stack();
        Stack(size_t);
        Stack(Type *,size_t);
        Stack(Array<Type> &);

/*!
        Возвращает ёмкость стэка.
        \return Число,являющееся ёмкостью стэка.
*/
        size_t capacity() const;

/*!
        Возвращает текущий размер стэка.
        \return Число,являющееся текущим размером стэка.
*/
        size_t size() const;

/*!
        Возвращает текущий размер стэка.
        \return Если стэк пуст,то возвращает true. Если стэк содержит элементы, то false.
*/
        bool empty() const;

/*!
        Возвращает элемент, лежащий на верхушке стэка.
        \return Число,лежащее на верхушке стэка.
*/
        Type top() const;

/*!
        Добавляет элемент в стэк.
        \param Число, которое будет добавлено в стэк.
        \return Если число получилось добавить в стэк, то возвращает true. Если не получилось, то false.
*/
        bool push(const Type);

/*!
        Удаляет элемент, лежащий на верхушке стэка.
*/
        void pop();

/*!
        Выводит значение элемента стэка по переданному параметру.
        \param Номер необходимого элемента.
        \return Значение по данному номеру.
*/
        Type getelement(const size_t) const;

/*!
        Печатает стэк.
*/
        void print() const;

/*!
        Деструктор
*/
        virtual ~Stack();
    private:
        Type *stk;
        const size_t maxsize;
        size_t cursize;
        void dump(const string) const;
};

#endif // STACK_H
