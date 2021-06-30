#ifndef AR2_H
#define AR2_H

class CAR2 : public CBasePlayerWeaponU
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 3; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);
	CBeam* m_pBeam1;
	void PrimaryAttack(void);
	void Cleaner(void);
	void SecondaryAttack(void);
	int SecondaryAmmoIndex(void);
	BOOL Deploy(void);
	void Holster(int skiplocal);
	void MyAnim(int iAnim);
	void Reload(void);
	void WeaponIdle(void);
	float m_flNextAnimTime;
	int m_iShell;
};

//=========================================================
//=========================================================

class CAR2Ball: public CBaseEntity
{
public:
	static CAR2Ball *AR2Shoot(entvars_t *pevOwner, Vector vecStart, Vector vecVelocity, float time);
	void AR2Touch(CBaseEntity *pOther);
	void Precache();
	void Spawn();
	void AR2Think();
	void Detonate();
	void Explode(TraceResult *tr, int);
	int TakeDamage(entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType);
	virtual float TouchGravGun( CBaseEntity *attacker, int stage )
	{
		pev->owner = attacker->edict();

		if( stage == 3 )
		{
			pev->dmgtime = gpGlobals->time + 6 ;
			// play launch sound
			switch (RANDOM_LONG(0, 2))
			{
				case 0:	EMIT_SOUND(ENT(pev), CHAN_VOICE, "ar2/ar2launch1.wav", 1, ATTN_NORM);	break;
				case 1:	EMIT_SOUND(ENT(pev), CHAN_VOICE, "ar2/ar2launch2.wav", 1, ATTN_NORM);	break;
			}
			m_fGravgunSound = false;
		}

		if( stage == 2 && gpGlobals->time - pev->dmgtime < 15 )
		{
			pev->dmgtime = gpGlobals->time + 20 ;
			if( !m_fGravgunSound )
			{
				EMIT_SOUND_DYN(ENT(pev), CHAN_VOICE, "ar2/ar2gravgun.wav", 0.2, ATTN_NORM, 0, 70 + RANDOM_LONG(0, 34));
				m_fGravgunSound = true;
			}
		}

		if( stage == 1 )
			pev->dmgtime = gpGlobals->time + 20 ;

		return 1600;
	}
	float m_flNextAttack;
	bool m_fRegisteredSound;
	bool m_fGravgunSound;
	float m_flLastSound;
	int m_iShockWaveTexture;
};

#endif // AR2_H