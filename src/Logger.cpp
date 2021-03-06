#define MSC_CLASS "Logger"
// #define MSC_LOG_DEV

#include "Logger.hpp"
#include <iostream>

namespace mediasoupclient
{
/* Class variables. */

Logger::LogHandlerInterface* Logger::handler{ nullptr };
char Logger::buffer[Logger::bufferSize];
Logger::LogLevel Logger::logLevel = Logger::LogLevel::LOG_NONE;

/* Class methods. */

void Logger::SetLogLevel(Logger::LogLevel level)
{
	Logger::logLevel = level;
}

void Logger::SetHandler(LogHandlerInterface* handler)
{
	Logger::handler = handler;
}

void Logger::SetDefaultHandler()
{
	Logger::handler = new Logger::DefaultLogHandler();
}

/* DefaultLogHandler */

void Logger::DefaultLogHandler::OnLog(LogLevel level, char* payload, size_t len)
{
	(void)level;
	(void)len;

	std::cout << payload << std::endl;
}
} // namespace mediasoupclient
