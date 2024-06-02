#ifndef LOGGER_H
#define LOGGER_H

enum LogLevel
{
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO
};
/**
 * Log a message to stdout.
 * @param level The log level.
 * @param msg The message to log.
 * @param ... The arguments to the message.
 */
void logger(enum LogLevel level, const char *msg, ...);
/**
 *  Log an error message to stdout.
 *  @param msg The message to log.
 *  @param ... The arguments to the message.
 */
#define LOG_ERROR(msg, ...) logger(LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)
/**
 *  Log a warning message to stdout.
 *  @param msg The message to log.
 *  @param ... The arguments to the message.
 */
#define LOG_WARN(msg, ...) logger(LOG_LEVEL_WARN, msg, ##__VA_ARGS__)
/**
 *  Log an info message to stdout.
 *  @param msg The message to log.
 *  @param ... The arguments to the message.
 */
#define LOG_INFO(msg, ...) logger(LOG_LEVEL_INFO, msg, ##__VA_ARGS__)

#endif
