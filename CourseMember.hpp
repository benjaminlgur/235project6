//
/** @file  CourseMember.hpp */
//  Project2C for CSCI 235 - Software Design and Analysis II
//  Same as Project1A with modified access specifiers to support inheritance
//
//  Created by Tiziana Ligorio on 3/4/19.
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
/** Description:
    A simple general Course Member class, a participant in the course,
    whose function is to be a Base class for Student, TeachingAssistant and Instructor
    Serves as an illustrative example for Inheritance and Polymorphism
 **/

#ifndef CourseMember_hpp
#define CourseMember_hpp

#include <string>

class CourseMember
{
public:
    /** Parameterized constructor
     @param id : the CourseMember's unique identifier
     @param first : the CourseMember's first name
     @param last : the CourseMember's last name
     */
    CourseMember(int id, std::string first, std::string last);
    
    /** Copy constructor
     @param another_member : the CourseMember to be copied
     */
    CourseMember(const CourseMember& another_member); //copy constructor
    
    /** @return: id_ */
    int getID() const;
    
    /** @return: returns first_name_ */
    std::string getFirstName() const;
    
    /** @return: returns last_name_ */
    std::string getLastName() const;
    
    virtual void displayMember() =0;
    
    

// modify access specifier from Project1A to allow for Inheritance
protected:
    int id_;
    std::string first_name_;
    std::string last_name_;
    
    
}; //end CourseMember

#endif /* CourseMember_hpp */
