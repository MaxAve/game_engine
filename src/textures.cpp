#include "../include/textures.hpp"

std::unordered_map<std::string, sf::Texture> textures::loaded_textures;

void textures::load_texture_as(std::string path, std::string texture_name)
{
    sf::Texture texture;
    if(!texture.loadFromFile(path))
    {
        debug::warn("Unable to load texture from '%s'", path);
    }
    else
    {
        textures::loaded_textures[texture_name] = texture;
    }
}