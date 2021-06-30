#ifndef FLAME_H
#define FLAME_H

class CFlame : public CBaseMonster
{
   public:
   static CFlame *ShootFlame( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity );

   void Spawn( void );
   void Explode( Vector vecSrc, Vector vecAim );
   void Explode( TraceResult *pTrace, int bitsDamageType );
   void EXPORT Smoke( void );

   void EXPORT BounceTouch( CBaseEntity *pOther );
   void EXPORT SlideTouch( CBaseEntity *pOther );
   void EXPORT ExplodeTouch( CBaseEntity *pOther );
   void EXPORT DangerSoundThink( void );
   void EXPORT PreDetonate( void );
   void EXPORT Detonate( void );
   void EXPORT DetonateUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

   virtual void BounceSound( void );
   virtual int BloodColor( void ) { return DONT_BLEED; }
   virtual void Killed( entvars_t *pevAttacker, int iGib );

   BOOL m_fRegisteredSound;
};

#endif // FLAME_H