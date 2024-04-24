#include "../include/objects.hpp"

std::unordered_map<std::string, objects::GameObject*> objects::loaded_objects = {};

std::vector<objects::GameObjectPtr> objects::render_order = std::vector<objects::GameObjectPtr>();

objects::GameObject::GameObject(std::string obj_name)
{
    if(objects::loaded_objects.find(obj_name) != objects::loaded_objects.end())
    {
        std::stringstream err;
        err << "Object '" << obj_name << "' already exists at " << objects::loaded_objects.at(name);
        throw std::invalid_argument(err.str());
    }
    this->name = obj_name;
    this->tags = std::vector<std::string>();
    this->layer = 0;
    objects::render_order.push_back({this});
    std::sort(objects::render_order.begin(), objects::render_order.end());
    objects::loaded_objects[this->name] = this;
}

objects::GameObject::~GameObject()
{
    objects::loaded_objects.erase(name);
    debug::info("Destroyed object. %i objects still active.", objects::loaded_objects.size());
}

int objects::GameObject::get_layer()
{
    return this->layer;
}

std::string objects::GameObject::get_name()
{
    return this->name;
}

std::vector<std::string> objects::GameObject::get_tags()
{
    return this->tags;
}

objects::GameObject *objects::GameObject::get_object_by_name(std::string name)
{
    if(objects::loaded_objects.find(name) != objects::loaded_objects.end())
    {
        return objects::loaded_objects.at(name);
    }
    debug::warn("Could not find GameObject named '%s'", name.c_str());
    return nullptr;
}

std::vector<objects::GameObject*> objects::GameObject::get_objects_by_tag(std::string tag)
{
    std::vector<objects::GameObject*> objs;
    for(auto& obj_ls_pair : objects::loaded_objects)
    {
        auto tag_index_find = std::find(obj_ls_pair.second->tags.begin(), obj_ls_pair.second->tags.end(), tag); 
        if (tag_index_find != obj_ls_pair.second->tags.end())
        {
            objs.push_back(obj_ls_pair.second);
        }
    }
    return objs;
}

void objects::GameObject::set_layer(int new_layer)
{
    this->layer = new_layer;
    std::sort(objects::render_order.begin(), objects::render_order.end());
}

void objects::delete_object(std::string name)
{
    delete objects::GameObject::get_object_by_name(name);
}

void objects::GameObject::set_texture(std::string texture)
{
    if(textures::loaded_textures.find(texture) == textures::loaded_textures.end())
    {
        debug::warn("Could not find texture named '%s'", texture.c_str());
    }
    else
    {
        this->sprite.setTexture(textures::loaded_textures.at(texture));
    }
}