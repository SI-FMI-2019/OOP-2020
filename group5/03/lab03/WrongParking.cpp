#include "WrongParking.hpp"
#include <cstring>

WrongParking::WrongParking(const char* description, 
                           const char* registrationPlate, 
                           const double fine, 
                           const bool hasPreviousFines)
    : description(new char[(strlen(description)) + 1])
    , fine(fine)
    , hasWrongParkings(hasPreviousFines)
{
    strcpy(this->registrationPlate, registrationPlate);
    strcpy(this->description, description);
}