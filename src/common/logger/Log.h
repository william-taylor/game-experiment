
#ifndef __LOGGER__H__
#define __LOGGER__H__

#include "spdlog/spdlog.h"

/*! @brief Logging facade for future proofing
 *
 * Uses spdlog under the hood, but might explore other loggers
 * as a later date, so this simple facade helps bring all logging
 * into one class so the under lying implementation can be swapped
 * out easier in future if needed.
 */
class Log
{
public:
    template<typename ...Args>
    static void info(const char* fmt, Args &&...args)
    {
        spdlog::info(fmt, args...);
    }

    template<typename ...Args>
    static void error(const char* fmt, Args &&...args)
    {
        spdlog::error(fmt, args...);
    }

    template<typename ...Args>
    static void warn(const char* fmt, Args &&...args)
    {
        spdlog::warn(fmt, args...);
    }

    template<typename ...Args>
    static void debug(const char* fmt, Args &&...args)
    {
        spdlog::debug(fmt, args...);
    }

    static void info(const char* msg);
    static void error(const char* msg);
    static void warn(const char* msg);
    static void debug(const char* msg);
};


#endif //BASIC_GAME_LOGGER_H
