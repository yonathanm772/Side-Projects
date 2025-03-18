#pragma once
#include "Components.h"
#include <tuple>
#include <string>

class EntityManager;

class Entity
{
	friend class EntityManager;

	bool			m_active	= true;
	size_t			m_id		= 0;
	std::string		m_tag = "default";
	bool			m_hasSpawnedSmallEnemies = false;
	Entity(const size_t id, const std::string& tag);

public:
	
	//component pointers
	std::shared_ptr<CTransform>		cTransform;
	std::shared_ptr<CShape>			cShape;
	std::shared_ptr<CCollision>		cCollision;
	std::shared_ptr<CInput>			cInput;
	std::shared_ptr<CScore>			cScore;
	std::shared_ptr<CLifespan>		cLifespan;

	// private member access functions
	bool isActive() const;
	bool hasSpawnedSmallEnemies();
	const std::string& tag() const;
	const size_t id() const;
	void destroy();
	void setSmallEnemySpawned();
};

