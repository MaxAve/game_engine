#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <sstream>
#include <bits/stdc++.h>
#include "debug.hpp"
#include "textures.hpp"

namespace objects
{
/**
 * Class for all game objects
*/
class GameObject
{
private:
    std::string name;
    std::vector<std::string> tags;

    int layer; // Objetcs with higher layer values will be rendered in front of objects with lower ones

public:
    bool shown; // Set to false to hide object (object's state will remain as is but will no longer be rendered).
    bool scene_persistent; // If set to true, the object will not be deleted before a scene change.

    sf::Sprite sprite;

    int get_layer();

    std::string get_name();

    std::vector<std::string> get_tags();

    /**
     * Sets new layer (objects with higher layer values will be rendered over objects with lower ones)
    */
    void set_layer(int new_layer);

    void set_texture(std::string texture);

    /**
     * Returns pointer to GameObject with the given name
    */
    static GameObject *get_object_by_name(std::string name);

    /**
     * Returns a vector of pointers to every GameObject with a given tag
    */
    static std::vector<GameObject*> get_objects_by_tag(std::string tag);

    GameObject(std::string obj_name);
    ~GameObject();
};

struct GameObjectPtr
{
    GameObject *object;
    bool operator < (const GameObjectPtr& other) const { return (object->get_layer() < other.object->get_layer()); }
    bool operator > (const GameObjectPtr& other) const { return (object->get_layer() > other.object->get_layer()); }
}; // Pointer for layer comparison

typedef struct GameObjectPtr GameObjectPtr;

extern std::unordered_map<std::string, GameObject*> loaded_objects; // Pointers to all objects in the scene

/** 
 * Pointers to objects ordered from lowest to highest layer.
 * Used to quickly render objects in a sorted manner.
 * This should get sorted every time a new object is added.
*/
extern std::vector<GameObjectPtr> render_order;

/**
 * Delete object with the given name
*/
void delete_object(std::string name);
} // namespace objects