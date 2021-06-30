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

#ifndef KNIFE_H
#define KNIFE_H

class CKnife : public CBasePlayerWeaponU
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 1; }
	void EXPORT SwingAgain(void);
	void EXPORT Smack(void);
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack(void);
	void SecondaryAttack(void);
	int Swing(int fFirst);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	int m_iSwing;
	TraceResult m_trHit;
};

#endif // KNIFE_H