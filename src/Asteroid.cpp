//
// Created by tony on 1/14/20.
//

#include "../header/Asteroid.h"
#include "../header/Math.h"
#include "../header/Game.h"
#include "../header/Random.h"
#include "../header/component/SpriteComponent.h"
#include "../header/component/MoveComponent.h"
#include "../header/component/CircleComponent.h"

Asteroid::Asteroid(Game *game) : Actor(game) {
    Vector2 randPosition = Random::getVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
    setPosition(randPosition);
    setRotation(Random::getFloatRange(0.0f, Math::TwoPi));

    auto* sc = new SpriteComponent(this);
    sc->setTexture(game->loadTexture("Assets/Asteroid.png"));

    mc = new MoveComponent(this);
    mc->setForwardSpeed(150.0f);

    cc = new CircleComponent(this);
    cc->setRadius(4);

    game->addSprite(sc);

    addComponent(sc);
    addComponent(mc);
    addComponent(cc);
}

const CircleComponent& Asteroid::getCircle() const {
    return *cc;
}

void Asteroid::updateActor(float deltaTime) {
    Actor::updateActor(deltaTime);
}

void Asteroid::reflect(int x, int y) {
    Vector2 pos = getPosition();
    mc->setForwardSpeed(-mc->getForwardSpeed());
}
