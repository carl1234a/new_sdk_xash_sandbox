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

#ifndef GONOME_H
#define GONOME_H

class CGonomeGuts : public CSquidSpit
{
public:
	void Spawn(void);
	void Touch(CBaseEntity *pOther);
};

class CGonome : public CBaseMonster
{
public:

	void Spawn(void);
	void Precache(void);

	int  Classify(void);
	void SetYawSpeed();
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	int IgnoreConditions();
	void IdleSound( void );
	void PainSound( void );
	void DeathSound( void );
	void AlertSound( void );
	void StartTask(Task_t *pTask);

	BOOL CheckMeleeAttack2(float flDot, float flDist);
	BOOL CheckRangeAttack1(float flDot, float flDist);
	void SetActivity( Activity NewActivity );

	Schedule_t *GetSchedule();
	Schedule_t *GetScheduleOfType( int Type );
	void RunTask(Task_t* pTask);

	int TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
	void Killed(entvars_t *pevAttacker, int iGib);

	void UnlockPlayer();
	CGonomeGuts* GetGonomeGuts(const Vector& pos);
	void ClearGuts();

	int	Save(CSave &save);
	int Restore(CRestore &restore);

	CUSTOM_SCHEDULES
	static TYPEDESCRIPTION m_SaveData[];

	static const char* pPainSounds[];
	static const char* pIdleSounds[];
	static const char* pDeathSounds[];
	static const char *pAttackHitSounds[];
	static const char *pAttackMissSounds[];

	virtual int SizeForGrapple() { return GRAPPLE_LARGE; }
protected:
	float m_flNextFlinch;
	float m_flNextThrowTime;// last time the gonome used the guts attack.
	CGonomeGuts* m_pGonomeGuts;
#if FEATURE_GONOME_LOCK_PLAYER
	BOOL m_fPlayerLocked;
	EHANDLE m_lockedPlayer;
#endif
	bool m_meleeAttack2;
	bool m_playedAttackSound;
};

class CDeadGonome : public CBaseMonster
{
public:
	void Spawn(void);
	int	Classify(void) { return	CLASS_ALIEN_MONSTER; }
	void KeyValue( KeyValueData *pkvd );
	int m_iPose;
	static const char *m_szPoses[3];
};

class CGonome : public CBaseMonster
{
public:

	void Spawn(void);
	void Precache(void);

	int  Classify(void);
	void SetYawSpeed();
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	int IgnoreConditions();
	void IdleSound( void );
	void PainSound( void );
	void DeathSound( void );
	void AlertSound( void );
	void StartTask(Task_t *pTask);

	BOOL CheckMeleeAttack2(float flDot, float flDist);
	BOOL CheckRangeAttack1(float flDot, float flDist);
	void SetActivity( Activity NewActivity );

	Schedule_t *GetSchedule();
	Schedule_t *GetScheduleOfType( int Type );
	void RunTask(Task_t* pTask);

	int TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);
	void Killed(entvars_t *pevAttacker, int iGib);

	void UnlockPlayer();
	CGonomeGuts* GetGonomeGuts(const Vector& pos);
	void ClearGuts();

	int	Save(CSave &save);
	int Restore(CRestore &restore);

	CUSTOM_SCHEDULES
	static TYPEDESCRIPTION m_SaveData[];

	static const char* pPainSounds[];
	static const char* pIdleSounds[];
	static const char* pDeathSounds[];
	static const char *pAttackHitSounds[];
	static const char *pAttackMissSounds[];

	virtual int SizeForGrapple() { return GRAPPLE_LARGE; }
protected:
	float m_flNextFlinch;
	float m_flNextThrowTime;// last time the gonome used the guts attack.
	CGonomeGuts* m_pGonomeGuts;
#if FEATURE_GONOME_LOCK_PLAYER
	BOOL m_fPlayerLocked;
	EHANDLE m_lockedPlayer;
#endif
	bool m_meleeAttack2;
	bool m_playedAttackSound;
};

#endif // GONOME_H