class Air{
private:
	int amount;
public:
	Air(int _amount) : amount(_amount){ }
	void Consume(int v){
		amount -= v;
	}
	int Avaliable() const{
		return amount;
	}
};

class Human{
public:
	Human(int breath);
};

// #1
Air CO2{9};
Human joel{5};

Human::Human(int breath){
	CO2.Consume(breath);
}

// result is 4



// #2
Human joel_2{5};
Air CO2_2{9};

Human::Human(int breath){
	CO2_2.Consume(breath);
}// #1 result is 4

// result is 9



// #3
// constexpr Air(int _amount) : amount(_amount){}
Human joel_3_1{5};
Air CO2_3_1{9};

Human::Human(int breath){
	CO2_3_1.Consume(breath);
}

Air CO2_3_2{9};
Human joel_3_2{5};

Human::Human(int breath){
	CO2_3_2.Consume(breath);
}

// result is 4, 'constexpr' makes Air's constructor always execute before Human's.
// but this method is not future compatible.



// #4
// constexpr Air(int _amount) : amount(_amount){}
Human joel_4{5};
//constinit Air CO2_4{9};

// Human::Human(int breath){
// 	CO2_4.Consume(breath);
// }

// result is 4, this method is better than #3
// if the constructor of Air fails to run at compile time due to some modification, 
// the compiler will immediately report an error, rather than generating a potential runtime bug.