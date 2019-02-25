#include "auction.h"

using namespace Auction;

int main()
{
    // если подходящих баннеров больше чем оставшихся мест, то баннеры будут выбраны случайно
    std::vector<Banner> banners;
    banners.emplace_back(Banner{ 200, 1,{ CountryId::RUSSIA, CountryId::USA, CountryId::FRANCE } });
    banners.emplace_back(Banner{ 200, 2,{ CountryId::USA, CountryId::FRANCE, CountryId::RUSSIA } });
    banners.emplace_back(Banner{ 200, 3,{ CountryId::GERMANY, CountryId::RUSSIA } });
    banners.emplace_back(Banner{ 200, 4,{} });
    banners.emplace_back(Banner{ 200, 5,{} });
    banners.emplace_back(Banner{ 200, 6,{} });

    AuctionControl auction;
    std::vector<Banner> filtered;
    auto resultStatus = auction.bannerfilter<CountryId>(banners, filtered, 3, CountryId::RUSSIA, &AuctionControl::countryFilter);

    if (resultStatus == Status::SUCCESS || resultStatus == Status::NOT_FATAL)
    {
        std::set<int> uniqueCheck;
        for (auto& banner : filtered)
        {
            auto res = uniqueCheck.insert(banner.m_uid);
            if (!res.second)
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