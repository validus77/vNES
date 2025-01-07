#include "vSystemRam.h"

vSystemRam::vSystemRam(uint16_t size) : data_(size, 0), busStartAddr_(0), size_(size) {

}

uint8_t vSystemRam::read(uint16_t addr) {
    uint16_t absAddr = ((addr - busStartAddr_) & 0x07FF);
    return data_[absAddr];
}

void vSystemRam::write(uint16_t addr, uint8_t data) {
    uint16_t absAddr = ((addr - busStartAddr_)  & 0x07FF );
    data_[absAddr] = data;
}

void vSystemRam::attach(uint16_t startAddr) {
    busStartAddr_ = startAddr;

}
