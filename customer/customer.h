#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../logic_classes.h"
#include <variant>

using DevicesType = std::variant<CPU*,
 GPU*,
 Memory*,
 HDD*,
 SSD*,
 Motherboard*,
 PSU*,
 PCCase*,
 CoolingUnit*,
 Handheld*,
 Stationed*,
 Laptop*,
 Desktop*,
 Earbuds*,
 Earphones*,
 Headphones*,
 Headset*,
 Microphone*,
 Speakers*,
 Display*,
 Keyboard*,
 Mouse*,
 Portable_HDD*,
 Printer*,
 SdCard*,
 Touchpad*,
 UsbDrive*,
 Webcam*,
 Wire*,
 Smartphones*,
 Smartwatch*,
 Tablet*,
 VR*>;

class Customer
{
public:
    static std::vector<std::tuple<DevicesType, int>> cart;
    double calculateTotal();
    void addToCart(const std::string id, const unsigned int);
    void removeFromCart(const unsigned int, const unsigned int);
    void viewCart();
    void checkout();
    void viewSpecs(const std::string id);

    static void updateCart();
    void loadCart();
};
#endif