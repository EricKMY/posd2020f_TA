#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape{
	public:
        Shape(string id):_id(id){}

        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual string info() const = 0;

        virtual void addChild(Shape *shape) {
		throw string("Only complex shape can add!");
	}

	virtual Shape *getChild(int index){
                throw string("Only complex shape can get!");
	}

        virtual Shape *findShape(string id){
                throw string("Only complex shape can find!");
        }

	virtual string listShape(){
		throw string("Not a complex shape!");
	}



        private:
        string _id;
};

#endif