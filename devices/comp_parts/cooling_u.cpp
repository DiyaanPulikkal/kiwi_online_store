#include "cooling_u.h"

CoolingUnit::CoolingUnit() : ComputerParts(){
        type = "-";
        form_factor = "-";
        cool_capacity = 0; // watts
        dimension = std::make_tuple(0.0, 0.0, 0.0);
        noise_level = 0; // dB
        fan_speed = 0;
        is_rgb = false;
        generateId();
}

CoolingUnit::CoolingUnit(const int q, const double p) : ComputerParts(q, p){
        type = "-";
        form_factor = "-";
        cool_capacity = 0; // watts
        dimension = std::make_tuple(0.0, 0.0, 0.0);
        noise_level = 0; // dB
        fan_speed = 0;
        is_rgb = false;
        generateId();
}

CoolingUnit::CoolingUnit(const std::string s) : ComputerParts(){
        type = "-";
        form_factor = "-";
        cool_capacity = 0; // watts
        dimension = std::make_tuple(0.0, 0.0, 0.0);
        noise_level = 0; // dB
        fan_speed = 0;
        is_rgb = false;
}

void CoolingUnit::setType(const std::string t){
    type = t;
}

void CoolingUnit::setFormFactor(const std::string ff){
    form_factor = ff;
}

void CoolingUnit::setCoolCapacity(const int cc){
    cool_capacity = cc;
}

void CoolingUnit::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

void CoolingUnit::setNoiseLevel(const int nl){
    noise_level = nl;
}

void CoolingUnit::setFanSpeed(const int fs){
    fan_speed = fs;
}

void CoolingUnit::setIsRgb(const bool i_rgb){
    is_rgb = i_rgb;
}

std::string CoolingUnit::getType() const{
    return type;
}

std::string CoolingUnit::getFormFactor() const{
    return form_factor;
}

int CoolingUnit::getCoolCapacity() const{
    return cool_capacity;
}

std::tuple<double, double, double> CoolingUnit::getDimension() const{
    return dimension;
}

int CoolingUnit::getNoiseLevel() const{
    return noise_level;
}

int CoolingUnit::getFanSpeed() const{
    return fan_speed;
}

bool CoolingUnit::getIsRgb() const{
    return is_rgb;
}

