#include "usb_drive.h"

UsbDrive::UsbDrive(): Peripherals(){
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    generateId();
}

UsbDrive::UsbDrive(const int q, const double p) : Peripherals(q, p) {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    generateId();
}

UsbDrive::UsbDrive(const std::string s) : Peripherals() {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
}

void UsbDrive::setCapacity(const unsigned int c) {
    capacity = c;
}

void UsbDrive::setInterface(const std::string i) {
    interface = i;
}

void UsbDrive::setTransferSpeed(const int s) {
    transfer_speed = s;
}

int UsbDrive::getCapacity() const {
    return capacity;
}

std::string UsbDrive::getInterface() const {
    return interface;
}

int UsbDrive::getTransferSpeed() const {
    return transfer_speed;
}

void UsbDrive::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void UsbDrive::generateId() {
    std::ifstream file_in("../txt_files/usb_drive.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const UsbDrive& usb: usb_drive_vec){
            std::string id = usb.getID(); // AZ0001
            std::string id_num = id.substr(2); // 0001
            unsigned int id_num_int = std::stoi(id_num);
            if (id_num_int > max_id){
                max_id = id_num_int;
            }
        }
        unsigned int no_of_zeros = 4 - std::to_string(max_id).length();
        std::string id = id_start;
        for (unsigned int i = 0; i < no_of_zeros; i++){
            id += "0";
        }
        id += std::to_string(max_id + 1);
        setID(id);
    }
    file_in.close();
    usb_drive_vec.push_back(*this);
    std::ofstream file_out("../txt_files/usb_drive.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const UsbDrive& usb: usb_drive_vec){
        file_out << usb.getID() << "|";
        file_out << usb.getDescription() << "|";
        file_out << usb.getBrand() << "|";
        file_out << usb.getModel() << "|";
        file_out << usb.getPrice() << "|";
        file_out << usb.getQuantity() << "|";
        file_out << usb.getOnDisplay() << "|";
        file_out << usb.getCapacity() << "|";
        file_out << usb.getInterface() << "|";
        file_out << usb.getTransferSpeed() << "|";
        file_out << usb.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void UsbDrive::updateVec(const UsbDrive usb_in){
    for (UsbDrive& usb: usb_drive_vec){
        if (usb.getID() == usb_in.getID()){
            usb.setDescription(usb_in.getDescription());
            usb.setBrand(usb_in.getBrand());
            usb.setModel(usb_in.getModel());
            usb.setPrice(usb_in.getPrice());
            usb.setQuantity(usb_in.getQuantity());
            usb.setOnDisplay(usb_in.getOnDisplay());
            usb.setCapacity(usb_in.getCapacity());
            usb.setInterface(usb_in.getInterface());
            usb.setTransferSpeed(usb_in.getTransferSpeed());
            usb.setImagePath(usb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/usb_drive.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const UsbDrive& usb: usb_drive_vec){
        file_out << usb.getID() << "|";
        file_out << usb.getDescription() << "|";
        file_out << usb.getBrand() << "|";
        file_out << usb.getModel() << "|";
        file_out << usb.getPrice() << "|";
        file_out << usb.getQuantity() << "|";
        file_out << usb.getOnDisplay() << "|";
        file_out << usb.getCapacity() << "|";
        file_out << usb.getInterface() << "|";
        file_out << usb.getTransferSpeed() << "|";
        file_out << usb.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void UsbDrive::readData() {
    std::ifstream file_in("../txt_files/usb_drive.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string capacity;
    std::string interface;
    std::string transfer_speed;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &capacity, &interface, &transfer_speed, &image_path};

    std::string row;
    while (std::getline(file_in, row)) {
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data) {
            std::getline(rowstream, *data_ptr, '|');
        }
        UsbDrive usb("a");
        usb.setID(id);
        usb.setDescription(description);
        usb.setBrand(brand);
        usb.setModel(model);
        usb.setPrice(std::stod(price));
        usb.setQuantity(std::stoi(quantity));
        usb.setOnDisplay(std::stoi(on_display));
        usb.setCapacity(std::stoi(capacity));
        usb.setInterface(interface);
        usb.setTransferSpeed(std::stoi(transfer_speed));
        usb.setImagePath(image_path);
        usb_drive_vec.push_back(usb);  
    }    
    file_in.close();
    return;
}

void UsbDrive::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<UsbDrive> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Transfer Speed" << std::endl;
        std::cout << "4. Filter Brand" << std::endl;
        std::cout << "5. Filter Interface" << std::endl;
        std::cout << "6. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 6 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 6: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortCapacity();
        } else if (sort_option == 3){
            sortTransferSpeed();
        } else if (sort_option == 4){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 5){
            std::cout << "Enter interface: ";
            std::getline(std::cin, filter_input);
            filtered = filterInterface(filter_input);
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 4){
            for (const UsbDrive usbdrive: usb_drive_vec){
                std::cout << usbdrive;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Capacity: " << usbdrive.getCapacity() << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Transfer Speed: " << usbdrive.getTransferSpeed() << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const UsbDrive usbdrive: filtered){
                std::cout << usbdrive << std::endl;
            }
        }
    }
    return;
}

void UsbDrive::sortPrice(){
    std::sort(usb_drive_vec.begin(), usb_drive_vec.end(), [](const UsbDrive& a, const UsbDrive& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void UsbDrive::sortCapacity(){
    std::sort(usb_drive_vec.begin(), usb_drive_vec.end(), [](const UsbDrive& a, const UsbDrive& b){
        return a.getCapacity() < b.getCapacity();
    });
    return;
}

void UsbDrive::sortTransferSpeed(){
    std::sort(usb_drive_vec.begin(), usb_drive_vec.end(), [](const UsbDrive& a, const UsbDrive& b){
        return a.getTransferSpeed() < b.getTransferSpeed();
    });
    return;
}

std::vector<UsbDrive> UsbDrive::filterBrand(const std::string b){
    std::vector<UsbDrive> filtered;
    for (const UsbDrive usb: usb_drive_vec){
        if (usb.getBrand() == b){
            filtered.push_back(usb);
        }
    }
    return filtered;
}

std::vector<UsbDrive> UsbDrive::filterInterface(const std::string i){
    std::vector<UsbDrive> filtered;
    for (const UsbDrive usb: usb_drive_vec){
        if (usb.getInterface() == i){
            filtered.push_back(usb);
        }
    }
    return filtered;
}

std::vector<UsbDrive> UsbDrive::filterOnDisplay(){
    std::vector<UsbDrive> filtered;
    for (const UsbDrive usb: usb_drive_vec){
        if (usb.getOnDisplay() == 1){
            filtered.push_back(usb);
        }
    }
    return filtered;
}

UsbDrive& UsbDrive::operator=(const UsbDrive& usb){
    setID(usb.getID());
    setDescription(usb.getDescription());
    setBrand(usb.getBrand());
    setModel(usb.getModel());
    setPrice(usb.getPrice());
    setQuantity(usb.getQuantity());
    setOnDisplay(usb.getOnDisplay());
    setCapacity(usb.getCapacity());
    setInterface(usb.getInterface());
    setTransferSpeed(usb.getTransferSpeed());
    setImagePath(usb.getImagePath());
    return *this;
}

