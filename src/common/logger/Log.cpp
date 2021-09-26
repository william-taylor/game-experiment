
#include "Log.h"

Log::Log()
{

}

void Log::info(const char* msg)
{
    spdlog::info(msg);
}

void Log::error(const char* msg)
{
    spdlog::error(msg);
}

void Log::warn(const char* msg)
{
    spdlog::error(msg);
}

void Log::debug(const char* msg)
{
    spdlog::error(msg);
}