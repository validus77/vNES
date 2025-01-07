#pragma once


#include <cstdint>
#include <vector>

class MemoryMappedDevice {
public:
    virtual uint8_t read(uint16_t addr) = 0;
    virtual void write(uint16_t addr, uint8_t data) = 0;
    virtual void attach(uint16_t startAddr) = 0;
};

struct DeviceMapping {
    MemoryMappedDevice* device;
    uint16_t startAddr;
    uint16_t endAddr;
};

class vBus {
public:

    void attachDevice(MemoryMappedDevice* device, uint16_t startAddr, uint16_t endAddr);
    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);

private:
    std::vector<DeviceMapping> devices_;

};

