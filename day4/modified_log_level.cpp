#include <iostream>

class Log
{
public:
    enum Level
    {
        LevelError = 0,
        LevelWarning,
        LevelInfo
    };

private:
    Level m_LogLevel = LevelInfo;

public:
    void setLevel(Level level)
    {
        m_LogLevel = level;
        return;
    }
    void Error(const char *message)
    {
        if (m_LogLevel >= LevelError)
            std::cout << "[ERROR] : " << message << std::endl;
        return;
    }
    void Warn(const char *message)
    {
        if (m_LogLevel >= LevelWarning)
            std::cout << "[WARN] : " << message << std::endl;
        return;
    }
    void Info(const char *message)
    {
        if (m_LogLevel >= LevelInfo)
            std::cout << "[INFO] : " << message << std::endl;
        return;
    }
};

int main()
{
    Log log;
    log.setLevel(Log::LevelError);
    log.Error("Hello");
    log.Warn("Hello");
    log.Info("Hello");
    // std::cin.get();
}