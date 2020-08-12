#include <iostream>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void setLevel(int level)
    {
        m_LogLevel = level;
        return;
    }
    void Error(const char *message)
    {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR] : " << message << std::endl;
        return;
    }
    void Warn(const char *message)
    {
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARN] : " << message << std::endl;
        return;
    }
    void Info(const char *message)
    {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO] : " << message << std::endl;
        return;
    }
};

int main()
{
    Log log;
    log.setLevel(log.LogLevelWarning);
    log.Error("Hello");
    log.Warn("Hello");
    log.Info("Hello");
    // std::cin.get();
}