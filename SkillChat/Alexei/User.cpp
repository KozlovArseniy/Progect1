#include"User.h"

User::User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name) {}

bool User::login(const std::string& login, const std::string& password)
{
	if (login == _login && password == _password)
	{
		_connectionToDB = true;
	}
	return _connectionToDB;
}

void User::sendMessage() {}

void User::showMessage() {}

void User::setLogin(const std::string& login) { _login = login; }

const std::string& User::getLogin() const { return _login; }

void User::setPassword(const std::string& password) { _password = password; }

const std::string& User::getPassword() const { return _password; }

void User::setName(const std::string& name) { _name = name; }

const std::string& User::getName() const { return _name; }