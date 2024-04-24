#pragma once

#include <SFML/Graphics.hpp>
#include <stdint.h>

namespace settings
{
typedef struct
{
    uint32_t framerate_limit;
    bool use_vsync;
    uint8_t text_size;
} GraphicsSettings;

extern GraphicsSettings graphics_settings;

void apply(sf::Window *window);
} // namespace settings