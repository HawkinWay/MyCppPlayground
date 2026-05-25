#include "logger.h"

namespace Shovy{
Logger::Logger(Logger&& other) noexcept :
     _file(std::move(other._file)){ }

Logger& Logger::operator=(Logger&& other) noexcept{
    if(this != &other){
        _file = std::move(other._file);
    }
    return *this;
}

void Logger::log(LogLevel logLevel, std::string_view msg){
    const char* levelString = "";
    switch (logLevel){
        case(LogLevel::Info):
            levelString = "INFO";
            break;
        case(LogLevel::Warning):
            levelString = "WARNING";
            break;
        case(LogLevel::Error):
            levelString = "ERROR";
            break;
    }

    std::cout << __TIME__ << "[" << levelString << "] " << msg << '\n';
    if(_file){
        _file << "[" << levelString << "] " << msg << '\n';
        _file.flush();
    }

}

void Logger::info(std::string_view msg){
    log(LogLevel::Info, msg);
}

void Logger::warning(std::string_view msg){
    log(LogLevel::Warning, msg);
}

void Logger::error(std::string_view msg){
    log(LogLevel::Error, msg);
}
}