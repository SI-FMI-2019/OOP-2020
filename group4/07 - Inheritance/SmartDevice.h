#pragma once

class SmartDevice {
   private:
    char* name = nullptr;

   public:
    SmartDevice(const char* name = "");
    ~SmartDevice();
    SmartDevice(const SmartDevice& rhs);
    SmartDevice& operator=(const SmartDevice& rhs);

    const char* getName() const;
    void setName(const char* newName);
};
