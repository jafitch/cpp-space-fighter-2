
#include "Blaster.h"
#include "Upgrade.h"

void Blaster::Update(const GameTime & gameTime)
{
	if (m_cooldown > 0) m_cooldown -= gameTime.GetElapsedTime();
}

void Blaster::Fire(TriggerType triggerType)
{
	if (!IsActive()) return;
	if (!CanFire()) return;
	if (!triggerType.Contains(GetTriggerType())) return;
	
	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	Projectile* pProjectile1 = GetProjectile();
	if (!pProjectile1) return;
	pProjectile1->SetDirection(-Vector2::UNIT_Y);
	pProjectile1->Activate(GetPosition(), IsAttachedToPlayer());

	//Projectile* pProjectile2 = GetProjectile();
	//if (!pProjectile2) return;
	//pProjectile2->SetDirection(Vector2(1, -1));
	//pProjectile2->Activate(GetPosition(), IsAttachedToPlayer());

	//Projectile* pProjectile3 = GetProjectile();
	//if (!pProjectile3) return;
	//pProjectile3->SetDirection(Vector2(-1, -1));
	//pProjectile3->Activate(GetPosition(), IsAttachedToPlayer());

	m_cooldown = m_cooldownSeconds;
}