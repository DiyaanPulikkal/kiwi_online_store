#include "Devices.h"

Devices::Devices(){
    brand = "-";
    model = "-";
    quantity = 0;
    price = 0;
    total_sales = 0;
    description = "-";
    on_display = false;
    image_path = "../img/no_image.png";
}

Devices::Devices(const int q, const double p){
    brand = "-";
    model = "-";
    quantity = q;
    price = p;
    total_sales = 0;
    description = "-";
    on_display = false;
    image_path = "../img/no_image.png";
}

std::string Devices::getDescription() const{
    return description;
}

double Devices::getPrice() const{
    return price;
}

double Devices::getQuantity() const{
    return quantity;
}

bool Devices::getOnDisplay() const{
    return on_display;
}

double Devices::getTotalSales(){
    return total_sales;
}

std::string Devices::getBrand() const{
    return brand;
}

std::string Devices::getModel() const{
    return model;
}

std::string Devices::getImagePath() const{
    return image_path;
}

void Devices::purchaseDevice(const unsigned int q){
    if (quantity >= q){
        quantity -= q;
        total_sales += price * q;
        return;
    }
    std::cout << "Not enough devices in stock" << std::endl;
}


//  Dev-only methods
void Devices::restock(const int q){
    quantity += q;
}

void Devices::setPrice(double p){
    price = p;
}

void Devices::setQuantity(const int q){
    quantity = q;
}

void Devices::setDescription(const std::string d){
    description = d;
}

void Devices::setBrand(const std::string b){
    brand = b;
}

void Devices::setModel(const std::string m){
    model = m;
}

void Devices::removeFromStock(const int q){
    quantity -= q;
    if (quantity >= q){
        quantity -= q;
    } else if (quantity < q){
        std::cout << "Not enough devices in stock" << std::endl;
    }
    if (quantity == 0){
        setOnDisplay(false);
    }
}

void Devices::setImagePath(const std::string i){
    image_path = i;
}

std::string Devices::getID() const{
    return id;
}

void Devices::setID(const std::string i){
    id = i;
}

void Devices::setOnDisplay(const bool o){
    on_display = o;
}

std::ostream& operator<<(std::ostream& os, const Devices& d){
    os << "ID: "<< d.id << std::endl;
    os << std::setw(15) << "Brand: " << d.brand;
    os << std::setw(15) << "Model: " << d.model;
    os << std::setw(15) << "Quantity: " << d.quantity;
    os << std::setw(15) << "Price: " << d.price;
    os << std::setw(15) << "For sale: " << (d.on_display? "Yes" : "No");
    return os;
}