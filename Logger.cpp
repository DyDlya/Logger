#pragma once
#include "Logger.h"


std::string Log::getFolder(std::string& file){

    std::string result = file;

        for (int i = result.size()-1;i > 0; i--) {
            if (result[i] == '/'){

                result.erase(i+1, result.size()-1);

                return result;
            }
        }

    result = static_cast<std::string>(__FILE__);
    return result;
}



LogRow::LogRow(){
    LogRow::Type = "None";
    LogRow::Message = "None";
    LogRow::File = "None";
}

LogRow::LogRow(std::string T, std::string M, std::string F): Type(T), Message(M), File(F){

}

Log::Log(){
    file_name = "None";


    //Log::WORKFOLDER = static_cast<std::string>(__FILE__);
    //for (int i = WORKFOLDER.size()-1;i > 0; i--) {
    //    if (Log::WORKFOLDER[i] == '/'){
    //        Log::WORKFOLDER.erase(i, WORKFOLDER.size()-1);
    //        break;
    //    }
    //}

}

void Log::startLog(std::ofstream* out){

    time_t nowTime = time(0);
    std::string locTime = static_cast<std::string>(ctime(&nowTime));

    *out << "\n"
        << "|=============== {START LOG} ===============|"
        << "\nTime: " << locTime
        << std::endl;
}

Log::Log(std::string fname){

    file_name = fname;

    Log::WORKFOLDER = getFolder(fname);

    Log::fileOutput = new std::ofstream(fname);

    Log::startLog(fileOutput);

}

void Log::logMessage(int LOG, std::string message){
    // Шаблон лога
    std::string log_msg = "[" + Log::LOG_ARRAY[LOG] + "]: " + message;

    // Запись лога в файл
    if (Log::file_name != "None"){
        *Log::fileOutput << log_msg<< std::endl;


    }

    // Лог в консоль
    std::cout << log_msg << std::endl;

}

std::string Log::getWorkPath(){
    std::string folder;

    if(Log::file_name == "None") {
        std::string arg = static_cast<std::string> (__FILE__);
        folder = getFolder(arg);
    }else{
        folder = getFolder(Log::file_name);
    }
    return folder;
}
