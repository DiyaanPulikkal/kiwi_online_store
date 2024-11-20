#include "microphone.h"

Microphone::Microphone(): Peripherals(){
    directionality = "-";
    has_usb = false;
    has_xlr = false;
    generateId();
}

Microphone::Microphone(const int q, const double p) : Peripherals(q, p){
    directionality = "-";
    has_usb = false;
    has_xlr = false;
    generateId();
}

Microphone::Microphone(const std::string s) : Peripherals(){
    directionality = "-";
    has_usb = false;
    has_xlr = false;
}

void Microphone::setDirectionality(const std::string d){
    directionality = d;
}

void Microphone::setUSB(const bool u){
    has_usb = u;
}

void Microphone::setXLR(const bool x){
    has_xlr = x;
}

std::string Microphone::getDirectionality() const{
    return directionality;
}

bool Microphone::getUSB() const{
    return has_usb;
}

bool Microphone::getXLR() const{
    return has_xlr;
}

void Microphone::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Microphone::generateId(){
    std::ifstream file_in("../txt_files/microphone.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Microphone& micro: microphone_vec){
            std::string id = micro.getID();
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
    microphone_vec.push_back(*this);
    std::ofstream file_out("../txt_files/microphone.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Microphone& micro: microphone_vec){
        file_out << micro.getID() << "|";
        file_out << micro.getDescription() << "|";
        file_out << micro.getBrand() << "|";
        file_out << micro.getModel() << "|";
        file_out << micro.getPrice() << "|";
        file_out << micro.getQuantity() << "|";
        file_out << micro.getOnDisplay() << "|";
        file_out << micro.getDirectionality() << "|";
        file_out << micro.getUSB() << "|";
        file_out << micro.getXLR() << "|";
        file_out << micro.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Microphone::updateVec(const Microphone microphone_in){
    for (Microphone& microphone: microphone_vec){
        if (microphone.getID() == microphone_in.getID()){
            microphone.setDescription(microphone_in.getDescription());
            microphone.setBrand(microphone_in.getBrand());
            microphone.setModel(microphone_in.getModel());
            microphone.setPrice(microphone_in.getPrice());
            microphone.setQuantity(microphone_in.getQuantity());
            microphone.setOnDisplay(microphone_in.getOnDisplay());
            microphone.setDirectionality(microphone_in.getDirectionality());
            microphone.setUSB(microphone_in.getUSB());
            microphone.setXLR(microphone_in.getXLR());
            microphone.setImagePath(microphone_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/microphone.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Microphone& micro: microphone_vec){
        file_out << micro.getID() << "|";
        file_out << micro.getDescription() << "|";
        file_out << micro.getBrand() << "|";
        file_out << micro.getModel() << "|";
        file_out << micro.getPrice() << "|";
        file_out << micro.getQuantity() << "|";
        file_out << micro.getOnDisplay() << "|";
        file_out << micro.getDirectionality() << "|";
        file_out << micro.getUSB() << "|";
        file_out << micro.getXLR() << "|";
        file_out << micro.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Microphone::readData() {
    std::ifstream file_in("../txt_files/microphone.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string directionality;
    std::string has_usb;
    std::string has_xlr;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &directionality, &has_usb, &has_xlr, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Microphone micro("a");
        micro.setID(id);
        micro.setDescription(description);
        micro.setBrand(brand);
        micro.setModel(model);
        micro.setPrice(std::stod(price));
        micro.setQuantity(std::stoi(quantity));
        micro.setOnDisplay(std::stoi(on_display));
        micro.setDirectionality(directionality);
        micro.setUSB(std::stoi(has_usb));
        micro.setXLR(std::stoi(has_xlr));
        micro.setImagePath(image_path);
        microphone_vec.push_back(micro);
    }
    file_in.close();
    return;
}

void Microphone::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Microphone> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter Directionality" << std::endl;
        std::cout << "4. Filter USB" << std::endl;
        std::cout << "5. Filter XLR" << std::endl;
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
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 3){
            std::cout << "Enter directionality: ";
            std::getline(std::cin, filter_input);
            filtered = filterDirectionality(filter_input);
        } else if (sort_option == 4){
            filtered = filterUSB();
        } else if (sort_option == 5){
            filtered = filterXLR();
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const Microphone microphone: microphone_vec){
                std::cout << microphone << std::endl;
            }
        } else {
            for (const Microphone microphone: filtered){
                std::cout << microphone << std::endl;
            }
        }
    }
    return;
}

void Microphone::sortPrice(){
    std::sort(microphone_vec.begin(), microphone_vec.end(), [](const Microphone& a, const Microphone& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

std::vector<Microphone> Microphone::filterBrand(const std::string brand){
    std::vector<Microphone> filtered;
    for (const Microphone micro: microphone_vec){
        if (micro.getBrand() == brand){
            filtered.push_back(micro);
        }
    }
    return filtered;
}

std::vector<Microphone> Microphone::filterDirectionality(const std::string directionality){
    std::vector<Microphone> filtered;
    for (const Microphone micro: microphone_vec){
        if (micro.getDirectionality() == directionality){
            filtered.push_back(micro);
        }
    }
    return filtered;
}

std::vector<Microphone> Microphone::filterUSB(){
    std::vector<Microphone> filtered;
    for (const Microphone micro: microphone_vec){
        if (micro.getUSB()){
            filtered.push_back(micro);
        }
    }
    return filtered;
}

std::vector<Microphone> Microphone::filterXLR(){
    std::vector<Microphone> filtered;
    for (const Microphone micro: microphone_vec){
        if (micro.getXLR()){
            filtered.push_back(micro);
        }
    }
    return filtered;
}

std::vector<Microphone> Microphone::filterOnDisplay(){
    std::vector<Microphone> filtered;
    for (const Microphone micro: microphone_vec){
        if (micro.getOnDisplay()){
            filtered.push_back(micro);
        }
    }
    return filtered;
}

Microphone& Microphone::operator=(const Microphone& micro){
    setID(micro.getID());
    setDescription(micro.getDescription());
    setBrand(micro.getBrand());
    setModel(micro.getModel());
    setPrice(micro.getPrice());
    setQuantity(micro.getQuantity());
    setOnDisplay(micro.getOnDisplay());
    setDirectionality(micro.getDirectionality());
    setUSB(micro.getUSB());
    setXLR(micro.getXLR());
    setImagePath(micro.getImagePath());
    return *this;
}