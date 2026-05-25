#pragma once

#include "../my_string/include/my_string.h"
#include <fstream>
#include <string_view>

namespace Shovy{
class Logger{
public:
    enum class LogLevel{
        Info,
        Warning,
        Error
    };

    explicit Logger(const Shovy::string& filename) : _file(filename.c_str(), std::ios::app){
        if(!_file){
            throw std::runtime_error("failed to open log file");
        }
    } 
   
    ~Logger() = default;

    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;
#if 0
    Logger(Logger&& other) noexcept;
    Logger& operator=(Logger&& other) noexcept;
#endif
    Logger(Logger&& other) noexcept = default;
    Logger& operator=(Logger&& other) noexcept = default;

    void log(LogLevel logLevel, std::string_view msg);

    void info(std::string_view msg);
    void warning(std::string_view msg);
    void error(std::string_view msg);

private:
    std::ofstream _file; 
};
}