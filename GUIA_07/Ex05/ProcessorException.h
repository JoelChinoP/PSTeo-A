#ifndef PROCESSOR_EXCEPTION_H
#define PROCESSOR_EXCEPTION_H

#include "ComputerException.h"

// Clase para manejar excepciones de procesamiento
class ProcessorException : public ComputerException {
public:
    ProcessorException(const string& msg) : ComputerException(msg) {}
};

#endif // PROCESSOR_EXCEPTION_H
