

#include "message.h"

#include <iostream>




int main(int argc, char **argv)
{
    messageTransportContainer sendMsg;
    messageTransportContainer getMsg;
    message msg;

    sendMsg.ID = 21345;
    sendMsg.title1 = "TEST STRING, MOO MOO";
    msg.send(sendMsg);



    getMsg.ID = 0;
    msg.receive(getMsg);

    std::cout << "ID : " << getMsg.ID << " --- " << "Title : " << getMsg.title1 << std::endl;
}



