#pragma once
#include "vBus.h"

class vSystemRam : public MemoryMappedDevice {
public:
    vSystemRam(uint16_t size);
    virtual uint8_t read(uint16_t addr);
    virtual void write(uint16_t addr, uint8_t data);
    virtual void attach(uint16_t startAddr);

private:
    std::vector<uint8_t> data_;
    uint16_t busStartAddr_;
    uint16_t size_;

};

