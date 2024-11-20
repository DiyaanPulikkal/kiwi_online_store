#include "touchpad.h"

Touchpad::Touchpad(): Peripherals(){
    type = "-";
    dimensions = std::make_tuple(0.0, 0.0);
    generateId();
}

Touchpad::Touchpad(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    dimensions = std::make_tuple(0.0, 0.0);
    generateId();
}

Touchpad::Touchpad(const std::string s) : Peripherals() {
    type = "-";
    dimensions = std::make_tuple(0.0, 0.0);
}

void Touchpad::setType(const std::string t) {
    type = t;
}

void Touchpad::setDimensions(const double l, const double w) {
    dimensions = std::make_tuple(l, w);
}

std::string Touchpad::getType() const {
    return type;
}

std::tuple<double, double> Touchpad::getDimensions() const {
    return dimensions;
}

void Touchpad::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Touchpad::generateId() {
    std::ifstream file_in("../txt_files/touchpad.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Touchpad& tpad: touchpad_vec){
            std::string id = tpad.getID(); // AZ0001
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
    touchpad_vec.push_back(*this);
    std::ofstream file_out("../txt_files/touchpad.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Touchpad& tpad: touchpad_vec){
        file_out << tpad.getID() << "|";
        file_out << tpad.getDescription() << "|";
        file_out << tpad.getBrand() << "|";
        file_out << tpad.getModel() << "|";
        file_out << tpad.getPrice() << "|";
        file_out << tpad.getQuantity() << "|";
        file_out << tpad.getOnDisplay() << "|";
        file_out << tpad.getType() << "|";
        file_out << std::get<0>(tpad.getDimensions()) << "|";
        file_out << std::get<1>(tpad.getDimensions()) << "|";
        file_out << tpad.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Touchpad::updateVec(const Touchpad tp_in){
    for (Touchpad& tpad: touchpad_vec){
        if (tpad.getID() == tp_in.getID()){
            tpad.setDescription(tp_in.getDescription());
            tpad.setBrand(tp_in.getBrand());
            tpad.setModel(tp_in.getModel());
            tpad.setPrice(tp_in.getPrice());
            tpad.setQuantity(tp_in.getQuantity());
            tpad.setOnDisplay(tp_in.getOnDisplay());
            tpad.setType(tp_in.getType());
            tpad.setDimensions(std::get<0>(tp_in.getDimensions()), std::get<1>(tp_in.getDimensions()));
            tpad.setImagePath(tp_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/touchpad.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Touchpad& tpad: touchpad_vec){
        file_out << tpad.getID() << "|";
        file_out << tpad.getDescription() << "|";
        file_out << tpad.getBrand() << "|";
        file_out << tpad.getModel() << "|";
        file_out << tpad.getPrice() << "|";
        file_out << tpad.getQuantity() << "|";
        file_out << tpad.getOnDisplay() << "|";
        file_out << tpad.getType() << "|";
        file_out << std::get<0>(tpad.getDimensions()) << "|";
        file_out << std::get<1>(tpad.getDimensions()) << "|";
        file_out << tpad.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Touchpad::readData(){
    std::ifstream file_in("../txt_files/touchpad.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        file_in.close();
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string length;
    std::string width;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &length, &width, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Touchpad tpad("a");
        tpad.setID(id);
        tpad.setDescription(description);
        tpad.setBrand(brand);
        tpad.setModel(model);
        tpad.setPrice(std::stod(price));
        tpad.setQuantity(std::stoi(quantity));
        tpad.setOnDisplay(std::stoi(on_display));
        tpad.setType(type);
        tpad.setDimensions(std::stod(length), std::stod(width));
        tpad.setImagePath(image_path);
        touchpad_vec.push_back(tpad);
    }    
    file_in.close();
    return;
}

void Touchpad::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Touchpad> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Dimensions" << std::endl;
        std::cout << "3. Filter Brand" << std::endl;
        std::cout << "4. Filter Type" << std::endl;
        std::cout << "5. Filter for sale" << std::endl; 
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 5 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 5: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortDimensions();
        } else if (sort_option == 3){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 4){
            std::cout << "Enter type: ";
            std::getline(std::cin, filter_input);
            filtered = filterType(filter_input);
        } else if (sort_option == 5){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 3){
            for (const Touchpad touchpad: touchpad_vec){
                std::cout << touchpad;
                switch (sort_option)
                {
                case 2:
                    std::cout << "Area: " << std::get<0>(touchpad.getDimensions()) * std::get<1>(touchpad.getDimensions()) << std::endl;                    
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Touchpad touchpad: filtered){
                std::cout << touchpad << std::endl;
            }
        }
    }
    return;
}

void Touchpad::sortPrice(){
    std::sort(touchpad_vec.begin(), touchpad_vec.end(), [](const Touchpad& a, const Touchpad& b){
        return a.getPrice() < b.getPrice();
    });
}

void Touchpad::sortDimensions(){
    std::sort(touchpad_vec.begin(), touchpad_vec.end(), [](const Touchpad& a, const Touchpad& b){
        return std::get<0>(a.getDimensions()) * std::get<1>(a.getDimensions()) < std::get<0>(b.getDimensions()) * std::get<1>(b.getDimensions());
    });
}

std::vector<Touchpad> Touchpad::filterBrand(const std::string brand){
    std::vector<Touchpad> filtered;
    for (const Touchpad tpad: touchpad_vec){
        if (tpad.getBrand() == brand){
            filtered.push_back(tpad);
        }
    }
    return filtered;
}

std::vector<Touchpad> Touchpad::filterType(const std::string type){
    std::vector<Touchpad> filtered;
    for (const Touchpad tpad: touchpad_vec){
        if (tpad.getType() == type){
            filtered.push_back(tpad);
        }
    }
    return filtered;
}

std::vector<Touchpad> Touchpad::filterOnDisplay(){
    std::vector<Touchpad> filtered;
    for (const Touchpad tpad: touchpad_vec){
        if (tpad.getOnDisplay() == 1){
            filtered.push_back(tpad);
        }
    }
    return filtered;
}

Touchpad& Touchpad::operator=(const Touchpad& tp_in){
    setID(tp_in.getID());
    setDescription(tp_in.getDescription());
    setBrand(tp_in.getBrand());
    setModel(tp_in.getModel());
    setPrice(tp_in.getPrice());
    setQuantity(tp_in.getQuantity());
    setOnDisplay(tp_in.getOnDisplay());
    setType(tp_in.getType());
    setDimensions(std::get<0>(tp_in.getDimensions()), std::get<1>(tp_in.getDimensions()));
    setImagePath(tp_in.getImagePath());
    return *this;
}