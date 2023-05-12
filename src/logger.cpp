#include "logger.h"

Logger *Logger::logger = nullptr;

Logger::Logger()
{
}

Logger::~Logger()
{
}

/**
 * get logger instance
 */
Logger *Logger::get_logger()
{
    if (logger == nullptr)
        return new Logger();
    else
        return logger;
}

void Logger::log(string msg)
{
    cout << "Log: " << msg << endl;
}