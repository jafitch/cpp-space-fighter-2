

#include "Level01.h"
#include "BioEnemyShip.h"
#include "BioEnemyShip2.h"
#include "Upgrade.h"
#include "GameTime.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>


void Level01::LoadContent(ResourceManager& resourceManager)
{
	
	InitializeEnemies(resourceManager);
	
	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground01.png"));

	Level::LoadContent(resourceManager);
	
	
}
void Level01::InitializeEnemies(ResourceManager& resourceManager)
{
	
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");
	Texture* pTexture2 = resourceManager.Load<Texture>("Textures\\BioEnemyShip2.png");
	Texture* pTexture3 = resourceManager.Load<Texture>("Textures\\Upgrade.png");

	const int COUNT = 21;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;
	Vector2 upgradePosition;

	std::srand(std::time(0));
	int randNum = std::rand() % Game::GetScreenWidth();

	int waves= 10;
	int waveNumber = 0;
	
		for (int waveCounter = 0; waveCounter < waves; waveCounter++)
		{
			//Level::SetWaveNumber(waveCounter+1);
			
			for (int i = 0; i < COUNT; i++)
			{
				delay += delays[i];
				position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

				upgradePosition.Set(randNum, -pTexture3->GetCenter().Y);

				BioEnemyShip* pEnemy = new BioEnemyShip();
				pEnemy->SetTexture(pTexture);
				pEnemy->SetCurrentLevel(this);
				pEnemy->Initialize(position, (float)delay);
				pEnemy->SetWaveNumber(waveCounter + 1);
				AddGameObject(pEnemy);

				BioEnemyShip2* pEnemy2 = new BioEnemyShip2();
				pEnemy2->SetTexture(pTexture2);
				pEnemy2->SetCurrentLevel(this);
				pEnemy2->Initialize(position, (float)delay);
				AddGameObject(pEnemy2);

				Upgrade* pUpgrade = new Upgrade();
				pUpgrade->SetTexture(pTexture3);
				pUpgrade->SetCurrentLevel(this);
				pUpgrade->Activate(Game::GetScreenWidth() / 2);
				AddGameObject(pUpgrade);

			}

		}
	
}


