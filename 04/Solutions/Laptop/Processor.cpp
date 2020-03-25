#include "Processor.hpp"

#include <iostream>

Processor::Processor(const double& frequency, const unsigned& cores, const double& cashMemory)
    : frequency(frequency)
    , cores(cores)
    , cashMemory(cashMemory)
{
}

void Processor::printProcessorInformation() const
{
    std::cout << "Frequency: " << this->frequency << " GHz" << std::endl;
    std::cout << this->cores << " cores" << std::endl;
    std::cout << "Cash: " << this->cashMemory << std::endl;
}