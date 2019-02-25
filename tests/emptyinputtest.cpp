#include "auction.h"

using namespace Auction;

int main()
{
    // на вход пустой массив
    std::vector<Banner> banners;
    AuctionControl auction;
    std::vector<Banner> filtered;
    auto filtrationResult = auction.bannerfilter<CountryId>(banners, filtered, 3, CountryId::RUSSIA, &AuctionControl::countryFilter);
    if (filtrationResult == Status::INVALID_ARGUMENT || filtrationResult == Status::NOT_FATAL)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}