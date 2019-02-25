/*
   las_well.h - well class definition for parseLas

   This file is part of the Parsers::Parse-Las-Cpp project

   Copyright (C) 2019 cages

   Licensed under the Apache License, Well 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   License-Identifier: Apache-2.0
*/


#ifndef LAS_WELL_H
#define LAS_WELL_H

#include "las.h"

class LasWell
{
    public:
        LasWell();
        ~LasWell();
        void parseLine(std::string line);
        void printInfo();
        void setHeader(const std::string line);
        void setStart(const std::string line);
        void setStop(const std::string line);
        void setStep(const std::string line);
        void setNull(const std::string line);
        void setCompany(const std::string line);
        void setWell(const std::string line);
        void setField(const std::string line);
        void setLocation(const std::string line);
        void setServiceCompany(const std::string line);
        void setCountryCode(const std::string line);
        void setProvince(const std::string line);
        void setLogDate(const std::string line);
        void setUniqueWellId(const std::string line);
        void setLicense(const std::string line);
        void setLatitude(const std::string line);
        void setLongitude(const std::string line);
        void setGeodeticDatum(const std::string line);
        void setApiNumber(const std::string line);
        void setUtmLocation(const std::string line);

        std::string getHeader();
        std::string getStart();
        std::string getStop();
        std::string getStep();
        std::string getNull();
        std::string getCompany();
        std::string getWell();
        std::string getField();
        std::string getLocation();
        std::string getServiceCompany();
        std::string getCountryCode();
        std::string getProvince();
        std::string getLogDate();
        std::string getUniqueWellId();
        std::string getLicense();
        std::string getLatitude();
        std::string getLongitude();
        std::string getGeodeticDatum();
        std::string getApiNumber();
        std::string getUtmLocation();


    private:
        // header fields
        std::string header;
        std::string start;
        std::string stop;
        std::string step;
        std::string null;
        std::string company;
        std::string mycompany;
        std::string well;
        std::string field;
        std::string location;
        std::string service_company;
        std::string country_code; // internet country codes
        std::string log_date; // default DD/MM/YYYY

        // For required location either use:
        std::string latitude;
        std::string longitude;
        // or (TODO: Add conditional for this option)
        /*
        std::string x;
        std::string y;
        std::string horizontal_coordinate_system;
        */
        //
        std::string geodetic_datum;
        // TODO: For country code 'ca' (Canada):
        std::string province;
        std::string unique_well_id;
        std::string license_number;
        // TODO: For country code 'us' (USA): 
        std::string state;
        std::string county;
        std::string api_number;
        std::string utm_location;
};

#endif /*  LAS_WELL_H */
