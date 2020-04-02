#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>

enum MsgType
{
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

class Logger
{
public:
    Logger();
    Logger(const char*);
    ~Logger();

    template <typename T>
    void write(MsgType, const T*);

    void write(MsgType, const char*);

    template <typename T>
    void writeLine(MsgType, const T*);

    void writeLine(MsgType, const char*);
private:
    const char* filePath;
    std::ofstream file;

    const char* getCurrentTime() const;
    const char* getMsgType(MsgType) const;
    void initialize(const bool);
    void printCommon(MsgType);
};

const char* Logger::getCurrentTime() const
{
    std::time_t now = std::time(0);
    char* strTime = ctime(&now);
    if (strTime[strlen(strTime) - 1] == '\n')
    {
        strTime[strlen(strTime) - 1] = '\0';
    }
    return strTime;
}

const char* Logger::getMsgType(MsgType type) const
{
    switch (type)
    {
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    case DEBUG:
        return "DEBUG";
    default:
        return " ";
    }
}

void Logger::initialize(const bool flag)
{
    if (file.is_open())
    {
        if (flag)
        {
            file << "*** LOGG DEFAULT SESSION STARTED ";
        }
        else
        {
            file << "*** LOGG SESSION STARTED ";
        }

        file << this->getCurrentTime();
        file << "\t";
        file << " *** \n";
    }
}

void Logger::printCommon(MsgType type)
{
    file << this->getCurrentTime();
    file << "\t";
    file << this->getMsgType(type);
    file << "\t";
}

Logger::Logger()
    : filePath("default_log.txt")
    , file(filePath, std::ios::out | std::ios::app)
{
    initialize(true);
}

Logger::Logger(const char* filePath)
    : filePath(filePath)
    , file(filePath, std::ios::out | std::ios::app)
{
    initialize(false);
}

Logger::~Logger()
{
    if (file.is_open())
    {
        file << "--- LOGG SESSION ENDED AT ";
        file << this->getCurrentTime();
        file << "\t";
        file << " --- \n";
        file.close();
    }
}

template <typename T>
void Logger::write(MsgType type, const T* msg)
{
    if (file.is_open())
    {
        printCommon(type);
        file << *msg;
    }
}

void Logger::write(MsgType type, const char* msg)
{
    if (file.is_open())
    {
        printCommon(type);
        file << msg;
    }
}

template <typename T>
void Logger::writeLine(MsgType type, const T* msg)
{
    if (file.is_open())
    {
        printCommon(type);
        file << *msg;
        file << "\n";
    }
}

void Logger::writeLine(MsgType type, const char* msg)
{
    if (file.is_open())
    {
        printCommon(type);
        file << msg;
        file << "\n";
    }
}

#endif // LOGGER_HPP