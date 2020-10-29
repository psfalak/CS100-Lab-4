#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string> 

class Mult : public Base {

    public: 
	Mult(Base* one, Base* two){
	val_1 = one; 
	val_2 = two; 
	}
	virtual double evaluate(){
		double val = val_1->evaluate(); 
		double val2 = val_2->evaluate(); 
		product = val * val2; 
		return product; 
	}
	virtual std::string stringify(){ 
		str += val_1->stringify(); 
		str += " * "; 
		str += val_2->stringify();
		return str;  
	}
    private: 
	Base* val_1;
	Base* val_2;
	double product; 
	std::string str; 
};


#endif
