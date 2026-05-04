#pragma once

#include <string>
#include <glm/glm.hpp>

/**
 * @class Weapon
 * @brief Base class for all weapons
 */
class Weapon {
public:
    enum class WeaponType {
        ASSAULT_RIFLE,
        SNIPER_RIFLE,
        SHOTGUN,
        PISTOL,
        ROCKET_LAUNCHER,
        PLASMA_RIFLE
    };

    Weapon(WeaponType type, const std::string& name, int damage, int ammo, int magCapacity);
    virtual ~Weapon();

    /**
     * @brief Fire the weapon
     */
    virtual void fire();

    /**
     * @brief Reload the weapon
     */
    virtual void reload();

    /**
     * @brief Get remaining ammo
     */
    int getAmmo() const { return currentAmmo; }

    /**
     * @brief Get ammo in magazine
     */
    int getMagazineAmmo() const { return magazineAmmo; }

    /**
     * @brief Get weapon damage
     */
    int getDamage() const { return damage; }

    /**
     * @brief Get weapon name
     */
    const std::string& getName() const { return name; }

    /**
     * @brief Get weapon type
     */
    WeaponType getType() const { return type; }

    /**
     * @brief Check if weapon can fire
     */
    bool canFire() const { return magazineAmmo > 0; }

    /**
     * @brief Add ammo to reserve
     */
    void addAmmo(int amount);

protected:
    WeaponType type;
    std::string name;
    int damage;
    int currentAmmo;           // Reserve ammo
    int magazineAmmo;          // Ammo in current magazine
    int magazineCapacity;
    float fireRate;            // Shots per second
};
