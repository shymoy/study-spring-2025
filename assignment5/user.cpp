#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string &name)
    : _name(name)
      , _friends(nullptr)
      , _size(0)
      , _capacity(0) {
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string &name) {
    if (_size == _capacity) {
        _capacity = 2 * _capacity + 1;
        std::string *newFriends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newFriends[i] = _friends[i];
        }
        delete[] _friends;
        _friends = newFriends;
    }

    _friends[_size++] = name;
}

User &User::operator+=(User &rhs) {
    add_friend(rhs._name);
    rhs.add_friend(this->_name);
    return *this;
}

bool User::operator<(const User &user) const {
    return this->_name < user._name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const {
    return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const {
    return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string &name) {
    _friends[index] = name;
}

/**
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
User::~User() {
    delete[] this->_friends;
};

User::User(const User &other) {
    this->_size = other.size();
    this->_capacity = other._capacity;
    this->_name = other._name;
    this->_friends = new std::string[this->_capacity];
    for (int i = 0; i < this->_size; i++) {
        this->_friends[i] = other._friends[i];
    }
}

User &User::operator=(const User &other) {
    std::string *new_friends = new std::string[other._capacity];
    for (int i = 0; i < other.size(); i++) {
        new_friends[i] = other._friends[i];
    }
    delete[] this->_friends;
    this->_friends = new_friends;
    this->_size = other.size();
    this->_capacity = other._capacity;
    this->_name = other._name;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "User(" << "name=" << user.get_name() << ", " << "friends=[";
    for (size_t i = 0; i < user.size(); i++) {
        os << user._friends[i];
        if (i != user.size() - 1) {
            os << ", ";
        }
    }
    os << "])";
    return os;
}
