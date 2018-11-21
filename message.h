

#include <string>
#include <iostream>


#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/access.hpp>

// TEST CONTAINER
struct messageTransportContainer
{
public:
// Actual Data for transport
// Only edit this part
// ===========================================================
    int ID;
    float f1;
    std::string title1;
    std::string title2;



// ===========================================================

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & ID;
        ar & f1;
        ar & title1;
        ar & title2;
    }
};



class message
{
public:
    message()=default;
    ~message()=default;

    int init();
    void send(const messageTransportContainer& data);
    void receive(messageTransportContainer& data);



private:
    int sockSend(std::ostringstream out);
    int sockReceive(std::ostringstream in);


    // temp container to handle data streaming. For when no socket exists.
    std::stringstream stream;

};
