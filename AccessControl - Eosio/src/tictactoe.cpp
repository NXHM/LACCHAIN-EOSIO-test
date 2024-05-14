#include <eosio/eosio.hpp>

using namespace eosio;
CONTRACT tictactoe : public contract {
  public:
    using contract::contract;
    ACTION welcome(name host, name opponent) {
        require_auth(has_auth(get_self()));// retorna error, termina la ejecucion
        print("Welcome...", host, "and...", opponent);
    }
    
};