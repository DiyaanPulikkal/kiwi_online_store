#include "pc_case.h"

PCCase::PCCase(): ComputerParts(){
    form_factor = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    cooling_type = "-";
    max_gpu_length = 0.0;
    max_cpu_height = 0.0;
    fan_support = {};
    generateId();
}

PCCase::PCCase(const int q, const double p) : ComputerParts(q, p){
    form_factor = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    cooling_type = "-";
    max_gpu_length = 0.0;
    max_cpu_height = 0.0;
    fan_support = {};
    generateId();
}

PCCase::PCCase(const std::string s) : ComputerParts(){
    form_factor = s;
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    cooling_type = "-";
    max_gpu_length = 0.0;
    max_cpu_height = 0.0;
    fan_support = {};
}

void PCCase::setFormFactor(const std::string ff){
    form_factor = ff;
}

void PCCase::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

void PCCase::setCoolingType(const std::string ct){
    cooling_type = ct;
}

void PCCase::setMaxGPULength(const double mgl){
    max_gpu_length = mgl;
}

void PCCase::setMaxCPUHeight(const double mch){
    max_cpu_height = mch;
}

void PCCase::setFanSupport(const int pos, const std::string fs, const int q){
    fan_support[pos] = std::make_tuple(fs, q);
}

std::string PCCase::getFormFactor() const{
    return form_factor;
}

std::tuple<double, double, double> PCCase::getDimension() const{
    return dimension;
}

std::string PCCase::getCoolingType() const{
    return cooling_type;
}

double PCCase::getMaxGPULength() const{
    return max_gpu_length;
}

double PCCase::getMaxCPUHeight() const{
    return max_cpu_height;
}

std::array<std::tuple<std::string, int>, 3> PCCase::getFanSupport() const{
    return fan_support;
}

