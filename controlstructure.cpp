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
    {MessageSeverity::debug, writeDebug},
    {MessageSeverity::info, writeInfo},
    {MessageSeverity::warn, writeWarn},
    {MessageSeverity::error, writeError},
    {MessageSeverity::fatal, writeFatal}
};
void writeMessage(MessageSeverity messageseverity){
	writeElapsedTime();
	logger[messageseverity]();
}

//Dynamic polymorphism
struct MessageSeverity{ 
    virtual void writeMessage() const = 0;
};
struct MessageDebug: MessageSeverity{
    void writeMessage() const override {
	std::cerr << "debug" << std::endl;
    }
};
struct MessageInfo: MessageSeverity{ 
    void writeMessage() const override {
	std::cerr << "info" << std::endl;
    }
};
struct MessageWarn: MessageSeverity{
    void writeMessage() const override {
	std::cerr << "warn" << std::endl;
    }
};
struct MessageError: MessageSeverity{
    void writeMessage() const override {
	std::cerr << "error" << std::endl;
    }
};
struct MessageFatal: MessageSeverity{
    void writeMessage() const override {
	std::cerr << "fatal" << std::endl;
    }
};
void writeMessageReference(const MessageSeverity& messageseverity){
    writeElapsedTime();
    messageseverity.writeMessage();
}
void writeMessagePointer(const MessageSeverity* messageseverity){
    writeElapsedTime();
    messageseverity->writeMessage();
}
std::cout << std::endl;
MessageDebug md;
MessageInfo mi;
MessageWarn mw;
MessageError me;
MessageFatal mf; 
MessageSeverity& msr1 = md;            
MessageSeverity& msr2 = mi;
MessageSeverity& msr3 = mw;
MessageSeverity& msr4 = me;            
MessageSeverity& msr5 = mf; 
writeMessageReference(msr1);           
writeMessageReference(msr2);
writeMessageReference(msr3);        
writeMessageReference(msr4);
writeMessageReference(msr5);
std::cerr << std::endl;
MessageSeverity* msp1 = new MessageDebug;
MessageSeverity* msp2 = new MessageInfo;
MessageSeverity* msp3 = new MessageWarn;
MessageSeverity* msp4 = new MessageError;
MessageSeverity* msp5 = new MessageFatal;
writeMessagePointer(msp1);
writeMessagePointer(msp2);
writeMessagePointer(msp3);
writeMessagePointer(msp5);
writeMessagePointer(msp6);
std::cout << std::endl;

//Static polymorphism
template <typename ConcreteMessageSeverity>                        
struct MessageSeverity{
    void writeMessage(){                            
        static_cast<ConcreteMessageSeverity*>(this)->writeMessageImpl();
    }
    virtual void writeMessageImpl() const = 0;
};
struct MessageDebug: MessageSeverity<MessageDebug>{
    void writeMessageImpl() const {              
        std::cerr << "debug" << std::endl;
    }
}; 
struct MessageInfo: MessageSeverity<MessageInfo>{
    void writeMessageImpl() const {          
        std::cerr << "info" << std::endl;
    }
};
struct MessageWarn: MessageSeverity<MessageWarn>{
    void writeMessageImpl() const {              
        std::cerr << "warn" << std::endl;
    }
};
struct MessageError: MessageSeverity<MessageError>{
    void writeMessageImpl() const {              
        std::cerr << "error" << std::endl;
    }
}; 
struct MessageFatal: MessageSeverity<MessageFatal>{
    void writeMessageImpl() const {              
        std::cerr << "fatal" << std::endl;
    }
}; 
template <typename T>
void writeMessage(T& messageseverity){                       	
    writeElapsedTime();                                   
    messageseverity.writeMessage();                         
}
std::cout << std::end;
MessageDebug md;
writeMessage(md);
MessageInfo mi;
writeMessage(mi);
MessageWarn mw;
writeMessage(mw);
MessageError mw;
writeMessage(mw);
MessageFatal mf;
writeMessage(mf);
std::cout << std::endl;
*/
