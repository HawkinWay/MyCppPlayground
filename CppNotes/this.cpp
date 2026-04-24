// 'this' is a pointer to the current object instance

class Entity{
public:
	int x, y;
	Entity(int x, int y){
		this->x = x;
		this->y = y;
		PrintEntity(this);	// 'this' will pass x and y
		PrintEntityRef(*this);
	}
	
};

void PrintEntity(Entity *e){

}

void PrintEntityRef(const Entity &e){
	
}
