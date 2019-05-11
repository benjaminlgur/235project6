//
/** @file  CourseMember.cpp */
//  Project2C for CSCI 235 - Software Design and Analysis II
//
//  Created by Tiziana Ligorio on 3/4/19.
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
/** Description:
    A simple general Course Member class, a participant in the course,
    whose function is to be a Base class for Student, TeachingAssistant and Instructor
    Serves as an illustrative example for Inheritance and Polymorphism
 **/

#include "CourseMember.hpp"


/** Parameterized constructor
 @param id : the CourseMember's unique identifier
 @param first : the CourseMember's first name
 @param last : the CourseMember's last name
 */
CourseMember::CourseMember(int id, std::string first, std::string last) : id_(id), first_name_(first), last_name_(last){}//end parameterized constructor

/** Copy constructor
 @param another_member : the CourseMember to be copied
 */
CourseMember::CourseMember(const CourseMember& another_member):
id_(another_member.getID()), first_name_(another_member.getFirstName()), last_name_(another_member.getLastName()){}

/** @return: id_ */
int CourseMember::getID() const
{
    return id_;
}

/** @return: returns first_name_ */
std::string CourseMember::getFirstName() const
{
    return first_name_;
}

/** @return: returns last_name_ */
std::string CourseMember::getLastName() const
{
    return last_name_;
}



