#pragma once
#include<string>

class User
{
public:
    explicit User(const std::string& login, const std::string& password, const std::string& name);

    bool login(const std::string& login, const std::string& password);

    void sendMessage();

    void showMessage();

    void setLogin(const std::string& login);

    const std::string& getLogin() const;

    void setPassword(const std::string& password);

    const std::string& getPassword() const;

    void setName(const std::string& name);

    const std::string& getName() const;

private:
    bool _connectionToDB = false;
    std::string _login;
    std::string _password;
    std::string _name;
};
