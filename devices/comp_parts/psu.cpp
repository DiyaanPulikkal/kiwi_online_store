#include "psu.h"

PSU::PSU(): ComputerParts(){
    form_factor = "-";
    efficiency = "-";
    modular = "-";
    wattage = 0;
    fan = std::make_tuple("-", 0);
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    generateId();
}

PSU::PSU(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    efficiency = "-";
    modular = "-";
    wattage = 0;
    fan = std::make_tuple("-", 0);
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    generateId();
}

PSU::PSU(const std::string s) : ComputerParts(){
    form_factor = s;
    efficiency = "-";
    modular = "-";
    wattage = 0;
    fan = std::make_tuple("-", 0);
    dimension = std::make_tuple(0.0, 0.0, 0.0);
}

void PSU::setFormFactor(const std::string ff){
    form_factor = ff;
}

void PSU::setEfficiency(const std::string e){
    efficiency = e;
}

void PSU::setModular(const std::string m){
    modular = m;
}

void PSU::setWattage(const int w){
    wattage = w;
}

void PSU::setFan(const std::string size, const int noise){
    fan = std::make_tuple(size, noise);
}

void PSU::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

std::string PSU::getFormFactor() const{
    return form_factor;
}

std::string PSU::getEfficiency() const{
    return efficiency;
}

std::string PSU::getModular() const{
    return modular;
}

int PSU::getWattage() const{
    return wattage;
}

std::tuple<std::string, int> PSU::getFan() const{
    return fan;
}

std::tuple<double, double, double> PSU::getDimension() const{
    return dimension;
}

