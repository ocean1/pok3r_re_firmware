#ifndef POK3R_H
#define POK3R_H

#include "libusb-1.0/libusb.h"

#include "zstring.h"
#include "zbinary.h"
using namespace LibChaos;

#define HOLTEK_VID          0x04d9
#define VORTEX_POK3R_PID    0x0141

#define SEND_EP             0x04
#define RECV_EP             0x83

#define INTERFACE           1
#define TIMEOUT             1000

class Pok3r {
public:
    Pok3r();
    ~Pok3r();

    bool findPok3r();
    bool open();
    void close();

    zu32 read(zu32 addr, ZBinary &bin);
    zu32 write(zu32 addr, ZBinary bin);

    ZString getVersion();

private:
    libusb_context *context;
    libusb_device *device;
    libusb_device_handle *handle;
    int interface;
};

#endif // POK3R_H