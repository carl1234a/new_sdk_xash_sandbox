//========= Copyright (c) 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: New version of the slider bar
//
// $NoKeywords: $
//=============================================================================

#ifndef PLAYERMONSTER_H
#define PLAYERMONSTER_H

//=========================================================
// Monster's Anim Events Go Here
//=========================================================

class CPlayerMonster : public CBaseMonster
{
public:
	void Spawn( void );
	void Precache( void );
	void SetYawSpeed( void );
	int Classify( void );
	void HandleAnimEvent( MonsterEvent_t *pEvent );
	int ISoundMask( void );
};

#endif // PLAYERMONSTER_H