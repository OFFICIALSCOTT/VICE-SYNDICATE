#pragma once

#include <vector>
#include <memory>
#include <string>

// Forward declaration
class Weapon;

/**
 * @class Inventory
 * @brief Player inventory system
 */
class Inventory {
public:
    Inventory();
    ~Inventory();

    /**
     * @brief Add item to inventory
     */
    void addItem(const std::string& itemName, int quantity = 1);

    /**
     * @brief Remove item from inventory
     */
    void removeItem(const std::string& itemName, int quantity = 1);

    /**
     * @brief Get item quantity
     */
    int getItemQuantity(const std::string& itemName) const;

    /**
     * @brief Add weapon to inventory
     */
    void addWeapon(std::shared_ptr<Weapon> weapon);

    /**
     * @brief Get weapon by index
     */
    std::shared_ptr<Weapon> getWeapon(int index) const;

    /**
     * @brief Get current weapon
     */
    std::shared_ptr<Weapon> getCurrentWeapon() const;

    /**
     * @brief Set current weapon
     */
    void setCurrentWeapon(int index);

private:
    std::vector<std::pair<std::string, int>> items;
    std::vector<std::shared_ptr<Weapon>> weapons;
    int currentWeaponIndex;
};
