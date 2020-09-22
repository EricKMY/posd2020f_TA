#ifndef UTILITY_H
#define UTILITY_H


using namespace std;

class Utility 
{
    public:
        Shape* getShapeById(Shape* shape, string id) {
            Iterator *it = shape->createIterator();
            try {
                it->first();
            }catch(string e) {
                throw string("Only complex shape can get shape!");
            }

            for(;!it->isDone(); it->next()){
                if(it->currentItem()->id() == id) {
                    return it->currentItem();
                }
                try{
                    return getShapeById(it->currentItem(), id);
                }catch(string e) {}
            }
            throw string("expected get shape but shape not found");
        }


        vector<Shape*> filterShapeByArea(Shape *shape, double upperbound, double lowerbound) {
            vector<Shape*> results = {};

            Iterator *it = shape->createIterator();
            try {
                it->first();
            }catch(string e) {
                if(shape->area() <= upperbound && shape->area() >= lowerbound) {
                    results.push_back(shape);
                }
                return results;
            }

            if(shape->area() <= upperbound && shape->area() >= lowerbound) {
                results.push_back(shape);
            }

            for(;!it->isDone(); it->next()){
                vector<Shape*> _v = filterShapeByArea(it->currentItem(), upperbound, lowerbound);
                results.insert(results.end(), _v.begin(), _v.end());
            }

            return results;
        }
};


#endif
