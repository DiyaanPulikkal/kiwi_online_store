#include "motherboard.h"

Motherboard::Motherboard() : ComputerParts(){
    form_factor = "-";
    socket = "-";
    memory = std::make_tuple("-", 0);
    chipset = "-";
    expansion_slots = {};
    connectivity = {};
    storage = {};
    audio = "-";
    multi_gpu = false;
    bios = "-";
    generateId();
}

Motherboard::Motherboard(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    socket = "-";
    memory = std::make_tuple("-", 0);
    chipset = "-";
    expansion_slots = {};
    connectivity = {};
    storage = {};
    audio = "-";
    multi_gpu = false;
    bios = "-";
    generateId();
}

Motherboard::Motherboard(const std::string s) : ComputerParts(){
    form_factor = s;
    socket = "-";
    memory = std::make_tuple("-", 0);
    chipset = "-";
    expansion_slots = {};
    connectivity = {};
    storage = {};
    audio = "-";
    multi_gpu = false;
    bios = "-";
}

void Motherboard::setFormFactor(const std::string ff){
    form_factor = ff;
}

void Motherboard::setSocket(const std::string s){
    socket = s;
}

void Motherboard::setMemory(const std::string t, const int c){
    memory = std::make_tuple(t, c);
}

void Motherboard::setChipset(const std::string c){
    chipset = c;
}

void Motherboard::addExpansionSlots(const std::string es){
    expansion_slots.push_back(es);
}

void Motherboard::clearExpansionSlots(){
    expansion_slots.clear();
}

void Motherboard::addConnectivity(const std::string c){
    connectivity.push_back(c);
}

void Motherboard::clearConnectivity(){
    connectivity.clear();
}

void Motherboard::addStorage(const std::string t){
    storage.push_back(t);
}

void Motherboard::clearStorage(){
    storage.clear();
}

void Motherboard::setAudio(const std::string a){
    audio = a;
}

void Motherboard::setMultiGPU(const bool mg){
    multi_gpu = mg;
}

void Motherboard::setBios(const std::string b){
    bios = b;
}

std::string Motherboard::getFormFactor() const{
    return form_factor;
}

std::string Motherboard::getSocket() const{
    return socket;
}

std::tuple<std::string, int> Motherboard::getMemory() const{
    return memory;
}

std::string Motherboard::getChipset() const{
    return chipset;
}

std::vector<std::string> Motherboard::getExpansionSlots() const{
    return expansion_slots;
}

std::vector<std::string> Motherboard::getConnectivity() const{
    return connectivity;
}

std::vector<std::string> Motherboard::getStorage() const{
    return storage;
}

std::string Motherboard::getAudio() const{
    return audio;
}

bool Motherboard::getMultiGPU() const{
    return multi_gpu;
}

std::string Motherboard::getBios() const{
    return bios;
}

