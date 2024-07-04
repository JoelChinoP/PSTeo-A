#ifndef COMPUTER_EXCEPTION_H
#define COMPUTER_EXCEPTION_H

#include <string>
using namespace std;

// Clase base para todas las excepciones del simulador
class ComputerException {
protected:
    string message; // Mensaje de error
public:
    ComputerException(const string& msg) : message(msg) {}
    virtual const string& getMessage() const {
        return message;
    }
};

#endif // COMPUTER_EXCEPTION_H
