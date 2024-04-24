#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "debug.hpp"

namespace textures
{
extern std::unordered_map<std::string, sf::Texture> loaded_textures;

/**
 * Load a texture and give it a name.
 * Providing an existing name will overwrite the old texture with that name.
*/
void load_texture_as(std::string path, std::string texture_name);
} // namespace textures