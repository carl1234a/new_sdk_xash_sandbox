/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#ifndef MONSTERMAKER_H
#define MONSTERMAKER_H

//=========================================================
// MonsterMaker - this ent creates monsters during the game.
//=========================================================
class CMonsterMaker : public CBaseMonster
{
public:
	void Spawn( void );
	void Precache( void );
	void KeyValue( KeyValueData* pkvd);
	void EXPORT ToggleUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT CyclicUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT MakerThink( void );
	void DeathNotice( entvars_t *pevChild );// monster maker children use this to tell the monster maker that they have died.
	void MakeMonster( void );

	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );

	static TYPEDESCRIPTION m_SaveData[];
	
	string_t m_iszMonsterClassname;// classname of the monster(s) that will be created.
	
	int m_cNumMonsters;// max number of monsters this ent can create
	
	int m_cLiveChildren;// how many monsters made by this monster maker that are currently alive
	int m_iMaxLiveChildren;// max number of monsters that this maker may have out at one time.

	float m_flGround; // z coord of the ground under me, used to make sure no monsters are under the maker when it drops a new child

	BOOL m_fActive;
	BOOL m_fFadeChildren;// should we make the children fadeout?
};

#endif // MONSTERMAKER_H