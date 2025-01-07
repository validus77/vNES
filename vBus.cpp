#include "vBus.h"

void vBus::attachDevice(MemoryMappedDevice *device, uint16_t startAddr, uint16_t endAddr) {
    devices_.push_back({device, startAddr, endAddr });
    device->attach(startAddr);
}

uint8_t vBus::read(uint16_t addr) {

    for(auto& mapping: devices_) {
        if( addr >= mapping.startAddr && addr <= mapping.endAddr) {
            return mapping.device->read(addr);
        }
    }
    return 0xFF;
}

void vBus::write(uint16_t addr, uint8_t data) {
    for(auto& mapping: devices_) {
        if( addr >= mapping.startAddr && addr <= mapping.endAddr) {
            mapping.device->write(addr, data);
            break;
        }
    }
    return;
}
