#pragma once

#include <iostream>
#include <cstdio>
#include <cstdarg>

namespace debug
{
extern bool show_debug_info;

void info(const char *format, ...);
void warn(const char *format, ...);
} // namespace debug