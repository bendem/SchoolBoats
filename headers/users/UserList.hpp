#ifndef USERLIST_HPP
#define USERLIST_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "collections/OrderedList.hpp"
#include "users/User.hpp"

using namespace std;

class UserList {

	private:
		OrderedList<User*>* users;

	public:
		UserList(string);
		UserList(const UserList&);
		~UserList();

		void load(string);
		void load(istream&);
		void save(string) const;
		void save(ostream&) const;
		User* search(string) const;

		void list() const;

};

#endif
