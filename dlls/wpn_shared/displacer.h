/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
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

#ifndef DISPLACER_H
#define DISPLACER_H

class CDisplacer : public CBasePlayerWeaponU
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo( ItemInfo *p );
	int AddToPlayer( CBasePlayer *pPlayer );
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void WeaponIdle( void );

	BOOL PlayEmptySound( void );

	void UseAmmo(int count);
	BOOL CanFireDisplacer( int count ) const;

	enum DISPLACER_FIREMODE { FIREMODE_FORWARD = 1, FIREMODE_BACKWARD };

	void ClearSpin( void );
	void EXPORT SpinUp( void );
	void EXPORT Teleport( void );
	void EXPORT Displace( void );
	int m_iLight;
private:
	int m_iFireMode;
};

class CDisplacerBall : public CBaseEntity
{
public:
	void Spawn( void );

	static void Shoot(entvars_t *pevOwner, Vector vecStart, Vector vecVelocity, Vector vecAngles);
	static void SelfCreate(entvars_t *pevOwner, Vector vecStart);

	void Touch(CBaseEntity *pOther);
	void EXPORT ExplodeThink( void );
	void EXPORT KillThink( void );
	void Circle( void );

	virtual int		Save(CSave &save);
	virtual int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];

	CBeam* m_pBeam[8];

	void EXPORT FlyThink( void );
	void ClearBeams( void );
	void ArmBeam( int iSide );

	int m_iBeams;
	int m_iTrail;

	CBaseEntity *pRemoveEnt;
	int m_iGravUse;

	float TouchGravGun( CBaseEntity *attacker, int stage)
	{
		pev->owner = attacker->edict();
		if( stage == 2 )
		{
			m_iGravUse = 1;
			Touch( attacker );
		}

		return 300;
	}
};

#endif // DISPLACER_H