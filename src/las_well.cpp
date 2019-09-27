/*
   las_well.cpp - LasWell class methods

   This file is part of the Las-Util-Cpp project

   Copyright (C) 2019 DC Slagel

   Licensed under the Apache License, Version 2.0 (the "License");
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

// ParseLas includes
#include "las.h"

LasWell::LasWell()
{
}

LasWell::~LasWell()
{
}

/* -------------------------------------------------------------------
 * Line formats:
 *
 * 1. Section Header
 * ~[section-name]
 * Example:
 * ~Well Information
 *
 * 2. name/value line
 * [name].[optional unit][space][value]:[comment]
 * Example:
 * STRT.M 1649.0000 : comment
 *
 * -------------------------------------------------------------------*/
void LasWell::parseLine(std::string line)
{
    std::string field_name;
    std::string raw_unit_and_data;
    std::string unit;
    std::string value;

    // Get section title or field name
    std::stringstream ss(line);
    std::getline(ss, field_name, '.');
    trim(field_name);

    // Get unit is there is one
    std::getline(ss, unit, ' ');

    // Get value if there is one
    std::getline(ss, value, ':');
    trim(value);


    if (field_name[0] == '~')
    {
        setHeader(field_name);
    }
    if (field_name == "STRT")
    {
        setStart(value);
    }
    if (field_name == "STOP")
    {
        setStop(value);
    }
    if (field_name == "STEP")
    {
        setStep(value);
    }
    if (field_name == "NULL")
    {
        setNull(value);
    }
    if (field_name == "COMP")
    {
        setCompany(value);
    }
    if (field_name == "WELL")
    {
        setWell(value);
    }
    if (field_name == "FLD")
    {
        setField(value);
    }
    if (field_name == "LOC")
    {
        setLocation(value);
    }
    if (field_name == "CTRY")
    {
        setCountryCode(value);
    }
    if (field_name == "PROV")
    {
        setProvince(value);
    }
    if (field_name == "SRVC")
    {
        setServiceCompany(value);
    }
    if (field_name == "DATE")
    {
        setLogDate(value);
    }
    if (field_name == "UWI")
    {
        setUniqueWellId(value);
    }
    if (field_name == "LIC")
    {
        setLicense(value);
    }
    if (field_name == "API")
    {
        setApiNumber(value);
    }
    if (field_name == "LATI")
    {
        setLatitude(value);
    }
    if (field_name == "LONG")
    {
        setLongitude(value);
    }
    if (field_name == "GDAT")
    {
        setGeodeticDatum(value);
    }
    if (field_name == "UTM")
    {
        setUtmLocation(value);
    }
    // tokens.clear();
}


void LasWell::setHeader(const std::string line)
{
    header = line;
}


void LasWell::setStart(const std::string line)
{
    start = line;
}


void LasWell::setStop(const std::string line)
{
    stop = line;
}


void LasWell::setStep(const std::string line)
{
    step = line;
}


void LasWell::setNull(const std::string line)
{
    null = line;
}

/* -------------------------------------------------------------------
 *
 * Example data:
 * #MNEM.UNIT              DATA                       DESCRIPTION
 * #----- -----            ----------               ---------------
 * COMP .                  ANY OIL COMPANY INC.     : COMPANY 
 *
 * Notes:
 * - The first '.' is a delimiter between the 'mnenomic name' and an
 *   optional 'unit'
 * - If a space immeadiatly follows the '.' then there isn't a 'unit'
 *   and data follows till the ':' which is the comment delimiter
 * -------------------------------------------------------------------*/
void LasWell::setCompany(const std::string line)
{
    company = line;
}

void LasWell::setWell(const std::string line)
{
    well = line;
}


void LasWell::setField(const std::string line)
{
    field = line;
}


void LasWell::setLocation(const std::string line)
{
    location = line;
}


void LasWell::setServiceCompany(const std::string line)
{
    service_company = line;
}


void LasWell::setCountryCode(const std::string line)
{
    country_code = line;
}