void PSU::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void PSU::generateId(){
    std::ifstream file_in("../txt_files/psu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const PSU& psu: psu_vec){
            std::string id = psu.getID(); // AZ0001
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
    psu_vec.push_back(*this);
    std::ofstream file_out("../txt_files/psu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PSU& psu: psu_vec){
        file_out << psu.getID() << "|";
        file_out << psu.getBrand() << "|";
        file_out << psu.getModel() << "|";
        file_out << psu.getPrice() << "|";        
        file_out << psu.getQuantity() << "|";
        file_out << psu.getOnDisplay() << "|";
        file_out << psu.getFormFactor() << "|";
        file_out << psu.getEfficiency() << "|";
        file_out << psu.getModular() << "|";
        file_out << psu.getWattage() << "|";
        file_out << std::get<0>(psu.getFan()) << "|";
        file_out << std::get<1>(psu.getFan()) << "|";
        file_out << std::get<0>(psu.getDimension()) << "|";
        file_out << std::get<1>(psu.getDimension()) << "|";
        file_out << std::get<2>(psu.getDimension()) << "|";
        file_out << psu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PSU::updateVec(const PSU psu_in){
    for (PSU& psu: psu_vec){
        if (psu.getID() == psu_in.getID()){
            psu.setDescription(psu_in.getDescription());
            psu.setBrand(psu_in.getBrand());
            psu.setModel(psu_in.getModel());
            psu.setPrice(psu_in.getPrice());
            psu.setQuantity(psu_in.getQuantity());
            psu.setOnDisplay(psu_in.getOnDisplay());
            psu.setFormFactor(psu_in.getFormFactor());
            psu.setEfficiency(psu_in.getEfficiency());
            psu.setModular(psu_in.getModular());
            psu.setWattage(psu_in.getWattage());
            psu.setFan(std::get<0>(psu_in.getFan()), std::get<1>(psu_in.getFan()));
            psu.setDimension(std::get<0>(psu_in.getDimension()), 
                            std::get<1>(psu_in.getDimension()), 
                            std::get<2>(psu_in.getDimension()));
            psu.setImagePath(psu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/psu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PSU& psu: psu_vec){
        file_out << psu.getID() << "|";
        file_out << psu.getBrand() << "|";
        file_out << psu.getModel() << "|";
        file_out << psu.getPrice() << "|";        
        file_out << psu.getQuantity() << "|";
        file_out << psu.getOnDisplay() << "|";
        file_out << psu.getFormFactor() << "|";
        file_out << psu.getEfficiency() << "|";
        file_out << psu.getModular() << "|";
        file_out << psu.getWattage() << "|";
        file_out << std::get<0>(psu.getFan()) << "|";
        file_out << std::get<1>(psu.getFan()) << "|";
        file_out << std::get<0>(psu.getDimension()) << "|";
        file_out << std::get<1>(psu.getDimension()) << "|";
        file_out << std::get<2>(psu.getDimension()) << "|";
        file_out << psu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PSU::readData(){
    std::ifstream file_in("../txt_files/psu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string form_factor;
    std::string efficiency;
    std::string modular;
    std::string wattage;
    std::string fan_size;
    std::string fan_noise;
    std::string length;
    std::string width;
    std::string height;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &brand, &model, &price, &quantity, &on_display, &form_factor, &efficiency, &modular, &wattage, &fan_size, &fan_noise, &length, &width, &height, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        PSU psu("a");
        psu.setID(id);
        psu.setDescription(description);
        psu.setBrand(brand);
        psu.setModel(model);
        psu.setPrice(std::stod(price));
        psu.setQuantity(std::stoi(quantity));
        psu.setOnDisplay(std::stoi(on_display));
        psu.setFormFactor(form_factor);
        psu.setEfficiency(efficiency);
        psu.setModular(modular);
        psu.setWattage(std::stoi(wattage));
        psu.setFan(fan_size, std::stoi(fan_noise));
        psu.setDimension(std::stod(length), std::stod(width), std::stod(height));
        psu.setImagePath(image_path);
        psu_vec.push_back(psu);
    }
    file_in.close();
    return;
}

void PSU::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<PSU> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Wattage" << std::endl;
        std::cout << "3. Dimension" << std::endl;
        std::cout << "4. Efficiency" << std::endl;
        std::cout << "5. Fan Noise" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter Form Factor" << std::endl;
        std::cout << "8. Filter Modular" << std::endl;
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
            sortWattage();
        } else if (sort_option == 3){
            sortDimension();
        } else if (sort_option == 4){
            sortEfficiency();
        } else if (sort_option == 5){
            sortFanNoise();
        } else if (sort_option == 6){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter form factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 8){
            std::cout << "Enter modular: ";
            std::getline(std::cin, filter_input);
            filtered = filterModular(filter_input);
        } else if (sort_option == 9){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const PSU psu: psu_vec){
                std::cout << psu;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Wattage: " << psu.getWattage() << "W" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Dimension: " << std::get<0>(psu.getDimension()) << " x " << std::get<1>(psu.getDimension()) << " x " << std::get<2>(psu.getDimension()) << "mm" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Efficiency: " << psu.getEfficiency() << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Fan Noise: " << std::get<1>(psu.getFan()) << "dB" << std::endl;
                    break;
                
                default:
                    std::cout << "      " << std::endl;
                    break;
                }
            }
        } else {
            for (const PSU psu: filtered){
                std::cout << psu << std::endl;
            }
        }
    }
    return;    
}

void PSU::sortPrice(){
    std::sort(psu_vec.begin(), psu_vec.end(), [](const PSU& a, const PSU& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void PSU::sortWattage(){
    std::sort(psu_vec.begin(), psu_vec.end(), [](const PSU& a, const PSU& b){
        return a.getWattage() < b.getWattage();
    });
    return;
}

void PSU::sortDimension(){
    std::sort(psu_vec.begin(), psu_vec.end(), [](const PSU& a, const PSU& b){
        return std::get<0>(a.getDimension()) < std::get<0>(b.getDimension());
    });
    return;
}

void PSU::sortEfficiency(){
    std::sort(psu_vec.begin(), psu_vec.end(), [](const PSU& a, const PSU& b){
        return a.getEfficiency() < b.getEfficiency();
    });
    return;
}

void PSU::sortFanNoise(){
    std::sort(psu_vec.begin(), psu_vec.end(), [](const PSU& a, const PSU& b){
        return std::get<1>(a.getFan()) < std::get<1>(b.getFan());
    });
    return;
}

std::vector<PSU> PSU::filterBrand(const std::string brand){
    std::vector<PSU> filtered;
    for (const PSU psu: psu_vec){
        if (psu.getBrand() == brand){
            filtered.push_back(psu);
        }
    }
    return filtered;
}

std::vector<PSU> PSU::filterFormFactor(const std::string form_factor){
    std::vector<PSU> filtered;
    for (const PSU psu: psu_vec){
        if (psu.getFormFactor() == form_factor){
            filtered.push_back(psu);
        }
    }
    return filtered;
}

std::vector<PSU> PSU::filterModular(const std::string modular){
    std::vector<PSU> filtered;
    for (const PSU psu: psu_vec){
        if (psu.getModular() == modular){
            filtered.push_back(psu);
        }
    }
    return filtered;
}

std::vector<PSU> PSU::filterOnDisplay(){
    std::vector<PSU> filtered;
    for (const PSU psu: psu_vec){
        if (psu.getOnDisplay() == 1){
            filtered.push_back(psu);
        }
    }
    return filtered;
}

PSU& PSU::operator=(const PSU& psu){
    setID(psu.getID());
    setDescription(psu.getDescription());
    setBrand(psu.getBrand());
    setModel(psu.getModel());
    setPrice(psu.getPrice());
    setQuantity(psu.getQuantity());
    setOnDisplay(psu.getOnDisplay());
    setFormFactor(psu.getFormFactor());
    setEfficiency(psu.getEfficiency());
    setModular(psu.getModular());
    setWattage(psu.getWattage());
    setFan(std::get<0>(psu.getFan()), std::get<1>(psu.getFan()));
    setDimension(std::get<0>(psu.getDimension()), 
                std::get<1>(psu.getDimension()), 
                std::get<2>(psu.getDimension()));
    setImagePath(psu.getImagePath());
    return *this;
}