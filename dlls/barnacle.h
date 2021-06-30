/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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

#ifndef BARNACLE_H
#define BARNACLE_H

#define	BARNACLE_AE_PUKEGIB	2

class CBarnacle : public CBaseMonster
{
public:
	void Spawn( void );
	void Precache( void );
	CBaseEntity *TongueTouchEnt( float *pflLength );
	int Classify( void );
	void HandleAnimEvent( MonsterEvent_t *pEvent );
	void EXPORT BarnacleThink( void );
	void EXPORT WaitTillDead( void );
	void Killed( entvars_t *pevAttacker, int iGib );
	int TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType );
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];

	float m_flAltitude;
	float m_flCachedLength;	// tongue cached length
	float m_flKillVictimTime;
	int m_cGibs;		// barnacle loads up on gibs each time it kills something.
	BOOL m_fTongueExtended;
	BOOL m_fLiftingPrey;
	float m_flTongueAdj;

	// FIXME: need a custom barnacle model with non-generic hitgroup
	// otherwise we can apply to damage to tongue instead of body
#ifdef BARNACLE_FIX_VISIBILITY
	void SetObjectCollisionBox( void )
	{
		pev->absmin = pev->origin + Vector( -16, -16, -m_flCachedLength );
		pev->absmax = pev->origin + Vector( 16, 16, 0 );
	}
#endif
};

#endif // BARNACLE_H