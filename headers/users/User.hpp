#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "utils/StreamUtils.hpp"

enum Role {
	Admin, ClubManager
};

class User {

	private:
		Role role;
		string login;
		string password;

	public:
		User(string, string, Role);
		User(const User&);
		~User();

		Role getRole() const;
		string getLogin() const;
		bool checkPassword(string) const;
		void setPassword(string);

		bool operator>(const User&) const;
		bool operator<(const User&) const;
		bool operator==(const User&) const;
		const User& operator=(const User&);
		friend ostream& operator<<(ostream&, const User&);

		// Serialization
		void save(ostream&) const;
		static User load(istream&);

};

#endif
