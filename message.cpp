
#include "message.h"

#include <algorithm>

#include <boost/serialization/export.hpp>


//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/optional.hpp>
//#include <boost/serialization/list.hpp>
//#include <boost/serialization/shared_ptr.hpp>



BOOST_CLASS_EXPORT_KEY(messageTransportContainer);
BOOST_CLASS_EXPORT_IMPLEMENT(messageTransportContainer);
BOOST_CLASS_IMPLEMENTATION(messageTransportContainer, boost::serialization::object_serializable);
BOOST_CLASS_TRACKING(messageTransportContainer, boost::serialization::track_never);


void message::send(const messageTransportContainer& data)
{

    boost::archive::text_oarchive oa(stream);
    oa << data;


}

void message::receive(messageTransportContainer& data)
{

    std::istringstream sin(stream.str());
    boost::archive::text_iarchive ia(sin);
    ia >> data;

}


