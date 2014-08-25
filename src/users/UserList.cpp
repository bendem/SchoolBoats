#include "users/UserList.hpp"

UserList::UserList(string filename) {
    this->users = new OrderedList<User*>();
    this->load(filename);
}

UserList::UserList(const UserList& orig) {
    this->users = new OrderedList<User*>(*orig.users);
}

UserList::~UserList() {
    for(int i = 0; this->users->size(); ++i) {
        delete this->users->remove(0);
    }
    delete this->users;
}

void UserList::add(User* u) {
    try {
        this->search(u->getLogin());
    } catch(UserNotFoundException e) {
        this->users->add(u);
        return;
    }
    throw DuplicatedUserException("Duplicated user login!");
}

void UserList::load(string filename) {
    ifstream is(filename, ios::in);
    this->load(is);
    is.close();
}

void UserList::load(istream& is) {
    while(is.peek() != EOF) {
        User u = User::load(is);
        this->users->add(new User(u));
    }

    if(this->users->isEmpty()) {
        this->users->add(new User("a", "a", Role::Admin));
    }
}

void UserList::save(string filename) const {
    ofstream userFile(filename, ios::out);
    this->save(userFile);
    userFile.close();
}

void UserList::save(ostream& os) const {
    for(int i = 0; i < this->users->size(); ++i) {
        this->users->get(i)->save(os);
    }
}

User* UserList::search(string login) const {
    User* u;
    for(int i = 0; i < this->users->size(); ++i) {
        u = this->users->get(i);
        if(u->getLogin() == login) {
            return u;
        }
    }
    throw UserNotFoundException("User not found");
}

void UserList::list() const {
    for(int i = 0; i < this->users->size(); ++i) {
        cout << *this->users->get(i) << endl;
    }
}
