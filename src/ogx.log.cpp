#include <ogx.log/ogx.log.hpp>

namespace eosio {

    //action
    void ogxlog::logexentry(
            eosio::name account,
            eosio::symbol src,
            eosio::asset amount,
            eosio::symbol dest,
            eosio::asset amountReceived,
            uint128_t exchangeFeeRate,
            uint64_t timestamp,
            uint64_t roundIdForSrc,
            uint64_t roundIdForDest
    ) {
        require_auth(OGX_CODE);
        require_recipient(account);
    }

    //action
    void ogxlog::logreclaim(
            eosio::name from,
            eosio::symbol currencyKey,
            eosio::asset amount
    ) {
        require_auth(OGX_CODE);
        require_recipient(from);
    }

    //action
    void ogxlog::logrefund(
            eosio::name from,
            eosio::symbol currencyKey,
            eosio::asset amount
    ) {
        require_auth(OGX_CODE);
        require_recipient(from);
    }

    ogxlog::~ogxlog() {
    }

} /// namespace eosio
