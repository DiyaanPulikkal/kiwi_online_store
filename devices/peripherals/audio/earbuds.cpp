#include "earbuds.h"

Earbuds::Earbuds(): Peripherals(){
    battery_life = 0;
    has_anc = false;
    water_resistant = false;
    generateId();
}

Earbuds::Earbuds(const int q, const double p) : Peripherals(q, p){
    battery_life = 0;
    has_anc = false;
    water_resistant = false;
    generateId();
}

Earbuds::Earbuds(const std::string s) : Peripherals(){
    battery_life = 0;
    has_anc = false;
    water_resistant = false;
}

void Earbuds::setBatteryLife(const double b){
    battery_life = b;
}

void Earbuds::setANC(const bool a){
    has_anc = a;
}

void Earbuds::setWaterResistant(const bool w){
    water_resistant = w;
}

double Earbuds::getBatteryLife() const{
    return battery_life;
}

bool Earbuds::getANC() const{
    return has_anc;
}

bool Earbuds::getWaterResistant() const{
    return water_resistant;
}

void Earbuds::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Earbuds::generateId(){
    std::ifstream file_in("../txt_files/earbuds.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Earbuds& earbud: earbuds_vec){
            std::string id = earbud.getID();
            std::string id_num = id.substr(2);
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
    earbuds_vec.push_back(*this);
    std::ofstream file_out("../txt_files/earbuds.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Earbuds& earbud: earbuds_vec){
        file_out << earbud.getID() << "|";
        file_out << earbud.getDescription() << "|";
        file_out << earbud.getBrand() << "|";
        file_out << earbud.getModel() << "|";
        file_out << earbud.getPrice() << "|";
        file_out << earbud.getQuantity() << "|";
        file_out << earbud.getOnDisplay() << "|";
        file_out << earbud.getBatteryLife() << "|";
        file_out << earbud.getANC() << "|";
        file_out << earbud.getWaterResistant() << "|";
        file_out << earbud.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Earbuds::updateVec(const Earbuds eb_in){
    for (Earbuds& eb: earbuds_vec){
        if (eb.getID() == eb_in.getID()){
            eb.setDescription(eb_in.getDescription());
            eb.setBrand(eb_in.getBrand());
            eb.setModel(eb_in.getModel());
            eb.setPrice(eb_in.getPrice());
            eb.setQuantity(eb_in.getQuantity());
            eb.setOnDisplay(eb_in.getOnDisplay());
            eb.setBatteryLife(eb_in.getBatteryLife());
            eb.setANC(eb_in.getANC());
            eb.setWaterResistant(eb_in.getWaterResistant());
            eb.setImagePath(eb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/earbuds.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Earbuds& earbud: earbuds_vec){
        file_out << earbud.getID() << "|";
        file_out << earbud.getDescription() << "|";
        file_out << earbud.getBrand() << "|";
        file_out << earbud.getModel() << "|";
        file_out << earbud.getPrice() << "|";
        file_out << earbud.getQuantity() << "|";
        file_out << earbud.getOnDisplay() << "|";
        file_out << earbud.getBatteryLife() << "|";
        file_out << earbud.getANC() << "|";
        file_out << earbud.getWaterResistant() << "|";
        file_out << earbud.getImagePath(); 
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Earbuds::readData(){
    std::ifstream file_in("../txt_files/earbuds.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string battery_l;
    std::string anc;
    std::string water_r;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &battery_l, &anc, &water_r, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Earbuds earbud("a");
        earbud.setID(id);
        earbud.setDescription(description);
        earbud.setBrand(brand);
        earbud.setModel(model);
        earbud.setPrice(std::stod(price));
        earbud.setQuantity(std::stoi(quantity));
        earbud.setOnDisplay(std::stoi(on_display));
        earbud.setBatteryLife(std::stod(battery_l));
        earbud.setANC(std::stoi(anc));
        earbud.setWaterResistant(std::stoi(water_r));
        earbud.setImagePath(image_path);
        earbuds_vec.push_back(earbud);
    }
    file_in.close();
    return;
}

void Earbuds::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Earbuds> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Battery Life" << std::endl;
        std::cout << "3. Filter Brand" << std::endl;
        std::cout << "4. Filter ANC" << std::endl;
        std::cout << "5. Filter Water Resistant" << std::endl;
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
            sortBatteryLife();
        } else if (sort_option == 3){
            std::string brand;
            std::cout << "Enter brand: ";
            std::getline(std::cin, brand);
            filtered = filterBrand(brand);
        } else if (sort_option == 4){
            filtered = filterANC();
        } else if (sort_option == 5){
            filtered = filterWaterResistant();
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 3){
            for (const Earbuds earbuds: earbuds_vec){
                std::cout << earbuds;
                ((sort_option == 1)? std::cout << std::endl : std::cout << "        " << "Battery Life: " << earbuds.getBatteryLife() << " hours" << std::endl);
            }
        } else {
            for (const Earbuds earbuds: filtered){
                std::cout << earbuds << std::endl;
            }
        }
    }
    return;
}

void Earbuds::sortPrice(){
    std::sort(earbuds_vec.begin(), earbuds_vec.end(), [](const Earbuds& a, const Earbuds& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void Earbuds::sortBatteryLife(){
    std::sort(earbuds_vec.begin(), earbuds_vec.end(), [](const Earbuds& a, const Earbuds& b){
        return a.getBatteryLife() > b.getBatteryLife();
    });
    return;
}

std::vector<Earbuds> Earbuds::filterBrand(const std::string brand){
    std::vector<Earbuds> filtered;
    for (const Earbuds earbud: earbuds_vec){
        if (earbud.getBrand() == brand){
            filtered.push_back(earbud);
        }
    }
    return filtered;
}

std::vector<Earbuds> Earbuds::filterANC(){
    std::vector<Earbuds> filtered;
    for (const Earbuds earbud: earbuds_vec){
        if (earbud.getANC()){
            filtered.push_back(earbud);
        }
    }
    return filtered;
}

std::vector<Earbuds> Earbuds::filterWaterResistant(){
    std::vector<Earbuds> filtered;
    for (const Earbuds earbud: earbuds_vec){
        if (earbud.getWaterResistant()){
            filtered.push_back(earbud);
        }
    }
    return filtered;
}

std::vector<Earbuds> Earbuds::filterOnDisplay(){
    std::vector<Earbuds> filtered;
    for (const Earbuds earbud: earbuds_vec){
        if (earbud.getOnDisplay()){
            filtered.push_back(earbud);
        }
    }
    return filtered;
}

Earbuds& Earbuds::operator=(const Earbuds& eb){
    setID(eb.getID());
    setDescription(eb.getDescription());
    setBrand(eb.getBrand());
    setModel(eb.getModel());
    setPrice(eb.getPrice());
    setQuantity(eb.getQuantity());
    setOnDisplay(eb.getOnDisplay());
    setBatteryLife(eb.getBatteryLife());
    setANC(eb.getANC());
    setWaterResistant(eb.getWaterResistant());
    setImagePath(eb.getImagePath());
    return *this;
}