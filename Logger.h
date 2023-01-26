#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

struct LogRow{
    std::string Type;
    std::string Message;
    std::string File;
    LogRow();
    LogRow(std::string T, std::string M, std::string F);

};

class Log {
private:
    std::string WORKFOLDER ;

    std::string file_name;
    std::string LOG_ARRAY[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

    std::string getFolder(std::string& file);
    void startLog(std::ofstream* out);


    //std::ifstream* fileInput;
    std::ofstream* fileOutput;

public:

    enum LOGS {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    Log();

    Log(std::string fname);

    void logMessage(int LOG, std::string message);

    std::string getWorkPath();
    void setWorkPath(std::string& wPath);


};





