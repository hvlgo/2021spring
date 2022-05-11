#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"


class UserProxy : public User
{
    EncryptStrategy* my_EncryptStrategy;
    VerificationStrategy* my_VerificationStrategy;
    RealUser* my_RealUser;
public:
    UserProxy(RealUser* real, EncryptStrategy* encrypt, VerificationStrategy* verification) : my_RealUser(real), my_EncryptStrategy(encrypt), my_VerificationStrategy(verification) {}
    void sendMessage(std::string message)
    {
        std::string mes = my_EncryptStrategy->encode(message);
        my_RealUser->sendMessage(mes);
        std::string mes_next = my_VerificationStrategy->verify(message);
        std::cout << mes_next << std::endl;
    }
};