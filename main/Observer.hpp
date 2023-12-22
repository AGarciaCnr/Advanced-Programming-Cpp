#pragma once

class Item;

class Observer {
public:
    virtual void Actualizar() = 0;
    virtual ~Observer() = default;
};