void CoolingUnit::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void CoolingUnit::generateId(){
    std::ifstream file_in("../txt_files/cooling_u.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }

    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const CoolingUnit& cu: cooling_unit_vec){
            std::string id = cu.getID(); // AZ0001
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
    cooling_unit_vec.push_back(*this);
    std::ofstream file_out("../txt_files/cooling_u.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CoolingUnit& cu: cooling_unit_vec){
        file_out << cu.getID() << "|";
        file_out << cu.getDescription() << "|";
        file_out << cu.getBrand() << "|";
        file_out << cu.getModel() << "|";
        file_out << cu.getPrice() << "|";
        file_out << cu.getQuantity() << "|";
        file_out << cu.getOnDisplay() << "|";
        file_out << cu.getType() << "|";
        file_out << cu.getFormFactor() << "|";
        file_out << cu.getCoolCapacity() << "|";
        file_out << std::get<0>(cu.getDimension()) << "|";
        file_out << std::get<1>(cu.getDimension()) << "|";
        file_out << std::get<2>(cu.getDimension()) << "|";
        file_out << cu.getNoiseLevel() << "|";
        file_out << cu.getFanSpeed() << "|";
        file_out << cu.getIsRgb() << "|";
        file_out << cu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CoolingUnit::updateVec(const CoolingUnit cu_in){
    for (CoolingUnit& cu: cooling_unit_vec){
        if (cu.getID() == cu_in.getID()){
            cu.setDescription(cu_in.getDescription());
            cu.setBrand(cu_in.getBrand());
            cu.setModel(cu_in.getModel());
            cu.setPrice(cu_in.getPrice());
            cu.setQuantity(cu_in.getQuantity());
            cu.setOnDisplay(cu_in.getOnDisplay());
            cu.setType(cu_in.getType());
            cu.setFormFactor(cu_in.getFormFactor());
            cu.setCoolCapacity(cu_in.getCoolCapacity());
            cu.setDimension(std::get<0>(cu_in.getDimension()),
                             std::get<1>(cu_in.getDimension()),
                             std::get<2>(cu_in.getDimension()));
            cu.setNoiseLevel(cu_in.getNoiseLevel());
            cu.setFanSpeed(cu_in.getFanSpeed());
            cu.setIsRgb(cu_in.getIsRgb());
            cu.setImagePath(cu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/cooling_u.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CoolingUnit& cu: cooling_unit_vec){
        file_out << cu.getID() << "|";
        file_out << cu.getDescription() << "|";
        file_out << cu.getBrand() << "|";
        file_out << cu.getModel() << "|";
        file_out << cu.getPrice() << "|";
        file_out << cu.getQuantity() << "|";
        file_out << cu.getOnDisplay() << "|";
        file_out << cu.getType() << "|";
        file_out << cu.getFormFactor() << "|";
        file_out << cu.getCoolCapacity() << "|";
        file_out << std::get<0>(cu.getDimension()) << "|";
        file_out << std::get<1>(cu.getDimension()) << "|";
        file_out << std::get<2>(cu.getDimension()) << "|";
        file_out << cu.getNoiseLevel() << "|";
        file_out << cu.getFanSpeed() << "|";
        file_out << cu.getIsRgb() << "|";
        file_out << cu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CoolingUnit::readData(){
    std::ifstream file_in("../txt_files/cooling_u.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string type;
    std::string form_factor;
    std::string cool_capacity;
    std::string l, w, h;
    std::string noise_level;
    std::string fan_speed;
    std::string is_rgb;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &desc, &brand, &model, &price, &quantity, &on_display, &type, &form_factor, &cool_capacity, &l, &w, &h, &noise_level, &fan_speed, &is_rgb, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        CoolingUnit cu("a");
        cu.setID(id);
        cu.setDescription(desc);
        cu.setBrand(brand);
        cu.setModel(model);
        cu.setPrice(std::stod(price));
        cu.setQuantity(std::stoi(quantity));
        cu.setOnDisplay(std::stoi(on_display));
        cu.setType(type);
        cu.setFormFactor(form_factor);
        cu.setCoolCapacity(std::stoi(cool_capacity));
        cu.setDimension(std::stod(l), std::stod(w), std::stod(h));
        cu.setNoiseLevel(std::stoi(noise_level));
        cu.setFanSpeed(std::stoi(fan_speed));
        cu.setIsRgb(std::stoi(is_rgb));
        cu.setImagePath(image_path);
        cooling_unit_vec.push_back(cu);
    }
    file_in.close();
    return;
}

void CoolingUnit::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<CoolingUnit> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Noise Level" << std::endl;
        std::cout << "4. Fan Speed" << std::endl;
        std::cout << "5. Dimension" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter Type" << std::endl;
        std::cout << "8. Filter Form Factor" << std::endl;
        std::cout << "9. Filter RGB" << std::endl;
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
            sortCoolCapacity();
        } else if (sort_option == 3){
            sortNoiseLevel();
        } else if (sort_option == 4){
            sortFanSpeed();
        } else if (sort_option == 5){
            sortDimension();
        } else if (sort_option == 6){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter type: ";
            std::getline(std::cin, filter_input);
            filtered = filterType(filter_input);
        } else if (sort_option == 8){
            std::cout << "Enter form factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 9){
            std::cout << "Enter 1 for RGB, 0 for non-RGB: ";
            std::getline(std::cin, filter_input);
            bool is_rgb;
            while (true){
                try{
                    is_rgb = std::stoi(filter_input);
                    if (is_rgb != 0 && is_rgb != 1){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: " << std::endl;
                    std::getline(std::cin, filter_input);
                }
            }
            filtered = filterIsRgb(is_rgb);
        } else if (sort_option == 10){
            filtered = filterOnDisplay();
        } else{
            break;
        }
        if (sort_option < 6){
            for (const CoolingUnit cu: cooling_unit_vec){
                std::cout << cu;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Cooling Capacity: " << cu.getCoolCapacity() << " watts" << std::endl;
                    break;
                
                case 3:
                    std::cout << "      " << "Noise Level: " << cu.getNoiseLevel() << " dB" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Fan Speed: " << cu.getFanSpeed() << " RPM" << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Dimension: " << std::get<0>(cu.getDimension()) << " x " << std::get<1>(cu.getDimension()) << " x " << std::get<2>(cu.getDimension()) << " mm" << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const CoolingUnit cu: filtered){
                std::cout << cu << std::endl;
            }
        }
    }
    return;
}


void CoolingUnit::sortPrice(){
    std::sort(cooling_unit_vec.begin(), cooling_unit_vec.end(), [](const CoolingUnit& a, const CoolingUnit& b){
        return a.getPrice() < b.getPrice();
    });
}

void CoolingUnit::sortCoolCapacity(){
    std::sort(cooling_unit_vec.begin(), cooling_unit_vec.end(), [](const CoolingUnit& a, const CoolingUnit& b){
        return a.getCoolCapacity() < b.getCoolCapacity();
    });
}

void CoolingUnit::sortNoiseLevel(){
    std::sort(cooling_unit_vec.begin(), cooling_unit_vec.end(), [](const CoolingUnit& a, const CoolingUnit& b){
        return a.getNoiseLevel() < b.getNoiseLevel();
    });
}

void CoolingUnit::sortFanSpeed(){
    std::sort(cooling_unit_vec.begin(), cooling_unit_vec.end(), [](const CoolingUnit& a, const CoolingUnit& b){
        return a.getFanSpeed() < b.getFanSpeed();
    });
}

void CoolingUnit::sortDimension(){
    std::sort(cooling_unit_vec.begin(), cooling_unit_vec.end(), [](const CoolingUnit& a, const CoolingUnit& b){
        return (std::get<0>(a.getDimension()) * std::get<1>(a.getDimension()) * std::get<2>(a.getDimension()))   < (std::get<0>(b.getDimension()) * std::get<1>(b.getDimension()) * std::get<2>(b.getDimension()));
    });
}

std::vector<CoolingUnit> CoolingUnit::filterBrand(const std::string brand){
    std::vector<CoolingUnit> filtered;
    for (const CoolingUnit cu: cooling_unit_vec){
        if (cu.getBrand() == brand){
            filtered.push_back(cu);
        }
    }
    return filtered;
}

std::vector<CoolingUnit> CoolingUnit::filterType(const std::string type){
    std::vector<CoolingUnit> filtered;
    for (const CoolingUnit cu: cooling_unit_vec){
        if (cu.getType() == type){
            filtered.push_back(cu);
        }
    }
    return filtered;
}

std::vector<CoolingUnit> CoolingUnit::filterFormFactor(const std::string form_factor){
    std::vector<CoolingUnit> filtered;
    for (const CoolingUnit cu: cooling_unit_vec){
        if (cu.getFormFactor() == form_factor){
            filtered.push_back(cu);
        }
    }
    return filtered;
}

std::vector<CoolingUnit> CoolingUnit::filterIsRgb(const bool is_rgb){
    std::vector<CoolingUnit> filtered;
    for (const CoolingUnit cu: cooling_unit_vec){
        if (cu.getIsRgb() == is_rgb){
            filtered.push_back(cu);
        }
    }
    return filtered;
}

std::vector<CoolingUnit> CoolingUnit::filterOnDisplay(){
    std::vector<CoolingUnit> filtered;
    for (const CoolingUnit cu: cooling_unit_vec){
        if (cu.getOnDisplay() == 1){
            filtered.push_back(cu);
        }
    }
    return filtered;
}

CoolingUnit& CoolingUnit::operator=(const CoolingUnit& cu){
    setID(cu.getID());
    setDescription(cu.getDescription());
    setBrand(cu.getBrand());
    setModel(cu.getModel());
    setPrice(cu.getPrice());
    setQuantity(cu.getQuantity());
    setOnDisplay(cu.getOnDisplay());
    setType(cu.getType());
    setFormFactor(cu.getFormFactor());
    setCoolCapacity(cu.getCoolCapacity());
    setDimension(std::get<0>(cu.getDimension()),
                 std::get<1>(cu.getDimension()),
                 std::get<2>(cu.getDimension()));
    setNoiseLevel(cu.getNoiseLevel());
    setFanSpeed(cu.getFanSpeed());
    setIsRgb(cu.getIsRgb());
    setImagePath(cu.getImagePath());
    return *this;
}