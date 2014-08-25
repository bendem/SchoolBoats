#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include "users/User.hpp"
#include "users/UserList.hpp"

using namespace std;

extern User* currentUser;
extern UserList userList;

void login();
char menu();
void result(string);
void wait();

#endif
