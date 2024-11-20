#include "webcam.h"

Webcam::Webcam(): Peripherals(){
    resolution = std::make_tuple(0, 0);
    fps = 0;
    field_of_view = 0;
    has_microphone = false;
    dimensions = std::make_tuple(0, 0, 0);
    generateId();
}

Webcam::Webcam(const int q, const double p) : Peripherals(q, p) {
    resolution = std::make_tuple(0, 0);
    fps = 0;
    field_of_view = 0;
    has_microphone = false;
    dimensions = std::make_tuple(0, 0, 0);
    generateId();
}

Webcam::Webcam(const std::string s) : Peripherals() {
    resolution = std::make_tuple(0, 0);
    fps = 0;
    field_of_view = 0;
    has_microphone = false;
    dimensions = std::make_tuple(0, 0, 0);
}

void Webcam::setResolution(int l, int h) {
    resolution = std::make_tuple(l, h);
}

void Webcam::setFps(const unsigned int f) {
    fps = f;
}

void Webcam::setFieldOfView(const int fov) {
    field_of_view = fov;
}

void Webcam::setHasMicrophone(const bool hm) {
    has_microphone = hm;
}

void Webcam::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

std::tuple<int, int> Webcam::getResolution() const {
    return resolution;
}

int Webcam::getFps() const {
    return fps;
}

int Webcam::getFieldOfView() const {
    return field_of_view;
}

bool Webcam::getHasMicrophone() const {
    return has_microphone;
}

std::tuple<double, double, double> Webcam::getDimensions() const {
    return dimensions;
}

