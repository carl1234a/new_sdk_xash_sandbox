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

#ifndef PIPEWRENCH_H
#define PIPEWRENCH_H

class CPipeWrench : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

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
	void WeaponIdle(void);
	void Holster(int skiplocal = 0);
	void BigSwing(void);

	int m_iSwing;
	TraceResult m_trHit;
	int m_iSwingMode;
	float m_flBigSwingStart;
	int m_iBigSwingHit;

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:

	unsigned short m_usPWrench;
};

#endif // PIPEWRENCH_H