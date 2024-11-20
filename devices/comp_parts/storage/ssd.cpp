#include "ssd.h"

SSD::SSD() : Storage(){
    power_consumption = 0;
    generateId();
}

SSD::SSD(const int q, const double p) : Storage(q, p){
    power_consumption = 0;
    generateId();
}

SSD::SSD(const std::string s) : Storage(){
    power_consumption = 0;
}

void SSD::setPowerConsumption(const int p){
    power_consumption = p;
}

int SSD::getPowerConsumption() const{
    return power_consumption;
}

void SSD::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void SSD::generateId(){
    std::ifstream file_in("../txt_files/ssd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const SSD& ssd: ssd_vec){
            std::string id = ssd.getID(); // AZ0001
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
    ssd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/ssd.txt", std::ios::out);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    for (const SSD& ssd: ssd_vec){
        file_out << ssd.getID() << "|";
        file_out << ssd.getDescription() << "|";
        file_out << ssd.getBrand() << "|";
        file_out << ssd.getModel() << "|";
        file_out << ssd.getPrice() << "|";
        file_out << ssd.getQuantity() << "|";
        file_out << ssd.getOnDisplay() << "|";
        file_out << ssd.getStorageCapacity() << "|";
        file_out << ssd.getStorageSpeed() << "|";
        file_out << ssd.getInterface() << "|";
        file_out << ssd.getFormFactor() << "|";
        file_out << ssd.getPowerConsumption() << "|";
        file_out << ssd.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void SSD::updateVec(const SSD ssd_in){
    for (SSD& ssd: ssd_vec){
        if (ssd.getID() == ssd_in.getID()){
            ssd.setDescription(ssd_in.getDescription());
            ssd.setBrand(ssd_in.getBrand());
            ssd.setModel(ssd_in.getModel());
            ssd.setPrice(ssd_in.getPrice());
            ssd.setQuantity(ssd_in.getQuantity());
            ssd.setOnDisplay(ssd_in.getOnDisplay());
            ssd.setStorageCapacity(ssd_in.getStorageCapacity());
            ssd.setStorageSpeed(ssd_in.getStorageSpeed());
            ssd.setInterface(ssd_in.getInterface());
            ssd.setFormFactor(ssd_in.getFormFactor());
            ssd.setPowerConsumption(ssd_in.getPowerConsumption());
            ssd.setImagePath(ssd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/ssd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    for (const SSD& ssd: ssd_vec){
        file_out << ssd.getID() << "|";
        file_out << ssd.getDescription() << "|";
        file_out << ssd.getBrand() << "|";
        file_out << ssd.getModel() << "|";
        file_out << ssd.getPrice() << "|";
        file_out << ssd.getQuantity() << "|";
        file_out << ssd.getOnDisplay() << "|";
        file_out << ssd.getStorageCapacity() << "|";
        file_out << ssd.getStorageSpeed() << "|";
        file_out << ssd.getInterface() << "|";
        file_out << ssd.getFormFactor() << "|";
        file_out << ssd.getPowerConsumption() << "|";
        file_out << ssd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void SSD::readData(){
    std::ifstream file_in("../txt_files/ssd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File not found" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string storage_c;
    std::string storage_s;
    std::string interface;
    std::string form_factor;
    std::string power_consumption;
    std::string image_path;
    std::array<std::string*, 13> data = {&id, &desc, &brand, &model, &price, &quantity, &on_display, &storage_c, &storage_s, &interface, &form_factor, &power_consumption, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        SSD ssd("a");
        ssd.setID(id);
        ssd.setDescription(desc);
        ssd.setBrand(brand);
        ssd.setModel(model);
        ssd.setPrice(std::stod(price));
        ssd.setQuantity(std::stoi(quantity));
        ssd.setOnDisplay(std::stoi(on_display));
        ssd.setStorageCapacity(std::stoi(storage_c));
        ssd.setStorageSpeed(std::stoi(storage_s));
        ssd.setInterface(interface);
        ssd.setFormFactor(form_factor);
        ssd.setPowerConsumption(std::stoi(power_consumption));
        ssd.setImagePath(image_path);
        ssd_vec.push_back(ssd);
    }
    file_in.close();
    return;
}

void SSD::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<SSD> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Speed" << std::endl;
        std::cout << "4. Power Consumption" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
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
            sortSpeed();
        } else if (sort_option == 4){
            sortPowerConsumption();
        } else if (sort_option == 5){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
            for (const SSD ssd: filtered){
                std::cout << ssd << std::endl;
            }
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
            for (const SSD ssd: filtered){
                std::cout << ssd << std::endl;
            }
        } else{
            break;
        }
        if (sort_option < 5){
            for (const SSD ssd: ssd_vec){
                std::cout << ssd;
                switch (sort_option)
                {
                case 2:
                    std::cout << "       " << "Capacity: " << ssd.getStorageCapacity() << std::endl;
                    break;

                case 3:
                    std::cout << "       " << "Speed: " << ssd.getStorageSpeed() << std::endl;
                    break;

                case 4:
                    std::cout << "       " << "Power Consumption: " << ssd.getPowerConsumption() << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const SSD ssd: filtered){
                std::cout << ssd << std::endl;
            }
        }
    }
    return;
}

void SSD::sortPrice(){
    std::sort(ssd_vec.begin(), ssd_vec.end(), [](const SSD& a, const SSD& b){
        return a.getPrice() < b.getPrice();
    });
}

void SSD::sortCapacity(){
    std::sort(ssd_vec.begin(), ssd_vec.end(), [](const SSD& a, const SSD& b){
        return a.getStorageCapacity() < b.getStorageCapacity();
    });
}

void SSD::sortSpeed(){
    std::sort(ssd_vec.begin(), ssd_vec.end(), [](const SSD& a, const SSD& b){
        return a.getStorageSpeed() < b.getStorageSpeed();
    });
}

void SSD::sortPowerConsumption(){
    std::sort(ssd_vec.begin(), ssd_vec.end(), [](const SSD& a, const SSD& b){
        return a.getPowerConsumption() < b.getPowerConsumption();
    });
}

std::vector<SSD> SSD::filterBrand(const std::string brand){
    std::vector<SSD> filtered;
    for (const SSD ssd: ssd_vec){
        if (ssd.getBrand() == brand){
            filtered.push_back(ssd);
        }
    }
    return filtered;
}

std::vector<SSD> SSD::filterOnDisplay(){
    std::vector<SSD> filtered;
    for (const SSD ssd: ssd_vec){
        if (ssd.getOnDisplay() == 1){
            filtered.push_back(ssd);
        }
    }
    return filtered;
}

// Operator overloading
SSD& SSD::operator=(const SSD& ssd){
    setID(ssd.getID());
    setDescription(ssd.getDescription());
    setBrand(ssd.getBrand());
    setModel(ssd.getModel());
    setPrice(ssd.getPrice());
    setQuantity(ssd.getQuantity());
    setOnDisplay(ssd.getOnDisplay());
    setStorageCapacity(ssd.getStorageCapacity());
    setStorageSpeed(ssd.getStorageSpeed());
    setInterface(ssd.getInterface());
    setFormFactor(ssd.getFormFactor());
    setPowerConsumption(ssd.getPowerConsumption());
    setImagePath(ssd.getImagePath());
    return *this;
}