void Webcam::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Webcam::generateId() {
    std::ifstream file_in("../txt_files/webcam.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Webcam& cam: webcam_vec){
            std::string id = cam.getID(); // AZ0001
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
    webcam_vec.push_back(*this);
    std::ofstream file_out("../txt_files/webcam.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Webcam& cam: webcam_vec){
        file_out << cam.getID() << "|";
        file_out << cam.getDescription() << "|";
        file_out << cam.getBrand() << "|";
        file_out << cam.getModel() << "|";
        file_out << cam.getPrice() << "|";
        file_out << cam.getQuantity() << "|";
        file_out << cam.getOnDisplay() << "|";
        file_out << std::get<0>(cam.getResolution()) << "|";
        file_out << std::get<1>(cam.getResolution()) << "|";
        file_out << cam.getFps() << "|";
        file_out << cam.getFieldOfView() << "|";
        file_out << cam.getHasMicrophone() << "|";
        file_out << std::get<0>(cam.getDimensions()) << "|";
        file_out << std::get<1>(cam.getDimensions()) << "|";
        file_out << std::get<2>(cam.getDimensions()) << "|";
        file_out << cam.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Webcam::updateVec(const Webcam cam_in) {
    for (Webcam& cam: webcam_vec){
        if (cam.getID() == cam_in.getID()){
            cam.setDescription(cam_in.getDescription());
            cam.setBrand(cam_in.getBrand());
            cam.setModel(cam_in.getModel());
            cam.setPrice(cam_in.getPrice());
            cam.setQuantity(cam_in.getQuantity());
            cam.setOnDisplay(cam_in.getOnDisplay());
            cam.setResolution(std::get<0>(cam_in.getResolution()), std::get<1>(cam_in.getResolution()));
            cam.setFps(cam_in.getFps());
            cam.setFieldOfView(cam_in.getFieldOfView());
            cam.setHasMicrophone(cam_in.getHasMicrophone());
            cam.setDimensions(std::get<0>(cam_in.getDimensions()), 
                            std::get<1>(cam_in.getDimensions()), 
                            std::get<2>(cam_in.getDimensions()));
            cam.setImagePath(cam_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/webcam.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Webcam& cam: webcam_vec){
        file_out << cam.getID() << "|";
        file_out << cam.getDescription() << "|";
        file_out << cam.getBrand() << "|";
        file_out << cam.getModel() << "|";
        file_out << cam.getPrice() << "|";
        file_out << cam.getQuantity() << "|";
        file_out << cam.getOnDisplay() << "|";
        file_out << std::get<0>(cam.getResolution()) << "|";
        file_out << std::get<1>(cam.getResolution()) << "|";
        file_out << cam.getFps() << "|";
        file_out << cam.getFieldOfView() << "|";
        file_out << cam.getHasMicrophone() << "|";
        file_out << std::get<0>(cam.getDimensions()) << "|";
        file_out << std::get<1>(cam.getDimensions()) << "|";
        file_out << std::get<2>(cam.getDimensions()) << "|";
        file_out << cam.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Webcam::readData(){
    std::ifstream file_in("../txt_files/webcam.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string resolution_w;
    std::string resolution_h;
    std::string fps;
    std::string fov;
    std::string has_mic;
    std::string dim_l;
    std::string dim_w;
    std::string dim_h;
    std::string image_path;
    std::array<std::string*, 16> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &resolution_w, &resolution_h, &fps, &fov, &has_mic, &dim_l, &dim_w, &dim_h, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');          
        }
        Webcam cam("a");
        cam.setID(id);
        cam.setDescription(description);
        cam.setBrand(brand);
        cam.setModel(model);
        cam.setPrice(std::stod(price));
        cam.setQuantity(std::stoi(quantity));
        cam.setOnDisplay(std::stoi(on_display));
        cam.setResolution(std::stoi(resolution_w), std::stoi(resolution_h));
        cam.setFps(std::stoi(fps));
        cam.setFieldOfView(std::stoi(fov));
        cam.setHasMicrophone(std::stoi(has_mic));
        cam.setDimensions(std::stod(dim_l), std::stod(dim_w), std::stod(dim_h));
        cam.setImagePath(image_path);
        webcam_vec.push_back(cam); 
    }
    file_in.close();
    return;
}

void Webcam::selectSortFilter() {
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Webcam> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Resolution" << std::endl;
        std::cout << "3. FPS" << std::endl;
        std::cout << "4. Field of View" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
        std::cout << "6. Filter Has Microphone" << std::endl;
        std::cout << "7. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 7 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 7: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortResolution();
        } else if (sort_option == 3){
            sortFps();
        } else if (sort_option == 4){
            sortFieldOfView();
        } else if (sort_option == 5){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 6){
            filtered = filterHasMicrophone();
        } else if (sort_option == 7){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 5){
            for (const Webcam webcam: webcam_vec){
                std::cout << webcam;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Resolution: " << std::get<0>(webcam.getResolution()) << "x" << std::get<1>(webcam.getResolution()) << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "FPS: " << webcam.getFps() << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Field of View: " << webcam.getFieldOfView() << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Webcam webcam: filtered){
                std::cout << webcam << std::endl;
            }
        }
    }
    return;    
}

void Webcam::sortPrice() {
    std::sort(webcam_vec.begin(), webcam_vec.end(), [](const Webcam& a, const Webcam& b) {
        return a.getPrice() < b.getPrice();
    });
}

void Webcam::sortResolution() {
    std::sort(webcam_vec.begin(), webcam_vec.end(), [](const Webcam& a, const Webcam& b) {
        return (std::get<0>(a.getResolution()) * std::get<1>(a.getResolution()))  < (std::get<0>(b.getResolution()) * std::get<1>(b.getResolution()));
    });
}

void Webcam::sortFps() {
    std::sort(webcam_vec.begin(), webcam_vec.end(), [](const Webcam& a, const Webcam& b) {
        return a.getFps() < b.getFps();
    });
}

void Webcam::sortFieldOfView() {
    std::sort(webcam_vec.begin(), webcam_vec.end(), [](const Webcam& a, const Webcam& b) {
        return a.getFieldOfView() < b.getFieldOfView();
    });
}

void Webcam::sortDimensions() {
    std::sort(webcam_vec.begin(), webcam_vec.end(), [](const Webcam& a, const Webcam& b) {
        return (std::get<0>(a.getDimensions()) * std::get<1>(a.getDimensions()) * std::get<2>(a.getDimensions())) < (std::get<0>(b.getDimensions()) * std::get<1>(b.getDimensions()) * std::get<2>(b.getDimensions()));
    });
}

std::vector<Webcam> Webcam::filterBrand(const std::string brand) {
    std::vector<Webcam> filtered;
    for (const Webcam cam: webcam_vec){
        if (cam.getBrand() == brand){
            filtered.push_back(cam);
        }
    }
    return filtered;
}

std::vector<Webcam> Webcam::filterHasMicrophone() {
    std::vector<Webcam> filtered;
    for (const Webcam cam: webcam_vec){
        if (cam.getHasMicrophone()){
            filtered.push_back(cam);
        }
    }
    return filtered;
}

std::vector<Webcam> Webcam::filterOnDisplay() {
    std::vector<Webcam> filtered;
    for (const Webcam cam: webcam_vec){
        if (cam.getOnDisplay() == 1){
            filtered.push_back(cam);
        }
    }
    return filtered;
}

Webcam& Webcam::operator=(const Webcam& cam) {
    setID(cam.getID());
    setDescription(cam.getDescription());
    setBrand(cam.getBrand());
    setModel(cam.getModel());
    setPrice(cam.getPrice());
    setQuantity(cam.getQuantity());
    setOnDisplay(cam.getOnDisplay());
    setResolution(std::get<0>(cam.getResolution()), std::get<1>(cam.getResolution()));
    setFps(cam.getFps());
    setFieldOfView(cam.getFieldOfView());
    setHasMicrophone(cam.getHasMicrophone());
    setDimensions(std::get<0>(cam.getDimensions()), 
                std::get<1>(cam.getDimensions()), 
                std::get<2>(cam.getDimensions()));
    setImagePath(cam.getImagePath());
    return *this;
}