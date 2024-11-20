#include "handheld.h"

Handheld::Handheld() : Console(){
    battery = "-";
    power_supply = "-";
    headphone_jack = "-";
    microSD_slot = 0;
    size = "-";
    generateId();
}

Handheld::Handheld(const int q, const double p) : Console(q, p) {
    battery = "-";
    power_supply = "-";
    headphone_jack = "-";
    microSD_slot = 0;
    size = "-";
    generateId();
}

Handheld::Handheld(const std::string s) : Console(){
    battery = s;
    power_supply = "-";
    headphone_jack = "-";
    microSD_slot = 0;
    size = "-";
}

std::string Handheld::getBattery() const {
    return battery;
}

std::string Handheld::getPowerSupply() const {
    return power_supply;
}

std::string Handheld::getHeadphoneJack() const {
    return headphone_jack;
}

int Handheld::getMicroSDSlot() const {
    return microSD_slot;
}

std::string Handheld::getSize() const {
    return size;
}

void Handheld::setBattery(const std::string b) {
    battery = b;
}

void Handheld::setPowerSupply(const std::string p) {
    power_supply = p;
}

void Handheld::setHeadphoneJack(const std::string h) {
    headphone_jack = h;
}

void Handheld::setMicroSDSlot(const int m) {
    microSD_slot = m;
}

void Handheld::setSize(const std::string s) {
    size = s;
}

