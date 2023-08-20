#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<ctime>
#include"User.h"

class Message
{
public:
    time_t now;

    Message();

    explicit Message(const std::string& text, User* sender, User* recipient);

    Message(const std::string& UUDI, const std::string& text, User* sender, User* recipient, const std::string& sendingDateTime);

    Message(const Message& other);

    Message& operator = (const Message& other);

    ~Message();
        
    const std::string& getUUID() const;

    void setText(const std::string& text);

    const std::string& getText() const;

    const std::string& getSender() const;

    const std::string& getRecipient() const;

    const std::string& getSendinDateTime() const;

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

private:
    std::string _UUID;
    std::string _text;
    std::string _sender;
    std::string _recipient;
    std::string _sendinDateTime;
};





