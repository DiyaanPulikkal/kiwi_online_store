#include "hdd.h"

HDD::HDD() : Storage(){
    rotation_speed = 0;
    cache = 0;
    power_consumption = std::make_tuple(0, 0, 0);
    generateId();
}

HDD::HDD(const int q, const double p) : Storage(q, p){
    rotation_speed = 0;
    cache = 0;
    power_consumption = std::make_tuple(0, 0, 0);
    generateId();
}

HDD::HDD(const std::string s) : Storage(){
    rotation_speed = 0;
    cache = 0;
    power_consumption = std::make_tuple(0, 0, 0);
}

void HDD::setRotationSpeed(const int r){
    rotation_speed = r;
}

void HDD::setCache(const int c){
    cache = c;
}

void HDD::setPowerConsumption(const double i, const double r, const double w){
    power_consumption = std::make_tuple(i, r, w);
}

int HDD::getRotationSpeed() const{
    return rotation_speed;
}

int HDD::getCache() const{
    return cache;
}

std::tuple<double, double, double> HDD::getPowerConsumption() const{
    return power_consumption;
}

void HDD::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void HDD::generateId(){
    std::ifstream file_in("../txt_files/hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const HDD& hdd: hdd_vec){
            std::string id = hdd.getID(); // AZ0001
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
    hdd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const HDD& hdd: hdd_vec){
        file_out << hdd.getID() << "|";
        file_out << hdd.getDescription() << "|";
        file_out << hdd.getBrand() << "|";
        file_out << hdd.getModel() << "|";
        file_out << hdd.getPrice() << "|";
        file_out << hdd.getQuantity() << "|";
        file_out << hdd.getOnDisplay() << "|";
        file_out << hdd.getStorageCapacity() << "|";
        file_out << hdd.getStorageSpeed() << "|";
        file_out << hdd.getInterface() << "|";
        file_out << hdd.getFormFactor() << "|";
        file_out << hdd.getRotationSpeed() << "|";
        file_out << hdd.getCache() << "|";
        file_out << std::get<0>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<1>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<2>(hdd.getPowerConsumption()) << "|";
        file_out << hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void HDD::updateVec(const HDD hdd_in){
    for (HDD& hdd: hdd_vec){
        if(hdd.getID() == hdd_in.getID()){
            hdd.setDescription(hdd_in.getDescription());
            hdd.setBrand(hdd_in.getBrand());
            hdd.setModel(hdd_in.getModel());
            hdd.setPrice(hdd_in.getPrice());
            hdd.setQuantity(hdd_in.getQuantity());
            hdd.setOnDisplay(hdd_in.getOnDisplay());
            hdd.setStorageCapacity(hdd_in.getStorageCapacity());
            hdd.setStorageSpeed(hdd_in.getStorageSpeed());
            hdd.setInterface(hdd_in.getInterface());
            hdd.setFormFactor(hdd_in.getFormFactor());
            hdd.setRotationSpeed(hdd_in.getRotationSpeed());
            hdd.setCache(hdd_in.getCache());
            hdd.setPowerConsumption(std::get<0>(hdd_in.getPowerConsumption()),
                                     std::get<1>(hdd_in.getPowerConsumption()),
                                     std::get<2>(hdd_in.getPowerConsumption()));
            hdd.setImagePath(hdd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const HDD& hdd: hdd_vec){
        file_out << hdd.getID() << "|";
        file_out << hdd.getDescription() << "|";
        file_out << hdd.getBrand() << "|";
        file_out << hdd.getModel() << "|";
        file_out << hdd.getPrice() << "|";
        file_out << hdd.getQuantity() << "|";
        file_out << hdd.getOnDisplay() << "|";
        file_out << hdd.getStorageCapacity() << "|";
        file_out << hdd.getStorageSpeed() << "|";
        file_out << hdd.getInterface() << "|";
        file_out << hdd.getFormFactor() << "|";
        file_out << hdd.getRotationSpeed() << "|";
        file_out << hdd.getCache() << "|";
        file_out << std::get<0>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<1>(hdd.getPowerConsumption()) << "|";
        file_out << std::get<2>(hdd.getPowerConsumption()) << "|";
        file_out << hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void HDD::readData(){
    std::ifstream file_in("../txt_files/hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string storage_c;
    std::string storage_s;
    std::string interface;
    std::string form_factor;
    std::string rotation_speed;
    std::string cache;
    std::string idle_power;
    std::string read_power;
    std::string write_power;
    std::string image_path;
    std::array<std::string*, 17> data = {&id, &description, &brand, &model, &price, &quantity, &on_display, &storage_c, &storage_s, &interface, &form_factor, &rotation_speed, &cache, &idle_power, &read_power, &write_power, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        HDD hdd("a");
        hdd.setID(id);
        hdd.setDescription(description);
        hdd.setBrand(brand);
        hdd.setModel(model);
        hdd.setPrice(std::stod(price));
        hdd.setQuantity(std::stoi(quantity));
        hdd.setOnDisplay(std::stoi(on_display));
        hdd.setStorageCapacity(std::stoi(storage_c));
        hdd.setStorageSpeed(std::stoi(storage_s));
        hdd.setInterface(interface);
        hdd.setFormFactor(form_factor);
        hdd.setRotationSpeed(std::stoi(rotation_speed));
        hdd.setCache(std::stoi(cache));
        hdd.setPowerConsumption(std::stod(idle_power), std::stod(read_power), std::stod(write_power));
        hdd.setImagePath(image_path);
        hdd_vec.push_back(hdd);
    }
    file_in.close();
    return;
}

void HDD::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<HDD> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Speed" << std::endl;
        std::cout << "4. Rotation Speed" << std::endl;
        std::cout << "5. Cache" << std::endl;
        std::cout << "6. Idle Power" << std::endl;
        std::cout << "7. Read Power" << std::endl;
        std::cout << "8. Write Power" << std::endl;
        std::cout << "9. Filter Brand" << std::endl;
        std::cout << "10. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 11 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 11: " << std::endl;
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
            sortRotationSpeed();
        } else if (sort_option == 5){
            sortCache();
        } else if (sort_option == 6){
            sortIdlePower();
        } else if (sort_option == 7){
            sortReadPower();
        } else if (sort_option == 8){
            sortWritePower();
        } else if (sort_option == 9){
            std::cout << "Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 10){
            filtered = filterOnDisplay();
        } else{
            break;
        }
        if (sort_option < 9){
            for (const HDD hdd: hdd_vec){
                std::cout << hdd;
                switch (sort_option)
                {
                case 2:
                    std::cout << "       " << "Capacity: " << hdd.getStorageCapacity() << std::endl;
                    break;
                
                case 3:
                    std::cout << "       " << "Speed: " << hdd.getStorageSpeed() << std::endl;
                    break;
                
                case 4:
                    std::cout << "       " << "Rotation Speed: " << hdd.getRotationSpeed() << std::endl;
                    break;
                
                case 5:
                    std::cout << "       " << "Cache: " << hdd.getCache() << std::endl;
                    break;

                case 6:
                    std::cout << "       " << "Idle Power: " << std::get<0>(hdd.getPowerConsumption()) << std::endl;
                    break;

                case 7:
                    std::cout << "       " << "Read Power: " << std::get<1>(hdd.getPowerConsumption()) << std::endl;
                    break;

                case 8:
                    std::cout << "       " << "Write Power: " << std::get<2>(hdd.getPowerConsumption()) << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const HDD hdd: filtered){
                std::cout << hdd << std::endl;
            }
        }
    }
    return;
}

void HDD::sortPrice(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return hdd1.getPrice() < hdd2.getPrice();
    });
}

void HDD::sortCapacity(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return hdd1.getStorageCapacity() < hdd2.getStorageCapacity();
    });
}

void HDD::sortSpeed(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return hdd1.getStorageSpeed() < hdd2.getStorageSpeed();
    });
}

