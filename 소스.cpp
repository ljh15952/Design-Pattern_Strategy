#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Strategy_Eat
{
public:
	virtual void Eat() {};
};
class Strategy_Move
{
public:
	virtual void Move() {};
};

class Eat_apple : public Strategy_Eat
{
public:
	void Eat()
	{
		cout << "사과 맜있어" << endl;
	}
};

class Eat_banana : public Strategy_Eat
{
public:
	void Eat()
	{
		cout << "바나나 맜있어" << endl;
	}
};



class Move_walk : public Strategy_Move
{
public:
	void Move()
	{
		cout << "걷기 재밌어" << endl;
	}
};

class Move_run : public Strategy_Move
{
public:
	void Move()
	{
		cout << "뛰기 재밌어" << endl;
	}
};
class Animal
{
private:
	Strategy_Eat * _Eat;
	Strategy_Move * _Move;
public:
	string _name;
	Animal()
	{
		_Eat = nullptr;
		_Move = nullptr;
	}
	void Move()
	{
		cout << _name;
		_Move->Move();
	}
	void Eat()
	{
		cout << _name;
		_Eat->Eat();
	}

	void SeteatStrategy(Strategy_Eat * Eat)
	{
		_Eat = Eat;
	}
	void SetmoveStrategy(Strategy_Move * Move)
	{
		_Move = Move;
	}
};

class Dog : public Animal
{
public :
	Dog(string a)
	{
		_name = a;
		SetmoveStrategy(new Move_run);
		SeteatStrategy(new Eat_apple);
	}
};

class Cat : public Animal
{
public :
	Cat(string a)
	{
		_name = a;
		SetmoveStrategy(new Move_walk);
		SeteatStrategy(new Eat_banana);
	}
};



int main()
{/*
	Animal * D = new Dog("강이지 ");
	D->Move();
	D->Eat();*/

	/*Animal * C = new Cat("고양이 ");
	C->Move();
	C->Eat();*/
	
	Cat * C1 = new Cat("ASD");
	C1->Eat();

	Animal * C = new Cat("ASDASD");
	C->Move();


	//D->SeteatStrategy(new Eat_banana);
	//D->Eat();
	//
	//D->SetmoveStrategy(new Move_walk);
	//D->Move();


}



