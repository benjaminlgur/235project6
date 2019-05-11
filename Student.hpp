//
/** @file  Student.hpp */
//  Project2C for CSCI 235 - Software Design and Analysis II
//
//  Created by Tiziana Ligorio on 13/4/19.
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
/** Description:
    A simple Student class, derived from a general CourseMember class,
    serves as an illustrative example for Inheritance and Polymorphism
 **/

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>
#include "CourseMember.hpp"

class Student : public CourseMember
{
public:
    /** parameterized constructor 
     @param id the student's unique identifier
     @param first the student's first name
     @param last the student's last name
     */
    Student(int id, std::string first, std::string last);
    
    Student(const Student& another_student); //copy constructor
    
    /*********** accessor methods ***************/
    
    /** @return: major_ the student's major */
    std::string getMajor() const;
    
    /** @return: gpa_ the student's gpa */
    double getGpa() const;
    
    
    /*********** mutator methods ***************/
    
    /** @param major the student's major */
    void setMajor(const std::string major);
    
    /** @param gpa the student's gpe */
    void setGpa(const double gpa);
    
    /** @post display Student data in the format
     first_name_ last_name_ majors in major_ with gpa: gpa_
     */
    virtual void displayMember() override;
    
    void operator= (const Student& another_student);
    
    
protected:
    std::string major_;
    double gpa_;
    
}; //end Student

#endif /* Student_hpp */
