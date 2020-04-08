#include "SmartDevice.h"
class SmartPhone : public SmartDevice {
   public:
   // No need for constructore/destructore/etc. as the default generated once are enough
    void setName(const char* newName);
    const char* getName();
};
