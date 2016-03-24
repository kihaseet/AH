#include "commonitemscollection.h"
#include "investigator/player.h"


void Common18Derringer::useCardAction()
{
    static_cast<investigator*>(place)->appendCardInHands(this);
}

void Common18Derringer::stopUseCardAction()
{
    static_cast<investigator*>(place)->removeCardFromHands(this);
}
