//
//  Perishable.cpp
//  MS05
//
//  Created by Carlos  Moyano on 10/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <stdio.h>
#include "Perishable.h"

namespace AMA {
    Perishable::Perishable(){
        Product('P');
        Date();
    }
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
        bool flag = false;
        if(newLine == true){
            flag = true;
        }
        Product::store(file, flag);
        file << "," <<  expiry_date.getYear() << expiry_date.getMonth() << expiry_date.getDay()
        << std::endl;
       
        if(newLine){
            file << "\n";
        
    }
        return file;
    }
    void Perishable::expiry(const Date& date){
        expiry_date = date;
    }
    std::fstream& Perishable::load(std::fstream& file){
    //    Product::load(file);
       
        /*read(file);
        std::istream& get(char& file);
        return file;*/
       
        char _sku[1000];
        file.getline(_sku,1000,',');
        file.ignore();
        char _name[1000];
        file.getline(_name,1000);
        file.ignore();
        double price;
        file >> price;
        file.ignore();
        int _qty;
        file >> _qty;
        file.ignore();
        int _qtyneeded;
        file >> _qtyneeded;
        file.ignore();
        expiry_date.read(file);
        file.ignore();
        
        
        setSku(_sku);
        name(_name);
        setPrice(price);
        setQty(_qty);
        setQtyNeeded(_qtyneeded);
        
        
        
        return file;
    
    }
    
    void Perishable::setYear(int _year){
        expiry_date.CopyYear(_year);
    }
    std::ostream& Perishable::write(std::ostream& os, bool linear) const{
        Product::write(os, linear);
            
            if(!linear){
                os << "Expiry date: ";
            }else{
                os << expiry_date.getYear() << "/" << expiry_date.getMonth() << "/" << expiry_date.getDay();
            }
    
        
        return os;
    }
    std::istream& Perishable::read(std::istream& is){
        int numDays;
        product_errorState.clear();
        Product::read(is);
        //Date temp;
        
        if (product_errorState.isClear()){
            std::cout << " Expiry date (YYYY/MM/DD): ";
            expiry_date.read(is);
            if (!is.fail()){
                if (expiry_date.getYear() < min_year || expiry_date.getYear() > max_year){
              
                    is.setstate(std::ios::failbit);
                    product_errorState.message("Invalid Year in Date Entry");
                }
                else if (expiry_date.getMonth() < 1 || expiry_date.getMonth() > 12){
                 
                    is.setstate(std::ios::failbit);
                    product_errorState.message("Invalid Month in Date Entry");
                }
                else{
                    numDays = expiry_date.getDay();
                    if (expiry_date.getDay() > numDays || expiry_date.getDay() < 1){
               
                        is.setstate(std::ios::failbit);
                        product_errorState.message("Invalid Day in Date Entry");
                    }
                }
            }
            else{
                is.setstate(std::ios::failbit);
                std::cout << "Invalid Date Entry";
            }
       
        }
      
        
        return is;
    }
    const Date& Perishable::expiry() const{
        return expiry_date;
    }
}
