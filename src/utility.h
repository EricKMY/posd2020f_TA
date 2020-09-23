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

        template <class Compare>
        vector<Shape*> filterShape(Shape *shape, Compare comp) {
            vector<Shape*> results = {};

            Iterator *it = shape->createIterator();
            try {
                it->first();
            }catch(string e) {

                if(comp(shape)) {
                    results.push_back(shape);
                }
                return results;
            }

            if(comp(shape)) {
                results.push_back(shape);
            }

            for(;!it->isDone(); it->next()){
                vector<Shape*> _v = filterShape(it->currentItem(), comp);
                results.insert(results.end(), _v.begin(), _v.end());
            }

            return results;
        }
};


#endif
