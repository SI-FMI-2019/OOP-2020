#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

class Processor
{
public:
    Processor() = default;
    Processor(const Processor&) = default;
    Processor& operator=(const Processor&) = default;
    ~Processor() = default;
    Processor(const double&, const unsigned&, const double&);

    void printProcessorInformation() const;
private:
    double frequency; // GHz
    unsigned cores;
    double cashMemory;
};

#endif // PROCESSOR_HPP