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

#ifndef BMODELS_H
#define BMODELS_H


// =================== FUNC_WALL ==============================================

/*QUAKED func_wall (0 .5 .8) ?
This is just a solid wall if not inhibited
*/
class CFuncWall : public CBaseEntity
{
public:
	void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

	// Bmodels don't go across transitions
	virtual int ObjectCaps( void ) { return CBaseEntity :: ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
};

class CFuncWallToggle : public CFuncWall
{
public:
	void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void TurnOff( void );
	void TurnOn( void );
	BOOL IsOn( void );
};

class CFuncConveyor : public CFuncWall
{
public:
	void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void UpdateSpeed( float speed );
};

// =================== FUNC_ILLUSIONARY ==============================================


/*QUAKED func_illusionary (0 .5 .8) ?
A simple entity that looks solid but lets you walk through it.
*/
class CFuncIllusionary : public CBaseToggle 
{
public:
	void Spawn( void );
	void EXPORT SloshTouch( CBaseEntity *pOther );
	void KeyValue( KeyValueData *pkvd );
	virtual int ObjectCaps( void ) { return CBaseEntity :: ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
};

// -------------------------------------------------------------------------------
//
// Monster only clip brush
// 
// This brush will be solid for any entity who has the FL_MONSTERCLIP flag set
// in pev->flags
//
// otherwise it will be invisible and not solid.  This can be used to keep 
// specific monsters out of certain areas
//
// -------------------------------------------------------------------------------
class CFuncMonsterClip : public CFuncWall
{
public:
	void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value ) {}		// Clear out func_wall's use function
};

// =================== FUNC_ROTATING ==============================================
class CFuncRotating : public CBaseEntity
{
public:
	// basic functions
	void Spawn( void  );
	void Precache( void  );
	void EXPORT SpinUp( void );
	void EXPORT SpinDown( void );
	void KeyValue( KeyValueData* pkvd);
	void EXPORT HurtTouch( CBaseEntity *pOther );
	void EXPORT RotatingUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT Rotate( void );
	void RampPitchVol(int fUp );
	void Blocked( CBaseEntity *pOther );
	virtual int ObjectCaps( void ) { return CBaseEntity :: ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );

	static TYPEDESCRIPTION m_SaveData[];

	float m_flFanFriction;
	float m_flAttenuation;
	float m_flVolume;
	float m_pitch;
	int m_sounds;
};

class CPendulum : public CBaseEntity
{
public:
	void Spawn( void );
	void KeyValue( KeyValueData *pkvd );
	void EXPORT Swing( void );
	void EXPORT PendulumUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT Stop( void );
	void Touch( CBaseEntity *pOther );
	void EXPORT RopeTouch( CBaseEntity *pOther );// this touch func makes the pendulum a rope
	virtual int ObjectCaps( void ) { return CBaseEntity :: ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	void Blocked( CBaseEntity *pOther );

	static TYPEDESCRIPTION m_SaveData[];

	float m_accel;			// Acceleration
	float m_distance;
	float m_time;
	float m_damp;
	float m_maxSpeed;
	float m_dampSpeed;
	vec3_t m_center;
	vec3_t m_start;
};

#endif // BMODELS_H