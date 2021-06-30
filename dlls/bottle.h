/***
*
*	Copyright (c) nillerusr All rights FUCKED
*
****/

#ifndef BOTTLE_H
#define BOTTLE_H

class CBottle : public CProp
{
public:
	void Spawn( void );
	void PropRespawn();
	void EXPORT BottleTouch( CBaseEntity *pOther );
};

#endif // BOTTLE_H