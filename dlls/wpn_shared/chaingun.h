/*
	Copyright (c) 1999, Cold Ice Modification. 
	
	This code has been written by SlimShady ( darcuri@optonline.net )

    Use, distribution, and modification of this source code and/or resulting
    object code is restricted to non-commercial enhancements to products from
    Valve LLC.  All other use, distribution, or modification is prohibited
    without written permission from Valve LLC and from the Cold Ice team.

    Please if you use this code in any public form, please give us credit.

*/

#ifndef CHAINGUN_H
#define CHAINGUN_H

class CChaingun : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 3; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	void PrimaryAttack( void );
	void ChaingunFire( float flSpread, float flCycleTime, BOOL fUseAutoAim ,int b_no);
	BOOL Deploy( void );
	void Reload( void );
	void BringUp( void );
	void WeaponIdle( void );
	void Slowdown();
	void EXPORT firemore(void);
	int phase;
	float cycletime;
	int fps;
	int m_iShell;
};

class CChaingunBox : public CBasePlayerAmmo
{
	void Spawn( void )
	{ 
		Precache( );
		SET_MODEL(ENT(pev), "models/ammo/w_chain.mdl");
		CBasePlayerAmmo::Spawn( );
	}
	void Precache( void )
	{
		PRECACHE_MODEL ("models/ammo/w_chain.mdl");
		PRECACHE_SOUND("items/9mmclip1.wav");
	}
	BOOL AddAmmo( CBaseEntity *pOther ) 
	{ 
		int bResult = (pOther->GiveAmmo( AMMO_CHAINGUNBOX_GIVE, "chain", CHAINGUN_MAX_CARRY) != -1);
		if (bResult)
		{
			EMIT_SOUND(ENT(pev), CHAN_ITEM, "items/9mmclip1.wav", 1, ATTN_NORM);
		}
		return bResult;
	}
};

#endif // CHAINGUN_H