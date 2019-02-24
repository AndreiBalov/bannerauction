#include "auction.h"

using namespace Auction;    
	
bool AuctionControl::countryFilter(const Banner* banner, CountryId country)
{
	if (!banner->m_countryList.size()
		|| std::find(std::begin(banner->m_countryList), std::end(banner->m_countryList), country) != banner->m_countryList.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}