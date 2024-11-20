#include "storage_parent.h"

Storage::Storage() : ComputerParts(){
    storage_capacity = 0;
    storage_speed = 0;
    interface = "-";
    form_factor = "-";
}

Storage::Storage(const int q, const double p) : ComputerParts(q, p){
    storage_capacity = 0;
    storage_speed = 0;
    interface = "-";
    form_factor = "-";
}

void Storage::setStorageCapacity(const int c){
    storage_capacity = c;
}

void Storage::setStorageSpeed(const int s){
    storage_speed = s;
}

void Storage::setInterface(const std::string i){
    interface = i;
}

void Storage::setFormFactor(const std::string f){
    form_factor = f;
}

int Storage::getStorageCapacity() const{
    return storage_capacity;
}

int Storage::getStorageSpeed() const{
    return storage_speed;
}

std::string Storage::getInterface() const{
    return interface;
}

std::string Storage::getFormFactor() const{
    return form_factor;
}

