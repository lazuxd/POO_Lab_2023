#include "LivingBeing.hpp"

LivingBeing::LivingBeing()
: isAlive(true)
{
}

LivingBeing::~LivingBeing()
{
}

bool LivingBeing::getIsAlive() const
{
    return isAlive;
}

void LivingBeing::kill()
{
    isAlive = false;
}
