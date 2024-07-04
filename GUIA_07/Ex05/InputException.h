#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include "ComputerException.h"

// Clase para manejar excepciones de entrada
class InputException : public ComputerException {
public:
    InputException(const string& msg) : ComputerException(msg) {}
};

#endif // INPUT_EXCEPTION_H
