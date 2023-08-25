//
// Created by Marius on 17/08/2023.
//

#ifndef DISPLAYMAP_RESOURCESMANAGER_H
#define DISPLAYMAP_RESOURCESMANAGER_H

#include <string_view>
#include <unordered_map>
#include <iostream>

template <typename T>
class ResourcesManager
{
public:
    ResourcesManager() = delete;
    static T const& getResource(std::string_view const& resource_location) {
        auto result = resources.find(resource_location);
        if (result == std::end(resources)) {
            if (!resources[resource_location].loadFromFile(resource_location.data())) {
                std::cout << "Impossible de charger la ressource : " << resource_location.data() << std::endl;
            }
            return resources[resource_location];
        }
        return result->second;
    }
private:
    static std::unordered_map<std::string_view, T> resources;
};

#endif //DISPLAYMAP_RESOURCESMANAGER_H
