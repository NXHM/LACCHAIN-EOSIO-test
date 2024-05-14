#include <eosio/eosio.hpp>
using namespace eosio;
CONTRACT helloword : public contract {
  public:
    using contract::contract;
    ACTION hi(name user) {
        require_auth( user);// retorna error, termina la ejecucion
        check(user!=name("stranger"), "You will not receive a hi from me...")
        print("Hi, ", user, "!");
    }
    ACTION hello(name user){
        if(has_auth(user)){// retorna falso, si no tiene la autorización adjunta, no termina la ejecución
            print("Hello,",user);
        }else{
            print("Hello, stranger...");
        }
    }
    ACTION hello_by_smart_contract_owner(name user){
        //_self es un simil
        if(has_auth(get_self())){// retorna falso, si no es el , no termina la ejecución
        // se solicita el permiso del dueño del smart contract no del usuario
            print("Hello,",user);
        }else{
            print("Hello, stranger...");
        }
    }
};