#ifndef BANNER_H
#define BANNER_H

#include <stdint.h>
#include <vector>

namespace Auction
{

using BannerId = int;

enum class CountryId : uint16_t
{
    RUSSIA,
    USA,
    GERMANY,
    GREECE,
    UK,
    FRANCE,
    COUNTRY_COUNT
};

struct Banner
{
    explicit Banner(uint32_t price, BannerId uid, std::vector<CountryId> contryList)
        : m_price(price), m_uid(uid), m_countryList(contryList)
    {
    }

    explicit Banner() : m_price(0), m_uid(-1)
    {
    }

    Banner(const Banner& from) = default;
    Banner& operator = (const Banner& rhv) = default;
    Banner(Banner&& from) = default;
    Banner& operator = (Banner&& from) = default;

    uint32_t m_price;
    BannerId m_uid;
    std::vector<CountryId> m_countryList;
};

}


#endif