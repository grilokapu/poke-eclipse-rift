#ifndef GUARD_ER_TRAINER_CARD_H
#define GUARD_ER_TRAINER_CARD_H

enum ERBadge
{
    ER_BADGE_ROCHAREACH,
    ER_BADGE_LEAFBOND,
    ER_BADGE_MINDSEAL,
    ER_BADGE_COUNT,
};

void ShowERTrainerCard(void (*callback)(void));
void ShowERBadgeObtainSprite(void);
void HideERBadgeObtainSprite(void);

#endif // GUARD_ER_TRAINER_CARD_H
