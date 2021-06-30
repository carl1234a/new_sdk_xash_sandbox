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

#ifndef SHOCKRIFLE_H
#define SHOCKRIFLE_H

class CShockrifle : public CBasePlayerWeaponU
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 5; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);

	void PrimaryAttack(void);
	void SecondaryAttack(void);
	BOOL Deploy(void);
	//BOOL HasAmmo(void){return TRUE;}
	//BOOL CanDeploy(void){return TRUE;}
	BOOL IsUseable(void){return TRUE;}
	void Holster(int skiplocal = 0);
	void Reload(void);
	void WeaponIdle(void);
	float m_flRechargeTime;
	int m_iLight;
};

#endif // SHOCKRIFLE_H