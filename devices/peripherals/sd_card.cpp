#include "sd_card.h"

SdCard::SdCard(): Peripherals(){
    type = "-";
    capacity = 0;
    speed = 0;
    class_rating = "-";
    form_factor = "-";
    generateId();
}

SdCard::SdCard(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    capacity = 0;
    speed = 0;
    class_rating = "-";
    form_factor = "-";
    generateId();
}

SdCard::SdCard(const std::string s) : Peripherals() {
    type = "-";
    capacity = 0;
    speed = 0;
    class_rating = "-";
    form_factor = "-";
}

void SdCard::setType(const std::string t) {
    type = t;
}

void SdCard::setCapacity(const unsigned int c) {
    capacity = c;
}

void SdCard::setSpeed(const unsigned int s) {
    speed = s;
}

void SdCard::setClassRating(const std::string cr) {
    class_rating = cr;
}

void SdCard::setFormFactor(const std::string ff) {
    form_factor = ff;
}

std::string SdCard::getType() const {
    return type;
}

int SdCard::getCapacity() const {
    return capacity;
}

int SdCard::getSpeed() const {
    return speed;
}

std::string SdCard::getClassRating() const {
    return class_rating;
}

std::string SdCard::getFormFactor() const {
    return form_factor;
}

void SdCard::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void SdCard::generateId() {
    std::ifstream file_in("../txt_files/sd_card.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const SdCard& sd: sd_card_vec){
            std::string id = sd.getID(); // AZ0001
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
    sd_card_vec.push_back(*this);
    std::ofstream file_out("../txt_files/sd_card.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const SdCard& sd: sd_card_vec){
        file_out << sd.getID() << "|";
        file_out << sd.getDescription() << "|";
        file_out << sd.getBrand() << "|";
        file_out << sd.getModel() << "|";
        file_out << sd.getPrice() << "|";
        file_out << sd.getQuantity() << "|";
        file_out << sd.getOnDisplay() << "|";
        file_out << sd.getType() << "|";
        file_out << sd.getCapacity() << "|";
        file_out << sd.getSpeed() << "|";
        file_out << sd.getClassRating() << "|";
        file_out << sd.getFormFactor() << "|";
        file_out << sd.getImagePath();
    }
    file_out.close();
    return;
}

void SdCard::updateVec(const SdCard sd_in){
    for (SdCard& sd: sd_card_vec){
        if (sd.getID() == sd_in.getID()){
            sd.setDescription(sd_in.getDescription());
            sd.setBrand(sd_in.getBrand());
            sd.setModel(sd_in.getModel());
            sd.setPrice(sd_in.getPrice());
            sd.setQuantity(sd_in.getQuantity());
            sd.setOnDisplay(sd_in.getOnDisplay());
            sd.setType(sd_in.getType());
            sd.setCapacity(sd_in.getCapacity());
            sd.setSpeed(sd_in.getSpeed());
            sd.setClassRating(sd_in.getClassRating());
            sd.setFormFactor(sd_in.getFormFactor());
            sd.setImagePath(sd_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/sd_card.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const SdCard& sd: sd_card_vec){
        file_out << sd.getID() << "|";
        file_out << sd.getDescription() << "|";
        file_out << sd.getBrand() << "|";
        file_out << sd.getModel() << "|";
        file_out << sd.getPrice() << "|";
        file_out << sd.getQuantity() << "|";
        file_out << sd.getOnDisplay() << "|";
        file_out << sd.getType() << "|";
        file_out << sd.getCapacity() << "|";
        file_out << sd.getSpeed() << "|";
        file_out << sd.getClassRating() << "|";
        file_out << sd.getFormFactor() << "|";
        file_out << sd.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void SdCard::readData() {
    std::ifstream file_in("../txt_files/sd_card.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string capacity;
    std::string speed;
    std::string class_rating;
    std::string form_factor;
    std::string image_path;
    std::array<std::string*, 13> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &capacity, &speed, &class_rating, &form_factor, &image_path};

    std::string row;
    while (std::getline(file_in, row)) {
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        SdCard sd("a");
        sd.setID(id);
        sd.setDescription(description);
        sd.setBrand(brand);
        sd.setModel(model);
        sd.setPrice(std::stod(price));
        sd.setQuantity(std::stoi(quantity));
        sd.setOnDisplay(std::stoi(on_display));
        sd.setType(type);
        sd.setCapacity(std::stoi(capacity));
        sd.setSpeed(std::stoi(speed));
        sd.setClassRating(class_rating);
        sd.setFormFactor(form_factor);
        sd.setImagePath(image_path);
        sd_card_vec.push_back(sd);        
    }
    file_in.close();
    return;
}

void SdCard::selectSortFilter() {
    unsigned int sort_option;
    std::string filter_input;
    std::vector<SdCard> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Capacity" << std::endl;
        std::cout << "3. Speed" << std::endl;
        std::cout << "4. Filter Brand" << std::endl;
        std::cout << "5. Filter Type" << std::endl;
        std::cout << "6. Filter Class Rating" << std::endl;
        std::cout << "7. Filter Form Factor" << std::endl;
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
            sortSpeed();
        } else if (sort_option == 4){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 5){
            std::cout << "Enter type: ";
            std::getline(std::cin, filter_input);
            filtered = filterType(filter_input);
        } else if (sort_option == 6){
            std::cout << "Enter class rating: ";
            std::getline(std::cin, filter_input);
            filtered = filterClassRating(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter form factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 4){
            for (const SdCard sdcard: sd_card_vec){
                std::cout << sdcard;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Capacity: " << sdcard.getCapacity() << "GB" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Speed: " << sdcard.getSpeed() << "MB/s" << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const SdCard sdcard: filtered){
                std::cout << sdcard << std::endl;
            }
        }
    }
    return;
}

void SdCard::sortPrice() {
    std::sort(sd_card_vec.begin(), sd_card_vec.end(), [](const SdCard& sd1, const SdCard& sd2){
        return sd1.getPrice() < sd2.getPrice();
    });
}

void SdCard::sortCapacity() {
    std::sort(sd_card_vec.begin(), sd_card_vec.end(), [](const SdCard& sd1, const SdCard& sd2){
        return sd1.getCapacity() < sd2.getCapacity();
    });
}

void SdCard::sortSpeed() {
    std::sort(sd_card_vec.begin(), sd_card_vec.end(), [](const SdCard& sd1, const SdCard& sd2){
        return sd1.getSpeed() < sd2.getSpeed();
    });
}

std::vector<SdCard> SdCard::filterBrand(const std::string b) {
    std::vector<SdCard> filtered;
    for (const SdCard sd: sd_card_vec){
        if (sd.getBrand() == b){
            filtered.push_back(sd);
        }
    }
    return filtered;
}

std::vector<SdCard> SdCard::filterType(const std::string t) {
    std::vector<SdCard> filtered;
    for (const SdCard sd: sd_card_vec){
        if (sd.getType() == t){
            filtered.push_back(sd);
        }
    }
    return filtered;
}

std::vector<SdCard> SdCard::filterClassRating(const std::string cr) {
    std::vector<SdCard> filtered;
    for (const SdCard sd: sd_card_vec){
        if (sd.getClassRating() == cr){
            filtered.push_back(sd);
        }
    }
    return filtered;
}

std::vector<SdCard> SdCard::filterFormFactor(const std::string ff) {
    std::vector<SdCard> filtered;
    for (const SdCard sd: sd_card_vec){
        if (sd.getFormFactor() == ff){
            filtered.push_back(sd);
        }
    }
    return filtered;
}

std::vector<SdCard> SdCard::filterOnDisplay() {
    std::vector<SdCard> filtered;
    for (const SdCard sd: sd_card_vec){
        if (sd.getOnDisplay()){
            filtered.push_back(sd);
        }
    }
    return filtered;
}

SdCard& SdCard::operator=(const SdCard& sd_in) {
    setID(sd_in.getID());
    setDescription(sd_in.getDescription());
    setBrand(sd_in.getBrand());
    setModel(sd_in.getModel());
    setPrice(sd_in.getPrice());
    setQuantity(sd_in.getQuantity());
    setOnDisplay(sd_in.getOnDisplay());
    setType(sd_in.getType());
    setCapacity(sd_in.getCapacity());
    setSpeed(sd_in.getSpeed());
    setClassRating(sd_in.getClassRating());
    setFormFactor(sd_in.getFormFactor());
    setImagePath(sd_in.getImagePath());
    return *this;
}