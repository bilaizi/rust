#include <chrono>
#include <iostream>
using namespace std;

enum class MessageSeverity{                               
    information,
    warning,
    fatal,
};

auto start = std::chrono::steady_clock::now(); 

void writeElapsedTime(){                                   
    auto now = std::chrono::steady_clock::now();  
    std::chrono::duration<double> diff = now - start;
    std::cerr << diff.count() << " sec. elapsed: ";
}

void writeInformation(){ std::cerr << "information" << std::endl; }
void writeWarning(){ std::cerr << "warning" << std::endl; }
void writeUnexpected(){ std::cerr << "unexpected" << std::endl; }

void writeMessage(MessageSeverity messageseverity){
    writeElapsedTime(); 
    if (MessageSeverity::information == messageseverity)
	    writeInformation();
    else if (MessageSeverity::warning == messageseverity)
	    writeWarning();
    else{
	    writeUnexpected();
    }
}

auto main()->int{
    std::cout << std::endl;
    writeMessage(MessageSeverity::information);
    writeMessage(MessageSeverity::warning);
    writeMessage(MessageSeverity::fatal);
    std::cout << std::endl;
}
