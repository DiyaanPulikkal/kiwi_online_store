#ifndef LIB_H
#define LIB_H

#include "../logic_classes.h"
#include "../dev/dev.h"
#include "../customer/customer.h"

int main();
void developer_mode();  
void customer_mode();
bool signed_in = false;

// Static variables
std::vector<HDD> HDD::hdd_vec;
std::vector<SSD> SSD::ssd_vec;
std::vector<CoolingUnit> CoolingUnit::cooling_unit_vec;
std::vector<CPU> CPU::cpu_vec;
std::vector<GPU> GPU::gpu_vec;
std::vector<Memory> Memory::memory_vec;
std::vector<Motherboard> Motherboard::motherboard_vec;
std::vector<PCCase> PCCase::pc_case_vec;
std::vector<PSU> PSU::psu_vec;
std::vector<Handheld> Handheld::handheld_vec;
std::vector<Stationed> Stationed::stationed_vec;
std::vector<Desktop> Desktop::desktop_vec;
std::vector<Laptop> Laptop::laptop_vec;
std::vector<Earbuds> Earbuds::earbuds_vec;
std::vector<Earphones> Earphones::earphones_vec;
std::vector<Headphones> Headphones::headphones_vec;
std::vector<Headset> Headset::headset_vec;
std::vector<Microphone> Microphone::microphone_vec;
std::vector<Speakers> Speakers::speakers_vec;
std::vector<Display> Display::display_vec;
std::vector<Keyboard> Keyboard::keyboard_vec;
std::vector<Mouse> Mouse::mouse_vec;
std::vector<Portable_HDD> Portable_HDD::portable_hdd_vec;
std::vector<Printer> Printer::printer_vec;
std::vector<SdCard> SdCard::sd_card_vec;
std::vector<Touchpad> Touchpad::touchpad_vec;
std::vector<UsbDrive> UsbDrive::usb_drive_vec;
std::vector<Webcam> Webcam::webcam_vec;
std::vector<Wire> Wire::wire_vec;
std::vector<Smartphones> Smartphones::smartphones_vec;
std::vector<Smartwatch> Smartwatch::smartwatch_vec;
std::vector<Tablet> Tablet::tablet_vec;
std::vector<VR> VR::vr_vec;

double Devices::total_sales;
std::vector<std::tuple<DevicesType, int>> Customer::cart;
// --------------------------------------------

void readAllData() {
    HDD::readData();
    SSD::readData();
    CoolingUnit::readData();
    CPU::readData();
    GPU::readData();
    Memory::readData();
    Motherboard::readData();
    PCCase::readData();
    PSU::readData();
    Handheld::readData();
    Stationed::readData();
    Desktop::readData();
    Laptop::readData();
    Earbuds::readData();
    Earphones::readData();
    Headphones::readData();
    Headset::readData();
    Microphone::readData();
    Speakers::readData();
    Display::readData();
    Keyboard::readData();
    Mouse::readData();
    Portable_HDD::readData();
    Printer::readData();
    SdCard::readData();
    Touchpad::readData();
    UsbDrive::readData();
    Webcam::readData();
    Wire::readData();
    Smartphones::readData();
    Smartwatch::readData();
    Tablet::readData();
    VR::readData();
}

const std::vector<std::string> categories = {
    "Computer Parts",
    "Console",
    "Desktop",
    "Laptop",
    "Peripherals",
    "Smartphone",
    "Smartwatch",
    "Tablet",
    "VR"
};

const std::vector<std::string> comp_parts_cat = {
    "CPU",
    "GPU",
    "RAM",
    "Motherboard",
    "HDD",
    "SSD",
    "PSU",
    "Case",
    "Cooling",
};

const std::vector<std::string> console_cat = {
    "Handheld",
    "Stationed"
};

const std::vector<std::string> peripherals_cat = {
    "Earbuds",
    "Earphones",
    "Headphones",
    "Headset",
    "Microphone",
    "Speakers",
    "Display",
    "Keyboard",
    "Mouse",
    "Portable HDD",
    "Printer",
    "SD Card",
    "Touchpad",
    "USB Drive",
    "Webcam",
    "Wire"
};