void Motherboard::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Motherboard::generateId(){
    std::ifstream file_in("../txt_files/motherboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Motherboard& motb: motherboard_vec){
            std::string id = motb.getID(); // AZ0001
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
    motherboard_vec.push_back(*this);
    std::ofstream file_out("../txt_files/motherboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Motherboard& motb: motherboard_vec){
        file_out << motb.getID() << "|";
        file_out << motb.getDescription() << "|";
        file_out << motb.getBrand() << "|";
        file_out << motb.getModel() << "|";
        file_out << motb.getPrice() << "|";
        file_out << motb.getQuantity() << "|";
        file_out << motb.getOnDisplay() << "|";
        file_out << motb.getFormFactor() << "|";
        file_out << motb.getSocket() << "|";
        file_out << std::get<0>(motb.getMemory()) << "|";
        file_out << std::get<1>(motb.getMemory()) << "|";
        file_out << motb.getChipset() << "|";
        for (std::string es: motb.getExpansionSlots()){
            file_out << es << ",";
        }
        file_out << "|";
        for (std::string c: motb.getConnectivity()){
            file_out << c << ",";
        }
        file_out << "|";
        for (std::string s: motb.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << motb.getAudio() << "|";
        file_out << motb.getMultiGPU() << "|";
        file_out << motb.getBios() << "|";
        file_out << motb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Motherboard::updateVec(const Motherboard mb_in){
    for (Motherboard& motb: motherboard_vec){
        if (motb.getID() == mb_in.getID()){
            motb.setDescription(mb_in.getDescription());
            motb.setBrand(mb_in.getBrand());
            motb.setModel(mb_in.getModel());
            motb.setPrice(mb_in.getPrice());
            motb.setQuantity(mb_in.getQuantity());
            motb.setOnDisplay(mb_in.getOnDisplay());
            motb.setFormFactor(mb_in.getFormFactor());
            motb.setSocket(mb_in.getSocket());
            motb.setMemory(std::get<0>(mb_in.getMemory()), std::get<1>(mb_in.getMemory()));
            motb.setChipset(mb_in.getChipset());
            motb.clearExpansionSlots();
            for (std::string es: mb_in.getExpansionSlots()){
                motb.addExpansionSlots(es);
            }
            motb.clearConnectivity();
            for (std::string c: mb_in.getConnectivity()){
                motb.addConnectivity(c);
            }
            motb.clearStorage();
            for (std::string s: mb_in.getStorage()){
                motb.addStorage(s);
            }
            motb.setAudio(mb_in.getAudio());
            motb.setMultiGPU(mb_in.getMultiGPU());
            motb.setBios(mb_in.getBios());
            motb.setImagePath(mb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/motherboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Motherboard& motb: motherboard_vec){
        file_out << motb.getID() << "|";
        file_out << motb.getDescription() << "|";
        file_out << motb.getBrand() << "|";
        file_out << motb.getModel() << "|";
        file_out << motb.getPrice() << "|";
        file_out << motb.getQuantity() << "|";
        file_out << motb.getOnDisplay() << "|";
        file_out << motb.getFormFactor() << "|";
        file_out << motb.getSocket() << "|";
        file_out << std::get<0>(motb.getMemory()) << "|";
        file_out << std::get<1>(motb.getMemory()) << "|";
        file_out << motb.getChipset() << "|";
        for (std::string es: motb.getExpansionSlots()){
            file_out << es << ",";
        }
        file_out << "|";
        for (std::string c: motb.getConnectivity()){
            file_out << c << ",";
        }
        file_out << "|";
        for (std::string s: motb.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << motb.getAudio() << "|";
        file_out << motb.getMultiGPU() << "|";
        file_out << motb.getBios() << "|";
        file_out << motb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Motherboard::readData(){
    std::ifstream file_in("../txt_files/motherboard.txt", std::ios::in);
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
    std::string socket;
    std::string memory_type;
    std::string memory_capacity;
    std::string chipset;
    std::string expansion_slots;
    std::string connectivity;
    std::string storage;
    std::string audio;
    std::string multi_gpu;
    std::string bios;
    std::string image_path;
    std::array<std::string*, 19> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &form_factor, &socket, &memory_type, &memory_capacity, &chipset, &expansion_slots, &connectivity, &storage, &audio, &multi_gpu, &bios, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Motherboard motb("a");
        motb.setID(id);
        motb.setDescription(description);
        motb.setBrand(brand);
        motb.setModel(model);
        motb.setPrice(std::stod(price));
        motb.setQuantity(std::stoi(quantity));
        motb.setOnDisplay(std::stoi(on_display));
        motb.setFormFactor(form_factor);
        motb.setSocket(socket);
        motb.setMemory(memory_type, std::stoi(memory_capacity));
        motb.setChipset(chipset);
        std::istringstream es_stream(expansion_slots);
        std::string es;
        while (std::getline(es_stream, es, ',')){
            motb.addExpansionSlots(es);
        }
        std::istringstream c_stream(connectivity);
        std::string c;
        while (std::getline(c_stream, c, ',')){
            motb.addConnectivity(c);
        }
        std::istringstream s_stream(storage);
        std::string s;
        while (std::getline(s_stream, s, ',')){
            motb.addStorage(s);
        }
        motb.setAudio(audio);
        motb.setMultiGPU(std::stoi(multi_gpu));
        motb.setBios(bios);
        motb.setImagePath(image_path);
        motherboard_vec.push_back(motb);
    }
    file_in.close();
    return;
}

void Motherboard::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Motherboard> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter Form Factor" << std::endl;
        std::cout << "4. Filter Socket" << std::endl;
        std::cout << "5. Filter Chipset" << std::endl;
        std::cout << "6. Filter Expansion Slots" << std::endl;
        std::cout << "7. Filter Connectivity" << std::endl;
        std::cout << "8. Filter Multi-GPU" << std::endl;
        std::cout << "9. Filter On Display" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "option number: ";
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
            std::cout << "Enter Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 3){
            std::cout << "Enter Form Factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 4){
            std::cout << "Enter Socket: ";
            std::getline(std::cin, filter_input);
            filtered = filterSocket(filter_input);
        } else if (sort_option == 5){
            std::cout << "Enter Chipset: ";
            std::getline(std::cin, filter_input);
            filtered = filterChipset(filter_input);
        } else if (sort_option == 6){
            std::cout << "Enter Expansion Slots: ";
            std::getline(std::cin, filter_input);
            filtered = filterExpansionSlots(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter Connectivity: ";
            std::getline(std::cin, filter_input);
            filtered = filterConnectivity(filter_input);
        } else if (sort_option == 8){
            std::cout << "Enter Multi-GPU (0/1): ";
            std::getline(std::cin, filter_input);
            while (true){
                try{
                    if (filter_input != "0" && filter_input != "1"){
                        throw std::invalid_argument("");
                    }
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 0 or 1: ";
                    std::getline(std::cin, filter_input);
                }
            }
            filtered = filterMultiGPU(std::stoi(filter_input));
        } else if (sort_option == 9){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (Motherboard motb: motherboard_vec){
                std::cout << motb << std::endl;
            }
        } else {
            for (Motherboard motb: filtered){
                std::cout << motb << std::endl;
            }
        }
    }
    return;
}

void Motherboard::sortPrice(){
    std::sort(motherboard_vec.begin(), motherboard_vec.end(), [](Motherboard a, Motherboard b){
        return a.getPrice() < b.getPrice();
    });
}

std::vector<Motherboard> Motherboard::filterBrand(const std::string brand){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getBrand() == brand){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterFormFactor(const std::string form_factor){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getFormFactor() == form_factor){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterSocket(const std::string socket){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getSocket() == socket){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterChipset(const std::string chipset){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getChipset() == chipset){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterExpansionSlots(const std::string expansion_slots){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        for (std::string es: motb.getExpansionSlots()){
            if (es == expansion_slots){
                filtered.push_back(motb);
                break;
            }
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterConnectivity(const std::string connectivity){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        for (std::string c: motb.getConnectivity()){
            if (c == connectivity){
                filtered.push_back(motb);
                break;
            }
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterMultiGPU(const bool multi_gpu){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getMultiGPU() == multi_gpu){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

std::vector<Motherboard> Motherboard::filterOnDisplay(){
    std::vector<Motherboard> filtered;
    for (Motherboard motb: motherboard_vec){
        if (motb.getOnDisplay()){
            filtered.push_back(motb);
        }
    }
    return filtered;
}

Motherboard& Motherboard::operator=(const Motherboard& mb){
    setID(mb.getID());
    setDescription(mb.getDescription());
    setBrand(mb.getBrand());
    setModel(mb.getModel());
    setPrice(mb.getPrice());
    setQuantity(mb.getQuantity());
    setOnDisplay(mb.getOnDisplay());
    setFormFactor(mb.getFormFactor());
    setSocket(mb.getSocket());
    setMemory(std::get<0>(mb.getMemory()), std::get<1>(mb.getMemory()));
    setChipset(mb.getChipset());
    clearExpansionSlots();
    for (std::string es: mb.getExpansionSlots()){
        addExpansionSlots(es);
    }
    clearConnectivity();
    for (std::string c: mb.getConnectivity()){
        addConnectivity(c);
    }
    clearStorage();
    for (std::string s: mb.getStorage()){
        addStorage(s);
    }
    setAudio(mb.getAudio());
    setMultiGPU(mb.getMultiGPU());
    setBios(mb.getBios());
    setImagePath(mb.getImagePath());
    return *this;
}