#include "inventory.h"
#include "../weapons/weapon.h"

Inventory::Inventory() : currentWeaponIndex(-1) {}

Inventory::~Inventory() {}

void Inventory::addItem(const std::string& itemName, int quantity) {
    for (auto& item : items) {
        if (item.first == itemName) {
            item.second += quantity;
            return;
        }
    }
    items.push_back({itemName, quantity});
}

void Inventory::removeItem(const std::string& itemName, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first == itemName) {
            it->second -= quantity;
            if (it->second <= 0) {
                items.erase(it);
            }
            return;
        }
    }
}

int Inventory::getItemQuantity(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item.first == itemName) {
            return item.second;
        }
    }
    return 0;
}

void Inventory::addWeapon(std::shared_ptr<Weapon> weapon) {
    weapons.push_back(weapon);
    if (currentWeaponIndex == -1) {
        currentWeaponIndex = 0;
    }
}

std::shared_ptr<Weapon> Inventory::getWeapon(int index) const {
    if (index >= 0 && index < static_cast<int>(weapons.size())) {
        return weapons[index];
    }
    return nullptr;
}

std::shared_ptr<Weapon> Inventory::getCurrentWeapon() const {
    if (currentWeaponIndex >= 0 && currentWeaponIndex < static_cast<int>(weapons.size())) {
        return weapons[currentWeaponIndex];
    }
    return nullptr;
}

void Inventory::setCurrentWeapon(int index) {
    if (index >= 0 && index < static_cast<int>(weapons.size())) {
        currentWeaponIndex = index;
    }
}
