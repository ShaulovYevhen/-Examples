//
//1.  Спроектировать приложение, которое позволяет создавать пиццу с произвольным
//    количеством ингредиентов.Предусмотреть два вида основ для пиццы(например
//    маленькая и средняя) а так же, как минимум, три вида ингредиентов.Реализовать
//    возможность подсчета общей стоимости пиццы со всеми включенными
//    ингредиентами.

#include <iostream>
using namespace std;

class BasePizza
{
protected:
    double price=0;
public:
    virtual double getPrice()
    {
        return price;
    }
};

class BigPizza : public BasePizza
{
public:
    BigPizza() 
    {
        price = 10;
    }
};

class SmallPizza : public BasePizza
{
public:
    SmallPizza()
    {
        price = 7.8;
    }
};

class ToppingsDecorator : public BasePizza
{
protected:
    BasePizza* pizza = nullptr;
public:
    ToppingsDecorator(BasePizza* pizzaToDecorate)
    {
        this->pizza = pizzaToDecorate;
    }
    ~ToppingsDecorator()
    {
        delete pizza;
    }
   double getPrice() override
    {
       return (this->pizza->getPrice()+this->price);
    }
};

class Cheese : public ToppingsDecorator
{
public:
    Cheese(BasePizza* pizzaToDecorate)  : ToppingsDecorator(pizzaToDecorate)
    {
        this->price = 1.00;
    }
};

class Mushroom : public ToppingsDecorator
{
public:
    Mushroom(BasePizza* pizzaToDecorate) : ToppingsDecorator(pizzaToDecorate)
    {
        this->price = 2.00;
    }
};

class Pork : public ToppingsDecorator
{
public:
    Pork(BasePizza* pizzaToDecorate) : ToppingsDecorator(pizzaToDecorate)
    {
        this->price = 5.00;
    }
};

class Chicken : public ToppingsDecorator
{
public:
    Chicken(BasePizza* pizzaToDecorate) : ToppingsDecorator(pizzaToDecorate)
    {
        this->price = 6.00;
    }
};

int main()
{
    BigPizza* bigPizza = new BigPizza();
    SmallPizza* smallPizza = new SmallPizza();
    cout << "Plain big pizza price = " << bigPizza->getPrice() << endl;
    cout << "Plain small pizza price =" << smallPizza->getPrice() << endl;
    Cheese* bigPizzaCheese = new Cheese(bigPizza);
    cout << "big Pizza Cheese price =" << bigPizzaCheese->getPrice() << endl;
    Pork* bigPizzaCheesePork = new Pork(bigPizzaCheese);
    cout << "big Pizza Cheese Pork price =" << bigPizzaCheesePork->getPrice() << endl;
    Pork* s = new Pork(new Cheese(new Chicken(smallPizza)));
    cout << "small pizza Cheese Pork Chicken price =" << s->getPrice() << endl;
}