void Handheld::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Handheld::generateId() {
    std::ifstream file_in("../txt_files/handheld.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Handheld& handheld: handheld_vec){
            std::string id = handheld.getID(); // AZ0001
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
    handheld_vec.push_back(*this);
    std::ofstream file_out("../txt_files/handheld.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Handheld& handheld: handheld_vec){
        file_out << handheld.getID() << "|";
        file_out << handheld.getDescription() << "|";
        file_out << handheld.getBrand() << "|";
        file_out << handheld.getModel() << "|";
        file_out << handheld.getPrice() << "|";
        file_out << handheld.getQuantity() << "|";
        file_out << handheld.getOnDisplay() << "|";
        file_out << std::get<0>(handheld.getResolution()) << "|";
        file_out << std::get<1>(handheld.getResolution()) << "|";
        file_out << handheld.getMainProcessor() << "|";
        file_out << handheld.getGraphicsProcessor() << "|";
        file_out << handheld.getStorageCapacity() << "|";
        file_out << handheld.getUSB() << "|";
        file_out << handheld.getDisplay() << "|";
        file_out << handheld.getInputOutputPort() << "|";
        file_out << handheld.getWifi() << "|";
        file_out << handheld.getWeight() << "|";
        file_out << handheld.getBluetooth() << "|";
        file_out << handheld.getPowerConsumption() << "|";
        file_out << handheld.getControllerVibration() << "|";
        file_out << handheld.getTVMode() << "|";
        file_out << handheld.getBattery() << "|";
        file_out << handheld.getPowerSupply() << "|";
        file_out << handheld.getHeadphoneJack() << "|";
        file_out << handheld.getMicroSDSlot() << "|";
        file_out << handheld.getSize() << "|";
        file_out << handheld.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Handheld::updateVec(const Handheld handheld_in) {
    for (Handheld& handheld: handheld_vec){
        if (handheld.getID() == handheld_in.getID()){
            handheld.setDescription(handheld_in.getDescription());
            handheld.setBrand(handheld_in.getBrand());
            handheld.setModel(handheld_in.getModel());
            handheld.setPrice(handheld_in.getPrice());
            handheld.setQuantity(handheld_in.getQuantity());
            handheld.setOnDisplay(handheld_in.getOnDisplay());
            handheld.setResolution(std::get<0>(handheld_in.getResolution()), std::get<1>(handheld_in.getResolution()));
            handheld.setMainProcessor(handheld_in.getMainProcessor());
            handheld.setGraphicsProcessor(handheld_in.getGraphicsProcessor());
            handheld.setStorageCapacity(handheld_in.getStorageCapacity());
            handheld.setUSB(handheld_in.getUSB());
            handheld.setDisplay(handheld_in.getDisplay());
            handheld.setInputOutputPort(handheld_in.getInputOutputPort());
            handheld.setWifi(handheld_in.getWifi());
            handheld.setWeight(handheld_in.getWeight());
            handheld.setBluetooth(handheld_in.getBluetooth());
            handheld.setPowerConsumption(handheld_in.getPowerConsumption());
            handheld.setControllerVibration(handheld_in.getControllerVibration());
            handheld.setTVMode(handheld_in.getTVMode());
            handheld.setBattery(handheld_in.getBattery());
            handheld.setPowerSupply(handheld_in.getPowerSupply());
            handheld.setHeadphoneJack(handheld_in.getHeadphoneJack());
            handheld.setMicroSDSlot(handheld_in.getMicroSDSlot());
            handheld.setSize(handheld_in.getSize());
            handheld.setImagePath(handheld_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/handheld.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Handheld& handheld: handheld_vec){
        file_out << handheld.getID() << "|";
        file_out << handheld.getDescription() << "|";
        file_out << handheld.getBrand() << "|";
        file_out << handheld.getModel() << "|";
        file_out << handheld.getPrice() << "|";
        file_out << handheld.getQuantity() << "|";
        file_out << handheld.getOnDisplay() << "|";
        file_out << std::get<0>(handheld.getResolution()) << "|";
        file_out << std::get<1>(handheld.getResolution()) << "|";
        file_out << handheld.getMainProcessor() << "|";
        file_out << handheld.getGraphicsProcessor() << "|";
        file_out << handheld.getStorageCapacity() << "|";
        file_out << handheld.getUSB() << "|";
        file_out << handheld.getDisplay() << "|";
        file_out << handheld.getInputOutputPort() << "|";
        file_out << handheld.getWifi() << "|";
        file_out << handheld.getWeight() << "|";
        file_out << handheld.getBluetooth() << "|";
        file_out << handheld.getPowerConsumption() << "|";
        file_out << handheld.getControllerVibration() << "|";
        file_out << handheld.getTVMode() << "|";
        file_out << handheld.getBattery() << "|";
        file_out << handheld.getPowerSupply() << "|";
        file_out << handheld.getHeadphoneJack() << "|";
        file_out << handheld.getMicroSDSlot() << "|";
        file_out << handheld.getSize() << "|";
        file_out << handheld.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Handheld::readData() {
    std::ifstream file_in("../txt_files/handheld.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resx;
    std::string resy;
    std::string main_processor;
    std::string graphics_processor;
    std::string storage_capacity;
    std::string usb;
    std::string display;
    std::string input_output_port;
    std::string wifi;
    std::string weight;
    std::string bluetooth;
    std::string power_consumption;
    std::string controller_vibration;
    std::string tv_mode;
    std::string battery;
    std::string power_supply;
    std::string headphone_jack;
    std::string microSD_slot;
    std::string size;
    std::string image_path;
    std::array<std::string*, 27> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resx, &resy, &main_processor, &graphics_processor, &storage_capacity, &usb, &display, &input_output_port, &wifi, &weight, &bluetooth, &power_consumption, &controller_vibration, &tv_mode, &battery, &power_supply, &headphone_jack, &microSD_slot, &size, &image_path};

    std::string row;
    while(std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Handheld handheld("a");
        handheld.setID(id);
        handheld.setDescription(description);
        handheld.setBrand(brand);
        handheld.setModel(model);
        handheld.setPrice(std::stod(price));
        handheld.setQuantity(std::stoi(quantity));
        handheld.setOnDisplay(std::stoi(on_display));
        handheld.setResolution(std::stoi(resx), std::stoi(resy));
        handheld.setMainProcessor(main_processor);
        handheld.setGraphicsProcessor(graphics_processor);
        handheld.setStorageCapacity(std::stoi(storage_capacity));
        handheld.setUSB(usb);
        handheld.setDisplay(display);
        handheld.setInputOutputPort(input_output_port);
        handheld.setWifi(wifi);
        handheld.setWeight(std::stod(weight));
        handheld.setBluetooth(bluetooth);
        handheld.setPowerConsumption(std::stod(power_consumption));
        handheld.setControllerVibration(std::stoi(controller_vibration));
        handheld.setTVMode(std::stoi(tv_mode));
        handheld.setBattery(battery);
        handheld.setPowerSupply(power_supply);
        handheld.setHeadphoneJack(headphone_jack);
        handheld.setMicroSDSlot(std::stoi(microSD_slot));
        handheld.setSize(size);
        handheld.setImagePath(image_path);
        handheld_vec.push_back(handheld);
    }
    file_in.close();
    return;
}

void Handheld::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Handheld> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Resolution" << std::endl;
        std::cout << "3. Storage Capacity" << std::endl;
        std::cout << "4. Weight" << std::endl;
        std::cout << "5. Power Consumption" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter Wifi" << std::endl;
        std::cout << "8. Filter Controller Vibration" << std::endl;
        std::cout << "9. Filter TV Mode" << std::endl;
        std::cout << "10. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 10 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 10: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortResolution();
        } else if (sort_option == 3){
            sortStorageCapacity();
        } else if (sort_option == 4){
            sortWeight();
        } else if (sort_option == 5){
            sortPowerConsumption();
        } else if (sort_option == 6){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter wifi: ";
            std::getline(std::cin, filter_input);
            filtered = filterWifi(filter_input);
        } else if (sort_option == 8){
            std::string controller_vibration_str;
            std::cout << "Enter 1 for controller vibration or 0 for no controller vibration: ";
            std::getline(std::cin, controller_vibration_str);
            while (true){
                try{
                    int controller_vibration = std::stoi(controller_vibration_str);
                    if (controller_vibration != 0 && controller_vibration != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterControllerVibration(controller_vibration);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, controller_vibration_str);
                }
            }
        } else if (sort_option == 9){
            std::string tv_mode_str;
            std::cout << "Enter 1 for TV mode or 0 for no TV mode: ";
            std::getline(std::cin, tv_mode_str);
            while (true){
                try{
                    int tv_mode = std::stoi(tv_mode_str);
                    if (tv_mode != 0 && tv_mode != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterTVMode(tv_mode);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, tv_mode_str);
                }
            }
        } else if (sort_option == 10){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const Handheld handheld: handheld_vec){
                std::cout << handheld;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Resolution: " << std::get<0>(handheld.getResolution()) << " x " << std::get<1>(handheld.getResolution()) << std::endl;
                    break;
                
                case 3:
                    std::cout << "      " << "Storage Capacity: " << handheld.getStorageCapacity() << " GB" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Weight: " << handheld.getWeight() << " g" << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Power Consumption: " << handheld.getPowerConsumption() << " W" << std::endl;
                    break;                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Handheld handheld: filtered){
                std::cout << handheld << std::endl;
            }
        }
    }
    return;    
}

void Handheld::sortPrice() {
    std::sort(handheld_vec.begin(), handheld_vec.end(), [](const Handheld& handheld1, const Handheld& handheld2){
        return handheld1.getPrice() < handheld2.getPrice();
    });
    return;
}

void Handheld::sortResolution() {
    std::sort(handheld_vec.begin(), handheld_vec.end(), [](const Handheld& handheld1, const Handheld& handheld2){
        return std::get<1>(handheld1.getResolution()) < std::get<1>(handheld2.getResolution());
    });
    return;
}

void Handheld::sortStorageCapacity() {
    std::sort(handheld_vec.begin(), handheld_vec.end(), [](const Handheld& handheld1, const Handheld& handheld2){
        return handheld1.getStorageCapacity() < handheld2.getStorageCapacity();
    });
    return;
}

void Handheld::sortWeight() {
    std::sort(handheld_vec.begin(), handheld_vec.end(), [](const Handheld& handheld1, const Handheld& handheld2){
        return handheld1.getWeight() < handheld2.getWeight();
    });
    return;
}

void Handheld::sortPowerConsumption() {
    std::sort(handheld_vec.begin(), handheld_vec.end(), [](const Handheld& handheld1, const Handheld& handheld2){
        return handheld1.getPowerConsumption() < handheld2.getPowerConsumption();
    });
    return;
}

std::vector<Handheld> Handheld::filterBrand(const std::string brand) {
    std::vector<Handheld> filtered;
    for (const Handheld handheld: handheld_vec){
        if (handheld.getBrand() == brand){
            filtered.push_back(handheld);
        }
    }
    return filtered;
}

std::vector<Handheld> Handheld::filterWifi(const std::string wifi) {
    std::vector<Handheld> filtered;
    for (const Handheld handheld: handheld_vec){
        if (handheld.getWifi() == wifi){
            filtered.push_back(handheld);
        }
    }
    return filtered;
}

std::vector<Handheld> Handheld::filterControllerVibration(const bool controller_vibration) {
    std::vector<Handheld> filtered;
    for (const Handheld handheld: handheld_vec){
        if (handheld.getControllerVibration() == controller_vibration){
            filtered.push_back(handheld);
        }
    }
    return filtered;
}

std::vector<Handheld> Handheld::filterTVMode(const bool tv_mode) {
    std::vector<Handheld> filtered;
    for (const Handheld handheld: handheld_vec){
        if (handheld.getTVMode() == tv_mode){
            filtered.push_back(handheld);
        }
    }
    return filtered;
}

std::vector<Handheld> Handheld::filterOnDisplay() {
    std::vector<Handheld> filtered;
    for (const Handheld handheld: handheld_vec){
        if (handheld.getOnDisplay() == 1){
            filtered.push_back(handheld);
        }
    }
    return filtered;
}

Handheld& Handheld::operator=(const Handheld& handheld_in) {
    setID(handheld_in.getID());
    setDescription(handheld_in.getDescription());
    setBrand(handheld_in.getBrand());
    setModel(handheld_in.getModel());
    setPrice(handheld_in.getPrice());
    setQuantity(handheld_in.getQuantity());
    setOnDisplay(handheld_in.getOnDisplay());
    setResolution(std::get<0>(handheld_in.getResolution()), std::get<1>(handheld_in.getResolution()));
    setMainProcessor(handheld_in.getMainProcessor());
    setGraphicsProcessor(handheld_in.getGraphicsProcessor());
    setStorageCapacity(handheld_in.getStorageCapacity());
    setUSB(handheld_in.getUSB());
    setDisplay(handheld_in.getDisplay());
    setInputOutputPort(handheld_in.getInputOutputPort());
    setWifi(handheld_in.getWifi());
    setWeight(handheld_in.getWeight());
    setBluetooth(handheld_in.getBluetooth());
    setPowerConsumption(handheld_in.getPowerConsumption());
    setControllerVibration(handheld_in.getControllerVibration());
    setTVMode(handheld_in.getTVMode());
    setBattery(handheld_in.getBattery());
    setPowerSupply(handheld_in.getPowerSupply());
    setHeadphoneJack(handheld_in.getHeadphoneJack());
    setMicroSDSlot(handheld_in.getMicroSDSlot());
    setSize(handheld_in.getSize());
    setImagePath(handheld_in.getImagePath());
    return *this;
}