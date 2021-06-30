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

#ifndef MORTAR_H
#define MORTAR_H

class CFuncMortarField : public CBaseToggle
{
public:
	void Spawn( void );
	void Precache( void );
	void KeyValue( KeyValueData *pkvd );

	// Bmodels don't go across transitions
	virtual int ObjectCaps( void ) { return CBaseToggle::ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }

	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );

	static TYPEDESCRIPTION m_SaveData[];

	void EXPORT FieldUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

	string_t m_iszXController;
	string_t m_iszYController;
	float m_flSpread;
	float m_flDelay;
	int m_iCount;
	int m_fControl;
};

class CMortar : public CGrenade
{
public:
	void Spawn( void );
	void Precache( void );

	void EXPORT MortarExplode( void );

	int m_spriteTexture;
};

#endif // MORTAR_H