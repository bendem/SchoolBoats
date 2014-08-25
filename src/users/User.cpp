#include "users/User.hpp"

User::User(string login, string password, Role role) {
	this->login = login;
	this->password = password;
	this->role = role;
}
User::User(const User& orig) {
	this->login = orig.login;
	this->password = orig.password;
	this->role = orig.role;
}
User::~User() {}

Role User::getRole() const {
	return this->role;
}

string User::getLogin() const {
	return this->login;
}

bool User::checkPassword(string toCheck) const {
	return toCheck == this->password;
}

bool User::operator>(const User& u) const {
	return this->login > u.login;
}
bool User::operator<(const User& u) const {
	return this->login < u.login;
}
bool User::operator==(const User& u) const {
	return this->login == u.login;
}

const User& User::operator=(const User& u) {
	// TODO Find how in the world accessing u.password makes it crash
	this->login = u.login;
	this->password = u.password;
	this->role = u.role;
	return *this;
}

ostream& operator<<(ostream& os, const User& u) {
	return os << u.login << " (" << (u.role == Role::Admin ? "admin" : "manager") << ")";
}

void User::save(ostream& os) const {
	StreamUtils::write(os, this->login);
	StreamUtils::write(os, this->password);
	StreamUtils::write(os, (int) this->role);
}

User User::load(istream& is) {
	string login, password;
	Role role;

	login = StreamUtils::readString(is);
	password = StreamUtils::readString(is);
	role = static_cast<Role>(StreamUtils::readInt(is));

	return User(login, password, role);
}
