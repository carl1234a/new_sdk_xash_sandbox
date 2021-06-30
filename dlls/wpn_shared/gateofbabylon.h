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

#ifndef GATEOFBABYLON_H
#define GATEOFBABYLON_H

class CGateOfBabylonSpawner;
#define MAX_SPAWNERS 7
class CGateOfBabylon : public CBasePlayerWeaponU
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( ) { return 0; }
	int GetItemInfo(ItemInfo *p);
	int ObjectCaps();
#ifndef CLIENT_DLL
	int Save( CSave &save );
	int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];
#endif
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	int AddToPlayer( CBasePlayer *pPlayer );
	BOOL Deploy( );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );

	EHANDLE m_pSpawners[MAX_SPAWNERS];
	bool IntersectOtherSpawner( CGateOfBabylonSpawner *spawner );

private:

	void AddSpawners( void );
	int m_iSpawnerCount;
};


class CGateOfBabylonBolt : public CBaseEntity
{
public:
	static CGateOfBabylonBolt *BoltCreate( void );

private:
	void Spawn( void );
	void Precache( void );
	void EXPORT BubbleThink( void );
	void EXPORT BoltTouch( CBaseEntity *pOther );
	void EXPORT RemoveThink();
	void Trail( void );
	float TouchGravGun( CBaseEntity *attacker, int stage );
	int m_iTrail;
};

class CGateOfBabylonSpawner : public CBaseEntity
{
public:
	static CGateOfBabylonSpawner *CreateSpawner( CGateOfBabylon *pGates, int iNumber );

private:
	void Spawn( void );
	void Precache( void );
	int Save( CSave &save );
	int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];
	void UpdatePosition( void );
	void Animate( void );
	void EXPORT FollowPlayerThink( void );
	bool FireBolts( void );

	EHBasePlayerItem m_pGates;
	Vector m_vecOffset;
	float m_flNextNPThrow;
	float m_flLastTimeAnim;
	int m_iNumber;
	int m_iMaxFrames;

	friend class CGateOfBabylon;
};

#endif // GATEOFBABYLON_H