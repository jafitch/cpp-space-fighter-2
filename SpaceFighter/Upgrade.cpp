
#include "Upgrade.h"
#include "Level.h"
#include "GameTime.h"
#include <iostream>
#include <chrono>
#include <thread>

Texture* Upgrade::s_pTexture = nullptr;

Upgrade::Upgrade()
{
	SetDirection(Vector2::UNIT_Y);
	SetCollisionRadius(9);
}

void Upgrade::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		Vector2 translation = m_direction * m_speed * gameTime.GetElapsedTime();
		TranslatePosition(translation);

		Vector2 position = GetPosition();
		Vector2 size = s_pTexture->GetSize();

		// Is the projectile off the screen?
		//if (position.Y < -size.Y) Deactivate();
		//else if (position.X < -size.X) Deactivate();
		if (position.Y > Game::GetScreenHeight() + size.Y) Deactivate();
		else if (position.X > Game::GetScreenWidth() + size.X) Deactivate();
	}

	GameObject::Update(gameTime);
}

void Upgrade::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(s_pTexture, GetPosition(), Color::WHITE * alpha, s_pTexture->GetCenter());
	}
}

void Upgrade::Activate(const Vector2& position)
{
	SetPosition(position);

	GameObject::Activate();
}

CollisionType Upgrade::GetCollisionType() const
{
	return (CollisionType::Player | GetProjectileType());
}

std::string Upgrade::ToString() const
{
	return std::string("Player").append(" Upgrade");
}

void Upgrade::Initialize(const Vector2 position, const double delaySeconds)
{
	SetPosition(position);
	m_delaySeconds = delaySeconds;

}