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
    auto banneroutput = auction.bannerfilterVT<CountryId>(banners, filtered, 3, CountryId::RUSSIA, &AuctionControl::countryFilter);


    //auto banneroutput2 = auction.bannerfilterVT<CountryId>(banners, filtered2, 3, CountryId::RUSSIA, &AuctionControl::countryFilter);

   // auto banneroutput1 = bannerfilter(banners, filtered1, /*slotCount*/3, CountryId::RUSSIA);
   // auto banneroutput2 = bannerfilter(banners, filtered2, /*slotCount*/3, CountryId::RUSSIA);

    //if (banneroutput1 && banneroutput2)
    //{
    //    if (filtered1 == filtered2)
    //    {
    //        return 1;
    //    }
    //    else
    //    {
    //        return 0;
    //    }
    //}
    //else
    //{
    //    return 0;
    //}
}