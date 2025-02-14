// run time conversion
//✔ When you need to safely convert a base class pointer to a derived class pointer.
//✔ When dealing with inheritance and polymorphism, ensuring correct type identification.
//✔ When working with heterogeneous collections of objects.

#include <iostream>

// Base class (polymorphic)
class SIPMessage {
public:
    virtual void parse() { 
        std::cout << "Parsing generic SIP message\n"; 
    }
    virtual ~SIPMessage() {}  // Virtual destructor for proper cleanup
};

// Derived class for SIP INVITE messages
class INVITEMessage : public SIPMessage {
public:
    void parse() override { 
        std::cout << "Parsing SIP INVITE message (Call Setup)\n"; 
    }
    void setupCall() { 
        std::cout << "Setting up a call...\n"; 
    }
};

// Derived class for SIP BYE messages
class BYEMessage : public SIPMessage {
public:
    void parse() override { 
        std::cout << "Parsing SIP BYE message (Call Termination)\n"; 
    }
    void terminateCall() { 
        std::cout << "Terminating call...\n"; 
    }
};

// Function to process a generic SIP message
void processSIPMessage(SIPMessage* msg) {
    std::cout << "Processing SIP message...\n";
    
    // Try casting to INVITEMessage
    INVITEMessage* invite = dynamic_cast<INVITEMessage*>(msg);
    if (invite) {
        std::cout << "Detected INVITE message!\n";
        invite->setupCall();
        return;
    }

    // Try casting to BYEMessage
    BYEMessage* bye = dynamic_cast<BYEMessage*>(msg);
    if (bye) {
        std::cout << "Detected BYE message!\n";
        bye->terminateCall();
        return;
    }

    // Default case
    std::cout << "Unknown message type\n";
}

int main() {
    SIPMessage* msg1 = new INVITEMessage();
    SIPMessage* msg2 = new BYEMessage();
    SIPMessage* msg3 = new SIPMessage();

    processSIPMessage(msg1);  // Should detect INVITE
    processSIPMessage(msg2);  // Should detect BYE
    processSIPMessage(msg3);  // Unknown message type

    delete msg1;
    delete msg2;
    delete msg3;

    return 0;
}
