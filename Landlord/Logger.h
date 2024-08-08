#ifndef LOGGER_H
#define LOGGER_H
#pragma once
#include <iostream>
#include <sstream>
#include <QDateTime>

/******************************************************************************
 *
 * @file       Logger.h
 * @brief      日志类，输出[当前文件名]:[当前函数] "message"
 *
 * @author     我好想睡觉
 * @date       2024/08/08
 * @history
 *****************************************************************************/

// 宏定义方便使用日志记录
#define LOG(message) Logger::getInstance().log(__FILE__, __FUNCTION__, message)

class Logger
{
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const char* file, const char* function, const std::string& message) {
        std::ostringstream oss;
        oss << "[" << extractClassName(file) << "::" << function << "] ：" << message;
        std::cout << oss.str() << std::endl;
    }

private:
    Logger() {}
    ~Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::string extractClassName(const char* file) {
        std::string fileStr(file);
        size_t pos = fileStr.find_last_of("/\\");
        if (pos != std::string::npos) {
            fileStr = fileStr.substr(pos + 1);
        }
        pos = fileStr.find_last_of('.');
        if (pos != std::string::npos) {
            fileStr = fileStr.substr(0, pos);
        }
        return fileStr;
    }
};

#endif // LOGGER_H
