#include<iostream>
#include "Message.h"
#include "MessageException.h"

using namespace std::string_literals;

Message::Message() {}

Message::Message(const std::string& text, User* sender, User* recipient) : _text(text), _sender(sender->getName()), _recipient(recipient->getName())
{
    time_t now = time(nullptr);
    struct tm ltm;
    localtime_s(&ltm, &now);
    std::string minutes = std::to_string(ltm.tm_min);
    std::string hours = std::to_string(ltm.tm_hour);
    std::string day = std::to_string(ltm.tm_mday);
    std::string month = std::to_string(1 + ltm.tm_mon);
    std::string year = std::to_string(1900 + ltm.tm_year);
    _sendinDateTime = setCorrectTime(hours) + ":"s + setCorrectTime(minutes) + " "s + setCorrectTime(day) + "/"s + setCorrectTime(month) + "/"s + year;
}

Message::Message(const std::string& UUID, const std::string& text, User* sender, User* recipient, const std::string& sendingDateTime) : _UUID(UUID), _text(text), _sender(sender->getName()), _recipient(recipient->getName()), _sendinDateTime(sendingDateTime) {}

Message::Message(const Message& other)
{
    _sender = other._sender;
    _recipient = other._recipient;
    _text = other._text;
}

Message& Message::operator = (const Message& other)
{
    if (this == &other)
        return *this;
    _sender = other._sender;
    _recipient = other._recipient;
    _text = other._text;
    return *this;
}

Message::~Message() {}

void Message::setText(const std::string& text)
{ 
    try
    {
        if (text == "")
            throw MessageException("Cannot send an empty message!"s);
        _text = text;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

const std::string& Message::getUUID() const { return _UUID; }

const std::string& Message::getText() const { return _text; }

const std::string& Message::getSender() const { return _sender; }

const std::string& Message::getRecipient() const { return _recipient; }

const std::string& Message::getSendinDateTime() const { return _sendinDateTime; }

const std::string& Message::setCorrectTime(std::string& str_time)
{
    if (std::stoi(str_time) < 10)
        str_time = "0"s + str_time;
    else
        str_time = str_time;
    return str_time;
}

std::ostream& operator << (std::ostream& os, const Message& m)
{
    return os << "Message from: "s << m._sender << "\nto: "s << m._recipient << "\nmessage text: "s << m._text << "\nposted at: "s << m._sendinDateTime;
}