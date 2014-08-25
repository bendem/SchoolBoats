#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include "collections/List.hpp"

template<class T>
class OrderedList : public List<T> {

    protected:
        int _mode;

        bool shouldInsert(const T&, const T&);

    public:
        OrderedList();
        OrderedList(int);
        OrderedList(const OrderedList&);

        void add(T);

        void setMode(int);
        int getMode() const;

        static int ASCENDING;
        static int DESCENDING;
};

#endif
