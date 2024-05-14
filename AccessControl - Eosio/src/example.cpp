#include <eosio/eosio.hpp>

using namespace eosio;

// CONTRACT es una macro de
// class [[eosio::contract]]

CONTRACT toyhaus : public contract {
  public:
  // se declaran aca las tablas y acciones
    using contract::contract;
     
     // [[eosio::action]] void
    ACTION welcome( name arrival){
        // require_auth(get_self()); significa que sola la cuenta que desplego el contrato puede ejecutar la accion
        // require_auth(arrival); significa que solo la cuenta que llamo la accion puede ejecutarla
        //require_auth(name("toyGOD"));
        check( has_auth(name("toyGOD")), "Only toyGODs friends and himself can call this action - Don´t try to play me");
        // if, error si no se cumple la condicion
        check( arrival == name("toyGOD"), "Only toyGOD can call this action - Don´t lie bout your name")
        print("Welcome to Toyhaus OWO, ", arrival);
    } 
}