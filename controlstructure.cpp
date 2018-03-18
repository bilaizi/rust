#include <chrono>
#include <iostream>
using namespace std;

enum class MessageSeverity{ 
    debug,
    info,
    warn,
    error,
    fatal,
};

auto start = std::chrono::steady_clock::now(); 

void writeElapsedTime(){                                   
    auto now = std::chrono::steady_clock::now();  
    std::chrono::duration<double> diff = now - start;
    std::cerr << diff.count() << " sec. elapsed: ";
}

void writeDebug(){ std::cerr << "debug" << std::endl; }
void writeInfo(){ std::cerr << "info" << std::endl; }
void writeWarn(){ std::cerr << "warn" << std::endl; }
void writeError(){ std::cerr << "error" << std::endl; }
void writeFatal(){ std::cerr << "fatal" << std::endl; }

void writeMessage(MessageSeverity messageseverity){
    writeElapsedTime(); 
    if(MessageSeverity::debug == messageseverity)
	writeDebug();
    else if(MessageSeverity::info == messageseverity)
	writeInfo();
    else if(MessageSeverity::warn == messageseverity)
	writeWarn();
    else if(MessageSeverity::error== messageseverity)
	writeError();
    else
	writeFatal();
}

auto main()->int{
    std::cout << std::endl;
    writeMessage(MessageSeverity::debug);
    writeMessage(MessageSeverity::info);
    writeMessage(MessageSeverity::warn);
    writeMessage(MessageSeverity::error);
    writeMessage(MessageSeverity::fatal);
    std::cout << std::endl;
}
/*
void writeMessage(MessageSeverity messageseverity){
    writeElapsedTime();
    switch(messageseverity){
        case MessageSeverity::debug:
            writeDebug();
            break;
        case MessageSeverity::info:
            writeInfo();
            break;
	case MessageSeverity::warn:
            writeWarn();
            break;
        case MessageSeverity::error:
            writeError();
            break;
        default:
            writeFatal();
            break;
 }

std::unordered_map<MessageSeverity, std::function<void()>> logger{
    {MessageSeverity::debug, writeInformation},
    {MessageSeverity::info, writeInfo},
    {MessageSeverity::warn, writeWarn},
    {MessageSeverity::error, writeError},
    {MessageSeverity::fatal, writeFatal}
};

void writeMessage(MessageSeverity messageseverity){
	writeElapsedTime();
	logger[messageseverity]();
}
*/
