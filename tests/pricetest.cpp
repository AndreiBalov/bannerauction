#include "auction.h"

using namespace Auction;

int main()
{
    // в выбору должны попадать банеры с самой высокой ценой
    std::vector<Banner> banners;
    banners.emplace_back(Banner{ 200, 1,{ CountryId::RUSSIA, CountryId::USA, CountryId::FRANCE } });
    banners.emplace_back(Banner{ 100, 2,{ CountryId::USA, CountryId::FRANCE, CountryId::RUSSIA } });
    banners.emplace_back(Banner{ 100, 6,{ CountryId::GERMANY, CountryId::RUSSIA } });
    banners.emplace_back(Banner{ 400, 3,{} });
    banners.emplace_back(Banner{ 600, 4,{} });
    banners.emplace_back(Banner{ 500, 4,{} });

    std::vector<Banner> filtered;
    AuctionControl auction;
    auto filtrationResult = auction.bannerfilter<CountryId>(banners, filtered, /*slotCount*/3, CountryId::RUSSIA, &AuctionControl::countryFilter);
    if (filtrationResult == Status::SUCCESS || filtrationResult == Status::NOT_FATAL)
    {
        auto result = std::find_if(std::begin(filtered), std::end(filtered), [](const Banner& banner)
        {
            return banner.m_price < 200;
        });
        return result != filtered.end() ? 1 : 0;
    }
    else
    {
        return 1;
    }
}