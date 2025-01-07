#include <iostream>
#include "vBus.h"
#include "vSystemRam.h"

int main() {
    vBus bus;
    vSystemRam ram(2048);
    bus.attachDevice(&ram, 0x0000, 0x2FFF);

    //bus.write(0x1000, 42);
    //std::cout << "Read[0x1000]: " << (int) bus.read(0x1000) << std::endl;


    bus.write(0, 42);
    std::cout << "Read[0]: " << (int) bus.read(0) << std::endl;
    bus.write(6143, 111);
    std::cout << "Read[2047]: " << (int) bus.read(2047) << std::endl;
    std::cout << "Read[4095]: " << (int) bus.read(4095) << std::endl;
    std::cout << "Read[6143]: " << (int) bus.read(6143) << std::endl;
    std::cout << "Read[8191)]: " << (int)bus.read(8191) << std::endl;

    return 0;
}
