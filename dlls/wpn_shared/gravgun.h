/***
Created by Solexid
*
****/

#ifndef GRAVGUN_H
#define GRAVGUN_H

class CGravGun : public CBasePlayerWeaponU
{
public:


	float m_flLastCmd;
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);
	int m_iStage;
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	int m_iGrabFailures;
	EHANDLE m_hAimentEntity;
	void UpdateEffect(const Vector &startPoint, const Vector &endPoint, float timeBlend);
	CBaseEntity *	TraceForward(CBaseEntity *pMe, float radius);
	void CreateEffect(void);
	void DestroyEffect(void);
	void EndAttack(void);
	void Attack(void);
	void Attack2(void);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void WeaponIdle(void);
	void Pull(CBaseEntity* ent);
	void GravAnim(int iAnim, int skiplocal, int body);
	Vector PredictTarget( float length );
	CBaseEntity *GetCrossEnt( Vector gunpos, Vector aim, float radius );
	float m_flNextGravgunAttack;
	float m_flAmmoUseTime;// since we use < 1 point of ammo per update, we subtract ammo on a timer.


	void EXPORT GrabThink( void );
	void EXPORT PullThink( void );
	float Fire(const Vector &vecOrigSrc, const Vector &vecDir);

	BOOL HasAmmo(void);


	enum GRAV_FIREMODE { FIRE_NARROW, FIRE_WIDE };

	CBeam				*m_pBeam;
	CBeam				*m_pNoise;
	CSprite				*m_pSprite;

private:
	float				m_shootTime;
	GRAV_FIREMODE		m_fireMode;
	float				m_shakeTime;
	BOOL				m_deployed;
	float				m_fPushSpeed;
};

#endif // GRAVGUN_H