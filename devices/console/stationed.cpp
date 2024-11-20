#include "stationed.h"

Stationed::Stationed() : Console(){
    ssd = "-";
    size = "-";
    generateId();
}

Stationed::Stationed(const int q, const double p) : Console(q, p) {
    std::string ssd;
    size = "-";
    generateId();
}

Stationed::Stationed(const std::string s) : Console(){
    ssd = s;
    size = "-";
}

std::string Stationed::getSSD() const {
    return ssd;
}

std::string Stationed::getSize() const {
    return size;
}

void Stationed::setSSD(const std::string s) {
    ssd = s;
}

void Stationed::setSize(const std::string s) {
    size = s;
}

void Stationed::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Stationed::generateId() {
    std::ifstream file_in("../txt_files/stationed.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Stationed& stationed: stationed_vec){
            std::string id = stationed.getID(); // AZ0001
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
    stationed_vec.push_back(*this);
    std::ofstream file_out("../txt_files/stationed.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Stationed& stationed: stationed_vec){
        file_out << stationed.getID() << "|";
        file_out << stationed.getDescription() << "|";
        file_out << stationed.getBrand() << "|";
        file_out << stationed.getModel() << "|";
        file_out << stationed.getPrice() << "|";
        file_out << stationed.getQuantity() << "|";
        file_out << stationed.getOnDisplay() << "|";
        file_out << std::get<0>(stationed.getResolution()) << "|";
        file_out << std::get<1>(stationed.getResolution()) << "|";
        file_out << stationed.getMainProcessor() << "|";
        file_out << stationed.getGraphicsProcessor() << "|";
        file_out << stationed.getStorageCapacity() << "|";
        file_out << stationed.getUSB() << "|";
        file_out << stationed.getDisplay() << "|";
        file_out << stationed.getInputOutputPort() << "|";
        file_out << stationed.getWifi() << "|";
        file_out << stationed.getWeight() << "|";
        file_out << stationed.getBluetooth() << "|";
        file_out << stationed.getPowerConsumption() << "|";
        file_out << stationed.getControllerVibration() << "|";
        file_out << stationed.getTVMode() << "|";
        file_out << stationed.getSSD() << "|";
        file_out << stationed.getSize() << "|";
        file_out << stationed.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Stationed::updateVec(const Stationed stationed_in) {
    for (Stationed& stationed: stationed_vec){
        if (stationed.getID() == stationed_in.getID()){
            stationed.setDescription(stationed_in.getDescription());
            stationed.setBrand(stationed_in.getBrand());
            stationed.setModel(stationed_in.getModel());
            stationed.setPrice(stationed_in.getPrice());
            stationed.setQuantity(stationed_in.getQuantity());
            stationed.setOnDisplay(stationed_in.getOnDisplay());
            stationed.setResolution(std::get<0>(stationed_in.getResolution()), std::get<1>(stationed_in.getResolution()));
            stationed.setMainProcessor(stationed_in.getMainProcessor());
            stationed.setGraphicsProcessor(stationed_in.getGraphicsProcessor());
            stationed.setStorageCapacity(stationed_in.getStorageCapacity());
            stationed.setUSB(stationed_in.getUSB());
            stationed.setDisplay(stationed_in.getDisplay());
            stationed.setInputOutputPort(stationed_in.getInputOutputPort());
            stationed.setWifi(stationed_in.getWifi());
            stationed.setWeight(stationed_in.getWeight());
            stationed.setBluetooth(stationed_in.getBluetooth());
            stationed.setPowerConsumption(stationed_in.getPowerConsumption());
            stationed.setControllerVibration(stationed_in.getControllerVibration());
            stationed.setTVMode(stationed_in.getTVMode());
            stationed.setSSD(stationed_in.getSSD());
            stationed.setSize(stationed_in.getSize());
            stationed.setImagePath(stationed_in.getImagePath());

            break;
        }
    }
    std::ofstream file_out("../txt_files/stationed.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Stationed& stationed: stationed_vec){
        file_out << stationed.getID() << "|";
        file_out << stationed.getDescription() << "|";
        file_out << stationed.getBrand() << "|";
        file_out << stationed.getModel() << "|";
        file_out << stationed.getPrice() << "|";
        file_out << stationed.getQuantity() << "|";
        file_out << stationed.getOnDisplay() << "|";
        file_out << std::get<0>(stationed.getResolution()) << "|";
        file_out << std::get<1>(stationed.getResolution()) << "|";
        file_out << stationed.getMainProcessor() << "|";
        file_out << stationed.getGraphicsProcessor() << "|";
        file_out << stationed.getStorageCapacity() << "|";
        file_out << stationed.getUSB() << "|";
        file_out << stationed.getDisplay() << "|";
        file_out << stationed.getInputOutputPort() << "|";
        file_out << stationed.getWifi() << "|";
        file_out << stationed.getWeight() << "|";
        file_out << stationed.getBluetooth() << "|";
        file_out << stationed.getPowerConsumption() << "|";
        file_out << stationed.getControllerVibration() << "|";
        file_out << stationed.getTVMode() << "|";
        file_out << stationed.getSSD() << "|";
        file_out << stationed.getSize() << "|";
        file_out << stationed.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Stationed::readData(){
    std::ifstream file_in("../txt_files/stationed.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resolution_x;
    std::string resolution_y;
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
    std::string ssd;
    std::string size;
    std::string image_path;
    std::array<std::string*, 24> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resolution_x, &resolution_y, &main_processor, &graphics_processor, &storage_capacity, &usb, &display, &input_output_port, &wifi, &weight, &bluetooth, &power_consumption, &controller_vibration, &tv_mode, &ssd, &size, &image_path};

    std::string row;
    while(std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Stationed stationed("a");
        stationed.setID(id);
        stationed.setDescription(description);
        stationed.setBrand(brand);
        stationed.setModel(model);
        stationed.setPrice(std::stod(price));
        stationed.setQuantity(std::stoi(quantity));
        stationed.setOnDisplay(std::stoi(on_display));
        stationed.setResolution(std::stod(resolution_x), std::stod(resolution_y));
        stationed.setMainProcessor(main_processor);
        stationed.setGraphicsProcessor(graphics_processor);
        stationed.setStorageCapacity(std::stoi(storage_capacity));
        stationed.setUSB(usb);
        stationed.setDisplay(display);
        stationed.setInputOutputPort(input_output_port);
        stationed.setWifi(wifi);
        stationed.setWeight(std::stod(weight));
        stationed.setBluetooth(bluetooth);
        stationed.setPowerConsumption(std::stod(power_consumption));
        stationed.setControllerVibration(std::stoi(controller_vibration));
        stationed.setTVMode(std::stoi(tv_mode));
        stationed.setSSD(ssd);
        stationed.setSize(size);
        stationed.setImagePath(image_path);
        stationed_vec.push_back(stationed);
    }
    file_in.close();
    return;
}

void Stationed::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Stationed> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Resolution" << std::endl;
        std::cout << "3. Storage Capacity" << std::endl;
        std::cout << "4. Power Consumption" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
        std::cout << "6. Filter Wifi" << std::endl;
        std::cout << "7. Filter Controller Vibration" << std::endl;
        std::cout << "8. Filter TV Mode" << std::endl;
        std::cout << "9. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 9 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 9: " << std::endl;
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
            sortPowerConsumption();
        } else if (sort_option == 5){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 6){
            std::cout << "Enter wifi: ";
            std::getline(std::cin, filter_input);
            filtered = filterWifi(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter 1 for controller vibration or 0 for no controller vibration: ";
            std::getline(std::cin, filter_input);
            while (true){
                try{
                    int controller_vibration = std::stoi(filter_input);
                    if (controller_vibration != 0 && controller_vibration != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterControllerVibration(controller_vibration);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, filter_input);
                }
            }
        } else if (sort_option == 8){
            std::cout << "Enter 1 for TV mode or 0 for no TV mode: ";
            std::getline(std::cin, filter_input);
            while (true){
                try{
                    int tv_mode = std::stoi(filter_input);
                    if (tv_mode != 0 && tv_mode != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterTVMode(tv_mode);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, filter_input);
                }
            }
        } else if (sort_option == 9){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 5){
            for (const Stationed stationed: stationed_vec){
                std::cout << stationed;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Resolution: " << std::get<0>(stationed.getResolution()) << " x " << std::get<1>(stationed.getResolution()) << std::endl;                    
                    break;

                case 3:
                    std::cout << "      " << "Storage Capacity: " << stationed.getStorageCapacity() << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Power Consumption: " << stationed.getPowerConsumption() << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }   
            }
        } else {
            for (const Stationed stationed: filtered){
                std::cout << stationed << std::endl;
            }
        }
    }
    return;    
}

void Stationed::sortPrice(){
    std::sort(stationed_vec.begin(), stationed_vec.end(), [](const Stationed& a, const Stationed& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void Stationed::sortResolution(){
    std::sort(stationed_vec.begin(), stationed_vec.end(), [](const Stationed& a, const Stationed& b){
        return std::get<0>(a.getResolution()) < std::get<0>(b.getResolution());
    });
    return;
}

void Stationed::sortStorageCapacity(){
    std::sort(stationed_vec.begin(), stationed_vec.end(), [](const Stationed& a, const Stationed& b){
        return a.getStorageCapacity() < b.getStorageCapacity();
    });
    return;
}

void Stationed::sortPowerConsumption(){
    std::sort(stationed_vec.begin(), stationed_vec.end(), [](const Stationed& a, const Stationed& b){
        return a.getPowerConsumption() < b.getPowerConsumption();
    });
    return;
}

std::vector<Stationed> Stationed::filterBrand(const std::string brand){
    std::vector<Stationed> filtered;
    for (const Stationed stationed: stationed_vec){
        if (stationed.getBrand() == brand){
            filtered.push_back(stationed);
        }
    }
    return filtered;
}

std::vector<Stationed> Stationed::filterWifi(const std::string wifi){
    std::vector<Stationed> filtered;
    for (const Stationed stationed: stationed_vec){
        if (stationed.getWifi() == wifi){
            filtered.push_back(stationed);
        }
    }
    return filtered;
}

std::vector<Stationed> Stationed::filterControllerVibration(const bool controller_vibration){
    std::vector<Stationed> filtered;
    for (const Stationed stationed: stationed_vec){
        if (stationed.getControllerVibration() == controller_vibration){
            filtered.push_back(stationed);
        }
    }
    return filtered;
}

std::vector<Stationed> Stationed::filterTVMode(const bool tv_mode){
    std::vector<Stationed> filtered;
    for (const Stationed stationed: stationed_vec){
        if (stationed.getTVMode() == tv_mode){
            filtered.push_back(stationed);
        }
    }
    return filtered;
}

std::vector<Stationed> Stationed::filterOnDisplay(){
    std::vector<Stationed> filtered;
    for (const Stationed stationed: stationed_vec){
        if (stationed.getOnDisplay() == 1){
            filtered.push_back(stationed);
        }
    }
    return filtered;
}

Stationed& Stationed::operator=(const Stationed& stationed){
    setID(stationed.getID());
    setDescription(stationed.getDescription());
    setBrand(stationed.getBrand());
    setModel(stationed.getModel());
    setPrice(stationed.getPrice());
    setQuantity(stationed.getQuantity());
    setOnDisplay(stationed.getOnDisplay());
    setResolution(std::get<0>(stationed.getResolution()), std::get<1>(stationed.getResolution()));
    setMainProcessor(stationed.getMainProcessor());
    setGraphicsProcessor(stationed.getGraphicsProcessor());
    setStorageCapacity(stationed.getStorageCapacity());
    setUSB(stationed.getUSB());
    setDisplay(stationed.getDisplay());
    setInputOutputPort(stationed.getInputOutputPort());
    setWifi(stationed.getWifi());
    setWeight(stationed.getWeight());
    setBluetooth(stationed.getBluetooth());
    setPowerConsumption(stationed.getPowerConsumption());
    setControllerVibration(stationed.getControllerVibration());
    setTVMode(stationed.getTVMode());
    setSSD(stationed.getSSD());
    setSize(stationed.getSize());
    setImagePath(stationed.getImagePath());
    return *this;
}