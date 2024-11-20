#include "portable_hdd.h"

Portable_HDD::Portable_HDD(): Peripherals() {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    dimensions = std::make_tuple(0, 0, 0);
    weight = 0;
    generateId();
}

Portable_HDD::Portable_HDD(int q, double p) : Peripherals(q, p) {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    dimensions = std::make_tuple(0, 0, 0);
    weight = 0;
}

Portable_HDD::Portable_HDD(const std::string s) : Peripherals() {
    capacity = 0;
    interface = "-";
    transfer_speed = 0;
    dimensions = std::make_tuple(0, 0, 0);
    weight = 0;
}

void Portable_HDD::setCapacity(int c) {
    capacity = c;
}

void Portable_HDD::setInterface(std::string i) {
    interface = i;
}

void Portable_HDD::setTransferSpeed(double ts) {
    transfer_speed = ts;
}

void Portable_HDD::setDimensions(double l, double w, double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Portable_HDD::setWeight(double w) {
    weight = w;
}

int Portable_HDD::getCapacity() const {
    return capacity;
}

std::string Portable_HDD::getInterface() const {
    return interface;
}

double Portable_HDD::getTransferSpeed() const {
    return transfer_speed;
}

std::tuple<double, double, double> Portable_HDD::getDimensions() const {
    return dimensions;
}

double Portable_HDD::getWeight() const {
    return weight;
}

void Portable_HDD::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Portable_HDD::generateId() {
    std::ifstream file_in("../txt_files/portable_hdd.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Portable_HDD& p_hdd: portable_hdd_vec){
            std::string id = p_hdd.getID(); // AZ0001
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
    portable_hdd_vec.push_back(*this);
    std::ofstream file_out("../txt_files/portable_hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Portable_HDD& p_hdd: portable_hdd_vec){
        file_out << p_hdd.getID() << "|";
        file_out << p_hdd.getDescription() << "|";
        file_out << p_hdd.getBrand() << "|";
        file_out << p_hdd.getModel() << "|";
        file_out << p_hdd.getPrice() << "|";
        file_out << p_hdd.getQuantity() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getCapacity() << "|";
        file_out << p_hdd.getInterface() << "|";
        file_out << p_hdd.getTransferSpeed() << "|";
        file_out << std::get<0>(p_hdd.getDimensions()) << "|";
        file_out << std::get<1>(p_hdd.getDimensions()) << "|";
        file_out << std::get<2>(p_hdd.getDimensions()) << "|";
        file_out << p_hdd.getWeight() << "|";
        file_out << p_hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Portable_HDD::updateVec(const Portable_HDD p_hdd_in){
    for (Portable_HDD& p_hdd: portable_hdd_vec){
        if (p_hdd.getID() == p_hdd_in.getID()){
            p_hdd.setDescription(p_hdd_in.getDescription());
            p_hdd.setBrand(p_hdd_in.getBrand());
            p_hdd.setModel(p_hdd_in.getModel());
            p_hdd.setPrice(p_hdd_in.getPrice());
            p_hdd.setQuantity(p_hdd_in.getQuantity());
            p_hdd.setOnDisplay(p_hdd_in.getOnDisplay());
            p_hdd.setCapacity(p_hdd_in.getCapacity());
            p_hdd.setInterface(p_hdd_in.getInterface());
            p_hdd.setTransferSpeed(p_hdd_in.getTransferSpeed());
            p_hdd.setDimensions(std::get<0>(p_hdd_in.getDimensions()), std::get<1>(p_hdd_in.getDimensions()), std::get<2>(p_hdd_in.getDimensions()));
            p_hdd.setWeight(p_hdd_in.getWeight());
            p_hdd.setImagePath(p_hdd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/portable_hdd.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Portable_HDD& p_hdd: portable_hdd_vec){
        file_out << p_hdd.getID() << "|";
        file_out << p_hdd.getDescription() << "|";
        file_out << p_hdd.getBrand() << "|";
        file_out << p_hdd.getModel() << "|";
        file_out << p_hdd.getPrice() << "|";
        file_out << p_hdd.getQuantity() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getOnDisplay() << "|";
        file_out << p_hdd.getCapacity() << "|";
        file_out << p_hdd.getInterface() << "|";
        file_out << p_hdd.getTransferSpeed() << "|";
        file_out << std::get<0>(p_hdd.getDimensions()) << "|";
        file_out << std::get<1>(p_hdd.getDimensions()) << "|";
        file_out << std::get<2>(p_hdd.getDimensions()) << "|";
        file_out << p_hdd.getWeight() << "|";
        file_out << p_hdd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Portable_HDD::readData(){
    std::ifstream file_in("../txt_files/portable_hdd.txt", std::ios::in);
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
    std::string length;
    std::string width;
    std::string height;
    std::string weight;
    std::string image_path;
    std::array<std::string*, 15> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &capacity, &interface, &transfer_speed, &length, &width, &height, &weight, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Portable_HDD p_hdd("a");
        p_hdd.setID(id);
        p_hdd.setDescription(description);
        p_hdd.setBrand(brand);
        p_hdd.setModel(model);
        p_hdd.setPrice(std::stod(price));
        p_hdd.setQuantity(std::stoi(quantity));
        p_hdd.setOnDisplay(std::stoi(on_display));
        p_hdd.setCapacity(std::stoi(capacity));
        p_hdd.setInterface(interface);
        p_hdd.setTransferSpeed(std::stod(transfer_speed));
        p_hdd.setDimensions(std::stod(length), std::stod(width), std::stod(height));
        p_hdd.setWeight(std::stod(weight));
        p_hdd.setImagePath(image_path);
        portable_hdd_vec.push_back(p_hdd);
    }
    file_in.close();
    return;    
}

void Portable_HDD::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Portable_HDD> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Transfer Speed" << std::endl;
        std::cout << "4. Dimensions" << std::endl;
        std::cout << "5. Weight" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter Interface" << std::endl;
        std::cout << "8. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 8 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 8: " << std::endl;
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
            sortDimensions();
        } else if (sort_option == 5){
            sortWeight();
        } else if (sort_option == 6){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter interface: ";
            std::getline(std::cin, filter_input);
            filtered = filterInterface(filter_input);
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const Portable_HDD portable_hdd: portable_hdd_vec){
                std::cout << portable_hdd;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Capacity: " << portable_hdd.getCapacity() << " GB" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Transfer Speed: " << portable_hdd.getTransferSpeed() << " MB/s" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Dimensions: " << std::get<0>(portable_hdd.getDimensions()) << " x " << std::get<1>(portable_hdd.getDimensions()) << " x " << std::get<2>(portable_hdd.getDimensions()) << " mm" << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Weight: " << portable_hdd.getWeight() << " g" << std::endl;
                    break;
                
                default:
                std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Portable_HDD portable_hdd: filtered){
                std::cout << portable_hdd << std::endl;
            }
        }
    }
    return;
}

void Portable_HDD::sortPrice(){
    std::sort(portable_hdd_vec.begin(), portable_hdd_vec.end(), [](const Portable_HDD& p_hdd1, const Portable_HDD& p_hdd2){
        return p_hdd1.getPrice() < p_hdd2.getPrice();
    });
    return;
}

void Portable_HDD::sortCapacity(){
    std::sort(portable_hdd_vec.begin(), portable_hdd_vec.end(), [](const Portable_HDD& p_hdd1, const Portable_HDD& p_hdd2){
        return p_hdd1.getCapacity() < p_hdd2.getCapacity();
    });
    return;
}

void Portable_HDD::sortTransferSpeed(){
    std::sort(portable_hdd_vec.begin(), portable_hdd_vec.end(), [](const Portable_HDD& p_hdd1, const Portable_HDD& p_hdd2){
        return p_hdd1.getTransferSpeed() < p_hdd2.getTransferSpeed();
    });
    return;
}

void Portable_HDD::sortDimensions(){
    std::sort(portable_hdd_vec.begin(), portable_hdd_vec.end(), [](const Portable_HDD& p_hdd1, const Portable_HDD& p_hdd2){
        return std::get<0>(p_hdd1.getDimensions()) < std::get<0>(p_hdd2.getDimensions());
    });
    return;
}

void Portable_HDD::sortWeight(){
    std::sort(portable_hdd_vec.begin(), portable_hdd_vec.end(), [](const Portable_HDD& p_hdd1, const Portable_HDD& p_hdd2){
        return p_hdd1.getWeight() < p_hdd2.getWeight();
    });
    return;
}

std::vector<Portable_HDD> Portable_HDD::filterBrand(const std::string brand){
    std::vector<Portable_HDD> filtered;
    for (const Portable_HDD p_hdd: portable_hdd_vec){
        if (p_hdd.getBrand() == brand){
            filtered.push_back(p_hdd);
        }
    }
    return filtered;
}

std::vector<Portable_HDD> Portable_HDD::filterInterface(const std::string interf){
    std::vector<Portable_HDD> filtered;
    for (const Portable_HDD p_hdd: portable_hdd_vec){
        if (p_hdd.getInterface() == interf){
            filtered.push_back(p_hdd);
        }
    }
    return filtered;
}

std::vector<Portable_HDD> Portable_HDD::filterOnDisplay(){
    std::vector<Portable_HDD> filtered;
    for (const Portable_HDD p_hdd: portable_hdd_vec){
        if (p_hdd.getOnDisplay()){
            filtered.push_back(p_hdd);
        }
    }
    return filtered;
}

Portable_HDD& Portable_HDD::operator=(const Portable_HDD& p_hdd){
    setID(p_hdd.getID());
    setDescription(p_hdd.getDescription());
    setBrand(p_hdd.getBrand());
    setModel(p_hdd.getModel());
    setPrice(p_hdd.getPrice());
    setQuantity(p_hdd.getQuantity());
    setOnDisplay(p_hdd.getOnDisplay());
    setCapacity(p_hdd.getCapacity());
    setInterface(p_hdd.getInterface());
    setTransferSpeed(p_hdd.getTransferSpeed());
    setDimensions(std::get<0>(p_hdd.getDimensions()), std::get<1>(p_hdd.getDimensions()), std::get<2>(p_hdd.getDimensions()));
    setWeight(p_hdd.getWeight());
    setImagePath(p_hdd.getImagePath());
    return *this;
}