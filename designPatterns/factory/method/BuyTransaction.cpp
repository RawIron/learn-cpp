#include "Item.h"
#include "Wallet.h"
#include "Inventory.h"
#include "Counter.h"


class Buy {
public:
    virtual void run();
    virtual bool itemExists() = 0;
    virtual bool canPay() = 0;
    virtual bool levelGreaterThan() = 0;

    virtual Item createItem() = 0;
    virtual Wallet createWallet() = 0;
    virtual Inventory createInventory() = 0;
    virtual Counter createCounter() = 0;
};

void Buy::run() {
    Item stuff = createItem();
    stuff.isValid();
    wallet.canPay();
    counter.greaterThan();
    inventory.add(stuff);
    wallet.withdraw();
}

