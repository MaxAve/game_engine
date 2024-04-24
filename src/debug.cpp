#include "../include/debug.hpp"

bool debug::show_debug_info;

void debug::info(const char *format, ...)
{
    if(debug::show_debug_info)
    {
        std::string debug_msg = "[INFO] " + std::string(format);
        va_list args;
        va_start(args, format);
        std::vprintf(debug_msg.c_str(), args);
        va_end(args);
    }
}

void debug::warn(const char *format, ...)
{
    if(debug::show_debug_info)
    {
        std::string debug_msg = "\033[93m[WARN] " + std::string(format);
        va_list args;
        va_start(args, format);
        std::vprintf(debug_msg.c_str(), args);
        va_end(args);
    }
}