void PCCase::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void PCCase::generateId(){
    std::ifstream file_in("../txt_files/pc_case.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const PCCase& pc_case: pc_case_vec){
            std::string id = pc_case.getID(); // AZ0001
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
    pc_case_vec.push_back(*this);
    std::ofstream file_out("../txt_files/pc_case.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PCCase& pc_case: pc_case_vec){
        file_out << pc_case.getID() << "|";
        file_out << pc_case.getDescription() << "|";
        file_out << pc_case.getBrand() << "|";
        file_out << pc_case.getModel() << "|";
        file_out << pc_case.getPrice() << "|";
        file_out << pc_case.getQuantity() << "|";
        file_out << pc_case.getOnDisplay() << "|";
        file_out << pc_case.getFormFactor() << "|";
        file_out << std::get<0>(pc_case.getDimension()) << ",";
        file_out << std::get<1>(pc_case.getDimension()) << ",";
        file_out << std::get<2>(pc_case.getDimension()) << "|";
        file_out << pc_case.getCoolingType() << "|";
        file_out << pc_case.getMaxGPULength() << "|";
        file_out << pc_case.getMaxCPUHeight() << "|";
        for (std::tuple<std::string, int> fs: pc_case.getFanSupport()){
            file_out << std::get<0>(fs) << "|";
            file_out << std::get<1>(fs) << "|";
        }
        file_out << pc_case.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PCCase::updateVec(const PCCase case_in){
    for (PCCase& pc_case: pc_case_vec){
        if (pc_case.getID() == case_in.getID()){
            pc_case.setDescription(case_in.getDescription());
            pc_case.setBrand(case_in.getBrand());
            pc_case.setModel(case_in.getModel());
            pc_case.setPrice(case_in.getPrice());
            pc_case.setQuantity(case_in.getQuantity());
            pc_case.setOnDisplay(case_in.getOnDisplay());
            pc_case.setFormFactor(case_in.getFormFactor());
            pc_case.setDimension(std::get<0>(case_in.getDimension()), std::get<1>(case_in.getDimension()), std::get<2>(case_in.getDimension()));
            pc_case.setCoolingType(case_in.getCoolingType());
            pc_case.setMaxGPULength(case_in.getMaxGPULength());
            pc_case.setMaxCPUHeight(case_in.getMaxCPUHeight());
            for (int i = 0; i < 3; i++){
                pc_case.setFanSupport(i, std::get<0>(case_in.getFanSupport()[i]), std::get<1>(case_in.getFanSupport()[i]));
            }
            pc_case.setImagePath(case_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/pc_case.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const PCCase& pc_case: pc_case_vec){
        file_out << pc_case.getID() << "|";
        file_out << pc_case.getDescription() << "|";
        file_out << pc_case.getBrand() << "|";
        file_out << pc_case.getModel() << "|";
        file_out << pc_case.getPrice() << "|";
        file_out << pc_case.getQuantity() << "|";
        file_out << pc_case.getOnDisplay() << "|";
        file_out << pc_case.getFormFactor() << "|";
        file_out << std::get<0>(pc_case.getDimension()) << ",";
        file_out << std::get<1>(pc_case.getDimension()) << ",";
        file_out << std::get<2>(pc_case.getDimension()) << "|";
        file_out << pc_case.getCoolingType() << "|";
        file_out << pc_case.getMaxGPULength() << "|";
        file_out << pc_case.getMaxCPUHeight() << "|";
        for (std::tuple<std::string, int> fs: pc_case.getFanSupport()){
            file_out << std::get<0>(fs) << "|";
            file_out << std::get<1>(fs) << "|";
        }
        file_out << pc_case.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void PCCase::readData(){
    std::ifstream file_in("../txt_files/pc_case.txt", std::ios::in);
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
    std::string length, width, height;
    std::string cooling_type;
    std::string max_gpu_length;
    std::string max_cpu_height;
    std::string fan_size1;
    std::string fan_noise1;
    std::string fan_size2;
    std::string fan_noise2;
    std::string fan_size3;
    std::string fan_noise3;
    std::string image_path;
    std::array<std::string*, 21> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &form_factor, &length, &width, &height, &cooling_type, &max_gpu_length, &max_cpu_height, &fan_size1, &fan_noise1, &fan_size2, &fan_noise2, &fan_size3, &fan_noise3, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        PCCase pc_case("a");
        pc_case.setID(id);
        pc_case.setDescription(description);
        pc_case.setBrand(brand);
        pc_case.setModel(model);
        pc_case.setPrice(std::stod(price));
        pc_case.setQuantity(std::stoi(quantity));
        pc_case.setOnDisplay(std::stoi(on_display));
        pc_case.setFormFactor(form_factor);
        pc_case.setDimension(std::stod(length), std::stod(width), std::stod(height));
        pc_case.setCoolingType(cooling_type);
        pc_case.setMaxGPULength(std::stod(max_gpu_length));
        pc_case.setMaxCPUHeight(std::stod(max_cpu_height));
        pc_case.setFanSupport(0, fan_size1, std::stoi(fan_noise1));
        pc_case.setFanSupport(1, fan_size2, std::stoi(fan_noise2));
        pc_case.setFanSupport(2, fan_size3, std::stoi(fan_noise3));
        pc_case.setImagePath(image_path);
        pc_case_vec.push_back(pc_case);
    }
    file_in.close();
    return;
}

void PCCase::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<PCCase> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Dimension" << std::endl;
        std::cout << "3. Max GPU Length" << std::endl;
        std::cout << "4. Max CPU Cooler Height" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
        std::cout << "6. Filter Form Factor" << std::endl;
        std::cout << "7. Filter Cooling Type" << std::endl;
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
            sortDimension();
        } else if (sort_option == 3){
            sortMaxGPULength();
        } else if (sort_option == 4){
            sortMaxCPUHeight();
        } else if (sort_option == 5){
            std::cout << "Enter Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 6){
            std::cout << "Enter Form Factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter Cooling Type: ";
            std::getline(std::cin, filter_input);
            filtered = filterCoolingType(filter_input);
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 5){
            for (PCCase pc_case: pc_case_vec){
                std::cout << pc_case;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Dimension: " << std::get<0>(pc_case.getDimension()) << " x " << std::get<1>(pc_case.getDimension()) << " x " << std::get<2>(pc_case.getDimension()) << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Max GPU Length: " << pc_case.getMaxGPULength() << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Max CPU Cooler Height: " << pc_case.getMaxCPUHeight() << std::endl;
                    break;

                default:
                    std::cout << "      " << std::endl;
                    break;
                }
            }
        } else {
            for (PCCase pc_case: filtered){
                std::cout << pc_case << std::endl;
            }
        }
    }
    return;
}

void PCCase::sortPrice(){
    std::sort(pc_case_vec.begin(), pc_case_vec.end(), [](PCCase a, PCCase b){
        return a.getPrice() < b.getPrice();
    });
}

void PCCase::sortDimension(){
    std::sort(pc_case_vec.begin(), pc_case_vec.end(), [](PCCase a, PCCase b){
        return std::get<0>(a.getDimension()) < std::get<0>(b.getDimension());
    });
}

void PCCase::sortMaxGPULength(){
    std::sort(pc_case_vec.begin(), pc_case_vec.end(), [](PCCase a, PCCase b){
        return a.getMaxGPULength() < b.getMaxGPULength();
    });
}

void PCCase::sortMaxCPUHeight(){
    std::sort(pc_case_vec.begin(), pc_case_vec.end(), [](PCCase a, PCCase b){
        return a.getMaxCPUHeight() < b.getMaxCPUHeight();
    });
}

std::vector<PCCase> PCCase::filterBrand(const std::string b){
    std::vector<PCCase> filtered;
    for (PCCase pc_case: pc_case_vec){
        if (pc_case.getBrand() == b){
            filtered.push_back(pc_case);
        }
    }
    return filtered;
}

std::vector<PCCase> PCCase::filterFormFactor(const std::string ff){
    std::vector<PCCase> filtered;
    for (PCCase pc_case: pc_case_vec){
        if (pc_case.getFormFactor() == ff){
            filtered.push_back(pc_case);
        }
    }
    return filtered;
}

std::vector<PCCase> PCCase::filterCoolingType(const std::string ct){
    std::vector<PCCase> filtered;
    for (PCCase pc_case: pc_case_vec){
        if (pc_case.getCoolingType() == ct){
            filtered.push_back(pc_case);
        }
    }
    return filtered;
}

std::vector<PCCase> PCCase::filterOnDisplay(){
    std::vector<PCCase> filtered;
    for (PCCase pc_case: pc_case_vec){
        if (pc_case.getOnDisplay() == 1){
            filtered.push_back(pc_case);
        }
    }
    return filtered;
}

PCCase& PCCase::operator=(const PCCase& case_in){
    setID(case_in.getID());
    setDescription(case_in.getDescription());
    setBrand(case_in.getBrand());
    setModel(case_in.getModel());
    setPrice(case_in.getPrice());
    setQuantity(case_in.getQuantity());
    setOnDisplay(case_in.getOnDisplay());
    setFormFactor(case_in.getFormFactor());
    setDimension(std::get<0>(case_in.getDimension()), std::get<1>(case_in.getDimension()), std::get<2>(case_in.getDimension()));
    setCoolingType(case_in.getCoolingType());
    setMaxGPULength(case_in.getMaxGPULength());
    setMaxCPUHeight(case_in.getMaxCPUHeight());
    for (int i = 0; i < 3; i++){
        setFanSupport(i, std::get<0>(case_in.getFanSupport()[i]), std::get<1>(case_in.getFanSupport()[i]));
    }
    setImagePath(case_in.getImagePath());
    return *this;
}

