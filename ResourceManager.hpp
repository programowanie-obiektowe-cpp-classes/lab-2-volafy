#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:

        Resource* resource;

    public:

        ResourceManager() : resource(new Resource()){}; //konstruktor

        ResourceManager(const ResourceManager& resourceManager): resource(new Resource(*resourceManager.resource)){}; //konstruktor domyslny

        ResourceManager& operator=(const ResourceManager& resourceManager){

            if (this != &resourceManager) {
                delete resource;//brak wyciekow pamieci :))
                resource = new Resource(*resourceManager.resource);
            }

            return *this;
        };

        ResourceManager(ResourceManager&& resourceManager) : resource(resourceManager.resource){
            resourceManager.resource = nullptr;
        }

        ResourceManager& operator=(ResourceManager&& resourceManager){
            if (this != &resourceManager) {

                delete resource;//brak wyciekow pamieci :))
                resource = resourceManager.resource;
                resourceManager.resource = nullptr;
            }
            return *this;
        }

        ~ResourceManager(){delete resource;}; //brak wyciekow pamieci :))

        double get() const { return resource->get(); }


};

