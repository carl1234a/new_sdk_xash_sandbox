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

#ifndef OTIS_H
#define OTIS_H

// first flag is Otis dying for scripted sequences?
#define		OTIS_AE_DRAW		( 2 )
#define		OTIS_AE_SHOOT		( 3 )
#define		OTIS_AE_HOLSTER		( 4 )

#define OTIS_BODY_GUNHOLSTERED	0
#define OTIS_BODY_GUNDRAWN		1
#define OTIS_BODY_DONUT			2

class COtis : public CBarney
{
public:
	void KeyValue(KeyValueData *pkvd);

	void Spawn(void);
	void Precache(void);
	void BarneyFirePistol(void);
	void AlertSound(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);

	int TakeDamage(entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType);

	void DeclineFollowing(void);

	// Override these to set behavior
	Schedule_t *GetSchedule(void);

	void TalkInit(void);
	void TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);
	void Killed(entvars_t *pevAttacker, int iGib);

	int		head;
	int		bodystate;
};

#endif // OTIS_H