int chooseDevicesCat(){
    std::string cat_str;
    unsigned int cat;
    std::cout << "Choose a category: " << std::endl;
    for (int i = 0; i < categories.size(); i++){
        std::cout << i + 1 << ". " << categories[i] << std::endl;
    }
    std::cout << "0. Go back" << std::endl;
    std::cout << "Category number: ";
    std::getline(std::cin, cat_str);
    while (true){
        try{
            cat = std::stoi(cat_str);
            if (cat > categories.size() || cat < 0){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number from 0 to " << categories.size() << ": " << std::endl;
            std::getline(std::cin, cat_str);
        }
    }
    return cat;
}

int chooseCompPartsCat(){
    std::string cat_str;
    unsigned int cat;
    std::cout << "Choose a category: " << std::endl;
    for (int i = 0; i < comp_parts_cat.size(); i++){
        std::cout << i + 1 << ". " << comp_parts_cat[i] << std::endl;
    }
    std::cout << "0. Go back" << std::endl;
    std::cout << "Category number: ";
    std::getline(std::cin, cat_str);
    while (true){
        try{
            cat = std::stoi(cat_str);
            if (cat > comp_parts_cat.size() || cat < 0){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number from 0 to " << comp_parts_cat.size() << ": " << std::endl;
            std::getline(std::cin, cat_str);
        }
    }
    return cat;
}

int chooseConsoleCat(){
    std::string cat_str;
    unsigned int cat;
    std::cout << "Choose a category: " << std::endl;
    for (int i = 0; i < console_cat.size(); i++){
        std::cout << i + 1 << ". " << console_cat[i] << std::endl;
    }
    std::cout << "0. Go back" << std::endl;
    std::cout << "Category number: ";
    std::getline(std::cin, cat_str);
    while (true){
        try{
            cat = std::stoi(cat_str);
            if (cat > console_cat.size() || cat < 0){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number from 0 to " << console_cat.size() << ": " << std::endl;
            std::getline(std::cin, cat_str);
        }
    }
    return cat;
}

int choosePeripheralsCat(){
    std::string cat_str;
    unsigned int cat;
    std::cout << "Choose a category: " << std::endl;
    for (int i = 0; i < peripherals_cat.size(); i++){
        std::cout << i + 1 << ". " << peripherals_cat[i] << std::endl;
    }
    std::cout << "0. Go back" << std::endl;
    std::cout << "Category number: ";
    std::getline(std::cin, cat_str);
    while (true){
        try{
            cat = std::stoi(cat_str);
            if (cat > peripherals_cat.size() || cat < 0){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number from 0 to " << peripherals_cat.size() << ": " << std::endl;
            std::getline(std::cin, cat_str);
        }
    }
    return cat;
}

void listDevices(const int cat, const int final_cat){
    if (cat == 1){
        if (final_cat == 1){
            for (const CPU& cpu : CPU::cpu_vec){
                std::cout << cpu << std::endl;
            }
        }else if (final_cat == 2){
            for (const GPU& gpu : GPU::gpu_vec){
                std::cout << gpu << std::endl;
            }
        }else if (final_cat == 3){
            for (const Memory& memory : Memory::memory_vec){
                std::cout << memory << std::endl;
            }
        }else if (final_cat == 4){
            for (const Motherboard& motherboard : Motherboard::motherboard_vec){
                std::cout << motherboard << std::endl;
            }
        }else if (final_cat == 5){
            for (const HDD& hdd : HDD::hdd_vec){
                std::cout << hdd << std::endl;
            }
        }else if (final_cat == 6){
            for (const SSD& ssd : SSD::ssd_vec){
                std::cout << ssd << std::endl;
            }
        }else if (final_cat == 7){
            for (const PSU& psu : PSU::psu_vec){
                std::cout << psu << std::endl;
            }
        }else if (final_cat == 8){
            for (const PCCase& pc_case : PCCase::pc_case_vec){
                std::cout << pc_case << std::endl;
            }
        }else if (final_cat == 9){
            for (const CoolingUnit& cooling_unit : CoolingUnit::cooling_unit_vec){
                std::cout << cooling_unit << std::endl;
            }
        } else if (final_cat == 0){
            if (signed_in){
                developer_mode();
            } else {
                customer_mode();
            }
        }
    } else if (cat == 2){
        if (final_cat == 1){
            for (const Handheld& handheld : Handheld::handheld_vec){
                std::cout << handheld << std::endl;
            }
        } else if (final_cat == 2){
            for (const Stationed& stationed : Stationed::stationed_vec){
                std::cout << stationed << std::endl;
            }
        } else if (final_cat == 0){
            if (signed_in){
                developer_mode();
            } else {
                customer_mode();
            }
        }
    } else if (cat == 3){
        for (const Desktop& desktop : Desktop::desktop_vec){
            std::cout << desktop << std::endl;
        }
    } else if (cat == 4){
        for (const Laptop& laptop : Laptop::laptop_vec){
            std::cout << laptop << std::endl;
        }
    } else if (cat == 5){
        if (final_cat == 1){
            for (const Earbuds& earbuds : Earbuds::earbuds_vec){
                std::cout << earbuds << std::endl;
            }
        } else if (final_cat == 2){
            for (const Earphones& earphones : Earphones::earphones_vec){
                std::cout << earphones << std::endl;
            }
        } else if (final_cat == 3){
            for (const Headphones& headphones : Headphones::headphones_vec){
                std::cout << headphones << std::endl;
            }
        } else if (final_cat == 4){
            for (const Headset& headset : Headset::headset_vec){
                std::cout << headset << std::endl;
            }
        } else if (final_cat == 5){
            for (const Microphone& microphone : Microphone::microphone_vec){
                std::cout << microphone << std::endl;
            }
        } else if (final_cat == 6){
            for (const Speakers& speakers : Speakers::speakers_vec){
                std::cout << speakers << std::endl;
            }
        } else if (final_cat == 7){
            for (const Display& display : Display::display_vec){
                std::cout << display << std::endl;
            }
        } else if (final_cat == 8){
            for (const Keyboard& keyboard : Keyboard::keyboard_vec){
                std::cout << keyboard << std::endl;
            }
        } else if (final_cat == 9){
            for (const Mouse& mouse : Mouse::mouse_vec){
                std::cout << mouse << std::endl;
            }
        } else if (final_cat == 10){
            for (const Portable_HDD& portable_hdd : Portable_HDD::portable_hdd_vec){
                std::cout << portable_hdd << std::endl;
            }
        } else if (final_cat == 11){
            for (const Printer& printer : Printer::printer_vec){
                std::cout << printer << std::endl;
            }
        } else if (final_cat == 12){
            for (const SdCard& sd_card : SdCard::sd_card_vec){
                std::cout << sd_card << std::endl;
            }
        } else if (final_cat == 13){
            for (const Touchpad& touchpad : Touchpad::touchpad_vec){
                std::cout << touchpad << std::endl;
            }
        } else if (final_cat == 14){
            for (const UsbDrive& usb_drive : UsbDrive::usb_drive_vec){
                std::cout << usb_drive << std::endl;
            }
        } else if (final_cat == 15){
            for (const Webcam& webcam : Webcam::webcam_vec){
                std::cout << webcam << std::endl;
            }
        } else if (final_cat == 16){
            for (const Wire& wire : Wire::wire_vec){
                std::cout << wire << std::endl;
            }
        } else if (final_cat == 0){
            if (signed_in){
                developer_mode();
            } else {
                customer_mode();
            }
        }
    } else if (cat == 6){
        for (const Smartphones& smartphone : Smartphones::smartphones_vec){
            std::cout << smartphone << std::endl;
        }
    } else if (cat == 7){
        for (const Smartwatch& smartwatch : Smartwatch::smartwatch_vec){
            std::cout << smartwatch << std::endl;
        }
    } else if (cat == 8){
        for (const Tablet& tablet : Tablet::tablet_vec){
            std::cout << tablet << std::endl;
        }
    } else if (cat == 9){
        for (const VR& vr : VR::vr_vec){
            std::cout << vr << std::endl;
        }
    } else if (cat == 0){
        if (signed_in){
            developer_mode();
        } else {
            customer_mode();
        }
    }
}
void loadTotalSales();

void developer_mode(){
    Dev dev;
    loadTotalSales();
    // Login
    if (!signed_in){
        std::string username;
        std::string password;
        bool first_attempt = true;
        while (!dev.verify(username, password)){
            if (!first_attempt){
                std::string retry;
                std::cout << "Invalid username or password. Retry? (y/n): ";
                std::getline(std::cin, retry);
                if (retry != "y"){
                    main();
                }
            }
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);
        }
        signed_in = true;
    }
    // Developer options
    while (true){
        unsigned int option;
        {
            std::string option_str;
            std::cout << "Welcome!" << std::endl;
            std::cout << "Options: " << std::endl;
            std::cout << "1. Add device" << std::endl;
            std::cout << "2. Remove device" << std::endl;
            std::cout << "3. List Devices" << std::endl;
            std::cout << "4. View sales" << std::endl;
            std::cout << "5. Put a product on display" << std::endl;
            std::cout << "6. Remove a product from display" << std::endl;
            std::cout << "7. Sign out" << std::endl;
            std::cout << "8. Exit" << std::endl;
            std::cout << "Option number: ";
            std::getline(std::cin, option_str);
            while (true){
                try{
                    option = std::stoi(option_str);
                    if (option > 8 || option < 1){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter a number from 1 to 8: " << std::endl;
                    std::getline(std::cin, option_str);
                }
            }
        }

        if (option == 1){
            int cat = chooseDevicesCat();
            int final_cat = 0;
            if (cat == 1){
                final_cat = chooseCompPartsCat();
            } else if (cat == 2){
                final_cat = chooseConsoleCat();
            } else if (cat == 5){
                final_cat = choosePeripheralsCat();
            }
            if (cat == 1){
                if (final_cat == 1){
                    dev.addCPU();
                } else if (final_cat == 2){
                    dev.addGPU();
                } else if (final_cat == 3){
                    dev.addMemory();
                } else if (final_cat == 4){
                    dev.addMotherboard();
                } else if (final_cat == 5){
                    dev.addHDD();
                } else if (final_cat == 6){
                    dev.addSSD();
                } else if (final_cat == 7){
                    dev.addPSU();
                } else if (final_cat == 8){
                    dev.addCase();
                } else if (final_cat == 9){
                    dev.addCooling_U();
                } else if (final_cat == 0){
                    continue;
                }
            } else if (cat == 2){
                if (final_cat == 1){
                    dev.addHandheld();
                } else if (final_cat == 2){
                    dev.addStationed();
                } else if (final_cat == 0){
                    continue;
                }
            } else if (cat == 3){
                dev.addDesktop();
            } else if (cat == 4){
                dev.addLaptop();
            } else if (cat == 5){
                if (final_cat == 1){
                    dev.addEarbuds();
                } else if (final_cat == 2){
                    dev.addEarphones();
                } else if (final_cat == 3){
                    dev.addHeadphones();
                } else if (final_cat == 4){
                    dev.addHeadset();
                } else if (final_cat == 5){
                    dev.addMicrophone();
                } else if (final_cat == 6){
                    dev.addSpeakers();
                } else if (final_cat == 7){
                    dev.addDisplay();
                } else if (final_cat == 8){
                    dev.addKeyboard();
                } else if (final_cat == 9){
                    dev.addMouse();
                } else if (final_cat == 10){
                    dev.addPortable_HDD();
                } else if (final_cat == 11){
                    dev.addPrinter();
                } else if (final_cat == 12){
                    dev.addSD_Card();
                } else if (final_cat == 13){
                    dev.addTouchpad();
                } else if (final_cat == 14){
                    dev.addUSB_Drive();
                } else if (final_cat == 15){
                    dev.addWebcam();
                } else if (final_cat == 16){
                    dev.addWire();
                } else if (final_cat == 0){
                    continue;
                }
            } else if (cat == 6){
                dev.addSmartphones();
            } else if (cat == 7){
                dev.addSmartwatch();
            } else if (cat == 8){
                dev.addTablet();
            } else if (cat == 9){
                dev.addVR();
            } else if (cat == 0){
                continue;
            }
            std::cout << "Device added!" << std::endl;
        } 
        else if (option == 2 ) {
            std::string id;
            std::cout << "Enter the ID of the device you want to remove (type n to go back): ";
            std::getline(std::cin, id);
            if (id == "n"){
                continue;
            }
            dev.removeDevice(id);
        }else if (option == 3){
            int cat = chooseDevicesCat();
            int final_cat = 0;
            if (cat == 1){
                final_cat = chooseCompPartsCat();
            } else if (cat == 2){
                final_cat = chooseConsoleCat();
            } else if (cat == 5){
                final_cat = choosePeripheralsCat();
            }
            listDevices(cat, final_cat);
        } else if (option == 4){
            std::cout << "Sales: " << Devices::getTotalSales() << std::endl;                        
        } else if (option == 5){
            std::string id;
            std::cout << "Enter the ID of the device you want to put on display (type n to go back): ";
            std::getline(std::cin, id);
            if (id == "n"){
                continue;
            }
            dev.putOnDisplay(id);
        } else if (option == 6){
            std::string id;
            std::cout << "Enter the ID of the device you want to remove from display (type n to go back): ";
            std::getline(std::cin, id);
            if (id == "n"){
                continue;
            }
            dev.removeFromDisplay(id);
        } else if (option == 7){
            signed_in = false;
            main();
        } else if (option == 8){
            std::exit(0);
        }
    } 
}
// ------------------------------------------------------------------

void listDevicesCustomer(const int cat, const int final_cat){
    listDevices(cat, final_cat);

    std::cout << "Options: " << std::endl;
    std::cout << "1. Sort & Filter" << std::endl;
    std::cout << "2. Go back" << std::endl;
    std::cout << "Option number: ";
    std::string option_str;
    std::getline(std::cin, option_str);
    unsigned int option;
    while (true){
        try{
            option = std::stoi(option_str);
            if (option > 2 || option < 1){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter either 1 or 2: " << std::endl;
            std::getline(std::cin, option_str);
        }
    }
    if (option == 1){
        if (cat == 1){
            if (final_cat == 1){
                CPU::selectSortFilter();
            } else if (final_cat == 2){
                GPU::selectSortFilter();
            } else if (final_cat == 3){
                Memory::selectSortFilter();
            } else if (final_cat == 4){
                Motherboard::selectSortFilter();
            } else if (final_cat == 5){
                HDD::selectSortFilter();
            } else if (final_cat == 6){
                SSD::selectSortFilter();
            } else if (final_cat == 7){
                PSU::selectSortFilter();
            } else if (final_cat == 8){
                PCCase::selectSortFilter();
            } else if (final_cat == 9){
                CoolingUnit::selectSortFilter();
            } else if (final_cat == 0){
                if (signed_in){
                    developer_mode();
                } else {
                    customer_mode();
                }
            }
        } else if (cat == 2){
            if (final_cat == 1){
                Handheld::selectSortFilter();
            } else if (final_cat == 2){
                Stationed::selectSortFilter();
            } else if (final_cat == 0){
                if (signed_in){
                    developer_mode();
                } else {
                    customer_mode();
                }
            }
        } else if (cat == 3){
            Desktop::selectSortFilter();
        } else if (cat == 4){
            Laptop::selectSortFilter();
        } else if (cat == 5){
            if (final_cat == 1){
                Earbuds::selectSortFilter();
            } else if (final_cat == 2){
                Earphones::selectSortFilter();
            } else if (final_cat == 3){
                Headphones::selectSortFilter();
            } else if (final_cat == 4){
                Headset::selectSortFilter();
            } else if (final_cat == 5){
                Microphone::selectSortFilter();
            } else if (final_cat == 6){
                Speakers::selectSortFilter();
            } else if (final_cat == 7){
                Display::selectSortFilter();
            } else if (final_cat == 8){
                Keyboard::selectSortFilter();
            } else if (final_cat == 9){
                Mouse::selectSortFilter();
            } else if (final_cat == 10){
                Portable_HDD::selectSortFilter();
            } else if (final_cat == 11){
                Printer::selectSortFilter();
            } else if (final_cat == 12){
                SdCard::selectSortFilter();
            } else if (final_cat == 13){
                Touchpad::selectSortFilter();
            } else if (final_cat == 14){
                UsbDrive::selectSortFilter();
            } else if (final_cat == 15){
                Webcam::selectSortFilter();
            } else if (final_cat == 16){
                Wire::selectSortFilter();
            } else if (final_cat == 0){
                if (signed_in){
                    developer_mode();
                } else {
                    customer_mode();
                }
            }
        } else if (cat == 6){
            Smartphones::selectSortFilter();
        } else if (cat == 7){
            Smartwatch::selectSortFilter();
        } else if (cat == 8){
            Tablet::selectSortFilter();
        } else if (cat == 9){
            VR::selectSortFilter();
        } else if (cat == 0){
            if (signed_in){
                developer_mode();
            } else {
                customer_mode();
            }
        }
    }

}

void recordTotalSales();

// Customer mode
void customer_mode(){
    Customer customer;
    customer.loadCart();
    while (true){    
        unsigned int option;
        {
            std::string option_str;
            std::cout << "Welcome!" << std::endl;
            std::cout << "Options: " << std::endl;
            std::cout << "1. Display products" << std::endl;
            std::cout << "2. View a product's specification" << std::endl;
            std::cout << "3. Add to cart" << std::endl;
            std::cout << "4. Remove from cart" << std::endl;
            std::cout << "5. View cart" << std::endl;
            std::cout << "6. Checkout" << std::endl;
            std::cout << "7. Sign out" << std::endl;
            std::cout << "8. Exit" << std::endl;
            std::cout << "Option number: ";
            std::getline(std::cin, option_str);
            while (true){
                try{
                    option = std::stoi(option_str);
                    if (option > 8 || option < 1){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter a number from 1 to 8: " << std::endl;
                    std::getline(std::cin, option_str);
                }
            }
        }

        if (option == 1){
            int cat = chooseDevicesCat();
            int final_cat = 0;
            if (cat == 1){
                final_cat = chooseCompPartsCat();
            } else if (cat == 2){
                final_cat = chooseConsoleCat();
            } else if (cat == 5){
                final_cat = choosePeripheralsCat();
            }
            listDevicesCustomer(cat, final_cat);
        } else if (option == 2){
            std::string id;
            std::cout << "Enter the ID of the device you want to view (type n to go back): ";
            std::getline(std::cin, id);
            if (id == "n"){
                continue;
            }
            customer.viewSpecs(id);
        } else if (option == 3){
            std::string id;
            std::cout << "Enter the ID of the device you want to add to cart (type n to go back): ";
            std::getline(std::cin, id);
            if (id == "n"){
                continue;
            }
            if (id.size() != 6){
                std::cout << "Invalid ID" << std::endl;
                continue;
            }
            std::string quantity_str;
            std::cout << "Enter the quantity you want to add: ";
            std::getline(std::cin, quantity_str);
            int quantity;
            while (true){
                try{
                    quantity = std::stoi(quantity_str);
                    if (quantity < 1){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter a number greater than 0: " << std::endl;
                    std::getline(std::cin, quantity_str);
                }
            }
            customer.addToCart(id, quantity);
        } else if (option == 4){
            std::string index_str;
            int index;
            customer.viewCart();
            std::cout << "Enter number of the device you want to remove from cart (type n to go back): ";
            std::getline(std::cin, index_str);
            if (index_str == "n"){
                continue;
            }
            while (true){
                try{
                    index = std::stoi(index_str) - 1;
                    if (index > customer.cart.size() || index < 0){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter a number from 1 to " << customer.cart.size() << ": " << std::endl;
                    std::getline(std::cin, index_str);
                }
            }
            std::cout << "Enter the quantity you want to remove: ";
            std::string quantity_str;
            std::getline(std::cin, quantity_str);
            int quantity;
            while (true){
                try{
                    quantity = std::stoi(quantity_str);
                    if (quantity > std::get<1>(customer.cart[index]) || quantity < 1){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter a number from 1 to " << std::get<1>(customer.cart[index]) << ": " << std::endl;
                    std::getline(std::cin, quantity_str);
                }
            }
            customer.removeFromCart(index, quantity);
        } else if (option == 5){
            customer.viewCart();
        } else if (option == 6){
            customer.checkout();
            recordTotalSales();
        } else if (option == 7){
            main();
        } else if (option == 8){
            std::exit(0);
        }
    }
}

// ------------------------------------------------------------------
void recordTotalSales(){
    std::ofstream file("../dev/sales_record.txt");
    if (!file.is_open() || file.fail()){
        std::cout << "Error: sales_record.txt could not be opened" << std::endl;
        return;
    }
    file << Devices::total_sales << std::endl;
    file.close();
}

void loadTotalSales(){
    std::ifstream file("../dev/sales_record.txt");
    if (!file.is_open() || file.fail()){
        std::cout << "Error: sales_record.txt could not be opened" << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    Devices::total_sales = std::stod(line);
    file.close();
}
    


#endif