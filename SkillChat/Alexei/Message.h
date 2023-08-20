#pragma once
#include<string>
#include<time.h>
#include"User.h"

class Message
{
public:
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
    
    const std::string& setCorrectTime( std::string& str_time);

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

private:
    std::string _UUID;
    std::string _text;
    std::string _sender;
    std::string _recipient;
    std::string _sendinDateTime;
   
};


