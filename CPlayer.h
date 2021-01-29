#pragma once
#include "Object.h"

class CPlayer :
    public Object
{
private:
    enum class State : char
    {
        IDLE,
        MAX
    };
public:
    vector<CMeshLoader*> playerMesh[(int)State::MAX];
    State playerState = State::IDLE;
    Frame frame;

    Vector3 jumpDir = Vector3(0, 1500, 0);

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Destroy() override;

    virtual void OnCollision(Collider* col) override;

    virtual void ObjectDead() override;
public:
    void Move();
    void Jump();
};

