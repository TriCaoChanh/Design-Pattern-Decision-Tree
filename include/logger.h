#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "common.h"

class Logger
{
private:
protected:
    Logger();
    static Logger *logger;

public:
    /**
     * Singleton Logger should not be cloneable.
     */
    Logger(Logger &other) = delete;

    /**
     * Singletons Logger should not be assignable.
     */
    void operator=(const Logger &) = delete;

    static Logger *get_logger();
    void log(string msg);

    ~Logger();
};

#endif