#include "vr.h"

VR::VR(): Devices(){
    resolution = std::make_tuple(0, 0);
    with_controllers = false;
    display = "-";
    type_USB_cable = "-";
    max_refresh_rate = 0;
    field_of_view = 0.0;
    size_display_inch = 0.0;
    generateId();
}

VR::VR(int q, double p) : Devices(q, p){
    resolution = std::make_tuple(0, 0);
    with_controllers = false;
    display = "-";
    type_USB_cable = "-";
    max_refresh_rate = 0;
    field_of_view = 0.0;
    size_display_inch = 0.0;
    generateId();
}

VR::VR(const std::string s) : Devices(){
    resolution = std::make_tuple(0, 0);
    with_controllers = false;
    display = "-";
    type_USB_cable = "-";
    max_refresh_rate = 0;
    field_of_view = 0.0;
    size_display_inch = 0.0;
}

std::tuple<int, int> VR::getResolution() const {
    return resolution;
}

bool VR::getWithControllers() const {
    return with_controllers;
}

std::string VR::getDisplay() const {
    return display;
}


std::string VR::getHaveUsbCable() const {
    return type_USB_cable;
}

int VR::getRefreshRate() const {
    return max_refresh_rate;
}

double VR::getFieldOfView() const {
    return field_of_view;
}

double VR::getSizeDisplayInch() const {
    return size_display_inch;
}

void VR::setResolution(int x, int y) {
    resolution = std::make_tuple(x, y);
}

void VR::setWithControllers(bool w) {
    with_controllers = w;
}   

void VR::setDisplay(std::string d) {
    display = d;
}

void VR::setUsbCable(std::string u) {
    type_USB_cable = u;
}

void VR::setRefreshRate(int r) {
    max_refresh_rate = r;
}

void VR::setFieldOfView(double f) {
    field_of_view = f;
}

void VR::setSizeDisplayInch(double s) {
    size_display_inch = s;
}

void VR::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void VR::generateId() {
    std::ifstream file_in("../txt_files/vr.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const VR& vr: vr_vec){
            std::string id = vr.getID(); // AZ0001
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
    vr_vec.push_back(*this);
    std::ofstream file_out("../txt_files/vr.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const VR& vr: vr_vec){
        file_out << vr.getID() << "|";
        file_out << vr.getDescription() << "|";
        file_out << vr.getBrand() << "|";
        file_out << vr.getModel() << "|";
        file_out << vr.getPrice() << "|";
        file_out << vr.getQuantity() << "|";
        file_out << vr.getOnDisplay() << "|";
        file_out << std::get<0>(vr.getResolution()) << "|" << std::get<1>(vr.getResolution()) << "|";
        file_out << vr.getWithControllers() << "|";
        file_out << vr.getDisplay() << "|";
        file_out << vr.getHaveUsbCable() << "|";
        file_out << vr.getRefreshRate() << "|";
        file_out << vr.getFieldOfView() << "|";
        file_out << vr.getSizeDisplayInch() << "|";
        file_out << vr.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    
    return;
}

void VR::updateVec(const VR vr_in){
    for (VR& vr: vr_vec){
        if (vr.getID() == vr_in.getID()){
            vr.setDescription(vr_in.getDescription());
            vr.setBrand(vr_in.getBrand());
            vr.setModel(vr_in.getModel());
            vr.setPrice(vr_in.getPrice());
            vr.setQuantity(vr_in.getQuantity());
            vr.setOnDisplay(vr_in.getOnDisplay());
            vr.setResolution(std::get<0>(vr_in.getResolution()), std::get<1>(vr_in.getResolution()));
            vr.setWithControllers(vr_in.getWithControllers());
            vr.setDisplay(vr_in.getDisplay());
            vr.setUsbCable(vr_in.getHaveUsbCable());
            vr.setRefreshRate(vr_in.getRefreshRate());
            vr.setFieldOfView(vr_in.getFieldOfView());
            vr.setSizeDisplayInch(vr_in.getSizeDisplayInch());
            vr.setImagePath(vr_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/vr.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const VR& vr: vr_vec){
        file_out << vr.getID() << "|";
        file_out << vr.getDescription() << "|";
        file_out << vr.getBrand() << "|";
        file_out << vr.getModel() << "|";
        file_out << vr.getPrice() << "|";
        file_out << vr.getQuantity() << "|";
        file_out << vr.getOnDisplay() << "|";
        file_out << std::get<0>(vr.getResolution()) << "|";
        file_out << std::get<1>(vr.getResolution()) << "|";
        file_out << vr.getWithControllers() << "|";
        file_out << vr.getDisplay() << "|";
        file_out << vr.getHaveUsbCable() << "|";
        file_out << vr.getRefreshRate() << "|";
        file_out << vr.getFieldOfView() << "|";
        file_out << vr.getSizeDisplayInch() << "|";
        file_out << vr.getImagePath();
        file_out << std::endl;
    }    
    file_out.close();
    return;
}

void VR::readData(){
    std::ifstream file_in("../txt_files/vr.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resw;
    std::string resh;
    std::string with_controllers;
    std::string display;
    std::string type_USB_cable;
    std::string max_refresh_rate;
    std::string field_of_view;
    std::string size_display_inch;
    std::string image_path;
    std::array<std::string*, 16> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resw, &resh, &with_controllers, &display, &type_USB_cable, &max_refresh_rate, &field_of_view, &size_display_inch, &image_path};
    
    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                 
        }
        VR vr("a");
        vr.setID(id);
        vr.setDescription(description);
        vr.setBrand(brand);
        vr.setModel(model);
        vr.setPrice(std::stod(price));
        vr.setQuantity(std::stoi(quantity));
        vr.setOnDisplay(std::stoi(on_display));
        vr.setResolution(std::stoi(resw), std::stoi(resh));
        vr.setWithControllers(std::stoi(with_controllers));
        vr.setDisplay(display);
        vr.setUsbCable(type_USB_cable);
        vr.setRefreshRate(std::stoi(max_refresh_rate));
        vr.setFieldOfView(std::stod(field_of_view));
        vr.setSizeDisplayInch(std::stod(size_display_inch));
        vr.setImagePath(image_path);
        vr_vec.push_back(vr);
    }
    file_in.close();
    return;
}

void VR::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<VR> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Resolution" << std::endl;
        std::cout << "3. Refresh Rate" << std::endl;
        std::cout << "4. Field of View" << std::endl;
        std::cout << "5. Size Display Inch" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter with Controllers" << std::endl;
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
            sortResolution();
        } else if (sort_option == 3){
            sortRefreshRate();
        } else if (sort_option == 4){
            sortFieldOfView();
        } else if (sort_option == 5){
            sortSizeDisplayInch();
        } else if (sort_option == 6){
            std::string brand;
            std::cout << "Enter brand: ";
            std::getline(std::cin, brand);
            filtered = filterBrand(brand);
        } else if (sort_option == 7){
            filtered = filterWithControllers();
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const VR vr: vr_vec){
                std::cout << vr;
                switch (sort_option)
                {
                case 2:
                    std::cout << "     " << "Resolution: " << std::get<0>(vr.getResolution()) << "x" << std::get<1>(vr.getResolution()) << std::endl;
                    break;

                case 3:
                    std::cout << "     " << "Refresh Rate: " << vr.getRefreshRate() << "Hz" << std::endl;
                    break;

                case 4:
                    std::cout << "     " << "Field of View: " << vr.getFieldOfView() << "°" << std::endl;
                    break;

                case 5:
                    std::cout << "     " << "Size Display Inch: " << vr.getSizeDisplayInch() << "\"" << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const VR vr: filtered){
                std::cout << vr << std::endl;
            }
        }
    }
    return;
}


