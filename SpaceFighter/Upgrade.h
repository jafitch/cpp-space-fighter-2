#pragma once

#include "KatanaEngine.h"
#include "GameObject.h"

/** @brief Represents a upgrade pickup. */
class Upgrade : public GameObject
{

public:

	/** @brief Instantiate a projectile object. */
	Upgrade();
	virtual ~Upgrade() {}

	/** @brief Set the texture that will be used to render the projectile.
		@param pTexture A pointer to the texture. */
	static void SetTexture(Texture* pTexture) { s_pTexture = pTexture; }

	/** @brief Update the projectile.
		@param pGameTime Timing values including time since last update. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the projectile.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Activate the projectile.
		@param position The position to activate the projectile at.
		@param wasShotByPlayer A flag to determine if the projectile was fired by the player. */
	virtual void Activate(const Vector2& position);

	/** @brief Get the type of collision the projectile will have.
		@return The type of collision the projectile will have. */
	virtual CollisionType GetCollisionType() const;

	/** @brief Get the string representation of the projectile.
		@return The string representation of the projectile. */
	virtual std::string ToString() const;

	/** @brief Initializes the enemy ship.
		@param position The starting position of the enemy ship.
		@param delaySeconds The delay before the enemy ship activates. */
	virtual void Initialize(const Vector2 position, const double delaySeconds);

protected:

	/** @brief Set the speed of the projectile.
		@param speed The speed of the projectile. */
	virtual void SetSpeed(const float speed) { m_speed = speed; }

	/** @brief Set the direction of the projectile.
		@param direction The direction of the projectile. */
	virtual void SetDirection(const Vector2 direction) { m_direction = direction; }

	/** @brief Get the speed of the projectile.
		@return The speed of the projectile. */
	virtual float GetSpeed() const { return m_speed; }

	/** @brief Get the direction of the projectile.
		@return The direction of the projectile. */
	virtual Vector2& GetDirection() { return m_direction; }

	/** @brief Get the collision type of the projectile.
		@return The collision type of the projectile. */
	virtual CollisionType GetProjectileType() const { return CollisionType::Upgrade; }

private:

	static Texture* s_pTexture;

	float m_speed = 150; // pixels per second

	Vector2 m_direction;

	bool m_wasShotByPlayer = true;

	double m_delaySeconds = 0;

	float m_cooldown = 0;

	float m_cooldownSeconds = 5;

};