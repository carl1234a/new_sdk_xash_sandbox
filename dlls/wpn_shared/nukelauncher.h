/*
	Copyright (c) 1999, Cold Ice Modification. 
	
	This code has been written by SlimShady ( darcuri@optonline.net )

    Use, distribution, and modification of this source code and/or resulting
    object code is restricted to non-commercial enhancements to products from
    Valve LLC.  All other use, distribution, or modification is prohibited
    without written permission from Valve LLC and from the Cold Ice team.

    Please if you use this code in any public form, please give us credit.
*/

#ifndef NUKELAUNCHER_H
#define NUKELAUNCHER_H

class CNuke : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	void Reload( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	BOOL Deploy( void );
	BOOL CanHolster( void );
	void Holster( void );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	void WeaponIdle( void );
	BOOL ShouldWeaponIdle( void ) { return TRUE; };
};

class CNukeRocket : public CGrenade
{
public:
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
	void Spawn( void );
	void Precache( void );
	void EXPORT IgniteThink( void );	
	void EXPORT BlowMeUp( void );
	void EXPORT FollowThink( void );
	void EXPORT RocketTouch( CBaseEntity *pOther );
	static CNukeRocket *CreateNukeRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CNuke *pLauncher );

	int m_iSpriteTexture;
	int m_iExplode;
	int m_iBalls;

	int killit;

	int m_iTrail;
	float m_flIgniteTime;
	CNuke *m_pLauncher;
};

class CNukeAmmo : public CBasePlayerAmmo
{
	void Spawn( void )
	{ 
		Precache( );
		SET_MODEL(ENT(pev), "models/w_rpgammo.mdl");
		CBasePlayerAmmo::Spawn( );
	}
	void Precache( void )
	{
		PRECACHE_MODEL ("models/w_rpgammo.mdl");
		PRECACHE_SOUND("items/9mmclip1.wav");
	}
	BOOL AddAmmo( CBaseEntity *pOther ) 
	{ 
		int iGive;
		iGive = AMMO_NUKECLIP_GIVE;
	
		if (pOther->GiveAmmo( iGive, "nuke", NUKE_MAX_CARRY ) != -1)
		{
			EMIT_SOUND(ENT(pev), CHAN_ITEM, "items/9mmclip1.wav", 1, ATTN_NORM);
			return TRUE;
		}
		return FALSE;
	}
};

#endif // NUKELAUNCHER_H