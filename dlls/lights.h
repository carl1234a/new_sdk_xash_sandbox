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

#ifndef LIGHTS_H
#define LIGHTS_H

class CLight : public CPointEntity
{
public:
	virtual void KeyValue( KeyValueData* pkvd ); 
	virtual void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );

	static TYPEDESCRIPTION m_SaveData[];

private:
	int m_iStyle;
	string_t m_iszPattern;
};

class CEnvLight : public CLight
{
public:
	void KeyValue( KeyValueData* pkvd ); 
	void Spawn( void );
};

#endif // LIGHTS_H