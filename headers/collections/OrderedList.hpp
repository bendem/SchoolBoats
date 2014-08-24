#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include "collections/List.hpp"

template<class T>
class OrderedList : public List<T> {

	protected:
		int _mode;

	public:

        void add(const T&);

		void setMode(int);
		int getMode() const;

		static int ASCENDING;
		static int DESCENDING;
};

#endif
