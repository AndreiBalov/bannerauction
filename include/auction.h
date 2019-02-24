#ifndef AUCTION_H
#define AUCTION_H

#include "banner.h"

#include <functional>
#include <algorithm>
#include <map>
#include <set>
#include <random>

namespace Auction
{

enum class Status : int8_t
{
    INVALID_ARGUMENT = -3,
    UNSUPPORTED = -2,
    FAILED = -1,
    SUCCESS = 0,
    NOT_FATAL = 1
};

class AuctionControl
{
public:
    template <class FType, class FFunc>
    Status bannerfilter(const std::vector<Banner>& bannersInput, std::vector<Banner>& bannersOutput,
        const uint32_t slotsCount, FType filterArg, FFunc filterFunction/*std::function<bool(AuctionControl&, const Banner*, FType)>*/)
    {
        if (!bannersInput.size())
            return Status::INVALID_ARGUMENT;

        if (!slotsCount)
            return Status::INVALID_ARGUMENT;

        // для группировки по ценам и сортировки
        std::multimap<uint32_t, const Banner*> auxMap;
        for (const auto& banner : bannersInput)
        {
            auxMap.insert(std::pair<uint32_t, const Banner*>(banner.m_price, &banner));
        }

        std::set<int> idCheck; // для соблюдения уникальности id 
        size_t leftSlots = slotsCount;
        // с конца потому что отсортировано по возрастанию
        for (auto crb = auxMap.crbegin(); crb != auxMap.crend(); ++crb)
        {
            auto res = auxMap.equal_range(crb->second->m_price);
            std::vector<const Banner*> suitableBanners;
            size_t count = std::count_if(res.first, res.second,
                [&filterArg, &filterFunction, &suitableBanners, &idCheck](std::pair<const uint32_t, const Banner*>& pair)
            {
                auto& banner = pair.second;
                if(filterFunction(banner, filterArg))
                {
                    // проверка уникального id
                    if (idCheck.find(banner->m_uid) == idCheck.end())
                    {
                        idCheck.insert(banner->m_uid);
                        suitableBanners.emplace_back(banner);
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            });

            if (count)
            {
                if (leftSlots < count)
                {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(0, static_cast<int>(count - 1));
                    std::set<int> uniqueCheck;
                    while (leftSlots)
                    {
                        auto randomPos = dis(rd);
                        auto insertResult = uniqueCheck.insert(randomPos);
                        if (insertResult.second)
                        {
                            bannersOutput.push_back(*suitableBanners[randomPos]);
                            leftSlots--;
                        }
                    }
                }
                else
                {
                    for (auto banner : suitableBanners)
                    {
                        bannersOutput.push_back(*banner);
                    }
                    leftSlots -= suitableBanners.size();
                }

                if (bannersOutput.size() == slotsCount)
                    return Status::SUCCESS;
            }
        }

        if (bannersOutput.size() > 0 && bannersOutput.size() != slotsCount)
        {
            return Status::NOT_FATAL;
        }
        else
        {
            return Status::FAILED;
        }
    }

    /*!
    * Фильтр по странам
    * /brief Для добавления фильтра по другом упараметру перегрузите эту функцию с другим вторым параметром
    */
    static bool countryFilter(const Banner* banner, CountryId country);
};

}

#endif