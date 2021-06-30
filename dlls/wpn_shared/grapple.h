/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   This source code contains proprietary and confidential information of
*   Valve LLC and its suppliers.  Access to this code is restricted to
*   persons who have executed a written SDK license with Valve.  Any access,
*   use or distribution of this code by or to any unlicensed person is illegal.
*
****/

#ifndef GRAPPLE_H
#define GRAPPLE_H

class CBarnacleGrapple : public CBasePlayerWeaponU
{
public:
	enum FireState
	{
		OFF = 0,
		CHARGE  = 1
	};

	void Precache( void );
	void Spawn( void );
	void EndAttack( void );

	int iItemSlot( void ) { return 1; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer* pPlayer );
	BOOL Deploy();
	void Holster( int skiplocal /* = 0 */ );
	void WeaponIdle( void );
	void PrimaryAttack( void );

	void Fire( Vector vecOrigin, Vector vecDir );

	void CreateEffect( void );
	void UpdateEffect( void );
	void DestroyEffect( void );
	virtual BOOL UseDecrement(void)
	{
		return FALSE;
	}
private:
	CBarnacleGrappleTip* m_pTip;

	CBeam* m_pBeam;

	float m_flShootTime;
	float m_flDamageTime;

	FireState m_FireState;

	bool m_bGrappling;
	bool m_bMissed;
	bool m_bMomentaryStuck;
};

#endif // GRAPPLE_H