void LasWell::setProvince(const std::string line)
{
    province = line;
}

void LasWell::setLogDate(const std::string line)
{
    log_date = line;
}

void LasWell::setUniqueWellId(const std::string line)
{
    unique_well_id = line;
}

void LasWell::setLicense(const std::string line)
{
    license_number = line;
}

void LasWell::setApiNumber(const std::string line)
{
    api_number = line;
}

void LasWell::setLatitude(const std::string line)
{
    latitude = line;
}


void LasWell::setLongitude(const std::string line)
{
    longitude = line;
}


void LasWell::setGeodeticDatum(const std::string line)
{
    geodetic_datum = line;
}

void LasWell::setUtmLocation(const std::string line)
{
    utm_location = line;
}


std::string LasWell::getHeader()
{
    return header;
}

std::string LasWell::getStart()
{
    return start;
}

std::string LasWell::getStop()
{
    return stop;
}

std::string LasWell::getStep()
{
    return step;
}

std::string LasWell::getNull()
{
    return null;
}

std::string LasWell::getCompany()
{
    return company;
}

std::string LasWell::getWell()
{
    return well;
}

std::string LasWell::getField()
{
    return field;
}

std::string LasWell::getLocation()
{
    return location;
}

std::string LasWell::getServiceCompany()
{
    return service_company;
}

std::string LasWell::getCountryCode()
{
    return country_code;
}

std::string LasWell::getProvince()
{
    return province;
}

std::string LasWell::getLogDate()
{
    return log_date;
}

std::string LasWell::getUniqueWellId()
{
    return unique_well_id;
}

std::string LasWell::getLicense()
{
    return license_number;
}

std::string LasWell::getApiNumber()
{
    return api_number;
}

std::string LasWell::getLatitude()
{
    return latitude;
}

std::string LasWell::getLongitude()
{
    return longitude;
}

std::string LasWell::getGeodeticDatum()
{
    return geodetic_datum;
}

std::string LasWell::getUtmLocation()
{
    return utm_location;
}

void LasWell::printInfo()
{
    std::cout
        << "# ------------------------------------------------------\n"
        << "#  " << getHeader() << "\n"
        << "# ------------------------------------------------------\n"
        << std::left
        << std::setw(17) << "Start" << ": [" << getStart() << "]\n"
        << std::setw(17) << "Stop" << ": [" << getStop() << "]\n"
        << std::setw(17) << "Step" << ": [" << getStep() << "]\n"
        << std::setw(17) << "Null" << ": [" << getNull() << "]\n"
        << std::setw(17) << "Well" << ": [" << getWell() << "]\n"
        << std::setw(17) << "Field" << ": [" << getField() << "]\n"
        << std::setw(17) << "Location" << ": [" << getLocation() << "]\n"
        << std::setw(17) << "Company" << ": [" << getCompany() << "]\n"
        << std::setw(17) << "ServiceCompany"
        << ": [" << getServiceCompany() << "]\n"
        << std::setw(17) << "CountryCode"
        << ": [" << getCountryCode() << "]\n";

    if (getCountryCode() == "CA") {
        std::cout << std::left
            << std::setw(17) << "Province"
            << ": [" << getProvince() << "]\n";
    }
    std::cout << std::left
        << std::setw(17) << "LogDate"
        << ": [" << getLogDate() << "]\n"
        << std::setw(17) << "UniqueWellId"
        << ": [" << getUniqueWellId() << "]\n"
        << std::setw(17) << "ApiNumber"
        << ": [" << getApiNumber() << "]\n"
        << std::setw(17) << "License"
        << ": [" << getLicense() << "]\n"
        << std::setw(17) << "Latitude"
        << ": [" << getLatitude() << "]\n"
        << std::setw(17) << "Longitude"
        << ": [" << getLongitude() << "]\n"
        << std::setw(17) << "GeodeticDatum"
        << ": [" << getGeodeticDatum() << "]\n"
        << "# ------------------------------------------------------\n\n";

}