void VR::sortPrice(){
    std::sort(vr_vec.begin(), vr_vec.end(), [](const VR& a, const VR& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void VR::sortResolution(){
    std::sort(vr_vec.begin(), vr_vec.end(), [](const VR& a, const VR& b){
        return (std::get<0>(a.getResolution()) * std::get<1>(a.getResolution())) < (std::get<0>(b.getResolution()) * std::get<1>(b.getResolution()));
    });
    return;
}

void VR::sortRefreshRate(){
    std::sort(vr_vec.begin(), vr_vec.end(), [](const VR& a, const VR& b){
        return a.getRefreshRate() < b.getRefreshRate();
    });
    return;
}

void VR::sortFieldOfView(){
    std::sort(vr_vec.begin(), vr_vec.end(), [](const VR& a, const VR& b){
        return a.getFieldOfView() < b.getFieldOfView();
    });
    return;
}

void VR::sortSizeDisplayInch(){
    std::sort(vr_vec.begin(), vr_vec.end(), [](const VR& a, const VR& b){
        return a.getSizeDisplayInch() < b.getSizeDisplayInch();
    });
    return;
}

std::vector<VR> VR::filterBrand(const std::string brand){
    std::vector<VR> filtered;
    for (const VR vr: vr_vec){
        if (vr.getBrand() == brand){
            filtered.push_back(vr);
        }
    }
    return filtered;
}

std::vector<VR> VR::filterWithControllers(){
    std::vector<VR> filtered;
    for (const VR vr: vr_vec){
        if (vr.getWithControllers()){
            filtered.push_back(vr);
        }
    }
    return filtered;
}

std::vector<VR> VR::filterOnDisplay(){
    std::vector<VR> filtered;
    for (const VR vr: vr_vec){
        if (vr.getOnDisplay()){
            filtered.push_back(vr);
        }
    }
    return filtered;
}

VR& VR::operator=(const VR& vr){
    setID(vr.getID());
    setDescription(vr.getDescription());
    setBrand(vr.getBrand());
    setModel(vr.getModel());
    setPrice(vr.getPrice());
    setQuantity(vr.getQuantity());
    setOnDisplay(vr.getOnDisplay());
    setResolution(std::get<0>(vr.getResolution()), std::get<1>(vr.getResolution()));
    setWithControllers(vr.getWithControllers());
    setDisplay(vr.getDisplay());
    setUsbCable(vr.getHaveUsbCable());
    setRefreshRate(vr.getRefreshRate());
    setFieldOfView(vr.getFieldOfView());
    setSizeDisplayInch(vr.getSizeDisplayInch());
    setImagePath(vr.getImagePath());
    return *this;
}
