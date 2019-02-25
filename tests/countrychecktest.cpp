#include "auction.h"

using namespace Auction;

int main()
{
    // проверить что все банеры удовлетворяют условию страны
    std::vector<Banner> banners;
    banners.emplace_back(Banner{ 200, 1,{ CountryId::RUSSIA, CountryId::USA, CountryId::FRANCE } });
    banners.emplace_back(Banner{ 100, 2,{ CountryId::USA, CountryId::FRANCE } });
    banners.emplace_back(Banner{ 400, 3,{ CountryId::GERMANY } });
    banners.emplace_back(Banner{ 300, 2,{ CountryId::GERMANY } });
    banners.emplace_back(Banner{ 400, 7,{ CountryId::RUSSIA, CountryId::GERMANY } });
    banners.emplace_back(Banner{ 400, 6,{ CountryId::RUSSIA, CountryId::UK } });

    AuctionControl auction;
    std::vector<Banner> filtered;
    auto filtrationResult = auction.bannerfilter<CountryId>(banners, filtered, 3, CountryId::GERMANY, &AuctionControl::countryFilter);
    if (filtrationResult == Status::SUCCESS || filtrationResult == Status::NOT_FATAL)
    {
        for (const auto& banner : filtered)
        {
            if (banner.m_countryList.size() &&
                (std::find(std::begin(banner.m_countryList), std::end(banner.m_countryList), CountryId::GERMANY) == banner.m_countryList.end()))
            {
                return 1;
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}