void HDD::sortRotationSpeed(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return hdd1.getRotationSpeed() < hdd2.getRotationSpeed();
    });
}

void HDD::sortCache(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return hdd1.getCache() < hdd2.getCache();
    });
}

void HDD::sortIdlePower(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return std::get<0>(hdd1.getPowerConsumption()) < std::get<0>(hdd2.getPowerConsumption());
    });
}

void HDD::sortReadPower(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return std::get<1>(hdd1.getPowerConsumption()) < std::get<1>(hdd2.getPowerConsumption());
    });
}

void HDD::sortWritePower(){
    std::sort(hdd_vec.begin(), hdd_vec.end(), [](const HDD& hdd1, const HDD& hdd2){
        return std::get<2>(hdd1.getPowerConsumption()) < std::get<2>(hdd2.getPowerConsumption());
    });
}

std::vector<HDD> HDD::filterBrand(const std::string brand){
    std::vector<HDD> filtered;
    for (const HDD hdd: hdd_vec){
        if (hdd.getBrand() == brand){
            filtered.push_back(hdd);
        }
    }
    return filtered;
}

std::vector<HDD> HDD::filterOnDisplay(){
    std::vector<HDD> filtered;
    for (const HDD hdd: hdd_vec){
        if (hdd.getOnDisplay() == 1){
            filtered.push_back(hdd);
        }
    }
    return filtered;
}

HDD& HDD::operator=(const HDD& hdd){
    setID(hdd.getID());
    setDescription(hdd.getDescription());
    setBrand(hdd.getBrand());
    setModel(hdd.getModel());
    setPrice(hdd.getPrice());
    setQuantity(hdd.getQuantity());
    setOnDisplay(hdd.getOnDisplay());
    setStorageCapacity(hdd.getStorageCapacity());
    setStorageSpeed(hdd.getStorageSpeed());
    setInterface(hdd.getInterface());
    setFormFactor(hdd.getFormFactor());
    setRotationSpeed(hdd.getRotationSpeed());
    setCache(hdd.getCache());
    setPowerConsumption(std::get<0>(hdd.getPowerConsumption()), std::get<1>(hdd.getPowerConsumption()), std::get<2>(hdd.getPowerConsumption()));
    setImagePath(hdd.getImagePath());
    return *this;
}
