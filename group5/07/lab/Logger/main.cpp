#include "Logger.hpp"

int main()
{
    Logger logger("someNewFile.log");
    logger.writeLine(INFO, "program got here");
    int a = 8;
    logger.writeLine(DEBUG, &a);
    return 0;
}