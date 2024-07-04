#ifndef OUTPUT_EXCEPTION_H
#define OUTPUT_EXCEPTION_H

#include "ComputerException.h"

// Clase para manejar excepciones de salida
class OutputException : public ComputerException {
public:
    OutputException(const string& msg) : ComputerException(msg) {}
};

#endif // OUTPUT_EXCEPTION_H
