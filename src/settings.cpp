#include "../include/settings.hpp"

settings::GraphicsSettings settings::graphics_settings;

void settings::apply(sf::Window *window)
{
    window->setFramerateLimit(settings::graphics_settings.framerate_limit);
    window->setVerticalSyncEnabled(settings::graphics_settings.use_vsync);
}