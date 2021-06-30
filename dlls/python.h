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

#ifndef PYTHON_H
#define PYTHON_H

class CPython : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 2; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );
	float m_flSoundDelay;

	BOOL m_fInZoom;// don't save this. 

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usFirePython;
};

class CPythonAmmo : public CBasePlayerAmmo
{
	void Spawn( void )
	{ 
		Precache();
		SET_MODEL( ENT(pev), "models/w_357ammobox.mdl" );
		CBasePlayerAmmo::Spawn();
	}
	void Precache( void )
	{
		PRECACHE_MODEL( "models/w_357ammobox.mdl" );
		PRECACHE_SOUND( "items/9mmclip1.wav" );
	}
	BOOL AddAmmo( CBaseEntity *pOther )
	{ 
		if( pOther->GiveAmmo( AMMO_357BOX_GIVE, "357", _357_MAX_CARRY ) != -1 )
		{
			EMIT_SOUND( ENT( pev ), CHAN_ITEM, "items/9mmclip1.wav", 1, ATTN_NORM );
			return TRUE;
		}
		return FALSE;
	}
};

#endif // PYTHON_H