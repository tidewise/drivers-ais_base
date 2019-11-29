#ifndef AIS_BASE_VOYAGEINFORMATION_HPP
#define AIS_BASE_VOYAGEINFORMATION_HPP

#include <string>

#include <base/Time.hpp>

namespace ais_base {
    /** Representation of the voyage data stored in AIS Messages */
    struct VoyageInformation {
        base::Time time;

        int imo = 0;
        base::Time eta;
        std::string destination;
    };
}

#endif
