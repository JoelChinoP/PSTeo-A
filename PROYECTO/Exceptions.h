#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FileException : public std::exception
{
private:
    std::string message;

public:
    explicit FileException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

#endif // EXCEPTIONS_H
