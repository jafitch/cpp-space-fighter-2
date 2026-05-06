
#include "Blaster.h"

void Blaster::Update(const GameTime & gameTime)
{
	if (m_cooldown > 0) m_cooldown -= gameTime.GetElapsedTime();
}

void Blaster::Fire(TriggerType triggerType)
{
	if (!IsActive()) return;
	if (!CanFire()) return;
	if (!triggerType.Contains(GetTriggerType())) return;

	Projectile* pProjectile1 = GetProjectile();
	if (!pProjectile1) return;

	Projectile* pProjectile2 = GetProjectile();
	if (!pProjectile2) return;

	Projectile* pProjectile3 = GetProjectile();
	if (!pProjectile3) return;

	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	Vector2 vector = vector.Set(1, 1);

	if (false) {
		pProjectile1->Activate(GetPosition(), IsAttachedToPlayer());
		pProjectile2->SetDirection(Vector2::UNIT_X);
		pProjectile2->Activate(GetPosition(), IsAttachedToPlayer());
		pProjectile3->SetDirection(-Vector2::UNIT_X);
		pProjectile3->Activate(GetPosition(), IsAttachedToPlayer());
	}
	else {
		pProjectile2->SetDirection();
		pProjectile1->Activate(GetPosition(), IsAttachedToPlayer());
	}
	m_cooldown = m_cooldownSeconds;
}