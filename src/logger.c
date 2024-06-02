#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "logger.h"

void logger(enum LogLevel level, const char *msg, ...)
{
    va_list args;

    switch(level)
    {
        case LOG_LEVEL_INFO:
            puts("\033[32m");
            break;
        case LOG_LEVEL_WARN:
            puts("\033[33m");
            break;
        case LOG_LEVEL_ERROR:
            puts("\033[31m");
            break;
        default:
            puts("\033[0m");
            break;
    }
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    printf("\033[0m\n");
    exit(1);
}